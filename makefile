#Variables
MAIN=Test5.cpp
LIBPATH=libs/
OBJPATH=obj/
BINPATH=bin/
CODEPATH=code/
IOPTION= -I libs
OBJFILES = $(OBJPATH)Event.o $(OBJPATH)TempsException.o $(OBJPATH)Temps.o $(OBJPATH)Timing.o $(OBJPATH)Planifiable.o $(OBJPATH)Professeur.o $(OBJPATH)Groupe.o $(OBJPATH)Local.o $(OBJPATH)Exception.o 
HEADFILES = $(LIBPATH)Event.h $(LIBPATH)Temps.h $(LIBPATH)Timing.h $(LIBPATH)Planifiable.h $(LIBPATH)Professeur.h $(LIBPATH)Groupe.h $(LIBPATH)Local.h $(LIBPATH)Exception.h $(LIBPATH)TempsException.h
#SILENCE
.SILENT:

#Compilation
$(BINPATH)Applic: $(CODEPATH)$(MAIN) $(OBJFILES) $(HEADFILES)
	echo Compilation de applic
	g++ -Wall -Wno-deprecated -o $(BINPATH)Applic $(CODEPATH)$(MAIN) $(IOPTION) $(OBJFILES)

clean:
	rm $(OBJPATH)*.o

clobber: clean
	rm $(BINPATH)Applic


#Les cibles "j'admet ma défaite"
remake: clean $(BINPATH)Applic

run: $(BINPATH)Applic
	bin/Applic

rerun: clean $(BINPATH)Applic
	bin/Applic









 #La suite de ce makefile se base uniquement sur de la magie






















##La magie
#Soyons fous
$(OBJPATH)%.o: $(CODEPATH)%.cpp #Automatiquement remplacé par $(OBJPATH)AnyFile.o: $(CODEPATH)Anyfile.cpp
	echo Compilation de $@
	g++ -Wno-deprecated -c $(IOPTION) $< -o $@

# $@ => Nom de la cible
# $< => Nom de la 1ere "condition" (ici $(CODEPATH)AnyFile.cpp)


##LES TEMPS ANCIENS

# $(OBJPATH)Temps.o: $(CODEPATH)Temps.cpp $(LIBPATH)Temps.h $(CODEPATH)TempsException.cpp $(LIBPATH)TempsException.h
# 	echo Compilation de $@
# 	g++ -Wall -c $(IOPTION) $< -o $@

# $(OBJPATH)Event.o: $(CODEPATH)Event.cpp $(LIBPATH)Event.h
# 	echo Compilation de $@
# 	g++ -Wall -c $(IOPTION) $< -o $@

# $(OBJPATH)Timing.o: $(CODEPATH)Timing.cpp $(LIBPATH)Timing.h 
# 	echo Compilation de $@
# 	g++ -Wall -c $(IOPTION) $< -o $@


# $(OBJPATH)Professeur.o: $(CODEPATH)Professeur.cpp $(LIBPATH)Professeur.h $(OBJPATH)Planifiable.o
# 	echo Compilation de $@
# 	g++ -Wno-deprecated -c $(IOPTION) $< -o $@

# $(OBJPATH)Planifiable.o: $(CODEPATH)Planifiable.cpp $(LIBPATH)Planifiable.h
# 	echo Compilation de $@
# 	g++ -Wno-deprecated -c $(IOPTION) $< -o $@

# $(OBJPATH)Local.o: $(CODEPATH)Local.cpp $(LIBPATH)Local.h
# 	echo Compilation de $@
# 	g++ -Wno-deprecated -c $(IOPTION) $< -o $@

# $(OBJPATH)Groupe.o: $(CODEPATH)Groupe.cpp $(LIBPATH)Groupe.h
# 	echo Compilation de $@
# 	g++ -Wno-deprecated -c $(IOPTION) $< -o $@