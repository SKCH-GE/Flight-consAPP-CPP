#ifndef VOL_H
#define VOL_H

#include <iostream>
#include <string>
#include <vector>
#include "aeroport.h"

using namespace std;
class Vol {
private:
    string id; // Flight ID
    Aeroport depart; // Starting airport
    Aeroport arrivee; // Arriving airport
    string dateDepart; // Day and hour of departure (formatted string)
    vector<string> places; // Table of strings representing seat allocations

    //vector<Zone> T_Zones; // Table indicating seat distributions for different zones

public:
    // Constructor
    Vol(const string& id, const Aeroport& depart, const Aeroport& arrivee, const string& dateDepart, int totalSeats);

    // Setters
    void setId(const string& id);
    void setDepart(const Aeroport& depart);
    void setArrivee(const Aeroport& arrivee);
    void setDateDepart(const string& dateDepart);
    void setPlaces(const vector<string>& places);
    //void setT_Zones(const vector<Zone>& T_Zones);


    // Getters
    std::string getID() const;
    Aeroport getDepart() const;
    Aeroport getArrivee() const;
    string getDateDepart() const;
    int getSeats() const;
    vector<string> getPlaces() const;

    // Other methods
    void afficher() ; // Display flight information
    void setNbPlaces(int x);
    void displayPlaces();

};

#endif // VOL_H
