#pragma once
#include<string.h>
#include<iostream>
#include "Flight.h"

using namespace std;

struct CheckFligths
{
	double arrival;
	string arrive;
};

struct Economy {
	bool available = true;
	int ID;
	Economy() {
		available = true;
	}
};

struct Business {
	bool available;
	int ID;
	Business() {
		available = true;
	}
};

class Planes {
private:
	CheckFligths* check;
	Economy* economy;
	Business* business;
	string type;
	int num_journeys;
	Flight* flights;
	int* econregistered;
	int* busregistered;
	int econregisteredseats;
	int busregisteredseats;

public:

	Planes() {
		economy = new Economy[50];
		business = new Business[10];
		econregisteredseats = (rand() % 6) + 10;
		busregisteredseats = (rand() % 5) + 1;
		econregistered = new int[econregisteredseats];
		busregistered = new int[busregisteredseats];

		num_journeys = 0;
	}

	void setTypeLocal() {
		type = "Local";
	}

	void setTypeInternational() {
		type = "International";
	}

	void setNumberofFlights() {

		if (type == "Local") {
			num_journeys = 2;
		}
		else {
			num_journeys = 1;
		}

		flights = new Flight[num_journeys];
		check = new CheckFligths[num_journeys];

	}

	void setEconomy()
	{
		int id = 1;
		for (int i = 0; i < 50; i++) {
			if (i == 0) {
				economy[i].available = true;            //The first seat is always available
			}
			else if (i == 1) {
				economy[i].available = false;           //The second seat is not available
			}

			if (i >= 2) {
				if (i % 2 == 0) {
					economy[i].available = true;
				}

				else {
					economy[i].available = false;
				}
			}

			economy[i].ID = id;
			id++;
		}
	}


	void setBusiness() {
		int id = 1;
		for (int i = 0; i < 10; i++) {
			if (i == 0) {
				business[i].available = true;       //The first seat is always available
			}
			else if (i == 1) {
				business[i].available = false;      //The Next seat is not available
			}

			if (i >= 2) {
				if (i % 2 == 0) {
					business[i].available = true;
				}

				else {
					business[i].available = false;
				}
			}
			business[i].ID = id;
			id++;
		}
	}

	void setFlights()
	{
		int indexforInter = 0;

		//Random generation of flight name
		string localflightname = "";
		string internationalflightname = "";

		int flightid;
		stringstream temp;
		string id;

		int flight1 = rand() % 1000;
		int flight2 = rand() % 1000;
		stringstream temp1;
		stringstream temp2;
		string id1;
		string id2;

		temp1 << flight1;
		temp1 >> id1;
		temp2 << flight2;
		temp2 >> id2;

		for (int i = 0; i < num_journeys; i++) {

			if (type == "Local") {
				localflightname = "L";
				flights[i].InitialiseDate();
				flights[i].setDate();
				flights[i].setLocal(i);
				check[i].arrive = flights[i].getArrivalloc();
				check[i].arrival = flights[i].getArrivaltime();
				flights[i].UpdateCOVID();

				if (i == 0) {
					localflightname = localflightname + id1;
					flights[i].setFlightname(localflightname);
					flights[i].setFlight1Depart();
					flights[i].setFlightArrival();
				}

				else if (i == 1) {
					localflightname = localflightname + id2;
					flights[i].setFlightname(localflightname);
					flights[i].setFlight2Depart();
					flights[i].setFlightArrival();
				}
			}

			else if (type == "International") {
				internationalflightname = "I";
				flights[i].UpdateCOVID();
				flights[i].InitialiseDate();
				flights[i].setDate();
				flightid = rand() % 1000;
				temp << flightid;
				temp >> id;
				internationalflightname = internationalflightname + id;
				flights[i].setFlightInternationalDepart(indexforInter);
				flights[i].setInternational(i);
				flights[i].setFlightname(internationalflightname);
				indexforInter++;
			}
		}

		/*for (int i = 0; i < num_journeys; i++) {
			for (int j = i + 1; j < num_journeys; j++) {
				if (check[i].arrive == flights[j].getArrivalloc() && check[i].depart == flights[j].getDepartloc()) {
					flights[j].setDepart(2);
				}
			}
		}*/
	}

	void DisplayEconomy()
	{
		for (int i = 0; i < 50; i++) {
			cout << economy[i].ID << endl;
		}
	}

	string getType()
	{
		return type;
	}

	int numberofJourneys()
	{
		return num_journeys;
	}

	Flight* getFlights()
	{
		return flights;
	}

	int getRegisteredSeats()
	{
		return econregisteredseats;
	}

	int* getEconseats()
	{
		return econregistered;
	}

	Economy* getEconSeats()
	{
		return economy;
	}

	Business* getBusSeats()
	{
		return business;
	}

	int* getBusseats()
	{
		return busregistered;
	}

	int getRegisteredBusSeats()
	{
		return busregisteredseats;
	}


};
