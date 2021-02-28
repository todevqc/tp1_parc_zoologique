#include "rhinoceros.h"

Rhinoceros::Rhinoceros(std::string sonNom, double sonPoids, int superficie) : Animal(sonNom, sonPoids){
    if (superficie >= 2000){
        this->superficieEspace = superficie; 
    }else{
        this->superficieEspace = 2000; 
    }
    this->calculerDiete();
}

void Rhinoceros::calculerDiete(){
    double fruits = (this->poids*0.5)/100;
    double herbe = 0;
    //calcule si besoin d'un supplement ou pas d'herbe
    double herbeDisponible = (this->superficieEspace*10)/1000;
    //calcule de l'apport quotidient en herbe de l'enclos 
    double apportQuotidienEnclos = (herbeDisponible*100)/this->poids;
    if (apportQuotidienEnclos < 2){
        double supplementHerbe = 2 - apportQuotidienEnclos;
        herbe = (this->poids*supplementHerbe)/100;
    }
    this->dieteJour->dieteAnimal(0, fruits, herbe);
}

void Rhinoceros::informationsAnimal(){    
    std::cout << "\nRhinoceros : " << this->nom << " (" << this->poids << " kg)" << std::endl;
    std::cout << "  Enclos de " << this->superficieEspace << " metres-carres" << std::endl; 
}