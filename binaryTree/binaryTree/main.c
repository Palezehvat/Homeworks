#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int scanOne();

bool talkWithUser(void) {
	printf("������� ���� �� ��������� ������\n0 - ����� �� �������������� ����.\n1 - �������� �������� �� ��������� ����� � �������. ���� ����� ���� ��� ����, �������� ���������� �� �����.\n2 - �������� �������� �� ��������� ����� �� �������. ���� ������ ����� ���, ������������ NULL.\n3 - ��������� ������� ��������� ����� � �������.\n4 - ������� �������� ���� � ��������� � ��� �������� �� �������. ���� ������ ����� ���, ������� ������ �� ������.\n");
	int command = scanOne();
	while (command > 4 || command < 0) {
		printf("�� ����� �������������� �������. ���������� ��� ���!\n");
		command = scanOne();
	}
	Node* tree = NULL;
	char* stringCopy = NULL;

	while (command != 0) {

		printf("������� ����\n");
		int key = scanOne();
		
		switch (command) {
			case 1:
				printf("������� ������ ������. �� �� ������ ��������� 100 ��������\n");
				int size = scanOne();
				while (size < 0 || size > 100) {
					while (getchar() != '\n') {
					}
					printf("������...\n");
					size = scanOne();
				}
				char buffer[101] = { '\0' };
				int checkScanf = scanf("%s", buffer);

				while (checkScanf != 1) {
					while (getchar() != '\n') {
					}
					printf("������...\n");
					checkScanf = scanf("%s", buffer);
				}
				size_t sizeBuffer = strlen(buffer);
				char* string = calloc(sizeBuffer + 1, sizeof(char));
				if (string == NULL) {
					return false;
				}
				for (size_t i = 0; i < sizeBuffer; ++i) {
					string[i] = buffer[i];
				}
				Node* check = addToBinaryTree(tree, key, string);
				if (check == NULL) {
					clearBinaryTree(tree);
					return false;
				}
				tree = check;
				printf("������� ��������� �������!\n");
				break;
			case 2://
				stringCopy = NULL;
				stringCopy = returnValueByKey(tree, key);
				if (string != NULL) {
					printf("%s\n", string);
				}
				printf("������� ��������� �������!\n");
				break;
			case 3:
				if (isKeyInTree(tree, key)) {
					printf("��, ����� ���� �������!\n");
				} else {
					printf("���, ������ ����� ���!\n");
				}
				printf("������� ��������� �������!\n");
				break;
			case 4:
				tree = deleteNodeInTreeByKey(tree, key);
				printf("������� ��������� �������!\n");
				break;
		}

		command = scanOne();

		while (command > 4 || command < 0) {
			printf("�� ����� �������������� �������. ���������� ��� ���!\n");
			command = scanOne();
		}
	}

	clearBinaryTree(tree);
	return true;
}

bool test(void) {
	Node* tree = NULL;
	char* buffer = calloc(4, sizeof(char));
	if (buffer == NULL) {
		return false;
	}
	buffer = "end";
	tree = addToBinaryTree(tree, 100, buffer);
	if (strcmp(returnValueByKey(tree, 100), buffer) != 0) {
		return false;
	}
	if (!isKeyInTree(tree, 100)) {
		return false;
	}
	
	tree = deleteNodeInTreeByKey(tree, 100);

	if (isKeyInTree(tree, 100)) {
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