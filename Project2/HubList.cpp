//**********************************************************************************************************
// Programmed by:	Justin Lucker, Connor Wright, and Jared Adamson
// File:			HubList.cpp
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
#include "HubList.h"

using namespace std;

// Default Constructor
HubList::HubList()
{

}

// Destructor
HubList::~HubList()
{
	//HubNode* current = new HubNode();
	//HubNode* next    = new HubNode();
	//current = head;
	//while (current->getNext() != NULL)
	//{
	//	next = current->getNext();
	//	delete current;
	//	current = next;
	//}
	//delete current;
	//delete next;
}

// Adds a new node to a linked list composed of hub objects
void HubList::insertHub(Hub nodeInfo, FlightNode* headFlight)
{
	HubNode* newNode = new HubNode();
	newNode->setInfo(nodeInfo);
	newNode->setNext(NULL);
	newNode->setHeadFlight(headFlight);

	HubNode *temp = head;

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
// Prints the contents of a linked list composed of hub objects
void HubList::printHubList()
{
	HubNode *temp = head;

	if (temp == NULL)
	{
		cout << "HubList is Empty" << endl;
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
		}   while (temp != NULL);
	}
}

// Prints each hub followed by its departing flights
void HubList::printHubFlights()
{
	HubNode *temp = head;
	FlightNode *tempFlight = temp->getHeadFlight();

	while (temp != NULL)
	{
		temp->printInfo(); 
		tempFlight = temp->getHeadFlight();

		while (tempFlight != NULL)
		{
			tempFlight->printInfo();

			if (tempFlight->getNext() == NULL)
			{
				break;
			}
			else
			{
				tempFlight = tempFlight->getNext();
			}
		}
		if (temp->getNext() == NULL)
		{
			break;
		}
		else
		{
			temp = temp->getNext();
		}
	}
}