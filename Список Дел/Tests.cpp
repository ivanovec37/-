#include"Tests.h"
#include <iostream>
using namespace std;
void FillList(Element list[], int& size)
{
	size = 5;

	list[0].name = "Посетить  стоматолога";
	list[0].priority = 1;
	list[0].discription = "Надо залечить зуб";
	Date date0(1, 3, 2000);
	Time time0(1, 12);
	list[0].datetime = DateTime(date0, time0);



	list[1].name = "Купить путёвку";
	list[1].priority = 0;
	list[1].discription = "Отдохнуть на красном море в Египте";
	Date date1(11, 7, 2022);
	Time time1(11, 12);
	list[1].datetime = DateTime(date1, time1);


	list[2].name = "Позаниматься с репетитором";
	list[2].priority = 2;
	list[2].discription = "Выучить новую тему";
	Date date2(30, 1, 2022);
	Time time2(1, 11);
	list[2].datetime = DateTime(date2, time2);

	list[3].name = "Посетить отделение банка";
	list[3].priority = 9;
	list[3].discription = "Получить кредит";
	Date date3(3, 2, 2022);
	Time time3(10, 12);
	list[3].datetime = DateTime(date3, time3);


	list[4].name = "Позвонить другу";
	list[4].priority = 2;
	list[4].discription = "Поздравить с Днем рождения";
	Date date4(3,2,2022);
	Time time4(21,41);
	list[4].datetime = DateTime(date4, time4);
}

void Test1(Element list[], int& size)
{

	FillList(list, size);

	vector<Element>Test = NameSearch(list, size, "Посетить");
	cout << "NameSearch" << endl;
	PrintList(Test.data(), Test.size());

	Test = PrioritySearch(list, size, 2);
	cout << "PrioritySearch" << endl;
	PrintList(Test.data(), Test.size());

	Test = DateTimeSearch(list, size, DateTime(Date(3, 2, 2022), Time(21, 41)));
	cout << "DateTimeSearch" << endl;
	PrintList(Test.data(), Test.size());

	Test = DaySearch(list, size, Date(3, 2, 2022));
	cout << "DaySearch" << endl;
	PrintList(Test.data(), Test.size());

	Test = WeekSearch(list, size, Date(30, 1, 2022));
	cout << "WeekSearch" << endl;
	PrintList(Test.data(), Test.size());

	Test = MonthSearch(list, size, Date(3, 2, 2022));
	cout << "MonthSearch" << endl;
	PrintList(Test.data(), Test.size());

	SortByPriority(list, size);
	cout << "SortByPriority" << endl;
	PrintList(list, size);

	SortByDateTime(list, size);
	cout << "SortByDateTime" << endl;
	PrintList(list, size);



}

void Test2(Element mass[], int& size)
{
	size = Add(mass, size);
	cout << endl;
	size = Add(mass, size);
	cout << endl;
	cout << " Полный список " << endl;
	PrintList(mass, size);

	Edit(mass, size, 0);
	cout << endl;
	cout << " Список после редактирования " << endl;
	PrintList(mass, size);
	size = Delete(mass, size, 0);
	cout << endl;
	cout << " Список после удаления первого элемента" << endl;
	PrintList(mass, size);

	cout << endl; 


}
