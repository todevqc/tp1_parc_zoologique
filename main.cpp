#include <iostream>

#include "animal.h"
#include "tigre.h"
#include "singe.h"
#include "rhinoceros.h"
//#include "diete.h"

int menuZoo();
Animal* ajouterTigre(int& numero);
Animal* ajouterSinge(int& numero);
Animal* ajouterRhinoceros(int& numero);
void compteRenduParc(Animal* unAnimal[], int& nombreAnimeaux);

//// BONUS SUPP
void supprimerAnimal(Animal* unAnimal[], int& nombreAnimeaux);
int animalExiste(std::string nomAnimal, Animal* unAnimal[], int& nombreAnimeaux);
void supprimer(int position, Animal* unAnimal[], int& nombreAnimeaux);

int main() {
    
    // quitter le logiciel si choix = 6, uniquement 
    bool quitterLogiciel = false;

    Animal* animeaux[250];
    int nbr_Animeaux_Parc = 0;

    do{
    switch (menuZoo()) {
        case 1:
            // verification de disponibilité de place dans le Zoo avant Ajout
            if (nbr_Animeaux_Parc>=250){
                std::cout << "\n ----  ZOOTOPIA  Presentement affiche complet !!  ----" << std::endl;
                std::cout << " Vous ne pouvez pas ajouter d'animal pour le moment !!!" << std::endl;
            }else{
                animeaux[nbr_Animeaux_Parc] = ajouterTigre(nbr_Animeaux_Parc);
            }
            break;
        case 2:
            // verification de disponibilité de place dans le Zoo avant Ajout
            if (nbr_Animeaux_Parc>=250){
                std::cout << "\n ----  ZOOTOPIA  Presentement affiche complet !!  ----" << std::endl;
                std::cout << " Vous ne pouvez pas ajouter d'animal pour le moment !!!" << std::endl;
            }else{
                animeaux[nbr_Animeaux_Parc] = ajouterSinge(nbr_Animeaux_Parc);
            }
            break;
        case 3:
            // verification de disponibilité de place dans le Zoo avant Ajout
            if (nbr_Animeaux_Parc>=250){
                std::cout << "\n ----  ZOOTOPIA  Presentement affiche complet !!  ----" << std::endl;
                std::cout << " Vous ne pouvez pas ajouter d'animal pour le moment !!!" << std::endl;
            }else{
                animeaux[nbr_Animeaux_Parc] = ajouterRhinoceros(nbr_Animeaux_Parc);
            }
            break;
        case 4:
            compteRenduParc(animeaux, nbr_Animeaux_Parc);
            break;
        case 5:
            supprimerAnimal(animeaux, nbr_Animeaux_Parc);
            break;
        case 6:
            std::cout << "\n  ***  Quitter !!  ***\n" << std::endl;
            quitterLogiciel = true;
            break;
        default:
            std::cout << "Erreur de saisie !!!\n veuillez choisir une option valide du menu !!" << std::endl;
            break;
        }
    } while (!quitterLogiciel);

}

int menuZoo(){

    std::cout << "\n  ------------------------" << std::endl;
    std::cout << "   - Menu Parc Zootopia - " << std::endl;
    std::cout << "  ------------------------" << std::endl;
    std::cout << " 1 - Ajouter un tigre" << std::endl;
    std::cout << " 2 - Ajouter un singe" << std::endl;
    std::cout << " 3 - Ajouter un rhinocéros" << std::endl;
    std::cout << " 4 - Afficher le compte-rendu du parc" << std::endl;
    std::cout << " 5 - Supprimer animal" << std::endl;
    std::cout << " 6 - Quitter" << std::endl;
    std::cout << "\n    Entrez votre choix :";

    int choix;
    std::cin >> choix;

    return choix;
}

Animal* ajouterTigre(int& numero){
    std::cout << "\n  ------------------------" << std::endl;
    std::cout << "   - Ajout d'un Tigre - " << std::endl;
    std::cout << "  ------------------------" << std::endl;
    std::cout << " Nom du Tigre : ";
    std::string nom; 
    std::cin >> nom;
    std::cout << " Poids du Tigre : ";
    double poids; 
    std::cin >> poids;
    numero++;
    return new Tigre(nom, poids);
}

