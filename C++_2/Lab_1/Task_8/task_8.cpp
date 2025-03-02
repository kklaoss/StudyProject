#include <iostream>  // Подключение библиотеки для работы с вводом и выводом
#include <fstream>   // Подключение библиотеки для работы с файлами
#include <string>    // Подключение библиотеки для работы со строками
#include <vector>    // Подключение библиотеки для работы с векторами (динамическими массивами)
// Определение структуры Car, которая представляет автомобиль
struct Car
{
	std::string brand;         // Марка автомобиля
	std::string manufacturer;  // Производитель автомобиля
	int year;                  // Год выпуска автомобиля
	std::string engine_type;   // Тип двигателя автомобиля
	int mileage;               // Пробег автомобиля в километрах
	double price;              // Цена автомобиля в гривнах
};
int main()
{
	setlocale(LC_ALL, "RU");  // Установка локали для поддержки русского языка
	// Создание вектора cars, содержащего информацию о нескольких автомобилях
	std::vector<Car> cars =
	{
		{"Toyota", "Toyota Motor Corporation", 2020, "Petrol", 50, 190000},
		{"Honda", "Honda Motor Co.", 2019, "Diesel", 150, 210000},
		{"BMW", "BMW AG", 2021, "Electric", 30, 180000},
		{"Audi", "Audi AG", 2018, "Petrol", 80, 250000}
	};
	// Создание и открытие бинарного файла "cars.dat" для записи
	std::ofstream out_file("cars.dat", std::ios::binary);
	// Запись каждого автомобиля из вектора cars в бинарный файл
	for (const auto& car : cars)
	{
		out_file.write((char*)&car, sizeof(Car));
	}
	out_file.close();  // Закрытие файла после записи
	std::vector<Car> filtered_cars;  // Создание вектора для хранения отфильтрованных автомобилей
	// Открытие бинарного файла "cars.dat" для чтения
	std::ifstream in_file("cars.dat", std::ios::binary);
	Car car;  // Создание временного объекта Car для чтения данных из файла
	// Чтение данных из файла и фильтрация автомобилей по пробегу и цене
	while (in_file.read((char*)&car, sizeof(Car)))
	{
		if (car.mileage < 100 && car.price < 200000)
		{
			filtered_cars.push_back(car);  // Добавление подходящего автомобиля в вектор filtered_cars
		}
	}
	in_file.close();  // Закрытие файла после чтения
	// Создание и открытие бинарного файла "cars.dat" для записи отфильтрованных данных
	std::ofstream out_new("cars.dat", std::ios::binary);
	// Запись каждого отфильтрованного автомобиля в бинарный файл
	for (const auto& car : filtered_cars)
	{
		out_new.write((char*)&car, sizeof(Car));
	}
	out_new.close();  // Закрытие файла после записи
	// Открытие бинарного файла "cars.dat" для чтения и вывода данных на экран
	std::ifstream display("cars.dat", std::ios::binary);
	// Чтение данных из файла и вывод информации об автомобилях на экран
	while (display.read((char*)&car, sizeof(Car)))
	{
		std::cout << "Марка: " << car.brand << std::endl;
		std::cout << "Производитель: " << car.manufacturer << std::endl;
		std::cout << "Год выпуска: " << car.year << std::endl;
		std::cout << "Тип двигателя: " << car.engine_type << std::endl;
		std::cout << "Пробег: " << car.mileage << " км" << std::endl;
		std::cout << "Цена: " << car.price << " грн" << std::endl;
		std::cout << "---------------------------" << std::endl;
	}
}