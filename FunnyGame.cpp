#include <iostream>
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	const unsigned short int size = 16;
	unsigned short int a[size], b[size], res = 0;
	short int stop = 0;
	unsigned short int n;

	ifstream fin("d.in.txt");
	ofstream fout("d.out.txt");
	while (fin >> n)
	{
		stop = 0; //Обнуляем переменную после каждого цикла
		res = 0;  //Обнуляем переменную после каждого цикла

		cout << n << endl;

		for (int i = 0; i < size; i++) // Превращаем десятично число в двоичное, но в обратном порядке
		{
			a[i] = n % 2;
			n = n / 2;
		}

		for (int i = 0; i < size; i++) // Разворачиваем массив
		{
			b[i] = a[15 - i];
		}

		for (int i = 0; i < size; i++) 
		{
			cout << b[i];
		}
		cout << endl;

		for (int i = 0; i < size; i++) // Находим кол-во незначащих нулуй
		{
			if (b[i] == 0 && b[i + 1] == 0)
			{
				stop++;
			}
			else
			{
				stop++; // Этот момент не совсем корректен, но т.к. максимум значений 32676
				break;  // У нас в любом случае будет 1 незначащий ноль, но в иделе это стоит исправить
			}
		}

		cout << "Незначущих нулей: " << stop << endl;

		int temp;

		for (int i = stop; i < size; i++) // Сортировка пузырьком для нахождения максимального двоичного числа
		{
			for (int j = stop; j < size - 1; j++)
			{
				if (b[j + 1] > b[j])
				{
					temp = b[j];
					b[j] = b[j + 1];
					b[j + 1] = temp;

				}
			}
		}

		for (int i = 0; i < size; i++) 
		{
			cout << b[i];
		}
		cout << endl;

		for (int i = 0; i < size; i++) // Возвращем максимальное число в десятичный вид
		{
			res = res + (b[i] * pow(2, 15 - i));
		}

		cout << res << endl << endl;

		fout << res << endl;
	}

	fin.close();
	fout.close();

	return 0;
}