#include <iostream>

#include "animal.h"
#include "tigre.h"
#include "singe.h"
#include "rhinoceros.h"

int menuZoo();
Animal* ajouterTigre(int& numero);
Animal* ajouterSinge(int& numero);
Animal* ajouterRhinoceros(int& numero);
void compteRenduParc(Animal* unAnimal[], int& nombreAnimaux);

//// BONUS SUPPRESSION
void supprimerAnimal(Animal* unAnimal[], int& nombreAnimaux);
int animalExiste(std::string nomAnimal, Animal* unAnimal[], int& nombreAnimaux);
void supprimer(int position, Animal* unAnimal[], int& nombreAnimaux);

int main() {
    
    // quitter le logiciel si choix = 6, uniquement 
    bool quitterLogiciel = false;

    Animal* animaux[250];
    int nbr_Animaux_Parc = 0;

    do{
    switch (menuZoo()) {
        case 1:
            // verification de disponibilité de place dans le Zoo avant Ajout
            if (nbr_Animaux_Parc>=250){
                std::cout << "\n ----  ZOOTOPIA  Presentement affiche complet !!  ----" << std::endl;
                std::cout << " Vous ne pouvez pas ajouter d'animal pour le moment !!!" << std::endl;
            }else{
                animaux[nbr_Animaux_Parc] = ajouterTigre(nbr_Animaux_Parc);
            }
            break;
        case 2:
            // verification de disponibilité de place dans le Zoo avant Ajout
            if (nbr_Animaux_Parc>=250){
                std::cout << "\n ----  ZOOTOPIA  Presentement affiche complet !!  ----" << std::endl;
                std::cout << " Vous ne pouvez pas ajouter d'animal pour le moment !!!" << std::endl;
            }else{
                animaux[nbr_Animaux_Parc] = ajouterSinge(nbr_Animaux_Parc);
            }
            break;
        case 3:
            // verification de disponibilité de place dans le Zoo avant Ajout
            if (nbr_Animaux_Parc>=250){
                std::cout << "\n ----  ZOOTOPIA  Presentement affiche complet !!  ----" << std::endl;
                std::cout << " Vous ne pouvez pas ajouter d'animal pour le moment !!!" << std::endl;
            }else{
                animaux[nbr_Animaux_Parc] = ajouterRhinoceros(nbr_Animaux_Parc);
            }
            break;
        case 4:
            compteRenduParc(animaux, nbr_Animaux_Parc);
            break;
        case 5:
            supprimerAnimal(animaux, nbr_Animaux_Parc);
            break;
        case 6:
            std::cout << "\n  ***  Quitter !!  ***\n" << std::endl;
            // delete (vider les cases du tableau). car en quitte le logiciel
            for (int i = 0; i < nbr_Animaux_Parc; i++) {
                delete animaux[i];
            }            
            quitterLogiciel = true;
            break;
        default:
            std::cout << "Erreur de saisie !!!\n veuillez choisir une option valide du menu !!" << std::endl;
            break;
        }
    } while (!quitterLogiciel);

}
//  affichage du menu et retourne le choix de l'utilisateur
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
//  ajout d'un tigre
Animal* ajouterTigre(int& numero){
    std::cout << "\n  ------------------------" << std::endl;
    std::cout << "   - Ajout d'un Tigre - " << std::endl;
    std::cout << "  ------------------------" << std::endl;
    std::cout << " Nom du Tigre (sans espaces): ";
    std::string nom; 
    std::cin >> nom;
    std::cout << " Poids du Tigre (en kg): ";
    double poids; 
    std::cin >> poids;
    numero++;
    return new Tigre(nom, poids);
}
//  Ajout d'un singe
Animal* ajouterSinge(int& numero){
    std::cout << "\n  ------------------------" << std::endl;
    std::cout << "   - Ajout d'un Singe - " << std::endl;
    std::cout << "  ------------------------" << std::endl;
    std::cout << " Nom du Singe (sans espaces): ";
    std::string nom; 
    std::cin >> nom;
    std::cout << " Poids du Singe (en kg): ";
    double poids; 
    std::cin >> poids;

    std::cout << " L'enclos du singe a-il de l'herbe ? : ";
    //  je concidere que 1 = oui (True)
    //  tout autres chiffre = Non (False)
    std::cout << "\n   1 - Oui.";
    std::cout << "\n   2 - Non.";
    std::cout << "\n Votre choix : ";
        int choix; 
        std::cin >> choix;
        bool enclosAvecHerbe = false;
        if (choix==1) {
            enclosAvecHerbe = true;
        }
    numero++;
    return new Singe(nom, poids, enclosAvecHerbe);
}
//  Ajout d'un Rhinoceros
Animal* ajouterRhinoceros(int& numero){
    std::cout << "\n  ---------------------------" << std::endl;
    std::cout << "   - Ajout d'un Rhinoceros - " << std::endl;
    std::cout << "  ---------------------------" << std::endl;
    std::cout << " Nom du Rhino (sans espaces): ";
    std::string nom; 
    std::cin >> nom;
    std::cout << " Poids du Rhino (en kg): ";
    double poids; 
    std::cin >> poids;
    std::cout << " Espace de l'enclos du Rhino (en mètres-carrés): ";
    int surface; 
    std::cin >> surface;
    numero++;
    return new Rhinoceros(nom, poids, surface);
}

