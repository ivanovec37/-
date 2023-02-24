#include<iostream>
#include<algorithm>
#include "WorkWithList.h"
using namespace std;

void FillElement(Element& element)
{
	cout << " Название дела : ";
	cin >> element.name;
	cout << " Приоритет дела (Цифра) : ";
	cin >> element.priority;
	cout << " Описание : ";
	cin >> element.discription;


	Date date;//Создание даты
	cout << " Введите дату : " << endl;
	cout << " Введите день : ";
	cin >> date.day;
	cout << " Введите месяц : ";
	cin >> date.month;
	cout << " Введите год : ";
	cin >> date.year;
	Time time;//Создание времени
	cout << " Введите время : " << endl;
	cout << " Введите часы : ";
	cin >> time.hour;
	cout << " Введите минуты :";
	cin >> time.minute;

	DateTime datetime;//Создание Даты и Времени
	datetime.date = date;
	datetime.time = time;

	element.datetime = datetime;

}

int Add(Element list[], int size)
{
	Element element;
	FillElement(element);
	list[size] = element;
	return size + 1;
}


int Delete(Element list[], int size, int index)
{
	for (int i = index + 1; i < size; i++)
	{
		list[i - 1] = list[i];
	}

	return size - 1;
}

void Edit(Element list[], int size, int index)
{
	cout << " Что Вы ходите отредактировать ?" << endl;
	cout << " 1 - Название дела  " << endl;
	cout << " 2 - Приоритет дела " << endl;
	cout << " 3 - Описание дела " << endl;
	cout << " 4 -  Дату дела " << endl;
	cout << " 5 - Время дела " << endl;
	cout << " 0 - Назад " << endl;
	int Answer;
	cin >> Answer;
	switch (Answer)
	{
	case 1:
		cout << " Введите название дела " << endl;
		cin >> list[index].name;
		break;
	case 2:
		cout << " Введите приоритет дела (Цифра) " << endl;
		cin >> list[index].priority;
		break;
	case 3:
		cout << " Введите описание дела " << endl;
		cin >> list[index].discription;
		break;
	case 4:
		cout << " Введите дату дела " << endl;
		cout << " Введите день ";
		cin >> list[index].datetime.date.day;
		cout << " Введите месяц ";
		cin >> list[index].datetime.date.month;
		cout << " Введите год ";
		cin >> list[index].datetime.date.year;
		break;
	case 5:
		cout << " Введите время дела " << endl;
		cout << " Введите час ";
		cin >> list[index].datetime.time.hour;
		cout << " Введите минуты ";
		cin >> list[index].datetime.time.minute;
		break;

	default:
		break;
	}
}


void PrintElement(Element element)
{
	cout << element.name << endl;
	cout << " Приоритет :" << element.priority << endl;
	cout << " Описание : " << element.discription << endl;
	cout << element.datetime.date.day << "." << element.datetime.date.month << "." << element.datetime.date.year << endl;
	cout << element.datetime.time.hour << ":" << element.datetime.time.minute << endl;
}

void PrintList(Element List[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1<<") ";
		PrintElement(List[i]);
		cout << endl;
	}
}


vector<Element> NameSearch(Element list[], int size, std::string name)
{
	vector<Element> res;
	for (int i = 0; i < size; i++)
	{
		if (list[i].name.find(name) != string::npos)
		{
			res.push_back(list[i]);
		}

	}

	return res;

}


vector<Element>PrioritySearch(Element list[], int size, int priority)
{
	vector<Element>result;
	for (int i = 0; i < size; i++)
	{
		if (list[i].priority == priority)
		{
			result.push_back(list[i]);
		}


	}

	return result;
}


vector<Element>DiscriptionSearch(Element list[], int size, std::string discription)
{
	vector<Element> res;
	for (int i = 0; i < size; i++)
	{
		if (list[i].discription.find(discription) != string::npos)
		{
			res.push_back(list[i]);
		}

	}

	return res;

}


vector<Element>DateTimeSearch(Element list[], int size, DateTime datetime)
{
	vector<Element>result;
	for (int i = 0; i < size; i++)
	{
		if (list[i].datetime.date.year == datetime.date.year &&
			list[i].datetime.date.month == datetime.date.month &&
			list[i].datetime.date.day == datetime.date.day &&
			list[i].datetime.time.hour == datetime.time.hour &&
			list[i].datetime.time.minute == datetime.time.minute)
		{

			result.push_back(list[i]);
		}


	}

	return result;

}


vector<Element>DaySearch(Element list[], int size, Date date)
{

	vector<Element>result;
	for (int i = 0; i < size; i++)
	{
		if (list[i].datetime.date.year == date.year &&
			list[i].datetime.date.month == date.month &&
			list[i].datetime.date.day == date.day)
		{

			result.push_back(list[i]);
		}


	}

	return result;

}


vector<Element>MonthSearch(Element list[], int size, Date date)
{

	vector<Element>result;
	for (int i = 0; i < size; i++)
	{
		if (list[i].datetime.date.year == date.year &&
			list[i].datetime.date.month == date.month)
		{

			result.push_back(list[i]);
		}


	}

	return result;

}

vector<Element>WeekSearch(Element list[], int size, Date startdate)
{
	int number = DaysOnMonth(startdate.month);

	vector<Element>result;
	
	int day =7-( number - startdate.day+1);
	for (int i = startdate.day; i < number + 1; i++)
	{
		auto tmp = DaySearch(list, size, Date(i, startdate.month, startdate.year));
		result.insert(result.end(), tmp.begin(), tmp.end());
	}

	for (int i = 1; i < day + 1; i++)
	{
		int month=startdate.month+1;
		int year=startdate.year;
		if (startdate.month == 12)
		{
			month = 1;
			year = startdate.year + 1;
		}

		auto tmp= DaySearch(list, size, Date(i,month,year ));
		result.insert(result.end(), tmp.begin(), tmp.end());
	}
	return result;
}


int DaysOnMonth(int month)
{

	if (month == 2)
	{
		return 28;
	}

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
		month == 10 || month == 12)
	{
		return 31;
	}

	return 30;


}

bool PriorityCompare(Element first, Element second)
{
	if (first.priority < second.priority)
	{
		return true;
	}
	return false;
}

void SortByPriority(Element list[], int size)
{
	Element* first = (Element*)list;

	sort(first, first + size, PriorityCompare);


}

bool DateTimeCompare(Element first, Element second)
{
	if (first.datetime.date.year < second.datetime.date.year)
	{
		return true;
	}
	else if (first.datetime.date.year > second.datetime.date.year)
	{
		return false;
	}
	if (first.datetime.date.month < second.datetime.date.month)
	{
		return true;
	}
	else if (first.datetime.date.month > second.datetime.date.month)
	{
		return false;
	}
	if (first.datetime.date.day < second.datetime.date.day)
	{
		return true;
	}
	else if (first.datetime.date.day > second.datetime.date.day)
	{
		return false;
	}

	if (first.datetime.time.hour < second.datetime.time.hour)
	{
		return true;
	}
	else if (first.datetime.time.hour > second.datetime.time.hour)
	{
		return false;
	}
	if (first.datetime.time.minute < second.datetime.time.minute)
	{
		return true;
	}
	else if (first.datetime.time.minute > second.datetime.time.minute)
	{
		return false;
	}
	return false;
}



void SortByDateTime(Element list[], int size)
{
	Element* first = (Element*)list;

	sort(first, first + size, DateTimeCompare);
}