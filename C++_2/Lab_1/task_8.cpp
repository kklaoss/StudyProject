#include <iostream>  // Подключение библиотеки для работы с вводом и выводом
#include <fstream>   // Подключение библиотеки для работы с файлами
#include <string>    // Подключение библиотеки для работы со строками
#include <vector>    // Подключение библиотеки для работы с векторами
// Определение структуры Car, которая представляет автомобиль
struct Car
{
	std::string brand;         // Марка автомобиля
	std::string manufacturer;  // Производитель автомобиля
	int year;                  // Год выпуска автомобиля
	std::string engine_type;   // Тип двигателя автомобиля
	int mileage;               // Пробег автомобиля в километрах
	double price;              // Цена автомобиля
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
	// Создание и открытие бинарного файла для записи данных
	std::ofstream out_file("cars.dat", std::ios::binary);
	// Запись данных о каждом автомобиле из вектора cars в файл
	for (const auto& car : cars)
	{
		out_file.write((char*)&car, sizeof(Car));  // Запись структуры Car в бинарном формате
	}
	out_file.close();  // Закрытие файла после записи
	// Создание вектора out_cars для хранения данных, считанных из файла
	std::vector<Car> out_cars;
	// Открытие бинарного файла для чтения данных
	std::ifstream in_file("cars.dat", std::ios::binary);
	Car car;
	// Чтение данных из файла и добавление их в вектор out_cars
	while (in_file.read((char*)&car, sizeof(Car)))
	{
		out_cars.push_back(car);  // Добавление считанной структуры Car в вектор out_cars
	}
	in_file.close();  // Закрытие файла после чтения
	// Вывод информации об автомобилях, которые удовлетворяют условиям (пробег < 100 км и цена < 200000 грн)
	for (const auto& car : out_cars)
	{
		if (car.mileage < 100 && car.price < 200000)
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
}