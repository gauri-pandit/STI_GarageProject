#include"Garage.h"
#include<iostream>
using namespace std;

myGarage::myGarage(int capacity)
	:iCapacity(capacity)
{

}

myGarage::~myGarage()
{
	for (int i = 0;i < iVehicles.size();i++)
	{
		delete iVehicles[i];
	}
}

void myGarage::open()
{
	int userChoice = 0;
	int result = 0;
	while (1)
	{
		system("CLS");
		cout << endl << "Parking is created with " << iCapacity << " spaces" << endl;
		showMenu(); // calling show menu function
		cout << "Please enter your choice : ";
		int userChoice;
		cin >> userChoice;
		result = processChoice(userChoice); // put userchoice to processchoice functions
		if (result == -1)
		{
			cout << endl << "Invalid choice, Please enter choice again :";
			continue;
		}
		cout << endl << endl << "Enter 1 to continue else enter 0 to exit : ";
		int continueOrExit = 0;
		cin >> continueOrExit;
		if (continueOrExit == 1)
			continue;
		else
			break;
	}
}

void myGarage::showMenu()
{
	cout << endl << "**Parking Place Activities**";
	cout << endl << "1.Show the Parking Vehicle List with free places";
	cout << endl << "2.Add the Vehicle";
	cout << endl << "3.Remove the Vehicle";
	cout << endl << "**Search the vehicle**";
	cout << endl << "4.With Registration Number";
	cout << endl << "5.With Color";
	cout << endl << "6.With number of Wheels";
	cout << endl << "7.With number of Passangers";
	cout << endl << "8.With specific attribute";
	cout << endl << "9.Show Air Quality" << endl << endl;
}

int myGarage::processChoice(int userChoice)
{
	int index = 0;

	switch (userChoice)
	{
	case 1:
		ShowVehicleList();
		break;
	case 2:
		addVehicle();
		break;
	case 3:
		cout << "Enter parking index number to remove vehicle : ";
		cin >> index;
		removeVehicle(index - 1);
		break;
	case 4:
		searchVehicleWithRegNumber();
		break;
	case 5:
		searchVehicleWithColor();
		break;
	case 6:
		searchVehicleWithWheels();//Number of wheels
		break;
	case 7:
		searchVehicleWithPassangers();
		break;
		//case 8:
		//	void SearchWithAttributes();//With specific attribute
		//	break;
	case 9:
		ShowAirQuality();
		break;
	default:
		return -1;
		break;
	}
	return 1;
};

bool myGarage::addVehicle()
{
	Vehicle* vehicle = createVehicle();
	bool success = false;
	if (vehicle)
	{
		int numOfVehiclesInGarage = iVehicles.size();
		if (numOfVehiclesInGarage < iCapacity)
		{
			iVehicles.push_back(vehicle);
			success = true;
			vehicle->printVehicleCreated();
		}
	}
	return success;
}

Vehicle* myGarage::createVehicle()
{
	int vehicleChoice = 0;
	cout << endl << "Enter vehicle choice 1.Car 2.Truck 3.Bus 4.Motorcycle 5.Cycle : ";
	cin >> vehicleChoice;

	vehicleDetails details;

	cout << "Enter brand name : ";
	cin >> details.vehicleName;
	cout << "Enter Registration Number : ";
	cin >> details.regNumber;
	cout << "Enter Vehicle Color : ";
	cin >> details.color;
	cout << "Enter number of wheels : ";
	cin >> details.numOfWheels;
	cout << "Enter number of passengers : ";
	cin >> details.numOfPassengers;

	Vehicle* newVehicle = nullptr;
	switch (vehicleChoice)
	{
	case 1:
		newVehicle = Car::create(details); //createCar(details);
		break;
	case 2:
		newVehicle = Truck::create(details);
		break;
	case 3:
		newVehicle = Bus::create(details);
		break;
	case 4:
		newVehicle = Bike::create(details);
		break;
	case 5:
		newVehicle = Cycle::create(details);
		break;
	default:
		break;
	}
	return newVehicle;
}

