//**********************************************************************************************************
// Programmed by:	Justin Lucker, Connor Wright, and Jared Adamson
// File:			FlightList.cpp
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
#include "FlightList.h"

// Default Constructor
FlightList::FlightList()
{

}

// Destructor
FlightList::~FlightList()
{
	//FlightNode* current = new FlightNode();
	//FlightNode* next    = new FlightNode();
	//current = head;
	//while (current->getNext() != NULL)
	//{
	//	next = current->getNext();
	//	delete current;
	//	current = next;
	//}
	////delete current;
	////delete next;
}

// Adds a new node to a linked list composed of flight objects
void FlightList::insertFlight(Flight nodeInfo)
{
	FlightNode* newNode = new FlightNode();
	newNode->setInfo(nodeInfo);
	newNode->setNext(NULL);

	FlightNode *temp = head;

	if (temp != NULL)
	{
		while (temp->getNext() != NULL)
		{
			temp = temp->getNext();
		}
		temp->setNext(newNode);
	}
	else
	{
		head = newNode;
	}
}

// Prints the contents of a linked list composed of flight objects
void FlightList::printFlightList()
{
	FlightNode *temp = head;

	if (temp == NULL)
	{
		cout << "FlightList is Empty" << endl;
		return;
	}
	else if (temp->getNext() == NULL)
	{
		temp->printInfo();
	}
	else
	{
		do
		{
			temp->printInfo();
			temp = temp->getNext();
		} while (temp != NULL);
	}
}

FlightNode* FlightList::getHeadFlight()
{
	return head;
}