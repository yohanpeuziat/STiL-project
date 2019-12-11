// Definition des PIN d entree
const int mainCloseSensorPin = A0;
const int mainFarSensorPin = A1;
const int secondCloseSensorPin = A2;
// const int secondFarSensorPin = A3;

// Definition des PIN de sortie
const int mainRedLightPin =  2;
const int mainGreenLightPin =  3;
const int secondRedLightPin =  4;
const int secondGreenLightPin =  5;

// Definition des variables de TEMPS
// delais apres captation d un vehicule proche et loin
const int delay_1 = 750;
const int delay_2 = 2500;
// delais maximum pour passage d un pieton
const unsigned long pedestrianMaxDelay = 10000;
// temps relatif au passage d un etat a un autre
unsigned long startTimer = 0;  // in ms
unsigned long currentTimer = 0;
unsigned long periodTimer = 0;

// Definition de l'OFFSET des capteurs
const int sensor_offset = 450;

// Definiiton des variables d ETAT et de changement
// etat 1 : MAIN a VERT
// etat 2 : SECOND a VERT
int currentState = 1;
int newState = 1;
// variable de changement demande par l algo
// change 1 : MAIN a VERT capteur PRES
// change 2 : SECOND a VERT capteur PRES
// change 3 : MAIN a VERT capteur LOIN
// change 4 : SECOND a VERT capteur LOIN
// change 5 : TIMER
int changeTo = 0;

// Definition des variables des capteurs
int mainCloseSensorValue = 0;
int mainFarSensorValue = 0;
int secondCloseSensorValue = 0;
// int secondFarSensorValue = 0;

// Definition des variables des etats des COULEURS des feux
int mainRedLightState = HIGH;
int mainGreenLightState = LOW;
int secondRedLightState = LOW;
int secondGreenLightState = HIGH;

// LoRa part
#include <RH_RF95.h>
#include <RHMesh.h>
#include <SoftwareSerial.h>
SoftwareSerial SSerial(A5, A4); // RX, TX
#define COMSerial SSerial
#define ShowSerial Serial 
RH_RF95<SoftwareSerial> driver(COMSerial);

#define RH_MESH_MAX_MESSAGE_LEN 50

// variable permettant d'identifier les intersections une à une 
#define MESH1_ADDRESS 1
#define MESH2_ADDRESS 2
#define MESH3_ADDRESS 3
#define MESH4_ADDRESS 4

// choix de la variable pour l'intersection 
RHMesh manager(driver, MESH3_ADDRESS);



void setup() {
  Serial.begin(9600);
  ShowSerial.begin(9600);
  pinMode(mainRedLightPin, OUTPUT);
  pinMode(mainGreenLightPin, OUTPUT);
  pinMode(secondRedLightPin, OUTPUT);
  pinMode(secondGreenLightPin, OUTPUT);
  if (!manager.init())
     ShowSerial.println("init failed");
  Serial.println("-- Initialization --");
  startTimer = millis();  //initial start time
}

uint8_t data[] = "prout prout";
uint8_t back[] = "And hello back to you from mesh 2";
// Dont put this on the stack:
uint8_t buf[RH_MESH_MAX_MESSAGE_LEN];
int check = 0;

void loop() {
  // mise a jour du temps courant et calcul de la periode courante
  updateTimers();
  
  // lecture des valeurs des capteurs
  readSensorValues();

  // ecriture dans le port serie des valeurs des capteurs pour deboggage
  // printSensorValues();

  // verifie si un changement doit etre applique
  checkStateChange();

  // applique le changement
  doStateChange();

  // delay(250);
  printSensorValues();

}

/*
Timer functions
*/

// update current timer and period timer
void updateTimers() {
  currentTimer = millis();
  periodTimer = currentTimer - startTimer;
}

// reset timers
void resetTimers() {
  startTimer = currentTimer;
  periodTimer = 0;
}

/*
Sensors functions
*/

// lecture des valeurs des capteurs et ecriture de celles ci dans les variables correspondantes
void readSensorValues() {
  mainCloseSensorValue = analogRead(mainCloseSensorPin);
  mainFarSensorValue = analogRead(mainFarSensorPin);
  secondCloseSensorValue = analogRead(secondCloseSensorPin);
  // secondFarSensorValue = analogRead(secondFarSensorPin);
}

/*
Debug functions
*/

// ecriture dans le port serie des valeurs des capteurs pour deboggage
void printSensorValues() {
  Serial.print("mainCloseSensorValue    =  ");
  Serial.println(mainCloseSensorValue);
  Serial.print("mainFarSensorValue      =  ");
  Serial.println(mainFarSensorValue);
  Serial.print("secondCloseSensorValue  =  ");
  Serial.println(secondCloseSensorValue);
  // Serial.print("secondFarSensorValue    =  ");
  // Serial.println(secondFarSensorValue);
}

