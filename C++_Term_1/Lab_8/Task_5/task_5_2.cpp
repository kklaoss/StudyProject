#include <iostream> // Подключение библиотеки для ввода-вывода
#include <forward_list> // Подключение библиотеки для работы с односвязным списком
using namespace std; // Использование пространства имен std
void remove_first_greater_than_four(forward_list<int>& list) // Функция для удаления первого элемента, большего 4
{
	for (auto iter = list.begin(); iter != list.end(); ++iter) // Цикл по элементам списка
	{
		if (*iter > 4) // Если текущий элемент больше 4
		{
			list.erase_after(iter); // Удаляем элемент после текущего
			break; // Выходим из цикла
		}
	}
}
void insert_ten_before_fifteen(forward_list<int>& list) // Функция для вставки 10 перед каждым 15
{
	for (auto iter = list.begin(); iter != list.end(); ++iter) // Цикл по элементам списка
	{
		if (*iter == 15) // Если текущий элемент равен 15
		{
			iter = list.insert_after(iter, 10); // Вставляем 10 после текущего элемента
			++iter; // Переходим к следующему элементу
		}
	}
}
void print_list(const forward_list<int>& list) // Функция для печати списка
{
	for (int value : list) // Цикл по элементам списка
	{
		cout << value << " "; // Вывод элемента
	}
	cout << endl; // Переход на новую строку
}
int main() // Основная функция
{
	setlocale(LC_ALL, "ru"); // Установка локали для вывода на русском языке
	forward_list<int> list = { 8, 3, 5, 10, 15, 7 }; // Инициализация списка
	cout << "Данный список: "; // Вывод сообщения
	print_list(list); // Печать списка
	remove_first_greater_than_four(list); // Удаление первого элемента, большего 4
	cout << "После удаления первого элемента больше 4: "; // Вывод сообщения
	print_list(list); // Печать списка
	insert_ten_before_fifteen(list); // Вставка 10 перед каждым 15
	cout << "После вставки 10 перед каждым 15: "; // Вывод сообщения
	print_list(list); // Печать списка
}
