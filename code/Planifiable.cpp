#include "Planifiable.h"


//Constructeurs
Planifiable::Planifiable()
{
    setId(0);
    txtptr = 0;
    tupleptr = 0;
}

Planifiable::Planifiable(int _id)
{
    setId(_id);
    txtptr = 0;
    tupleptr = 0;
}

Planifiable::Planifiable(const Planifiable& para)
{
    setId(para.getId());
    txtptr = 0;
    tupleptr = 0;
}

Planifiable::~Planifiable()
{
    if(tupleptr) delete tupleptr;
    if(txtptr) delete txtptr;
}

//Getters
int Planifiable::getId(void)const//LA FONCTION MAUDITE 2: LE RETOUR DU LD 1
{
    return id;
}

//Setters
void Planifiable::setId(int param)
{
    id = param; 
}

