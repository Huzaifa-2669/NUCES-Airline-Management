#pragma once
#include "Flight.h"
#include "Plane.h"
using namespace std;

class Booking {
private:
	string flighttype;
	string flightnum;
	string departure;
	string destination;
	char* seatnum;
	string direct;
	Route routes;
	double duration;
	double cost;

public:
	Booking() {
		cost = 0;
		seatnum = new char[3];
	}
	void setflightype(string f) {
		flighttype = f;
	}
	void setflightnum(string f) {
		flightnum = f;
	}
	void setDirect(string d) {
		direct = d;
	}
	void setDeparture(string s) {
		departure = s;
	}
	void setDestination(string d) {
		destination = d;
	}
	void setSeatNumber(char* s) {
		for (int i = 0; i < 4; i++)
		{
			seatnum[i] = s[i];
		}
	}
	void setRoutes(Route r) {
		routes = r;
	}
	void setDuration(double d) {
		duration = d;
	}
	double getcost() {
		return cost;
	}

	void DisplayBooking() {

		cout << "Flight Type" << "\t" << "Flight name" << "\t" << "Departure" << "\t\t" << "Arrival" << "\t\t" << "Seat Number" << endl;
		cout << flighttype << "\t\t" << flightnum << "\t\t" << departure << "\t\t" << destination << "\t\t" << seatnum << endl;
		cout << endl;
		if (direct == "Indirect") {
			cout << "You will be travelling via: " << endl;
			for (int i = 0; i < routes.stops; i++) {
				cout << routes.route[i] << "  ";
			}

			cout << endl;
			for (int i = 0; i < routes.stops; i++) {
				cost = cost + routes.totaldistance[i];
			}
			cost = cost / routes.stops;
			cost = cost / 957;
			cost = cost * 20000 * 0.9;
		}

		else {
			if (flighttype == "Inter") {
				cost = duration * 20000 * 0.9;
			}
			else {
				cost = duration * 10000 * 0.95;
			}
		}
		cout << endl;
	}

	friend ostream& operator<<(ostream& out, const Booking& b)
	{

		out << "Cost for Flight is: " << b.cost << endl;

		return out;
	}
};