#include "Parameters.h"

int main() {
    //---INSTANCIATIONS---//
    ServiceActionMoteur* hardware;
    // BrainCanevas* brain;
    ZedCanevas* zed;

    hardware=new Hardware();
    // brain=new BrainCanevas();
    zed=new ZedCanevas();

    //---BINDING---//
    // brain->bindServiceActionMoteur(hardware);
    zed->bindServiceActionMoteur(hardware);

    //---CORPS PRINCIPAL---//
    // brain->activate();
    zed->activate();

    //wait(1);
    while(1){
        hardware->stop();
        // brain->step();
        zed->step();
        wait(0.1);
    }
}
