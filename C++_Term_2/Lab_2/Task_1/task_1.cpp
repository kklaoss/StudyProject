// ����������� ������������� ����� � ����������� ������ Num
#include "task_1.h"
// ����������� ����������� ���������� ��� �����/������
#include <iostream>
// ���������� ������������ ������ Num
Num::Num(int in_x, int in_y)
{
	// ������������� ���� x ��������� ��������� in_x
	x = in_x;
	// ������������� ���� y ��������� ��������� in_y
	y = in_y;
}
// ���������� ������ print()
void Num::print() const
{
	// ����� �������� x � y
	std::cout << "�������� x: " << x << "\n�������� y: " << y << std::endl;
}
// ���������� ������ math()
void Num::math() const
{
	// ��������, ���� x ������ y
	if (x > y)
	{
		// ����� �������� y (��� ��� y ������)
		std::cout << "\n������� �������� �� �����: " << y * y << std::endl;
	}
	else
	{
		// ����� �������� x (��� ��� x ������ ��� ����� y)
		std::cout << "\n������� �������� �� �����: " << x * x << std::endl;
	}
}