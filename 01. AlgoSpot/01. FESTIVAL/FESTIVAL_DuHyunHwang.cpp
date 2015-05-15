#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef struct TESTCASE{
	int n; //�뿩�� �� �ִ� ������ ��
	int l; //������ ������
	int price[1000];
	double minPrice;
} TESTCASE;

double findMinPrice(TESTCASE testcase){
	int calcNum = testcase.l;	//����
	int sum = 0;
	double avg = 0;
	int i = 0, j = 0;
	while (calcNum <= testcase.n){	//���� �� 
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
		calcNum++; //���� 3->4->5->6
	}
	return testcase.minPrice;
}

int main(){
	// file open
#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif //_WIN32

	int	testcaseNum = 0;
	scanf("%d", &testcaseNum);	//��� testcase?
	TESTCASE testcase[100];	//testcase ������ �迭 ����
	int i = 0, j = 0;
	//read
	for (i = 0; i < testcaseNum; i++){	//testcase���� ��ŭ for��	2
		scanf("%d", &testcase[i].n);	//day����	6
		scanf("%d", &testcase[i].l);	//l ���� ����	3

		for (j = 0; j < testcase[i].n; j++){	//	6��(day����) for��
			scanf("%d", &testcase[i].price[j]);	//	price ����	i : testcase��ȣ,	j=��¥
		}
	}

	for (i = 0; i < testcaseNum; i++){	//testcase���� ��ŭ for��
		testcase[i].minPrice = findMinPrice(testcase[i]);	//testcase��ȣ ���� minprice �Լ� ����
		printf("%.11f\n", testcase[i].minPrice);	//���
	}
	
	return 0;
}

