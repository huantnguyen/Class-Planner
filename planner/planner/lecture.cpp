#include <iostream>
#include "lecture.h"
using namespace std;

// Constructor
Lecture::Lecture()
{
	setTitle("Uninitialized Class");
	setLecturer("Uninitialized Lecturer");
	setUnit(-1);
}

Lecture::Lecture(string title, string lecturer, double unit)
{
	setTitle(title);
	setLecturer(lecturer);
	setUnit(unit);
}

// Initializer Functions
void Lecture::setTitle(string title)
{
	m_title = title;
}
void Lecture::setLecturer(string lecturer)
{
	m_lecturer = lecturer;
}
void Lecture::setUnit(double unit)
{
	m_unit = unit;
}
void Lecture::setSchedule(int day, std::string time, std::string location, double length)
{
	setTime(day, time);
	setLocation(day, location);
	setLength(day, length);
}
void Lecture::setTime(int day, string time)
{
	m_schedule[day].m_time = time;
}
void Lecture::setLocation(int day, string location)
{
	m_schedule[day].m_location = location;
}
void Lecture::setLength(int day, double length)
{
	m_schedule[day].m_length = length;
}

// Accessor Functions
string Lecture::getTitle()
{
	return m_title;
}
string Lecture::getLecturer()
{
	return m_lecturer;
}
double Lecture::getUnit()
{
	return m_unit;
}
string Lecture::getTime(int day)
{
	return m_schedule[day].m_time;
}
string Lecture::getLocation(int day)
{
	return m_schedule[day].m_location;
}
double Lecture::getLength(int day)
{
	return m_schedule[day].m_length;
}