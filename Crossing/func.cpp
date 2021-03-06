
#include <math.h>
#include "typedef.h"

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

float len(float *kat1, float *kat2)
{
	return (sqrt(pow((kat1[0] - kat2[0]), 2) + pow((kat1[1] - kat2[1]), 2)));
}
