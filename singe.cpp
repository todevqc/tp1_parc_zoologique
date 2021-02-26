#include "singe.h"

Singe::Singe(std::string nom, double poids, bool enclosAvecHerbe) : Animal (nom, poids){
    this->enclosAvecHerbe = enclosAvecHerbe;
    this->calculerDiete();
}

void Singe::calculerDiete(){
    double viande = (this->poids*1)/100;
    double fruits = (this->poids*1)/100;
    double herbe = 0;
    if (!this->enclosAvecHerbe){
        herbe = (this->poids*0.5)/100;
    }
    this->dieteJour->dieteAnimal(viande, fruits, herbe);
}

void Singe::informationsAnimal(){    
    std::cout << "Singe : " << this->nom << " (" << this->poids << " kg)" << std::endl;
    if (this->enclosAvecHerbe) {
        std::cout << "  Enclos avec herbe" << std::endl;
    }else{
        std::cout << "  Enclos sans herbe" << std::endl;
    }  
}