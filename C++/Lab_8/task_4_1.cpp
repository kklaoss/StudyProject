#include <iostream> // Подключение библиотеки для ввода-вывода
#include <forward_list> // Подключение библиотеки для работы с односвязным списком
using namespace std; // Использование пространства имен std
void remove_before_55(forward_list<double>& list) // Определение функции для удаления элемента перед 55
{
	auto prev = list.before_begin(); // Инициализация итератора prev перед началом списка
	auto current = list.begin(); // Инициализация итератора current на начало списка
	while (current != list.end() && next(current) != list.end() && *next(current) != 55) // Цикл до конца списка или до элемента перед 55
	{
		++prev; // Перемещение итератора prev на следующий элемент
		++current; // Перемещение итератора current на следующий элемент
	}
	if (current != list.end() && next(current) != list.end() && *next(current) == 55) // Проверка, что следующий элемент равен 55
	{
		list.erase_after(prev); // Удаление элемента перед 55
	}
}
int main() // Основная функция программы
{
	setlocale(LC_ALL, "RU"); // Установка локали для вывода на русском языке
	forward_list<double> list = { 10.5, 20.5, 55.0, 30.5, 40.5 }; // Инициализация списка значениями
	cout << "Данный список: "; // Вывод сообщения
	for (double value : list) // Цикл по элементам списка
	{
		cout << value << " "; // Вывод элемента списка
	}
	cout << endl; // Переход на новую строку
	remove_before_55(list); // Вызов функции для удаления элемента перед 55
	cout << "Список после удаления: "; // Вывод сообщения
	for (double value : list) // Цикл по элементам списка
	{
		cout << value << " "; // Вывод элемента списка
	}
	cout << endl; // Переход на новую строку
}