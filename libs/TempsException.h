#ifndef TEMPSEXCEPTION_H
#define TEMPSEXCEPTION_H
#include "Exception.h"
class TempsException:public Exception
{
    private:
        int code;
    public:
    //Constructeurs
        TempsException();
        TempsException(const char*, int);
        TempsException(const TempsException&);
        ~TempsException();

    //Getters
        int getCode()const;

    //Constantes



};

        static const int HEURE_INVALIDE = 1;
        static const int MINUTE_INVALIDE = 2;
        static const int DEPASSEMENT = 3;
        static const int FORMAT_INVALIDE = 4;

#endif