#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <locale.h>

int scanOne();

int whichPosition(int size) {
	List* list = createList();
	addPositions(list, size);

}

int main() {
	setlocale(LC_ALL, "RUS");
	printf("������� ����������� �����\n");
	int size = scanOne();
	whichPosition(size);
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