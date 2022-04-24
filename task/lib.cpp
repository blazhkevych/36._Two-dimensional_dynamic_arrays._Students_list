#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

// функция удаления динамического массива
void Free(char* ptr)
{
	delete[] ptr;
}

// Функция выводит русский текст в окно консоли
//void RussianMessage(const char* s)
//{
//	char* buf = new char[strlen(s) + 1];
//	CharToOemA(s, buf);
//	cout << buf;
//	delete[] buf;
//}

// Функция меню выбора действия со списком студентов
void Menu(char ptr[][30], int row)
{
	for (int i = 0; i < row; i++)
	{
		//RussianMessage(ptr[i]);
		cout << ptr[i];
		cout << endl;
	}
}

// Функция добавляет студентов в список
char** AddStudents(char** oldList, int& number)
{
	system("cls");
	int n;
	//RussianMessage("Введите количество студентов для добавления в список: ");
	cout << "Введите количество студентов для добавления в список: ";
	cin >> n;
	cin.get();
	char** newList = new char* [number += n];
	for (int i = 0; i < number - n; i++)
		newList[i] = oldList[i];
	char str[100];
	for (int i = number - n; i < number; i++)
	{
		//RussianMessage("Введите фамилию студента: ");
		cout << "Введите фамилию студента: ";
		cin.getline(str, 100);
		int length = strlen(str);
		newList[i] = new char[length + 1];
		strcpy_s(newList[i], strlen(newList[i]), str);
	}
	delete[] oldList;
	system("pause");
	return newList;
}

// Функция печатает список студентов
void Print(char** list, int number)
{
	system("cls");
	//RussianMessage("Список студентов: ");
	cout << "Список студентов: \n";
	cout << endl;
	for (int i = 0; i < number; i++)
	{
		//RussianMessage(list[i]);
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
			if (strcmp(list[currentIndex], list[biggerIndex]) < 0)
				biggerIndex = currentIndex;
		}

		char* temp = list[startIndex];
		list[startIndex] = list[biggerIndex];
		list[biggerIndex] = temp;
	}

	//RussianMessage("Список отсортирован!\n ");
	cout << "Список отсортирован!\n ";
	system("pause");
}

// Функция удаляет студента из списка
char** RemoveStudent(char** oldList, int& number)
{
	system("cls");
	char str[100];
	//RussianMessage("Введите фамилию студента для удаления: ");
	cout << "Введите фамилию студента для удаления: ";
	cin.getline(str, 100);
	/*
		Реализация алгоритма удаления студента из списка
	*/
	system("pause");
	return nullptr;
}

// Функция модификации студента в списке
char** EditStudent(char** list, int number)
{
	system("cls");
	char str[100];
	//RussianMessage("Введите фамилию студента для модификации: ");
	cout << "Введите фамилию студента для модификации: ";
	cin.getline(str, 100);
	/*
		Реализация алгоритма модификации фамилии студента
	*/
	for (int i = 0; i < number; i++)
	{
		//RussianMessage("Введите новые данные студента: ");
		cout << "Введите новые данные студента: ";
		char strNewData[100];
		cin.getline(strNewData, 100);
		//strcat_s(strNewData, strlen(strNewData), '\0');
		char* buf = new char[strlen(strNewData) + 1];
		CharToOemA(strNewData, buf);

		delete[] buf;

		char* copyOfListI = list[i];
		char* copyOfStr = str;
		_strlwr_s(copyOfListI, strlen(copyOfListI));
		_strlwr_s(copyOfStr, strlen(copyOfStr));


		if (strstr(list[i], str)) // ищем студента
		{
			Free(list[i]); // удаляем старого студента



			int length = strlen(strNewData);
			list[i] = new char[length + 1];
			strcpy_s(list[i], strlen(list[i]), strNewData);
		}
	}

	//RussianMessage("\nСтудент отредактирован!");
	cout << "\nСтудент отредактирован!";

	system("pause");
	return list;
}

// Функция поиска студента в списке
void FindStudent(char** list, int number)
{
	system("cls");
	char str[100];
	//RussianMessage("Введите фамилию студента или несколько первых букв: ");
	cout << "Введите фамилию студента или несколько первых букв: ";
	cin.getline(str, 100);

	for (int i = 0; i < number; i++)
	{
		if (strstr(list[i], str))
			cout << list[i] << endl;
	}

	system("pause");
}