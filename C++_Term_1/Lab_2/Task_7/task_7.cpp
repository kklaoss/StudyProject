#include <iostream> // ���������� ���������� ��� ������������� ������� �����-������
using namespace std; // ����������� ������������ ��� std
void f2_7(float X, float Y, float Z)
{
	int B, b; // ���������� ���� ���������� B � b ��� �������� ���� ���������� ��������
	if (X > Y) { // ���������, ������ �� X, ��� Y
		if (X > Z) { // ���� X ������ Z
			B = X; // ����������� B �������� X
			if (Y > Z) { b = Y; } // ���� Y ������ Z, ����������� b �������� Y
			else { b = Z; } // � ��������� ������ ����������� b �������� Z
		}
		else { B = Z; b = X; } // ���� X �� ������ Z
		// ����������� B �������� Z
		// ����������� b �������� X
	}
	else { // ���� X �� ������ Y
		if (Y > Z) { // ���������, ������ �� Y, ��� Z
			B = Y; // ����������� B �������� Y
			if (X > Z) { b = X; } // ���� X ������ Z, ����������� b �������� X
			else { b = Z; } // � ��������� ������ ����������� b �������� Z
		}
		else { B = Z; b = Y; } // ���� Y �� ������ Z
		// ����������� B �������� Z
		// ����������� b �������� Y
	}
	cout << " " << endl << "Two largest numbers: " << B << " " << b;
	// ������� ��� ���������� ����� B � b
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
	case 27: f2_7(a, b, c); break; // ���� ����� ����� 27, ���������� ������� f2_7 � ����������� a, b, c
	default: cout << "The task was not found";
		// ���� ����� �����, ������� �� ������������� �� ����� ������, ��������� ��������� �� ������
	}
	return 0; // ������� 0
}