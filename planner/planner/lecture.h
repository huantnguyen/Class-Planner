#ifndef LECTURE_H
#define LECTURE_H
#include <string>

// Define Days
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
	Lecture()
	{
		setTitle("Uninitialized Class");
		setLecturer("Uninitialized Lecturer");
		setUnit(-1);
	}

	Lecture(std::string title, std::string lecturer, double unit)
	{
		setTitle(title);
		setLecturer(lecturer);
		setUnit(unit);
	}

	// Initializer Functions
	void setTitle(std::string title) { m_title = title; }
	void setLecturer(std::string lecturer) { m_lecturer = lecturer; }
	void setUnit(double unit) { m_unit = unit; }
	void setTime(int day, std::string time) { m_schedule[day].m_time = time; }
	void setLocation(int day, std::string location) { m_schedule[day].m_location = location; }
	void setLength(int day, double length) { m_schedule[day].m_length = length; }

	// Accessor Functions
	std::string getTitle() { return m_title; }
	std::string getLecturer() { return m_lecturer; }
	double getUnit() { return m_unit; }
	std::string getTime(int day) { return m_schedule[day].m_time; }
	std::string getLocation(int day) { return m_schedule[day].m_location; }
	double getLength(int day) { return m_schedule[day].m_length; }

private:
	std::string m_title;
	std::string m_lecturer;
	double m_unit;

	struct schedule {
		std::string m_time;
		std::string m_location;
		double m_length = -1;
	} m_schedule[5];
	
};

#endif