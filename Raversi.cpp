#include "raversi.h"
#include <iostream>



Raversi::Raversi() {

    // Mise de tout le tableau en case vide
    for ( int y = 0 ; y < 8 ; y++ ) {
        for ( int x = 0 ; x < 8 ; x++ ) {
            tab[y][x] = ' ';
        }
    }

    // Mise des pions de départ
    tab[3][3]= 'X';
    tab[3][4]= 'O';
    tab[4][3]= 'O';
    tab[4][4]= 'X';

}



Raversi::~Raversi() {

}



char Raversi::get(int x, int y) {

    // Si la position n'est pas correct, on renvoie un tiret
    if ( x < 0 || y < 0 || x >= 8 || y >= 8 ) {
        return '-';
    }

    // Sinon, on renvoie la case correspondante
    return tab[y][x];

}



bool Raversi::set(int x, int y, char c) {

    // Si la position n'est pas correct, on retourne false
    if ( x < 0 || y < 0 || x >= 8 || y >= 8 ) {
        return false;
    }

    // Si le type n'est pas correct, on retourne false
    if ( c != 'O' && c != 'X' ) {
        return false;
    }

    // Si la case visée n'est pas vide, on retourne false
    if ( tab[y][x] != ' ' ) {
        return false;
    }

    // A partir d'ici, les paramètres sont bon, reste à savoir si un pion a le droit d'être placé ici

    // Rappel : un pion a le droit d'être placé si son placement retournera au moins un autre pion

    // Nombre de pions retournés
    int count = 0;

    // Retournement de pions dans toutes les directions
    for ( int d = 0 ; d < 8 ; d++ ) {
        count += flip(x, y, c, d);
    }

    // Si aucun pion n'a été retourné, on retourne false
    if (count == 0) {
        return false;
    }

    // Sinon, le pion est placé et on retourne true
    tab[y][x] = c;
    return true;

}



int Raversi::count(char c) {

    // Nombre de pions de type c
    int r = 0;

    // Analyse de tout le plateau
    for ( int y = 0 ; y < 8 ; y++ ) {
        for ( int x = 0 ; x < 8 ; x++ ) {
            if ( tab[y][x] == c ) {
                r++;
            }
        }
    }

    // Fin <img src="../../bundles/tinymce/vendor/tiny_mce/plugins/emotions/img/smile.png" title=":)" alt=":)">
    return r;

}



bool Raversi::isFill() {

    // Analyse de tout le plateau
    for ( int y = 0 ; y < 8 ; y++ ) {
        for ( int x = 0 ; x < 8 ; x++ ) {

            // Si une case est vide, on renvoie false (car la présence d'une case vide indique que le plateau n'est pas plein)
            if ( tab[y][x] == ' ' ) {
                return false;
            }

        }
    }

    // Si il n'y a pas eu de "return false" pendant l'analyse, c'est qu'il n'y a pas de case vide et donc que le plateau est plein donc on renvoie true
    return true;
}



void Raversi::print() {

    // Print powa <img src="../../bundles/tinymce/vendor/tiny_mce/plugins/emotions/img/smile.png" title=":)" alt=":)">

    std::cout << std::endl << std::endl;

    std::cout << "+-";
    for ( int x = 0 ; x < 8 ; x++ ) {
        std::cout << x << "-";
    }
    std::cout << std::endl;

    for ( int y = 0 ; y < 8 ; y++ ) {

        std::cout << "| ";
        for ( int x = 0 ; x < 8 ; x++ ) {
            std::cout << "  ";
        }
        std::cout << "|" << std::endl;

        std::cout << y << ' ';
        for ( int x = 0 ; x < 8 ; x++ ) {
            std::cout << tab[y][x] << " ";
        }
        std::cout << y << std::endl;

    }

    std::cout << "| ";
    for ( int x = 0 ; x < 8 ; x++ ) {
        std::cout << "  ";
    }
    std::cout << "|" << std::endl;

    std::cout << "+-";
    for ( int x = 0 ; x < 8 ; x++ ) {
        std::cout << x << "-";
    }
    std::cout << "+" << std::endl;

    std::cout << std::endl << std::endl;

}



int Raversi::flip(int x, int y, char c, int d) {

    // DIR :
    // 701
    // 6 2
    // 543


    // Déplacement suivant X et Y
    int dX = 0;
    int dY = 0;

    // Vers le haut ? => dY = -1
    if ( d == 7 || d == 0 || d == 1 ) {
        dY = -1;
    }

    // Vers le bas ? => Dy = +1
    if ( d == 5 || d == 4 || d == 3 ) {
        dY = +1;
    }

    // Vers la gauche ? => dX = -1
    if ( d == 7 || d == 6 || d == 5 ) {
        dX = -1;
    }

    // Vers la droite ? => dX = +1
    if ( d == 1 || d == 2 || d == 3 ) {
        dX = +1;
    }


    // Distance parcouru durant la prochaine boucle de déplacement (cf "while" suivant)
    int dist = 0;

    // Copie de x et y durant le déplacement en boucle (cf "while" suivant)
    int x2 = x, y2 = y;


    // Déplacement en boucle infinie
    // Ce déplacement sera interrompu si :
    //     - une bourdure est atteinte
    //     - une case vide est atteinte
    while (1) {

        x2 += dX;
        y2 += dY;

        dist++;

        // Si c'est une case hors plateau, impossible de retourner des pions
        if ( x2 < 0 || y2 < 0 || x2 >= 8 || y2 >= 8 ) {
            return 0;
        }

        // Si c'est une case vide, impossible de retourner des pions
        if ( tab[y2][x2] == ' ' ) {
            return 0;
        }

        // Si c'est une case de même type, arrêt du déplacement
        if ( tab[y2][x2] == c ) {
            break;
        }

    }


    // Si la distance parcouru ne vaut pas au moins 2, impossible de retourner des pions ...
    if ( dist < 2 ) {
        return 0;
    }


    // Retournement des pions
    x2 = x;
    y2 = y;
    for ( int i = 1 ; i < dist ; i++ ) {
        x2 += dX;
        y2 += dY;
        tab[y2][x2] = c;
    }


    // Fin ok !
    return dist-1;


}
