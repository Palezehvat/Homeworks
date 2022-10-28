#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <locale.h>

int scanOne();

int whichPosition(int size, int step) {
	List* list = createList();
	addPositions(list, size);
	return counting(list, size, step);
}

int main() {
	setlocale(LC_ALL, "RUS");
	printf("������� ����������� �����\n");
	int size = scanOne();
	if (size == 0) {
		return 0;
	}
	printf("������� ��� ����������\n");
	int step = scanOne();
	printf("%s %d", "������� ���� �� ����, ���������� ������� � �������� ������, ����� ���������� ����������� ������� ������� ���������� �� ���������. ����������� �������: ", whichPosition(size, step));
}

int scanOne() {
	int number = 0;
	int checkScanf = scanf("%d", &number);

	while (checkScanf != 1) {
		while (getchar() != '\n') {
		}

		printf("������...\n");
		checkScanf = scanf("%d", &number);
	}

	return number;
}