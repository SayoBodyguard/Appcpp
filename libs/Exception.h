#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
class Exception
{
    private:
        char* Message;
    public:
    //Constructeurs
        Exception();
        Exception(const char*);
        Exception(const Exception&);
        virtual ~Exception();

    //Getters
        const char* getMessage()const;
    
    //Setters
        void setMessage(const char*);
    
    //Methodes
        virtual int getCode()const = 0;
};
#endif