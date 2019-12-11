// rf95_mesh_address1.pde
// -*- mode: C++ -*-
// Example sketch showing how to create a simple addressed, routed reliable messaging client
// with the RHMesh class.
// It is designed to work with the other examples rf95_mesh_address*
// Hint: you can simulate other network topologies by setting the 
// RH_TEST_NETWORK define in RHRouter.h
#include <RH_RF95.h>
#include <SoftwareSerial.h>
#include <stdio.h>
#include <stdlib.h>
#include <Process.h>
#include <Bridge.h>

SoftwareSerial SSerial(A5,A4); // RX, TX
#define COMSerial SSerial
#define ShowSerial Serial 
#define TAILLE_MAX 2

RH_RF95<SoftwareSerial> driver(COMSerial);


#include <RHMesh.h>

// Mesh has much greater memory requirements, and you may need to limit the
// max message length to prevent wierd crashes
#define RH_MESH_MAX_MESSAGE_LEN 2

// In this small artifical network of 4 nodes,
#define MESH1_ADDRESS 1
#define MESH2_ADDRESS 2
#define MESH3_ADDRESS 3
#define MESH4_ADDRESS 4


// Class to manage message delivery and receipt, using the driver declared above
RHMesh manager(driver, MESH1_ADDRESS);

void setup() 
{
  ShowSerial.begin(9600);
  if (!manager.init())
    ShowSerial.println("init failed");
  // Defaults after init are 434.0MHz, 0.05MHz AFC pull-in, modulation FSK_Rb2_4Fd36
}

uint8_t data[] = "Hello World!";
uint8_t back[] = "And hello back to you from mesh 1";
// Dont put this on the stack:
uint8_t buf[RH_MESH_MAX_MESSAGE_LEN];


void loop()
{     
  ReceiveAck();
}

void ReceiveAck(){
    char addr;
    uint8_t len = sizeof(buf);
    uint8_t from;
//    int fromInt = from;
//    int bufInt=buf[0];
//    char ArduinoAddr[TAILLE_MAX];
//    char dataLight[TAILLE_MAX];
    memset(buf, 0, len);
    if(manager.recvfromAck(buf, &len, &from))
    {
        ShowSerial.print("got message from : 0x");
        ShowSerial.print(from, HEX);
        ShowSerial.print(": ");
        ShowSerial.println((char*)buf);
//        sprintf(ArduinoAddr,"%d",fromInt);
//        sprintf(dataLight,"%d",bufInt);
//        WriteLocalFile(ArduinoAddr,dataLight);
        // Send a reply back to the originator router
        if(manager.sendtoWait(back, sizeof(back), from) != RH_ROUTER_ERROR_NONE)
        ShowSerial.println("sendtoWait failed");
    }
}

//void WriteLocalFile(char* ArduinoAddr, char* buf){
//    FILE* fichier = NULL;
//    fichier = fopen("light_state.txt", "r+");
//    char chaine[TAILLE_MAX] = "";
//    if (fichier != NULL)
//    {
//        int copie=0;
//        long position;
//        while (fgets(chaine, TAILLE_MAX, fichier) != NULL){
//            if (strcmp(ArduinoAddr,chaine)==0){
//                copie=1;
//                position=ftell(fichier);
//            }
//        }
//        if (copie==1){
//            fseek(fichier, position+2, SEEK_SET);
//            fputs(buf,fichier);
//        }
//        else{
//            fseek(fichier, 0, SEEK_END);
//            fputs(ArduinoAddr,fichier);
//            char etatPrint[3]="\n";
//            strcat(etatPrint,buf);
//            strcat(etatPrint,"\n");
//            fputs(etatPrint,fichier);
//        }
//        fclose(fichier);
//    }
//    else
//    {
//        ShowSerial.print("Impossible d'ouvrir le fichier light_state.txt");
//    }
//}

