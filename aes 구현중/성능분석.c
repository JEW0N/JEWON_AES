#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void bubbleSort(int* a) { //�����Ʈ �Լ�
	for (int i = 0; i < 9999; i++)
		for (int j = 0; j < 9999; j++)
			if (a[j] > a[j + 1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
}
int intcmp(const void* a, const void* b) { //����Ʈ�� ���Լ�
	return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}
void main() {
	int i, a[10000], b[10000];
	clock_t st1, et1, st2, et2;//st1,et1�� �����Ʈ��, st2,et2�� ����Ʈ��

	//srand�� rand()�� �̿��� 1~10000���� ���������� a[i], b[i] �� �����ϰ� ����
	//�ߺ����� ����
	srand((unsigned int)time(NULL));
	for (i = 0; i < 10000; i++) {
		a[i] = (rand() % 10000) + 1;
		b[i] = a[i];
	}
	//�����Ʈ �ӵ�����
	st1 = clock();
	bubbleSort(a);
	et1 = clock();

	//����Ʈ �ӵ�����
	st2 = clock();
	qsort(b, 10000, 4, intcmp); //���� : �迭��, ����, �� ����� ũ��(int), ���Լ�
	et2 = clock();

	//������ ����� Ȯ���ϱ� ���Ѵٸ� �Ʒ� �ּ��� �����ϰ� �������� �ȴ�.
	//for (i = 0; i < 10000; i++) printf("%d ", a[i]);

	printf("�����Ʈ �ӵ� : %d ms\n", et1 - st1);
	printf("�� ��Ʈ �ӵ� : %d ms\n", et2 - st2);
}