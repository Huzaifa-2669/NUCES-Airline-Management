#include<iostream>
#include<string>
#include<fstream>
#include "Account.h"

using namespace std;

class Admin {
private:
    Account* admin;
public:
    Admin(Account* a) {
        admin = a;

        string CNIC;
        string username;
        string password;
        //find out number of lines inside file
        fstream file;
        file.open("Admin.txt", ios::in);
        int numoflogins = 0;
        while ((!file.eof()) && (!file.fail())) {
            file >> CNIC >> username >> password;
            numoflogins++;
        }
        file.close();

        int i = 0;
        ifstream retain;
        retain.open("Admin.txt");
        while ((!retain.eof()) && (!retain.fail())) {
            retain >> CNIC >> username >> password;
            admin[i].setCNIC(CNIC);
            admin[i].setUser(username);
            admin[i].setPass(password);
            i++;

            if (i == numoflogins - 1) {
                break;
            }
        }
    }

    void changeLoginData() {
        string store;
        string user;
        string pass;
        string userchange;
        string passchange;
        string CNIC;

        //find out number of lines inside file
        ifstream line;
        line.open("Admin.txt");
        int numoflogins = 0;
        while ((!line.eof()) && (!line.fail())) {
            line >> store >> user >> pass;
            numoflogins++;
        }
        line.close();

        //finding the line CNIC located in
        ifstream storelogindata;
        storelogindata.open("Admin.txt");

        cout << "Type CNIC number to proceed to change username or password: ";
        cin >> CNIC;

        int i = 0;
        while ((!storelogindata.eof()) && (!storelogindata.fail())) {

            storelogindata >> store >> user >> pass;

            if (CNIC == store) {
                cout << "Type changed username: ";
                cin >> userchange;
                admin[i].resetUsername(userchange);
                cout << "Type changed password: ";
                cin >> passchange;
                admin[i].resetPassword(passchange);
                break;
            }
            i++;
        }

        if (i == numoflogins) {
            cout << "No Record of CNIC" << endl;
        }

        //clearing old data
        ofstream clear;
        clear.open("Admin.txt", ofstream::out | ofstream::trunc);
        clear.close();

        //re-writing all the login details along with changed username and password
        ofstream changelogin;
        changelogin.open("Admin.txt", ios::app);
        int count = 0;
        while (count != (numoflogins - 1)) {

            changelogin << admin[count].getCNIC();
            changelogin << " ";
            changelogin << admin[count].getUsername();
            changelogin << " ";
            changelogin << admin[count].getPassword();
            changelogin << "\n";
            count++;

        }
        changelogin.close();

    }

    bool loginExistence(int numofpass) {

        string CNIC;
        string username;
        string password;

        int len;
        ifstream check;
        check.open("Admin.txt", ios::binary); // open your file
        check.seekg(0, ios::end); // put the "cursor" at the end of the file
        len = check.tellg(); // find the position of the cursor
        check.close(); // close your file

        if (len < 0) {
            cout << "No record of CNIC" << endl;
            return false;
        }
        else {
            int count = 0;
            ifstream data;
            data.open("Admin.txt");
            while (!data.eof() && !data.fail()) {
                data >> CNIC >> username >> password;

                for (int i = 0; i < numofpass; i++) {

                    if (admin[i].getCNIC() == CNIC) {
                        count++;
                        break;
                    }
                }
            }
            data.close();
            if (count == 0) {
                cout << "No record of CNIC" << endl;
                return false;
            }

            else {
                return true;
            }
        }
    }


    bool Login(int num) {
        cout << endl;
        string CNIC;
        string username;
        string password;

        string C;
        string user;
        string pass;

        cout << "Type Admin CNIC: ";
        cin >> CNIC;

        cout << "Type Admin username: ";
        cin >> username;

        cout << "Type Admin password: ";
        cin >> password;


        int count = 0;
        int index = 0;
        ifstream data;
        data.open("Admin.txt");

        while (!data.eof() && !data.fail()) {
            data >> C >> user >> pass;

            for (int i = 0; i < num; i++) {
                if (admin[i].getCNIC() == CNIC && admin[i].getUsername() == username && admin[i].getPassword() == password) {
                    count++;
                    index = i;
                    break;
                }
            }
        }
        data.close();

        if (count == 0) {
            cout << endl;
            cout << "Invalid Login" << endl;
            return false;
        }

        else {
            cout << endl;
            cout << admin[index].getCNIC() << endl;
            cout << admin[index].getUsername() << endl;
            cout << admin[index].getPassword() << endl;
            cout << endl;
            return true;
        }

    }

};