//  affichage du conpte rendu
void compteRenduParc(Animal* unAnimal[], int& nombreAnimaux){
    std::cout << "\n  -----------------------------------" << std::endl;
    std::cout << "   - Compte rendu du Parc Zootopia - " << std::endl;
    std::cout << "  -----------------------------------" << std::endl;
    
    double viande = 0;
    double fruits = 0;
    double herbe = 0;

    std::cout << "\n  Presentement nous avons " << nombreAnimaux << " residents." << std::endl;

    for (int i = 0; i < nombreAnimaux; i++) {
        //   calcule de la diete (methode polymorphique) de chaque animal
        unAnimal[i]->setDieteJour(unAnimal[i]->calculerDiete());
        //  Affichage des information de chaque animal ainsi que sa diète
        unAnimal[i]->informationsAnimal();
        unAnimal[i]->afficherDiete();
        //  calcule de l'ensemble des diètes pour le total des besoins en nourriture du zoo
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

///////////////////////////////////////////////
//          BONUS SUPPRESSION ANIMAL         //
///////////////////////////////////////////////


/**
 * méthode qui prends le nom d'un animal a supprimer danns le tableau
 * appele la méthode de recherche animalExiste(), si l'animal existe
 * appele la methode de suppression supprimer()
 * @param unAnimal tableau de pointeur contenant des animaux
 * @param nombreAnimaux nombre total d'animaux dans le tableau (eviter d'aller au dela des cases necessaire)
*/
void supprimerAnimal(Animal* unAnimal[], int& nombreAnimaux){
    std::cout << "\n  ----------------------" << std::endl;
    std::cout << "   - Supprimer Animal - " << std::endl;
    std::cout << "  ----------------------" << std::endl;
    //  verfifer qu'il existe au moins un animal a supprimer
    if (nombreAnimaux != 0)
    {    
        std::cout << " Nom de l'animal à supprimer : ";
        std::string nomAnimal; 
        std::cin >> nomAnimal;
        
        //  retourne la position, si inexistant retourne -1
        int positionAnimal = animalExiste(nomAnimal, unAnimal, nombreAnimaux);
        
        if (positionAnimal>=0) {
            supprimer(positionAnimal, unAnimal, nombreAnimaux);
            std::cout << "\n *************************************** ";
            std::cout << "\n * Succés de la suppression de l'animal * \n";
        }else{
            std::cout << "\n *************************************** ";
            std::cout << "\n ERREUR !!! \n L'animal que vous tentez de supprimer n'existe pas ! \n";
        }
    }else{
        std::cout << "\n *************************************** ";
        std::cout << "\n ERREUR !!! \n Il n'y a aucun animal à supprimer dans le Zoo ! \n";
    }
}
/**
 * méthode qui recherche si un animal axiste dans le tableau grace a son nom, et retourne sa position
 * retourne -1 si l'animal n'existe pas
 * @return position de l'animal dans le tableau
 * @param nomAnimal nom de l'animal a rechercher dans le tableau
 * @param unAnimal tableau de pointeur contenant des animaux
 * @param nombreAnimaux nombre total d'animaux dans le tableau (eviter d'aller au dela des cases necessaire)
*/
int animalExiste(std::string nomAnimal, Animal* unAnimal[], int& nombreAnimaux){
    for (int i = 0; i < nombreAnimaux; i++){
        if (unAnimal[i]->getNom()==nomAnimal) {
            return i;
        }
    }
    return -1;
}
/**
 * méthode qui supprime un animal de notre zoo (du tableau),
 * en reorganisant les autres element du tableau pour ne pas laisser de vide
 * @param position entier representant la position de l'animal a supprimer dans le tableau
 * @param unAnimal tableau de pointeur contenant des animaux
 * @param nombreAnimaux nombre total d'animaux dans le tableau (eviter d'aller au dela des cases necessaire)
*/
void supprimer(int position, Animal* unAnimal[], int& nombreAnimaux){
    // liberation de la case memoire de l'animal a supprimer
    delete unAnimal[position];
    for (int i = position; i < (nombreAnimaux-1); i++){
        unAnimal[i]=unAnimal[i+1];
    }    
    //  juste une securité pour ne pas avoir 2 pointeur qui pointent la meme case memoire
    //  meme si il n'y aura pas accés
    unAnimal[nombreAnimaux-1] = NULL;
    nombreAnimaux --;
}