//**********************************************************************************************************
// Programmed by:	Justin Lucker, Connor Wright, and Jared Adamson
// File:			FlightNode.h
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
#ifndef _FLIGHTNODE
#define _FLIGHTNODE

#include <string>
#include <stdlib.h>
#include "Flight.h"
#include "Date_Time.h"

#pragma once

using namespace std;

class FlightNode
{
	std::string flightNumber;
	std::string flightPrice;
	std::string flightSource;
	std::string flightDestination;
	std::string flightDuration;
	std::string flightCompany;
	Date_Time   flightDeparture;

	FlightNode* next;
	FlightNode* head;
public:
	
	FlightNode();
	FlightNode(Flight newNode);
	~FlightNode();

	void setFlightNumber(std::string flightNumber);
	void setFlightPrice(std::string flightPrice);
	void setFlightSource(std::string flightSource);
	void setFlightDestination(std::string flightDestination);
	void setFlightDeparture(Date_Time flightDeparture);
	void setFlightDuration(std::string flightDuration);
	void setFlightCompany(std::string flightCompany);
	void setNext(FlightNode* next);

	std::string getFlightNumber();
	std::string getFlightPrice();
	std::string getFlightSource();
	std::string getFlightDestination();
	std::string getFlightDuration();
	std::string getFlightCompany();
	Date_Time   getFlightDeparture();
	FlightNode*  getNext();

	void setInfo(Flight newNode);
	void printInfo();
};
#endif
