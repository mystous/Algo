#include <stdio.h>

double lowestPrice(int, int);

int day[1000]={0,};
int team[1000] = {0,};

int main(void)
{
	FILE* inputStream;
	FILE* outputStream;

	fopen_s(&inputStream, "input.txt", "r");
	fopen_s(&outputStream, "output.txt", "w");

	int testCase=0;
	fscanf_s(inputStream,"%d",&testCase);
	
	//printf("testCase %d\n", testCase);
	for(int i=0 ; i< testCase ; i++)
	{
		int Day, Team;
		fscanf_s(inputStream,"%d %d",&Day, &Team);
		//printf("%d %d\n", Day, Team);	

		for(int j=0; j<Day ; j++)
		{
			fscanf_s(inputStream, "%d", &day[j]);
		//	printf("%d ", day[j]);
		}
		//printf("\n");
		
		double lowPrice =lowestPrice(Day, Team);
		printf("%.10lf\n", lowPrice);
		fprintf(outputStream,"%.12lf\n", lowPrice);
		//printf("\n");
	}
	
	fclose(inputStream);
	fclose(outputStream);

	return 0;
}

double lowestPrice(int Day, int Team)
{
	double lowPrice=100000;
	double tmpPrice=0;

	for( int i=Team ; i <= Day ; i++) //연속된 날짜 늘려감 Team=3->4->5->6
	{
		//printf("\nTeam 수 : %d \n", i);
		int testCnt=Day-i+1; //6-3+1=4번 / 6-4+1=3번
		for(int j=0 ; j< testCnt ; j++)	//연속된 날 쉬프트 (123)123  
		{
			//sum
			int shift = i+j; //team + 오른쪽으로 쉬프트
			for(int k=j ; k<shift ; k++) //
			{
				tmpPrice += day[k];				
			}
			tmpPrice = tmpPrice / i;
			
			if(tmpPrice < lowPrice)
				lowPrice = tmpPrice;
				
			tmpPrice=0; //초기화
		}
	}

	return lowPrice;
}