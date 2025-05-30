// ����������� ����������� ���������� �����/������
#include <iostream>
// ����������� ����������� ���������� ��� ������ � ���������
#include <vector>
// ����������� ������������� ����� � ����������� ������ Worker
#include "task_2.h"
// ������� ������� ���������
int main()
{
	// ��������� ������� ������ ��� ����������� ����������� ���������
	setlocale(LC_ALL, "RU");
	// �������� ������� worker_1 � ����������� ("Petrov", 75000, 1990)
	Worker worker_1("Petrov", 75000, 1990);
	// ����� ���������� � worker_1
	worker_1.print();
	// ���������� � ����� �������� worker_1
	worker_1.age();
	// ���������� � ����� ���� �� 50-����� worker_1
	worker_1.days_until_50();
	// ���������� ��� �������� ���������� ����������
	int count;
	// ������ ��� �������� �������� Worker
	std::vector<Worker> workers;
	// ������ ���������� ���������� � ������������
	std::cout << "\n\n������� ���������� ����������: ";
	std::cin >> count;
	// �������� ������������ ���������� ����������
	if (count <= 0)
	{
		// ����� ��������� �� ������, ���� ���������� �� �������������
		std::cout << "������������ ����������!" << std::endl;
		// ������� ���� ������
		return 1;
	}
	// ����������� ������ ��� ���� ��������
	workers.reserve(count);
	// ������ �� ���� ���������� � ����������
	std::cout << "��������� ���������� � ����������:" << std::endl;
	// ���� ��� ����� ���������� � ������ ���������
	for (int i = 0; i < count; ++i)
	{
		// ���������� ��� ���������� �������� �������� ������
		std::string name;
		double salary;
		int year;
		// ����� ������ �������� ���������
		std::cout << "\n������ #" << i + 1 << std::endl;
		// ������ ������� ���������
		std::cout << "������� �������: ";
		std::cin >> name;
		// ������ �������� ���������
		std::cout << "������� �����: ";
		std::cin >> salary;
		// ������ ���� �������� ���������
		std::cout << "������� ��� ��������: ";
		std::cin >> year;
		// ���������� ������ ������� Worker � ������
		workers.emplace_back(name, salary, year);
	}
	// ����� ��������� ��� ������� � ������������
	std::cout << "\n����������:" << std::endl;
	// ���� ��� ������ ���������� � ���� ����������
	for (size_t i = 0; i < workers.size(); ++i)
	{
		// ����� ������ �������� ���������
		std::cout << "\n������ #" << i + 1 << std::endl;
		// ����� ���������� � ���������
		workers[i].print();
		// ���������� � ����� �������� ���������
		workers[i].age();
		// ���������� � ����� ���� �� 50-����� ���������
		workers[i].days_until_50();
		// ������� �� ����� ������ ��� ������� ������
		std::cout << std::endl;
	}
}