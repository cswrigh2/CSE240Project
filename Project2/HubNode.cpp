//**********************************************************************************************************
// Programmed by:	Justin Lucker, Connor Wright, and Jared Adamson
// File:			HubNode.cpp
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
#include "HubNode.h"
#include "Hub.h"
#include <iostream>

using namespace std;

// Constructor for Object
HubNode::HubNode()
{

}
// Destructor for Object
HubNode::~HubNode()
{

}
// Mutator Functions for object
void HubNode::setAirportName(string airportName)			{ this->airportName			= airportName;			}
void HubNode::setAirportLocation(string airportLocation)	{ this->airportLocation		= airportLocation;		}
void HubNode::setHeadFlight(FlightNode* headFlight)			{ this->headFlight			= headFlight;			}
void HubNode::setNext(HubNode* nextNode)					{ this->next				= nextNode;				}
void HubNode::setInfo(Hub newNode)							
{
	setAirportName(newNode.getAirport());
	setAirportLocation(newNode.getLocation());
	headFlight = NULL;
}

// Accessor Functions for object
FlightNode* HubNode::getHeadFlight()						{ return headFlight;								}
HubNode* HubNode::getNext()									{ return next;										}

// Prints the characteristic information about object
void HubNode::printInfo()
{
	cout <<"*******************************************************************************" << endl;
	cout << airportName + " " + "(" + airportLocation + ")" << endl;
	cout << "*******************************************************************************" << endl;
}



