#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

bool readFromFileToTree(char fileName[], Tree* tree) {
	FILE* file = fopen(fileName, "r");
	if (file == NULL) {
		printf("���� �� ������!");
		return false;
	}
}

bool connectingFunction(char fileName[]) {
	Tree* tree = createTree();
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
	printf("������� ��� ����� � ��� �����������, ������ �� ������ ��������� 100 ��������\n");
	char fileName[100] = { '\0' };
	int checkScan = scanf("%s", &fileName);
	while (checkScan != 1) {
		while (getchar() != '\n') {
		}

		printf("������...");
		checkScan = scanf("%s", &fileName);
	}

}