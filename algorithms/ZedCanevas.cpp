#include "Parameters.h"
#include "ZedCanevas.h"

int MAXPASDEJEU=900;
int pasDeJeuZ;

void ZedCanevas::activate() {
	pasDeJeuZ=0;
    //wait(1);
    //actionMoteur->initHeadingDeg();
    return;
}

void ZedCanevas::step() {

	if (pasDeJeuZ>MAXPASDEJEU) {return;}
    pasDeJeuZ++;


/***************** Dessine un Z *****************/
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

    return;
}