Animal* ajouterSinge(int& numero){
    std::cout << "\n  ------------------------" << std::endl;
    std::cout << "   - Ajout d'un Singe - " << std::endl;
    std::cout << "  ------------------------" << std::endl;
    std::cout << " Nom du Singe : ";
    std::string nom; 
    std::cin >> nom;
    std::cout << " Poids du Singe : ";
    double poids; 
    std::cin >> poids;

    std::cout << " L'enclos du singe a-il de l'herbe ? : ";
    //  je concidere que 1 = oui (True)
    //  tout autres chiffre = Non (False)
    std::cout << "\n 1 - Oui.";
    std::cout << "\n 2 - Non.";
    std::cout << "\n Votre choix : ";
        int choix; 
        std::cin >> choix;
        bool enclosAvecHerbe = false;
        if (choix) {
            enclosAvecHerbe = true;
        }
    numero++;
    return new Singe(nom, poids, enclosAvecHerbe);
}

Animal* ajouterRhinoceros(int& numero){
    std::cout << "\n  ---------------------------" << std::endl;
    std::cout << "   - Ajout d'un Rhinoceros - " << std::endl;
    std::cout << "  ---------------------------" << std::endl;
    std::cout << " Nom du Rhino : ";
    std::string nom; 
    std::cin >> nom;
    std::cout << " Poids du Rhino : ";
    double poids; 
    std::cin >> poids;
    std::cout << " Espace de l'enclos du Rhino : ";
    int surface; 
    std::cin >> surface;
    numero++;
    return new Rhinoceros(nom, poids, surface);
}


void compteRenduParc(Animal* unAnimal[], int& nombreAnimeaux){
    std::cout << "\n  -----------------------------------" << std::endl;
    std::cout << "   - Compte rendu du Parc Zootopia - " << std::endl;
    std::cout << "  -----------------------------------" << std::endl;
    
    double viande = 0;
    double fruits = 0;
    double herbe = 0;

    std::cout << "nombreAnimeaux : " << nombreAnimeaux << std::endl;
    for (int i = 0; i < nombreAnimeaux; i++) {
        
        std::cout << "\n  -----------------------------------" << std::endl;
        std::cout << "i : " << i << std::endl;
        unAnimal[i]->informationsAnimal();
        unAnimal[i]->afficherDiete();
        viande += unAnimal[i]->getDieteJour()->getViande();
        fruits += unAnimal[i]->getDieteJour()->getFruits();
        herbe += unAnimal[i]->getDieteJour()->getHerbe();
    }
    std::cout << "\n  ===================================" << std::endl;
    std::cout << "Diete quotidienne totale :" << std::endl;
    std::cout << "Viande : " << viande << " kg" << std::endl;
    std::cout << "Fruits : " << fruits << " kg" <<  std::endl;
    std::cout << "Herbe  : " << herbe << " kg" <<  std::endl;
}

void supprimerAnimal(Animal* unAnimal[], int& nombreAnimeaux){
    std::cout << "\n  ----------------------" << std::endl;
    std::cout << "   - Supprimer Animal - " << std::endl;
    std::cout << "  ----------------------" << std::endl;
    std::cout << " Nom de l'animal à supprimer : ";
    std::string nomAnimal; 
    std::cin >> nomAnimal;
    
    //  retourne la position, si inexistant retourne nombreAnimeaux
    int positionAnimal = animalExiste(nomAnimal, unAnimal, nombreAnimeaux);
    
    if (positionAnimal!=nombreAnimeaux) {
        supprimer(positionAnimal, unAnimal, nombreAnimeaux);
        std::cout << " * Succés de la suppression de l'animal * ";
    }else{
        std::cout << " ERREUR !!! \n L'animal que vous tentez de supprimer n'existe pas ! ";
    }
}

int animalExiste(std::string nomAnimal, Animal* unAnimal[], int& nombreAnimeaux){
    for (int i = 0; i < nombreAnimeaux; i++){
        if (unAnimal[i]->getNom()==nomAnimal) {
            return i;
        }
    }
    return nombreAnimeaux;
}

void supprimer(int position, Animal* unAnimal[], int& nombreAnimeaux){
    // liberation de la case memoire de l'animal a supprimer
    delete unAnimal[position];
    for (int i = position; i < (nombreAnimeaux-1); i++){
        unAnimal[i]=unAnimal[i+1];
    }    
    //  juste une securité pour ne pas avoir 2 pointeur qui pointent la meme case memoire
    //  meme si il n'y aura pas accés
    unAnimal[nombreAnimeaux-1] = NULL;
    nombreAnimeaux --;
}