#pragma once
#include <vector>
#include "ToDoList.h"
/// <summary>
/// Заполнение данных одного дела.
/// </summary>
/// <param name="element">Пустой элемент</param>
void FillElement(Element& element);

/// <summary>
/// Добавление нового дела в конец списка
/// </summary>
/// <param name="list">Список дел</param>
/// <param name="size">Размер списка</param>
/// <returns>Новый размер списка</returns>
int Add(Element list[], int size);


/// <summary>
/// Удаление дела из списка
/// </summary>
/// <param name="list">Список дел</param>
/// <param name="size">Размер списка</param>
/// <param name="index">индекс списка выберет пользователь</param>
/// <returns>Новый список</returns>
int Delete(Element list[], int size, int index);

void Edit(Element list[], int size, int index);

void PrintElement(Element element);

void PrintList(Element List[], int size);


/// <summary>
/// Функция поиска дел по названию
/// </summary>
/// <param name="list"></param>
/// <param name="size"></param>
/// <param name="name"></param>
/// <returns></returns>
std::vector<Element> NameSearch(Element list[], int size, std::string name);

/// <summary>
/// Функция поиска дел по приоритету          
/// </summary>
/// <param name="list"></param>
/// <param name="size"></param>
/// <param name="priority"></param>
/// <returns></returns>
std::vector<Element>PrioritySearch(Element list[], int size, int priority);


/// <summary>
/// Функция поиска дел по описанию
/// </summary>
/// <param name="list">Список</param>
/// <param name="size">размер списка</param>
/// <param name="description">описание дела</param>
/// <returns>возвращает результат поиска</returns>
std::vector<Element>DiscriptionSearch(Element list[], int size, std::string description);


/// <summary>
/// Дата и время
/// </summary>
/// <param name="list"></param>
/// <param name="size"></param>
/// <param name="datetime"></param>
/// <returns>result.push_back(list[i])</returns>
std::vector<Element>DateTimeSearch(Element list[], int size,DateTime datetime );

/// <summary>
/// Функция поиска дел на 1 день
/// </summary>
/// <param name="list">список дел</param>
/// <param name="size">размер списка</param>
/// <param name="date">дата</param>
/// <returns>результат поиска</returns>
std::vector<Element>DaySearch(Element list[], int size, Date date);


/// <summary>
/// Список дел на месяц
/// </summary>
/// <param name="list">список дел</param>
/// <param name="size">размер списка</param>
/// <param name="date">дата</param>
/// <returns></returns>
std::vector<Element>MonthSearch(Element list[], int size, Date date);


/// <summary>
/// Список дел на неделю
/// </summary>
/// <param name="list">список дел</param>
/// <param name="size">размер списка</param>
/// <param name="startdate">начальный день</param>
/// <returns></returns>
std::vector<Element>WeekSearch(Element list[], int size, Date startdate);


/// <summary>
/// Функция поиска количество дней в месяце
/// </summary>
/// <param name="month">месяц</param>
/// <returns>Количество дней в месяце</returns>
int DaysOnMonth(int month);



/// <summary>
/// Функция компоратор сравнивающая по приоритету
/// </summary>
/// <param name="first">первый элемент</param>
/// <param name="second">последний элемент</param>
/// <returns>возвращает true</returns>
bool PriorityCompare(Element first, Element second);

/// <summary>
/// Функция сортировки по приоритету
/// </summary>
/// <param name="list">список дел</param>
/// <param name="size">размер списка</param>
void SortByPriority(Element list[], int size);

/// <summary>
/// Сравнение по дате и времени
/// </summary>
/// <param name="first">Первый элемент списка,последний элемент списка</param>
/// <param name="second"></param>
/// <returns>возвращает true</returns>
bool DateTimeCompare(Element first, Element second);





/// <summary>
/// Сортировка по дате и времени исполнения
/// </summary>
/// <param name="list">список дел</param>
/// <param name="size">размер списка</param>
void SortByDateTime(Element list[], int size);
