#include "bubblesort.h"
using namespace wan;

void BubbleSort::Sort(double *pData,int count)
{
	double temp;
	for (int i = 0; i < count; ++i)
	{
		for (int j = count-1; j >= i; --j)
		{
			if (pData[j] < pData[j-1])
			{
				temp = pData[j-1];
				pData[j-1] = pData[j];
				pData[j] = temp;
			}
		}
	}
}