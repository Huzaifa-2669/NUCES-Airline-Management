#include<iostream>
#include<iomanip>
#include "Plane.h"
#include"Booking.h"

using namespace std;

class Quetta
{
private:
    Planes* Local;
    Planes* International;


public:

    Quetta::Quetta()
    {

        Local = new Planes[10];
        International = new Planes[10];
    }

    void Quetta::setNorthData(Planes* p)
    {
        for (int i = 0; i < 5; i++) {
            Local[i].setEconomy();
            Local[i].setBusiness();
            Local[i].setTypeLocal();
            Local[i].setNumberofFlights();
            for (int j = 0; j < 2; j++) {
                Local[i].getFlights()[j].setDepartLoc("North Quetta");
            }
            Local[i].setFlights();
        }


        for (int i = 0; i < 5; i++) {
            International[i].setEconomy();
            International[i].setBusiness();
            International[i].setTypeInternational();
            International[i].setNumberofFlights();
            for (int j = 0; j < 1; j++) {
                International[i].getFlights()[j].setDepartLoc("North Quetta");
            }
            International[i].setFlights();
        }
    }

    void Quetta::setSouthData(Planes* p)
    {
        for (int i = 5; i < 10; i++) {
            Local[i].setEconomy();
            Local[i].setBusiness();
            Local[i].setTypeLocal();
            Local[i].setNumberofFlights();
            for (int j = 0; j < 2; j++) {
                Local[i].getFlights()[j].setDepartLoc("South Quetta");
            }
            Local[i].setFlights();
        }

        for (int i = 5; i < 10; i++) {
            International[i].setEconomy();
            International[i].setBusiness();
            International[i].setTypeInternational();
            International[i].setNumberofFlights();
            for (int j = 0; j < 1; j++) {
                International[i].getFlights()[j].setDepartLoc("South Quetta");
            }
            International[i].setFlights();
        }
    }

    void Quetta::DisplayNorthData()
    {
        Flight* dummy;
        string temp = "";

        cout << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "North Quetta Airport" << endl << endl;

        cout << "Landing Date" << "\t" << "Flight Type" << "\t" << "Flight name" << "\t" << "Departure" << "\t\t" << "Arrival" << "\t\t\t" << "Timings" << "\t\t\t                 " << "COVID Status" << endl;
        for (int i = 0; i < 5; i++) {
            dummy = Local[i].getFlights();

            cout << endl;
            for (int j = 0; j < Local[i].numberofJourneys(); j++) {

                temp = temp + dummy[j].getAirport() + " " + dummy[j].getArrivalloc();

                cout << dummy[j].getDate() << "\t\t" << Local[i].getType() << "\t\t" << dummy[j].getflightname() << "\t\t"
                    << dummy[j].getDepartloc() << "\t\t" << temp << "\t\t"
                    << fixed << setprecision(2) << "Departs: " << dummy[j].getDeparttime() << "\t" << "Arrives: " << dummy[j].getArrivaltime() << "\t\t";
                if (dummy[j].COVID() == true) {
                    cout << "Active, Flight Terminated";
                }
                else {
                    cout << "Clean, Flight Ongoing";
                }
                cout << endl;
                temp = "";
            }
        }

        cout << endl;

        string spaces;

        for (int i = 0; i < 5; i++) {
            dummy = International[i].getFlights();

            cout << endl;
            for (int j = 0; j < International[i].numberofJourneys(); j++) {
                cout << dummy[j].getDate() << "\t\t";
                cout << "Inter" << "(" << dummy[j].getIndirect() << ")" << "\t";
                cout << dummy[j].getflightname() << "\t\t";
                if (dummy[j].getArrivalloc().size() >= 8) {
                    spaces = "\t\t";
                }
                else {
                    spaces = "\t\t\t";
                }
                cout << dummy[j].getDepartloc() << "\t\t";
                cout << dummy[j].getArrivalloc() << spaces;
                cout << "Departs: " << dummy[j].getDeparttime() << "\t";
                cout << "Arrives: " << dummy[j].getArrivaltime() << "\t\t";
                if (dummy[j].COVID() == true) {
                    cout << "Active, Flight Terminated";
                }
                else {
                    cout << "Clean, Flight Ongoing";
                }
                cout << endl;
            }
        }

        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }

