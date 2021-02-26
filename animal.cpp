#include "animal.h"
/**
 * Constructeur d'initialisation d'un Animal
 * @param le_nom represente le nom de l'animal
 * @param le_poids represente le poids e l'animal en kg
*/
Animal::Animal(std::string le_nom, double le_poids){
    this->nom = le_nom;
    this->poids = le_poids;
    this->dieteJour = new Diete();
}
/**
 * Affichage de la diète (Viande - Fruits - Herbe)
*/
void Animal::afficherDiete(){
    std::cout << "  Mange " << this->dieteJour->getViande() << " kg de viande par jour" << std::endl;
    std::cout << "  Mange " << this->dieteJour->getFruits() << " kg de fruits par jour" << std::endl;
    std::cout << "  Mange " << this->dieteJour->getHerbe() << " kg d'herbe par jour" << std::endl;
}
/**
 * @return Pointeur sur un objet Diete associé a l'animal
*/
Diete* Animal::getDieteJour(){
    return this->dieteJour;
}
/**
 * @return Le Nom de l'animal
*/
std::string Animal::getNom(){
    return this->nom;
}
/**
 * Desctructeur virtuel de la classe mere animal, qui appel un delete sur l'objet Diete associé 
*/
Animal::~Animal(){
    delete this->dieteJour;
};