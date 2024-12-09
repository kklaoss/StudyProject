#include <iostream> // Объявление библиотеки для использования потоков ввода-вывода
using namespace std; // Подключение пространства имён std
void f2_idz2(int num)
{
	cout << " " << endl << "The serial number of the day in the year: " << num << endl;
	// Запрос у пользователя ввода порядкового номера дня в году
	int day; // Объявление целочисленной переменной day для хранения дня недели
	day = (num - 1) % 7;
	// Вычисление дня недели, используя остаток от деления на 7
	// (num - 1) используется, чтобы сделать 1-й день года равным 0 (понедельник)
	switch (day) // Используем switch для определения дня недели
	{
	case 0: cout << "This Monday" << endl; break; // Если day равно 0, выводим "Это понедельник"
	case 1: cout << "This Tuesday" << endl; break;  // Если day равно 1, выводим "Это вторник"
	case 2: cout << "This Wednesday" << endl; break; // Если day равно 2, выводим "Это среда"
	case 3: cout << "This Thursday" << endl; break; // Если day равно 3, выводим "Это четверг"
	case 4: cout << "This Friday" << endl; break; // Если day равно 4, выводим "Это пятница"
	case 5: cout << "This Saturday" << endl; break; // Если day равно 5, выводим "Это суббота"
	case 6: cout << "This Sunday" << endl; break; // Если day равно 6, выводим "Это воскресенье"
	default: cout << "Incorrect day number. Please enter a number from 1 to 365" << endl;
		// Если введен некорректный номер дня, выводим сообщение об ошибке
	}
}
int main() // Начало основной функции программы
{
	float a, b, c, d; // Объявление переменных для хранения значений
	cout << "Enter the variables:" << endl << " " << endl;  // Вывод сообщения для пользователя
	cout << "Variable 1 - "; cin >> a; // Запрос ввода первой переменной
	cout << "Variable 2 - "; cin >> b; // Запрос ввода второй переменной
	cout << "Variable 3 - "; cin >> c; // Запрос ввода третьей переменной
	cout << "Variable 4 - "; cin >> d; // Запрос ввода четвертой переменной
	int nomer; // Объявление переменной для хранения номера задачи
	cout << " " << endl << "Specify the task number: "; cin >> nomer; // Запрос ввода номера задачи от пользователя
	switch (nomer) // Использование оператора switch для выбора задачи по номеру
	{
	case 212: f2_idz2(a); break; // Если введён номер 212, вызывается функция f2_idz2 с переменной a
	default: cout << "The task was not found";
		// Если введён номер, который не соответствует ни одной задаче, выводится сообщение об ошибке
	}
	return 0; // Возврат 0
}