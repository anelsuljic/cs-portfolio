all : antlr test

antlr :
	@echo "Generant fitxers necessaris per a executar el projecte..."
	@antlr4 -Dlanguage=Python3 -no-listener -visitor forth.g4

test :
	@echo "Executant jocs de proves del test.txt (si no apareix cap missatge \
	addicional, vol dir que han funcionat correctament)"
	@python3 -m doctest test.txt

execute :
	python3 -i forth.py

clean :
	@echo "Netejant directori"
	@rm -rf forthLexer.* forthParser.* forthVisitor.* *.interp *.tokens \
			.antlr/ __pycache__/