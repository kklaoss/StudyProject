#include <iostream>  // ����������� ���������� ��� ������ � ������ � �������
#include <fstream>   // ����������� ���������� ��� ������ � �������
#include <vector>    // ����������� ���������� ��� ������������� ���������� vector
// ����������� ��������� Data ��� �������� ���� (����, �����, ���)
struct Data
{
	int day;    // ���� ��� �������� ���
	int month;  // ���� ��� �������� ������
	int year;   // ���� ��� �������� ����
};
int main()
{
	setlocale(LC_ALL, "RU");  // ��������� ������ ��� ��������� �������� �����
	Data data;  // �������� ������� ��������� Data ��� ���������� �������� ����
	std::vector<Data> dates;  // �������� ������� ��� �������� ���� ��� �� �����
	// �������� ����� "file_6.txt" ��� ������
	std::ifstream out_file("file_6.txt");
	// ������ ������ �� ����� ��������� � ���������� �� � ������ dates
	while (out_file >> data.day >> data.month >> data.year)
	{
		dates.push_back(data);  // ���������� ����������� ���� � ������
	}
	out_file.close();  // �������� ����� ����� ������
	// ����� ����������� ��������� ����� �� �����
	std::cout << "���������� ��������� �����:" << std::endl;
	for (const auto& data : dates)
	{
		// ����� ������ ���� � ������� "���� ����� ���"
		std::cout << data.day << " " << data.month << " " << data.year << std::endl;
	}
	std::vector<Data> filtered_dates;  // �������� ������� ��� �������� ��������������� ���
	// ���������� ���: ��������� ������ ��, ������� �������� � �������� � ����� �� ���
	for (const auto& data : dates)
	{
		if (data.month >= 3 && data.month <= 5)
		{
			filtered_dates.push_back(data);  // ���������� ���������� ���� � ����� ������
		}
	}
	// �������� ����� "new_file_6.txt" ��� ������
	std::ofstream new_file("new_file_6.txt");
	// ������ ��������������� ��� � ����� ����
	for (const auto& data : filtered_dates)
	{
		new_file << data.day << " " << data.month << " " << data.year << std::endl;
	}
	new_file.close();  // �������� ����� ����� ������
	// ����� ��������� �� �������� ���������� ���������
	std::cout << "\n��������� ���������. ���������� ��������� � ���� new_file_6.txt";
}