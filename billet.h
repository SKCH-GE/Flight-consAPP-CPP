#ifndef BILLET_H
#define BILLET_H

#include "vol.h"

class Billet {
private:
    Vol vol; // Object of class Vol to indicate the flight
    string volId;
    int noPlaces; // Seat number on the ticket

public:
    // Constructor
    Billet(const string volId,int noPlaces);
    Billet(const Vol& vol, int noPlaces);

    // Getters
    void getVol() const;
    int getNoPlaces() const;
};

#endif // BILLET_H
