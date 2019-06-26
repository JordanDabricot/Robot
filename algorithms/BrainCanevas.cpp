#include "Parameters.h"
#include "BrainCanevas.h"

int MAXPASDEJEU=900;

int pasDeJeuCourrant;
int pasDeJeuZ;

void BrainCanevas::activate() {
  pasDeJeuCourrant=0;
	pasDeJeuZ=0;
    //wait(1);
    //actionMoteur->initHeadingDeg();
    return;
}

void BrainCanevas::step() {

    if (pasDeJeuCourrant>MAXPASDEJEU) {return;}
    pasDeJeuCourrant++;

	if (pasDeJeuZ>MAXPASDEJEU) {return;}
    pasDeJeuZ++;


    //SOME RANDOM STUFF
    //  if (pasDeJeuCourrant>=121){
    //     if (readCounterGauche()>=10000 && readCounterDroite() >=10000) {
    //         moveBack();
    //         if (readCounterGauche()>=15000 && readCounterDroite()>=15000){
    //             resetCounterDroite();
    //             resetCounterGauche();
    //         }
    //     } else {
    //         move();
    //     }
    //     return;
    // }
    // if (pasDeJeuCourrant>=120){
    //     resetCounterGauche();
    //     resetCounterDroite();
    // }
    // if (pasDeJeuCourrant>=100){
    //     moveBack();
    //     return;
    // }
    //
    // if (pasDeJeuCourrant>=80){
    //     stepTurn(RIGHT);
    //     return;
    // }
    //
    // if (pasDeJeuCourrant>=60){
    //     move();
    //     return;
    // }
    //
    // if (pasDeJeuCourrant>=40){
    //     stepTurn(LEFT);
    //     return;
    // }
    //
    // if (pasDeJeuCourrant>20 && pasDeJeuCourrant<40){
    //     return;
    // }
    //
    // if (pasDeJeuCourrant<=20){
    //     move();
    //     return;
    // }
    //
    // return;

	//Itineraire Z Line
    // if (pasDeJeuZ>=121){
    //     if (readCounterGauche()>=10000 && readCounterDroite() >=10000) {
    //         moveBack();
    //         if (readCounterGauche()>=15000 && readCounterDroite()>=15000){
    //             resetCounterDroite();
    //             resetCounterGauche();
    //         }
    //     } else {
    //         move();
    //     }
    //     return;
    // }
    // if (pasDeJeuZ>=120){
    //     resetCounterGauche();
    //     resetCounterDroite();
    // }
    // if (pasDeJeuZ){
    //     move();
    //     return;
    // }

    if (pasDeJeuZ < 40){
      forward(600);
      return;
    }

    if (pasDeJeuZ < 45){
      stepTurn(DIAGONALD);
      return;
    }

    if (pasDeJeuZ < 75){
      forward(600);
      return;
    }

    if (pasDeJeuZ < 81){
      stepTurn(DIAGONALG);
      return;
    }

    if (pasDeJeuZ < 110){
      forward(700);
      return;
    }

    //
    //
    //
    // if (pasDeJeuZ<=80){
    //     stepTurn(DIAGONALG);
    //     return;
    // }
    //
    // /* if (pasDeJeuZ>20 && pasDeJeuZ<40){
    //     return;
    // } */
    //
    // if (pasDeJeuZ>=121){
    //     move();
    //     return;
    // }

    return;
}
