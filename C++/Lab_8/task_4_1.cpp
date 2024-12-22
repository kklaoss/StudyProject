#include <iostream> // ����������� ���������� ��� �����-������
#include <forward_list> // ����������� ���������� ��� ������ � ����������� �������
using namespace std; // ������������� ������������ ���� std
void remove_before_55(forward_list<double>& list) // ����������� ������� ��� �������� �������� ����� 55
{
	auto prev = list.before_begin(); // ������������� ��������� prev ����� ������� ������
	auto current = list.begin(); // ������������� ��������� current �� ������ ������
	while (current != list.end() && next(current) != list.end() && *next(current) != 55) // ���� �� ����� ������ ��� �� �������� ����� 55
	{
		++prev; // ����������� ��������� prev �� ��������� �������
		++current; // ����������� ��������� current �� ��������� �������
	}
	if (current != list.end() && next(current) != list.end() && *next(current) == 55) // ��������, ��� ��������� ������� ����� 55
	{
		list.erase_after(prev); // �������� �������� ����� 55
	}
}
int main() // �������� ������� ���������
{
	setlocale(LC_ALL, "RU"); // ��������� ������ ��� ������ �� ������� �����
	forward_list<double> list = { 10.5, 20.5, 55.0, 30.5, 40.5 }; // ������������� ������ ����������
	cout << "������ ������: "; // ����� ���������
	for (double value : list) // ���� �� ��������� ������
	{
		cout << value << " "; // ����� �������� ������
	}
	cout << endl; // ������� �� ����� ������
	remove_before_55(list); // ����� ������� ��� �������� �������� ����� 55
	cout << "������ ����� ��������: "; // ����� ���������
	for (double value : list) // ���� �� ��������� ������
	{
		cout << value << " "; // ����� �������� ������
	}
	cout << endl; // ������� �� ����� ������
}