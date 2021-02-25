#include "rhinoceros.h"

Rhinoceros::Rhinoceros(std::string nom, double poids, int superficieEspace) : Animal(nom, poids){
    this->superficieEspace = superficieEspace; 
}

double Rhinoceros::calculerDiete(){

    double diete = 0;
    //fruit
    diete += (this->poids*0.5)/100;
    //calcule si besoin d'un supplement ou pas d'herbe
    double herbeDisponible = (this->poids*10)/1000;
    if (((herbeDisponible*100)/this->poids) < 2){
        double supplementHerbe = 2 - ((herbeDisponible*100)/this->poids);
        diete += (this->poids*supplementHerbe)/100;
    }
    
    return diete;
}