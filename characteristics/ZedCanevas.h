ZedCanevas::ZedCanevas():actionMoteur(){}
void ZedCanevas::move(){actionMoteur->move(); return;}
void ZedCanevas::forward(int puissance){actionMoteur->forward(puissance); return;}
void ZedCanevas::moveBack(){actionMoteur->moveBack(); return;}
void ZedCanevas::stepTurn(int dir){actionMoteur->stepTurn(dir); return;}
void ZedCanevas::resetCounterGauche(){actionMoteur->resetCounterGauche(); return;}
void ZedCanevas::resetCounterDroite(){actionMoteur->resetCounterDroite(); return;}
int ZedCanevas::readCounterGauche(){return actionMoteur->readCounterGauche();}
int ZedCanevas::readCounterDroite(){return actionMoteur->readCounterDroite();}

void ZedCanevas::bindServiceActionMoteur(ServiceActionMoteur* service) {
    actionMoteur=service;
    return;
}
