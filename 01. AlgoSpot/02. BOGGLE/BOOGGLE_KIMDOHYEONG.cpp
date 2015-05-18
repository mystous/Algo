#include <stdio.h>
#include <string.h>


struct letterLocation
{
	char c;
	int row;
	int col;
};

char board[5][5];
struct letterLocation locate[256];
char letter[256]={0};

bool checkLetter(char *string);

int main(void)
{
	int game=0;
#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif //_WIN32


	scanf("%d\n", &game);
	for(int i=0; i<game ; i++)
	{
		//보드판 채우기 
		for(int j = 0 ; j<5 ; j++)
		{
			for(int k=0 ; k<5 ; k++){
				scanf("%c", &board[j][k]);
				printf("%c", board[j][k]);

				char c=board[j][k];
				locate[c].c=c;
				locate[c].row=j;
				locate[c].col=k;
			}
			scanf("\n");
			printf("\n", board[i][i]);
		}
		//문자 개수확인하기
		int letters=0;
		scanf("%d\n", &letters);
		printf("%d\n", letters);
		
		//문자 개수 만큼
		for(int j=0 ; j<letters ; j++)
		{
			char string[10];
			scanf("%s\n", string);
			printf("%d\n",j);
			printf("%s ", string);
			
			if(checkLetter(string))
			{
				printf("YES");
			}
			else
			{
				printf(" NO");
			}
			printf("\n");
			
		}

	}
	
}

bool checkLetter(char *string)
{
	char c = string[0];
	if(locate[c].c==c)
	{
		int row = locate[c].row;
		int col = locate[c].col;
		int length = strlen(string);
		string++;
		
		for(int i=1 ; i<length ; i++)
		{
			printf("%c",*string);
			if( row-1 > 0 && col-1 >0 && (*string==board[row-1][col-1])){
				row=row-1;
				col=col-1;
				string++;
				continue;
			}
			if( row-1 > 0  && (*string==board[row-1][col])){
				row=row-1;
				string++;
				continue;
			}
			if( row-1 > 0 && col+1 <5 && (*string==board[row-1][col+1])){
				row=row-1;
				col=col+1;
				string++;
				continue;
			}
			if( col+1 <5 && (*string==board[row][col+1])){
				printf("test");
				col=col+1;
				string++;
				continue;
			}
			if( row+1 < 5 && col+1 < 5 && (*string==board[row+1][col+1])){
				row=row+1;
				col=col+1;
				string++;
				continue;
			}
			if( row+1 < 5 && (*string==board[row+1][col])){
				row=row+1;
				string++;
				continue;
			}
			if( row+1 < 5 && col-1 > 0 && (*string==board[row+1][col-1])){
				row=row+1;
				col=col-1;
				string++;
				continue;
			}
			if(  col-1 >0 && (*string==board[row][col-1])){
				col=col-1;
				string++;
				continue;
			}		
			return false;
		}
		return true;
	}
	else
	{
		return false;
	}
	
}