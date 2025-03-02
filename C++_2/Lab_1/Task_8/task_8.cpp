#include <iostream>  // ����������� ���������� ��� ������ � ������ � �������
#include <fstream>   // ����������� ���������� ��� ������ � �������
#include <string>    // ����������� ���������� ��� ������ �� ��������
#include <vector>    // ����������� ���������� ��� ������ � ��������� (������������� ���������)
// ����������� ��������� Car, ������� ������������ ����������
struct Car
{
	std::string brand;         // ����� ����������
	std::string manufacturer;  // ������������� ����������
	int year;                  // ��� ������� ����������
	std::string engine_type;   // ��� ��������� ����������
	int mileage;               // ������ ���������� � ����������
	double price;              // ���� ���������� � �������
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
	// �������� � �������� ��������� ����� "cars.dat" ��� ������
	std::ofstream out_file("cars.dat", std::ios::binary);
	// ������ ������� ���������� �� ������� cars � �������� ����
	for (const auto& car : cars)
	{
		out_file.write((char*)&car, sizeof(Car));
	}
	out_file.close();  // �������� ����� ����� ������
	std::vector<Car> filtered_cars;  // �������� ������� ��� �������� ��������������� �����������
	// �������� ��������� ����� "cars.dat" ��� ������
	std::ifstream in_file("cars.dat", std::ios::binary);
	Car car;  // �������� ���������� ������� Car ��� ������ ������ �� �����
	// ������ ������ �� ����� � ���������� ����������� �� ������� � ����
	while (in_file.read((char*)&car, sizeof(Car)))
	{
		if (car.mileage < 100 && car.price < 200000)
		{
			filtered_cars.push_back(car);  // ���������� ����������� ���������� � ������ filtered_cars
		}
	}
	in_file.close();  // �������� ����� ����� ������
	// �������� � �������� ��������� ����� "cars.dat" ��� ������ ��������������� ������
	std::ofstream out_new("cars.dat", std::ios::binary);
	// ������ ������� ���������������� ���������� � �������� ����
	for (const auto& car : filtered_cars)
	{
		out_new.write((char*)&car, sizeof(Car));
	}
	out_new.close();  // �������� ����� ����� ������
	// �������� ��������� ����� "cars.dat" ��� ������ � ������ ������ �� �����
	std::ifstream display("cars.dat", std::ios::binary);
	// ������ ������ �� ����� � ����� ���������� �� ����������� �� �����
	while (display.read((char*)&car, sizeof(Car)))
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