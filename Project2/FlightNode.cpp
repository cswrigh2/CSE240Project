//**********************************************************************************************************
// Programmed by:	Justin Lucker, Connor Wright, and Jared Adamson
// File:			FlightNode.cpp
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
#include "FlightNode.h"
#include"Flight.h"
#include <iostream>
// Default Constructor
FlightNode::FlightNode()
{

}
// Constructor that takes an object of type flight
FlightNode::FlightNode(Flight newNode)
{
	
}

// Destructor for Object
FlightNode::~FlightNode()
{

}
// Mutator Functions for object
void FlightNode::setFlightNumber(string flightNumber)			{ this->flightNumber		= flightNumber;			}
void FlightNode::setFlightPrice(string flightPrice)				{ this->flightPrice			= flightPrice;			}
void FlightNode::setFlightSource(string flightSource)			{ this->flightSource		= flightSource;			}
void FlightNode::setFlightDestination(string flightDestination)	{ this->flightDestination	= flightDestination;	}
void FlightNode::setFlightDeparture(Date_Time flightDeparture)	{ this->flightDeparture		= flightDeparture;		}
void FlightNode::setFlightDuration(string flightDuration)		{ this->flightDuration		= flightDuration;		}
void FlightNode::setFlightCompany(string flightCompany)			{ this->flightCompany		= flightCompany;		}
void FlightNode::setNext(FlightNode* next)						{ this->next				= next;					} 
void FlightNode::setInfo(Flight newNode)
{
	setFlightNumber(newNode.getFlightNumber());
	setFlightPrice(newNode.getFlightPrice());
	setFlightSource(newNode.getFlightSource());
	setFlightDestination(newNode.getFlightDestination());
	setFlightDeparture(newNode.getFlightDeparture());
	setFlightDuration(newNode.getFlightDuration());
	setFlightCompany(newNode.getFlightCompany());
	setNext(NULL);
}

// Accessor Functions for object
string FlightNode::getFlightNumber()							{ return flightNumber;								}
string FlightNode::getFlightPrice()								{ return flightPrice;								}
string FlightNode::getFlightSource()							{ return flightSource;								}
string FlightNode::getFlightDestination()						{ return flightDestination;							}
string FlightNode::getFlightDuration()							{ return flightDuration;							}
string FlightNode::getFlightCompany()							{ return flightCompany;								}
Date_Time FlightNode::getFlightDeparture()						{ return flightDeparture;							}
FlightNode* FlightNode::getNext()								{ return next;										}

// Prints the characteristic information about object
void FlightNode::printInfo()
{
	cout << "FLIGHT: " + flightNumber + " " +"AIRLINE: " + flightCompany + " " + "DEPARTURE: " + flightDeparture.toString() +" " + "DURATION: " + flightDuration << endl;
	cout << "SOURCE: " + flightSource << endl;
	cout << "DESTINATION: " + flightDestination << endl;
	cout << " " << endl;
}


