#pragma once
#include<string>


//����
struct Date
{
	int day;//����
	int month;//�����
	int year;//���
	Date() : day(0), month(0), year(0) {}
	Date(int day,int month,int year) : day(day), month(month), year(year) {}
};

//�����
struct Time
{
	int hour;//������
	int minute;//����
	Time() : hour(0), minute(0) {}
	Time(int hour,int minute) : hour(hour), minute(minute) {}
};



//���� � �����
struct DateTime
{
	Date date;// ���� � �����
	Time time;// ���� �� ��������
	DateTime() {}
	DateTime(Date date,Time time):time(time),date(date){}
};

//���� ������� ������
struct Element
{
	std::string name;//��������
	int priority;// ���������
	std::string discription;//��������
	DateTime datetime;//���� � ����� � ��������
	Element() : priority(0) {}
};