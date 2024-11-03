#ifndef PASSAGER_H
#define PASSAGER_H

#include <iostream>
#include <string>
#include <vector>
#include "billet.h"
using namespace std;

class Passager {
private:
    string id;
    string nom;
    string prenom;
    vector<Billet> T_Billets; // Table to store tickets as objects of class Billet

public:
    // Constructor
    Passager(const std::string& id, const std::string& nom, const std::string& prenom);

    // Getters
    string getID() const;
    string getNom() const;
    string getPrenom() const;
    void getBillets() ;

    // Method to add a ticket to T_Billets
    void addBillet(const Billet& billet);
};

#endif // PASSAGER_H
