#include <iostream>

#include "animal.h"
#include "tigre.h"
#include "singe.h"
#include "rhinoceros.h"
#include "diete.h"

int menuZoo();
Animal* ajouterTigre(int& numero);
Animal* ajouterSinge(int& numero);
Animal* ajouterRhinoceros(int& numero);
void compteRenduParc(Animal* unAnimal[], int& numero);

int main() {
    
    // je laisse l'utilisateur quitter le logiciel si il choisi 5, dans le menu et uniquement a ce moment la 
    bool quitterLogiciel = false;

    Animal* animeaux[250];
    int nbr_Animeaux_Parc = 0;


    animeaux[nbr_Animeaux_Parc] = new Tigre("Alice", 120.8);
    nbr_Animeaux_Parc++;

    std::cout << "------------------------------------------" << std::endl;

    animeaux[nbr_Animeaux_Parc] = new Singe("Bob", 10.5, true);
    nbr_Animeaux_Parc++;

    std::cout << "------------------------------------------" << std::endl;

    animeaux[nbr_Animeaux_Parc] = new Singe("Monke", 8.7, false);
    nbr_Animeaux_Parc++;

    std::cout << "------------------------------------------" << std::endl;

    animeaux[nbr_Animeaux_Parc] = new Rhinoceros("Eve", 1812.3, 1000);
    nbr_Animeaux_Parc++;

    std::cout << "------------------------------------------" << std::endl;

    animeaux[nbr_Animeaux_Parc] = new Rhinoceros("Horny", 2021.5, 6000);
    nbr_Animeaux_Parc++;

    std::cout << "------------------------------------------" << std::endl;


    do{
    switch (menuZoo()) {
        case 1:
            animeaux[nbr_Animeaux_Parc] = ajouterTigre(nbr_Animeaux_Parc);
            break;
        case 2:
            animeaux[nbr_Animeaux_Parc] = ajouterSinge(nbr_Animeaux_Parc);
            break;
        case 3:
            animeaux[nbr_Animeaux_Parc] = ajouterRhinoceros(nbr_Animeaux_Parc);
            break;
        case 4:
            compteRenduParc(animeaux, nbr_Animeaux_Parc);
            break;
        case 5:
            std::cout << "Quitter !!" << std::endl;
            quitterLogiciel = true;
            break;    
        default:
            std::cout << "Erreur de saisie !!!\n veuillez saisir une option de menu valide !!" << std::endl;
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
    std::cout << " 5 - Quitter" << std::endl;
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


void compteRenduParc(Animal* unAnimal[], int& numero){
    std::cout << "\n  -----------------------------------" << std::endl;
    std::cout << "   - Compte rendu du Parc Zootopia - " << std::endl;
    std::cout << "  -----------------------------------" << std::endl;
    
    double viande = 0;
    double fruits = 0;
    double herbe = 0;

    for (int i = 0; i < numero; i++) {
        std::cout << "\n  -----------------------------------" << std::endl;
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
