import os
import serial
import time
ser = serial.Serial("/dev/cu.usbmodem14201", 9600 , timeout=1)               #Ouverture du port 'COM3'
#ser.read(2048)


def rechercheData(s):
    n=len(s)
    indexList=[]
    dicodata={}
    for i in range(5,n):                                    #5 est la taille minimale que l'on peut avoir avant un '\r' avec les données utiles
        if chr(s[i])=='\r':                                 #\r est le caractère de fin de message que l'on reçoit sur le port 'COM3'
            indexList.append(i)                             #On stocke les indices des fins de message
    #print(indexList)
    for j in range(0,len(indexList)):                       #On parcourt la liste de tous les indices de fin de message pour ajouter les données utiles dans le dictionnaire des feux
        dicodata[chr(s[indexList[j]-4])]=chr(s[indexList[j]-1]) #On connait la structure des données utiles donc si on a l'indice de la fin de message, on peut avoir le numéro de                
    return(dicodata)                                            #l'intersection et l'état du feu


def chercheIndex(caractere,chaine):                         #Cherche l'indice d'un caractère dans un string
    index=0
    for i in range(len(chaine)):
        if(chaine[i]==caractere):
            index=i
    return(index)

def ecritureTxt(dicoData):
    os.chdir("/Users/clementrubin/Desktop/software-cooc/data/")       #On se place dans le repertoire où l'on peut trouver le fichier txt
    mon_fichier = open("light_state.txt", "r")
    contenu=mon_fichier.read()                                                      #Ouverture du fichier en mode écriture et on sauvegarde tout ce qu'il y a dedans
    mon_fichier.close()                                 
    mon_fichier= open("light_state.txt", "w")                                       #Fermeture du fichier et réouverture avec écrasement des données
    for key in dicoData:                                                            #Parcours du dictionnaire adresse/état des feux
        print("Truc bidule")
        if key in contenu:                                                          #Il ne faut pas inscrire de nouvelles données si le feu est déjà présent
            index=chercheIndex(key,contenu)
            if dicoData[key]=='0':
                contenu=contenu[0:index+2]+'R'+contenu[index+3:len(contenu)]        #Modification de l'état du feu en fonction de la valeur du dictionnaire
            else:
                contenu=contenu[0:index+2]+'V'+contenu[index+3:len(contenu)]
        else:                                                                       #Si la clé n'est pas présente dans le txt, c'est un nouveau feu
            contenu=contenu+key+'\n'                                                #On ajoute l'adresse du feu et sa valeur à la fin du txt
            if dicoData[key]=='0':
                contenu=contenu+'R'
            else:
                contenu=contenu+'V'
            contenu=contenu+'\n'
    mon_fichier.write(contenu)                                                      #On écrit définitivement dans le txt
    mon_fichier.close()

while(True):
    s = ser.read(2048)                                      #Lecture du port ouvert 
    dico=rechercheData(s)
    time.sleep(0.25)
    ecritureTxt(dico)
