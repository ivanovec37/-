#pragma once
#include <vector>
#include "ToDoList.h"
/// <summary>
/// ���������� ������ ������ ����.
/// </summary>
/// <param name="element">������ �������</param>
void FillElement(Element& element);

/// <summary>
/// ���������� ������ ���� � ����� ������
/// </summary>
/// <param name="list">������ ���</param>
/// <param name="size">������ ������</param>
/// <returns>����� ������ ������</returns>
int Add(Element list[], int size);


/// <summary>
/// �������� ���� �� ������
/// </summary>
/// <param name="list">������ ���</param>
/// <param name="size">������ ������</param>
/// <param name="index">������ ������ ������� ������������</param>
/// <returns>����� ������</returns>
int Delete(Element list[], int size, int index);

void Edit(Element list[], int size, int index);

void PrintElement(Element element);

void PrintList(Element List[], int size);


/// <summary>
/// ������� ������ ��� �� ��������
/// </summary>
/// <param name="list"></param>
/// <param name="size"></param>
/// <param name="name"></param>
/// <returns></returns>
std::vector<Element> NameSearch(Element list[], int size, std::string name);

/// <summary>
/// ������� ������ ��� �� ����������          
/// </summary>
/// <param name="list"></param>
/// <param name="size"></param>
/// <param name="priority"></param>
/// <returns></returns>
std::vector<Element>PrioritySearch(Element list[], int size, int priority);


/// <summary>
/// ������� ������ ��� �� ��������
/// </summary>
/// <param name="list">������</param>
/// <param name="size">������ ������</param>
/// <param name="description">�������� ����</param>
/// <returns>���������� ��������� ������</returns>
std::vector<Element>DiscriptionSearch(Element list[], int size, std::string description);


/// <summary>
/// ���� � �����
/// </summary>
/// <param name="list"></param>
/// <param name="size"></param>
/// <param name="datetime"></param>
/// <returns>result.push_back(list[i])</returns>
std::vector<Element>DateTimeSearch(Element list[], int size,DateTime datetime );

/// <summary>
/// ������� ������ ��� �� 1 ����
/// </summary>
/// <param name="list">������ ���</param>
/// <param name="size">������ ������</param>
/// <param name="date">����</param>
/// <returns>��������� ������</returns>
std::vector<Element>DaySearch(Element list[], int size, Date date);


/// <summary>
/// ������ ��� �� �����
/// </summary>
/// <param name="list">������ ���</param>
/// <param name="size">������ ������</param>
/// <param name="date">����</param>
/// <returns></returns>
std::vector<Element>MonthSearch(Element list[], int size, Date date);


/// <summary>
/// ������ ��� �� ������
/// </summary>
/// <param name="list">������ ���</param>
/// <param name="size">������ ������</param>
/// <param name="startdate">��������� ����</param>
/// <returns></returns>
std::vector<Element>WeekSearch(Element list[], int size, Date startdate);


/// <summary>
/// ������� ������ ���������� ���� � ������
/// </summary>
/// <param name="month">�����</param>
/// <returns>���������� ���� � ������</returns>
int DaysOnMonth(int month);



/// <summary>
/// ������� ���������� ������������ �� ����������
/// </summary>
/// <param name="first">������ �������</param>
/// <param name="second">��������� �������</param>
/// <returns>���������� true</returns>
bool PriorityCompare(Element first, Element second);

/// <summary>
/// ������� ���������� �� ����������
/// </summary>
/// <param name="list">������ ���</param>
/// <param name="size">������ ������</param>
void SortByPriority(Element list[], int size);

/// <summary>
/// ��������� �� ���� � �������
/// </summary>
/// <param name="first">������ ������� ������,��������� ������� ������</param>
/// <param name="second"></param>
/// <returns>���������� true</returns>
bool DateTimeCompare(Element first, Element second);





/// <summary>
/// ���������� �� ���� � ������� ����������
/// </summary>
/// <param name="list">������ ���</param>
/// <param name="size">������ ������</param>
void SortByDateTime(Element list[], int size);
