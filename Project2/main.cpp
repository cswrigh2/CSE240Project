//**********************************************************************************************************
// Programmed by:	Justin Lucker, Connor Wright, and Jared Adamson
// File:			main.cpp
// Program:			CSE240Project
// Date:			03/18/2014
// Date Modified:	03/22/2014
// Class:			CSE 240
// Email:			jlucker@asu.edu
// Description:		This program takes two .csv files as input and populates two interconnected linked lists 
//					with the data contained within the .csv files.  The data is initially loaded into two
//					vectors called hubVector and flightVector which act as buffers and are deleted after
//					the linked list is created. The user is then able to print a list of each airport with 
//					a list of its departing flights below it.
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
	
	// Debug menu creates and then displays the linked list 
	cout << "Project Debug Menu" << endl;
	cout << "Please Make a Selection" << endl;
	cout << "1. To Display Flights by their Departure Airports" << endl;
	cout << "2. To Quit" << endl;
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
	else
	{
		return 0;
	}
}
