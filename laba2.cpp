// laba2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
	const int n = 100;
	int sort[n];
	int nesort[n];
	time_point<steady_clock> start;
	time_point<steady_clock> end;
	time_point<steady_clock> start1;
	time_point<steady_clock> end1;
	time_point<steady_clock> start2;
	time_point<steady_clock> end2;
	time_point<steady_clock> start3;
	time_point<steady_clock> end3;
	time_point<steady_clock> start4;
	time_point<steady_clock> end4;
	time_point<steady_clock> start5;
	time_point<steady_clock> end5;
	while (true)
	{
		setlocale(0, "");
		cout << "Выберите действие: " << "\n";
		cout << "1) Создать массив:" << "\n";
		cout << "2) Отсортировать массив:\n";
		cout << "3) Найти максимальный и минимальный элемент массива:\n";
		cout << "4) Найти среднее значение макс и мин элементов, индексы элементов равных ему и их количество:\n";
		cout << "5) Найти количество элементов в отсортированном массиве, которые меньше введенного вами числа:\n";
		cout << "6) Найти количество элементов в отсортированном массиве, которые больше введенного вами числа:\n";
		cout << "7) Определить есть ли введенное число в массиве:\n";
		cout << "8) Поменять местами элементы массива:\n";
		cout << "0) Завершить программу\n";
		cout << "Ваш выбор: ";
		int p;
		cin >> p;
		cout << "\n";
		if (p == 0)
			break;
		switch (p)
		{
		case 1:
			//1 ЗАДАНИЕ
			cout << "1) Неотсортированный массив: ";
			for (int i = 0; i < n; i++)
			{
				nesort[i] = rand() % 199 - 99;
				cout << nesort[i] << " ";
			}
			for (int i = 0; i < n; i++)
				sort[i] = nesort[i];
			cout << "\n\n\n";
			break;

		case 2:
			//2 ЗАДАНИЕ
			cout << "2) Отсортированный массив: ";
			start = chrono::steady_clock::now();
			int x, j;
			for (int i = 1; i < n; i++)
			{
				x = sort[i];
				j = i;
				while ((j > 0) && (x < sort[j - 1]))
				{
					sort[j] = sort[j - 1];
					j--;
				}
				sort[j] = x;
			}
			end = chrono::steady_clock::now();
			for (int i = 0; i < n; i++)
				cout << sort[i] << " ";
			cout << "\n";
			cout << "Затраченное время: " << duration_cast<microseconds>(end - start).count() << " мкс.";
			cout << "\n\n\n";
			break;

		case 3:
			//3 ЗАДАНИЕ
			//поиск max и min в отсортированном массиве
			start1 = chrono::steady_clock::now();
			int mns;
			mns = sort[0];
			int mas;
			mas = sort[0];
			for (int i = 0; i < n; i++)
			{
				if (sort[i] > mas)
					mas = sort[i];
				if (sort[i] < mns)
					mns = sort[i];
			}
			end1 = chrono::steady_clock::now();

			//поиск max и min в неотсортированном массиве
			start2 = chrono::steady_clock::now();
			int mn;
			mn = nesort[0];
			int ma;
			ma = nesort[0];
			for (int i = 0; i < n; i++)
			{
				if (nesort[i] > ma)
					ma = nesort[i];
				if (nesort[i] < mn)
					mn = nesort[i];
			}
			end2 = chrono::steady_clock::now();
			cout << "3) Максимальный элемент массива: " << mas << "\n";
			cout << "   Минимальный элемент массива: " << mns << "\n";
			cout << "   Затраченное время в отсорт массиве: " << duration_cast<nanoseconds>(end1 - start1).count() << "нс.";
			cout << "   Затраченное время в неотсорт. массиве: " << duration_cast<nanoseconds>(end2 - start2).count() << "нс.";
			cout << "\n\n\n";
			break;

		case 4:
			//4 ЗАДАНИЕ
			int sum;
			int mid;
			int k;
			k = 0;
			sum = mas + mns;
			if (sum % 2 != 0)
				sum += 1;
			mid = sum / 2;
			cout << "4) Среднее значение макс и мин элементов: " << mid << "\n";

			cout << "   Индексы элементов равных среднему значению макс и мин в отсорт массиве: ";
			start3 = chrono::steady_clock::now();
			for (int i = 0; i < n; i++)
			{
				if (sort[i] == mid)
				{
					cout << i << " ";
					k++;
				}

			}
			end3 = chrono::steady_clock::now();
			cout << "\n";

			cout << "   Индекс элементов равных среднему значению макс и мин в неотсорт массиве: ";
			start4 = chrono::steady_clock::now();
			for (int i = 0; i < n; i++)
			{
				if (nesort[i] == mid)
					cout << i << " ";
			}
			cout << "\n";
			cout << "   Количество элементов равных среднему значению: " << k;
			end4 = chrono::steady_clock::now();
			cout << "\n";
			cout << "   Затраченное время в отсорт массиве: " << duration_cast<microseconds>(end3 - start3).count() << "мкс." << "\n";
			cout << "   Затраченное время в неотсорт. массиве: " << duration_cast<microseconds>(end4 - start4).count() << "мкс." << "\n";
			cout << "\n\n";
			break;

		case 5:
			//5 ЗАДАНИЕ
			cout << "5) Введите число для вывода количества элементов меньших заданного числа: ";
			int ka;
			ka = 0;
			int a;
			cin >> a;
			for (int i = 0; i < n; i++)
			{
				if (sort[i] < a)
					ka += 1;
			}
			cout << "   Количесвто элементов меньше " << a << ": " << ka;
			cout << "\n\n\n";
			break;

		case 6:
			//6 ЗАДАНИЕ
			cout << "6) Введите число для вывода количества элементов больших заданного числа: ";
			int b;
			cin >> b;
			int kb;
			kb = 0;
			for (int i = 0; i < n; i++)
			{
				if (sort[i] > b)
					kb += 1;
			}
			cout << "   Количесвто элементов больше " << b << ": " << kb;
			cout << "\n\n\n";
			break;

		case 7:
			//7 ЗАДАНИЕ
			int num;
			int st;
			st = 0;
			int en;
			en = n;
			cout << "7)Задайте число, чтобы проверить есть ли оно в массиве: ";
			cin >> num;
			int midl;
			for (int i = st; i < en; i++)
			{
				midl = ((st + en) / 2) + ((st + en) % 2);
				if (num < sort[midl])
					en = midl;
				if (num > sort[midl])
					st = midl + 1;
				if (num == sort[st] or num == sort[midl])
					break;
			}
			if (num == sort[st] or num == sort[midl])
			{
				cout << "  Заданное число Есть\n\n";
				break;
			}
			else
			{
				cout << "  Заданного числа Нет\n\n";
				break;
			}
			cout << "\n\n\n";
			break;

		case 8:
			//8 ЗАДАНИЕ
			cout << "8) Введите индексы элементов массива, которые хотите поменять: " << "\n";
			start5 = chrono::steady_clock::now();
			int m, l;
			cin >> m >> l;
			int swap;
			swap = sort[l];
			sort[l] = sort[m];
			sort[m] = swap;
			end5 = chrono::steady_clock::now();
			cout << "Массив с переставленными элементами: ";
			for (int i = 0; i < n; i++)
				cout << sort[i] << " ";
			cout << "\n" << "Затраченное время на перестановку символов массива: " << duration_cast<milliseconds>(end5 - start5).count() << "мс." << "\n";
			break;
		}
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
