#include <iostream> // ����������� ���������� ��� �����-������
#include <forward_list> // ����������� ���������� ��� ������ � ����������� �������
using namespace std; // ������������� ������������ ���� std
void remove_first_greater_than_four(forward_list<int>& list) // ������� ��� �������� ������� ��������, �������� 4
{
	for (auto iter = list.begin(); iter != list.end(); ++iter) // ���� �� ��������� ������
	{
		if (*iter > 4) // ���� ������� ������� ������ 4
		{
			list.erase_after(iter); // ������� ������� ����� ��������
			break; // ������� �� �����
		}
	}
}
void insert_ten_before_fifteen(forward_list<int>& list) // ������� ��� ������� 10 ����� ������ 15
{
	for (auto iter = list.begin(); iter != list.end(); ++iter) // ���� �� ��������� ������
	{
		if (*iter == 15) // ���� ������� ������� ����� 15
		{
			iter = list.insert_after(iter, 10); // ��������� 10 ����� �������� ��������
			++iter; // ��������� � ���������� ��������
		}
	}
}
void print_list(const forward_list<int>& list) // ������� ��� ������ ������
{
	for (int value : list) // ���� �� ��������� ������
	{
		cout << value << " "; // ����� ��������
	}
	cout << endl; // ������� �� ����� ������
}
int main() // �������� �������
{
	setlocale(LC_ALL, "ru"); // ��������� ������ ��� ������ �� ������� �����
	forward_list<int> list = { 8, 3, 5, 10, 15, 7 }; // ������������� ������
	cout << "������ ������: "; // ����� ���������
	print_list(list); // ������ ������
	remove_first_greater_than_four(list); // �������� ������� ��������, �������� 4
	cout << "����� �������� ������� �������� ������ 4: "; // ����� ���������
	print_list(list); // ������ ������
	insert_ten_before_fifteen(list); // ������� 10 ����� ������ 15
	cout << "����� ������� 10 ����� ������ 15: "; // ����� ���������
	print_list(list); // ������ ������
}
