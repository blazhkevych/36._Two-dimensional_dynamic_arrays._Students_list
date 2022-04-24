// Функция выводит русский текст в окно консоли
//void RussianMessage(const char*);

// Функция добавляет студентов в список
char** AddStudents(char**, int&);

// Функция печатает список студентов
void Print(char**, int);

// Функция сортировки списка студентов
void Sort(char**, int);

//Функция удаляет студента из списка
char** RemoveStudent(char**, int&);

// Функция модификации студента в списке
char** EditStudent(char**, int);

// Функция поиска студента в списке
void FindStudent(char**, int);

// Функция меню выбора действия со списком студентов
void Menu(char ptr[][30], int row);

// функция удаления динамического массива
void Free(char* ptr);