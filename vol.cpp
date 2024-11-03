#include "vol.h"

Vol::Vol(const string &id, const Aeroport& depart, const Aeroport& arrivee, const string &dateDepart, int totalSeats)
    : id(id), depart(depart), arrivee(arrivee), dateDepart(dateDepart), places(totalSeats, "NULL") {}

// Setters
void Vol::setId(const string& id) {
    this->id = id;
}

void Vol::setDepart(const Aeroport& depart) {
    this->depart = depart;
}

void Vol::setArrivee(const Aeroport& arrivee) {
    this->arrivee = arrivee;
}

void Vol::setDateDepart(const string& dateDepart) {
    this->dateDepart = dateDepart;
}

void Vol::setPlaces(const vector<string>& places) {
    this->places = places;
}

// Getters
string Vol::getID() const {
    return id;
}

Aeroport Vol::getDepart() const {
    return depart;
}

Aeroport Vol::getArrivee() const {
    return arrivee;
}

string Vol::getDateDepart() const {
    return dateDepart;
}
int Vol::getSeats() const{
    return places.size();
}

vector<string> Vol::getPlaces() const {
    return places;
}

void Vol::afficher()  {
    cout << "\t****************************\n\tFlight ID: " << id << "\n";
    cout << "\n\tDeparture Airport: ";
    depart.afficherAeroport();
    cout << "\n\tArriving Airport: ";
    arrivee.afficherAeroport();
    cout << "\n\tDeparture Date and Time: " << dateDepart << "\n\t*************************************\n";
}
void Vol::setNbPlaces(int x){
    places.resize(x,"NULL");
    /*for (int i=0; i<x ; i++){
        cout<<"\t le passager de l'idantifiant : "<<places[i]<<" est a la places " << i <<endl;
    }*/
}
void Vol::displayPlaces(){
    for (int i=0; i<places.size() ; i++){
            cout<<"\t le passager de l'idantifiant : "<<places[i]<<" est a la places " << i <<endl;
        };
}
