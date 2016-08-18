#include "raversi.h"
#include <iostream>



int main(int argc, char *argv[]) {

    std::cout << "Bienvenue sur Raversi !" << std::endl;

    Raversi raversi;

    char currentPlayer = 'O';

    while (1) {

         std::cout << std::endl;

        if (!raversi.count('O')) {
            std::cout << "Le joueur X a gagné !!!" << std::endl;
            break;
        }

        if (!raversi.count('X')) {
            std::cout << "Le joueur O a gagné !!!" << std::endl;
            break;
        }

        std::cout << "Plateau :" << std::endl;

        raversi.print();

        std::cout << "Joueur " << currentPlayer << " : veuillez entrer votre position :" << std::endl;

        int x, y;
        std::cout << "x: ";
        std::cin >> x;

        std::cout << "y: ";
        std::cin >> y;

        std::cout << std::endl;

        if (raversi.set(x, y, currentPlayer)) {
            currentPlayer = currentPlayer == 'O' ? 'X' : 'O';
        } else {
            std::cout << "Vous ne pouvez pas joué ici !!!" << std::endl;
        }

    }

    std::cout << "Fin !" << std::endl;

    return 0;

}
