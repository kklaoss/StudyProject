// ����������� ����������� ��������� ��� �����/������ � ������ �� ��������
#include <iostream>
#include <string>
// ������� ������� ���������
int main()
{
	// ��������� ������� ������ ��� ����������� ����������� ���������
	setlocale(LC_ALL, "RU");
	// ���������� ���������� ��� �������� ������ ������
	std::string str_1;
	// ����� ����������� ��� ����� ������ ������
	std::cout << "������� ������ ������: ";
	// ������ ���� ������ �� ������� � ���������� � ���������� str_1
	std::getline(std::cin, str_1);
	// ���������� ���������� ��� �������� ������ ������
	std::string str_2;
	// ����� ����������� ��� ����� ������ ������
	std::cout << "������� ������ ������: ";
	// ������ ���� ������ �� ������� � ���������� � ���������� str_2
	std::getline(std::cin, str_2);
	// ���������� ����������-����� ��� ��������, ��� �� ������� �� ������ ������ ������� �� ������
	bool all_chars_found = true;
	// ������� ������� ������� ������ ������
	for (auto ch_1 : str_1)
	{
		// ���������� ����������-����� ��� ��������, ������ �� ������� ������ �� ������ ������
		bool found = false;
		// ������� ������� ������� ������ ������
		for (auto ch_2 : str_2)
		{
			// ���� ������ �� ������ ������ ������ �� ������ ������
			if (ch_1 == ch_2)
			{
				// ��������� ����� � true
				found = true;
				// ���������� ����������� �����
				break;
			}
		}
		// ���� ������ �� ������ ������ �� ������ �� ������ ������
		if (!found)
		{
			// ��������� ����� all_chars_found � false
			all_chars_found = false;
			// ���������� �������� �����
			break;
		}
	}
	// ��������, ��� �� ������� �� ������ ������ ������� �� ������ ������
	if (all_chars_found)
	{
		// ������� �� ����� ������ ��� ������� ������
		std::cout << std::endl;
		// ����� ��������� � ���, ��� ��� ������� �������
		std::cout << "��� ������� �� ������ ������ ����������� �� ������ ������." << std::endl;
	}
	else
	{
		// ������� �� ����� ������ ��� ������� ������
		std::cout << std::endl;
		// ����� ��������� � ���, ��� �� ��� ������� �������
		std::cout << "�� ��� ������� �� ������ ������ ����������� �� ������ ������." << std::endl;
	}
	// ����� ������� ��������� ��������� "computer" � ������ ������
	size_t pos_1 = str_1.find("computer");
	// ���� ��������� ��������� "computer" �������
	while (pos_1 != std::string::npos)
	{
		// ������ ��������� "computer" �� "PC" � ������ ������
		str_1.replace(pos_1, 8, "PC");
		// ����� ���������� ��������� ��������� "computer" ����� ������� �������
		pos_1 = str_1.find("computer", pos_1 + 2);
	}
	// ����� ������� ��������� ��������� "computer" �� ������ ������
	size_t pos_2 = str_2.find("computer");
	// ���� ��������� ��������� "computer" �������
	while (pos_2 != std::string::npos)
	{
		// ������ ��������� "computer" �� "PC" �� ������ ������
		str_2.replace(pos_2, 8, "PC");
		// ����� ���������� ��������� ��������� "computer" ����� ������� �������
		pos_2 = str_2.find("computer", pos_2 + 2);
	}
	// ����� ������ ������ ����� ������
	std::cout << "������ ������ ����� ������: " << str_1 << std::endl;
	// ����� ������ ������ ����� ������
	std::cout << "������ ������ ����� ������: " << str_2 << std::endl;
}