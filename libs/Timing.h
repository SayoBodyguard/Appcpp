#ifndef TIMING_H
#define TIMING_H

#include <iostream>
#include "Temps.h"
#include "string.h"
using namespace std;

class Timing
{

    private:
        char* nom;
        Temps debut;
        Temps duree;

        int cmp(const Timing&);
    public:
    //Variables statiques
        static char LUNDI[6];
        static char MARDI[6];
        static char MERCREDI[9];
        static char JEUDI[6];
        static char VENDREDI[9];
        static char SAMEDI[7];
        static char DIMANCHE[9];

    //Constructeurs
        Timing(); //Defaut
        Timing(const char*, const Temps&, const Temps&); //Initialisation
        Timing(const Timing&); //Copie

    //Destructeur
        ~Timing();

    //Getters
        const char* getJour()const;
        Temps getHeure()const;
        Temps getDuree()const;

    //Setters
        void setJour(const char*);
        void setHeure(const Temps&);
        void setDuree(const Temps&);

    //Surcharge des opérateurs
    int operator<(const Timing&);
    int operator>(const Timing&);
    int operator==(const Timing&);
    //Extra
        void Affiche()const;

};

#endif