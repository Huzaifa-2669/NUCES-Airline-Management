#include <iostream>
#include<ctime>
#include<Windows.h>
#include <fstream>
#include "Account.h"
#include "Passenger.h"
#include "Flight.h"
#include "Admin.h"
#include "Plane.h"
#include "Islamabad.h"
#include "Peshawar.h"
#include "Karachi.h"
#include "Quetta.h"
#include "Lahore.h"
#include "Booking.h"

using namespace std;

string phoneNumber;
string name;
string address;
string email;

double BankDetails() {
	double amount = 0;

	cout << "Bank Details:" << endl;
	cout << "Type amount you have in your bank: ";
	cin >> amount;
	while (amount < 0)
	{
		cout << "Invalid amount, Please enter a valid amount: ";
		cin >> amount;
	}
	return amount;
}

void AboutUs() {
	cout << endl;
	cout << "You have just Landed on the Top 10 most Intelligently Coded Programs ever." << endl;
	cout << "Huzaifa Mahmood" << endl;
	cout << endl;
}

void ContactUs() {
	phoneNumber = "03250369499";
	name = "Huzaifa Mahmood";
	address = "Yahan say straight aur wahan say right. Us kaay baad";
	email = "i222669@nu.edu.pk";
	cout << endl;
	cout << "Phone Number : " << phoneNumber << endl;
	cout << "Name : " << name << endl;
	cout << "Email :" << email << "" << endl;
	cout << "Address : " << address << endl;
	cout << endl;
}

int main() {
	srand((unsigned)time(0));
	cout << endl;
	long double CNIC;
	string username;
	string password;
	string secret = "E56789";
	string key;

	//check number of logins in text file to loop through and print
	ifstream countlogin;
	int noOfLogins = 0;
	countlogin.open("Passenger.txt");
	while (!countlogin.eof() && !countlogin.fail()) {

		countlogin >> CNIC >> username >> password;
		noOfLogins++;
	}
	if (noOfLogins > 0) {
		noOfLogins--;
	}
	countlogin.close();

	//initially defining variables
	char update = 'n';
	bool exist;

	//generation of Passengers
	Account* pass;
	pass = new Account[50000];

	//generation of Admins
	Account* ad;
	ad = new Account[20];


	//Aggregation link
	Passenger passenger(pass);
	Admin admin(ad);

	//Planes Generation
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

	//Booking Object
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
	Sleep(2000);
	cout << "Loading .";Sleep(500); cout << ".";Sleep(500); cout << ".";Sleep(500); cout << "." << endl;
	system("CLS");
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "Welcome To NUCES AirLine Management System" << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
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
		if (loginoption == 1) {

			int panel = 0;
			while (panel != 3) {

				cout << "Would you like:\n"
					<< "1) Passenger Login\n"
					<< "2) Admin Login\n"
					<< "3) go back to sign up or check flight schedule\n"
					<< "Option: ";
				cin >> panel;

				if (panel == 1) {
					cout << endl;
					exist = passenger.loginExistence(noOfLogins);
					if (exist == false) {
						cout << "Would you like to sign up (y or n): ";
						cin >> update;
						if (update == 'y') {
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

									else if (passengerchoice == 2) {
										cout << "Which city would you like to book flight from: ";
										cin >> city1;

										if (city1 == "Islamabad") {
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
												}
											}
										}

										else if (city1 == "Quetta") {
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
													}
												}
											}
										}

										else if (city1 == "Karachi") {
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
													}
												}
											}
										}

										else if (city1 == "Peshawar") {
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
													}
												}
											}
										}

										else if (city1 == "Lahore") {
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
													}
												}
											}
										}
									}

									else if (passengerchoice == 3) {
										int abroad;
										cout << "How many times have you been abroad: ";
										cin >> abroad;
										if (abroad > 5) {
											cout << "What airport would you like to see the Special Flight: ";
											cin >> city;

											if (city == "Islamabad") {
												islam.DisplayNorthData();
												islam.DisplaySouthData();
												islam.PassengerSF();
											}

											else if (city == "Quetta") {
												qut.DisplayNorthData();
												qut.DisplaySouthData();
												qut.PassengerSF();
											}

											else if (city == "Karachi") {
												khi.DisplayNorthData();
												khi.DisplaySouthData();
												khi.PassengerSF();
											}

											else if (city == "Peshawar") {
												pesh.DisplayNorthData();
												pesh.DisplaySouthData();
												pesh.PassengerSF();
											}

											else if (city == "Lahore") {
												lah.DisplayNorthData();
												lah.DisplaySouthData();
												lah.PassengerSF();
											}
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
									while (adminchoice != 5) {
										cout << "Would you like to:\n"
											<< "1) Change routes of Indirect International Flights\n"
											<< "2) Restrict Passengers\n"
											<< "3) Update Departure Time\n"
											<< "4) Update About Us Information \n"
											<< "5) Go back\n"
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
										else if (adminchoice == 4)
										{
											cout << "Enter New Name :" << endl;
											cin.ignore();
											getline(cin, name);
											cout << "Enter New Address :" << endl;
											getline(cin, address);
											cout << "Enter New Contact Number :" << endl;
											cin >> phoneNumber;
											cout << "Enter New Email :" << endl;
											cin >> email;
											cout << "Thank You for Updating Your Information" << endl;
											cout << "Would you like to view the Updated Information ? (1/0)" << endl;
											cin >> adminchoice;
											if (adminchoice == 1)
											{
												AboutUs();
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
					islam.IslamabadSpecialFlights();//Special flight settings for passenger
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
	return 0;
}