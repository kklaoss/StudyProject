#include <iostream> // ���������� ���������� ��� ������������� ������� �����-������
#include <cmath> // ���������� ���������� ��� ���������� �������������� ��������
using namespace std; // ����������� ������������ ��� std
int main()
{
	float c;
	cout << "c = "; cin >> c;
	float PI = 3.14159265, S, b, a; // ���������� ��������� PI � ���������� S, b, a
	b = c * cos(PI / 3); // ���������� ����� ������� b ������������, ��������� ������� ���� 60 �������� (PI/3)
	a = c * sin(PI / 3); // ���������� ����� ������� a ������������, ��������� ����� ���� 60 �������� (PI/3)
	S = a * b; // ���������� ������� S ������������, ��������� ������� S = a * b
	cout << S; // ����� ������� S �� �����
	return 0; // ������� 0
}