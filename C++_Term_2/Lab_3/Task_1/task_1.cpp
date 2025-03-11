// ����������� ����������� ��������� ��� �����/������, ������ �� �������� � ���������� ��������
#include <iostream>
#include <string>
#include <sstream>
// ������� ������� ���������
int main()
{
	// ��������� ������� ������ ��� ����������� ����������� ���������
	setlocale(LC_ALL, "RU");
	// ���������� ���������� ��� �������� ���������� ������
	std::string text;
	// ����� ����������� ��� ����� ������
	std::cout << "������� �����: ";
	// ������ ���� ������ ������ �� �������
	std::getline(std::cin, text);
	// ������� �� ����� ������ ����� �����
	std::cout << std::endl;
	// ��������: ���� �� 'A' � ���� "few"/"Few"
	int count_A = 0;
	int count_few_or_Few = 0;
	// ����� ������� ��������� ��������� "dollar" � ������
	size_t pos = text.find("dollar");
	// ���� ������ ���� ��������� "dollar" �� "ruble"
	while (pos != std::string::npos)
	{
		// ������ 6 �������� "dollar" �� "ruble" (5 ��������)
		text.replace(pos, 6, "ruble");
		// ����� ���������� ��������� "dollar" ����� ������� ������� ������
		pos = text.find("dollar", pos + 5);
	}
	// �������� ���������� ������ ��� ��������� ������ �� ��������� �����
	std::istringstream in_string(text);
	// ���������� ��� �������� �������� ����� �� ������
	std::string word;
	// ���������� ���� �� ������ �� ������
	while (in_string >> word)
	{
		// ��������: ���������� �� ����� �� 'A'
		if (!word.empty() && word[0] == 'A')
		{
			count_A++; // ���������� �������� ���� �� 'A'
		}
		// ��������: �������� �� ����� "few" ��� "Few"
		if (word == "few" || word == "Few")
		{
			count_few_or_Few++; // ���������� �������� ���� "few/Few"
		}
	}
	// ����� ����������� � �������������� ����� ����� ��� �������
	std::cout << R"(���������� ����, ������������ �� "A": )" << count_A << std::endl;
	std::cout << R"(���������� ���� "few" ��� "Few": )" << count_few_or_Few << std::endl;
	std::cout << R"(����� ����� ������ "dollar" �� "ruble": )" << text << std::endl;
}