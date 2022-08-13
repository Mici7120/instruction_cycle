#Remplazar Nombre_de_la_clase ppr el nombre que tengan en clase .cpp
CXX=g++

all: build

#Escenario de construccion
build:
	$(CXX) -std=c++11 -o main main.cpp Simulator.cpp

#Ambiente de ejecucion
run:
	@./main
