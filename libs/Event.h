#ifndef EVENT_H
#define EVENT_H
#include <cstring>
#include <iostream>
#include "Timing.h"
using namespace std;
class Event
{
	private:
		int id;
		char* intitule;
		Timing* timing;
	
	public:
		static int codeCourant;
	//construct & dest
		Event();
		Event(int, const char*);
		Event(const Event&);
		~Event();
		
	//getset
		void setCode(const int);
		const int getCode()const;

		Timing getTiming()const;
		void setTiming(const Timing&);
		
		void setIntitule(const char*);
		const char* getIntitule()const;
		void Affiche()const;
};
#endif