#include <iostream>  // Подключение библиотеки для работы с вводом и выводом
#include <fstream>   // Подключение библиотеки для работы с файлами
#include <vector>    // Подключение библиотеки для использования контейнера vector
#include <string>    // Подключение библиотеки для работы со строками
// Определение структуры Book, которая представляет информацию о книге
struct Book
{
	std::string title;       // Название книги
	std::string second_name; // Фамилия автора
	std::string first_name;  // Имя автора
	int year;                // Год издания
	std::string publisher;   // Издательство
	double cost;             // Себестоимость книги
	double price;            // Цена книги
	double profit;           // Прибыль от книги
};
int main()
{
	setlocale(LC_ALL, "RU");  // Установка локали для поддержки кириллицы
	std::vector<Book> books;  // Создание вектора для хранения объектов типа Book
	std::ifstream in_file("file_5.txt");  // Открытие файла для чтения данных
	Book book;  // Создание временного объекта Book для хранения данных из файла
	// Чтение данных из файла и сохранение их в вектор books
	while (in_file >> book.title >> book.second_name >> book.first_name >> book.year >> book.publisher >> book.cost >> book.price >> book.profit)
	{
		books.push_back(book);  // Добавление объекта book в вектор books
	}
	in_file.close();  // Закрытие файла после чтения
	// Вывод содержимого исходного файла на экран
	std::cout << "Содержимое исходного файла:" << std::endl;
	for (const auto& book : books)
	{
		std::cout << book.title << " " << book.second_name << " " << book.first_name << " " << book.year << " " << book.publisher << " " << book.cost << " " << book.price << " " << book.profit << std::endl;
	}
	std::vector<Book> filtered_books;  // Создание вектора для хранения отфильтрованных книг
	// Фильтрация книг по фамилии автора (начинающейся на 'K')
	for (const auto& book : books)
	{
		if (book.second_name[0] == 'K')
		{
			filtered_books.push_back(book);  // Добавление книги в отфильтрованный вектор
		}
	}
	std::ofstream new_file("new_file_5.txt");  // Открытие файла для записи отфильтрованных данных
	// Запись отфильтрованных данных в новый файл
	for (const auto& book : filtered_books)
	{
		new_file << book.title << " " << book.second_name << " " << book.first_name << " " << book.year << " " << book.publisher << " " << book.cost << " " << book.price << " " << book.profit << std::endl;
	}
	new_file.close();  // Закрытие файла после записи
	// Вывод сообщения о завершении обработки
	std::cout << "\nОбработка завершена. Результаты сохранены в файл new_file_5.txt";
}