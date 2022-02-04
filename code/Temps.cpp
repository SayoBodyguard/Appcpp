#include "Temps.h"
#include "TempsException.h"

//Constructeurs
Temps::Temps()
{
	setHeure(0);
	setMinute(0);
}

Temps::Temps(int _heure, int _minute)
{
	setHeure(_heure);
	setMinute(_minute);
}

Temps::Temps(int _duree)
{
	if(_duree > 1619) //23h59 en minutes
	{
		throw TempsException("Durée trop longue!", DEPASSEMENT);
	}
	setHeure(_duree/60);
	setMinute(_duree%60);
}

Temps::Temps(const Temps& param)
{
	setHeure(param.getHeure());
	setMinute(param.getMinute()); 
}

//Destructeur
Temps::~Temps()
{
	//Il n'y a que des "int", rien a faire
}

//Setters
inline void Temps::setHeure(int val)
{
	if( val < 0 || val >= 24 )
			throw TempsException("Heure invalide", HEURE_INVALIDE);	
	heure = val;
}

inline void Temps::setMinute(int val)
{
	if( (val < 0) || (val >= 60) )
		throw TempsException("Minute invalide", MINUTE_INVALIDE);
	minute = val;
}

//Getters
inline int Temps::getHeure()const
{
	return heure;
}

inline int Temps::getMinute()const
{
	return minute; 
}

inline int Temps::getDureeMinutes()const
{
	return (heure*60)+minute;
}

//Surcharge des opérateurs
Temps& Temps::operator=(const Temps& para)
{
	heure = para.heure;
	minute = para.minute;
	return *this;
}

Temps Temps::operator+( const Temps& tB)const
{
	int duree;
	duree = this->getDureeMinutes() + tB.getDureeMinutes();
	if(duree >= (24*60))
	{
		throw TempsException("Temps additioné trop élevé", DEPASSEMENT);
	}

	return Temps(duree);
}

Temps operator+(int num, const Temps& obj)
{
	if(obj.getDureeMinutes() + num >=(24*60))
		throw TempsException("Temps additioné trop élevé", DEPASSEMENT);
	return obj+Temps(num);
}

Temps operator+(const Temps& obj, int num)
{
	if(obj.getDureeMinutes() + num >=(24*60))
		throw TempsException("Temps additioné trop élevé", DEPASSEMENT);
	return obj+Temps(num);
}

Temps Temps::operator-(const Temps& par)const
{
	int duree;
	duree = this->getDureeMinutes() - par.getDureeMinutes();
	if(duree < 0)
	{
		throw TempsException("Temps résultat négatif",DEPASSEMENT);
	}

	return Temps(duree);
}

Temps operator-(int num, const Temps& obj)
{	
	if(obj.getDureeMinutes()-num < 0)
		throw TempsException("Temps resultat négatif", DEPASSEMENT);
	return obj-Temps(num);
}

Temps operator-(const Temps& obj, int num)
{
	if(obj.getDureeMinutes()-num < 0)
		throw TempsException("Temps resultat négatif", DEPASSEMENT);
	return obj-Temps(num);
}

ostream& operator<<(ostream& s, const Temps& t)
{
	if(t.getMinute())
	{
		s << t.getHeure() << "h" << t.getMinute();
	}
	else
	{
		if(t.getHeure())
			s << t.getHeure() << " heures";
		else
			cout << "Durée Nulle";
	}
	return s;
}

istream& operator>>(istream& s, Temps& t)
{
	char param[6];
	char param2[3];

	s >> &param[0];
	if(param[2]!= 'h')
		throw TempsException("Format Invalide",FORMAT_INVALIDE);
	strncpy(&param2[0], &param[0],2);
	param2[2] = 0;
	t.setHeure(atoi(&param2[0]));
	strncpy(&param2[0], &param[3],2);
	param2[2] = 0;
	t.setMinute(atoi(&param2[0]));
	return s;

	//Pas propre, demander une correction.
}

int Temps::operator<(const Temps& par)
{
	return cmp(par)==-1;
}

int Temps::operator>(const Temps& par)
{
	return cmp(par)==1;
}

int Temps::operator==(const Temps& par)
{
	return cmp(par)==0;
}

Temps Temps::operator++()
{
	if(this->getDureeMinutes() >= (24*60+1))
		throw TempsException("Temps additioné trop élevé", DEPASSEMENT);
	*this = *(this) + 1;
	return *(this);
}

Temps Temps::operator++(int)
{
	if(this->getDureeMinutes() >= (24*60+1))
		throw TempsException("Temps additioné trop élevé", DEPASSEMENT);
	Temps temp(*this);
	++(*this);
	return temp;
}

Temps Temps::operator--()
{
	if(this->getDureeMinutes() == 0)
		throw TempsException("Temps resultat négatif", DEPASSEMENT);
	*this = *(this) - 1;
	return *(this);
}

Temps Temps::operator--(int)
{
	if(this->getDureeMinutes() == 0)
		throw TempsException("Temps resultat négatif", DEPASSEMENT);
	Temps temp(*this);
	++(*this);
	return temp;
}


//Extra
void Temps::Affiche()const
{
	if(getMinute())
	{
		cout << getHeure() << "h" << getMinute() << endl;
	}
	else
	{
		if(getHeure())
			cout << getHeure() << " heures" << endl;
		else
			cout << "Durée Nulle" << endl;
	}
}

inline int Temps::cmp(const Temps& t)
{
	if(getDureeMinutes() < t.getDureeMinutes()) return -1;
	if(getDureeMinutes() > t.getDureeMinutes()) return 1;
	return 0;
}