int myGarage::removeVehicle(int index)
{
	if (iVehicles.size() == 0)
		return 0;

	// iterator declaration    // iterator variable : vectorBegin
	std::vector<Vehicle*>::iterator it = iVehicles.begin();

	// get vehicle at index
	Vehicle* vehicle = iVehicles.at(index);
	vehicle->printVehicleRemoved();

	// remove vehicle at index
	iVehicles.erase(it + index);

	delete vehicle;

	return iVehicles.size();
}

void myGarage::ShowVehicleList()
{
	int nVehicles = iVehicles.size();
	if (nVehicles <= 0)
	{
		cout << endl << "Parking is EMPTY";
		return;
	}
	printVehicles(iVehicles);

	for (int i = iVehicles.size(); i < iCapacity; i++)
	{
		cout << endl << i + 1;
	}
}

void myGarage::printVehicles(std::vector<Vehicle*> vehicles)// pass vector to print when call this function
{
	cout << endl << "index   type    Name   Number  Color  Wheels  Passengers";

	string type, name, number, color;
	int wheels, passengers;

	int i = 0;
	for (; i < vehicles.size(); i++)
	{
		type = vehicles[i]->getVehicleCategory();
		name = vehicles[i]->getVehicleName();
		number = vehicles[i]->getRegNumber();
		color = vehicles[i]->getColor();
		wheels = vehicles[i]->getNumOfWheels();
		passengers = vehicles[i]->getNumOfPassengers();

		cout << endl << i + 1 << "        " << type << "    " << name << "  " << number << "  " << color << "     " << wheels << "         " << passengers;
	}
}

void myGarage::searchVehicleWithRegNumber()
{
	string regNum;
	cout << endl << "Enter Registration number to Search: ";
	cin >> regNum;
	std::vector<Vehicle*> vehiclesFound;// created new vector here to push back searched specific values found in loop 

	for (int i = 0; i < iVehicles.size(); i++)
	{
		if (regNum == iVehicles[i]->getRegNumber())
		{
			vehiclesFound.push_back(iVehicles[i]);
		}
	}
	printVehicles(vehiclesFound);
}

void myGarage::searchVehicleWithColor()
{
	string Color;
	cout << endl << "Enter Color to Search: ";
	cin >> Color;
	std::vector<Vehicle*> vehiclesFound;

	for (int i = 0; i < iVehicles.size(); i++)
	{
		if (Color == iVehicles[i]->getColor())
		{
			vehiclesFound.push_back(iVehicles[i]);
		}
	}
	printVehicles(vehiclesFound);
}
void myGarage::searchVehicleWithWheels()
{
	int Wheels;
	cout << endl << "Enter number of wheels to Search: ";
	cin >> Wheels;
	std::vector<Vehicle*> vehiclesFound;

	for (int i = 0; i < iVehicles.size(); i++)
	{
		if (Wheels == iVehicles[i]->getNumOfWheels())
		{
			vehiclesFound.push_back(iVehicles[i]);
		}
	}
	printVehicles(vehiclesFound);
}

void myGarage::searchVehicleWithPassangers()
{
	int Passangers;
	cout << endl << "Enter number of Passangers to Search: ";
	cin >> Passangers;
	std::vector<Vehicle*> vehiclesFound;

	for (int i = 0; i < iVehicles.size(); i++)
	{
		if (Passangers == iVehicles[i]->getNumOfPassengers())
		{
			vehiclesFound.push_back(iVehicles[i]);
		}
	}
	printVehicles(vehiclesFound);
}

void myGarage::ShowAirQuality()
{
	int numberOfPollutingVehicles = 0;
	for (int i = 0; i < iVehicles.size(); i++)
	{
		if (iVehicles[i]->isPollutingVehicle())
			numberOfPollutingVehicles++;
		else
			continue;
	}
	double pollution = (double)numberOfPollutingVehicles / iCapacity; // *100;
	pollution = pollution * 100;
	cout << endl << "Air is " << pollution << " % polluted in the parking";
}




