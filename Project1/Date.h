#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int daysVus[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	bool VusokosnuiRik(int a);
	bool CheckCorrect(int day, int month, int year);
public:
	Date();
	Date(int count);
	Date(int day, int month, int year);
	void CheckDatePlus();
	void CheckDateMinys();
	//int NumberOfDayInMonth(int a);
	Date& operator+=(int day);
	Date& operator-=(int day);
	Date& operator()(int day);
	Date& operator()(int month, int day);
	Date& operator()(int year, int month, int day);
	void ShowDate();
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
	int GetDay()const;
	int GetMonth()const;
	int GetYear()const;

	friend bool operator<(const Date& other, const Date& other2);
	friend bool operator>(const Date& other, const Date& other2);
	friend bool operator==(const Date& other, const Date& other2);
	friend bool operator!=(const Date& other, const Date& other2);
	friend ofstream& operator<<(ofstream& of, Date & other);
	friend ifstream& operator>>(ifstream& in, Date & other);

	~Date();
};

void operator++(Date&ths);
void operator--(Date&ths);

ofstream& operator<<(ofstream& of, Date & other)
{
	of << other.day << endl;
	of << other.month << endl;
	of << other.year << endl;
	return of;
}

ifstream& operator>>(ifstream& in, Date & other)
{
	in >> other.day;
	in >> other.month;
	in >> other.year;
	return in;
}

//void operator++(Date&ths);
//void operator--(Date&ths);



//Date & operator++(Date&ths, int)
//{
//	Date temp = *this;
//	this->day++;
//	CheckDatePlus();
//	return temp;
//}
//
//Date & operator--(Date&ths, int)
//{
//	Date temp = *this;
//	this->day--;
//	CheckDateMinys();
//	return temp;
//}