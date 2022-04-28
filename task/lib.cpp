#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;
using std::system;

// функция удаления динамического массива
void Free(char* ptr)
{
	delete[] ptr;
}

// Функция меню выбора действия со списком студентов
void Menu(char ptr[7][30], int row)
{
	for (int i = 0; i < row; i++)
	{
		cout << ptr[i];
		cout << endl;
	}
}

// Функция добавляет студентов в список
char** AddStudents(char** oldList, int& number)
{
	system("cls");
	int n;
	cout << "Введите количество студентов для добавления в список: ";
	cin >> n;
	cin.get();
	char** newList = new char* [number += n];
	for (int i = 0; i < number - n; i++)
		newList[i] = oldList[i];
	char str[100];
	for (int i = number - n; i < number; i++)
	{
		cout << "Введите фамилию студента: ";
		cin.getline(str, 100);
		int lengthStr = strlen(str) + 1; // Длина фамилии + нуль терм.
		newList[i] = new char[lengthStr];
		strcpy_s(newList[i], lengthStr, str);
	}
	delete[] oldList;
	system("pause");
	return newList;
}

// Функция печатает список студентов
void Print(char** list, int number)
{
	system("cls");
	cout << "Список студентов: \n";
	cout << endl;
	for (int i = 0; i < number; i++)
	{
		cout << list[i];
		cout << endl;
	}
	cout << endl;
	system("pause");
}

// Функция сортировки списка студентов
void Sort(char** list, int number)
{
	system("cls");

	for (int startIndex = 0; startIndex < number - 1; ++startIndex)
	{
		int biggerIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < number; ++currentIndex)
		{
			if (strcmp(list[currentIndex], list[biggerIndex]) < 0) // Сортировка по убыванию
				biggerIndex = currentIndex;
		}

		char* temp = list[startIndex];
		list[startIndex] = list[biggerIndex];
		list[biggerIndex] = temp;
	}

	cout << "Список отсортирован!\n ";
	system("pause");
}

// Функция удаляет студента из списка
char** RemoveStudent(char** oldList, int& number)
{
	system("cls");
	char str[100];
	cout << "Введите фамилию студента для удаления: ";
	cin.getline(str, 100);

	char** newList = new char* [--number];
	int i{ 0 }, index{ 0 }, k{ 0 };
	bool exit{ false };
	for (i = 0; i < number + 1; i++)
	{
		if (strstr(oldList[i], str))
		{
			index = i;
			exit = true;
			for (int j = 0; j < number + 1; j++)
			{
				if (j == index)
				{
					j++;
					newList[k] = oldList[j];
					k++;
					continue;
				}
				else if (j < index)
				{
					newList[k] = oldList[j];
					k++;
					continue;
				}
				else if (j > index)
				{
					newList[k] = oldList[j];
					k++;
				}
			}
		}
		if (exit)
			break;
	}

	Free(oldList[index]);
	delete[] oldList;
	oldList = nullptr;

	cout << "\nСтудент отредактирован!\n";

	system("pause");
	return newList;
}

// Функция модификации студента в списке
char** EditStudent(char** list, int number)
{
	system("cls");
	char str[100];
	cout << "Введите фамилию студента для модификации: ";
	cin.getline(str, 100);

	bool exit{ false };
	for (int i = 0; i < number; i++)
	{
		if (strstr(list[i], str))
		{
			exit = true;
			Free(list[i]);
			cout << "Введите новые данные студента: ";
			char strNewData[100];
			cin.getline(strNewData, 100);
			char* buf = new char[strlen(strNewData) + 1];
			strcpy_s(buf, strlen(buf) + 1, strNewData);
			list[i] = buf;
			buf = nullptr;
		}
		if (exit)
			break;
	}

	cout << "\nСтудент отредактирован!\n";

	system("pause");
	return list;
}

// Функция поиска студента в списке
void FindStudent(char** list, int number)
{
	system("cls");
	char str[100];
	cout << "Введите фамилию студента или несколько первых букв: ";
	cin.getline(str, 100);

	int k{ 0 };
	for (int i = 0; i < number; i++)
	{
		if (strstr(list[i], str))
			cout << list[i] << endl;
	}

	system("pause");
}