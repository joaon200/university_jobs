import socket
from datetime import datetime
from time import sleep

startstop = ""

#This function read a standar data from an .txt documento and send us by tcp socket to the server
with socket.socket() as sock: 
    while True:
        folder=open("dados_sistemas_simulados.txt","r")
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.connect(('192.168.1.56', 8090))
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

        dados=folder.readline()

        dados=dados.replace("'","")
        dados=dados.replace("b","")
        dados=dados.replace("T","/")
        dados=dados.replace("Z","")
        dados=dados.replace(":","-")
        dados=dados.split(' ')

        temp = dados[0]
        temp = float(temp)
        humid = dados[1]
        humid = int(humid)
        luz = dados[2]
        luz = int(luz)

        now = str(now)
        now=now.replace(" ","T")
        datahora = now[:19]        

        print(datahora)

        if(startstop == 'start' or startstop == 'stop'):
            enviar = ("DA"+str(temp)+" "+str(humid)+" "+str(luz)+" "+str(id)+" "+str(datahora))
        else:
            enviar = ("PR"+str(id))
                
        sock.send(enviar.encode())
        content1 = sock.recv(40)
        content1=str(content1)
        content1=content1.replace("'","")
        content1=content1.replace("b","")
        startstop = content1
        print(startstop)
        sleep(10)
    
        folder.close()
