#include "Parameters.h"
#include "HMC5883L.h"
#include "MotorEncoder.h"

#define PWMGAUCHE D9
#define DIRGAUCHE D7
#define PWMDROITE D10
#define DIRDROITE D8
#define I2C_SDA   D14
#define I2C_SCL   D15

PwmOut pwmgauche(PWMGAUCHE);
DigitalOut dirgauche(DIRGAUCHE);
PwmOut pwmdroite(PWMDROITE);
DigitalOut dirdroite(DIRDROITE);
HMC5883L compass(I2C_SDA,I2C_SCL);

Counter counterGauche(PB_14);
Counter counterDroite(PB_13);

double initHeading;

Hardware::Hardware() {
    pwmgauche.period_us(1000);
    pwmdroite.period_us(1000);
    pwmgauche.pulsewidth_us(0);
    pwmdroite.pulsewidth_us(0);
    dirgauche=0;
    dirdroite=0;
    //compass.init();
    //initHeading=compass.getHeadingXYDeg();
}

void Hardware::move() {
    dirgauche=0;
    dirdroite=1;
    pwmgauche.pulsewidth_us(600);
    pwmdroite.pulsewidth_us(600);
    return;
}

void Hardware::moveBack() {
    dirgauche=1;
    dirdroite=0;
    pwmgauche.pulsewidth_us(600);
    pwmdroite.pulsewidth_us(600);
    return;
}

void Hardware::stepTurn(int dir) {
  if (dir==RIGHT) {
    dirgauche=0;
    dirdroite=0;
		pwmgauche.pulsewidth_us(800);
		pwmdroite.pulsewidth_us(500);
  } else if(dir==DIAGONALD){
    dirgauche=0;
    dirdroite=0;
    pwmgauche.pulsewidth_us(1000);
    pwmdroite.pulsewidth_us(0);
  } else if(dir==DIAGONALG){
    dirgauche=1;
    dirdroite=1;
    pwmgauche.pulsewidth_us(0);
    pwmdroite.pulsewidth_us(1050);
  } else if(dir==LEFT) {
    dirgauche=1;
    dirdroite=1;
		pwmgauche.pulsewidth_us(500);
		pwmdroite.pulsewidth_us(800);
	}
  return;
}

void Hardware::forward(int puissance) {
    dirgauche=0;
    dirdroite=1;
    pwmgauche.pulsewidth_us(puissance);
    pwmdroite.pulsewidth_us(puissance);
    return;
}

void Hardware::stop() {
    dirgauche=0;
    dirdroite=1;
    pwmgauche.pulsewidth_us(0);
    pwmdroite.pulsewidth_us(0);
    return;
}

void Hardware::initHeadingDeg(){
    compass.init();
    wait(1);
    initHeading=compass.getHeadingXYDeg();
    wait(1);
    return;
}

int Hardware::getHeadingDeg(){
    return fabs(compass.getHeadingXYDeg()-initHeading);
}

void Hardware::resetCounterGauche(){
    return counterGauche.reset();
}

void Hardware::resetCounterDroite(){
    return counterDroite.reset();
}

int Hardware::readCounterGauche(){
    return counterGauche.read();
}

int Hardware::readCounterDroite(){
    return counterDroite.read();
}
