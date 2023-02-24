#pragma once
#include<string>


//Дата
struct Date
{
	int day;//день
	int month;//месяц
	int year;//год
	Date() : day(0), month(0), year(0) {}
	Date(int day,int month,int year) : day(day), month(month), year(year) {}
};

//Время
struct Time
{
	int hour;//минуты
	int minute;//часы
	Time() : hour(0), minute(0) {}
	Time(int hour,int minute) : hour(hour), minute(minute) {}
};



//Дата и Время
struct DateTime
{
	Date date;// поле с датой
	Time time;// поле со временем
	DateTime() {}
	DateTime(Date date,Time time):time(time),date(date){}
};

//Один элемент списка
struct Element
{
	std::string name;//название
	int priority;// приоритет
	std::string discription;//описание
	DateTime datetime;//поле с датой и временем
	Element() : priority(0) {}
};