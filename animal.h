#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <string>

class Animal{
    protected:
        std::string nom;
        double poids;
    public:
        Animal(std::string le_nom, double le_poids);
        virtual ~Animal(){};
        virtual double calculerDiete() = 0;
};

#endif