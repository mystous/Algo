#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char board[5][5];

bool checkLetter(char *string, int length);

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
				//printf("%c", board[j][k]);
				char c=board[j][k];
			}
			scanf("\n");
			//printf("\n", board[i][i]);
		}
		//문자 개수확인하기
		int letters=0;
		scanf("%d\n", &letters);
		//printf("%d\n", letters);
		
		//문자 개수 만큼
		for(int j=0 ; j<letters ; j++)
		{
			char string[10];
			scanf("%s\n", string);
			
			printf("%s", string);
			int length=strlen(string);
			//printf("%d\n",length);

			
			if(checkLetter(string, length))
			{
				printf(" YES\n");
			}
			else
			{
				printf(" NO\n");
			}

			
		}

	}
	
}

bool checkLetter(char *string, int length)
{
	char c;
	for(int row=0 ; row<5 ; row++)
	{
		for(int col=0 ; col<5 ; col++)
		{
			
			c=board[row][col];
			int tmpRow = row;
			int tmpCol = col;
			if( c == string[0] ){
				//printf("check %c %d %d \n",c, row, col);
			}
			
			if( c == string[0] ){//첫글자 찾기
				bool isTrue=false;
				for(int i=1 ; i<length ; i++)
				{
					//printf("%c",string[i]);
					if(string[i]==NULL){
					//	printf("null을 만났습니다\n");
						return true;
					}
					if( tmpRow-1 >= 0 && tmpCol-1 >= 0 && (string[i]==board[tmpRow-1][tmpCol-1])){
						tmpRow=tmpRow-1;
						tmpCol=tmpCol-1;
						isTrue=true;
						continue;
					}
					if( tmpRow-1 >= 0   && (string[i]==board[tmpRow-1][tmpCol])){
						tmpRow=tmpRow-1;
						isTrue=true;
						continue;
					}
					if( tmpRow-1 >= 0 && tmpCol+1 <5 && (string[i]==board[tmpRow-1][tmpCol+1])){
						tmpRow=tmpRow-1;
						tmpCol=tmpCol+1;
						isTrue=true;
						continue;
					}
					if( tmpCol+1 < 5 && (string[i]==board[tmpRow][tmpCol+1])){
						tmpCol=tmpCol+1;
						isTrue=true;
						continue;
					}
					if( tmpRow+1 < 5 && tmpCol+1 < 5 && (string[i]==board[tmpRow+1][tmpCol+1])){
						tmpRow=tmpRow+1;
						tmpCol=tmpCol+1;
						isTrue=true;
						continue;
					}
					if( tmpRow+1 < 5 && (string[i]==board[tmpRow+1][tmpCol])){
						tmpRow=tmpRow+1;
						isTrue=true;
						continue;
					}
					if( tmpRow+1 < 5 && tmpCol-1 >= 0 && (string[i]==board[tmpRow+1][tmpCol-1])){
						tmpRow=tmpRow+1;
						tmpCol=tmpCol-1;
						isTrue=true;
						continue;
					}
					if(  tmpCol-1 >= 0 && (string[i]==board[tmpRow][tmpCol-1])){
						tmpCol=tmpCol-1;
						isTrue=true;
						continue;
					}		
					if( i==(length-1) )
					{
						isTrue=true;
					}else{
						isTrue=false;
					}
					break;
					
				}
				if(isTrue){
					return true;
				}
			}
		}
	}
	return false;
}