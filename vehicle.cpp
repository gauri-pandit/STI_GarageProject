#include <iostream>
#include<string>
#include"Vehicle.h"

// class definition in cpp file

//==================Vehicle Class==================================
Vehicle::Vehicle(vehicleDetails details)
{
	iRegNumber = details.regNumber;
	iColor = details.color;
	iNumOfWheels = details.numOfWheels;
	iNumOfPassengers = details.numOfPassengers;
	iVehicleName = details.vehicleName;
}

Vehicle::~Vehicle()
{
}

//==================Car Class======================================

Car::Car(vehicleDetails details, bool convertible, bool electric)
	:Vehicle(details)
{
	iIsConvertibleCar = convertible;
	iIsElectricCar = electric;
}

Car::~Car()
{

}

Vehicle* Car::create(vehicleDetails details)
{
	int isConvertible, isElectric;
	cout << "Is car convertible 1.Yes or 0.No : ";
	cin >> isConvertible;
	cout << "Is car electric 1.Yes or 0.No : ";
	cin >> isElectric;

	Vehicle* newVehicle = new Car(details, isConvertible, isElectric);
	return newVehicle;
}

void Car::printVehicleCreated()
{
	cout << endl << "Car is parked in the parking " << endl;
}

void Car::printVehicleRemoved()
{
	cout << endl << "Car is removed from parking " << endl;
}
//==================Truck class======================================
Truck::Truck(vehicleDetails details, bool isOpen, bool isHeavy)
	:Vehicle(details), isOpen(isOpen), isHeavy(isHeavy)
{

}

Truck::~Truck()
{

}
Vehicle* Truck::create(vehicleDetails details)
{
	int isOpen, isHeavy;
	cout << "Is it open truck 1.Yes or 0.No : ";
	cin >> isOpen;
	cout << "Is it heavy truck 1.Yes or 0.No : ";
	cin >> isHeavy;

	Vehicle* newVehicle = new Truck(details, isOpen, isHeavy);
	return newVehicle;
}

void Truck::printVehicleCreated()
{
	cout << endl << "Truck is parked in the parking " << endl;
}

void Truck::printVehicleRemoved()
{
	cout << endl << "Truck is removed from parking " << endl;
}
//==================Bus class=========================================
Bus::Bus(vehicleDetails details, bool isLongRoute, bool isEco)
	:Vehicle(details), isLongRoute(isLongRoute), isEco(isEco)
{

}

Bus::~Bus()
{

}
Vehicle* Bus::create(vehicleDetails details)
{
	int isLongRoute, isEco;
	cout << "Is it LongRoute Bus 1.Yes or 0.No : ";
	cin >> isLongRoute;
	cout << "Is it Eco Bus 1.Yes or 0.No : ";
	cin >> isEco;

	Vehicle* newVehicle = new Bus(details, isLongRoute, isEco);
	return newVehicle;
}

void Bus::printVehicleCreated()
{
	cout << endl << "Bus is parked in the parking " << endl;
}

void Bus::printVehicleRemoved()
{
	cout << endl << "Bus is removed from parking " << endl;
}

//==================Bike class=======================================

Bike::Bike(vehicleDetails details, bool isSportBike, bool isElectric)
	:Vehicle(details)
{
	iIsSportBike = isSportBike;
	iIsElectricBike = isElectric;
	iNumOfWheels = 2;
	iNumOfPassengers = 2;
}

Bike::~Bike()
{

}

Vehicle* Bike::create(vehicleDetails details)
{
	int isSport, isElectric;
	cout << "Is it sport Motorcycle 1.Yes or 0.No : ";
	cin >> isSport;
	cout << "Is it electric Motorcycle 1.Yes or 0.No : ";
	cin >> isElectric;

	Vehicle* newVehicle = new Bike(details, isSport, isElectric);
	return newVehicle;
}

void Bike::printVehicleCreated()
{
	cout << endl << "Motorcycle is parked in the parking " << endl;
}

void Bike::printVehicleRemoved()
{
	cout << endl << "Motorcycle is removed from parking " << endl;
}

//==================Cycle Class======================================

Cycle::Cycle(vehicleDetails details, bool isSport, bool isElectric)
	:Vehicle(details), iIsSport(isSport), iIsElectricCycle(isElectric)
{

}

Cycle::~Cycle()
{

}

Vehicle* Cycle::create(vehicleDetails details)
{
	int isSport, isElectric;
	cout << "Is Cycle sport 1.Yes or 0.No : ";
	cin >> isSport;
	cout << "Is Cycle electric 1.Yes or 0.No : ";
	cin >> isElectric;

	Vehicle* newVehicle = new Cycle(details, isSport, isElectric);
	return newVehicle;
}

void Cycle::printVehicleCreated()
{
	cout << endl << "Cycle is parked in the parking " << endl;
}

void Cycle::printVehicleRemoved()
{
	cout << endl << "Cycle is removed from parking " << endl;
}