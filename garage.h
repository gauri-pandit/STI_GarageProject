#include<vector>
#include"Vehicle.h"

class myGarage
{
public:
	myGarage(int capacity);
	~myGarage();
	void open();
	void showMenu();
	int processChoice(int userChoice);
	bool addVehicle();
	Vehicle* createVehicle();
	int removeVehicle(int index);
	void ShowVehicleList();
	void searchVehicleWithRegNumber();
	void searchVehicleWithColor();
	void searchVehicleWithWheels();
	void searchVehicleWithPassangers();
	void printVehicles(std::vector<Vehicle*> vehicles);
	void ShowAirQuality();
private:
	const int iCapacity = 0;
	std::vector<Vehicle*> iVehicles;
};





