//**********************************************************************************************************
// Programmed by:	Justin Lucker, Connor Wright, and Jared Adamson
// File:			Flight.cpp
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
#include "Flight.h"
#include<string>
#include <stdlib.h>
#include <iostream>
#include "Date_Time.h"

using namespace std;

Flight::Flight()
{
	// Default Constructor
}

Flight::~Flight()
{

}

Flight::Flight(string flightNumber, string flightPrice, string flightSource, string flightDestination,
	Date_Time flightDeparture, string flightDuration, string flightCompany)
{
	setFlightNumber(flightNumber);
	setFlightPrice(flightPrice);
	setFlightSource(flightSource);
	setFlightDestination(flightDestination);
	setFlightDeparture(flightDeparture);
	setFlightDuration(flightDuration);
	setFlightCompany(flightCompany);
}

void Flight::setFlightNumber(string flightNumber)			{ this->flightNumber = flightNumber;			}
void Flight::setFlightPrice(string flightPrice)				{ this->flightPrice = flightPrice;				}
void Flight::setFlightSource(string flightSource)			{ this->flightSource = flightSource;			}
void Flight::setFlightDestination(string flightDestination)	{ this->flightDestination = flightDestination;	}
void Flight::setFlightDeparture(Date_Time flightDeparture)	{ this->flightDeparture = flightDeparture;		}
void Flight::setFlightDuration(string flightDuration)		{ this->flightDuration = flightDuration;		}
void Flight::setFlightCompany(string flightCompany)			{ this->flightCompany = flightCompany;			}

std::string Flight::getFlightNumber()						{ return flightNumber;							}
std::string Flight::getFlightPrice()						{ return flightPrice;							}
std::string Flight::getFlightSource()						{ return flightSource;							}
std::string Flight::getFlightDestination()					{ return flightDestination;						}
std::string Flight::getFlightDuration()						{ return flightDuration;						}
std::string Flight::getFlightCompany()						{ return flightCompany;							}
Date_Time Flight::getFlightDeparture()						{ return flightDeparture;						}

void Flight::printInfo()
{
	cout << flightNumber					<< "\n ";
	cout << flightPrice						<< "\n ";
	cout << flightSource					<< "\n";
	cout << flightDestination				<< "\n ";
	cout << flightDeparture.toString()      << "\n ";
	cout << flightDuration					<< "\n";
	cout << flightCompany					<< endl;
}


