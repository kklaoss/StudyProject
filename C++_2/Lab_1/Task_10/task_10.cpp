#include <iostream>  // Подключение библиотеки для работы с вводом и выводом
#include <fstream>   // Подключение библиотеки для работы с файлами
#include <vector>    // Подключение библиотеки для использования контейнера vector
#include <string>    // Подключение библиотеки для работы со строками
// Определение структуры Product, которая представляет товар
struct Product
{
	std::string name;  // Название товара
	int year;          // Год изготовления
	double price;      // Цена товара
	int months;        // Количество прошедших месяцев
};
int main()
{
	setlocale(LC_ALL, "RU");  // Установка локали для поддержки кириллицы
	// Создание и открытие бинарного файла для записи данных
	std::ofstream out_file("products.dat", std::ios::binary);
	// Создание вектора products, содержащего несколько товаров
	std::vector<Product> products =
	{
		{"Молоко", 2025, 100.0, 12},
		{"Хлеб", 2025, 50.0, 15},
		{"Сыр", 2025, 200.0, 20},
		{"Вода", 2025, 30.0, 5}
	};
	// Запись каждого товара из вектора в бинарный файл
	for (const auto& product : products)
	{
		out_file.write((char*)&product, sizeof(Product));
	}
	out_file.close();  // Закрытие файла после записи
	std::vector<Product> filtered_products;  // Создание вектора для хранения отфильтрованных товаров
	// Открытие бинарного файла для чтения данных
	std::ifstream in_file("products.dat", std::ios::binary);
	Product temp;  // Временная переменная для хранения данных о товаре
	// Чтение данных из файла и добавление их в вектор filtered_products
	while (in_file.read((char*)&temp, sizeof(Product)))
	{
		filtered_products.push_back(temp);
	}
	in_file.close();  // Закрытие файла после чтения
	// Применение скидок к ценам товаров в зависимости от количества прошедших месяцев
	for (auto& product : filtered_products)
	{
		if (product.months >= 15)
		{
			product.price *= 0.90;  // Скидка 10% если прошло 15 и более месяцев
		}
		else if (product.months >= 10)
		{
			product.price *= 0.95;  // Скидка 5% если прошло от 10 до 14 месяцев
		}
	}
	// Создание и открытие нового бинарного файла для записи обновленных данных
	std::ofstream out_new("products.dat", std::ios::binary);
	// Запись обновленных данных о товарах в новый файл
	for (const auto& product : filtered_products)
	{
		out_new.write((char*)&product, sizeof(Product));
	}
	out_new.close();  // Закрытие файла после записи
	// Открытие бинарного файла для чтения и отображения данных
	std::ifstream display("products.dat", std::ios::binary);
	// Чтение данных из файла и вывод информации о каждом товаре на экран
	while (display.read((char*)&temp, sizeof(Product)))
	{
		std::cout << "Название товара: " << temp.name << std::endl;
		std::cout << "Год изготовления: " << temp.year << std::endl;
		std::cout << "Цена: " << temp.price << std::endl;
		std::cout << "Количество прошедших месяцев: " << temp.months << std::endl;
		std::cout << "\n-----------------------------------\n";
	}
	display.close();  // Закрытие файла после отображения данных
}