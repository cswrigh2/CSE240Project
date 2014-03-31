//**********************************************************************************************************
// Programmed by:	Justin Lucker, Connor Wright, and Jared Adamson
// File:			Hub.h
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
#ifndef _HUB
#define _HUB

#include <string>
#include <stdlib.h>
#include "FlightNode.h"
#pragma warning

using namespace std;



class Hub
{
private:
	string airportName;
	string airportLocation;

public:
	Hub();
	Hub(string airportName, string airportLocation);
	~Hub();
	void setAirport(string airportName);
	void setLocation(string airportLocation);
	void printInfo();
	string getAirport();
	string getLocation();

};
#endif
