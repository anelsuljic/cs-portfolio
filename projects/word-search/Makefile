# Opciones compilador
OPTIONS = -ansi -O2 -DNDEBUG -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -Wshadow -std=c++11



# Directorios
SRCDIR = cc
INCDIR = hh
LIBDIR = libs
OBJDIR = obj



# Macros
HEADS = -I $(INCDIR)/ -I $(LIBDIR)/
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/builder.o $(OBJDIR)/solver.o \
		  $(OBJDIR)/sopa-letras.o $(OBJDIR)/diccionario.o $(OBJDIR)/match.o \
		  $(OBJDIR)/hueco.o $(OBJDIR)/orientacion.o $(OBJDIR)/eda-error.o \
		  $(OBJDIR)/eda-mem.o 


# Creación del ejecutable
program: $(OBJECTS)
	@echo "Creando ejecutable..."
	@g++ $(OPTIONS) -o program $(OBJECTS) $(HEADS)


# Creación de ficheros .o
objetos: $(OBJECTS)



# Creación de 'main.o'
$(OBJDIR)/main.o: main.cc | $(OBJDIR)

	@echo "Creando 'main.o'..."
	@g++ $(OPTIONS) -c main.cc $(HEADS) \
					-o $(OBJDIR)/main.o



# Creación de 'solver.o'
$(OBJDIR)/solver.o: $(SRCDIR)/solver.cc $(INCDIR)/solver.hh | $(OBJDIR)

	@echo "Creando 'solver.o' ..."
	@g++ $(OPTIONS) -c $(SRCDIR)/solver.cc $(HEADS) \
					-o $(OBJDIR)/solver.o



# Creación de 'builder.o'
$(OBJDIR)/builder.o: $(SRCDIR)/builder.cc $(INCDIR)/builder.hh | $(OBJDIR)

	@echo "Creando 'builder.o' ..."
	@g++ $(OPTIONS) -c $(SRCDIR)/builder.cc $(HEADS) \
					-o $(OBJDIR)/builder.o



# Creación de 'match.o'
$(OBJDIR)/match.o: $(SRCDIR)/match.cc \
						 $(INCDIR)/match.hh | $(OBJDIR)

	@echo "Creando 'match.o' ..."
	@g++ $(OPTIONS) -c $(SRCDIR)/match.cc $(HEADS) \
					-o $(OBJDIR)/match.o



# Creación de 'hueco.o'
$(OBJDIR)/hueco.o: $(SRCDIR)/hueco.cc \
						 $(INCDIR)/hueco.hh | $(OBJDIR)

	@echo "Creando 'hueco.o' ..."
	@g++ $(OPTIONS) -c $(SRCDIR)/hueco.cc $(HEADS) \
					-o $(OBJDIR)/hueco.o



# Creación de 'diccionario.o'
$(OBJDIR)/diccionario.o: $(SRCDIR)/diccionario.cc \
						 $(INCDIR)/diccionario.hh | $(OBJDIR)

	@echo "Creando 'diccionario.o' ..."
	@g++ $(OPTIONS) -c $(SRCDIR)/diccionario.cc $(HEADS) \
					-o $(OBJDIR)/diccionario.o



# Creación de 'sopa-letras.o'
$(OBJDIR)/sopa-letras.o: $(SRCDIR)/sopa-letras.cc \
						 $(INCDIR)/sopa-letras.hh | $(OBJDIR)

	@echo "Creando 'sopa-letras.o' ..."
	@g++ $(OPTIONS) -c $(SRCDIR)/sopa-letras.cc $(HEADS) \
					-o $(OBJDIR)/sopa-letras.o



# Creación de 'orientacion.o'
$(OBJDIR)/orientacion.o: $(INCDIR)/orientacion.hh $(SRCDIR)/orientacion.cc \
						 | $(OBJDIR)

	@echo "Creando 'orientacion.o'..."
	@g++ $(OPTIONS) -c $(SRCDIR)/orientacion.cc $(HEADS) \
				    -o $(OBJDIR)/orientacion.o



# Creación de 'eda-error.o'
$(OBJDIR)/eda-error.o: $(LIBDIR)/eda-error.hh $(LIBDIR)/impl/eda-error.cc \
					   | $(OBJDIR)

	@echo "Creando 'eda-error.o'..."
	@g++ $(OPTIONS) -c $(LIBDIR)/impl/eda-error.cc $(HEADS) \
					-o $(OBJDIR)/eda-error.o



# Creación de 'eda-mem.o'
$(OBJDIR)/eda-mem.o: $(LIBDIR)/eda-mem.hh $(LIBDIR)/impl/eda-mem.cc \
					 | $(OBJDIR)
	
	@echo "Creando 'eda-mem.o'..."
	@g++ $(OPTIONS) -c $(LIBDIR)/impl/eda-mem.cc $(HEADS) \
				    -o $(OBJDIR)/eda-mem.o



# Creación del directorio de objetos
$(OBJDIR):
	@echo "Creando directorio '$(OBJDIR)/'..."
	@mkdir -p $(OBJDIR)



# Eliminación de archivos
clean:
	@echo "Eliminando ejecutables..."
	@rm -f program
	@echo "Eliminando *.out ..."
	@rm -f *.out
	@echo "Eliminando *.o ..."
	@rm -rf $(OBJDIR)