#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include <string.h>
#include "Planifiable.h"
#include <iostream>
#include <strstream>
using namespace std;
class Professeur: public Planifiable
{
    private:
        char* nom;
        char* prenom;

    public:
    // constructeurs
        Professeur();
        Professeur(const char*, const char*);
        Professeur(int, const char*, const char*);
        Professeur(const Professeur&);

        ~Professeur();

    // Getters
        const char* getNom()const;
        const char* getPrenom()const;

    // Setters
        void setNom(const char*);
        void setPrenom(const char*);

    //Surcharge des operateurs
        friend ostream& operator<<(ostream&, const Professeur&);
        Professeur& operator=(const Professeur&);
        

    // methodes
        const char* Txt();
        const char* Tuple();
};

#endif