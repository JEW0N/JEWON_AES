#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void bubbleSort(int* a) { //버블소트 함수
	for (int i = 0; i < 9999; i++)
		for (int j = 0; j < 9999; j++)
			if (a[j] > a[j + 1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
}
int intcmp(const void* a, const void* b) { //퀵소트용 비교함수
	return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}
void main() {
	int i, a[10000], b[10000];
	clock_t st1, et1, st2, et2;//st1,et1은 버블소트용, st2,et2는 퀵소트용

	//srand와 rand()를 이용해 1~10000까지 랜덤생성해 a[i], b[i] 에 동일하게 대입
	//중복제거 안함
	srand((unsigned int)time(NULL));
	for (i = 0; i < 10000; i++) {
		a[i] = (rand() % 10000) + 1;
		b[i] = a[i];
	}
	//버블소트 속도측정
	st1 = clock();
	bubbleSort(a);
	et1 = clock();

	//퀵소트 속도측정
	st2 = clock();
	qsort(b, 10000, 4, intcmp); //인자 : 배열명, 길이, 각 요소의 크기(int), 비교함수
	et2 = clock();

	//정렬이 됬는지 확인하기 원한다면 아래 주석을 해제하고 돌려보면 된다.
	//for (i = 0; i < 10000; i++) printf("%d ", a[i]);

	printf("버블소트 속도 : %d ms\n", et1 - st1);
	printf("퀵 소트 속도 : %d ms\n", et2 - st2);
}