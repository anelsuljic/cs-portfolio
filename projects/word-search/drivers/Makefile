# Opciones compilador
OPTIONS = -ansi -O2 -DNDEBUG -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -Wshadow -std=c++11




# Directorios
SRCDIR = ../cc
INCDIR = ../hh
LIBDIR = ../libs
OBJDIR = ../obj




# Macros
HEADS = -I $(INCDIR)/ -I $(LIBDIR)/
OBJ-TEST-ORIENTACION = $(OBJDIR)/orientacion.o $(OBJDIR)/eda-mem.o \
					   $(OBJDIR)/eda-error.o
OBJ-TEST-HUECO = $(OBJDIR)/hueco.o $(OBJDIR)/orientacion.o \
				 $(OBJDIR)/eda-mem.o $(OBJDIR)/eda-error.o
OBJ-TEST-MATCH = $(OBJDIR)/match.o $(OBJDIR)/orientacion.o \
				 $(OBJDIR)/eda-mem.o $(OBJDIR)/eda-error.o
OBJ-TEST-DICCIONARIO = $(OBJDIR)/diccionario.o $(OBJDIR)/eda-mem.o \
					   $(OBJDIR)/eda-error.o
OBJ-TEST-SOPA-LETRAS = $(OBJDIR)/sopa-letras.o $(OBJDIR)/orientacion.o \
					   $(OBJDIR)/eda-mem.o $(OBJDIR)/eda-error.o



# Creación de 'test-hueco'
test-hueco: test-hueco.cc $(OBJ-TEST-HUECO)
	@echo "Creando ejecutable 'test-hueco'..."
	@g++ $(OPTIONS) -o test-hueco test-hueco.cc \
					   $(OBJ-TEST-HUECO) $(HEADS)



# Creación de 'test-match'
test-match: test-match.cc $(OBJ-TEST-MATCH)
	@echo "Creando ejecutable 'test-match'..."
	@g++ $(OPTIONS) -o test-match test-match.cc \
					   $(OBJ-TEST-MATCH) $(HEADS)



# Creación de 'test-list-sort'
test-list-sort: test-list-sort.cc
	@echo "Creando ejecutable 'test-list-sort'..."
	@g++ $(OPTIONS) -o test-list-sort test-list-sort.cc $(HEADS)



# Creación de 'test-sopa-letras'
test-sopa-letras: test-sopa-letras.cc $(OBJ-TEST-SOPA-LETRAS)
	@echo "Creando ejecutable 'test-sopa-letras'..."
	@g++ $(OPTIONS) -o test-sopa-letras test-sopa-letras.cc \
					   $(OBJ-TEST-SOPA-LETRAS) $(HEADS)



# Creación de 'test-diccionario'
test-diccionario: test-diccionario.cc $(OBJ-TEST-DICCIONARIO)
	@echo "Creando ejecutable 'test-diccionario'..."
	@g++ $(OPTIONS) -o test-diccionario test-diccionario.cc \
					   $(OBJ-TEST-DICCIONARIO) $(HEADS)



# Creación de 'test-eda-util'
test-eda-util: test-eda-util.cc
	@echo "Creando ejecutable 'test-eda-util'..."
	@g++ $(OPTIONS) -o test-eda-util test-eda-util.cc $(HEADS)



# Creación de 'test-orientacion'
test-orientacion: test-orientacion.cc $(OBJ-TEST-ORIENTACION) | $(OBJDIR)

	@echo "Creando ejecutable 'test-orientacion'..."
	@g++ $(OPTIONS) test-orientacion.cc $(OBJDIR)/orientacion.o \
					$(OBJDIR)/eda-mem.o $(OBJDIR)/eda-error.o \
					$(HEADS) \
					-o test-orientacion 



# Creación de sopa-letras.o
$(OBJDIR)/sopa-letras.o: $(INCDIR)/sopa-letras.hh \
						 $(SRCDIR)/sopa-letras.cc | $(OBJDIR)

	@echo "Creando 'sopa-letras.o'..."
	@g++ $(OPTIONS) -c $(SRCDIR)/sopa-letras.cc $(HEADS) \
				    -o $(OBJDIR)/sopa-letras.o



# Creación de diccionario.o
$(OBJDIR)/diccionario.o: $(INCDIR)/diccionario.hh \
						 $(SRCDIR)/diccionario.cc | $(OBJDIR)

	@echo "Creando 'diccionario.o'..."
	@g++ $(OPTIONS) -c $(SRCDIR)/diccionario.cc $(HEADS) \
				    -o $(OBJDIR)/diccionario.o



# Creación de 'hueco.o'
$(OBJDIR)/hueco.o: $(INCDIR)/hueco.hh $(SRCDIR)/hueco.cc | $(OBJDIR)

	@echo "Creando 'hueco.o'..."
	@g++ $(OPTIONS) -c $(SRCDIR)/hueco.cc $(HEADS) \
				    -o $(OBJDIR)/hueco.o



# Creación de 'match.o'
$(OBJDIR)/match.o: $(INCDIR)/match.hh $(SRCDIR)/match.cc | $(OBJDIR)

	@echo "Creando 'match.o'..."
	@g++ $(OPTIONS) -c $(SRCDIR)/match.cc $(HEADS) \
				    -o $(OBJDIR)/match.o



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



$(OBJDIR):
	@echo "Creando directorio '$(OBJDIR)/' ..."
	@mkdir -p ../obj



clean:
	@echo "Eliminando ejecutables..."
	@rm -f test-eda-util test-orientacion test-diccionario test-list-sort \
		   test-match test-hueco test-sopa-letras
	@echo "Eliminando *.out ..."
	@rm -f *.out
	@echo "Eliminando *.o ..."
	@rm -rf $(OBJDIR)