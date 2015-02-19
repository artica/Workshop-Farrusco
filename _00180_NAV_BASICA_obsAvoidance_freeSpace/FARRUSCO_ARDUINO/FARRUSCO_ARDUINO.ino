/*  ----------------------------------------------------------------------------
 *  WWW.GUIBOT.PT                                                  WWW.ARTICA.CC
 *  ----------------------------------------------------------------------------
 *  FARRUSCO BASIC NAVIGATION
 *  ----------------------------------------------------------------------------
 *
 * Programa que Evita Obstaculos e testa funcionalidades basicas do Farrusco.
 * Os Delays foram removidos e agora usam-se intervalos de tempo com a biblioteca Metro,
 * isto possibilita a implementacao de computacao paralela.
 *
 *
 * This Obstacle Avoidance program tests Farrusco's basic features.  
 * Delays were removed and time intervals were added to perform parallel computing, 
 * Metro library is required. 
 *
 *
 *  Components                    Functions                Parameters
 *
 * - Servo                         ServoRange()             min, max, delay, increment
 * - Bumpers                       BumperReader()
 * - Infra-Red Sensor              ReadIR()
 *
*/
#include <EEPROM.h>
#include <Metro.h>


// navigation state
byte navState;

const int MAX_VELOCITY = 255;
// --------------------------------------------------------------------------- METRO

Metro servoMetro = Metro(25); 
Metro servoDelayMetro = Metro(25);
Metro bumperMetro = Metro(100); 
Metro sensorIRMetro = Metro(50); 
Metro serialMetro = Metro(50); 
Metro becoMetro = Metro(500); 




// --------------------------------------------------------------------------- BUMPERS
int bumperLeft = 8;
int bumperRight = 7;

int BLeft, BRight;
// calibration variables, use it to perform a straight path
byte maxSpeedLeft = 255;
byte maxSpeedRight = 255;


// --------------------------------------------------------------------------- IR SENSOR
int IRPin = 0;
int IRValue;

// --------------------------------------------------------------------------- SETUP
void ReadEepromValues()
{
  navState = EEPROM.read(0);
  MotorSetMaxVelocity(EEPROM.read(1), EEPROM.read(2));
}
void StoreEepromValues()
{
  EEPROM.write(0,navState);
  EEPROM.write(1,maxSpeedLeft);
  EEPROM.write(2,maxSpeedRight);
}


void setup() 
{
  Serial.begin(115200);
  
  ReadEepromValues();
  
  MotorSetup();
  ServoSetup();
  HeartBitSetup();
  
  // frontal bumpers
  pinMode (bumperLeft, INPUT);
  pinMode (bumperRight, INPUT);  
  // activate internal resistence
  digitalWrite(bumperLeft, HIGH);
  digitalWrite(bumperRight, HIGH);
  
  
  obstacleAvoidanceSetup();
  delay(1000);
}


// --------------------------------------------------------------------------- LOOP

void loop() 
{

  HeartBit();
  
  if (!ProcessingUpdate()) {
    switch(navState)
    {
      case 0:
        ObstacleAvoidanceUpdate();
        break;
      case 1: 
        FreeSpaceUpdate();
        break;
    } 
  }

}

