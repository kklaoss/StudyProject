#include <iostream>  // ����������� ���������� ��� ������ � ������ � �������
#include <fstream>   // ����������� ���������� ��� ������ � �������
#include <string>    // ����������� ���������� ��� ������ �� ��������
#include <vector>    // ����������� ���������� ��� ������ � ���������
// ����������� ��������� Car, ������� ������������ ����������
struct Car
{
	std::string brand;         // ����� ����������
	std::string manufacturer;  // ������������� ����������
	int year;                  // ��� ������� ����������
	std::string engine_type;   // ��� ��������� ����������
	int mileage;               // ������ ���������� � ����������
	double price;              // ���� ����������
};
int main()
{
	setlocale(LC_ALL, "RU");  // ��������� ������ ��� ��������� �������� �����
	// �������� ������� cars, ����������� ���������� � ���������� �����������
	std::vector<Car> cars =
	{
		{"Toyota", "Toyota Motor Corporation", 2020, "Petrol", 50, 190000},
		{"Honda", "Honda Motor Co.", 2019, "Diesel", 150, 210000},
		{"BMW", "BMW AG", 2021, "Electric", 30, 180000},
		{"Audi", "Audi AG", 2018, "Petrol", 80, 250000}
	};
	// �������� � �������� ��������� ����� ��� ������ ������
	std::ofstream out_file("cars.dat", std::ios::binary);
	// ������ ������ � ������ ���������� �� ������� cars � ����
	for (const auto& car : cars)
	{
		out_file.write((char*)&car, sizeof(Car));  // ������ ��������� Car � �������� �������
	}
	out_file.close();  // �������� ����� ����� ������
	// �������� ������� out_cars ��� �������� ������, ��������� �� �����
	std::vector<Car> out_cars;
	// �������� ��������� ����� ��� ������ ������
	std::ifstream in_file("cars.dat", std::ios::binary);
	Car car;
	// ������ ������ �� ����� � ���������� �� � ������ out_cars
	while (in_file.read((char*)&car, sizeof(Car)))
	{
		out_cars.push_back(car);  // ���������� ��������� ��������� Car � ������ out_cars
	}
	in_file.close();  // �������� ����� ����� ������
	// ����� ���������� �� �����������, ������� ������������� �������� (������ < 100 �� � ���� < 200000 ���)
	for (const auto& car : out_cars)
	{
		if (car.mileage < 100 && car.price < 200000)
		{
			std::cout << "�����: " << car.brand << std::endl;
			std::cout << "�������������: " << car.manufacturer << std::endl;
			std::cout << "��� �������: " << car.year << std::endl;
			std::cout << "��� ���������: " << car.engine_type << std::endl;
			std::cout << "������: " << car.mileage << " ��" << std::endl;
			std::cout << "����: " << car.price << " ���" << std::endl;
			std::cout << "---------------------------" << std::endl;
		}
	}
}