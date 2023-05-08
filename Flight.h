#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Route {
    //Struct to store the route and the total distance of the route
    string* route;
    double* totaldistance;
    int stops;

    void setRoute(int n) {
        stops = n;
        route = new string[n];
        totaldistance = new double[n];
    }
};

class Flight {
private:
    string date;
    int day;
    int month;
    bool covid;
    int ID;
    string flightname;
    double Depart;
    double Arrival;
    string departloc;
    string arrivalloc;
    double duration;
    string arrivalairport;
    string* international;
    int* internationaltimes;
    Route* route;
    string indirect;
    Route singleroute;

public:

    Flight()
    {
        //Constructor to initialise departure and arrival to 0 and initialise the international array and internationaltimes array
        Depart = 0;
        Arrival = 0;
        string temp[25] = { "USA", "UK", "UAE", "China", "Spain", "Italy", "Australia", "Korea", "Japan", "New Zealand", "Canada", "Brazil", "Turkey", "Hungary",
                            "Egypt", "Algeria", "South Africa", "Nigeria", "Oman", "Qatar", "Malaysia", "Russia", "Saudi Arabia", "Uzbekistan", "Azerbaijan" };


        international = new string[25];
        internationaltimes = new int[5];
        route = new Route[10];

        covid = false;

        for (int i = 0; i < 5; i++) {
            internationaltimes[i] = 0;
        }

        for (int i = 0; i < 24; i++) {
            international[i] = temp[i];
        }

        duration = 0;
    }

    void InitialiseDate() {
        //Initialises the date to 31/1
        month = 1;
        day = 31;
    }

    void UpdateCOVID()
    {
        //Randomly generates a 1 or 2, if 1 then covid is true, if 2 then covid is false
        int flip = (rand() % 2) + 1;
        if (flip == 1) {
            covid = true;
        }
        else {
            covid = false;
        }
    }

    void setDate()  //Converts the day and month into a string and stores it in date
    {
        string da = "";
        stringstream d;
        stringstream m;
        string dat;
        string mon;

        d << day;
        d >> dat;
        m << month;
        m >> mon;

        da = da + dat + "/" + mon;
        date = da;
    }

    void CalculateShortestPath(Route* r)
    {
        //Distance array of Each City from Internation coutries array
        double Islamabaddurations[25] = { 12502, 8604, 4686, 2841, 8516, 6671, 9164, 4933, 5831, 13045, 10262, 14239, 4766, 6593, 4231, 6890, 14312, 11894, 4977, 2270, 4435, 3847, 4410, 1549, 3321 };
        double Karachidurations[25] = { 12885, 8511, 4008, 3744, 8422, 6578, 9081, 5861, 6787, 13232, 10980, 13549, 4378, 6204, 3615, 6432, 13809, 11725, 4494, 1560, 4382, 4984, 3723, 2456, 3307 };
        double Lahoredurations[25] = { 12309, 9303, 4891, 2789, 9214, 7370, 8920, 4886, 5812, 13045, 10262, 14239, 4766, 6593, 4231, 6890, 14312, 12227, 5437, 2333, 4185, 4011, 4615, 1882, 4100 };
        double Peshawardurations[25] = { 11991, 8418, 4514, 2969, 8329, 6485, 9300, 5054, 5946, 13417, 9983, 13944, 4350, 6070, 3957, 6558, 14024, 11705, 4788, 2157, 4566, 3878, 4328, 1362, 3134 };
        double Quettadurations[25] = { 12313, 8192, 3780, 3504, 8103, 6260, 9406, 5590, 6513, 13559, 10390, 13547, 3938, 5765, 3538, 6256, 13520, 11436, 4312, 1620, 4668, 4454, 3504, 1774, 3000 };

        int setrandomindirects;

        //This for loop will allocate random number of stops(1-5) to the stops variable of route
        for (int i = 0; i < 10; i++) {
            r[i].setRoute(rand() % 5 + 1);
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < r[i].stops; j++) {
                setrandomindirects = (rand() % 23) + 1;
                r[i].route[j] = international[setrandomindirects];

                if (departloc == "North Islamabad" || departloc == "South Islamabad") {             //If flight took off from Islamabad Add the distance from Islamabad to the indirect country
                    r[i].totaldistance[j] = Islamabaddurations[setrandomindirects];
                }

                if (departloc == "North Peshawar" || departloc == "South Peshawar") {
                    r[i].totaldistance[j] = Peshawardurations[setrandomindirects];
                }

                if (departloc == "North Quetta" || departloc == "South Quetta") {
                    r[i].totaldistance[j] = Quettadurations[setrandomindirects];
                }

                if (departloc == "North Karachi" || departloc == "South Karachi") {
                    r[i].totaldistance[j] = Karachidurations[setrandomindirects];
                }

                if (departloc == "North Lahore" || departloc == "South Lahore") {
                    r[i].totaldistance[j] = Lahoredurations[setrandomindirects];
                }

                while (r[i].route[j] == arrivalloc) {
                    setrandomindirects = (rand() % 23) + 1;
                    r[i].route[j] = international[setrandomindirects];

                    if (departloc == "North Islamabad" || departloc == "South Islamabad") {
                        r[i].totaldistance[j] = Islamabaddurations[setrandomindirects];
                    }

                    if (departloc == "North Peshawar" || departloc == "South Peshawar") {
                        r[i].totaldistance[j] = Peshawardurations[setrandomindirects];
                    }

                    if (departloc == "North Quetta" || departloc == "South Quetta") {
                        r[i].totaldistance[j] = Quettadurations[setrandomindirects];
                    }

                    if (departloc == "North Karachi" || departloc == "South Karachi") {
                        r[i].totaldistance[j] = Karachidurations[setrandomindirects];
                    }

                    if (departloc == "North Lahore" || departloc == "South Lahore") {
                        r[i].totaldistance[j] = Lahoredurations[setrandomindirects];
                    }

                }
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < r[i].stops; j++) {
                for (int k = j + 1; k < r[i].stops; k++) {
                    if (r[i].route[j] == r[i].route[k]) {
                        r[i].route[j] = "";
                    }
                }
            }
        }

