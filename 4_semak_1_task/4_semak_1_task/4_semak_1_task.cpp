// 4_semak_1_task.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "locale.h"
#include "conio.h"
#include "stdlib.h"
#include <iostream>
#include "DynamicArray.h"

int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "RUS");
	system("color 75");

	const int N = 7;
	const int H = 5;
	const int n = 1;

	cout << "Start" << "\n";
	DynamicArray work;
	DynamicArray arr1 = DynamicArray(N);
	cout << "First ";
	work.operator<<(arr1);
	cout << "\n";
	DynamicArray arr2 = DynamicArray(H, n);
	cout << "Second ";
	work.operator<<(arr2);
	cout << "\n";
	DynamicArray arr3 = DynamicArray(arr2);
	cout << "Copy of Second ";
	work.operator<<(arr2);
	cout << "\n";
	cout << "First array == Second array ? " << ((operator==(arr1, arr2)) ? "yes" : "no") << ".\n";
	cout << "First array != Second array ? " << ((operator!=(arr1, arr2)) ? "yes" : "no") << ".\n";
	cout << "First array < Second array ? " << ((operator<(arr1, arr2)) ? "yes" : "no") << ".\n";
	cout << "First array <= Second array ? " << ((operator<=(arr1, arr2)) ? "yes" : "no") << ".\n";
	cout << "First array > Second array ? " << ((operator>(arr1, arr2)) ? "yes" : "no") << ".\n";
	cout << "First array >= Second array ? " << ((operator>=(arr1, arr2)) ? "yes" : "no") << ".\n";
	cout << "Length of Second array: " << arr2.length()<<"\n";
	cout << "Second element of First array: " << arr1.getElem(2) << "\n";
	cout << "Thirst array with new size '3': ";
	arr3.resize(3);
	work.operator<<(arr3);
	cout << "\n";
	int x = 15;
	arr1.pushBack(x);
	cout << "We pushBack x = 15 in First array: ";
	work.operator<<(arr1);
	cout << "\n";
	

	printf("Thank you! Goodbye!");
	_getch();

	return 0;
}
