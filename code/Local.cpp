#include "Local.h"

//Constructeurs
Local::Local():Planifiable()
{
    Nom = NULL;
    setNom("NULL");
}

Local::Local(int _id, const char* _nom):Planifiable(_id)
{
    Nom=NULL;
    setNom(_nom);
}

Local::Local(const char* _nom):Planifiable()
{
    Nom = NULL;
    setNom(_nom);
}

Local::Local(const Local& para):Planifiable((const Planifiable&) para)
{
    Nom = NULL;
    setNom(para.getNom());
}

Local::~Local()
{
    if(Nom) delete Nom;
}

//Getters
const char* Local::getNom()const
{
    return Nom;
}

//Setters
void Local::setNom(const char* para)
{
    if(Nom) delete Nom;
    Nom = new char[strlen(para)];
    strcpy(Nom, para);
}

//Methodes
const char* Local::Txt()
{
    if(txtptr) delete txtptr;
    ostrstream s;
    s << getNom();
    txtptr = new char[strlen(s.str())+1];
    strcpy(txtptr, s.str());
    return txtptr;
}

const char* Local::Tuple()
{
    if(tupleptr) delete tupleptr;
    ostrstream s;
    s << getId() << ";" << getNom();
    tupleptr = new char[strlen(s.str())+1];
    strcpy(tupleptr, s.str());
    return tupleptr;
}

//Surcharge d'opérateurs
ostream& operator<<(ostream& s, const Local& para)
{
    s << para.getNom();
    return s;
}

Local& Local::operator=(const Local& para)
{
    setNom(para.getNom());
    setId(para.getId());
    return *this;
}