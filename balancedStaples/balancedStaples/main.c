#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include "stack.h"
#include <string.h>

bool isBalanced(char stringStaples[], int* errorCode) {
	ElementStack* buffer = NULL;
	size_t sizeStringStaples = strlen(stringStaples);
	size_t i = 0;
	while(i < sizeStringStaples) {
		if (stringStaples[i] == '{' || stringStaples[i] == '(' || stringStaples[i] == '[') {
			pushElements(&buffer, stringStaples[i]);
		} else if (stringStaples[i] == ']' || stringStaples[i] == ')' || stringStaples[i] == '}') {
			char lastOpenStaple = popElements(&buffer, errorCode);
			if (*errorCode == 1 || !((lastOpenStaple == '[' && stringStaples[i] == ']') || (lastOpenStaple == '(' && stringStaples[i] == ')') || (lastOpenStaple == '{' && stringStaples[i] == '}') )) {
				return false;
			}
		} else {
			*errorCode = 1;
			return false;
		}
		++i;
	}
	if (buffer != NULL) {
		return false;
	}
	return true;
}

bool firstTest(void) {
	char stringStaples[5] = { '{', '(', '}', ')', '\0'};
	int errorCode = 0;
	return isBalanced(stringStaples, &errorCode) == false && errorCode == 0;
}

bool secondTest(void) {
	char stringStaples[5] = { '{', '(', ')', '}', '\0'};
	int errorCode = 0;
	return isBalanced(stringStaples, &errorCode) == true && errorCode == 0;
}

int main() {
	setlocale(LC_ALL, "RUS");
	if (!firstTest() || !secondTest()) {
		printf("������...\n");
		return 0;
	} else {
		printf("����� �������� �������!\n");
	}
	printf("������� ������������������ ������(������ 100 ��������)\n");
	char stringStaples[100];
	gets_s(stringStaples, 100);
	int errorCode = 0;
	printf(isBalanced(stringStaples, &errorCode) && errorCode == 0 ? "���� ����������� ������ ��������������\n" : errorCode != 0 ? "������..." : "���� ����������� ������ �� ��������������\n");
}