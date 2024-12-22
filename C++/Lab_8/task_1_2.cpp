#include <iostream> // ����������� ���������� ��� �����-������
#include <stack>    // ����������� ���������� ��� ������ �� ������
#include <vector>   // ����������� ���������� ��� ������ � ��������
using namespace std; // ������������� ������������ ���� std
struct book // ����������� ��������� ��� �������� ���������� � �����
{
	char title[100]; // �������� �����
	double price;    // ���� �����
};
int main() // ����� ����� � ���������
{
	setlocale(LC_ALL, "RU"); // ��������� ������ ��� ����������� ����������� �������� �����
	book first_book = { "�����������", 150.55 }; // �������� ������ �����
	book second_book = { "����� ����", 135.75 }; // �������� ������ �����
	book third_book = { "������ ����", 160.25 }; // �������� ������� �����
	stack<book> stack_books; // �������� ����� ��� �������� ����
	stack_books.push(first_book); // ���������� ������ ����� � ����
	stack_books.push(second_book); // ���������� ������ ����� � ����
	stack_books.push(third_book); // ���������� ������� ����� � ����
	book new_book = { "����������", 95.45 }; // �������� ����� �����
	stack_books.push(new_book); // ���������� ����� ����� � ����
	vector<book> vector_books; // �������� ������� ��� �������� ����
	double total_price = 0.0; // ������������� ���������� ��� �������� ����� ��������� ����
	while (!stack_books.empty()) // ����, ���� ���� �� ����
	{
		book vector_book = stack_books.top(); // ��������� ������� ����� �� �����
		vector_books.push_back(vector_book); // ���������� ����� � ������
		total_price += vector_book.price; // ���������� ���� ����� � ����� ���������
		stack_books.pop(); // �������� ������� ����� �� �����
	}
	double average_price = total_price / vector_books.size(); // ���������� ������� ���� ����
	cout << "������ ���� ����, ������� �����:\n"; // ����� ���������
	for (int i = vector_books.size() - 1; i >= 0; --i) // ���� ��� ������ ���� � �������� �������
	{
		cout << "��������� �����: " << vector_books[i].title << "; ����: " << vector_books[i].price << " ���.\n"; // ����� ���������� � �����
	}
	cout << "\n������� ���� ����: " << average_price << " ���.\n"; // ����� ������� ���� ����
}