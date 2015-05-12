#include <stdio.h>
#include <iostream>

using namespace std;

#define FOR(A, B, C) for( A = B ; A < C ; ++A )

char	BOARD[5][5];
char	WORD[11];
int		CACHE[5][5][10];
int		nLen;

int Judgement(int m, int n, int nWordIndex)
{
	if (m < 0 || m > 4 || n < 0 || n > 4)
		return 0;

	int &ret = CACHE[m][n][nWordIndex];

	if (-1 != ret)
		return ret;

	if (BOARD[m][n] != WORD[nWordIndex])
		return ret = 0;

	nWordIndex++;

	if (nWordIndex >= nLen)
		return ret = 1;

	ret = (Judgement(m - 1, n - 1, nWordIndex) || Judgement(m - 1, n, nWordIndex) || Judgement(m - 1, n + 1, nWordIndex) || Judgement(m, n - 1, nWordIndex) || Judgement(m, n + 1, nWordIndex) || Judgement(m + 1, n - 1, nWordIndex) || Judgement(m + 1, n, nWordIndex) || Judgement(m + 1, n + 1, nWordIndex));
	return ret;
}

int StrLen()
{
	int			i;

	FOR(i, 0, 11)
	{
		if (NULL == WORD[i])
			return i;
	}

	return 0;
}

int main()
{
	int				nTestcases, nWordCount;
	int				i, j, k, m, n;
	bool			bFound = false;

#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif //_WIN32

	cin >> nTestcases;
	FOR(i, 0, nTestcases)
	{
		FOR(j, 0, 5)
			FOR(k, 0, 5)
			cin >> BOARD[j][k];

		cin >> nWordCount;
		FOR(j, 0, nWordCount)
		{
			FOR(k, 0, 5)
				FOR(m, 0, 5)
				FOR(n, 0, 10)
				CACHE[k][m][n] = -1;

			bFound = false;
			cin >> WORD;
			nLen = StrLen();
			FOR(m, 0, 5)
			{
				FOR(n, 0, 5)
				{
					if (1 == Judgement(m, n, 0))
					{
						bFound = true;
						break;
					}
				}

				if (bFound)
					break;
			}

			if (bFound)
				cout << WORD << " YES" << endl;
			else
				cout << WORD << " NO" << endl;
		}
	}

	return 0;
}