    void Quetta::DisplaySouthData()
    {
        Flight* dummy;
        string temp = "";

        cout << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "South Quetta Airport" << endl << endl;

        cout << "Landing Date" << "\t" << "Flight Type" << "\t" << "Flight name" << "\t" << "Departure" << "\t\t" << "Arrival" << "\t\t\t" << "Timings" << "\t\t\t                 " << "COVID Status" << endl;
        for (int i = 5; i < 10; i++) {
            dummy = Local[i].getFlights();

            cout << endl;
            for (int j = 0; j < Local[i].numberofJourneys(); j++) {

                temp = temp + dummy[j].getAirport() + " " + dummy[j].getArrivalloc();

                cout << dummy[j].getDate() << "\t\t" << Local[i].getType() << "\t\t" << dummy[j].getflightname() << "\t\t"
                    << dummy[j].getDepartloc() << "\t\t" << temp << "\t\t"
                    << fixed << setprecision(2) << "Departs: " << dummy[j].getDeparttime() << "\t" << "Arrives: " << dummy[j].getArrivaltime() << "\t\t";
                if (dummy[j].COVID() == true) {
                    cout << "Active, Flight Terminated";
                }
                else {
                    cout << "Clean, Flight Ongoing";
                }
                cout << endl;
                temp = "";
            }
        }

        cout << endl;

        string spaces;

        for (int i = 5; i < 10; i++) {
            dummy = International[i].getFlights();

            cout << endl;
            for (int j = 0; j < International[i].numberofJourneys(); j++) {
                cout << dummy[j].getDate() << "\t\t";
                cout << "Inter" << "(" << dummy[j].getIndirect() << ")" << "\t";
                cout << dummy[j].getflightname() << "\t\t";
                cout << dummy[j].getDepartloc() << "\t\t";
                if (dummy[j].getArrivalloc().size() >= 8) {
                    spaces = "\t\t";
                }
                else {
                    spaces = "\t\t\t";
                }
                cout << dummy[j].getArrivalloc() << spaces;
                cout << "Departs: " << dummy[j].getDeparttime() << "\t";
                cout << "Arrives: " << dummy[j].getArrivaltime() << "\t\t";
                if (dummy[j].COVID() == true) {
                    cout << "Active, Flight Terminated";
                }
                else {
                    cout << "Clean, Flight Ongoing";
                }
                cout << endl;
            }
        }

        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }

    void Quetta::QuettaSpecialFlight()
    {
        Flight* dummy;
        Route* rou;
        string spaces;
        string flightname;


        double mintotal = 0;
        int whichroute = 0;
        int initialise = 0;
        double total = 0;
        double velocity = 927;
        double newdur = 0;
        int count = 0;
        int route = 0;

        cout << "Type the specific Indirect Flight name to see differnet routes: ";
        cin >> flightname;

        for (int i = 0; i < 10; i++) {
            dummy = International[i].getFlights();

            for (int j = 0; j < International[i].numberofJourneys(); j++) {

                if (dummy[j].getIndirect() == "Indirect") {

                    if (flightname == dummy[j].getflightname()) {
                        cout << dummy[j].getDate() << "\t";
                        cout << "Inter" << "(" << dummy[j].getIndirect() << ")" << "\t";
                        cout << dummy[j].getflightname() << "\t\t";
                        cout << dummy[j].getDepartloc() << "\t\t";
                        if (dummy[j].getArrivalloc().size() >= 8) {
                            spaces = "\t\t";
                        }
                        else {
                            spaces = "\t\t\t";
                        }
                        cout << dummy[j].getArrivalloc() << spaces;
                        cout << fixed << setprecision(2) << "Departs: " << dummy[j].getDeparttime() << "\t";
                        cout << fixed << setprecision(2) << "Arrives: " << dummy[j].getArrivaltime();
                        cout << endl << endl;

                        rou = dummy[j].getRoutes();
                        cout << "Indirect Routes:" << endl;

                        for (int x = 0; x < 10; x++) {
                            cout << "Route " << x + 1 << endl;

                            for (int k = 0; k < rou[x].stops; k++) {
                                if (rou[x].route[k] == "") {
                                    continue;
                                }
                                cout << rou[x].route[k] << "  ";
                                total += rou[x].totaldistance[k];
                            }

                            if (initialise == 0) {
                                mintotal = total;
                            }

                            else if (mintotal > total) {
                                mintotal = total;
                                whichroute = x + 1;
                            }
                            initialise++;
                            cout << endl;
                            cout << "Total Distance: " << total << "km";
                            cout << endl;
                            cout << endl;
                            total = 0;
                        }
                        cout << endl;
                        cout << "Route " << whichroute << " has the Least Distance with: " << mintotal << endl;
                        cout << "As an Admin you are allowed to choose any route: ";
                        cin >> route;
                        cout << endl;
                        for (int x = 0; x < 10; x++) {
                            if (route = x + 1) {
                                for (int k = 0; k < rou[x].stops; k++) {
                                    if (rou[x].route[k] == "") {
                                        continue;
                                    }
                                    total += rou[x].totaldistance[k];
                                }
                                newdur = total / velocity;
                                dummy[j].setDuration(newdur);
                                dummy[j].setFlightArrival();
                                dummy[j].setDate();
                            }
                            total = 0;
                        }
                        cout << "Landing Date" << "\t" << "Flight Type" << "\t" << "Flight name" << "\t" << "Departure" << "\t\t" << "Arrival" << "\t\t\t" << "Timings" << endl;
                        cout << dummy[j].getDate() << "\t\t";
                        cout << "Inter" << "(" << dummy[j].getIndirect() << ")" << "\t";
                        cout << dummy[j].getflightname() << "\t\t";
                        cout << dummy[j].getDepartloc() << "\t\t";
                        if (dummy[j].getArrivalloc().size() >= 8) {
                            spaces = "\t\t";
                        }
                        else {
                            spaces = "\t\t\t";
                        }
                        cout << dummy[j].getArrivalloc() << spaces;
                        cout << fixed << setprecision(2) << "Departs: " << dummy[j].getDeparttime() << "\t";
                        cout << fixed << setprecision(2) << "Arrives: " << dummy[j].getArrivaltime();
                        cout << endl << endl;

                        initialise = 0;
                        mintotal = 0;
                    }
                }

            }
        }


    }

