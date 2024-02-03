//By: Charles Koduru 
//12/13/2023-- started intial positioning with servos

#include <Wire.h>
#include<Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

// Servo Limits
//min =160
//max = 680


 //int alpha = 0--not in use;
 int alpha =1;
 int alphaServoMin = 350;//300
 int alphaServoMax = 550;//600
 int alphaInital = 180;
 int alphaCount = 280;

 int bravo =2;
 int bravoServoMin = 550;
 int bravoServoMax = 700;
 int bravoInital = 10;
 int bravoCount = 610;

 int charlie =3;
 int charlieServoMin = 460;
 int charlieServoMax = 780;
 int charlieInital = 20;
 int charlieCount = 360;

 int delta =4;
 int deltaServoMin = 180;
 int deltaServoMax = 580;
 int deltaInital = 50;
 int deltaCount = 180;

 int echo =5;
 int echoServoMin = 0;
 int echoServoMax = 800;
 int echoInital = 0;
 int echoCount = 100;


unsigned long previousMillis = 0;
const long interval = 10; // I

int chooseServo;
int levelServo;
int count = 280; // Initial value



void setup() {
  Serial.begin(9600);
  Serial.println("PCA9685 Servo Test");

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

 
  Serial.println("Please choose a servo and select the postions.");
    Serial.println("Use the '+' and '-' sign to change the servo position.");
    Serial.println("Then click the '0' key to choose the next servo");
    Serial.println("_____________________________________________________");
    Serial.println("Start -> '8'  |  Stop -> '9'");
    Serial.println("1 | 2 | 3 | 4 | 5");
}



void loop() {
 
  keyboardServo();
  
   // exit(0);//exits loops
}

void deltaServo(){
  //DELTA -- good
  for(int x = 0; x<2;x++){// loops how many times it opens/closes

      for (int pulselen = deltaServoMin; pulselen < deltaServoMax; pulselen++) {
        pwm.setPWM(delta, deltaInital, pulselen);
      }

      delay(1000);

      // Move servo from max to min position
      for (int pulselen = deltaServoMax; pulselen > deltaServoMin; pulselen--) {
        pwm.setPWM(delta, deltaInital, pulselen);
      }
      delay(1000);

      }
      int middle = (deltaServoMax+deltaServoMin)/2;
      for (int pulselen = deltaServoMin; pulselen < middle; pulselen++) {
        pwm.setPWM(delta, deltaInital, pulselen);

      }
      delay(1000);
      Serial.println("delta Servo");
      exit(0);
    }


void echoServo(){
   //Echo -- good
  for(int x = 0; x<1;x++){// loops how many times it opens/closes

      for (int pulselen = echoServoMin; pulselen < echoServoMax; pulselen++) {
        pwm.setPWM(echo, echoInital, pulselen);

      }

      delay(1000);

      // Move servo from max to min position
      for (int pulselen = echoServoMax; pulselen > echoServoMin; pulselen--) {
        pwm.setPWM(echo, echoInital, pulselen);
      }
      delay(1000);

      }
      int middle = (echoServoMax+echoServoMin)/2;
      for (int pulselen = echoServoMin; pulselen < middle; pulselen++) {
        pwm.setPWM(echo, echoInital, pulselen);
      }
      delay(1000);
      Serial.println("Echo Server");
      exit(0);
    }

void charlieServo(){
  //charlie -- good
 // for(int x = 0; x<2;x++){// loops how many times it opens/closes

      
      for (int pulselen = charlieServoMin; pulselen < charlieServoMax; pulselen++) {
        pwm.setPWM(charlie, charlieInital, pulselen);
        delay(10);
      }

      delay(1000);

      // Move servo from max to min position
      for (int pulselen = charlieServoMax; pulselen > charlieServoMin; pulselen--) {
        pwm.setPWM(charlie, charlieInital, pulselen);
        delay(10);
      }
      delay(1000);

      //}
      int middle = (charlieServoMax+charlieServoMin)/6;//4
      for (int pulselen = charlieServoMin; pulselen < middle; pulselen++) {
        pwm.setPWM(charlie, charlieInital, pulselen);
        delay(10);
      }
      delay(1000);
      Serial.println("Charlie Server");
      exit(0);
    }

