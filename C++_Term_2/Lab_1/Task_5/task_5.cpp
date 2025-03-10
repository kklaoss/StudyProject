#include <iostream>  // ����������� ���������� ��� ������ � ������ � �������
#include <fstream>   // ����������� ���������� ��� ������ � �������
#include <vector>    // ����������� ���������� ��� ������������� ���������� vector
#include <string>    // ����������� ���������� ��� ������ �� ��������
// ����������� ��������� Book, ������� ������������ ���������� � �����
struct Book
{
	std::string title;       // �������� �����
	std::string second_name; // ������� ������
	std::string first_name;  // ��� ������
	int year;                // ��� �������
	std::string publisher;   // ������������
	double cost;             // ������������� �����
	double price;            // ���� �����
	double profit;           // ������� �� �����
};
int main()
{
	setlocale(LC_ALL, "RU");  // ��������� ������ ��� ��������� ���������
	std::vector<Book> books;  // �������� ������� ��� �������� �������� ���� Book
	std::ifstream in_file("file_5.txt");  // �������� ����� ��� ������ ������
	Book book;  // �������� ���������� ������� Book ��� �������� ������ �� �����
	// ������ ������ �� ����� � ���������� �� � ������ books
	while (in_file >> book.title >> book.second_name >> book.first_name >> book.year >> book.publisher >> book.cost >> book.price >> book.profit)
	{
		books.push_back(book);  // ���������� ������� book � ������ books
	}
	in_file.close();  // �������� ����� ����� ������
	// ����� ����������� ��������� ����� �� �����
	std::cout << "���������� ��������� �����:" << std::endl;
	for (const auto& book : books)
	{
		std::cout << book.title << " " << book.second_name << " " << book.first_name << " " << book.year << " " << book.publisher << " " << book.cost << " " << book.price << " " << book.profit << std::endl;
	}
	std::vector<Book> filtered_books;  // �������� ������� ��� �������� ��������������� ����
	// ���������� ���� �� ������� ������ (������������ �� 'K')
	for (const auto& book : books)
	{
		if (book.second_name[0] == 'K')
		{
			filtered_books.push_back(book);  // ���������� ����� � ��������������� ������
		}
	}
	std::ofstream new_file("new_file_5.txt");  // �������� ����� ��� ������ ��������������� ������
	// ������ ��������������� ������ � ����� ����
	for (const auto& book : filtered_books)
	{
		new_file << book.title << " " << book.second_name << " " << book.first_name << " " << book.year << " " << book.publisher << " " << book.cost << " " << book.price << " " << book.profit << std::endl;
	}
	new_file.close();  // �������� ����� ����� ������
	// ����� ��������� � ���������� ���������
	std::cout << "\n��������� ���������. ���������� ��������� � ���� new_file_5.txt";
}