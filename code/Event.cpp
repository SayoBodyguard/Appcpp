#include "Event.h"
	int Event::codeCourant = 0;
	//Defaut
	Event::Event():intitule(NULL)
	{
		timing = NULL;
		cout << "Constructeur par defaut\n";
		setIntitule("defaut");
		setCode(codeCourant++);
	}
	//Definition
	Event::Event(int valId, const char* valInt):intitule(NULL)
	{
		timing = NULL;
		cout << "Constructeur de definition\n";
		setIntitule(valInt);
		setCode(valId);
	}
	
	//Copie
	Event::Event(const Event& val):intitule(NULL)
	{
		timing = NULL;
		cout << "Constructeur de copie" << endl;
		setIntitule(val.getIntitule());
		setCode(val.getCode());
	}
	
	//Destructeur
	Event::~Event()
	{
		cout << "Destructeur code " << id << endl;
		delete intitule;
		if(timing)
			delete timing;
	}
//Getters and setters
	//ID
	inline void Event::setCode(const int val)
	{
		if ( val < 0)
		{
			cout << "Passage d'un parametre négatif a setCode. (C'est quoi une exception?)" << endl;
			exit(-1);
		} 
		id = val;
		
	}
	inline const int Event::getCode()const
	{
		return id;
	}
	
	//intitule
	inline void Event::setIntitule( const char* val)
	{
		if(val == NULL)
			return;
		if(intitule)
			delete intitule;
		intitule = new char[strlen(val)+1];
		strcpy(intitule,val);
	}
	
	inline const char* Event::getIntitule()const
	{
		return intitule;
	}

	//timing
	inline Timing Event::getTiming()const
	{
		
		return *timing;
	}

	void Event::setTiming(const Timing& val)  //LA FONCTION MAUDITE 
	{
		if(timing)
			delete timing;
		timing = new Timing(val);
	}
//Fonction bonus
	void Event::Affiche()const
	{
		cout << endl << "----------------" << endl;

		cout << "Code: "<< getCode() << endl;
		cout << "Intitule: " << getIntitule() << endl;
		if(timing)
		{
			getTiming().Affiche();
		}
		cout << "----------------" << endl;
	}
	
