//**********************************************************************************************************
// Programmed by:	Justin Lucker, Connor Wright, and Jared Adamson
// File:			Hub.cpp
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
#include "Hub.h"
#include <stdlib.h> 
#include <iostream>

using namespace std;

// Default Constructor
Hub::Hub()
{
	
}

// Constructor
Hub::Hub(string airportName, string airportLocation)
{
	setAirport(airportName);
	setLocation(airportLocation);
}

// Mutator Functions for object
void Hub::setAirport(string airportName)		{ this->airportName = airportName;			}
void Hub::setLocation(string airportLocation)	{ this->airportLocation = airportLocation;	}

// Accessor Functions for object
string Hub::getAirport()						{ return airportName;						}
string Hub::getLocation()						{ return airportLocation;					}

// Prints the characteristic information about object
void Hub::printInfo()
{
	cout << airportName << "\t ";
	cout << airportLocation << endl;
}

Hub::~Hub()
{

}

