#include <iostream> // Подключение библиотеки для ввода-вывода
#include <stack>    // Подключение библиотеки для работы со стеком
#include <vector>   // Подключение библиотеки для работы с вектором
using namespace std; // Использование пространства имен std
struct book // Определение структуры для хранения информации о книге
{
	char title[100]; // Название книги
	double price;    // Цена книги
};
int main() // Точка входа в программу
{
	setlocale(LC_ALL, "RU"); // Установка локали для корректного отображения русского языка
	book first_book = { "Пентаграмма", 150.55 }; // Создание первой книги
	book second_book = { "Корни дуба", 135.75 }; // Создание второй книги
	book third_book = { "Мелкие боги", 160.25 }; // Создание третьей книги
	stack<book> stack_books; // Создание стека для хранения книг
	stack_books.push(first_book); // Добавление первой книги в стек
	stack_books.push(second_book); // Добавление второй книги в стек
	stack_books.push(third_book); // Добавление третьей книги в стек
	book new_book = { "Компромисс", 95.45 }; // Создание новой книги
	stack_books.push(new_book); // Добавление новой книги в стек
	vector<book> vector_books; // Создание вектора для хранения книг
	double total_price = 0.0; // Инициализация переменной для хранения общей стоимости книг
	while (!stack_books.empty()) // Цикл, пока стек не пуст
	{
		book vector_book = stack_books.top(); // Получение верхней книги из стека
		vector_books.push_back(vector_book); // Добавление книги в вектор
		total_price += vector_book.price; // Добавление цены книги к общей стоимости
		stack_books.pop(); // Удаление верхней книги из стека
	}
	double average_price = total_price / vector_books.size(); // Вычисление средней цены книг
	cout << "Данный стек книг, включая новую:\n"; // Вывод сообщения
	for (int i = vector_books.size() - 1; i >= 0; --i) // Цикл для вывода книг в обратном порядке
	{
		cout << "Назавание книги: " << vector_books[i].title << "; Цена: " << vector_books[i].price << " руб.\n"; // Вывод информации о книге
	}
	cout << "\nСредняя цена книг: " << average_price << " руб.\n"; // Вывод средней цены книг
}