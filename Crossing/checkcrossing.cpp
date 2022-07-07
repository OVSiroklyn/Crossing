
#include "typedef.h"
#include "func.h"

float checkcrossing(float *ccA, float *ccB, float *ccpry)
{
	if (ccA[0] != ccB[0]) 	// ��������, ���� ������ ������������.
	{
		// ���������� �����, �� ��������� ����� �i��i��� ��.
		float *fast, vid[2];
		fast = transmutate(ccA, ccB);
		vid[0] = fast[0];
		vid[1] = fast[1];
		
		if ((vid[0] == ccpry[0]) && (vid[1] == ccpry[1])) // ��������, �� �������� ������ �����
			return 2;
		else if (vid[0] == ccpry[0])
			return 3;
		else
		{
			// ���������� ����� �������� ���� ������ (� ������������� ab � cd).
			fast = crossing(ccpry, vid);
			res[0] = fast[0];
			res[1] = fast[1];
		}
	}
	else // ���� ������ ����������� �� �.
	{
		res[0] = ccA[0];
		res[1] = ccpry[0] * ccA[0] + ccpry[1];
	}

	// ���������� ������ �i��i��i�.
	float len_vid0, len_res1, len_res2;
	len_vid0 = len(ccA, ccB);
	len_res1 = len(res, ccA);
	len_res2 = len(res, ccB);

	// ��������, �� �������� �� ����� �������� ������. 
	if (len_vid0 == len_res1 + len_res2)
		return 1;
	else
		return 0;

}