#include<iostream>
#include<fstream>
#include<ctime>
#include "Account.h"
#include "Admin.h"
#include "Booking.h"
#include "Flight.h"
#include "Islamabad.h"
#include "Karachi.h"
#include "Lahore.h"
#include "Passenger.h"
#include "Peshawar.h"
#include "Plane.h"
#include "Quetta.h"

using namespace std;
double BankDetails() {
    double amount = 0;
    cout << "Bank Details :" << endl;
    cout << "Type the Amount you have in Bank :" << endl;
    cin >> amount;

    return amount;
}

void AboutUs() {
    cout << endl;
    cout << "You have just Landed on the Top 10 most Intelligently Coded Programs ever." << endl;
    cout << "Huzaifa Mahmood" << endl;

}

void ContactUs() {
    cout << endl;
    cout << "Phone Number : 03250369499" << endl;
    cout << "Huzaifa Mahmood " << endl;
    cout << "Email : I222669@nu.edu.pk" << endl;
    cout << "Address : Yahan say straight aur wahan say right. Us kaay baad Fuck off" << endl;

}

int main()
{
    srand((unsigned)time(0));
    Peshawar p;
    cout << endl;
    long double CNIC;
    string username;
    string password;
    string secret = "E56789";
    string key;

    //Check no of logins in the Text file
    fstream countLogins;
    int noOfLogins = 0;
    countLogins.open("Passengers.txt", ios::in);
    while (!countLogins.eof() && !countLogins.fail())
    {
        countLogins >> CNIC >> username >> password;
        noOfLogins++;
    }
    if (noOfLogins > 0)
    {
        noOfLogins--;
    }
    countLogins.close();

    //initially define variables
    char update = 'n';
    bool exist;

    //Generation of Passengers
    Account* pass;
    pass = new Account[5000];

    //Generation of Admins
    Account* ad;
    ad = new Account[20];

    //Aggregation
    Passenger passenger(pass);
    Admin admin(ad);

    //Plane Generation
    Planes* Islama = new Planes[20];
    Planes* Karanchi = new Planes[20];
    Planes* Quet = new Planes[20];
    Planes* Pesh = new Planes[20];
    Planes* Lah = new Planes[20];

    Islamabad islam;
    Peshawar pesh;
    Quetta qut;
    Lahore lah;
    Karachi khi;

    islam.setNorthData(Islama);
    islam.setSouthData(Islama);
    pesh.setNorthData(Pesh);
    pesh.setSouthData(Pesh);
    qut.setNorthData(Quet);
    qut.setSouthData(Quet);
    lah.setNorthData(Lah);
    lah.setSouthData(Lah);
    khi.setNorthData(Karanchi);
    khi.setSouthData(Karanchi);

    //Booking Obejct Creation
    Booking booking;
    string city;
    string city1;
    string direction;
    double leftamount = 0;
    int pay = 0;
    int option;
    int loginoption = 0;
    int adminchoice = 0;
    int passengerchoice = 0;

    while (loginoption != 6) {
        cout << endl;
        cout << "Would you like to:\n"
            << "1) Login\n"
            << "2) Sign up\n"
            << "3) Schedule\n"
            << "4) About Us\n"
            << "5) Contact us\n"
            << "6) Exit\n"
            << "Option: ";
        cin >> loginoption;

        cout << endl;
        if (loginoption == 1)
        {
            int panel = 0;
            while (panel != 3)
            {
                cout << "Would you like to \n";
                cout << "1) Passenger Login\n";
                cout << "2) Admin Login\n";
                cout << "3) Go Back to Home Page\n";
                cout << "Option  :";
                cin >> panel;

                if (panel == 1)
                {
                    cout << endl;
                    exist = passenger.loginExistence(noOfLogins);
                    if (exist == false)
                    {
                        cout << "Would you loke to Sign up (y / n)" << endl;
                        cin >> update;
                        if (update == 'y')
                        {
                            cout << endl;
                            passenger.Signup(noOfLogins, update);
                            noOfLogins++;
                        }
                    }
                    else {
                        cout << endl;
                        exist = passenger.Login(noOfLogins);
                        if (exist == true) {
                            cout << "Would you like to change you login details (y or n): ";
                            cin >> update;
                            if (update == 'y') {
                                cout << endl;
                                passenger.changeLoginData();
                            }
                            else {
                                cout << endl;
                                passenger.setBankAmount(BankDetails());
                                cout << endl;
                                //implementation of passenger choice for booking
                                while (passengerchoice != 4) {
                                    cout << "Would you like to:\n"
                                        << "1) Check Flight Schedule\n"
                                        << "2) Book Flight\n"
                                        << "3) Avail Special Flights\n"
                                        << "4) Log out\n"
                                        << "Option: ";
                                    cin >> passengerchoice;

                                    if (passengerchoice == 1) {
                                        cout << "What city would you like to see flight schedule of: ";
                                        cin >> city;

                                        if (city == "Islamabad" || city == "islamabad") {

                                            cout << "Would you like to see data from North airport or South: ";
                                            cin >> direction;

                                            if (direction == "North" || direction == "north") {

                                                islam.DisplayNorthData();
                                            }

                                            else {

                                                islam.DisplaySouthData();
                                            }
                                        }

                                        if (city == "Karachi" || city == "karachi") {


                                            cout << "Would you like to see data from North airport or South: ";
                                            cin >> direction;

                                            if (direction == "North" || direction == "north") {

                                                khi.DisplayNorthData();
                                            }

                                            else {

                                                khi.DisplaySouthData();
                                            }
                                        }

                                        if (city == "Lahore" || city == "lahore") {


                                            cout << "Would you like to see data from North airport or South: ";
                                            cin >> direction;

                                            if (direction == "North" || direction == "north") {

                                                lah.DisplayNorthData();
                                            }

                                            else {

                                                lah.DisplaySouthData();
                                            }
                                        }

                                        if (city == "Quetta" || city == "quetta") {

                                            cout << "Would you like to see data from North airport or South: ";
                                            cin >> direction;

                                            if (direction == "North" || direction == "north") {

                                                qut.DisplayNorthData();
                                            }

                                            else {

                                                qut.DisplaySouthData();
                                            }
                                        }

                                        if (city == "Peshawar" || city == "peshawar") {

                                            cout << "Would you like to see data from North airport or South: ";
                                            cin >> direction;

                                            if (direction == "North" || direction == "north") {

                                                pesh.DisplayNorthData();
                                            }

                                            else {

                                                pesh.DisplaySouthData();
                                            }
                                        }
                                    }

                                    else if (passengerchoice == 2) {
                                        cout << "Which city would you like to book flight from: ";
                                        cin >> city1;

                                        if (city1 == "Islamabad" || city1 == "islamabad") {
                                            islam.DisplayNorthData();
                                            islam.DisplaySouthData();
                                            islam.RegisteredSeats(booking);
                                            cout << endl;
                                            booking.DisplayBooking();
                                            cout << booking;
                                            cout << endl;
                                            while (pay != 2) {
                                                cout << "Would you like to:\n"
                                                    << "1) Proceed to Payment\n"
                                                    << "2) Go back\n"
                                                    << "Option: ";
                                                cin >> pay;

                                                if (pay == 1) {
                                                    leftamount = passenger.getAmount() - booking.getcost();
                                                    if (leftamount < 0) {
                                                        cout << "You cannot afford Flights" << endl;
                                                    }
                                                    else {
                                                        cout << "Your Left Over Amount: " << leftamount << endl;
                                                        passenger.setBankAmount(leftamount);
                                                    }
                                                    cout << "Would you Like to Refund your Booking ? (y/n)" << endl;
                                                    char choise;
                                                    cin >> choise;
                                                    if (choise == 'y')
                                                    {
                                                        cout << "Your Money will be refunded after Government Tax (25%).\nDo you Still wish to continue ? ( y / n)" << endl;
                                                        cin >> choise;
                                                        if (choise == 'y')
                                                        {
                                                            double ticketPrice = booking.getcost();
                                                            double governmentTax = ticketPrice * 0.25;
                                                            cout << "Your Ticket Price was: $" << ticketPrice;
                                                            cout << "The Government Tax is : $" << governmentTax;
                                                            leftamount = passenger.getAmount() + (ticketPrice - governmentTax);
                                                            passenger.setBankAmount(leftamount);
                                                            cout << "Now your Bank Balance is : $" << passenger.getAmount();

                                                        }

                                                    }

                                                }
                                            }
                                        }

                                        else if (city1 == "Quetta" || city1 == "quetta") {
                                            qut.DisplayNorthData();
                                            qut.DisplaySouthData();
                                            qut.RegisteredSeats(booking);
                                            cout << endl;
                                            booking.DisplayBooking();
                                            cout << booking;
                                            cout << endl;
                                            while (pay != 2) {
                                                cout << "Would you like to:\n"
                                                    << "1) Proceed to Payment\n"
                                                    << "2) Go back\n"
                                                    << "Option: ";
                                                cin >> pay;

                                                if (pay == 1) {
                                                    leftamount = passenger.getAmount() - booking.getcost();
                                                    if (leftamount < 0) {
                                                        cout << "You cannot afford Flights" << endl;
                                                    }
                                                    else {
                                                        cout << "Your Left Over Amount: " << leftamount << endl;
                                                        passenger.setBankAmount(leftamount);
                                                        cout << "Would you Like to Refund your Booking ? (y/n)" << endl;
                                                        char choise;
                                                        cin >> choise;
                                                        if (choise == 'y')
                                                        {
                                                            cout << "Your Money will be refunded after Government Tax (25%).\nDo you Still wish to continue ? ( y / n)" << endl;
                                                            cin >> choise;
                                                            if (choise == 'y')
                                                            {
                                                                double ticketPrice = booking.getcost();
                                                                double governmentTax = ticketPrice * 0.25;
                                                                cout << "Your Ticket Price was: $" << ticketPrice;
                                                                cout << "The Government Tax is : $" << governmentTax;
                                                                leftamount = passenger.getAmount() + (ticketPrice - governmentTax);
                                                                passenger.setBankAmount(leftamount);
                                                                cout << "Now your Bank Balance is : $" << passenger.getAmount();

                                                            }

                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else if (city1 == "Karachi" || city1 == "karachi") {
                                            khi.DisplayNorthData();
                                            khi.DisplaySouthData();
                                            khi.RegisteredSeats(booking);
                                            cout << endl;
                                            booking.DisplayBooking();
                                            cout << booking;
                                            cout << endl;
                                            while (pay != 2) {
                                                cout << "Would you like to:\n"
                                                    << "1) Proceed to Payment\n"
                                                    << "2) Go back\n"
                                                    << "Option: ";
                                                cin >> pay;

                                                if (pay == 1) {
                                                    leftamount = passenger.getAmount() - booking.getcost();
                                                    if (leftamount < 0) {
                                                        cout << "You cannot afford Flights" << endl;
                                                    }
                                                    else {
                                                        cout << "Your Left Over Amount: " << leftamount << endl;
                                                        passenger.setBankAmount(leftamount);
                                                        cout << "Would you Like to Refund your Booking ? (y/n)" << endl;
                                                        char choise;
                                                        cin >> choise;
                                                        if (choise == 'y')
                                                        {
                                                            cout << "Your Money will be refunded after Government Tax (25%).\nDo you Still wish to continue ? ( y / n)" << endl;
                                                            cin >> choise;
                                                            if (choise == 'y')
                                                            {
                                                                double ticketPrice = booking.getcost();
                                                                double governmentTax = ticketPrice * 0.25;
                                                                cout << "Your Ticket Price was: $" << ticketPrice;
                                                                cout << "The Government Tax is : $" << governmentTax;
                                                                leftamount = passenger.getAmount() + (ticketPrice - governmentTax);
                                                                passenger.setBankAmount(leftamount);
                                                                cout << "Now your Bank Balance is : $" << passenger.getAmount();

                                                            }

                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else if (city1 == "Peshawar" || city1 == "peshawar") {
                                            pesh.DisplayNorthData();
                                            pesh.DisplaySouthData();
                                            pesh.RegisteredSeats(booking);
                                            cout << endl;
                                            booking.DisplayBooking();
                                            cout << booking;
                                            cout << endl;
                                            while (pay != 2) {
                                                cout << "Would you like to:\n"
                                                    << "1) Proceed to Payment\n"
                                                    << "2) Go back\n"
                                                    << "Option: ";
                                                cin >> pay;

                                                if (pay == 1) {
                                                    leftamount = passenger.getAmount() - booking.getcost();
                                                    if (leftamount < 0) {
                                                        cout << "You cannot afford Flights" << endl;
                                                    }
                                                    else {
                                                        cout << "Your Left Over Amount: " << leftamount << endl;
                                                        passenger.setBankAmount(leftamount);
                                                        cout << "Would you Like to Refund your Booking ? (y/n)" << endl;
                                                        char choise;
                                                        cin >> choise;
                                                        if (choise == 'y')
                                                        {
                                                            cout << "Your Money will be refunded after Government Tax (25%).\nDo you Still wish to continue ? ( y / n)" << endl;
                                                            cin >> choise;
                                                            if (choise == 'y')
                                                            {
                                                                double ticketPrice = booking.getcost();
                                                                double governmentTax = ticketPrice * 0.25;
                                                                cout << "Your Ticket Price was: $" << ticketPrice;
                                                                cout << "The Government Tax is : $" << governmentTax;
                                                                leftamount = passenger.getAmount() + (ticketPrice - governmentTax);
                                                                passenger.setBankAmount(leftamount);
                                                                cout << "Now your Bank Balance is : $" << passenger.getAmount();

                                                            }

                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else if (city1 == "Lahore" || city1 == "lahore") {
                                            lah.DisplayNorthData();
                                            lah.DisplaySouthData();
                                            lah.RegisteredSeats(booking);
                                            cout << endl;
                                            booking.DisplayBooking();
                                            cout << booking;
                                            cout << endl;
                                            while (pay != 2) {
                                                cout << "Would you like to:\n"
                                                    << "1) Proceed to Payment\n"
                                                    << "2) Go back\n"
                                                    << "Option: ";
                                                cin >> pay;

                                                if (pay == 1) {
                                                    leftamount = passenger.getAmount() - booking.getcost();
                                                    if (leftamount < 0) {
                                                        cout << "You cannot afford Flights" << endl;
                                                    }
                                                    else {
                                                        cout << "Your Left Over Amount: " << leftamount << endl;
                                                        passenger.setBankAmount(leftamount);
                                                        cout << "Would you Like to Refund your Booking ? (y/n)" << endl;
                                                        char choise;
                                                        cin >> choise;
                                                        if (choise == 'y')
                                                        {
                                                            cout << "Your Money will be refunded after Government Tax (25%).\nDo you Still wish to continue ? ( y / n)" << endl;
                                                            cin >> choise;
                                                            if (choise == 'y')
                                                            {
                                                                double ticketPrice = booking.getcost();
                                                                double governmentTax = ticketPrice * 0.25;
                                                                cout << "Your Ticket Price was: $" << ticketPrice;
                                                                cout << "The Government Tax is : $" << governmentTax;
                                                                leftamount = passenger.getAmount() + (ticketPrice - governmentTax);
                                                                passenger.setBankAmount(leftamount);
                                                                cout << "Now your Bank Balance is : $" << passenger.getAmount();

                                                            }

                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    else if (passengerchoice == 3) {
                                        char choise;
                                        cout << "Do you Have VISA for your passport? (y/n)" << endl;
                                        cin >> choise;
                                        if (choise == 'y')
                                        {
                                            int abroad;
                                            cout << "How many times have you been abroad: ";
                                            cin >> abroad;
                                            if (abroad > 5) {
                                                cout << "What airport would you like to see the Special Flight: ";
                                                cin >> city;

                                                if (city == "Islamabad") {
                                                    islam.PassengerSF();
                                                }

                                                else if (city == "Quetta") {
                                                    qut.PassengerSF();
                                                }

                                                else if (city == "Karachi") {
                                                    khi.PassengerSF();
                                                }

                                                else if (city == "Peshawar") {
                                                    pesh.PassengerSF();
                                                }

                                                else if (city == "Lahore") {
                                                    lah.PassengerSF();
                                                }
                                            }
                                            else
                                            {
                                                cout << "You have not visited enough countries to view Special Flights..." << endl;
                                            }
                                        }
                                        else {
                                            cout << "Sorry ... You cannot view Special Flights without VISA." << endl;
                                        }
                                    }
                                    cout << endl;
                                }
                            }
                        }
                    }

                }

                else if (panel == 2) {
                    cout << "Type secret admin key: ";
                    cin >> key;
                    if (key == secret) {
                        exist = admin.loginExistence(20);
                        if (exist == false) {
                            cout << endl;
                            continue;
                        }

                        else {
                            exist = admin.Login(20);
                            if (exist == true) {
                                cout << "Would you like to change you login details (y or n): ";
                                cin >> update;
                                if (update == 'y') {
                                    cout << endl;
                                    admin.changeLoginData();
                                }
                                else {
                                    cout << endl;
                                    //implementation of Admin choice for changing Schedule
                                    while (adminchoice != 4) {
                                        cout << "Would you like to:\n"
                                            << "1) Change routes of Indirect International Flights\n"
                                            << "2) Restrict Passengers\n"
                                            << "3) Update Departure Time\n"
                                            << "4) Go back\n"
                                            << "Option: ";
                                        cin >> adminchoice;

                                        if (adminchoice == 1) {
                                            cout << "What airport would you like to see the Special Flight: ";
                                            cin >> city;

                                            if (city == "Islamabad") {
                                                islam.DisplayNorthData();
                                                islam.DisplaySouthData();
                                                islam.IslamabadSpecialFlights();
                                            }

                                            else if (city == "Quetta") {
                                                qut.DisplayNorthData();
                                                qut.DisplaySouthData();
                                                qut.QuettaSpecialFlight();
                                            }

                                            else if (city == "Karachi") {
                                                khi.DisplayNorthData();
                                                khi.DisplaySouthData();
                                                khi.KarachiSpecialFlight();
                                            }

                                            else if (city == "Peshawar") {
                                                pesh.DisplayNorthData();
                                                pesh.DisplaySouthData();
                                                pesh.PeshawarSpecialFlight();
                                            }

                                            else if (city == "Lahore") {
                                                lah.DisplayNorthData();
                                                lah.DisplaySouthData();
                                                lah.LahoreSpecialFlight();
                                            }
                                        }

                                        else if (adminchoice == 2) {
                                            cout << "What airport would you like to see the Special Flight: ";
                                            cin >> city1;

                                            if (city1 == "Islamabad") {
                                                islam.DisplayNorthData();
                                                islam.DisplaySouthData();
                                                islam.RestrictSeats();
                                            }

                                            else if (city1 == "Quetta") {
                                                qut.DisplayNorthData();
                                                qut.DisplaySouthData();
                                                qut.RestrictSeats();
                                            }

                                            else if (city1 == "Karachi") {
                                                khi.DisplayNorthData();
                                                khi.DisplaySouthData();
                                                khi.RestrictSeats();
                                            }

                                            else if (city1 == "Peshawar") {
                                                pesh.DisplayNorthData();
                                                pesh.DisplaySouthData();
                                                pesh.RestrictSeats();
                                            }

                                            else if (city1 == "Lahore") {
                                                lah.DisplayNorthData();
                                                lah.DisplaySouthData();
                                                lah.RestrictSeats();
                                            }

                                        }
                                        //adminchoice == 3
                                        else if (adminchoice == 3) {
                                            cout << "What city airports would you like to change depart times for: ";
                                            cin >> city1;

                                            if (city1 == "Islamabad") {
                                                islam.DisplayNorthData();
                                                islam.DisplaySouthData();
                                                islam.changeDepartTimes();
                                                islam.DisplayNorthData();
                                                islam.DisplaySouthData();
                                            }

                                            else if (city1 == "Quetta") {
                                                qut.DisplayNorthData();
                                                qut.DisplaySouthData();
                                                qut.ChangeDepartTimes();
                                                qut.DisplayNorthData();
                                                qut.DisplaySouthData();
                                            }

                                            else if (city1 == "Karachi") {
                                                khi.DisplayNorthData();
                                                khi.DisplaySouthData();
                                                khi.ChangeDepartTimes();
                                                khi.DisplayNorthData();
                                                khi.DisplaySouthData();
                                            }

                                            else if (city1 == "Peshawar") {
                                                pesh.DisplayNorthData();
                                                pesh.DisplaySouthData();
                                                pesh.ChangeDepartTimes();
                                                pesh.DisplayNorthData();
                                                pesh.DisplaySouthData();
                                            }

                                            else if (city1 == "Lahore") {
                                                lah.DisplayNorthData();
                                                lah.DisplaySouthData();
                                                lah.ChangeDepartTimes();
                                                lah.DisplayNorthData();
                                                lah.DisplaySouthData();
                                            }
                                        }
                                    }
                                    cout << endl;
                                }
                            }
                        }
                    }
                }

                else {
                    break;
                }
            }
        }

        else if (loginoption == 2) {
            update = 'y';
            cout << endl;
            passenger.Signup(noOfLogins, update);
            noOfLogins++;
        }

        else if (loginoption == 3) {
            cout << endl;
            cout << "Would you like to:\n"
                << "1) Filter Schedule\n"
                << "2) See Full Schedule\n"
                << "3) Would you like to Avail Special Flight\n"
                << "Option: ";
            cin >> option;


            if (option == 1) {
                cout << "What city would you like to see flight schedule of: ";
                cin >> city;

                if (city == "Islamabad") {

                    cout << "Would you like to see data from North airport or South: ";
                    cin >> direction;

                    if (direction == "North") {

                        islam.DisplayNorthData();
                    }

                    else {

                        islam.DisplaySouthData();
                    }
                }

                if (city == "Karachi") {


                    cout << "Would you like to see data from North airport or South: ";
                    cin >> direction;

                    if (direction == "North") {

                        khi.DisplayNorthData();
                    }

                    else {

                        khi.DisplaySouthData();
                    }
                }

                if (city == "Lahore") {


                    cout << "Would you like to see data from North airport or South: ";
                    cin >> direction;

                    if (direction == "North") {

                        lah.DisplayNorthData();
                    }

                    else {

                        lah.DisplaySouthData();
                    }
                }

                if (city == "Quetta") {

                    cout << "Would you like to see data from North airport or South: ";
                    cin >> direction;

                    if (direction == "North") {

                        qut.DisplayNorthData();
                    }

                    else {

                        qut.DisplaySouthData();
                    }
                }

                if (city == "Peshawar") {

                    cout << "Would you like to see data from North airport or South: ";
                    cin >> direction;

                    if (direction == "North") {

                        pesh.DisplayNorthData();
                    }

                    else {

                        pesh.DisplaySouthData();
                    }
                }
            }


            else if (option == 2) {
                islam.DisplayNorthData();
                islam.DisplaySouthData();
                khi.DisplayNorthData();
                khi.DisplaySouthData();
                lah.DisplayNorthData();
                lah.DisplaySouthData();
                qut.DisplayNorthData();
                qut.DisplaySouthData();
                pesh.DisplayNorthData();
                pesh.DisplaySouthData();
            }

            else {
                cout << "What airport would you like to see the Special Flight: ";
                cin >> city;

                if (city == "Islamabad") {
                    islam.PassengerSF();//Special flight settings for passenger
                }
                else if (city == "Karachi")
                {
                    khi.PassengerSF();
                }
                else if (city == "Lahore")
                {
                    lah.PassengerSF();
                }
                else if (city == "Quetta")
                {
                    qut.PassengerSF();
                }
                else if (city == "Peshawar")
                {
                    pesh.PassengerSF();
                }

            }
        }

        else if (loginoption == 4) {
            AboutUs();
        }

        else if (loginoption == 5) {
            ContactUs();
        }

        else {
            break;
        }

        update = 'n';
        cout << endl;

    }

    //remove("login_data.txt");

    return 0;

}