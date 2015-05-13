#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef struct TESTCASE{
	int n; //대여할 수 있는 날들의 수
	int l; //섭외한 공연팀
	int price[1000];
	double minPrice;
} TESTCASE;

double findMinPrice(TESTCASE testcase){
	int calcNum = testcase.l;
	int sum = 0;
	double avg = 0;
	int i = 0, j = 0;
	while (calcNum < testcase.n){
		for (i = 0; i <= testcase.n - calcNum; i++){
			sum = 0;
			for (j = 0; j < calcNum; j++){
				sum += testcase.price[i + j];
			}
			avg = sum / (double)calcNum;
			if (calcNum == testcase.l && i == 0){
				testcase.minPrice = avg;
			}
			else if (avg < testcase.minPrice){
				testcase.minPrice = avg;
			}
		}
		calcNum++;
	}
	return testcase.minPrice;
}

int main(){
	// file open
#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif //_WIN32

	int	testcaseNum = 0;
	scanf("%d", &testcaseNum);
	TESTCASE testcase[100];
	int i = 0, j = 0;
	for (i = 0; i < testcaseNum; i++){
		scanf("%d", &testcase[i].n);
		scanf("%d", &testcase[i].l);
		for (j = 0; j < testcase[i].n; j++){
			scanf("%d", &testcase[i].price[j]);
		}
	}

	for (i = 0; i < testcaseNum; i++){
		testcase[i].minPrice = findMinPrice(testcase[i]);
		printf("%.11f\n", testcase[i].minPrice);
	}
	
	return 0;
}

