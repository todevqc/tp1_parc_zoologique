#ifndef __SINGE_H__
#define __SINGE_H__

#include <iostream>
#include <string>

#include "animal.h"

class Singe : public Animal{
    private:
        bool enclosAvecHerbe;
    public:
        Singe(std::string nom, double poids, bool enclosAvecHerbe);
        Diete* calculerDiete();
        void informationsAnimal();
};

#endif