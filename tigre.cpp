#include "tigre.h"

Tigre::Tigre(std::string nom, double poids) : Animal(nom, poids){
    this->calculerDiete();
    std::cout << "Tigre creer" << std::endl;
}

void Tigre::calculerDiete(){
    double viande = (this->poids*5)/100;
    this->dieteJour->dieteAnimal(viande, 0, 0);
}

void Tigre::informationsAnimal(){    
    std::cout << "Tigre : " << this->nom << " (" << this->poids << " kg)" << std::endl;    
}