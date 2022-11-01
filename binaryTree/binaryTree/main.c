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
			if (!deleteNodeInTreeByKey(tree, key)) {
				clearBinaryTree(tree);
				return false;
			}
			printf("������� ��������� �������!\n");
		} else {
			printf("�� ����� �������������� �������. ���������� ��� ���!\n");
		}
		command = scanOne();
	}
	clearBinaryTree(tree);
}

int main() {
	setlocale(LC_ALL, "RUS");
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