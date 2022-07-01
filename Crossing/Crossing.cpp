#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
//#include "func.h"

float * transmutate(float *tA, float *tB);
float * crossing(float *cA, float *cB);

int main(void)
{
	// Включення української мови.
	setlocale(LC_CTYPE, "ukr");

	//Оголошення зімнних
	float pry[2], A[2], B[2];

	// Оголошення призначення програми.
	printf("Ця програма перевiряє, чи перетинаються:\nВiдрiзок типу:   A(x1, y1), B(x2,y2)\nПряма типу:      ax + b = y \n\n");

	// Відрізок.
	printf("Введiть x1: ");
	scanf("%f", &A[0]);
	printf("Введiть y1: ");
	scanf("%f", &A[1]);
	printf("Введiть x2: ");
	scanf("%f", &B[0]);
	if (A[0] == B[0]) // Перевiрка на помилку.
	{
		printf("x2 не може дорiвнювати x1.");
		return 0;
	}
	printf("Введiть y2: ");
	scanf("%f", &B[1]);
	// Пряма
	printf("Введiть a: ");
	scanf("%f", &pry[0]);
	printf("Введiть b: ");
	scanf("%f", &pry[1]);


	// Показ користувачу його даних у зручному форматі.
	printf("\nВашi данi:\nВiдрiзок:   A(%.2f, %.2f), B(%.2f, %.2f).\nПряма:      ", A[0], A[1], B[0], B[1]);
	if (pry[1] >= 0)
		printf("%.2fx + %.2f = y.\n", pry[0], pry[1]);
	else
		printf("%.2fx - %.2f = y.\n", pry[0], pry[1] * (-1));

	// Визначення прямої, що проходить через вiдрiзок АВ.
	float *vid;
	vid = transmutate(A, B);

	if (vid[1] >= 0)
		printf("\nПряма, що проходить через AB:   %.2fx + %.2f = y.\n", vid[0], vid[1]);
	else
		printf("\nПряма, що проходить через AB:   %.2fx - %.2f = y.\n", vid[0], vid[1] * (-1));

	printf("\nРандомные тесты посреди кода:\nC(%.2f, %.2f) ", vid[0], vid[1]);
	printf("C(%.2f, %.2f) \n\n", pry[0], pry[1]);

	// Визначення точки перетину двох прямих (З коефіцієнтами ab і cd).
	float *res;
	res = crossing(pry, vid);

	printf("C(%.2f, %.2f) ", res[0], res[1]);

	// Перевірка, чи належить ця точка перетину відрізку. 
	if ((pow((A[0] - B[0]), 2) + pow((A[1] - B[1]), 2)) == ((pow((A[0] - res[0]), 2) + pow((A[1] - res[1]), 2)) + (pow((res[0] - B[0]), 2) + pow((res[1] - B[1]), 2))))
		printf("\nТак, пряма та вiдрiзок перетинаються у точцi:   C(%.2f, %.2f) ", res[0], res[1]);
	else
		printf("\nНi, пряма та вiдрiзок не перетинаються.\n");


	return 0;
}


float * transmutate(float *tA, float *tB)
{
	float t_fin[2];
	t_fin[0] = (tA[1] - tB[1]) / (tA[0] - tB[0]);
	t_fin[1] = tB[1] - t_fin[0] * tB[0];
	return(t_fin);
}

float * crossing(float *cA, float *cB)
{
	float c_fin[2];
	c_fin[0] = (cB[1] - cA[1]) / (cA[0] - cB[0]);
	c_fin[1] = cA[0] * c_fin[0] + cA[1];
	return(c_fin);
}