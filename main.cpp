#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

#include "aeroport.h"
#include "vol.h"
#include "passager.h"
#include "billet.h"
using namespace std;

void displayPassengers(const std::vector<Passager>& Tpassagers) {
    // Display table header
    std::cout << "Les passagers enregistres :\n";
    std::cout << std::setw(15) << std::left << "--Nom--";
    std::cout << std::setw(15) << std::left << "--Prenom--";
    std::cout << std::setw(10) << std::left << "--ID--" << std::endl;

    // Display table rows for each passenger
    for(const Passager& elementP : Tpassagers) {
        std::cout << std::setw(15) << std::left << elementP.getNom();
        std::cout << std::setw(15) << std::left << elementP.getPrenom();
        std::cout << std::setw(10) << std::left << elementP.getID() << std::endl;
    }
}
void addAirport(vector<Aeroport>& Tairports) {
    string nom, code, location;
    cout << "Entrez le nom de l'aeroport : ";
    cin >> nom;
    cout << "Entrez le code de l'aeroport : ";
    cin >> code;
    cout << "Entrez l'emplacement de l'aeroport : ";
    cin >> location;
    Aeroport airport(nom, code, location);
    Tairports.push_back(airport);
    cout << "Aeroport ajoute avec succes !" << endl;
}
void createFlight(vector<Vol>& Tvols, const vector<Aeroport>& Tairports) {
    string id, departCode, arriveeCode, dateDepart;
    int seats;
    cout << "Entrez l'ID du vol : ";
    cin >> id;
    cout << "Entrez le code de l'aeroport de depart : ";
    cin >> departCode;
    cout << "Entrez le code de l'aeroport d'arrivee : ";
    cin >> arriveeCode;
    cout << "Entrez la date de depart : ";
    cin >> dateDepart;
    // Assuming Aeroport has a constructor that takes code as argument
    Aeroport depart, arrivee;
    for(const Aeroport& airport : Tairports) {
        if(airport.getCode() == departCode) depart = airport;
        if(airport.getCode() == arriveeCode) arrivee = airport;
    }
    if(depart.getCode().empty() || arrivee.getCode().empty()) {
        cout << "Aeroport non trouve." << endl;
        return;
    }
    cout << "Entrez le nombre des places sur ce Vol : ";
    cin >> seats;
    Vol flight(id, depart, arrivee, dateDepart,seats);
    Tvols.push_back(flight);
    cout << "Vol cree avec succes !" << endl;
}
void displayAirports(const vector<Aeroport>& Tairports) {
    cout << "Liste des airports :\n";
    cout << std::setw(15) << std::left << "--Nom--";
    cout << std::setw(15) << std::left << "--Code--";
    cout << std::setw(20) << std::left << "--Emplacement--" << std::endl;

    for (const Aeroport& airport : Tairports) {
        cout << std::setw(15) << std::left << airport.getNom();
        cout << std::setw(15) << std::left << airport.getCode();
        cout << std::setw(20) << std::left << airport.getLocation() << endl;
    }
}
void deleteAirport(vector<Aeroport>& Tairports) {
    string codeToDelete;
    cout << "Entrez le code de l'aeroport a supprimer : ";
    cin >> codeToDelete;

    auto it = std::find_if(Tairports.begin(), Tairports.end(),
        [&](const Aeroport& airport) { return airport.getCode() == codeToDelete; });

    if (it != Tairports.end()) {
        Tairports.erase(it);
        cout << "Aeroport supprime avec succes !" << endl;
    } else {
        cout << "Aeroport non trouve." << endl;
    }
}
void displayFlights(const vector<Vol>& Tvols) {
    cout << "Liste des vols :\n";
    cout << std::setw(15) << std::left << "--ID--";
    cout << std::setw(15) << std::left << "--Depart--";
    cout << std::setw(15) << std::left << "--Arrivee--";
    cout << std::setw(20) << std::left << "--Date de depart--";
    cout << std::setw(10) << std::left << "--Places--" << std::endl;

    for (const Vol& flight : Tvols) {
        cout << std::setw(15) << std::left << flight.getID();
        cout << std::setw(15) << std::left << flight.getDepart().getNom(); // Assuming Aeroport has getNom() method
        cout << std::setw(15) << std::left << flight.getArrivee().getNom();
        cout << std::setw(20) << std::left << flight.getDateDepart();
        cout << std::setw(10) << std::left << flight.getSeats() << endl;
    }
}
void deleteFlight(vector<Vol>& Tvols) {
    string idToDelete;
    cout << "Entrez l'ID du vol a supprimer : ";
    cin >> idToDelete;

    auto it = std::find_if(Tvols.begin(), Tvols.end(),
        [&](const Vol& flight) { return flight.getID() == idToDelete; });

    if (it != Tvols.end()) {
        Tvols.erase(it);
        cout << "Vol supprime avec succes !" << endl;
    } else {
        cout << "Vol non trouve." << endl;
    }
}
void addPassenger(vector<Passager>& Tpassagers) {
    string nn, pn, idp;
    cout << "Donner le nom : ";
    cin >> nn;
    cout << "Donner le prenom : ";
    cin >> pn;
    cout << "Donner l'identifiant : ";
    cin >> idp;
    Passager P(idp, nn, pn);
    Tpassagers.push_back(P);
    cout << "Passager bien enregistre !" << endl;
}
void managePassengers(vector<Passager>& Tpassagers) {
    int choix33;
    do {
        displayPassengers(Tpassagers);
        cout << "Taper 0 pour retourner au menu principal : ";
        cin >> choix33;
    } while (choix33 != 0);
}
void buyTicket(std::vector<Vol>& Tvols, std::vector<Passager>& Tpassagers) {
    // Input flight ID
    std::string flightID;
    std::cout << "Entrez l'ID du vol pour lequel vous souhaitez acheter un billet : ";
    std::cin >> flightID;

    // Find the flight by ID
    Vol* selectedFlight = nullptr;
    for (Vol& vol : Tvols) {
        if (vol.getID() == flightID) {
            selectedFlight = &vol;
            break;
        }
    }

    if (selectedFlight) {
        // Input place number
        int placeNumber;
        std::cout << "Entrez le numero de place : ";
        std::cin >> placeNumber;

        // Create ticket
        Billet ticket(*selectedFlight, placeNumber);

        // Ask to buy more tickets
        char buyMore;
        do {
            std::cout << "Voulez-vous acheter plus de billets pour le meme passager ? (o/n) : ";
            std::cin >> buyMore;
            if (buyMore == 'o' || buyMore == 'O') {
                std::cout << "Entrez le numero de place : ";
                std::cin >> placeNumber;
                Billet additionalTicket(*selectedFlight, placeNumber);
                // Confirm additional ticket
                char confirmAdditional;
                std::cout << "Confirmez-vous l'achat du billet ? (o/n) : ";
                std::cin >> confirmAdditional;
                if (confirmAdditional == 'o' || confirmAdditional == 'O') {
                    ticket = additionalTicket;
                }
            }
        } while (buyMore == 'o' || buyMore == 'O');

        // Confirm ticket purchase
        char confirmPurchase;
        std::cout << "Confirmez-vous l'achat du billet ? (o/n) : ";
        std::cin >> confirmPurchase;

        if (confirmPurchase == 'o' || confirmPurchase == 'O') {
            // Add the ticket to a passenger
            std::string passagerID;
            std::cout << "Entrez l'ID du passager auquel vous souhaitez ajouter le billet : ";
            std::cin >> passagerID;
            Passager* passager = nullptr;
            for (Passager& p : Tpassagers) {
                if (p.getID() == passagerID) {
                    passager = &p;
                    break;
                }
            }
            if (passager) {
                passager->addBillet(ticket);
                std::cout << "Billet achete avec succes !" << std::endl;
            } else {
                std::cout << "Passager non trouve." << std::endl;
            }
        } else {
            std::cout << "Achat de billet annule." << std::endl;
        }
    } else {
        std::cout << "Le vol avec l'ID " << flightID << " n'est pas disponible." << std::endl;
    }
}