    void Quetta::PassengerSF() {

        Flight* dummy;
        Route* rou;
        string spaces;
        string flightname;


        double mintotal = 0;
        int whichroute = 0;
        int initialise = 0;
        double total = 0;
        double velocity = 927;
        double newdur = 0;
        int count = 0;
        int route = 0;

        cout << "Type the specific Indirect Flight name to see differnet routes: ";
        cin >> flightname;

        for (int i = 0; i < 10; i++) {
            dummy = International[i].getFlights();

            for (int j = 0; j < International[i].numberofJourneys(); j++) {

                if (dummy[j].getIndirect() == "Indirect") {

                    if (flightname == dummy[j].getflightname()) {
                        cout << dummy[j].getDate() << "\t";
                        cout << "Inter" << "(" << dummy[j].getIndirect() << ")" << "\t";
                        cout << dummy[j].getflightname() << "\t\t";
                        cout << dummy[j].getDepartloc() << "\t\t";
                        if (dummy[j].getArrivalloc().size() >= 8) {
                            spaces = "\t\t";
                        }
                        else {
                            spaces = "\t\t\t";
                        }
                        cout << dummy[j].getArrivalloc() << spaces;
                        cout << fixed << setprecision(2) << "Departs: " << dummy[j].getDeparttime() << "\t";
                        cout << fixed << setprecision(2) << "Arrives: " << dummy[j].getArrivaltime();
                        cout << endl << endl;

                        rou = dummy[j].getRoutes();
                        cout << "Indirect Routes:" << endl;

                        for (int x = 0; x < 10; x++) {
                            cout << "Route " << x + 1 << endl;

                            for (int k = 0; k < rou[x].stops; k++) {
                                if (rou[x].route[k] == "") {
                                    continue;
                                }
                                cout << rou[x].route[k] << "  ";
                                total += rou[x].totaldistance[k];
                            }
                            total = total / rou[x].stops;
                            if (initialise == 0) {
                                mintotal = total;
                            }

                            else if (mintotal > total) {
                                mintotal = total;
                                whichroute = x + 1;
                            }
                            initialise++;
                            cout << endl;
                            cout << "Total Distance: " << total << "km";
                            cout << endl;
                            cout << endl;
                            total = 0;
                        }
                        cout << endl;
                        cout << "The route to your destination will be the following" << endl;
                        cout << "Route " << whichroute << " has the Least Distance with: " << mintotal << endl;
                        route = whichroute;

                        cout << endl;
                        for (int x = 0; x < 10; x++) {
                            if (route = x + 1) {
                                for (int k = 0; k < rou[x].stops; k++) {
                                    if (rou[x].route[k] == "") {
                                        continue;
                                    }
                                    total += rou[x].totaldistance[k];
                                }
                                newdur = total / velocity;
                                dummy[j].setDuration(newdur);
                                dummy[j].setFlightArrival();
                                dummy[j].setDate();
                            }
                            total = 0;
                        }
                        cout << "Landing Date" << "\t" << "Flight Type" << "\t" << "Flight name" << "\t" << "Departure" << "\t\t" << "Arrival" << "\t\t\t" << "Timings" << endl;
                        cout << dummy[j].getDate() << "\t\t";
                        cout << "Inter" << "(" << dummy[j].getIndirect() << ")" << "\t";
                        cout << dummy[j].getflightname() << "\t\t";
                        cout << dummy[j].getDepartloc() << "\t\t";
                        if (dummy[j].getArrivalloc().size() >= 8) {
                            spaces = "\t\t";
                        }
                        else {
                            spaces = "\t\t\t";
                        }
                        cout << dummy[j].getArrivalloc() << spaces;
                        cout << fixed << setprecision(2) << "Departs: " << dummy[j].getDeparttime() << "\t";
                        cout << fixed << setprecision(2) << "Arrives: " << dummy[j].getArrivaltime();
                        cout << endl << endl;

                        initialise = 0;
                        mintotal = 0;
                    }
                }

            }
        }



    }

