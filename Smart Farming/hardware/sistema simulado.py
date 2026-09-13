import os
import socket
from datetime import datetime
from time import sleep

startstop = ""

#This function read a standar data from an .txt documento and send it to server by tcp socket
with socket.socket() as sock: 
    while True:
        pasta = os.path.dirname(os.path.abspath(__file__))
        caminho = os.path.join(pasta, "dados_sistemas_simulados.txt")

        file = open(caminho,"r")
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.connect(('127.0.0.1', 8090))
        #commented code below is used to test the server and the start/stop command, it is not necessary for the normal operation of the system
        """enviar = ("ER"+str(3))
        sock.send(enviar.encode())
        content1 = sock.recv(40)
        content1=str(content1)
        content1=content1.replace("'","")
        content1=content1.replace("b","")
        startstop = content1
        print(startstop)
        #sleep(10)"""    
        now = datetime.now()
        id = 2

        dados = file.readline()

        dados = dados.replace("'","")
        dados = dados.replace("b","")
        dados = dados.replace("T","/")
        dados = dados.replace("Z","")
        dados = dados.replace(":","-")
        dados = dados.split(' ')

        temp = dados[0]
        temp = float(temp)
        humid = dados[1]
        humid = int(humid)
        luz = dados[2]
        luz = int(luz)

        now = str(now)
        now = now.replace(" ","T")
        datahora = now[:19]        

        print(datahora)

        if(startstop == 'start' or startstop == 'stop'):
            enviar = ("DA"+str(temp)+" "+str(humid)+" "+str(luz)+" "+str(id)+" "+str(datahora))
        else:
            enviar = ("PR"+str(id))

        #send data to the server and receive the start/stop command from the server        
        sock.send(enviar.encode())
        content1 = sock.recv(40).decode()
        content1 = str(content1)
        #content1 = content1.replace("'","")
        #content1 = content1.replace("b","")
        startstop = content1
        print(startstop)
        sleep(10)
    
        file.close()
