#ifndef __TIGRE_H__
#define __TIGRE_H__

#include <iostream>
#include <string>

#include "animal.h"

class Tigre : public Animal{
    public:
        Tigre(std::string nom, double poids);
        void calculerDiete();
        void informationsAnimal();
        ~Tigre(){
            std::cout << "Tigre detruit" << std::endl;
        };
};

#endif