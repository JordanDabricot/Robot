#include "Parameters.h"

int main() {
    //---INSTANCIATIONS---//
    ServiceActionMoteur* hardware;
    BrainCanevas* brain;

    hardware=new Hardware();
    brain=new BrainCanevas();

    //---BINDING---//
    brain->bindServiceActionMoteur(hardware);

    //---CORPS PRINCIPAL---//
    brain->activate();

    //wait(1);
    while(1){
        hardware->stop();
        brain->step();
        wait(0.1);
    }
}
