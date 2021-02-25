#include <iostream>

#include "animal.h"
#include "tigre.h"
#include "singe.h"
#include "rhinoceros.h"

int menuZoo();

int main() {
    
    Tigre* tigroux = new Tigre("tigroux", 120);
    std::cout << "diete tigre : " << tigroux->calculerDiete() << std::endl;
    Singe* monSinge = new Singe("singe herbe", 120, true);
    std::cout << "diete singe avec herbe : " << monSinge->calculerDiete() << std::endl;
    Singe* monSinge2 = new Singe("singe", 120, false);
    std::cout << "diete sans herbe : " << monSinge2->calculerDiete() << std::endl;
    Rhinoceros* rhinos = new Rhinoceros("rhinos", 450, 2500);
    std::cout << "diete rhino : " << rhinos->calculerDiete() << std::endl;

    // je laisse l'utilisateur quitter le logiciel si il choisi 5, dans le menu et uniquement a ce moment la 
    bool quitterMenu = false;

    do{
    switch (menuZoo()) {
        case 1:
            std::cout << " 1 - Ajouter un tigre" << std::endl;
            break;
        case 2:
            std::cout << " 2 - Ajouter un singe" << std::endl;
            break;
        case 3:
            std::cout << " 3 - Ajouter un rhinocéros" << std::endl;
            break;
        case 4:
            std::cout << " 4 - Afficher le compte-rendu du parc" << std::endl;
            break;
        case 5:
            std::cout << "Quitter !!" << std::endl;
            quitterMenu = true;
            break;    
        default:
            std::cout << "Erreur de saisie !!!\n veuillez saisir une option de menu valide !!" << std::endl;
            break;
        }
    } while (!quitterMenu);

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
