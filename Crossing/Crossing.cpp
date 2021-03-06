#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "typedef.h"
#include "checkcrossing.h"

int main(int argc, char **argv)
{
	// Включення української мови.
	setlocale(LC_CTYPE, "ukr");

	//Оголошення зiмнних
	float pry[2], A[2], B[2], C;
	int c;

	// Оголошення призначення програми.
	printf("Ця програма перевiряє, чи перетинаються:\nВiдрiзок типу:   A(x1, y1), B(x2,y2)\nПряма типу:      ax + b = y \n");

	if (argc == 7)
	{
		char *fail;
		A[0] = strtof(argv[1], &fail);
		A[1] = strtof(argv[2], &fail);
		B[0] = strtof(argv[3], &fail);
		B[1] = strtof(argv[4], &fail);
		pry[0] = strtof(argv[5], &fail);
		pry[1] = strtof(argv[6], &fail);
		if (*fail != 0)
		{
			printf("\nБудь ласка, введiть коректнi данi.\n");
			return 0;
		}
	}
	else if ((argc == 2) && ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "-?") == 0)))
	{
		printf("\n   Програму розробив здобувач I курсу НАУ iменi М. Є. Жуковського \"ХАi\" студент групи 515i2 Олександр СIРОКЛИН.\n\n   Завдання:\n   Необхiдно розробити консольний додаток Windows на мовi C, що отримує вiд користувача координати двох точок (А та В), що формують вiдрiзок, та коефiцiєнти a та b для формули прямої y = ax + b, та завдяки отриманим даним виводить, чи перетинаються вiдрiзок з прямою, чи нi.\n   Якщо програму запущено з шiстьма параметрами командного рядка, програма не запитує данi у користувача, а iнтерпретує їх як координати точок A та B та коефiцiєнти, та одразу виводить iнформацiю щодо можливого перетину, або повiдомлення про помилку, якщо один або декiлька параметрiв некоректнi(наприклад, вони не є числами, або їх менше, нiж 6).\n   Якщо програма запущена з аргументом - h або - ? , то програма має вивести iнформацiю з використання програми та завершити її виконання.\n   Усi повiдомлення програми мають бути українською мовою.\n");
		return 0;
	}
	else if (argc == 1)
	{
		// Вiдрiзок.
		printf("\nВведiть x1: ");
		scanf("%f", &A[0]);
		printf("Введiть y1: ");
		scanf("%f", &A[1]);
		printf("Введiть x2: ");
		scanf("%f", &B[0]);
		printf("Введiть y2: ");
		scanf("%f", &B[1]);
		// Пряма
		printf("Введiть a : ");
		scanf("%f", &pry[0]);
		printf("Введiть b : ");
		scanf("%f", &pry[1]);
	}
	else
	{
		printf("\nБудь ласка, введiть коректнi данi.\n");
		return 0;
	}

	// Показ користувачу його даних у зручному форматi.
	printf("\nВашi данi:\nВiдрiзок:   A(%.2f, %.2f), B(%.2f, %.2f).\nПряма:      ", A[0], A[1], B[0], B[1]);
	if (pry[1] >= 0)
		printf("%.2fx + %.2f = y.\n", pry[0], pry[1]);
	else
		printf("%.2fx - %.2f = y.\n", pry[0], pry[1] * (-1));

	if ((A[0] == B[0]) && (A[1] == B[1]))
	{
		printf("\nТочки A i В не можуть знаходитися у однiй точцi.\n");
		return 0;
	}

	C = checkcrossing(A, B, pry);
	c = (int)C;

	switch (c)
	{
	case 0:
		printf("\nНi, пряма та вiдрiзок не перетинаються.\n");
		break;
	case 1:
		printf("\nТак, пряма та вiдрiзок перетинаються у точцi:   C(%.2f, %.2f).\n", res[0], res[1]);
		break;
	case 2:
		printf("\nВiдрiзок знаходиться у прямiй.\n");
		break;
	case 3:
		printf("\nВiдрiзок та пряма паралельнi.\n");
		break;
	}

	return 0;
}
