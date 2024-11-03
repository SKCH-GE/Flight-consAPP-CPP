#include "billet.h"

// Constructor
/*Billet::Billet(const Vol& vol, int noPlaces)
    : vol(vol), noPlaces(noPlaces) {}*/
Billet::Billet(const Vol& vol, int noPlaces)
    : vol(vol), noPlaces(noPlaces) {
    // Update the places vector in the Vol class
    std::vector<std::string> places = vol.getPlaces();
    if (noPlaces >= 0 && noPlaces < places.size()) {
        places[noPlaces] = this->vol.getID(); // Assuming ID is unique for each passenger
    }
}

// Getters
void Billet::getVol() const {
    cout<<"l'idantifiant du vol de cette billet est :" <<vol.getID()<<endl;
}

int Billet::getNoPlaces() const {
    return noPlaces;
}
