#include <stdio.h>
#include <iostream>
using namespace std;

#define FOR(A,B,C) for( A = B ; A < C ; ++A )
#define MAX_DATE		1000

int cost[MAX_DATE];

void InitCost()
{
	int		i;

	FOR(i, 0, MAX_DATE)
		cost[i] = 0;
}
int main() 
{
	int			nTestCase, t, c, i, j, k, nLoop, nLoop2;
	int			N, L;
	double		avg = 0.0, min = 0.0;
#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif //_WIN32

	cin >> nTestCase;
	FOR(t, 0, nTestCase)
	{
		cin >> N;
		cin >> L;
		FOR(c, 0, N)
			cin >> cost[c];
		
		nLoop = N + 1;
		min = 10000000;
		FOR(i, L, nLoop)
		{
			nLoop2 = N - i + 1;
			
			FOR(j, 0, nLoop2)
			{
				avg = 0.0;
				FOR(k, j, i + j)
					avg += cost[k];
				avg /= i;
				if (avg < min)
					min = avg;
			}
		}
		//cout << min << endl;
		printf("%.12f\n", min);
	}

	return 0;
}