void bravoServo(){
   //bravo -- good 
  for(int x = 0; x<1;x++){// loops how many times it opens/closes

      
      for (int pulselen = bravoServoMin; pulselen <= bravoServoMax; pulselen++) {
        pwm.setPWM(bravo, bravoInital, pulselen);
        delay(15);
      }

      delay(1000);

      // Move servo from max to min position
      for (int pulselen = bravoServoMax; (pulselen >= bravoServoMin) | (pulselen >= bravoServoMin-10) ; pulselen--) {
        pwm.setPWM(bravo, bravoInital, pulselen);
        delay(15);
      }
      delay(1000);

      }
      int middle = bravoServoMax-((bravoServoMax+bravoServoMin)/40);
      for (int pulselen = bravoServoMin; pulselen <= middle; pulselen++) {
        pwm.setPWM(bravo, bravoInital, pulselen);
        delay(15);
      }
      delay(1000);
      Serial.println("Bravo Server");
      exit(0);

    }

void alphaServo(){
    //for(int x = 0; x<1;x++){// loops how many times it opens/closes

          
          for (int pulselen = alphaServoMin; pulselen <= alphaServoMax; pulselen++) {
            pwm.setPWM(alpha, alphaInital, pulselen);
            delay(30);
          }

          delay(1000);

          // Move servo from max to min position
          for (int pulselen = alphaServoMax; (pulselen >= alphaServoMin) | (pulselen >= alphaServoMin-10) ; pulselen--) {
            pwm.setPWM(alpha, alphaInital, pulselen);
            delay(30);
          }
          delay(1000);

          //}

          int middle = alphaServoMax-((alphaServoMax+alphaServoMin)/40);
          for (int pulselen = alphaServoMin; pulselen <= middle; pulselen++) {
            pwm.setPWM(alpha, alphaInital, pulselen);
            delay(30);
          }
          delay(1000);
      Serial.println("Alpha Server");
      exit(0);
    }

void initalPos(){


      pwm.setPWM(charlie, 0, 360);
      delay(500);
      pwm.setPWM(alpha, 0, 280);
      delay(500);
      pwm.setPWM(bravo, 0,610);
      delay(500);

      //open close stuff
      pwm.setPWM(delta,0,180);
      delay(500);
      pwm.setPWM(delta,0,580);
      delay(500);
      pwm.setPWM(delta,0,180);
      delay(500);
      pwm.setPWM(echo,0,100);
      delay(500);
      pwm.setPWM(echo,0,500);
      delay(500);
      pwm.setPWM(echo,0,100);
      delay(500);
      pwm.setPWM(echo,0,300);
      delay(2000);
      pwm.setPWM(delta,0,180);
      delay(500);
      pwm.setPWM(delta,0,580);
      delay(500);
      pwm.setPWM(delta,0,180);
      delay(500);

    }


void stopServo(){

      pwm.setPWM(echo, 0,4096);
      delay(500);
      pwm.setPWM(delta, 0,4096);
      delay(500);
      pwm.setPWM(charlie, 0, 4096);
      delay(500);
      pwm.setPWM(bravo, 0,4096);
      delay(500);
      pwm.setPWM(alpha, 0, 4096);
      delay(500);
    }

