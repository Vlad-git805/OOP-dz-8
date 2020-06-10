#include "Array.h"

Array::Array()
{
	this->size = 0;
	arr = nullptr;
}

Array::Array(int size)
{
	this->size = size;
	this->arr = new long[size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = 0;
	}
}

Array::Array(const Array& other)
{
	this->size = other.size;
	this->arr = new long[this->size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = other.arr[i];
	}
}

bool Array::Check()const
{
	if (size == 0) return false;
	else return true;
}

bool Array::CheckIndex(int _index)const
{
	if (_index < 0 || _index >= this->size) return false;
	else return true;
}

void Array::FillArrRandom()
{
	if (Check())
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 50;
		}
	}
}

void Array::FillArrByKeyBoard()
{
	if (Check())
	{
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
	}
}

void Array::FillArrDefault()
{
	if (Check())
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = i;
		}
	}
}

void Array::ShowArr()const
{
	if (Check())
	{
		cout << "arr[" << size << "] = ";
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
	}
	else cout << "There are no elements in array" << endl;
	cout << endl;
}

void Array::AddElementToArr(long element)
{
	long *temp = new long[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = element;
	this->size++;
	delete[]arr;
	arr = temp;
}

void Array::DeleteElementByIndex(int index)
{
	if (Check())
	{
		if (CheckIndex(index))
		{
			long *temp = new long[size - 1];
			for (int i = 0, j = 0; i < size; i++)
			{
				if (i != index)
				{
					temp[j] = arr[i];
					j++;
				}
			}
			delete[]arr;
			this->size--;
			arr = temp;
		}
	}
}

void Array::SortArr()
{
	if (Check())
	{
		long temp = 0;
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
}

long Array::GetMin()
{
	if (Check())
	{
		int min = this->arr[0];
		for (int i = 0; i < size; i++)
		{
			if (min < arr[i])
			{
				min = arr[i];
			}
		}
		return min;
	}
}

long Array::GetMax()
{
	if (Check())
	{
		int max = this->arr[0];
		for (int i = 0; i < size; i++)
		{
			if (max > arr[i])
			{
				max = arr[i];
			}
		}
		return max;
	}
}

double Array::GetavgValue()
{
	if (Check())
	{
		double avg = 0;
		for (int i = 0; i < size; i++)
		{
			avg += arr[i];
		}
		return avg /= size;
	}
}

Array Array::operator++()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] += 1;
	}
	return *this;
}

Array Array::operator++(int)
{
	Array temp = *this;
	for (int i = 0; i < size; i++)
	{
		arr[i] += 1;
	}
	return temp;
}

Array Array::operator--()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] -= 1;
	}
	return *this;
}

Array Array::operator--(int)
{
	Array temp = *this;
	for (int i = 0; i < size; i++)
	{
		arr[i] -= 1;
	}
	return temp;
}

Array Array::operator-()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] *= -1;
	}
	return *this;
}

Array & Array::operator=(const Array & other)
{
	if (this == &other)
		return *this;

	if (arr != nullptr)
		delete[]arr;

	size = other.size;
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
	return *this;
}

Array::operator long() const
{
	long sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

Array Array::operator()(int count)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] += count;
	}
	return *this;
}

int Array::operator[](int count)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] = count)
		{
			return i;
		}
	}
}

Array::~Array()
{
	if (arr != nullptr)
		delete[]arr;
}