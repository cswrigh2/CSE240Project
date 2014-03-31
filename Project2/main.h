//**********************************************************************************************************
// Programmed by:	Justin Lucker, Connor Wright, and Jared Adamson
// File:			main.h
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
#ifndef _MAIN
#define _MAIN
#include <iostream>
#include <fstream>
#include <string>
#include <xstring>
#include <vector>
#include "Hub.h"
#include "Flight.h"
#include "HubNode.h"
#include "HubList.h"
#include "FlightList.h"
#include "ProjectIO.h"

#pragma once

using namespace std;

string hubFileName		= "Hub.csv";
string flightFileName	= "Flight.csv";
string flightNumber;
string flightPrice;
string flightSource;
string flightDestination;
string flightDeparture;
string flightDuration;
string flightCompany;

int main();


#endif