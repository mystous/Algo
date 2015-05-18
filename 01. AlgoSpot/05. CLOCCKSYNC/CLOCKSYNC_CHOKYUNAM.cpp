#include <stdio.h>
#include <iostream>

using namespace std;

#define CLOCK_COUNT			16
#define BUTTON_COUNT		10
#define ACTION_MAX			5
#define CLICK_COUNT			5

#define FOR(A, B, C) for( A = B ; A < C ; ++A )

const int BUTTON_ACTION[BUTTON_COUNT][ACTION_MAX] = { { 0, 1, 2, -1, -1 }, { 3, 7, 9, 11, -1 }, { 4, 10, 14, 15, -1 }, { 0, 4, 5, 6, 7 }, { 6, 7, 8, 10, 12 }, { 0, 2, 14, 15, -1 }, { 3, 14, 15, -1, -1 }, { 4, 5, 7, 14, 15 }, { 1, 2, 3, 4, 5 }, { 3, 4, 5, 9, 13 } };
const int ACTION_COUNT[BUTTON_COUNT] = { 3, 4, 4, 5, 5, 4, 3, 5, 5, 5 };
int g_Count = 999999;

bool IsAllMidNight(int CLOCK_TIME[CLOCK_COUNT])
{
	int					i;

	FOR(i, 0, CLOCK_COUNT)
	{
		if (12 != CLOCK_TIME[i])
			return false;
	}

	return true;
}

void CheckClock(int oldCLOCK_TIME[CLOCK_COUNT], int nButtonIndex, int nClickCount)
{
	int				i, j;
	int				CLOCK_TIME[CLOCK_COUNT];

	if (BUTTON_COUNT == nButtonIndex)
		return;

	FOR(i, 0, CLOCK_COUNT)
		CLOCK_TIME[i] = oldCLOCK_TIME[i];

	FOR(i, 0, CLICK_COUNT)
	{
		if (0 != i)
		{
			FOR(j, 0, ACTION_COUNT[nButtonIndex])
			{
				CLOCK_TIME[BUTTON_ACTION[nButtonIndex][j]] += 3;
				if (CLOCK_TIME[BUTTON_ACTION[nButtonIndex][j]] > 12)
					CLOCK_TIME[BUTTON_ACTION[nButtonIndex][j]] %= 12;
			}

			nClickCount++;
			if (IsAllMidNight(CLOCK_TIME))
			{
				if (g_Count > nClickCount)
					g_Count = nClickCount;
			}
		}

		CheckClock(CLOCK_TIME, nButtonIndex + 1, nClickCount);
	}
}

int main()
{
	int			i, j, nTestCase;
	int			CLOCK_TIME[CLOCK_COUNT];
#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif //_WIN32

	cin >> nTestCase;
	FOR(i, 0, nTestCase)
	{
		FOR(j, 0, CLOCK_COUNT)
			cin >> CLOCK_TIME[j];

		g_Count = 999999;

		if (IsAllMidNight(CLOCK_TIME))
			g_Count = 0;
		else
			CheckClock(CLOCK_TIME, 0, 0);

		if (g_Count == 999999)
			g_Count = -1;

		cout << g_Count << endl;
	}
	return 0;
}
