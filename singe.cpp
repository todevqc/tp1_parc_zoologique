#include "singe.h"

Singe::Singe(std::string nom, double poids, bool enclosAvecHerbe) : Animal (nom, poids){
    this->enclosAvecHerbe = enclosAvecHerbe;
}

double Singe::calculerDiete(){
    double diete = 0;
    diete += (this->poids*1)/100;
    diete += (this->poids*1)/100;
    if (!this->enclosAvecHerbe){
        diete += (this->poids*0.5)/100;
    }
    return diete;
}