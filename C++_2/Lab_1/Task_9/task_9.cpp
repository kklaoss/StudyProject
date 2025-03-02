#include <iostream>  // ����������� ���������� ��� ������ � ������ � �������
#include <fstream>   // ����������� ���������� ��� ������ � �������
#include <string>    // ����������� ���������� ��� ������ �� ��������
#include <vector>    // ����������� ���������� ��� ������ � ��������� (������������� ���������)
int main()
{
	setlocale(LC_ALL, "RU");  // ��������� ������ ��� ��������� ��������� � �������
	std::string input;  // ���������� ���������� ��� �������� �������� ������������� ������
	std::cout << "������� �������: ";  // ����� ����������� ��� ����� ��������
	getline(std::cin, input);  // ���������� �������� ������ � ����������
	std::ofstream out_file("data.dat", std::ios::binary);  // �������� ������� ��� ������ � ���� "data.dat" � �������� ������
	out_file.write(input.c_str(), input.size());  // ������ �������� ������ � ���� ��� �������� ������
	out_file.close();  // �������� ����� ����� ������
	std::cout << "\n�� ��������������: ";  // ����� ��������� ����� ������������ ������ �� ��������������
	std::ifstream in_file("data.dat", std::ios::binary);  // �������� ������� ��� ������ �� ����� "data.dat" � �������� ������
	char ch;  // ���������� ���������� ��� �������� ������ ������� �� �����
	std::vector<int> codes;  // ���������� ������� ��� �������� ����� ��������
	while (in_file >> ch)  // ������ �������� �� ����� �� ������
	{
		std::cout << ch << " ";  // ����� �������� ������� �� �����
		codes.push_back(static_cast<unsigned char>(ch));  // �������������� ������� � ��� �������� ��� � ���������� � ������
	}
	in_file.close();  // �������� ����� ����� ������
	out_file.open("data.dat", std::ios::binary);  // �������� ����� "data.dat" ��� ������ � �������� ������
	for (int code : codes)  // ���� �� ���� ��������� ������� � ������ ��������
	{
		out_file.write(reinterpret_cast<const char*>(&code), sizeof(int));  // ������ ��������� ���� ������� � ���� ��� �������� ������
	}
	out_file.close();  // �������� ����� ����� ������
	std::cout << "\n����� ��������������: ";  // ����� ��������� ����� ������������ ������ ����� ��������������
	in_file.open("data.dat", std::ios::binary);  // �������� ����� "data.dat" ��� ������ � �������� ������
	int code;  // ���������� ���������� ��� �������� ��������� ���� �������
	while (in_file.read(reinterpret_cast<char*>(&code), sizeof(int)))  // ������ �������� ����� �������� �� �����
	{
		std::cout << code << " ";  // ����� ��������� ���� ������� �� �����
	}
	std::cout << std::endl;  // ������� �� ����� ������ ����� ������ ���� �����
}