#include <iostream>
#include <iomanip>
#include <string>
#include "lecture.h"
#include "json.hpp"
#include <fstream>

using namespace std;

int main()
{
	std::ifstream ifs;
	ifs.open("courses.JSON");
	auto courses = nlohmann::json::parse(ifs);
	ifs.close();

	string s = courses[0]["major"];
	cout << s << endl;

	Lecture Lec1;

	// Initialize CS35L Lecture
	Lec1.setTitle("CS35L");
	Lec1.setLecturer("Eggert");
	Lec1.setUnit(2);
	for (int day = MONDAY; day <= FRIDAY; day++)
	{
		switch (day)
		{
		case MONDAY:
			Lec1.setTime(day, "4:00pm");
			Lec1.setLocation(day, "Boelter Hall 3464");
			Lec1.setLength(day, 1.5);
			break;
		case WEDNESDAY:
			Lec1.setSchedule(day, "4:00pm", "Boelter Hall 3464", 1.5);
			break;
		case FRIDAY:
			Lec1.setTime(day, "4:00pm");
			Lec1.setLocation(day, "Young Hall CS76");
			Lec1.setLength(day, 1.5);
			break;
		}
	}

	// Report CS35L Lecture Info
	cout << "=== Class Info ===" << endl;
	cout << setw(12) << left << "Class:" << Lec1.getTitle() << endl;
	cout << setw(12) << left << "Lecturer:" << Lec1.getLecturer() << endl;
	cout << setw(12) << left << "Units:" << Lec1.getUnit() << endl;
	cout << "==== Schedule ====" << endl;
	for (int day = MONDAY; day <= FRIDAY; day++)
	{
		cout << setw(12) << left << DAY[day] + ":";
		if (Lec1.getLength(day) < 0)
		{
			cout << "No class today!" << endl;
		}
		else
		{
			cout << "Lecture at " << Lec1.getTime(day);
			cout << " at " << Lec1.getLocation(day);
			cout << " for " << Lec1.getLength(day) << " hours." << endl;
		}
	}
}