//dados.cc
//Cuerpo de los métodos de la clase Dados
#include "dados.h"
#include <cstdlib>

Dados::Dados(){
	//It will change the random seed and set a initial value for d1_ and d2_
	srand(time(NULL)); //time(NULL) returns "UNIX Epoch"
	d1_ = 1;
	d2_ = 2;

}

Dados::lanzamiento(){
	//It assigns a random value for d1_ and d2_
	d1_  = (rand() % 6)+1;
	d2_ = (rand() % 6)+1;
}

Dados::getDado1(){
	//It returns d1_ value
	return d1_;
}

Dados::getDado2(){
	//It returns d2_ value
	return d2_;
}

Dados::setDado1(int valor){
	//It assigns valor to d1_  if it is correct return True
	if (0 < valor < 7){
		d1_ = valor;
		return true;
	}
	else{
		return false;
	}
}

Dados::setDado2(int valor){
	//It assigns valor to d2_  if it is correct return True
	if (0 < valor < 7){
		d2_ = valor;
		return true;
	}
	else{
		return false;
	}
}

Dados::getSuma(){
	//It returns the sum of the two dices
	int suma;
	suma = d1_ + d2_;
	return suma;
}
