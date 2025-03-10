#include <iostream> // ���������� ���������� ��� ������������� ������� �����-������
using namespace std; // ����������� ������������ ��� std
void f2_idz2(int num)
{
	cout << " " << endl << "The serial number of the day in the year: " << num << endl;
	// ������ � ������������ ����� ����������� ������ ��� � ����
	int day; // ���������� ������������� ���������� day ��� �������� ��� ������
	day = (num - 1) % 7;
	// ���������� ��� ������, ��������� ������� �� ������� �� 7
	// (num - 1) ������������, ����� ������� 1-� ���� ���� ������ 0 (�����������)
	switch (day) // ���������� switch ��� ����������� ��� ������
	{
	case 0: cout << "This Monday" << endl; break; // ���� day ����� 0, ������� "��� �����������"
	case 1: cout << "This Tuesday" << endl; break;  // ���� day ����� 1, ������� "��� �������"
	case 2: cout << "This Wednesday" << endl; break; // ���� day ����� 2, ������� "��� �����"
	case 3: cout << "This Thursday" << endl; break; // ���� day ����� 3, ������� "��� �������"
	case 4: cout << "This Friday" << endl; break; // ���� day ����� 4, ������� "��� �������"
	case 5: cout << "This Saturday" << endl; break; // ���� day ����� 5, ������� "��� �������"
	case 6: cout << "This Sunday" << endl; break; // ���� day ����� 6, ������� "��� �����������"
	default: cout << "Incorrect day number. Please enter a number from 1 to 365" << endl;
		// ���� ������ ������������ ����� ���, ������� ��������� �� ������
	}
}
int main() // ������ �������� ������� ���������
{
	float a, b, c, d; // ���������� ���������� ��� �������� ��������
	cout << "Enter the variables:" << endl << " " << endl;  // ����� ��������� ��� ������������
	cout << "Variable 1 - "; cin >> a; // ������ ����� ������ ����������
	cout << "Variable 2 - "; cin >> b; // ������ ����� ������ ����������
	cout << "Variable 3 - "; cin >> c; // ������ ����� ������� ����������
	cout << "Variable 4 - "; cin >> d; // ������ ����� ��������� ����������
	int nomer; // ���������� ���������� ��� �������� ������ ������
	cout << " " << endl << "Specify the task number: "; cin >> nomer; // ������ ����� ������ ������ �� ������������
	switch (nomer) // ������������� ��������� switch ��� ������ ������ �� ������
	{
	case 212: f2_idz2(a); break; // ���� ����� ����� 212, ���������� ������� f2_idz2 � ���������� a
	default: cout << "The task was not found";
		// ���� ����� �����, ������� �� ������������� �� ����� ������, ��������� ��������� �� ������
	}
	return 0; // ������� 0
}