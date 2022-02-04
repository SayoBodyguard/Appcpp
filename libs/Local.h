#ifndef LOCAL_H
#define LOCAL_H

#include <string.h>
#include "Planifiable.h"
#include <iostream>
#include <strstream>
using namespace std;

class Local: public Planifiable
{
    private:
        char* Nom;

    public:
    //Constructeurs
        Local();
        Local(int, const char*);
        Local(const char*);
        Local(const Local&);
        ~Local();

    //Getters
        const char* getNom()const;

    //Setters
        void setNom(const char*);

    //Methodes
        const char* Txt();
        const char* Tuple();
        
    //Surcharge opérateurs
        friend ostream& operator<<(ostream&, const Local&);
        Local& operator= (const Local&);

};

#endif