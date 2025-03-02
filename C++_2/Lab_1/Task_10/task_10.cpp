#include <iostream>  // ����������� ���������� ��� ������ � ������ � �������
#include <fstream>   // ����������� ���������� ��� ������ � �������
#include <vector>    // ����������� ���������� ��� ������������� ���������� vector
#include <string>    // ����������� ���������� ��� ������ �� ��������
// ����������� ��������� Product, ������� ������������ �����
struct Product
{
	std::string name;  // �������� ������
	int year;          // ��� ������������
	double price;      // ���� ������
	int months;        // ���������� ��������� �������
};
int main()
{
	setlocale(LC_ALL, "RU");  // ��������� ������ ��� ��������� ���������
	// �������� � �������� ��������� ����� ��� ������ ������
	std::ofstream out_file("products.dat", std::ios::binary);
	// �������� ������� products, ����������� ��������� �������
	std::vector<Product> products =
	{
		{"������", 2025, 100.0, 12},
		{"����", 2025, 50.0, 15},
		{"���", 2025, 200.0, 20},
		{"����", 2025, 30.0, 5}
	};
	// ������ ������� ������ �� ������� � �������� ����
	for (const auto& product : products)
	{
		out_file.write((char*)&product, sizeof(Product));
	}
	out_file.close();  // �������� ����� ����� ������
	std::vector<Product> filtered_products;  // �������� ������� ��� �������� ��������������� �������
	// �������� ��������� ����� ��� ������ ������
	std::ifstream in_file("products.dat", std::ios::binary);
	Product temp;  // ��������� ���������� ��� �������� ������ � ������
	// ������ ������ �� ����� � ���������� �� � ������ filtered_products
	while (in_file.read((char*)&temp, sizeof(Product)))
	{
		filtered_products.push_back(temp);
	}
	in_file.close();  // �������� ����� ����� ������
	// ���������� ������ � ����� ������� � ����������� �� ���������� ��������� �������
	for (auto& product : filtered_products)
	{
		if (product.months >= 15)
		{
			product.price *= 0.90;  // ������ 10% ���� ������ 15 � ����� �������
		}
		else if (product.months >= 10)
		{
			product.price *= 0.95;  // ������ 5% ���� ������ �� 10 �� 14 �������
		}
	}
	// �������� � �������� ������ ��������� ����� ��� ������ ����������� ������
	std::ofstream out_new("products.dat", std::ios::binary);
	// ������ ����������� ������ � ������� � ����� ����
	for (const auto& product : filtered_products)
	{
		out_new.write((char*)&product, sizeof(Product));
	}
	out_new.close();  // �������� ����� ����� ������
	// �������� ��������� ����� ��� ������ � ����������� ������
	std::ifstream display("products.dat", std::ios::binary);
	// ������ ������ �� ����� � ����� ���������� � ������ ������ �� �����
	while (display.read((char*)&temp, sizeof(Product)))
	{
		std::cout << "�������� ������: " << temp.name << std::endl;
		std::cout << "��� ������������: " << temp.year << std::endl;
		std::cout << "����: " << temp.price << std::endl;
		std::cout << "���������� ��������� �������: " << temp.months << std::endl;
		std::cout << "\n-----------------------------------\n";
	}
	display.close();  // �������� ����� ����� ����������� ������
}