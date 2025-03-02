#include <iostream>  // Подключение библиотеки для работы с вводом и выводом
#include <fstream>   // Подключение библиотеки для работы с файлами
#include <vector>    // Подключение библиотеки для использования контейнера vector
// Определение структуры Data для хранения даты (день, месяц, год)
struct Data
{
	int day;    // Поле для хранения дня
	int month;  // Поле для хранения месяца
	int year;   // Поле для хранения года
};
int main()
{
	setlocale(LC_ALL, "RU");  // Установка локали для поддержки русского языка
	Data data;  // Создание объекта структуры Data для временного хранения даты
	std::vector<Data> dates;  // Создание вектора для хранения всех дат из файла
	// Открытие файла "file_6.txt" для чтения
	std::ifstream in_file("file_6.txt");
	// Чтение данных из файла построчно и сохранение их в вектор dates
	while (in_file >> data.day >> data.month >> data.year)
	{
		dates.push_back(data);  // Добавление прочитанной даты в вектор
	}
	in_file.close();  // Закрытие файла после чтения
	// Вывод содержимого исходного файла на экран
	std::cout << "Содержимое исходного файла:" << std::endl;
	for (const auto& data : dates)
	{
		// Вывод каждой даты в формате "день месяц год"
		std::cout << data.day << " " << data.month << " " << data.year << std::endl;
	}
	std::vector<Data> filtered_dates;  // Создание вектора для хранения отфильтрованных дат
	// Фильтрация дат: оставляем только те, которые попадают в диапазон с марта по май
	for (const auto& data : dates)
	{
		if (data.month >= 3 && data.month <= 5)
		{
			filtered_dates.push_back(data);  // Добавление подходящей даты в новый вектор
		}
	}
	// Открытие файла "new_file_6.txt" для записи
	std::ofstream new_file("new_file_6.txt");
	// Запись отфильтрованных дат в новый файл
	for (const auto& data : filtered_dates)
	{
		new_file << data.day << " " << data.month << " " << data.year << std::endl;
	}
	new_file.close();  // Закрытие файла после записи
	// Вывод сообщения об успешном завершении обработки
	std::cout << "\nОбработка завершена. Результаты сохранены в файл new_file_6.txt";
}