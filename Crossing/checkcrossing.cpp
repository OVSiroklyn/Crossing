
#include "typedef.h"
#include "func.h"

float checkcrossing(float *ccA, float *ccB, float *ccpry)
{
	if (ver == false) //Звичайний випадок.
	{
		// Визначення прямої, що проходить через вiдрiзок АВ.
		float *fast, vid[2];
		fast = transmutate(ccA, ccB);
		vid[0] = fast[0];
		vid[1] = fast[1];

		// Визначення точки перетину двох прямих (З коефіцієнтами ab і cd).
		fast = crossing(ccpry, vid);
		res[0] = fast[0];
		res[1] = fast[1];
	}
	else // Якщо відрізок паралельний осі у.
	{
		res[0] = ccA[0];
		res[1] = ccpry[0] * ccA[0] + ccpry[1];
	}

	// Визначення довжин вiдрiзкiв.
	float len_vid0, len_res1, len_res2;
	len_vid0 = len(ccA, ccB);
	len_res1 = len(res, ccA);
	len_res2 = len(res, ccB);

	// Перевірка, чи належить ця точка перетину відрізку. 
	if (len_vid0 == len_res1 + len_res2)
		return 1;
	else
		return 0;

}