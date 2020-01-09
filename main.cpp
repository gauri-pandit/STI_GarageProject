#include<iostream>
#include "Garage.h"
using namespace std;

int main()
{
	int garageSpace = 15;
	myGarage* newGarage = new myGarage(garageSpace);
	if (newGarage)
	{
		newGarage->open();
	}

	delete newGarage;

	return 0;
}