    void Quetta::ChangeDepartTimes() {

        string flightname;
        Flight* dummy;

        Economy* e = NULL;
        int* economys = NULL;
        int size = 0;

        Business* b = NULL;
        int* buisnessS = NULL;
        int size1 = 0;

        double dur = 0;

        cout << endl;
        cout << "Type the specific Flight name : ";
        cin >> flightname;

        double depart = 0;
        cout << "Change Departure Time: ";
        cin >> depart;

        int index = 0;
        int local = 0;
        int busi = 0;
        int x = 0;
        for (int i = 0; i < 10; i++) {


            dummy = Local[i].getFlights();

            for (int j = 0; j < Local[i].numberofJourneys(); j++) {

                if (flightname == dummy[j].getflightname()) {
                    dummy[j].setLocalFlight(depart);
                    dummy[j].setFlightArrival();
                    break;
                }
            }




            dummy = International[i].getFlights();

            for (int j = 0; j < International[i].numberofJourneys(); j++) {

                if (flightname == dummy[j].getflightname()) {
                    dummy[j].setInterFlight(depart);
                    dummy[j].setFlightArrival();
                    index = i;
                    busi++;
                    break;
                }
            }


            if (local > 0) {
                break;
            }

            else if (busi > 0) {
                break;
            }

        }


    }

