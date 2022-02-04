#ifndef GROUPE_H
#define GROUPE_H
#include <string.h>
#include "Planifiable.h"
#include <iostream>
#include <strstream>
using namespace std;

class Groupe: public Planifiable
{
    private:
        int Numero;
    public:
        //Constructeurs
        Groupe();
        Groupe(int num);
        Groupe(int id, int num);
        Groupe(const Groupe&);
        ~Groupe();

        //Getters
        int getNumero()const;

        //Setters
        void setNumero(int);
        
        //Methodes
        const char* Txt();
        const char* Tuple();

        //Surcharge operateurs
        friend ostream& operator<<(ostream&, const Groupe&);
        Groupe& operator=(const Groupe&);
};
#endif