#ifndef LECTURE_H
#define LECTURE_H
#include <string>

// Global Constants
const int MONDAY	= 0;
const int TUESDAY	= 1;
const int WEDNESDAY = 2;
const int THURSDAY	= 3;
const int FRIDAY	= 4;
const std::string DAY[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

class Lecture
{
public:
	// Constructor
	Lecture();
	Lecture(std::string title, std::string lecturer, double unit);

	// Initializer Functions
	void setTitle(std::string title);
	void setLecturer(std::string lecturer);
	void setUnit(double unit);
	void setSchedule(int day, std::string time, std::string location, double length);
	void setTime(int day, std::string time);
	void setLocation(int day, std::string location);
	void setLength(int day, double length);

	// Accessor Functions
	std::string getTitle();
	std::string getLecturer();
	double getUnit();
	std::string getTime(int day);
	std::string getLocation(int day);
	double getLength(int day);

private:
	std::string m_title;
	std::string m_lecturer;
	double m_unit;

	struct schedule {
		std::string m_time = "Uninitialized Time";
		std::string m_location = "Uninitialized Location";
		double m_length = -1;
	} m_schedule[5];
	
};

#endif