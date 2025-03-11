// Подключение стандартных библиотек для ввода/вывода, работы со строками и строковыми потоками
#include <iostream>
#include <string>
#include <sstream>
// Главная функция программы
int main()
{
	// Установка русской локали для корректного отображения кириллицы
	setlocale(LC_ALL, "RU");
	// Объявление переменной для хранения введенного текста
	std::string text;
	// Вывод приглашения для ввода текста
	std::cout << "Введите текст: ";
	// Чтение всей строки текста из консоли
	std::getline(std::cin, text);
	// Переход на новую строку после ввода
	std::cout << std::endl;
	// Счетчики: слов на 'A' и слов "few"/"Few"
	int count_A = 0;
	int count_few_or_Few = 0;
	// Поиск первого вхождения подстроки "dollar" в тексте
	size_t pos = text.find("dollar");
	// Цикл замены всех вхождений "dollar" на "ruble"
	while (pos != std::string::npos)
	{
		// Замена 6 символов "dollar" на "ruble" (5 символов)
		text.replace(pos, 6, "ruble");
		// Поиск следующего вхождения "dollar" после текущей позиции замены
		pos = text.find("dollar", pos + 5);
	}
	// Создание строкового потока для разбиения текста на отдельные слова
	std::istringstream in_string(text);
	// Переменная для хранения текущего слова из потока
	std::string word;
	// Извлечение слов из потока по одному
	while (in_string >> word)
	{
		// Проверка: начинается ли слово на 'A'
		if (!word.empty() && word[0] == 'A')
		{
			count_A++; // Увеличение счетчика слов на 'A'
		}
		// Проверка: является ли слово "few" или "Few"
		if (word == "few" || word == "Few")
		{
			count_few_or_Few++; // Увеличение счетчика слов "few/Few"
		}
	}
	// Вывод результатов с использованием сырых строк для кавычек
	std::cout << R"(Количество слов, начинающихся на "A": )" << count_A << std::endl;
	std::cout << R"(Количество слов "few" или "Few": )" << count_few_or_Few << std::endl;
	std::cout << R"(Текст после замены "dollar" на "ruble": )" << text << std::endl;
}