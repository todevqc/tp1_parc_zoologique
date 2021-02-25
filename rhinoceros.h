#ifndef __RHINOCEROS_H__
#define __RHINOCEROS_H__

#include <iostream>
#include <string>

#include "animal.h"

class Rhinoceros : public Animal{
    private:
        int superficieEspace;
    public:
        Rhinoceros(std::string nom, double poids, int superficieEspace);
        double calculerDiete();
};

#endif