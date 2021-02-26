#include "diete.h"

Diete::Diete(){
    this->viande = 0;
    this->fruits = 0;
    this->herbe = 0;
    std::cout << "Diete creer" << std::endl;
}

void Diete::dieteAnimal(double besoinsViande, double besoinsFruits, double besoinsHerbe){
    this->viande = besoinsViande;
    this->fruits = besoinsFruits;
    this->herbe = besoinsHerbe;
}

double Diete::getViande(){
    return this->viande;
}

double Diete::getFruits(){
    return this->fruits;
}

double Diete::getHerbe(){
    return this->herbe;
}