//**********************************************************************************************************
// Programmed by:	Justin Lucker, Connor Wright, and Jared Adamson
// File:			main.cpp
// Program:			CSE240Project
// Date:			03/18/2014
// Date Modified:	04/04/2014
// Class:			CSE 240
// Email:			cswrigh2@asu.edu
// Description:		This program takes two .csv files as input and populates two interconnected linked lists 
//					with the data contained within the .csv files.  The data is initially loaded into two
//					vectors called hubVector and flightVector which act as buffers and are deleted after
//					the linked list is created. The user is then able to print a list of each airport with 
//					a list of its departing flights below.
//**********************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <xstring>
#include <vector>
#include "Hub.h"
#include "main.h"
#include "Flight.h"
#include "HubNode.h"
#include "HubList.h"
#include "FlightList.h"

using namespace std;

int main()
{
	ifstream hubFile(hubFileName);
	ifstream flightFile(flightFileName);
	string line;
	string airportName;
	string airportLocation;
	string flightNumber;
	string flightPrice;
	string flightSource;
	string flightDestination;
	string flightDeparture;
	string flightDuration;
	string flightCompany;
	std::vector<Hub> hubVector;
	std::vector<Flight> flightVector;
	HubList hubList;


	// Read the Hub.csv file and add it to the hubVector
	if (hubFile.is_open())
	{
		while (getline(hubFile, line))
		{
			while (getline(hubFile, airportName, ','))
			{
				getline(hubFile, airportLocation);
				Hub newHub = Hub(airportName, airportLocation);
				hubVector.push_back(newHub);
			}
		}
		hubFile.close();
	}
	// If the program is unable to open the file it displays a message and then closes
	else
	{
		cout << "Unable to Open Hub Resource File" << endl;
		getchar();
		return 0;
	}


	// Read the Flight.csv file and add it to the fligthVector
	if (flightFile.is_open())
	{
		while (getline(flightFile, line))
		{
			while (getline(flightFile, flightNumber, ','))
			{
				//getline(flightFile, flightNumber, ',');
				getline(flightFile, flightPrice, ',');
				getline(flightFile, flightSource, ',');
				getline(flightFile, flightDestination, ',');
				getline(flightFile, flightDeparture, ',');
				getline(flightFile, flightDuration, ',');
				getline(flightFile, flightCompany);
				Date_Time newDate = Date_Time(flightDeparture);
				Flight newFlight = Flight(flightNumber, flightPrice, flightSource, flightDestination, newDate, flightDuration, flightCompany);
				flightVector.push_back(newFlight);
			}
		}
		flightFile.close();
	}
	// If the program is unable to open the file it displays a message and then closes
	else
	{
		cout << "Unable to Open Flight Resource File" << endl;
		getchar();
		return 0;
	}

	bool good = false;

	while (good == false)
	{

		cout << "Project Debug Menu" << endl;
		cout << "Please Make a Selection" << endl;
		cout << "1. To Display Flights by their Departure Airports" << endl;
		cout << "2. To Book a Flight" << endl;
		cout << "3. To Quit" << endl;
		int selection;
		cin >> selection;
		if (selection == 1)
		{
			HubList hList;
			for (int i = 0; i < hubVector.size(); i++)
			{
				FlightList flightList;
				for (int j = 0; j < flightVector.size(); j++)
				{
					if (hubVector[i].getAirport() == flightVector[j].getFlightSource())
					{
						flightList.insertFlight(flightVector[j]);
					}
				}
				hList.insertHub(hubVector[i], flightList.getHeadFlight());
			}
			// Sets the hubList HubList object equal to the local variable hList
			// ---------> hubList is now the means of accessing the list for future use
			hubList = hList;

			// Deletes the local HubList variable now that we don't need it
			hList.HubList::~HubList();

			// Calls function that prints each hub and then its corresponding flights
			hubList.printHubFlights();

			//// Clears all of the content of the vectors
			hubVector.clear();
			flightVector.clear();

			//// Effectively frees memory that the vectors were using
			vector<Hub>().swap(hubVector);
			vector<Flight>().swap(flightVector);

			// Waits for user input
			system("pause");

			// Destructs the hubList object before closing the program
			hubList.HubList::~HubList();
		}

		else if (selection == 2)
		{
			// Gets user inputs for flight destination

			string destination;

			good = false;

			while (good == false)
			{
				cout << "Please Choose Your Destination:" << endl;
				cout << "1. Tucson International Airport, Tucson" << endl;
				cout << "2. Los Angeles International Airport, Los Angeles" << endl;
				cout << "3. Whiteman Airport, Los Angeles" << endl;
				cout << "4. San Francisco International Airport, San Francisco" << endl;
				cout << "5. San Diego International Airport, San Diego" << endl;
				cout << "6. Albany International Airport, Albany" << endl;
				cout << "7. Chicago Midway International Airport, Chicago" << endl;
				cout << "8. Chicago O'Hare International Airport,Chicago" << endl;
				cout << "9. General Edward Lawrence Logan International Airport, Boston" << endl;
				cout << "10. Mc Carran International Airport, Las Vegas" << endl;
				cout << "11. John F Kennedy International Airport, New York" << endl;
				cout << "12. Miami International Airport, Miami" << endl;
				cout << "13. Honolulu International Airport, Honolulu" << endl;
				cout << "14. Denver International Airport, Denver" << endl;
				cin >> selection;

				if (selection > 0 && selection < 15)
				{
					good = true;
				}
				else 
				{
					cout << "Invalid Selection" << endl;
				}
			}

			// Set the user inputs to variable destination for later use
			if (selection == 1) destination = "Tucson International Airport";
			else if (selection == 2) destination = "Los Angeles International Airport";
			else if (selection == 3) destination = "Whiteman Airport";
			else if (selection == 4) destination = "San Francisco International Airport";
			else if (selection == 5) destination = "San Diego International Airport";
			else if (selection == 6) destination = "Albany International Airport";
			else if (selection == 7) destination = "Chicago Midway International Airport";
			else if (selection == 8) destination = "Chicago O'Hare International Airport";
			else if (selection == 9) destination = "General Edward Lawrence Logan International Airport";
			else if (selection == 10) destination = "Mc Carran International Airport";
			else if (selection == 11) destination = "John F Kennedy International Airport";
			else if (selection == 12) destination = "Miami International Airport";
			else if (selection == 13) destination = "Honolulu International Airport";
			else if (selection == 14) destination = "Denver International Airport";

			Date_Time desiredDepartureDate;

			while (good == false)
			{
				cout << "Please Enter the Date in the Format MM/HH/DD/MM/YYYY" << endl;
				cout << "Examples: 15/08/15/12/2013 or 15/08/03/03/2013" << endl;

				string date;

				cin >> date;

				if (date.length() == 16)
				{
					good = true;

					desiredDepartureDate = Date_Time(date);
				}
				else 
				{
					cout << "Invalid Selection" << endl;
				}
			}

			good = false;
			int luggage;

			while (good == false)
			{
				cout << "Please Enter the Number of Luggage for Check-in" << endl;

				cin >> selection;

				if (selection >= 0)
				{
					good = true;

					luggage = selection;
				}
				else 
				{
					cout << "Invalid Selection" << endl;
				}
			}

			int sortMethod;
			good = false;

			while (good == false)
			{

				cout << "Would you like the quickest flight or best price?" << endl;
				cout << "1. To Select the Cheepest Flight." << endl;
				cout << "2. To Select the Fastest Flight." << endl;
				cin >> selection;

				if (selection == 1) 
				{
					good = true;

					cout << "Selection Accepted" << endl; sortMethod = 1;
				}
				else if (selection == 2)
				{
					good = true;

					cout << "Selection Accepted" << endl; sortMethod = 2;
				}
				else 
				{ 
					cout << "Invalid Selection" << endl; 
				}
			}

			good = false;

			while (good == false)
			{

				cout << "Please Confirm Your Selection" << endl;
				cout << "Your Selected Destination was: " << destination << endl;
				cout << "Your Selected Departure Time was: " << desiredDepartureDate.toString() << endl;
				cout << "You Selected " << luggage << " For Check-in" << endl;
				if (sortMethod == 1)
				{
					cout << "You Selected the Cheapest Flight Available" << endl;
				}
				if (sortMethod == 2)
				{
					cout << "You Selected the Fastest Flight Available" << endl;
				}
				cout << "Are these Options Correct?" << endl;
				cout << "1. Yes" << endl;
				cout << "2. No, Try Again" << endl;

				cin >> selection;

				if (selection == 1) 
				{
					good = true;

					cout << "Selection Accepted" << endl; sortMethod = 1;
				}
				else 
				{

					cout << "Invalid Selection" << endl; 
				}
			}

			//Use shortest path algorithm here
			//destination is the string variable for destination
			//desiredDepartureDate is the Date_Time for their desired departure time
			//luggage is the int for their amount of luggage
			//sortMethod is 1 if we want the cheapest flight and 2 if we want the fastest flight

		}
		else if (selection == 3)
		{
			//Memory handling

			//// Clears all of the content of the vectors
			hubVector.clear();
			flightVector.clear();

			//// Effectively frees memory that the vectors were using
			vector<Hub>().swap(hubVector);
			vector<Flight>().swap(flightVector);

			// Destructs the hubList object before closing the program
			hubList.HubList::~HubList();

			return 0;
		}
		else
		{
			cout << "Invalid Selection" << endl; 
			good = false; 
		}
	}
}
