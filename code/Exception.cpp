#include "Exception.h"

//Constructeurs
Exception::Exception():Message(NULL)
{
    setMessage("NULL");
}

Exception::Exception(const char* para):Message(NULL)
{
    setMessage(para);
}

Exception::Exception(const Exception& para):Message(NULL)
{
    setMessage(para.getMessage());
}

Exception::~Exception()
{
    if (Message) delete Message;
}

//Getters
const char* Exception::getMessage()const
{
    return Message;
}

//Setters
void Exception::setMessage(const char* param)
{
    if(Message) delete Message;
    Message = new char[strlen(param)];
    strcpy(Message, param);
}