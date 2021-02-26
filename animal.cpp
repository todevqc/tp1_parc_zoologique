#include "animal.h"

Animal::Animal(std::string le_nom, double le_poids){
    this->nom = le_nom;
    this->poids = le_poids;
    this->dieteJour = new Diete();
    std::cout << "Animal creer" << std::endl;
}


void Animal::afficherDiete(){
    std::cout << "  Mange " << this->dieteJour->getViande() << " kg de viande par jour" << std::endl;
    std::cout << "  Mange " << this->dieteJour->getFruits() << " kg de fruits par jour" << std::endl;
    std::cout << "  Mange " << this->dieteJour->getHerbe() << " kg d'herbe par jour" << std::endl;

}

Diete* Animal::getDieteJour(){
    return this->dieteJour;
}

Animal::~Animal(){
    delete this->dieteJour;
    std::cout << "Animal detruit" << std::endl;
};