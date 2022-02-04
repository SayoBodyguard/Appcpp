#include "Timing.h"

    char Timing::LUNDI[6]("Lundi");
    char Timing::MARDI[6]("Mardi");
    char Timing::MERCREDI[9] ("Mercredi");
    char Timing::JEUDI[6]("Jeudi");
    char Timing::VENDREDI[9]("Vendredi");
    char Timing::SAMEDI[7]("Samedi");
    char Timing::DIMANCHE[9]("Dimanche"); // Ca fait vrament gorille...
//Constructeurs
    Timing::Timing():nom(NULL) //Defaut
    {
        setJour("Defaut");
     //   setHeure(Temps());
     //   setDuree(Temps());
    }

    Timing::Timing(const char* _nom, const Temps& _debut, const Temps& _duree):nom(NULL)//Initialisation
    {
        setJour(_nom);
        setHeure(_debut);
        setDuree(_duree);
    }

    Timing::Timing(const Timing& val):nom(NULL) // Copie
    {
        setJour(val.getJour());
        setHeure(val.getHeure());
        setDuree(val.getDuree());
    }

//Destructeur
    Timing::~Timing()
    {
        if(nom)
            delete nom;
    }


//Getters
    inline const char* Timing::getJour()const
    {
        return nom;
    }

    inline Temps Timing::getHeure()const
    {
        return debut;
    }

    inline Temps Timing::getDuree()const
    {
        return duree;
    }


//Setters
    inline void Timing::setJour(const char* val)
    {
        if (val==NULL)
        {
            cerr << "Chaine de caractère pour setnom invalide" << endl;
            return;
        }
        nom = new char[strlen(val)];
        strcpy(nom, val);
    }

    inline void Timing::setHeure(const Temps& val)
    {
        debut = val;
    }

    inline void Timing::setDuree(const Temps& val)
    {
        duree = val;
    }

    int Timing::cmp(const Timing& para)
    {
        if(getJour() < para.getJour())
            return -1;
        if(getJour() > para.getJour())
            return 1;
        
        if(getHeure() < para.getHeure())
            return -1;
        if(getHeure() > para.getHeure())
            return 1;

        if(getDuree() < para.getDuree())
            return -1;
        if(getDuree() > para.getDuree())
            return 1;
        return 0;
    }
    
    int Timing::operator<(const Timing& para)
    {
        return (cmp(para) == -1);
    }

    int Timing::operator>(const Timing& para)
    {
        return (cmp(para) == 1);
    }

    int Timing::operator==(const Timing& para)
    {
        return (cmp(para) == 0);    
    }
//Extra
    void Timing::Affiche()const
    {
        cout << endl << "Jour: " << getJour() << endl;
        cout << "Heure de début: ";
        getHeure().Affiche();
        cout << endl << "Durée: ";
        getDuree().Affiche();
    }


