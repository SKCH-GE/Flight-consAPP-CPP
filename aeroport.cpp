#include "aeroport.h"
Aeroport::Aeroport(){
    code="000";
    nom="UNKNOWN";
    pays="UNKNOWN";
}
Aeroport::Aeroport(string c, string n,string p)
{
    code=c;
    nom=n;
    pays=p;
}
void Aeroport::afficherAeroport()
{
    cout<<"\n\t ************************* \n";
    cout<<"\t les parametres de cet aeroport sont \n";
    cout<<"\t le code IATA : "<<code<<"\n";
    cout<<"\t le nom l'aeroport : "<<nom<<"\n";
    cout<<"\t cet aeroport ce trouve en : "<<pays<<"\n";
    cout<<"\n\t ************************* \n";
}
string Aeroport::getCode() const{
    return code;
}
string Aeroport::getNom() const{
    return nom;
}
string Aeroport::getLocation() const{
    return pays;
}
