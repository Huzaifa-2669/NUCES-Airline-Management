#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>

using namespace std;

class Account {
private:
    string CNIC;
    string username;
    string password;
public:
    Account() {
        ;
    }

    bool characterCheck(string pass) {

        int numlet = pass.length();
        if (numlet < 8)
        {
            return false;
        }

        bool numeric = 0;
        bool capital = 0;
        bool lower = 0;
        bool special = 0;

        for (int i = 0; i < numlet; i++) {
            if (pass[i] >= 48 && pass[i] <= 57) {
                numeric = 1;
            }

            if (pass[i] >= 65 && pass[i] <= 90) {
                capital = 1;
            }

            if (pass[i] >= 97 && pass[i] <= 122) {
                lower = 1;
            }

            if ((pass[i] >= 33 && pass[i] <= 47) || (pass[i] >= 58 && pass[i] <= 64)) {
                special = 1;
            }
        }
        if (numeric && capital && lower && special)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void PasswordCheck() {
        string re_enter;

        int numlet = password.length();
        char* pass = new char[numlet];
        strcpy(pass, password.c_str());


        while (characterCheck(pass) == false) {
            cout << "Must type a valid password, Type password again: ";
            getPasswordInput();
            numlet = password.length();
            pass = new char[numlet];
            strcpy(pass, password.c_str());

        }

        cout << "Re-Type password: ";
        char ch = _getch();
        while (ch != 13) {//character 13 is enter
            if (ch == 8)
            {
                cout << "\b \b";
                re_enter.pop_back();
            }
            else
            {
                re_enter.push_back(ch);
                cout << '*';
                ch = _getch();

            }
        }
        cout << endl;

        while (re_enter != password) {
            cout << "Invalid Password, Re-type password again: ";
            re_enter = "";
            char ch = _getch();
            while (ch != 13) {//character 13 is enter
                if (ch == 8)
                {
                    cout << "\b \b";
                    re_enter.pop_back();
                }
                else
                {
                    re_enter.push_back(ch);
                    cout << '*';
                    ch = _getch();
                }
            }
            cout << endl;
        }
    }

    void Registration(string c) {
        CNIC = c;
        while (CNIC.length() < 13 || CNIC.length() > 13) {
            cout << "Invalid CNIC, Type CNIC again: ";
            cin >> CNIC;
        }
        cout << "Type username: ";
        cin >> username;
        getPasswordInput();
        PasswordCheck();
    }

    void getPasswordInput() {

        cout << "Type password (must be 8 characters): ";
        char ch = _getch();
        while (ch != 13) {//character 13 is enter
            if (ch == 8)
            {
                cout << "\b \b";
                password.pop_back();
            }
            else
            {
                password.push_back(ch);
                cout << '*';
                ch = _getch();

            }
        }

        cout << endl;

    }

    void StoreLogin() {
        fstream details;
        details.open("Passenger.txt", ios::out | ios::app);
        details << CNIC;
        details << " ";
        details << username;
        details << " ";
        details << password;
        details << "\n";
        details.close();
    }

    void setCNIC(string C) {
        CNIC = C;
    }

    void setUser(string u) {
        username = u;
    }

    void setPass(string p) {
        password = p;
        PasswordCheck();
    }

    string getPassword() {
        return password;
    }

    string getUsername() {
        return username;
    }

    string getCNIC() {
        return CNIC;
    }

    void resetUsername(string user) {
        username = user;
    }

    void resetPassword(string pass) {
        password = pass;
    }
};