int main() {
    vector<Aeroport> Tairports;
    vector<Passager> Tpassagers;
    vector<Vol> Tvols;
    int choix1, choix2, choix3;
    int userChoice;
    do {

        cout << "------>Menu Principal<------\n";
        cout << "1. Taper 1 pour gerer les airports : \n";
        cout << "2. Taper 2 pour gerer les vols : \n";
        cout << "3. Taper 3 pour gerer les passagers : \n";
        cout << "4. Taper 4 pour modifier le nombre de :\n\tAirports/Vols/Passager :\n";
        cout << "0. Taper 0 pour quitter. \n";
        cin >> userChoice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrée invalide. Veuillez entrer un entier.\n";
            continue;
        }
        system("cls"); // Windows
        switch (userChoice) {
        case 1:
            do {

                cout << "Gestion des airports..\n";
                cout << "Taper 1 pour ajouter un airport.\n";
                cout << "Taper 2 pour afficher les airports.\n"; // Added display option
                cout << "Taper 3 pour supprimer un airport.\n";   // Added delete option
                cout << "Taper 0 pour le menu principal.\n";
                cin >> choix1;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrée invalide. Veuillez entrer un entier.\n";
                    continue;
                }
                system("cls"); // Windows
                switch (choix1) {
                    case 1:
                        addAirport(Tairports);
                        break;
                    case 2:
                        // Function to display airports
                        displayAirports(Tairports);
                        break;
                    case 3:
                        // Function to delete an airport
                        deleteAirport(Tairports);
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Option invalide.\n";
                        break;
                }
            } while (choix1 != 0);
            break;
        case 2:
            do {

                cout << "Gestion des vols..\n";
                cout << "Taper 1 pour creer un vol.\n";
                cout << "Taper 2 pour afficher les vols.\n";     // Added display option
                cout << "Taper 3 pour supprimer un vol.\n";       // Added delete option
                cout << "Taper 0 pour le menu principal.\n";
                cin >> choix2;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrée invalide. Veuillez entrer un entier.\n";
                    continue;
                }
                system("cls"); // Windows
                switch (choix2) {
                    case 1:
                        createFlight(Tvols, Tairports);
                        break;
                    case 2:
                        // Function to display flights
                        displayFlights(Tvols);
                        break;
                    case 3:
                        // Function to delete a flight
                        deleteFlight(Tvols);
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Option invalide.\n";
                        break;
                }
            } while (choix2 != 0);
            break;

        case 3:
            do {
                cout << "Gestion des passagers..\n";
                cout << "Taper 1 pour ajouter un nouveau passager.\n";
                cout << "Taper 2 pour gerer les billets.\n";
                cout << "Taper 3 pour afficher les passagers.\n";
                cout << "Taper 0 pour le menu principal.\n";
                cin >> choix3;
                switch (choix3) {
                    case 1:
                        addPassenger(Tpassagers);
                        break;
                    case 2:
                        buyTicket(Tvols,Tpassagers);
                        break;
                    case 3:
                        managePassengers(Tpassagers);
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Option invalide.\n";
                        break;
                }
            } while (choix3 != 0);
            break;
            case 4:
                // Code for modifying numbers of airports, flights, passengers
                break;
            case 0:
                break;
            default:
                cout << "Option invalide.\n";
                break;
        }
    } while (userChoice != 0);
    return 0;
}
