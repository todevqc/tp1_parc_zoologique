#include "tigre.h"

Tigre::Tigre(std::string nom, double poids) : Animal(nom, poids){

}

double Tigre::calculerDiete(){
    return ((this->poids*5)/100);
}
