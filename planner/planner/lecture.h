#ifndef LECTURE_H
#define LECUTRE_H
#include <string>



class Lecture
{
public:
	void setUnit(double unit) { m_unit = unit; }
	void setLecturer(std::string lecturer) { m_lecturer = lecturer; }
	void setTitle(std::string title) { m_title = title; }
	void setTime(int day, std::string time) { m_schedule[day].m_time = time; }
	void setLocation(int day, std::string location) { m_schedule[day].m_location = location; }
	void setLength(int day, double length) { m_schedule[day].m_length = length; }

	double getUnit() { return m_unit; }
	std::string getLecturer() { return m_lecturer; }
	std::string getTitle() { return m_title; }
	std::string getTime(int day) { return m_schedule[day].m_time; }
	std::string getLocation(int day) { return m_schedule[day].m_location; }
	double getLength(int day) { return m_schedule[day].m_length; }

private:
	double m_unit;
	std::string m_lecturer;
	std::string m_title;

	struct schedule {
		std::string m_time;
		std::string m_location;
		double m_length;
	} m_schedule[5];
	
};

#endif