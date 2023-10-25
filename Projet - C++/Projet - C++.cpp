#include <vector>
#include <iostream>


class Case {
public:
    Case();
    int getValeur() const;
    void setValeur(int nouvelleValeur);
    bool estVide() const;

private:
    int valeur; // Valeur de la case (0 pour une case vide, sinon une puissance de 2)
};

Case::Case() : valeur(0) {
}

int Case::getValeur() const {
    return valeur;
}

void Case::setValeur(int nouvelleValeur) {
    valeur = nouvelleValeur;
}

bool Case::estVide() const {
    return (valeur == 0);
}

