#include <iostream>
#include "WorkWithList.h"
#include"Tests.h"
using namespace std;
int List_Type_Menu()
{
	int Answer;
	cout << " Выберете тип списка" << endl;
	cout << "1.Полный список" << endl;
	cout << "2.Список на месяц" << endl;
	cout << "3.Список на неделю" << endl;
	cout << "4.Список на день" << endl;
	cout << "5.Назад" << endl;
	cin >> Answer;
	return Answer;
}
int Menu(Element list[], int& size)
{
	cout << endl;
	//1   Отображение списка дел:
		//1.1  Полный список
		//1.2  Список на месяц
		//1.3 Список на неделю
		//1.4 Список на день
			//1.1-4.1  сортировка по приоритету 
			//1.1-4.2 сортировка по дате и времени
	//2 Добавление дел:
	//3 Удаление дел(вывести весь список и спросить номер дела)
	//4 Редактирование дел(вывести весь список и спросить номер дела)
	//5 Поиск дела
		//5.1 по названию
		//5.2 по приоритету
		//5.3 по описанию
		//5.4 по дате и времени исполнения
	//6 Выход из программы

	while (true)
	{
		cout << "\t""****Главное меню*****" << endl << endl;
		cout << "1.Отобразить список дел" << endl;
		cout << "2.Добавление дел" << endl;
		cout << "3.Удаление дел" << endl;
		cout << "4.Редактирование дела" << endl;
		cout << "5.Поиск дела" << endl;
		cout << "6.Выход" << endl;
		cout << endl;
		cout << "Выберете пункт меню" << endl;
		int userAnswer;
		cin >> userAnswer;
		system("cls");
		if (userAnswer == 1)
		{
			while (true)
			{
				cout << "Выберете тип сортировки" << endl;
				cout << "1. Cортировка по приоритету" << endl;
				cout << "2.Cортировка по дате и времени" << endl;
				cout << "3.Назад" << endl;
				cin >> userAnswer;
				system("cls");
				if (userAnswer == 1)
				{
					while (true)
					{
						userAnswer = List_Type_Menu();
						system("cls");
						if (userAnswer == 1)
						{
							if (size == 0)
							{
								cout << "Список пустой." << endl;

							}
							else
							{
								SortByPriority(list, size);
								PrintList(list, size);

							}
							cout << "Нажмите любую клавишу для возврата в главное меню" << endl;
							getchar();
							getchar();
							system("cls");
							return 1;

						}
						else if (userAnswer == 2)
						{
							if (size == 0)
							{
								cout << "Список пустой." << endl;

							}
							else
							{
								while (true)
								{
									cout << "Введите год" << endl;
									int year;
									cin >> year;
									cout << "Введите номер месяца " << endl;
									int month;
									cin >> month;
									if (month < 1 || month>12)
									{
										cout << "Нет такого месяца" << endl;
									}
									else
									{
										system("cls");
										vector<Element>L = MonthSearch(list, size, Date(1, month, year));
										if (L.size() == 0)
										{
											cout << "Список пустой." << endl;
											break;
										}
										else
										{
											SortByPriority(L.data(), L.size());
											PrintList(L.data(), L.size());
											break;
										}
									}


								}

							}
							cout << "Нажмите любую клавишу для возврата в главное меню" << endl;
							getchar();
							getchar();
							system("cls");
							return 1;


						}
						else if (userAnswer == 3)
						{
							if (size == 0)
							{
								cout << "Список пустой." << endl;

							}
							else
							{
								while (true)
								{
									cout << "Введите год" << endl;
									int year1;
									cin >> year1;
									cout << "Введите номер месяца " << endl;
									int month1;
									cin >> month1;
									cout << "Введите дату(день) с которого начинается неделя" << endl;
									int day;
									cin >> day;
									if (month1 < 1 || month1>12)
									{
										cout << "Нет такого месяца" << endl;
									}
									else if (day < 1 || DaysOnMonth(month1) < day)
									{
										cout << " Нет такого дня в месяце" << endl;
									}
									else
									{
										system("cls");
										vector<Element>R = WeekSearch(list, size, Date(day, month1, year1));
										if (R.size() == 0)
										{
											cout << "Список пустой." << endl;
											break;
										}
										else
										{

											SortByPriority(R.data(), R.size());
											PrintList(R.data(), R.size());
											break;
										}
									}
								}
							}
							cout << "Нажмите любую клавишу для возврата в главное меню" << endl;
							getchar();
							getchar();
							system("cls");
							return 1;
						}
						else if (userAnswer == 4)
						{
							if (size == 0)
							{
								cout << "Список пустой." << endl;

							}
							else
							{
								while (true)
								{
									cout << "Введите год" << endl;
									int year1;
									cin >> year1;
									cout << "Введите номер месяца " << endl;
									int month1;
									cin >> month1;
									cout << "Введите день " << endl;
									int day;
									cin >> day;
									if (month1 < 1 || month1>12)
									{
										cout << "Нет такого месяца" << endl;
									}
									else if (day < 1 || DaysOnMonth(month1) < day)
									{
										cout << " Нет такого дня в месяце" << endl;
									}
									else
									{
										system("cls");
										vector<Element>R = DaySearch(list, size, Date(day, month1, year1));
										if (R.size() == 0)
										{
											cout << "Список пустой." << endl;
											break;
										}
										else
										{

											SortByPriority(R.data(), R.size());
											PrintList(R.data(), R.size());
											break;
										}
									}
								}
							}
							cout << "Нажмите любую клавишу для возврата в главное меню" << endl;
							getchar();
							getchar();
							system("cls");
							return 1;


						}
						else if (userAnswer == 5)
						{
							break;
						}
						else
						{
							cout << "Нет такого пункта меню" << endl << endl;
						}
					}



				}

				else if (userAnswer == 2)
				{
					while (true)
					{
						userAnswer = List_Type_Menu();
						system("cls");
						if (userAnswer == 1)
						{
							if (size == 0)
							{
								cout << "Список пустой." << endl;

							}
							else
							{
								SortByDateTime(list, size);
								PrintList(list, size);

							}
							cout << "Нажмите любую клавишу для возврата в главное меню" << endl;
							getchar();
							getchar();
							system("cls");
							return 1;

						}
						else if (userAnswer == 2)
						{
							if (size == 0)
							{
								cout << "Список пустой." << endl;

							}
							else
							{
								while (true)
								{
									cout << "Введите год" << endl;
									int year;
									cin >> year;
									cout << "Введите номер месяца " << endl;
									int month;
									cin >> month;
									if (month < 1 || month>12)
									{
										cout << "Нет такого месяца" << endl;
									}
									else
									{
										system("cls");
										vector<Element>L = MonthSearch(list, size, Date(1, month, year));
										if (L.size() == 0)
										{
											cout << "Список пустой." << endl;
											break;
										}
										else
										{
											SortByDateTime(L.data(), L.size());
											PrintList(L.data(), L.size());
											break;
										}
									}


								}

							}
							cout << "Нажмите любую клавишу для возврата в главное меню" << endl;
							getchar();
							getchar();
							system("cls");
							return 1;


						}
						else if (userAnswer == 3)
						{
							if (size == 0)
							{
								cout << "Список пустой." << endl;

							}
							else
							{
								while (true)
								{
									cout << "Введите год" << endl;
									int year1;
									cin >> year1;
									cout << "Введите номер месяца " << endl;
									int month1;
									cin >> month1;
									cout << "Введите дату(день) с которого начинается неделя" << endl;
									int day;
									cin >> day;
									if (month1 < 1 || month1>12)
									{
										cout << "Нет такого месяца" << endl;
									}
									else if (day < 1 || DaysOnMonth(month1) < day)
									{
										cout << " Нет такого дня в месяце" << endl;
									}
									else
									{
										system("cls");
										vector<Element>R = WeekSearch(list, size, Date(day, month1, year1));
										if (R.size() == 0)
										{
											cout << "Список пустой." << endl;
											break;
										}
										else
										{

											SortByDateTime(R.data(), R.size());
											PrintList(R.data(), R.size());
											break;
										}
									}
								}
							}
							cout << "Нажмите любую клавишу для возврата в главное меню" << endl;
							getchar();
							getchar();
							system("cls");
							return 1;
						}
						else if (userAnswer == 4)
						{
							if (size == 0)
							{
								cout << "Список пустой." << endl;

							}
							else
							{
								while (true)
								{
									cout << "Введите год" << endl;
									int year1;
									cin >> year1;
									cout << "Введите номер месяца " << endl;
									int month1;
									cin >> month1;
									cout << "Введите день " << endl;
									int day;
									cin >> day;
									if (month1 < 1 || month1>12)
									{
										cout << "Нет такого месяца" << endl;
									}
									else if (day < 1 || DaysOnMonth(month1) < day)
									{
										cout << " Нет такого дня в месяце" << endl;
									}
									else
									{
										system("cls");
										vector<Element>R = DaySearch(list, size, Date(day, month1, year1));
										if (R.size() == 0)
										{
											cout << "Список пустой." << endl;
											break;
										}
										else
										{

											SortByDateTime(R.data(), R.size());
											PrintList(R.data(), R.size());
											break;
										}
									}
								}
							}
							cout << "Нажмите любую клавишу для возврата в главное меню" << endl;
							getchar();
							getchar();
							system("cls");
							return 1;


						}
						else if (userAnswer == 5)
						{
							break;
						}
						else
						{
							cout << "Нет такого пункта меню" << endl << endl;
						}
					}

				}
				else if (userAnswer == 3)
				{
					break;
				}
				else
				{
					cout << " Нет такого пункта меню" << endl << endl;
				}


			}


		}

		else if (userAnswer == 2)
		{

			size = Add(list, size);
			system("cls");
		}
		else if (userAnswer == 3)
		{
			PrintList(list, size);
			cout << endl;


			while (true)
			{
				cout << "Введите номер дела которое хотите удалить(нажмите 0 для  возврата)" << endl;
				int P;
				cin >> P;
				if (P == 0)
				{
					system("cls");
					return 1;

				}
				else if (P<1 || P>size)
				{
					cout << "Нет такого дела в списке" << endl;
				}
				else
				{
					size = Delete(list, size, P - 1);
					system("cls");
					break;
				}
			}

		}

		else if (userAnswer == 4)
		{
			PrintList(list, size);
			cout << endl;
			while (true)
			{
				cout << "Введите номер дела который хотите отредактировать(нажмите 0 для  возврата)" << endl;
				int P;
				cin >> P;
				if (P == 0)
				{
					system("cls");
					return 1;

				}
				else if (P<1 || P>size)
				{
					cout << "Нет такого дела в списке" << endl;
				}
				else
				{
					Edit(list, size, P - 1);

					break;
				}
			}
			system("cls");
		}
		else if (userAnswer == 5)
		{
			while (true)
			{
				cout << " По какому признаку найти дело?" << endl;
				cout << " 1- Название дела" << endl;
				cout << " 2- по приоритету дела" << endl;
				cout << " 3-  по описанию дела" << endl;
				cout << " 4-  по дате и времени исполнения дела" << endl;
				cout << " 5 - Назад" << endl;
				int Answer;
				cin >> Answer;
				if (Answer == 1)
				{
					cout << "Введите название дела" << endl;
					string r;
					cin >> r;
					vector<Element>R = NameSearch(list, size, r);
					if (R.size() == 0)
					{
						cout << "Список пустой" << endl;
					}
					else
					{
						PrintList(R.data(), R.size());
					}

				}
				else if (Answer == 2)
				{

					cout << "Введите приоритет дела" << endl;
					int r;
					cin >> r;
					vector<Element>R = PrioritySearch(list, size, r);
					if (R.size() == 0)
					{
						cout << "Список пустой" << endl;
					}
					else
					{
						PrintList(R.data(), R.size());
					}
				
				}
				else if (Answer == 3)
				{

					cout << "Введите описание дела" << endl;
					string r;
					cin >> r;
					vector<Element>R =DiscriptionSearch (list, size, r);
					if (R.size() == 0)
					{
						cout << "Список пустой" << endl;
					}
					else
					{
						PrintList(R.data(), R.size());
					}
				}
				else if (Answer == 4)
				{

					cout << "Введите дату и время  дела" << endl;
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
					vector<Element>R = DateTimeSearch(list, size, datetime);
					if (R.size() == 0)
					{
						cout << "Список пустой" << endl;
					}
					else
					{
						PrintList(R.data(), R.size());
					}
				}
				else if (Answer == 5)
				{
					system("cls");
					break;
				}
				else
				{
					cout << " Нет такого пункта меню" << endl;
					continue;
				}

				cout << "Нажмите любую клавишу для возврата в главное меню" << endl;
				getchar();
				getchar();
				system("cls");
				return 1;

			}

		}

		else if (userAnswer == 6)
		{
			return 0;
		}

		else
		{
			cout << "Нет такого пункта меню" << endl;
			cout << "Выберете другой пункт  меню" << endl << endl;
		}


	}
}



int main()
{
	system("chcp 1251"); system("cls");

	int size = 0;
	Element list[200];

	FillList(list, size);

	while (true)
	{
		if (Menu(list, size) == 0)
		{
			return 0;
		}


	}





}
