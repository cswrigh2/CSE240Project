//**********************************************************************************************************
// Programmed by:	Justin Lucker, Connor Wright, and Jared Adamson
// File:			FlightList.h
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
#ifndef _FLIGHTLIST
#define _FLIGHTLIST

#include <string>
#include <stdlib.h>
#include <iostream>
#include "HubNode.h"
#include "FlightNode.h"
#include "Hub.h"

#pragma once

using namespace std;

class FlightList
{
	FlightNode* head;

public:
	FlightList();
	~FlightList();

	void insertFlight(Flight nodeInfo);
	void printFlightList();
	FlightNode* getHeadFlight();
};
#endif
