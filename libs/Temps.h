#ifndef TEMPS_H
#define TEMPS_H

#include <iostream>
#include <cstring>
#include "TempsException.h"
using namespace std;

/**************************************************************************************/
/*** Modélise la notion de temps/de durée  ********************************************/
/**************************************************************************************/

class Temps
{
	//Les copains
		friend Temps operator+(int,const Temps&);
		friend Temps operator+(const Temps&, int);
		friend Temps operator-(int, const Temps&);
		friend Temps operator-(const Temps&, int);
		friend ostream& operator<<(ostream&, const Temps&);
		friend istream& operator>>(istream&, Temps&);

	private:
		int heure;
		int minute;

		int cmp(const Temps&); //-1 si this < param, 0 si =, 1 si this > param
		
	public:
	//Constructeurs
		Temps(); //Par defaut
		Temps(int,int); //D�finition => Heures, minutes
		Temps(int); //D�finition => Dur�e en minutes
		Temps(const Temps&); //Copie

	//Destructeur
		~Temps();

	//Getters
		int getHeure()const;
		int getMinute()const;
		int getDureeMinutes()const;
	
	//Setters
		void setHeure(int);
		void setMinute(int);

	//Surcharge des opérateurs
		Temps& operator=(const Temps&);
		Temps operator+(const Temps&)const;
		Temps operator-(const Temps&)const;
		int operator<(const Temps&);
		int operator>(const Temps&);
		int operator==(const Temps&);
		Temps operator++();
		Temps operator++(int);
		Temps operator--();
		Temps operator--(int);

	//Extra
		void Affiche()const;
};
#endif