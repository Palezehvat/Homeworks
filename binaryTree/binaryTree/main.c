#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "binaryTree.h"
#include <string.h>

int scanOne();

bool talkWithUser(void) {
	printf("������� ���� �� ��������� ������\n0 - ����� �� �������������� ����.\n1 - �������� �������� �� ��������� ����� � �������. ���� ����� ���� ��� ����, �������� ���������� �� �����.\n2 - �������� �������� �� ��������� ����� �� �������. ���� ������ ����� ���, ������������ NULL.\n3 - ��������� ������� ��������� ����� � �������.\n4 - ������� �������� ���� � ��������� � ��� �������� �� �������. ���� ������ ����� ���, ������� ������ �� ������.\n");
	int command = scanOne();
	Node* tree = NULL;
	while (command != 0) {
		if (command == 1) {
			printf("������� ����\n");
			int key = scanOne();
			printf("������� ������ ������. �� �� ������ ��������� 199 ��������\n");
			int size = scanOne() + 1;
			char* string = calloc(size, sizeof(char));
			char buffer[200] = { '\0' };
			if (string == NULL) {
				return false;
			}
			while (strlen(buffer) != size - 1) {
				strcpy(buffer, "");
				printf("������� ������!\n");
				int checkScanf = scanf("%s", buffer);
				while (checkScanf != 1) {
					while (getchar() != '\n') {
					}

					printf("������...\n");
					checkScanf = scanf("%s", buffer);
				}
			}
			strcpy(string, buffer);
			Node* check = addToBinaryTree(tree, key, string);
			if (check == NULL) {
				clearBinaryTree(tree);
				return false;
			}
			tree = check;
			printf("������� ��������� �������!\n");
		} else if (command == 2) {
			printf("������� ����\n");
			int key = scanOne();
			char* string = returnValueByKey(tree, key);
			if (string != NULL) {
				printf("%s\n", string);
			}
			printf("������� ��������� �������!\n");
		} else if (command == 3) {
			printf("������� ����\n");
			int key = scanOne();
			if (isThereAKeyInTheTree(tree, key)) {
				printf("��, ����� ���� �������!\n");
			} else {
				printf("���, ������ ����� ���!\n");
			}
			printf("������� ��������� �������!\n");
		} else if (command == 4) {
			printf("������� ����\n");
			int key = scanOne();
			tree = deleteNodeInTreeByKey(tree, key);
			printf("������� ��������� �������!\n");
		} else {
			printf("�� ����� �������������� �������. ���������� ��� ���!\n");
		}
		command = scanOne();
	}
	clearBinaryTree(tree);
}

bool test(void) {
	Node* tree = NULL;
	char* buffer = calloc(4, sizeof(char));
	if (buffer == NULL) {
		return false;
	}
	for (int i = 0; i < 3; ++i) {
		if (i == 0) {
			buffer[i] = 'e';
		} else if (i == 1) {
			buffer[i] = 'n';
		} else if (i == 2) {
			buffer[i] = 'd';
		}
	}
	tree = addToBinaryTree(tree, 100, buffer);
	if (strcmp(returnValueByKey(tree, 100), buffer) != 0) {
		return false;
	}
	if (!isThereAKeyInTheTree(tree, 100)) {
		return false;
	}
	
	tree = deleteNodeInTreeByKey(tree, 100);

	if (isThereAKeyInTheTree(tree, 100)) {
		return false;
	}
	return true;
}

int main() {
	setlocale(LC_ALL, "RUS");
	if (test()) {
		printf("����� ������ �������\n");
	} else {
		printf("������...");
	}

	if (!talkWithUser()) {
		printf("������!\n");
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