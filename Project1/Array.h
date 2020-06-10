#pragma once
#include <iostream>
#include <ctime>

using namespace std;

class Array
{
private:
	long *arr;
	int size;
	bool Check()const;
	bool CheckIndex(const int _index)const;
public:
	Array();
	Array(int size);
	Array(const Array& other);
	void FillArrRandom();
	void FillArrByKeyBoard();
	void FillArrDefault();
	void ShowArr()const;
	void AddElementToArr(long element);
	void DeleteElementByIndex(int index);
	void SortArr();
	long GetMin();
	long GetMax();
	double GetavgValue();
	Array operator++();
	Array operator++(int);
	Array operator--();
	Array operator--(int);
	Array operator-();
	Array& operator=(const Array& other);
	explicit operator long()const;
	Array operator()(int count);
	int operator[](int count);
	~Array();
};

