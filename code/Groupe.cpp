#include "Groupe.h"
//Constructeurs
Groupe::Groupe():Planifiable()
{
    setNumero(0);
}

Groupe::Groupe(int _num):Planifiable()
{
    setNumero(_num);
} 

Groupe::Groupe(int _id, int _num):Planifiable(_id)
{
    setNumero(_num);
}

Groupe::Groupe(const Groupe& para):Planifiable((const Planifiable&) para)
{
    setNumero(para.getNumero());
}

Groupe::~Groupe()
{

}

//Getters
int Groupe::getNumero()const
{
    return Numero;
}

//Setters
void Groupe::setNumero(int val)
{
    Numero = val;
}

//Methodes
const char* Groupe::Txt()
{
    //cout << "Appel txt groupe" << endl;
    if(txtptr) delete txtptr;
    ostrstream s;
    s << "G" << getNumero();
    txtptr = new char[strlen(s.str())+1];
    strcpy(txtptr, s.str());
    return txtptr;
}

const char* Groupe::Tuple()
{
    if(tupleptr) delete tupleptr;
    ostrstream s;
    s << getId() << ";G" << getNumero();
    tupleptr = new char[strlen(s.str())+1];
    strcpy(tupleptr, s.str());
    return tupleptr;
}

//Surcharge operateurs
ostream& operator<<(ostream& s, const Groupe& para)
{
    s << "G" << para.getNumero();
    return s;
}

Groupe& Groupe::operator=(const Groupe& para)
{
    setNumero(para.getNumero());
    setId(para.getId());
    return *this;
}