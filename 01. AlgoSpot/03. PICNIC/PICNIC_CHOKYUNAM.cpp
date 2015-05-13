#include <stdio.h>
#include <iostream>

using namespace std;

#define FOR(A, B, C) for( A = B ; A < C ; ++A )

int		nStudent[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

int		g_nStudentCount;
int		g_nCoupleCount;
int		g_Couple[45][2];
int		g_nCase;
int		g_nSuccessCase;
int		g_nMatchCase;

void CheckCouple(int nSelectCouple, int nMatchCase, int nCase, bool bUsedCouple[45])
{
	int				i, j;
	bool			bUsedCoupleCopy[45];

	FOR(i, 0, g_nCoupleCount)
		bUsedCoupleCopy[i] = bUsedCouple[i];

	if (-1 != nSelectCouple)
	{
		if (0 != (nMatchCase & nStudent[g_Couple[nSelectCouple][0]]))
			return;
		if (0 != (nMatchCase & nStudent[g_Couple[nSelectCouple][1]]))
			return;

		bUsedCoupleCopy[nSelectCouple] = true;

		nMatchCase |= nStudent[g_Couple[nSelectCouple][0]];
		nMatchCase |= nStudent[g_Couple[nSelectCouple][1]];

		if (g_nMatchCase == nMatchCase)
		{
			g_nSuccessCase++;
			return;
		}
	}

	if (nCase == g_nCase)
		return;

	FOR(i, 0, g_nCoupleCount)
	{
		if (bUsedCoupleCopy[i])
			continue;

		CheckCouple(i, nMatchCase, nCase + 1, bUsedCoupleCopy);
		bUsedCoupleCopy[i] = true;
	}
	
	//bUsedCouple[nSelectCouple] = false;
}

int main()
{
	int				nTestcases;
	int				i, j, k;

#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif //_WIN32

	cin >> nTestcases;

	FOR(i, 0, nTestcases)
	{
		int		nMatchCase = 0;
		bool	bUsedCouple[45];
		
		cin >> g_nStudentCount;
		cin >> g_nCoupleCount;
		g_nCase = g_nStudentCount / 2;
		g_nSuccessCase = 0;

		g_nMatchCase = 1;
		FOR(j, 0, g_nStudentCount)
			g_nMatchCase *= 2;
		g_nMatchCase -= 1;

		FOR(j, 0, g_nCoupleCount)
		{
			cin >> g_Couple[j][0];
			cin >> g_Couple[j][1];
			bUsedCouple[j] = false;
		}

		CheckCouple(-1, nMatchCase, 0, bUsedCouple);
		cout << g_nSuccessCase << endl;
	}


	return 0;
}
