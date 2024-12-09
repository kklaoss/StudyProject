﻿#include <iostream>  // Подключяем библиотеки для ввода-вывода
#include <vector>    // Подключяем библиотеки для работы с векторами
using namespace std;  // Используем пространства имен std
void №1()
{
	int n; // Объявляем целочисленную переменную n, которая будет использоваться для хранения количества элементов в массиве
	const int max_size = 100; // Объявляем константную целочисленную переменную max_sixe со значением 100, которая будет использоваться для ограничения размера массива
	int array[max_size]; // Объявляем целочисленный массив array размером max_size (100 элементов)
	cout << "Введите количество элементов в массиве (n <= 100): "; // Запрос на ввод количества элементов в массиве
	cin >> n; // Считываем значение, введенное пользователем, и сохраняет его в переменную n
	if (n <= 0 || n > max_size) // Проверяем, что значение n находится в допустимом диапазоне (от 1 до 100)
	{
		cout << "\n(!) Количество элементов должно быть в диапазоне от 1 до 100\n"; // Выводим на консоль сообщение об ошибке, если значение n не соответствует допустимому диапазону
		return; // Возвращаем ничего
	}
	cout << "\nВведите элементы массива (натуральные числа <= 100):\n\n"; // Выводим на консоль запрос на ввод элементов массива
	for (int i = 0; i < n; ++i)
	{
		cout << "Элемент " << i + 1 << ": ";
		cin >> array[i]; // Цикл for последовательно считывает n элементов с клавиатуры и сохраняет их в массив array
	}
	int last_element = array[n - 1]; // Сохраняем последний элемент массива в переменную last_element
	for (int i = n - 1; i > 0; --i)
	{
		array[i] = array[i - 1]; // Цикл for сдвигает все элементы массива на одну позицию вправо, начиная с последнего
	}
	array[0] = last_element; // Помещаем последний элемент массива в начало массива
	cout << "\nРезультат: "; // Выводим на консоль заголовок для вывода результата
	for (int i = 0; i < n; ++i)
	{
		cout << array[i] << " "; // Цикл for последовательно выводит все элементы массива на консоль
	}
	cout << endl;
}

void enlarge(vector<int>& vec)
{
	if (vec.size() < 2)
	{
		return;  // Если в векторе меньше двух элементов, ничего не делаем
	}
	vector<int> result;  // Создаём новый вектор для хранения результата
	for (size_t i = 0; i < vec.size() - 1; ++i) // Цикл по элементам вектора
	{
		result.push_back(vec[i]);  // Добавляем текущий элемент в результат
		result.push_back((vec[i] + vec[i + 1]) / 2);  // Добавляем полусумму текущего и следующего элемента
	}
	result.push_back(vec.back());  // Добавляем последний элемент исходного вектора
	vec = result;  // Присваиваем исходному вектору новый вектор
}
void №2()
{
	vector<int> vec = { 0, 2, 4, 6, 8, 10 };  // Создаём вектор с начальными значениями
	cout << "Исходный вектор: ";  // Выводим текст "Исходный вектор: "
	for (size_t i = 0; i < vec.size(); ++i) // Цикл по элементам вектора
	{
		cout << vec[i] << " ";  // Выводим элементы вектора
	}
	cout << endl;  // Переход на новую строку
	enlarge(vec);  // Вызоваем функцию enlarge для изменения вектора
	cout << "\nИзменённый вектор: ";  // Выводим текст "Изменённый вектор: "
	for (size_t i = 0; i < vec.size(); ++i) // Цикл по элементам вектора
	{
		cout << vec[i] << " ";  // Выводим элементы изменённого вектора
	}
	cout << endl;  // Переход на новую строку
}

int main()
{
	setlocale(LC_ALL, "RUS"); //  Устанавливаем локаль операционной системы на русский язык, чтобы обеспечить корректный вывод русских символов.
	№2(); // Вызываем функцию №2()
	return 0; // Возвращаем 0
}