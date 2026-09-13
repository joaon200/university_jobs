#from tracemalloc import stop
from multiprocessing import Manager
import MySQLdb
from threading import Thread, Lock
import threading
#from dataclasses import replace
import socket

startstop = dict({1 : 'start'})
y = Lock()

def split(word): 
    return [char for char in word]

def handle_client(client,con):
        #print("novo cliente")
        content1 = client.recv(50).decode()
        #content1 = str(content1)
        #content1 = content1.replace("'","")
        #content1 = content1.replace("b","")
        #print(content1)

        if len(content1) == 0:
           return

        else:
            #data function, if the client send a data message, the server will save the data in a .txt file for simulate sistems and update the database
            if (content1[0:2] == "DA"):
                #print("cheguei aqui dados")
                split1 = content1[2:]
                split1 = split1.replace("T","/")
                split1 = split1.replace("Z","")
                split1 = split1.replace(":","-")
                split1 = split1.split(' ')

                temp = split1[0]
                temp = float(temp)
                humid = split1[1]
                humid = int(humid)
                luz = split1[2]
                luz = int(luz)
                id = split1[3]
                id = int(id)
                data = split1[4]
                print("\ntemperatura: ", temp)
                print("\nhumidade: ",humid)
                print("\nluz: ",luz)
                print("\nid: ",id)
                print("\ndata: ",data)

                file = open("dados_sistemas_simulados.txt","a")
                file.write(str(temp)+' '+str(humid)+' '+str(luz)+'\n')
                file.close()

                enviar = startstop.get(id,'nao')
                if(startstop.get(id,'nao') == 'nao'):
                    client.send('start'.encode())
                    startstop.update({id : 'start'})
                    print("aqui")
                else:
                    client.send(enviar.encode())
                    print(enviar)

                #write data to the database
                cursor = con.cursor()
                cursor.execute("INSERT INTO amostra (luz,temp,humidade,datahora,ID_PLACA) VALUES(%d, %d, %f,'%s', %d)" % (humid, luz, temp, data, id))
                con.commit()

            #first connection    
            elif(content1[0:2] == "PR"):
                #print("cheguei aqui primeira")
                IDERRO = int(content1[2:])
                print(IDERRO)
                y.acquire()
                enviar = startstop.get(IDERRO,'nao')
                if(enviar == 'nao'):
                    client.send('start'.encode())
                    startstop.update({IDERRO : 'start'})
                    #print("aqui")
                else:
                    client.send(enviar.encode())
                y.release()

            #error function, if the client send an error message, the server will send the start/stop command to the client and upate database
            elif(content1[0:2] == "ER"):
                #print("cheguei aqui erro")
                IDERRO = int(content1[2:])
                print(IDERRO)
                y.acquire()
                enviar = startstop.get(IDERRO,'nao')
                if(enviar == 'nao'):
                    client.send('start'.encode())
                    startstop.update({IDERRO : 'start'})
                    #print("aqui")
                else:
                    client.send(enviar.encode())
                y.release()

            #start/stop function, if the client send a start/stop message, the server will update the start/stop command for that client and update database
            elif(content1[0:2]=="ST"):
                #print("cheguei aqui start/stop")
                IDSTART = int(content1[2:])
                #print(IDSTART)
                y.acquire()
                if(startstop.get(IDSTART,'nao') == 'start' or startstop.get(IDSTART,'nao') == 'stop' ):
                    if(startstop[IDSTART] == 'start'):
                        #print(startstop[IDSTART])
                        startstop.update({IDSTART:'stop'}) 
                        print(startstop[IDSTART])
                    elif(startstop[IDSTART] =='stop'):
                        #print(startstop[IDSTART])
                        startstop.update({IDSTART:'start'})
                        #print(startstop[IDSTART])
                elif(startstop.get(IDSTART,'nao') == 'nao'):
                    startstop.update({IDSTART:'start'})
                    #print(startstop[IDSTART])
                y.release()

            #not implemented function                
            elif(content1[0:2]=="EN"):
                #print("cheguei aqui fim")
                IDFIM = int(content1[2:6])
                print(IDFIM)

        client.close()

if __name__ == '__main__':
    with socket.socket() as s:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) # reutilizar porta logo após servidor terminal, evita a excepcao 'OSError: [Errno 98] Address already in use'        
        sock.bind(('0.0.0.0', 8090 ))
        s.listen(5)

        #conects to the database
        con = MySQLdb.connect(host='127.0.0.1',user='root',passwd='J0@02001',db='smartfarming')
        con.select_db('smartfarming')                 
    
        while True:
            #accepts clients and creates a thread for every conection
            client, addr = sock.accept()
            threading.Thread(target=handle_client, args=(client,con)).start() # começar thread para lidar com os cliente, uma para cada cliente
