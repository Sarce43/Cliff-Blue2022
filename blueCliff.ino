#include<DC_motor_controller.h>
#include<TwoMotors.h>
#include<VL53L0X.h>
#include<Wire.h>

////////////////////////// program of Readme ///////////////////////////////
void blinkLed(uint8_t turns, uint16_t time, bool keep = false);
void readDistances (char side = 'A');
void blink_forever (uint16_t time = 250);

/////////////////////////////Pins//////////////////////////////////////////////
#define distF_act 5               //Pin of VL front
#define distL_act 6               //Pin of VL Left
#define distB_act 7               //Pin of VL Behind

#define lineR_Exp 4               // Right line sensors of expansor
#define lindeM_Exp 3              // Mid line sensors of expansor
#define lineL_Exp 2               // Left line sensors of expansor 

#define expanser_address 0x20     // Address of expanser
#define ledExp 1                  // LED from expansor pin
#define button 0                  //program boot button

/////////////////////// state variables /////////////////////////////////

float distanceF = 0;                // Setting the state of sensors at start
float distanceB = 0;
float distanceL = 0;

bool lineR = false;
bool lineM = false;
bool lineL = false;



//////////////////////// Definitions ////////////////////////////////////////
DC_motor_controller motR;
DC_motor_controller motL;

TwoMotors both(&motL, &motR);

VL53L0X distF;
VL53L0X distL;
VL53L0X distB;

//////////////////// globals variables ////////////////////////////////
#define fast = 100;
#define halFast = 50;


void setup () {
  Wire.begin();

  turnPin(ledExp, 0);
  blinkLED(1,150, true);
  initDistanceSensors();
  
  motR.hBridge(9,10,11);
  motR.setEncoderPin(3,5);
  motR.setRR(21.3);
  motR.setPIDconstants(1.2,0.35,0.05);
  motR.setPins();


attachInterrupt(digitalPinToInterrupt(3),interR,FALLING);
}
void loop () {
  
}
