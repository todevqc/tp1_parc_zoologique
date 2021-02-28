#include "tigre.h"
/**
 * Constructeur d'initialisation d'un tigre
 * @param nom represente le nom du tigre
 * @param poids represente le poids du tigre
*/
Tigre::Tigre(std::string nom, double poids) : Animal(nom, poids){
}
/**
 * calcule la diète d'un tigre et retourne un pointeur vers un objet Diete associer
*/
Diete* Tigre::calculerDiete(){
    double viande = (this->poids*5)/100;
    return new Diete(viande, 0, 0);
}

void Tigre::informationsAnimal(){    
    std::cout << "\nTigre : " << this->nom << " (" << this->poids << " kg)" << std::endl;    
}