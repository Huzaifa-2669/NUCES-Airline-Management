#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include "Account.h"
#include "Booking.h"

class Passenger {
private:
    Account* passenger;
    string seatnumber;
    Booking book;
    double bankamount;

public:
    Passenger(Account* p) {
        string CNIC;
        string username;
        string password;
        passenger = p;
        //Finding the number of lines in the file
        fstream file;
        file.open("Passenger.txt", ios::in);
        int numberoflogins = 0;
        while (!file.eof() && !file.fail())
        {
            file >> CNIC >> username >> password;
            numberoflogins++;
        }
        file.close();
        int i = 0;
        file.open("Passenger.txt", ios::in);
        while (!file.eof() && !file.fail())
        {
            file >> CNIC >> username >> password;
            passenger[i].setCNIC(CNIC);
            passenger[i].setUser(username);
            passenger[i].setPass(password);
            i++;
            if (i == numberoflogins - 1)
            {
                break;
            }
        }
    }
    void setBankAmount(double b) {
        bankamount = b;
    }

    void Signup(int& numofpass, char update) {
        string CNIC;
        int age = 0;
        int count = 0;
        cout << "Enter your Age :";
        cin >> age;
        while (age <= 0)
        {
            cout << "Invalid Age, Please Enter a valid age: ";
            cin >> age;
        }
        if (age < 18)
        {
            cout << "Please Enter your Guardians CNIC :";
        }
        else
        {
            cout << "Enter Your CINC :";
        }
        cin >> CNIC;
        while (CNIC.length() < 13 || CNIC.length() > 13)
        {
            cout << "Invalid CNIC, Please enter valid CNIC :";
            cin >> CNIC;
        }
        //Validation to Check for existing CNIC
        for (int i = 0; i < numofpass; i++)
        {
            if (passenger[i].getCNIC() == CNIC)
            {
                count++;
            }
        }
        while (count > 0)
        {
            count = 0;
            cout << "CNIC already exists, Please enter another CNIC :";
            cin >> CNIC;
            for (int i = 0; i < numofpass; i++)
            {
                if (passenger[i].getCNIC() == CNIC)
                {
                    count++;
                }
            }
        }

        passenger[numofpass].Registration(CNIC);
        if (update == 'y')
        {
            passenger[numofpass].StoreLogin();
        }
        cout << endl;
    }

};