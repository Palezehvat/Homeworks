#include "avlTree.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

int scanOne();

bool talkWithUser(void) {
	printf("� ��� ���� ��������� �������:\n0 - ����� �� �������������� ����\n1 - �������� �������� �� ��������� ����� � �������. ���� ����� ���� ��� ����, �������� ���������� �� �����.\n2 - �������� �������� �� ��������� ����� �� �������.���� ������ ����� ���, ������������ NULL.\n3 - ��������� ������� ��������� �����.\n4- ������� �������� ���� � ��������� � ��� �������� �� �������.���� ������ ����� ���, ������� ������ �� ������.");
	int command = scanOne();

	while (command > 4 || command < 0) {
		printf("�� ����� �������������� �������. ���������� ��� ���!\n");
		command = scanOne();
	}

	while (command != 0) {

		switch (command) {
			case 1:


				break;
			case 2:



				break;



			case 3:



				break;
			case 4:


				break;
		}


		command = scanOne();

		while (command > 4 || command < 0) {
			printf("�� ����� �������������� �������. ���������� ��� ���!\n");
			command = scanOne();
		}
	}
}

bool test() {
	return true;
}

int main() {
	setlocale(LC_ALL, "RUS");
	if (test()) {
		printf("����� ������ �������!\n");
	} else {
		printf("������...\n");
		return -1;
	}
	if (!talkWithUser()) {
		printf("������...\n");
		return -1;
	}
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