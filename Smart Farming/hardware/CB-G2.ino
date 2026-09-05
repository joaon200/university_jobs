
#include <OneWire.h>
#include <DallasTemperature.h>
#include <NTPClient.h>
#include "WiFi.h"

const uint16_t port = 8090;
const char * host = "192.168.1.56";

String datahora = " ";
String startstop = "";


WiFiUDP ntpUDP;
NTPClient ntp(ntpUDP);

/* create a hardware timer */
hw_timer_t * timer = NULL;
volatile SemaphoreHandle_t timerSemaphore;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

volatile uint32_t isrCounter = 0;
volatile uint32_t lastIsrAt = 0;
volatile uint32_t time1 = 0;
volatile uint32_t lasttime = 0;

void ARDUINO_ISR_ATTR onTimer(){
  // Increment the counter and set the time of ISR
  portENTER_CRITICAL_ISR(&timerMux);
  isrCounter++;
  lastIsrAt = millis();
  portEXIT_CRITICAL_ISR(&timerMux);
  // Give a semaphore that we can check in the loop
  xSemaphoreGiveFromISR(timerSemaphore, NULL);
  // It is safe to use digitalRead/Write here if you want to toggle an output
}

const char* ssid = "NOS-1214";
const char* password =  "7RGUT3KJ";
WiFiClient  client;


//sensor de temperatura
int sensor_temp = A4; 
OneWire ds(sensor_temp);
DallasTemperature sensors(&ds); 
float temperatura;


//sensor de luminosidade
const int LDR = A7 ;             // Pino analógico que o sensor está conectado
int luz ;                        // valor que sera armazenado o valor do LDR

//sensor de humidade
const int Humid = A5;            //Pino a que o sensor esta conectado
int humidade;
int perchumid;
int SoloSeco = 0; //VALOR MEDIDO COM O SOLO SECO 
int SoloMolhado = 2300; //VALOR MEDIDO COM O SOLO MOLHADO
int percSoloSeco = 0; //MENOR PERCENTUAL DO SOLO SECO
int percSoloMolhado = 100; //MAIOR PERCENTUAL DO SOLO MOLHADO

//definir led
const int LED = 17;             //luz - leds
const int LED1 = 16;            //temperatura - azul-min
const int LED2 = 5;             //humidade - amarelo
const int LED3 = 4;             //temperatura -verde+max 


void setup() {
  pinMode(sensor_temp, INPUT);   //coloca a variavel oneWireBus como entrada
  pinMode(LDR, INPUT);          //Coloca a variavel LDR como entrada
  pinMode(LED, OUTPUT);         //coloca a variavel LED como saida
  pinMode(LED1, OUTPUT);        //coloca a variavel LED1 como saida
  pinMode(LED2, OUTPUT);        //coloca a variavel LED2 como saida
  pinMode(LED3, OUTPUT);        //coloca a variavel LED3 como saida
  pinMode(Humid, INPUT);        //coloca a variavel Humid como entrada
  Serial.begin(115200);         //inicializa a comunicação serie com a taxa de 9600 bps

  //efetua a ligação ao wifi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  
  //configura o servidor de data e hora
  ntp.begin();
  //GMT em segundos
  // +1 = 3600
  // +8 = 28800
  // -1 = -3600
  // -3 = -10800
  ntp.setTimeOffset(3600);//precisa de mais uma hora porque o servidor esta num fuso hrario diferente

  //configuração do timer
  timerSemaphore = xSemaphoreCreateBinary();

  timer = timerBegin(0, 80, true);

  timerAttachInterrupt(timer, &onTimer, true);

  timerAlarmWrite(timer, 20000000, true);

  timerAlarmEnable(timer);

    
}

void loop() {
  
  int tempdefaultmin = 20.0;
  int tempdefaultmax = 25.0;
  int humdefaultmin = 60;

  
  //sensor de luz
  luz = analogRead(LDR);        // Faz a leitura do pino analógico LDR e armazena o valor na variavel luz

  if (luz < 2050) {             // Se o valor de luz for menos que 2050 significa que temos pouca luz
    digitalWrite(LED, LOW);
  } else {                      // Se não
    digitalWrite(LED, HIGH);
  }

  //sensor de humidade
  humidade = analogRead(Humid);
  perchumid = constrain(analogRead(Humid),SoloSeco,SoloMolhado); //MANTÉM humidade DENTRO DO INTERVALO
  perchumid = map(perchumid,SoloMolhado,SoloSeco,percSoloMolhado,percSoloSeco); //EXECUTA A FUNÇÃO "map" DE ACORDO COM OS PARÂMETROS PASSADOS
  if( perchumid<humdefaultmin){
    digitalWrite(LED2, HIGH); 
  }else{
    digitalWrite(LED2, LOW);
  }


  //sensor temperatura
  sensors.requestTemperatures(); 
  temperatura = sensors.getTempCByIndex(0);
    if(temperatura<tempdefaultmin){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED3, LOW); 
  }else if(temperatura>tempdefaultmax){
    

    digitalWrite(LED1, LOW);
  }else{
    digitalWrite(LED3, LOW);
    digitalWrite(LED1, LOW);
    }
  time1=millis();
  if(time1>=lasttime+1000){
    lasttime=time1;
    Serial.print("temperatura: ");
    Serial.print(temperatura);
    Serial.println("ºC");
    Serial.print("percentagem da humidade: ");
    Serial.print(perchumid);
    Serial.println("%"); 
    Serial.print("LDR : " );      // Mostra o valor no monitor serial
    Serial.println(luz);   
    }
  //delay(1000);                 // Aguarda 1s

  if (xSemaphoreTake(timerSemaphore, 0) == pdTRUE){
    uint32_t isrCount = 0, isrTime = 0;
    // Read the interrupt count and time
    portENTER_CRITICAL(&timerMux);
    isrCount = isrCounter;
    isrTime = lastIsrAt;
    portEXIT_CRITICAL(&timerMux);int i=0;
    // Print it
    WiFiClient client;
    
   //conexão ao servidor
    if (!client.connect(host, port)) {
        Serial.println("Connection to host failed");
    }
    Serial.println("Connected to server successful!");

    //conexão ao servidor de data e hora
    if (ntp.update()) {
    datahora = ntp.getFormattedDate();

    } else {
      Serial.println("!Erro ao atualizar NTP!\n");
    }
    Serial.println(datahora);
    
    
    int ID = 1; 
    String da = "DA";
    String de = "PR";

    //se a string lida do servidor for "start" envia dados senao envia a mensagem parado ao servidor
    if (startstop == "start"){
      client.print(da+String(temperatura)+" "+String(perchumid)+" "+String(luz)+" "+String(ID)+" "+datahora);
      startstop = client.readString();
      Serial.println(startstop);
    }
    else{
      client.print(de+String(ID));
      startstop = client.readString();
      Serial.print(startstop);
    }
    
 
    Serial.println("Disconnecting...");
    client.stop();
  }

}
