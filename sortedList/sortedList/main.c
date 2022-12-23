#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <locale.h>
#include <stdbool.h>

int scanOne() {
	int number = 0;
	int checkScanf = scanf("%d", &number);

	while (checkScanf != 1) {
		while (getchar() != '\n') {
		}

		printf("%s", "������... ��������� ������������ ����� \n");
		checkScanf = scanf("%d", &number);
	}

	return number;
}

bool talkWithUser(void) {
	List* list = createList();
	printf(" 0 � �����\n 1 � �������� �������� � ������������� ������\n 2 � ������� �������� �� ������\n 3 � ����������� ������\n");
	int userComand = scanOne();
	while (userComand != 0) {
		if (userComand == 1) {
			printf("������� ��������\n");
			int value = scanOne();
			if (insert(list, value) == -1) {
				return false;
			}
		}
		else if (userComand == 2) {
			printf("������� ��������\n");
			int number = scanOne();
			if (delete(list, number) == -1) {
				printf("���������, �� �� �������� �� �����!\n");
			}
		} else if (userComand == 3) {
			print(list);
		}
		printf("������� ��������� �������\n");
		userComand = scanOne();
	}
	
	clearList(&list);
	return true;
}

bool tests() {
	List* list = createList();
	insert(list, 100);
	if (top(list) != 100) {
		clearList(&list);
		return false;
	}
	delete(list, 100);
	if (top(list) != -1) {
		clearList(&list);
		return false;
	}
	clearList(&list);
	return true;
}

int main() {
	setlocale(LC_ALL, "RUS");
	if (tests()) {
		printf("����� ������ �������\n");
	} else {
		printf("���-�� ������...\n");
		return 0;
	}
	bool check = talkWithUser();
	if (!check) {
		printf("��������� ������...\n");
	}
}