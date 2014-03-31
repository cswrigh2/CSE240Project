//**********************************************************************************************************
// Programmed by:	Justin Lucker, Connor Wright, and Jared Adamson
// File:			Date_Time.h
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
#ifndef _DATE_TIME
#define _DATE_TIME

#include <string>
#include <stdlib.h>

#pragma once

using namespace std;

class Date_Time
{
public:
	int minutes;
	int hours;
	int day;
	int month;
	int year;

	string minutesString;
	string hoursString;
	string dayString;
	string monthString;
	string yearString;
	string date;

	Date_Time();
	~Date_Time();
	Date_Time(string departure);
	void addMiutes(int min);
	string toString();
	int getDays(int month);
	bool isALeapYear(int year);
	void deleteDate();
};
#endif
