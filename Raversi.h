#ifndef RAVERSI_H
#define RAVERSI_H



class Raversi {


    public:

        // Constructeur
        Raversi();

        // Destructeur
        ~Raversi();


    public:

        // Renvoie le type de pion en x,y
        char get(int x, int y);

        // Place (si possible) un pion de type c en x;y
        // Si le pion peut être placé        => renvoie true
        // Si le pion ne peut pas être placé => renvoie false
        //     Note : le placement entraine le retournement d'autres pions
        bool set(int x, int y, char c);


    public:

        // Renvoie le nombre de pion de type c sur le plateau
        int count(char c);

        // Renvoie si le plateau est plein ou non
        bool isFill ();

        // Affiche le plateau
        void print();


    private:

        // Retourne des pions dans la direction d à partir de x,y
        // Les pions retournés seront de type c
        // Cette fonction renvoie le nombre de pion retourné
        int flip(int x, int y, char c, int d);


    private:

        // Plateau
        char tab[8][8];


};



#endif // RAVERSI_H
