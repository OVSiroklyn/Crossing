#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include "typedef.h"
#include "checkcrossing.h"

int main(void)
{
	// Включення української мови.
	setlocale(LC_CTYPE, "ukr");

	//Оголошення зімнних
	float pry[2], A[2], B[2], C;

	// Оголошення призначення програми.
	printf("\nЦя програма перевiряє, чи перетинаються:\nВiдрiзок типу:   A(x1, y1), B(x2,y2)\nПряма типу:      ax + b = y \n\n");

	// Відрізок.
	printf("Введiть x1: ");
	scanf("%f", &A[0]);
	printf("Введiть y1: ");
	scanf("%f", &A[1]);
	printf("Введiть x2: ");
	scanf("%f", &B[0]);
	if (A[0] == B[0]) // Перевiрка на помилку.
		ver = true;
	printf("Введiть y2: ");
	scanf("%f", &B[1]);
	// Пряма
	printf("Введiть a : ");
	scanf("%f", &pry[0]);
	printf("Введiть b : ");
	scanf("%f", &pry[1]);


	// Показ користувачу його даних у зручному форматі.
	printf("\nВашi данi:\nВiдрiзок:   A(%.2f, %.2f), B(%.2f, %.2f).\nПряма:      ", A[0], A[1], B[0], B[1]);
	if (pry[1] >= 0)
		printf("%.2fx + %.2f = y.\n", pry[0], pry[1]);
	else
		printf("%.2fx - %.2f = y.\n", pry[0], pry[1] * (-1));

	C = checkcrossing(A, B, pry);

	if (C == 1)
		printf("\nТак, пряма та вiдрiзок перетинаються у точцi:   C(%.2f, %.2f).\n", res[0], res[1]);
	else
		printf("\nНi, пряма та вiдрiзок не перетинаються.\n");


	return 0;
}
