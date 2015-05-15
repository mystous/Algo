#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef struct TESTCASE{
	int n; //대여할 수 있는 날들의 수
	int l; //섭외한 공연팀
	int price[1000];
	double minPrice;
} TESTCASE;

double findMinPrice(TESTCASE testcase){
	int calcNum = testcase.l;	//가수
	int sum = 0;
	double avg = 0;
	int i = 0, j = 0;
	while (calcNum <= testcase.n){	//가수 수 
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
		calcNum++; //가수 3->4->5->6
	}
	return testcase.minPrice;
}

int main(){
	// file open
#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif //_WIN32

	int	testcaseNum = 0;
	scanf("%d", &testcaseNum);	//몇개의 testcase?
	TESTCASE testcase[100];	//testcase 저장할 배열 선언
	int i = 0, j = 0;
	//read
	for (i = 0; i < testcaseNum; i++){	//testcase개수 만큼 for문	2
		scanf("%d", &testcase[i].n);	//day개수	6
		scanf("%d", &testcase[i].l);	//l 가수 개수	3

		for (j = 0; j < testcase[i].n; j++){	//	6번(day개수) for문
			scanf("%d", &testcase[i].price[j]);	//	price 저장	i : testcase번호,	j=날짜
		}
	}

	for (i = 0; i < testcaseNum; i++){	//testcase개수 만큼 for문
		testcase[i].minPrice = findMinPrice(testcase[i]);	//testcase번호 마다 minprice 함수 실행
		printf("%.11f\n", testcase[i].minPrice);	//출력
	}
	
	return 0;
}

