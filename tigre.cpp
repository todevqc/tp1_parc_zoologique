#include "tigre.h"
/**
 * Constructeur d'initialisation d'un tigre, avec calcule de sa diète
 * @param nom represente le nom du tigre
 * @param poids represente le poids du tigre
*/
Tigre::Tigre(std::string nom, double poids) : Animal(nom, poids){
    this->calculerDiete();
}
/**
 * calcule la diète d'un tigre et enregistre les données
*/
void Tigre::calculerDiete(){
    double viande = (this->poids*5)/100;
    this->dieteJour->dieteAnimal(viande, 0, 0);
}

void Tigre::informationsAnimal(){    
    std::cout << "Tigre : " << this->nom << " (" << this->poids << " kg)" << std::endl;    
}