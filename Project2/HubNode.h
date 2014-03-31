//**********************************************************************************************************
// Programmed by:	Justin Lucker, Connor Wright, and Jared Adamson
// File:			HubNode.h
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
#ifndef _HUBNODE
#define _HUBNODE

#include "Hub.h"
#include "FlightNode.h"
#include <string>
#pragma once

using namespace std;

class HubNode
{
private:
	HubNode* next;
	FlightNode* headFlight;
	string airportName;
	string airportLocation;
public:
	HubNode();
	~HubNode();
	void setAirportName(string name); 
	void setAirportLocation(string location);
	void setInfo(Hub newNode);
	void setNext(HubNode* next);
	void setHeadFlight(FlightNode* headFlight);
	void printInfo();
	string getAirportName();
	string getAirportLocation();
	FlightNode* getHeadFlight();
	HubNode* getNext();
};
#endif
