#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "Event.h"
using namespace std;


// Quelques conseils avant de commencer...
// * N'oubliez pas de tracer (cout << ...) tous les constructeurs et le destructeur !!! Ca, c'est pas un conseil,
//   c'est obligatoire :-)
// * N'essayez pas de compiler ce programme entierement immediatement. Mettez tout en commentaires
//   sauf le point (1) et creez votre classe (dans ce fichier pour commencer) afin de compiler et tester 
//   le point (1). Une fois que cela fonctionne, decommentez le point (2) et modifier votre classe en 
//   consequence. Vous developpez, compilez et testez donc etape par etape. N'attendez pas d'avoir encode 
//   300 lignes pour compiler...
// * Une fois que tout le programme compile et fonctionne correctement, creez le .h contenant la declaration
//   de la classe, le .cxx contenant la definition des methodes, et ensuite le makefile permettant de compiler
//   le tout grace a la commande make 


int main()
{
  cout << endl << "(1) ***** Test constructeur par defaut + Affiche *******************************" << endl;
  {
    Event event;
    event.Affiche();
  } // La presence des accolades assure que le destructeur de Event sera appele --> a tracer !

  cout << endl << "(2) ***** Test des setters et getters *****" << endl;
  {
    Event event;
    event.setCode(1);
    event.setIntitule("Resto avec Denys (Merci Denys :)");
    event.Affiche();
    cout << "Code        = " << event.getCode() << endl;
    cout << "Intitule    = " << event.getIntitule() << endl;
  }

  cout << endl << "(3) ***** Test du constructeur d'initialisation ********************************" << endl;
  {
    Event event(2,"Cinema avec les potos");
    event.Affiche();
  }

  cout << endl << "(4) ***** Test du constructeur de copie ****************************************" << endl;
  {
    Event event1(1,"Labo C++");
    cout << "event1 (AVANT) :" << endl;
    event1.Affiche();
    {   
      Event event2(event1);
      cout << "event2 :" << endl;
      event2.Affiche();
      event2.setIntitule("Labo UNIX");
      event2.Affiche();
    } // de nouveau, les {} assurent que event2 sera detruit avant la suite
    cout << "event1 (APRES) :" << endl;
    event1.Affiche();
  }

  cout << endl << "(5) ***** Test d'allocation dynamique (constructeur par defaut) ****************" << endl;
  {
    Event *p = new Event();
    p->setCode(3);
    p->setIntitule("Visite medicale");
    p->Affiche();
    delete p;
  }

  cout << endl << "(6) ***** Test d'allocation dynamique (constructeur de copie) ******************" << endl;
  {
    Event event1(5,"Theorie C++");
    cout << "event1 (AVANT) :" << endl;
    event1.Affiche();
    Event* p = new Event(event1);
    cout << "La copie :" << endl;
    p->Affiche();
    cout << "Destruction de la copie..." << endl; 
    delete p;
    cout << "event1 (APRES) :" << endl;
    event1.Affiche();
  }

  return 0;
}
