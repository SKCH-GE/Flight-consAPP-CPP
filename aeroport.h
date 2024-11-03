#ifndef AEROPORT_H
#define AEROPORT_H
#include <iostream>
using namespace std;

class Aeroport
{
    private:
        string code;
        string nom;
        string pays;

    public:
        Aeroport();
        Aeroport(string code, string nom, string pays);
        void afficherAeroport();
        string getCode() const;
        string getNom() const;
        string getLocation() const;
};

#endif
