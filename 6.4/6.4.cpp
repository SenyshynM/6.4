// lab 6.4
// варіант 10

#include <iostream>
#include <iomanip>
using namespace std;

void Print(int* a, const int size);
void Create(int* a, const int size, const int Low, const int High);
int sum(int* a, const int size);
int find_zero(int* a, const int size);
int min(int* a, const int size);
void format_mas(int* a, int* b, int size);

int main()
{
	srand((unsigned)time(0));

	int n;
	cout << "n = "; cin >> n;
	int* a = new int[n];
	int* b = new int[n];

	Create(a, n, -10, 10);
	cout << "array = ";
	Print(a, n);

	cout << "min element =" << setw(6) << min(a, n) << endl;
	cout << "sum after zero  = " << sum(a, n) << endl;
	format_mas(a, b, n);
	cout << "array = ";
	Print(b, n);

	getchar();
}

void format_mas(int* a, int* b, const int size) // в завданні не було вказано, чи можна використовувати додатковий масив
{
	int k = 0;

	for (int i = 0; i < size; i += 2)
		b[k++] = a[i];

	for (int i = 1; i < size; i += 2)
		b[k++] = a[i];
}

void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << '\n';
}

void Create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}

int sum(int* a, const int size)
{
	int i = find_zero(a, size);
	int sum = 0;
	for (i; i < size; i++)
	{
		sum += abs(a[i]);
	}
	return sum;
}

int find_zero(int* a, const int size)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] == 0)
			return i;
	}
}

int min(int* a, const int size) 
{
	int m = a[0];
	for (int i = 1; i < size; i++)
	{
		if (abs(a[i]) < abs(m))
		{ 
			m = a[i];
		}
	}
	return m; // повертаємо найменший за модулем елемент
}