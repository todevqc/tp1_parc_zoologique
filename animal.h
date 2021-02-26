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
        virtual ~Animal();
        virtual void calculerDiete() = 0;
        void afficherDiete();
        virtual void informationsAnimal(){}
        Diete* getDieteJour();
};

#endif