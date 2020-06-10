#include "Date.h"

Date::Date() : day(1), month(1), year(0) {}

Date::Date(int count) : Date()
{
	if (CheckCorrect(count, count, count))
	{
		this->day = count;
		this->month = count;    
		this->year = count;
		CheckDatePlus();
	}
}

Date::Date(int day, int month, int year) : Date()
{
	if (CheckCorrect(day, month, year))
	{
		this->day = day;
		this->month = month;    
		this->year = year;
		CheckDatePlus();
	}
}

/*
while (this->month > 12 || this->day > NumberOfDayInMonth(this->month))
	{
		while (this->month > 12)
		{
			this->year++;
			this->month -= 12;
		}
		while (VusokosnuiRik(this->year) == true && this->day > NumberOfDayInMonth(this->month))
		{
			if (this->month == 2)
			{
				this->day -= 29;
				this->month++;
			}
			else
			{
				this->day -= NumberOfDayInMonth(this->month);
				this->month++;
			}
		}
		while (this->day > NumberOfDayInMonth(this->month))
		{
			this->day -= NumberOfDayInMonth(this->month);
			this->month++;
		}
	}
*/

bool Date::CheckCorrect(int day, int month, int year)
{
	if (day < 1) return false;
	if (month < 1)return false;
	if (year < 0) return false;
	return true;
}

void Date::CheckDatePlus()
{
	while (this->month > 12 || this->day > days[this->month])
	{
		while (this->month > 12)
		{
			this->year++;
			this->month -= 12;
		}
		while (this->day > 365)
		{
			if (VusokosnuiRik(this->year) == true)
			{
				this->day -= 366;
				this->year++;
			}
			else
			{
				this->day -= 365;
				this->year++;
			}
		}
		while (this->day > days[this->month])
		{
			if (VusokosnuiRik(this->year))
			{
				this->day -= daysVus[this->month];
				this->month++;
			}
			else
			{
				this->day -= days[this->month];
				this->month++;
			}
		}
	}
}

void Date::CheckDateMinys()
{
	while (this->month < 1 || this->day < 1)
	{
		while (this->month < 1)
		{
			this->year--;
			this->month += 12;
		}
		while (this->day < 1)
		{
			if (VusokosnuiRik(this->year) == true)
			{
				this->month--;
				this->day += daysVus[this->month];
			}
			else
			{
				this->month--;
				this->day += days[this->month];
			}
			if (this->month < 1)
			{
				this->year--;
				this->month += 12;
			}
		}
	}
}

bool Date::VusokosnuiRik(int a)
{
	bool b = false;
	if (a % 4 == 0)
	{
		if (a % 100 != 0)
		{
			b = true;
		}
		else
		{
			if (a % 400 == 0)
			{
				b = true;
			}
			else
			{
				b = false;
			}
		}
	}
	else
	{
		b = false;
	}
	return b;
}

Date& Date::operator+=(int day)
{
	this->day += day;
	CheckDatePlus();
	return *this;
}

Date& Date::operator-=(int day)
{
	this->day -= day;
	CheckDateMinys();
	return *this;
}

Date& Date::operator()(int day)
{
	this->day += day;
	CheckDatePlus();
	return *this;
}
Date& Date::operator()(int month, int day)
{
	this->day += day;
	this->month += month;
	CheckDatePlus();
	return *this;
}
Date& Date::operator()(int year, int month, int day)
{
	this->day += day;
	this->month += month;
	this->year += year;
	CheckDatePlus();
	return *this;
}

void Date::ShowDate()
{
	cout << day << " : " << month << " : " << year << endl;
}

void Date::SetDay(int day)
{
	this->day = day;
}

void Date::SetMonth(int month)
{
	this->month = month;
}

void Date::SetYear(int year)
{
	this->year = year;
}

int Date::GetDay()const
{
	return this->day;
}

int Date::GetMonth()const
{
	return this->month;
}

int Date::GetYear()const
{
	return this->year;
}

Date::~Date()
{
}

bool operator>(const Date& other, const Date& other2)
{
	if (other.year != other2.year)
	{
		if (other.year > other2.year)
		{
			return true;
		}
		else return false;
	}
	else if (other.year != other2.month)
	{
		if (other.year > other2.month)
		{
			return true;
		}
		else return false;
	}
	else if (other.year != other2.day)
	{
		if (other.year > other2.day)
		{
			return true;
		}
		else return false;
	}
	else return false;
}

bool operator<(const Date& other, const Date& other2)
{
	if (other.year != other2.year)
	{
		if (other.year < other2.year)
		{
			return true;
		}
		else return false;
	}
	else if (other.year != other2.month)
	{
		if (other.year < other2.month)
		{
			return true;
		}
		else return false;
	}
	else if (other.year != other2.day)
	{
		if (other.year < other2.day)
		{
			return true;
		}
		else return false;
	}
	else return false;
}

bool operator==(const Date& other, const Date& other2)
{
	return (other.year == other2.year && other.year == other2.month && other.year == other2.day);
}

bool operator!=(const Date& other, const Date& other2)
{
	return (other.year != other2.year || other.year != other2.month || other.year != other2.day);
}

void operator++(Date&ths)
{
	int a = ths.GetDay();
	ths.SetDay(++a);
	ths.CheckDatePlus();
}

void operator--(Date&ths)
{
	int a = ths.GetDay();
	ths.SetDay(--a);
	ths.CheckDateMinys();
}