    void Quetta::RestrictSeats()
    {

        string flightname;
        Flight* dummy;

        Economy* e = NULL;
        int* economys = NULL;
        int size;

        Business* b = NULL;
        int* buisnessS = NULL;
        int size1;

        double dur = 0;

        cout << endl;
        cout << "Type the specific Flight name : ";
        cin >> flightname;

        int index = 0;
        int local = 0;
        int busi = 0;
        int x = 0;
        for (int i = 0; i < 10; i++) {


            dummy = Local[i].getFlights();

            for (int j = 0; j < Local[i].numberofJourneys(); j++) {

                if (flightname == dummy[j].getflightname()) {
                    index = i;
                    local++;
                    break;
                }
            }




            dummy = International[i].getFlights();

            for (int j = 0; j < International[i].numberofJourneys(); j++) {

                if (flightname == dummy[j].getflightname()) {
                    index = i;
                    busi++;
                    break;
                }
            }


            if (local > 0) {
                break;
            }

            else if (busi > 0) {
                break;
            }

        }

        cout << endl << endl;

        int restriction = 0;
        cout << "As Admin How Many Seat would you like to restrict: ";
        cin >> restriction;
        while (restriction < 0 || restriction > 7) {
            cout << "Sorry, That isn't possible or else you are sending an empty plane" << endl;
            cout << "Type seat Restriction again: ";
            cin >> restriction;
        }

        e = International[index].getEconSeats();
        economys = International[index].getEconseats();
        size = International[index].getRegisteredSeats();
        economys = new int[size];

        b = International[index].getBusSeats();
        buisnessS = International[index].getBusseats();
        size1 = International[index].getRegisteredBusSeats();
        buisnessS = new int[size1];


        int check = 0;
        for (int i = 0; i < size; i++) {
            economys[i] = (rand() % 25) + 1;
            for (int j = 0; j < check; j++) {
                while (economys[i] == economys[j] || economys[i] % 2 == 0) {
                    economys[i] = (rand() % 25) + 1;
                }
            }
            check++;
        }


        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < size; j++) {
                if (e[i].ID == economys[j]) {
                    e[i].available = false;
                }
            }
        }

        for (int i = 0; i < 50; i++) {
            if (restriction == 0) {
                break;
            }
            if (e[i].available == true) {
                e[i].available = false;
                restriction--;
            }
        }

        check = 0;
        for (int i = 0; i < size1; i++) {
            buisnessS[i] = (rand() % 25) + 1;
            for (int j = 0; j < check; j++) {
                while (buisnessS[i] == buisnessS[j] || buisnessS[i] % 2 == 0) {
                    buisnessS[i] = (rand() % 25) + 1;
                }
            }
            check++;
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < size1; j++) {
                if (b[i].ID == buisnessS[j]) {
                    b[i].available = false;
                }
            }
        }



        cout << endl;
        cout << "--------------------------" << endl;
        int arr[10] = { 4,9,14,19,24,29,34,39,44,49 };
        int count = 0;
        int output = 0;
        int a = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {


                if (count == 1) {
                    cout << endl;
                    cout << "|";
                    cout << "     ";
                    if (e[output].available == true) {
                        if (e[output].ID < 10) {
                            cout << "E" << "0" << e[output].ID << "  ";
                        }
                        else {
                            cout << "E" << e[output].ID << "  ";
                        }
                    }
                    else {
                        cout << " X " << "  ";
                    }
                    output++;
                    count++;

                }

                else if (count == 2 || count == 3) {
                    cout << " ";
                    if (e[output].available == true) {
                        if (e[output].ID < 10) {
                            cout << "E" << "0" << e[output].ID << "  ";
                        }
                        else {
                            cout << "E" << e[output].ID << "  ";
                        }

                    }
                    else {
                        cout << " X " << "  ";
                    }

                    if (count == 3) {
                        cout << "   |";
                    }
                    count++;
                    output++;
                }

                else if (count == 4) {
                    cout << "                ";
                    if (e[output].available == true) {
                        if (e[output].ID < 10) {
                            cout << "E" << "0" << e[output].ID;
                        }
                        else {
                            cout << "E" << e[output].ID;
                        }
                    }
                    else {
                        cout << " X ";
                    }
                    cout << "|";
                    count = 1;
                    output = output - 3;
                }

                else if (count == 0) {
                    cout << "| ";
                    if (e[output].available == true) {
                        if (e[output].ID < 10) {
                            cout << "E" << "0" << e[output].ID << "  ";
                        }
                        else {
                            cout << "E" << e[output].ID << "  ";
                        }

                    }
                    else {
                        cout << " X " << "  ";
                    }
                    output = arr[a];
                    count = 4;
                }

            }
            cout << endl;
            cout << "--------------------------" << endl;
            count = 0;
            output++;
            a++;
        }

        cout << endl;
        cout << "--------------------------" << endl;

        count = 0;
        output = 0;
        a = 0;
        int arr1[2] = { 4,9 };

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 5; j++) {


                if (count == 1) {
                    cout << endl;
                    cout << "|";
                    cout << "     ";
                    if (b[output].available == true) {
                        if (b[output].ID < 10) {
                            cout << "I" << "0" << b[output].ID << "  ";
                        }
                        else {
                            cout << "I" << b[output].ID << "  ";
                        }
                    }
                    else {
                        cout << " X " << "  ";
                    }
                    output++;
                    count++;

                }

                else if (count == 2 || count == 3) {
                    cout << " ";
                    if (b[output].available == true) {
                        if (b[output].ID < 10) {
                            cout << "I" << "0" << b[output].ID << "  ";
                        }
                        else {
                            cout << "I" << b[output].ID << "  ";
                        }

                    }
                    else {
                        cout << " X " << "  ";
                    }

                    if (count == 3) {
                        cout << "   |";
                    }
                    count++;
                    output++;
                }

                else if (count == 4) {
                    cout << "                ";
                    if (b[output].available == true) {
                        if (b[output].ID < 10) {
                            cout << "I" << "0" << b[output].ID;
                        }
                        else {
                            cout << "I" << b[output].ID;
                        }
                    }
                    else {
                        cout << " X ";
                    }
                    cout << "|";
                    count = 1;
                    output = output - 3;
                }

                else if (count == 0) {
                    cout << "| ";
                    if (b[output].available == true) {
                        if (b[output].ID < 10) {
                            cout << "I" << "0" << b[output].ID << "  ";
                        }
                        else {
                            cout << "I" << b[output].ID << "  ";
                        }

                    }
                    else {
                        cout << " X " << "  ";
                    }
                    output = arr1[a];
                    count = 4;
                }

            }
            cout << endl;
            if (i == 1) {
                cout << "--------------------------" << endl;
                cout << "   --------------------   " << endl;
                cout << "      --------------      " << endl;
                cout << "         --------         " << endl;
                cout << "            --            " << endl;
            }
            else {
                cout << "--------------------------" << endl;
            }

            count = 0;
            output++;
            a++;
        }

        cout << endl;

    }

    void Quetta::RegisteredSeats(Booking& book)
    {

        string flightname;
        Flight* dummy;

        Economy* e = NULL;
        int* economys = NULL;
        int size;

        Business* b = NULL;
        int* buisnessS = NULL;
        int size1;

        double dur = 0;

        cout << endl;
        cout << "Type the specific Flight name : ";
        cin >> flightname;

        int index = 0;
        int local = 0;
        int busi = 0;
        int x = 0;
        for (int i = 0; i < 10; i++) {


            dummy = Local[i].getFlights();

            for (int j = 0; j < Local[i].numberofJourneys(); j++) {

                if (flightname == dummy[j].getflightname()) {
                    dur = dummy[j].getArrivaltime() - dummy[j].getDeparttime();
                    if (dur < 0) {
                        dur = dur * -1;
                    }
                    if (dummy[j].getIndirect() == "Direct") {
                        book.setDuration(dur);
                    }
                    book.setDeparture(dummy[j].getDepartloc());
                    book.setDestination(dummy[j].getArrivalloc());
                    book.setflightnum(dummy[j].getflightname());
                    book.setflightype("Inter");
                    book.setDirect(dummy[j].getIndirect());
                    if (dummy[j].getIndirect() == "Indirect") {
                        book.setRoutes(dummy[j].getSingleRoute());
                    }
                    index = i;
                    local++;
                    break;
                }
            }




            dummy = International[i].getFlights();

            for (int j = 0; j < International[i].numberofJourneys(); j++) {

                if (flightname == dummy[j].getflightname()) {
                    dur = dummy[j].getArrivaltime() - dummy[j].getDeparttime();
                    if (dur < 0) {
                        dur = dur * -1;
                    }
                    if (dummy[j].getIndirect() == "Direct") {
                        book.setDuration(dur);
                    }

                    book.setDeparture(dummy[j].getDepartloc());
                    book.setDestination(dummy[j].getArrivalloc());
                    book.setflightnum(dummy[j].getflightname());
                    book.setflightype("Inter");
                    book.setDirect(dummy[j].getIndirect());
                    if (dummy[j].getIndirect() == "Indirect") {
                        book.setRoutes(dummy[j].getSingleRoute());
                    }

                    index = i;
                    busi++;
                    break;
                }
            }


            if (local > 0) {
                break;
            }

            else if (busi > 0) {
                break;
            }

        }

        cout << endl << endl;

        e = International[index].getEconSeats();
        economys = International[index].getEconseats();
        size = International[index].getRegisteredSeats();
        economys = new int[size];

        b = International[index].getBusSeats();
        buisnessS = International[index].getBusseats();
        size1 = International[index].getRegisteredBusSeats();
        buisnessS = new int[size1];


        int check = 0;
        for (int i = 0; i < size; i++) {
            economys[i] = (rand() % 25) + 1;
            for (int j = 0; j < check; j++) {
                while (economys[i] == economys[j] || economys[i] % 2 == 0) {
                    economys[i] = (rand() % 25) + 1;
                }
            }
            check++;
        }


        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < size; j++) {
                if (e[i].ID == economys[j]) {
                    e[i].available = false;
                }
            }
        }

        check = 0;
        for (int i = 0; i < size1; i++) {
            buisnessS[i] = (rand() % 25) + 1;
            for (int j = 0; j < check; j++) {
                while (buisnessS[i] == buisnessS[j] || buisnessS[i] % 2 == 0) {
                    buisnessS[i] = (rand() % 25) + 1;
                }
            }
            check++;
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < size1; j++) {
                if (b[i].ID == buisnessS[j]) {
                    b[i].available = false;
                }
            }
        }



        cout << endl;
        cout << "--------------------------" << endl;
        int arr[10] = { 4,9,14,19,24,29,34,39,44,49 };
        int count = 0;
        int output = 0;
        int a = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {


                if (count == 1) {
                    cout << endl;
                    cout << "|";
                    cout << "     ";
                    if (e[output].available == true) {
                        if (e[output].ID < 10) {
                            cout << "E" << "0" << e[output].ID << "  ";
                        }
                        else {
                            cout << "E" << e[output].ID << "  ";
                        }
                    }
                    else {
                        cout << " X " << "  ";
                    }
                    output++;
                    count++;

                }

                else if (count == 2 || count == 3) {
                    cout << " ";
                    if (e[output].available == true) {
                        if (e[output].ID < 10) {
                            cout << "E" << "0" << e[output].ID << "  ";
                        }
                        else {
                            cout << "E" << e[output].ID << "  ";
                        }

                    }
                    else {
                        cout << " X " << "  ";
                    }

                    if (count == 3) {
                        cout << "   |";
                    }
                    count++;
                    output++;
                }

                else if (count == 4) {
                    cout << "                ";
                    if (e[output].available == true) {
                        if (e[output].ID < 10) {
                            cout << "E" << "0" << e[output].ID;
                        }
                        else {
                            cout << "E" << e[output].ID;
                        }
                    }
                    else {
                        cout << " X ";
                    }
                    cout << "|";
                    count = 1;
                    output = output - 3;
                }

                else if (count == 0) {
                    cout << "| ";
                    if (e[output].available == true) {
                        if (e[output].ID < 10) {
                            cout << "E" << "0" << e[output].ID << "  ";
                        }
                        else {
                            cout << "E" << e[output].ID << "  ";
                        }

                    }
                    else {
                        cout << " X " << "  ";
                    }
                    output = arr[a];
                    count = 4;
                }

            }
            cout << endl;
            cout << "--------------------------" << endl;
            count = 0;
            output++;
            a++;
        }

        cout << endl;
        cout << "--------------------------" << endl;

        count = 0;
        output = 0;
        a = 0;
        int arr1[2] = { 4,9 };

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 5; j++) {


                if (count == 1) {
                    cout << endl;
                    cout << "|";
                    cout << "     ";
                    if (b[output].available == true) {
                        if (b[output].ID < 10) {
                            cout << "I" << "0" << b[output].ID << "  ";
                        }
                        else {
                            cout << "I" << b[output].ID << "  ";
                        }
                    }
                    else {
                        cout << " X " << "  ";
                    }
                    output++;
                    count++;

                }

                else if (count == 2 || count == 3) {
                    cout << " ";
                    if (b[output].available == true) {
                        if (b[output].ID < 10) {
                            cout << "I" << "0" << b[output].ID << "  ";
                        }
                        else {
                            cout << "I" << b[output].ID << "  ";
                        }

                    }
                    else {
                        cout << " X " << "  ";
                    }

                    if (count == 3) {
                        cout << "   |";
                    }
                    count++;
                    output++;
                }

                else if (count == 4) {
                    cout << "                ";
                    if (b[output].available == true) {
                        if (b[output].ID < 10) {
                            cout << "I" << "0" << b[output].ID;
                        }
                        else {
                            cout << "I" << b[output].ID;
                        }
                    }
                    else {
                        cout << " X ";
                    }
                    cout << "|";
                    count = 1;
                    output = output - 3;
                }

                else if (count == 0) {
                    cout << "| ";
                    if (b[output].available == true) {
                        if (b[output].ID < 10) {
                            cout << "I" << "0" << b[output].ID << "  ";
                        }
                        else {
                            cout << "I" << b[output].ID << "  ";
                        }

                    }
                    else {
                        cout << " X " << "  ";
                    }
                    output = arr1[a];
                    count = 4;
                }

            }
            cout << endl;
            if (i == 1) {
                cout << "--------------------------" << endl;
                cout << "   --------------------   " << endl;
                cout << "      --------------      " << endl;
                cout << "         --------         " << endl;
                cout << "            --            " << endl;
            }
            else {
                cout << "--------------------------" << endl;
            }

            count = 0;
            output++;
            a++;
        }

        cout << endl;

        char* seat;
        string store = "";
        seat = new char[3];
        cin.ignore(10000, '\n');
        cout << "Type the Available seat you would like: ";
        cin.get(seat, 4);

        book.setSeatNumber(seat);
        if (seat[1] != 0) {
            store = store + seat[1] + seat[2];
        }
        else {
            store = store + seat[2];
        }

        int id = 0;
        stringstream convert(store);
        convert >> id;

        for (int i = 0; i < 50; i++) {
            if (e[i].ID == id) {
                e[i].available = false;
            }
        }

        check = 0;
        for (int i = 0; i < size; i++) {
            economys[i] = (rand() % 25) + 1;
            for (int j = 0; j < check; j++) {
                while (economys[i] == economys[j] || economys[i] % 2 == 0) {
                    economys[i] = (rand() % 25) + 1;
                }
            }
            check++;
        }


        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < size; j++) {
                if (e[i].ID == economys[j]) {
                    e[i].available = false;
                }
            }
        }

        check = 0;
        for (int i = 0; i < size1; i++) {
            buisnessS[i] = (rand() % 25) + 1;
            for (int j = 0; j < check; j++) {
                while (buisnessS[i] == buisnessS[j] || buisnessS[i] % 2 == 0) {
                    buisnessS[i] = (rand() % 25) + 1;
                }
            }
            check++;
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < size1; j++) {
                if (b[i].ID == buisnessS[j]) {
                    b[i].available = false;
                }
            }
        }



        cout << endl;
        cout << "--------------------------" << endl;
        count = 0;
        output = 0;
        a = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {


                if (count == 1) {
                    cout << endl;
                    cout << "|";
                    cout << "     ";
                    if (e[output].available == true) {
                        if (e[output].ID < 10) {
                            cout << "E" << "0" << e[output].ID << "  ";
                        }
                        else {
                            cout << "E" << e[output].ID << "  ";
                        }
                    }
                    else {
                        cout << " X " << "  ";
                    }
                    output++;
                    count++;

                }

                else if (count == 2 || count == 3) {
                    cout << " ";
                    if (e[output].available == true) {
                        if (e[output].ID < 10) {
                            cout << "E" << "0" << e[output].ID << "  ";
                        }
                        else {
                            cout << "E" << e[output].ID << "  ";
                        }

                    }
                    else {
                        cout << " X " << "  ";
                    }

                    if (count == 3) {
                        cout << "   |";
                    }
                    count++;
                    output++;
                }

                else if (count == 4) {
                    cout << "                ";
                    if (e[output].available == true) {
                        if (e[output].ID < 10) {
                            cout << "E" << "0" << e[output].ID;
                        }
                        else {
                            cout << "E" << e[output].ID;
                        }
                    }
                    else {
                        cout << " X ";
                    }
                    cout << "|";
                    count = 1;
                    output = output - 3;
                }

                else if (count == 0) {
                    cout << "| ";
                    if (e[output].available == true) {
                        if (e[output].ID < 10) {
                            cout << "E" << "0" << e[output].ID << "  ";
                        }
                        else {
                            cout << "E" << e[output].ID << "  ";
                        }

                    }
                    else {
                        cout << " X " << "  ";
                    }
                    output = arr[a];
                    count = 4;
                }

            }
            cout << endl;
            cout << "--------------------------" << endl;
            count = 0;
            output++;
            a++;
        }

        cout << endl;
        cout << "--------------------------" << endl;

        count = 0;
        output = 0;
        a = 0;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 5; j++) {


                if (count == 1) {
                    cout << endl;
                    cout << "|";
                    cout << "     ";
                    if (b[output].available == true) {
                        if (b[output].ID < 10) {
                            cout << "I" << "0" << b[output].ID << "  ";
                        }
                        else {
                            cout << "I" << b[output].ID << "  ";
                        }
                    }
                    else {
                        cout << " X " << "  ";
                    }
                    output++;
                    count++;

                }

                else if (count == 2 || count == 3) {
                    cout << " ";
                    if (b[output].available == true) {
                        if (b[output].ID < 10) {
                            cout << "I" << "0" << b[output].ID << "  ";
                        }
                        else {
                            cout << "I" << b[output].ID << "  ";
                        }

                    }
                    else {
                        cout << " X " << "  ";
                    }

                    if (count == 3) {
                        cout << "   |";
                    }
                    count++;
                    output++;
                }

                else if (count == 4) {
                    cout << "                ";
                    if (b[output].available == true) {
                        if (b[output].ID < 10) {
                            cout << "I" << "0" << b[output].ID;
                        }
                        else {
                            cout << "I" << b[output].ID;
                        }
                    }
                    else {
                        cout << " X ";
                    }
                    cout << "|";
                    count = 1;
                    output = output - 3;
                }

                else if (count == 0) {
                    cout << "| ";
                    if (b[output].available == true) {
                        if (b[output].ID < 10) {
                            cout << "I" << "0" << b[output].ID << "  ";
                        }
                        else {
                            cout << "I" << b[output].ID << "  ";
                        }

                    }
                    else {
                        cout << " X " << "  ";
                    }
                    output = arr1[a];
                    count = 4;
                }

            }
            cout << endl;
            if (i == 1) {
                cout << "--------------------------" << endl;
                cout << "   --------------------   " << endl;
                cout << "      --------------      " << endl;
                cout << "         --------         " << endl;
                cout << "            --            " << endl;
            }
            else {
                cout << "--------------------------" << endl;
            }

            count = 0;
            output++;
            a++;
        }

        cout << endl;

    }
};