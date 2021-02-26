#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <iostream>
#include <string>

#include "diete.h"

class Animal{
    protected:
        std::string nom;
        double poids;
        Diete* dieteJour;
    public:
        Animal(std::string le_nom, double le_poids);
        //  destructeur virtuel qui appel un delete sur l'objet Diete qui lui est associer
        virtual ~Animal();
        //  calcule la diète personnalisé et stock les données dans les variable qui correspondes
        virtual void calculerDiete() = 0;
        //  affichage de la diete d'un animal
        void afficherDiete();
        //  affichage des information de chaque animal, notament son Type
        virtual void informationsAnimal(){}
        //  Getters des informations qui sont utiliser ailleurs dans le logiciel
        Diete* getDieteJour();
        std::string getNom();
};

#endif