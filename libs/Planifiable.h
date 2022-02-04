#ifndef PLANIFIABLE_H
#define PLANIFIABLE_H
class Planifiable //=>classe abstraite
{
    protected:
        int id;
        char* txtptr;
        char* tupleptr;
    public:
        //Constructeur
        Planifiable();
        Planifiable(int);
        Planifiable(const Planifiable&);
        virtual ~Planifiable();

        //Getters
        int getId(void)const;

        //Setters
        void setId(int);

        //Methodes
        virtual const char* Txt() = 0;
        virtual const char* Tuple() = 0;
};
#endif