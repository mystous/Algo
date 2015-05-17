#include <stdio.h>
#include <iostream>

using namespace std;

#define FOR(A, B, C) for( A = B ; A < C ; ++A )

int		g_H, g_W;
int		g_Count;
int		g_colOffset[4][3] = { { 0, 1, 0 }, { 0, 1, 1 }, { 0, 0, 1 }, { 0, 0, -1 } };
int		g_rowOffset[4][3] = { { 0, 0, 1 }, { 0, 0, 1 }, { 0, 1, 1 }, { 0, 1, 1 } };

bool FindFirstSlot(int &row, int &col, int MAZE[20][20])
{
	int			i, j;

	FOR(i, 0, g_H)
	{
		FOR(j, 0, g_W)
		{
			if (0 == MAZE[i][j])
			{
				row = i;
				col = j;
				return true;
			}
		}
	}

	return false;
}

void FindSolution(int MAZE[20][20], int nRow, int nCol, int nWhiteCount, int nType)
{
	int				i, row, col, bCanFill = true;
	int				myMAZE[20][20];

	if (nRow >= g_H || nCol >= g_W || nWhiteCount < 3)
		return;

	FOR(row, 0, g_H)
		FOR(col, 0, g_W)
		myMAZE[row][col] = MAZE[row][col];

	FOR(i, 0, 3)
	{
		if (nRow + g_rowOffset[nType][i] >= g_H || nRow + g_rowOffset[nType][i] < 0 || nCol + g_colOffset[nType][i] >= g_W || nCol + g_colOffset[nType][i] < 0)
			return;

		if (0 != myMAZE[nRow + g_rowOffset[nType][i]][nCol + g_colOffset[nType][i]])
		{
			bCanFill = false;
			break;
		}
		else
		{
			myMAZE[nRow + g_rowOffset[nType][i]][nCol + g_colOffset[nType][i]] = 1;
			nWhiteCount--;
		}
	}

	if (!bCanFill)
		return;

	if (0 == nWhiteCount)
	{
		g_Count++;
		return;
	}

	row = nRow;
	col = nCol;
	if (FindFirstSlot(row, col, myMAZE))
	{
		FOR(i, 0, 4)
			FindSolution(myMAZE, row, col, nWhiteCount, i);
	}
}

int main()
{
	int				nTestCase, i, j, k;
	char			chMap;
	int				MAZE[20][20];
	int				nWhiteCount, row, col;

#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif //_WIN32

	cin >> nTestCase;
	FOR(i, 0, nTestCase)
	{
		g_Count = 0;
		nWhiteCount = 0;
		cin >> g_H;
		cin >> g_W;
		FOR(j, 0, g_H)
		{
			FOR(k, 0, g_W)
			{
				cin >> chMap;
				if ('#' == chMap)
					MAZE[j][k] = -1;
				else
				{
					nWhiteCount++;
					MAZE[j][k] = 0;
				}
			}
		}

		row = 0;
		col = 0;

		if (FindFirstSlot(row, col, MAZE))
		{
			FOR(j, 0, 4)
				FindSolution(MAZE, row, col, nWhiteCount, j);
		}
		cout << g_Count << endl;
	}

	return 0;
}
