#include <iostream> // Объявление библиотеки для использования потоков ввода-вывода
using namespace std; // Подключение пространства имён std
void f2_2(float K, float L, float N)
{
	if (K > L && K > N) cout << " " << endl << "Serial number of the largest number: " << 1 << endl;
	// Проверка, является ли K наибольшим числом среди K, L и N
	// Если да, выводим, что это первое число
	if (L > K && L > N) cout << " " << endl << "Serial number of the largest number: " << 2 << endl;
	// Проверка, является ли L наибольшим числом среди K, L и N
	// Если да, выводим, что это второе число
	if (N > K && N > L) cout << " " << endl << "Serial number of the largest number: " << 3 << endl;
	// Проверка, является ли N наибольшим числом среди K, L и N
	// Если да, выводим, что это третье число
	if (K < L && K < N) cout << " " << endl << "Serial number of the smallest number: " << 1;
	// Проверка, является ли K наименьшим числом среди K, L и N
	// Если да, выводим, что это первое число
	if (L < K && L < N) cout << " " << endl << "Serial number of the smallest number: " << 2;
	// Проверка, является ли L наименьшим числом среди K, L и N
	// Если да, выводим, что это второе число
	if (N < K && N < L) cout << " " << endl << "Serial number of the smallest number: " << 3;
	// Проверка, является ли N наименьшим числом среди K, L и N
	// Если да, выводим, что это третье число
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
	case 22: f2_2(a, b, c); break; // Если введён номер 22, вызывается функция f2_2 с переменными a, b, c
	default: cout << "The task was not found";
		// Если введён номер, который не соответствует ни одной задаче, выводится сообщение об ошибке
	}
	return 0; // Возврат 0
}