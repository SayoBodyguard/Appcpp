#include "TempsException.h"

TempsException::TempsException():Exception()
{
    code = 0;
}

TempsException::TempsException(const char* _message, int _code):Exception(_message)
{
    code = _code;
}

TempsException::TempsException(const TempsException& para):Exception((const TempsException&)para)
{
    code = para.getCode();
}
TempsException::~TempsException()
{}

int TempsException::getCode()const
{
    return code;
}