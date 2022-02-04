#include "Professeur.h"



//Constructeurs
Professeur::Professeur():Planifiable()
{
    nom = NULL;
    prenom = NULL;
    cout << "Entrée constructeur professeur" << endl;
    setNom("NULL");
    setPrenom("NULL");
}

Professeur::Professeur(const char* _nom, const char* _prenom):Planifiable()
{
    nom = NULL;
    prenom = NULL;
    setNom(_nom);
    setPrenom(_prenom);
}

Professeur::Professeur(int _id, const char* _nom, const char* _prenom):Planifiable(_id)
{
    nom = NULL;
    prenom = NULL;
    setNom(_nom);
    setPrenom(_prenom);
}

Professeur::Professeur(const Professeur& para):Planifiable((const Planifiable&) para)
{
    nom = NULL;
    prenom = NULL;
    setNom(para.getNom());
    setPrenom(para.getPrenom());
}

Professeur::~Professeur()
{
    if(nom) delete nom;
    if(prenom) delete prenom;
}

//Getters
inline const char* Professeur::getNom()const
{
    return nom;
}

inline const char* Professeur::getPrenom()const
{
    return prenom;
}

//Setters
inline void Professeur::setNom(const char* para)
{
    if(!para) return;
    if(nom) delete nom;
    nom = new char[strlen(para)+1];
    strcpy(nom,para);
}

inline void Professeur::setPrenom(const char* para)
{
    if(!para) return;
    if(prenom) delete prenom;
    prenom = new char[strlen(para)+1];
    strcpy(prenom,para);
}

//Surcharge des operateurs
Professeur& Professeur::operator=(const Professeur& para)
{
    setNom(para.getNom());
    setPrenom(para.getPrenom());
    setId(para.getId());
    return *this;
}

ostream& operator<<(ostream& s, const Professeur& para)
{
    s << "Nom: " << para.getNom() << " " << "Prenom: " << para.getPrenom() << endl;
    return s;
}

//Methodes
inline const char* Professeur::Txt()
{
    if(txtptr) delete txtptr;
    ostrstream ost;
    ost << nom << " " << prenom << endl;
    txtptr = new char[strlen(ost.str())];
    strcpy(txtptr, ost.str());
    return txtptr;
}

inline const char* Professeur::Tuple()
{
    if(tupleptr) delete tupleptr;
    ostrstream ost;
    ost << id << ";" <<  nom << ";" << prenom << endl;
    tupleptr = new char[strlen(ost.str())];
    strcpy(tupleptr, ost.str());
    return tupleptr;
}