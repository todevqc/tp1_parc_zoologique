#ifndef __RHINOCEROS_H__
#define __RHINOCEROS_H__

#include <iostream>
#include <string>

#include "animal.h"

class Rhinoceros : public Animal{
    private:
        int superficieEspace;
    public:
        Rhinoceros(std::string sonNom, double sonPoids, int superficie);
        void calculerDiete();
        void informationsAnimal();
};

#endif