void keyboardServo(){
         // '-' -> 45 write
    // '+' -> 43 write
    
  if (Serial.available()) {
    chooseServo = Serial.read();
    delay(1000);

    Serial.println(chooseServo);

    if (chooseServo == '1') {
      int oCount = alphaCount;
      Serial.println("Alpha Servo");

      while (true) {
        if (Serial.available() > 0) {
          levelServo = Serial.read();

          if (levelServo == 43) {
            Serial.println("rise");
            if (oCount + 20 <= alphaServoMax) {
              oCount += 20;
            } else {
              oCount = alphaServoMax;
            }            pwm.setPWM(alpha, 0, oCount);
            delay(500);
            Serial.println(oCount);

          } else if (levelServo == 45) {
            Serial.println("lower");
            if (oCount - 20 >= alphaServoMin) {
              oCount -= 20;
            } else {
              oCount = alphaServoMin;
            }            pwm.setPWM(alpha, 0, oCount);
            delay(500);
            Serial.println(oCount);

          } else if (levelServo == 48) {
            Serial.println("break");
            alphaCount = oCount;
            break;
          }
        }
      }
    }


    if (chooseServo == '2') {
      int oCount = bravoCount;
      Serial.println("Bravo Servo");

      while (true) {
        if (Serial.available() > 0) {
          levelServo = Serial.read();

          if (levelServo == 43) {
            Serial.println("rise");
            if (oCount + 20 <= bravoServoMax) {
              oCount += 20;
            } else {
              oCount = bravoServoMax;
            }
            pwm.setPWM(bravo, 0, oCount);
            delay(500);
            Serial.println(oCount);

          } else if (levelServo == 45) {
            Serial.println("lower");
            if (oCount - 20 >= bravoServoMin) {
              oCount -= 20;
            } else {
              oCount = bravoServoMin;
            }            pwm.setPWM(bravo, 0, oCount);
            delay(500);
            Serial.println(oCount);

          } else if (levelServo == 48) {
            Serial.println("break");
            bravoCount = oCount;
            break;
          }
        }
      }
    }

    if (chooseServo == '3') {
      int oCount = charlieCount;
      Serial.println("Charlie Servo");

      while (true) {
        if (Serial.available() > 0) {
          levelServo = Serial.read();

          if (levelServo == 43) {
            Serial.println("rise");
            if (oCount + 20 <= charlieServoMax) {
              oCount += 20;
            } else {
              oCount = charlieServoMax;
            }
            pwm.setPWM(charlie, 0, oCount);
            delay(500);
            Serial.println(oCount);

          } else if (levelServo == 45) {
            Serial.println("lower");
            if (oCount - 20 >= charlieServoMin) {
              oCount -= 20;
            } else {
              oCount = charlieServoMin;
            }            pwm.setPWM(charlie, 0, oCount);
            delay(500);
            Serial.println(oCount);

          } else if (levelServo == 48) {
            Serial.println("break");
            charlieCount = oCount;
            break;
          }
        }
      }
    }

    if (chooseServo == '4') {
      int oCount = deltaCount;
      Serial.println("Delta Servo");

      while (true) {
        if (Serial.available() > 0) {
          levelServo = Serial.read();

          if (levelServo == 43) {
            Serial.println("rise");
             if (oCount + 100 <= deltaServoMax) {
              oCount += 100;
            } else {
              oCount = deltaServoMax;
            }

            pwm.setPWM(delta, 0, oCount);
            delay(500);
            Serial.println(oCount);

          } else if (levelServo == 45) {
            Serial.println("lower");
            if (oCount - 100 >= deltaServoMin) {
              oCount -= 100;
            } else {
              oCount = deltaServoMin;
            }
            pwm.setPWM(delta, 0, oCount);
            delay(500);
            Serial.println(oCount);

          } else if (levelServo == 48) {
            Serial.println("break");
            deltaCount = oCount;
            break;
          }
        }
      }
    }
  
    if (chooseServo == '5') {
      int oCount = echoCount;
      Serial.println("Echo Servo");

      while (true) {
        if (Serial.available() > 0) {
          levelServo = Serial.read();

          if (levelServo == 43) {
            Serial.println("rise");
            if (oCount + 20 <= echoServoMax) {
              oCount += 20;
            } else {
              oCount = echoServoMax;
            }            pwm.setPWM(echo, 0, oCount);
            delay(500);
            Serial.println(oCount);

          } else if (levelServo == 45) {
            Serial.println("lower");
            oCount -= 20;
            pwm.setPWM(echo, 0, oCount);
            delay(500);
            Serial.println(oCount);

          } else if (levelServo == 48) {
            Serial.println("break");
            echoCount = oCount;
            break;
          }
        }
      }
    }
  
    if (chooseServo == '7'){
      keyboardServo();
      delay(1000);

    }
    if (chooseServo == '8') {
      initalPos();
      delay(1000);
    }
      
    if (chooseServo == '9') {
      stopServo();
      delay(1000);

    }
  
    
  


    Serial.println("done"); 
  }


    }