        int oneroute = (rand() % 10) + 1;

        singleroute = r[oneroute - 1];
    }

    void setDuration(double num)
    {
        duration = duration + num;
    }

    void setLocalFlight(double n)
    {
        Depart = n;
    }

    void setInterFlight(double n)
    {
        Depart = n;
    }

    void setFlight1Depart()
    {
        int first = (rand() % 12) + 1;
        Depart = first;
    }

    void setFlight2Depart()
    {
        int second = (rand() % 11) + 13;
        Depart = second;
    }

    void setFlightInternationalDepart(int n)
    {
        int hour = 0;

        for (int i = 0; i < 5; i++) {
            hour = (rand() % 23) + 1;
            internationaltimes[i] = hour;

            //Conditions to ensure that the international flights do not have the same departure time
            if (i == 1) {
                while (internationaltimes[i] == internationaltimes[0]) {
                    internationaltimes[i] = (rand() % 23) + 1;
                }
            }

            if (i == 2) {
                while (internationaltimes[i] == internationaltimes[0] || internationaltimes[i] == internationaltimes[1]) {
                    internationaltimes[i] = (rand() % 23) + 1;
                }
            }

            if (i == 3) {
                while (internationaltimes[i] == internationaltimes[0] || internationaltimes[i] == internationaltimes[1] || internationaltimes[i] == internationaltimes[2]) {
                    internationaltimes[i] = (rand() % 23) + 1;
                }
            }

            if (i == 4) {
                while (internationaltimes[i] == internationaltimes[0] || internationaltimes[i] == internationaltimes[1] || internationaltimes[i] == internationaltimes[2] || internationaltimes[i] == internationaltimes[3]) {
                    internationaltimes[i] = (rand() % 23) + 1;
                }
            }
        }

        Depart = internationaltimes[n];

    }

    void setFlightArrival()
    {
        Arrival = Depart + duration;

        int integerpart = 0;
        double decimalpart = 0;
        integerpart = Arrival;
        decimalpart = Arrival - integerpart;
        Arrival = Arrival - decimalpart;

        while (Arrival > 24) {
            Arrival = Arrival - 24;
            day++;
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                if (day > 31) {
                    month++;
                    day = 1;
                }
            }

            else if (month == 2) {
                if (day > 28) {
                    month++;
                    day = 1;
                }
            }

            else {
                if (day > 30) {
                    month++;
                    day = 1;
                }
            }
        }

        if (decimalpart >= 0.6) {
            Arrival++;
            decimalpart = decimalpart - 0.6;
            Arrival = Arrival + decimalpart;
        }

    }

    void setLocal(int count)
    {
        int city = (rand() % 20) + 1;
        int airport = (rand() % 2) + 1;

        indirect = "Direct";

        if (departloc == "North Islamabad" || departloc == "South Islamabad") {
            while (city == 5 || city == 9 || city == 15 || city == 17) {
                city = (rand() % 20) + 1;
            }
        }

        if (departloc == "North Peshawar" || departloc == "South Peshawar") {
            while (city == 1 || city == 12 || city == 13 || city == 20) {
                city = (rand() % 20) + 1;
            }
        }

        if (departloc == "North Quetta" || departloc == "South Quetta") {
            while (city == 2 || city == 6 || city == 16 || city == 19) {
                city = (rand() % 20) + 1;
            }
        }

        if (departloc == "North Karachi" || departloc == "South Karachi") {
            while (city == 3 || city == 7 || city == 11 || city == 14) {
                city = (rand() % 20) + 1;
            }
        }

        if (departloc == "North Lahore" || departloc == "South Lahore") {
            while (city == 4 || city == 8 || city == 10 || city == 18) {
                city = (rand() % 20) + 1;
            }
        }

        if (city == 5 || city == 9 || city == 15 || city == 17) {
            if (airport == 1) {
                arrivalairport = "North";
            }
            else {
                arrivalairport = "South";
            }

            arrivalloc = "Islamabad";
        }


        if (city == 1 || city == 12 || city == 13 || city == 20) {

            if (airport == 1) {
                arrivalairport = "North";
            }
            else {
                arrivalairport = "South";
            }

            arrivalloc = "Peshawar";
        }


        if (city == 2 || city == 6 || city == 16 || city == 19) {
            if (airport == 1) {
                arrivalairport = "North";
            }
            else {
                arrivalairport = "South";
            }
            arrivalloc = "Quetta";
        }


        if (city == 3 || city == 7 || city == 11 || city == 14) {
            if (airport == 1) {
                arrivalairport = "North";
            }
            else {
                arrivalairport = "South";
            }
            arrivalloc = "Karachi";
        }

        else if (city == 4 || city == 8 || city == 10 || city == 18) {
            if (airport == 1) {
                arrivalairport = "North";
            }
            else {
                arrivalairport = "South";
            }

            arrivalloc = "Lahore";
        }



        if (departloc == "North Islamabad" || departloc == "South Islamabad") {
            if (arrivalloc == "Peshawar") {
                duration = 0.15;
            }

            if (arrivalloc == "Quetta") {
                duration = 1.02;
            }

            if (arrivalloc == "Karachi") {
                duration = 2;
            }

            if (arrivalloc == "Lahore") {
                duration = 1;
            }
        }

        if (departloc == "North Peshawar" || departloc == "South Peshawar") {
            if (arrivalloc == "Islamabad") {
                duration = 0.15;
            }

            if (arrivalloc == "Quetta") {
                duration = 0.54;
            }

            if (arrivalloc == "Karachi") {
                duration = 1.38;
            }

            if (arrivalloc == "Lahore") {
                duration = 1;
            }
        }

        if (departloc == "North Quetta" || departloc == "South Quetta") {
            if (arrivalloc == "Islamabad") {
                duration = 1.02;
            }

            if (arrivalloc == "Peshawar") {
                duration = 0.54;
            }

            if (arrivalloc == "Karachi") {
                duration = 1.15;
            }

            if (arrivalloc == "Lahore") {
                duration = 1.05;
            }
        }

        if (departloc == "North Karachi" || departloc == "South Karachi") {
            if (arrivalloc == "Islamabad") {
                duration = 2;
            }

            if (arrivalloc == "Peshawar") {
                duration = 1.38;
            }

            if (arrivalloc == "Quetta") {
                duration = 1.15;
            }

            if (arrivalloc == "Lahore") {
                duration = 1.5;
            }
        }

        if (departloc == "North Lahore" || departloc == "South Lahore") {
            if (arrivalloc == "Islamabad") {
                duration = 1;
            }

            if (arrivalloc == "Peshawar") {
                duration = 1;
            }

            if (arrivalloc == "Quetta") {
                duration = 1.05;
            }

            if (arrivalloc == "Karachi") {
                duration = 1.5;
            }
        }
    }

    void setInternational(int count)
    {

        double Islamabaddurations[25] = { 12502, 8604, 4686, 2841, 8516, 6671, 9164, 4933, 5831, 13045, 10262, 14239, 4766, 6593, 4231, 6890, 14312, 11894, 4977, 2270, 4435, 3847, 4410, 1549, 3321 };
        double Karachidurations[25] = { 12885, 8511, 4008, 3744, 8422, 6578, 9081, 5861, 6787, 13232, 10980, 13549, 4378, 6204, 3615, 6432, 13809, 11725, 4494, 1560, 4382, 4984, 3723, 2456, 3307 };
        double Lahoredurations[25] = { 12309, 9303, 4891, 2789, 9214, 7370, 8920, 4886, 5812, 13045, 10262, 14239, 4766, 6593, 4231, 6890, 14312, 12227, 5437, 2333, 4185, 4011, 4615, 1882, 4100 };
        double Peshawardurations[25] = { 11991, 8418, 4514, 2969, 8329, 6485, 9300, 5054, 5946, 13417, 9983, 13944, 4350, 6070, 3957, 6558, 14024, 11705, 4788, 2157, 4566, 3878, 4328, 1362, 3134 };
        double Quettadurations[25] = { 12313, 8192, 3780, 3504, 8103, 6260, 9406, 5590, 6513, 13559, 10390, 13547, 3938, 5765, 3538, 6256, 13520, 11436, 4312, 1620, 4668, 4454, 3504, 1774, 3000 };
        double velocity = 927;

        int intercity = (rand() % 24) + 1;
        intercity--;

        if (departloc == "North Islamabad" || departloc == "South Islamabad") {
            duration = Islamabaddurations[intercity] / velocity;
        }

        if (departloc == "North Peshawar" || departloc == "South Peshawar") {
            duration = Peshawardurations[intercity] / velocity;
        }

        if (departloc == "North Quetta" || departloc == "South Quetta") {
            duration = Quettadurations[intercity] / velocity;
        }

        if (departloc == "North Karachi" || departloc == "South Karachi") {
            duration = Karachidurations[intercity] / velocity;
        }

        if (departloc == "North Lahore" || departloc == "South Lahore") {
            duration = Lahoredurations[intercity] / velocity;
        }

        arrivalloc = international[intercity];

        int direct = (rand() % 2) + 1;

        if (direct == 1) {
            indirect = "Direct";
        }
        else {
            indirect = "Indirect";
        }

        if (indirect == "Indirect") {
            CalculateShortestPath(route);
        }

        Arrival = Depart + duration;

        int integerpart = 0;
        double decimalpart = 0;
        integerpart = Arrival;
        decimalpart = Arrival - integerpart;
        Arrival = Arrival - decimalpart;

        if (decimalpart >= 0.6) {
            Arrival++;
            decimalpart = decimalpart - 0.6;
            Arrival = Arrival + decimalpart;
        }
        if (Arrival > 24) {
            Arrival = Arrival - 24;
        }

    }

    void setFlightname(string n) {
        flightname = n;
    }

    void setID(int id) {
        ID = id;
    }

    void setDepartLoc(string c)
    {
        departloc = c;
    }

    int getID() {
        return ID;
    }

    string getDepartloc()
    {
        return departloc;
    }

    string getArrivalloc()
    {
        return arrivalloc;
    }

    string getflightname() {
        return flightname;
    }

    double getDeparttime()
    {
        return Depart;
    }

    double getArrivaltime()
    {
        return Arrival;
    }

    double getDur()
    {
        return duration;
    }

    string getAirport() {
        return arrivalairport;
    }

    string getIndirect()
    {
        return indirect;
    }

    Route* getRoutes()
    {
        return route;
    }

    int getDay()
    {
        return day;
    }

    int getmonth()
    {
        return month;
    }

    string getDate()
    {
        return date;
    }

    Route getSingleRoute()
    {
        return singleroute;
    }

    bool COVID()
    {
        return covid;
    }

};