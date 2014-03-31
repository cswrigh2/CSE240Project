//**********************************************************************************************************
// Programmed by:	Justin Lucker, Connor Wright, and Jared Adamson
// File:			Date_Time.cpp
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
#include "Date_Time.h"
#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

// Default Constructor
Date_Time::Date_Time()
{

}

// Destructor
Date_Time::~Date_Time()
{

}

// Constructor
Date_Time::Date_Time(string departure)
{
	int count = 0;
	string tempDeparture;

	if (departure.length() == 16)
	{
		minutesString = departure.substr(0, 2);
		hoursString   = departure.substr(3, 2);
		dayString     = departure.substr(6, 2);
		monthString   = departure.substr(9, 2);
		yearString    = departure.substr(12,4);

		minutes       = atoi(minutesString.c_str());
		hours         = atoi(hoursString.c_str());
		day           = atoi(dayString.c_str());
		month         = atoi(monthString.c_str());
		year          = atoi(yearString.c_str());
	}
	// Just in case the departure string parameter is not in the specified format
	// this will change it into the specified format and set the Date_Time objects's
	// variable equal to that.
	// example:
	// Spcified format:  15/08/15/12/2013 or 15/08/03/03/2013 with each value represented with 2 integers (and the year which is 4)
	// Different format: 15/08/3/3/12/2013 the month and day are represented by only one digit
	// The Fix:  add a zero in front of any single digit value.
	else
	{
		for (int i = 0; i < departure.length(); i++)
		{
			if (departure[i] != '/' && departure[i + 1] != '/')
			{
				tempDeparture = tempDeparture + departure[i] + departure[i + 1];
				i = i + 1;
			}
			else if (departure[i] == '/')
			{
				tempDeparture = tempDeparture + departure[i];
			}
			else if (departure[i] != '/' && departure[i + 1] == '/')
			{
				tempDeparture = tempDeparture + "0" + departure[i];
			}
		}

		minutesString	= tempDeparture.substr(0, 2);
		hoursString		= tempDeparture.substr(3, 2);
		dayString		= tempDeparture.substr(6, 2);
		monthString		= tempDeparture.substr(9, 2);
		yearString		= tempDeparture.substr(12, 4);

		minutes			= atoi(minutesString.c_str());
		hours			= atoi(hoursString.c_str());
		day				= atoi(dayString.c_str());
		month			= atoi(monthString.c_str());
		year			= atoi(yearString.c_str());

	}	
}
// Function that adds minutes to the Date_Time object
// This will probably be used for implementing the delays
void Date_Time::addMiutes(int min)
{
	if (minutes + min < 60)
	{
		minutes = minutes + min;
		minutesString = std::to_string(minutes);
	}
	else
	{
		if (minutes + min > 60)
		{
			minutes = (minutes + min) % 60;
			minutesString = std::to_string(minutes);

			hours = hours + ((minutes + min) / 60);

			if (hours + ((minutes + min) / 60) > 24)
			{
				hours = (hours + ((minutes + min) / 60)) % 24;
				hoursString = std::to_string(hours);

				day = (day + (hours + ((minutes + min) / 60))) / 24;

				if (day > getDays(month))
				{
					day = (day + (hours + ((minutes + min) / 60)) % 24) % getDays(month);
					dayString = std::to_string(day);

					month = (month + (day + (hours + ((minutes + min) / 60))) / 24) / 12;

					if (month > 12)
					{
						month = (month + (day + (hours + ((minutes + min) / 60))) / 24) % 12;
						monthString = std::to_string(month);
						year = year + 1;
						yearString = std::to_string(year);
					}
				}
			}
		}
	}
}

// Returns formatted date string
string Date_Time::toString()
{
	string date = monthString + "/" + dayString + "/" + yearString + " " + hoursString + ":" + minutesString;
	return date;
}

int Date_Time::getDays(int month)
{
	int numberOfDays;
	int monthInput;

	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		numberOfDays = 30;
	}
	else if (month == 2)
	{
		if (isALeapYear(year) == true)
		{
			numberOfDays = 28;
		}
		else
		{
			numberOfDays = 29;
		}
	}
	else
	{
		numberOfDays = 31;
	}
	return numberOfDays;
}

bool Date_Time::isALeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	else
		return false;
}
