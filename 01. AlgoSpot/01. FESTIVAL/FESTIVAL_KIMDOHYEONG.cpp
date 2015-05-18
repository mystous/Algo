#include <stdio.h>

double lowestPrice(int, int);

int day[1000]={0,};
int team[1000] = {0,};



int main(void)
{
#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif //_WIN32


	int testCase=0;
	scanf("%d",&testCase);
	
	//printf("testCase %d\n", testCase);
	for(int i=0 ; i< testCase ; i++)
	{
		int Day, Team;
		scanf("%d %d",&Day, &Team);
		//printf("%d %d\n", Day, Team);	

		for(int j=0; j<Day ; j++)
		{
			scanf("%d", &day[j]);
		//	printf("%d ", day[j]);
		}
		//printf("\n");
		
		double lowPrice =lowestPrice(Day, Team);
		printf("%.12lf\n", lowPrice);
	}

	return 0;
}

double lowestPrice(int Day, int Team)
{
	double lowPrice=100000;
	double tmpPrice=0;

	for( int i=Team ; i <= Day ; i++) //���ӵ� ��¥ �÷��� Team=3->4->5->6
	{
		//printf("\nTeam �� : %d \n", i);
		int testCnt=Day-i+1; //6-3+1=4�� / 6-4+1=3��
		for(int j=0 ; j< testCnt ; j++)	//���ӵ� �� ����Ʈ (123)123  
		{
			//sum
			int shift = i+j; //team + ���������� ����Ʈ
			for(int k=j ; k<shift ; k++) //
			{
				tmpPrice += day[k];				
			}
			tmpPrice = tmpPrice / i;
			
			if(tmpPrice < lowPrice)
				lowPrice = tmpPrice;
				
			tmpPrice=0; //�ʱ�ȭ
		}
	}

	return lowPrice;
}