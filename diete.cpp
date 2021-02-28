#include "diete.h"

Diete::Diete(double besoinsViande, double besoinsFruits, double besoinsHerbe){
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