/*
Output functions
*/

// fonction verifiant le changement d etat des feux
// s il y a changement alors appelle les fonctions de changement de de couleurs
void doStateChange() {
  if (changeTo == 1) {
    main_to_green();
    delay(delay_1);
  } else if (changeTo == 2) {
    second_to_green();
    delay(delay_1);
  } else if (changeTo == 3) {
    main_to_green();
    delay(delay_2);
  } else if (changeTo == 4) {
    second_to_green();
    delay(delay_2);
  } else if (changeTo == 5) {
    if (currentState == 2) {
      main_to_green();
      newState = 1;
      resetTimers();
      delay(delay_2);
    } else {
      second_to_green();
      newState = 2;
      resetTimers();
      delay(delay_2);
    }
  }
  
  if (changeTo != 0) {
    currentState = newState;
    resetTimers();
    changeTo = 0;
  }
}

// envoie des informations aux feux
void writeLightState() {
  digitalWrite(mainRedLightPin, mainRedLightState);
  digitalWrite(mainGreenLightPin, mainGreenLightState);
  digitalWrite(secondRedLightPin, secondRedLightState);
  digitalWrite(secondGreenLightPin, secondGreenLightState);
}

// fonction de changement de couleur d une intersection
void main_to_green() {
  secondRedLightState = HIGH;
  secondGreenLightState = LOW;
  writeLightState();
  delay(500);
  mainRedLightState = LOW;
  mainGreenLightState = HIGH;
  writeLightState();
  sprintf(data, "%d", mainGreenLightState);
  sendData();
  check = 0;
  //Serial.println(" -- Main to green --");
}

// fonction de changement de couleur d une intersection
void second_to_green() {
  mainRedLightState = HIGH;
  mainGreenLightState = LOW;
  writeLightState();
  delay(500);
  secondRedLightState = LOW;
  secondGreenLightState = HIGH;
  writeLightState();
  sprintf(data, "%d", mainGreenLightState);
  sendData();
  check = 0;
  //Serial.println(" -- Second to green --");
}

/*
Logical functions
*/

// fonction etudiant les differentes conditions pour changer d etat
// ecrit le nouvel etat des feux
void checkStateChange() {
  changeStateAlgorithm();
  if (changeStatePedestrianTimer()) {
    if (currentState == 1) {
      newState = 2;
    } else {
      newState = 1;
    }
  }
}

// algorithme de decision de l etat des feux en fonction des valeurs des capteurs
// appelle les fonctions de changement d etat des intersections
void changeStateAlgorithm() {
  if (mainCloseSensorValue > sensor_offset && secondCloseSensorValue < sensor_offset && currentState == 2) {
    changeTo = 1;
    newState = 1;
  }
  
  else {
    if (mainCloseSensorValue < sensor_offset && secondCloseSensorValue > sensor_offset && currentState == 1) {
      changeTo = 2;
      newState = 2;
    }

    else {
      if (mainFarSensorValue > sensor_offset && currentState == 2) {
        changeTo = 3;
        newState = 1;
      }
/*
      else {
        if (mainFarSensorValue < sensor_offset && secondFarSensorValue > sensor_offset && currentState == 1) {
          changeTo = 4;
          newState = 2;
        }
      }
*/
    }

  }
}

// algorithme de verification du depassement du temps maximum pour pieton
boolean changeStatePedestrianTimer() {
  if (periodTimer > pedestrianMaxDelay) {
    changeTo = 5;
    return true;
  }
}

/*
LoRa functions
*/

void sendData(){
  while(check==0){
    char addr= '1';
    uint8_t len = sizeof(buf);
    uint8_t from;
    
    if(ShowSerial.available())
    {
        addr = ShowSerial.read();
    }
    
    if(addr > '0' && addr <= '4')
    {
        // Send a message to a mesh
        // It will be routed by the intermediate
        // nodes to the destination node, accorinding to the
        // routing tables in each node
        // ShowSerial.print("Send message to mesh ");
        // ShowSerial.println(addr - '0');
        if(manager.sendtoWait(data, sizeof(data), addr - '0') == RH_ROUTER_ERROR_NONE)
        {
            // It has been reliably delivered to the next node.
            // Now wait for a reply from the ultimate router
            memset(buf, 0, len);
            if(manager.recvfromAckTimeout(buf, &len, 3000, &from))
            {
                //ShowSerial.print("got reply from : 0x");
                //ShowSerial.print(from, HEX);
                //ShowSerial.print(": ");
                //ShowSerial.println((char*)buf);
                check+=1;
            }
            else
            {
                //ShowSerial.println("No reply, are meshes running?");
            }
        }
        else ShowSerial.println("sendtoWait failed. Are the intermediate meshes running?");
        addr = 0;     
    }
  }
}
