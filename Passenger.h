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

    void changeLoginData() {
        string store;
        string user;
        string pass;
        string userchange;
        string passchange;
        string CNIC;

        //Finding the number of lines in the file
        fstream file;
        file.open("Passenger.txt", ios::in);
        int numoflogins = 0;
        while (!file.eof() && !file.fail())
        {
            file >> CNIC >> user >> pass;
            numoflogins++;
        }
        file.close();

        fstream storelogindata;
        storelogindata.open("Passenger.txt", ios::in);

        cout << "Enter CNIC number to proceed to change Username or Password: ";
        cin >> CNIC;

        int i = 0;
        while (!storelogindata.eof() && !storelogindata.fail())
        {
            storelogindata >> store >> user >> pass;
            if (CNIC == store)
            {
                cout << "Type changed username: ";
                cin >> userchange;
                passenger[i].setUser(userchange);
                cout << "Enter Changed Password :";
                passenger[i].getPasswordInput();
                passenger[i].PasswordCheck();
                break;
            }
            i++;
        }
        if (i == numoflogins)
        {
            cout << "No record of CNIC found" << endl;
        }
        storelogindata.close();
        //Clearing the file
        file.open("Passenger.txt", ios::out, ios::trunc);
        file.close();
        //Storing the updated data
        file.open("Passenger.txt", ios::out, ios::app);
        int count = 0;
        while (count != (numoflogins - 1))
        {
            file << passenger[count].getCNIC();
            file << " ";
            file << passenger[count].getUsername();
            file << " ";
            file << passenger[count].getPassword();
            file << endl;
            count++;
        }
        file.close();
    }

    bool loginExistence(int numofpass) {
        string CNIC;
        string username;
        string password;

        double len;
        fstream check;
        check.open("Passenger.txt", ios::in | ios::binary);

    }
};