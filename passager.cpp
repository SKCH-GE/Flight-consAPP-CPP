#include "passager.h"

// Constructor
Passager::Passager(const std::string& id, const std::string& nom, const std::string& prenom)
    : id(id), nom(nom), prenom(prenom) {}

// Getters
string Passager::getID() const {
    return id;
}

string Passager::getNom() const {
    return nom;
}

string Passager::getPrenom() const {
    return prenom;
}

void Passager::getBillets() {
    for(Billet i : T_Billets){
        i.getVol();
    }
}

// Method to add a ticket to T_Billets
void Passager::addBillet(const Billet& billet) {
    T_Billets.push_back(billet);
}
