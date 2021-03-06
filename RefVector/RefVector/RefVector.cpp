// RefVector.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

int do_something(std::vector<int> v1, std::vector<int> v2, std::vector<int> *r);

int main()
{
	//Deklaration der Vektoren
	std::vector<int> vect1;
	std::vector<int> vect2;
	std::vector<int> res;

	//Befüllen der Vektoren 1 und 2
	for (int i = 0; i < 20; i++) {
		vect1.push_back(i);
		vect2.push_back(20 - i);
	}

	//Vektoren verarbeiten 
	//do_something erstellt von vect1 und vect2 Kopien und bekommt die Adresse von res
	if (do_something(vect1, vect2, &res) != 0) {
		std::cout << "Fatal eroor!!" << std::endl;
		return -1;
	}
	
	//Result Vektor ausgeben
	for (int i = 0; i < res.size(); i++) {
		std::cout << i << ". " << res.at(i) << std::endl;
	}

	//wait for keypress
	std::cin.get();
    return 0;
}

//Berechnet das Skalarprodukt
int do_something(std::vector<int> v1, std::vector<int> v2, std::vector<int> *r) {
	for (int i = 0; i < v1.size(); i++) {
		//ASCII Pfeil, weil auf den Member einer referenzierten Klasse zugegriffen wird
		r->push_back(v1.at(i) * v2.at(i));
	}
	return 0;
}