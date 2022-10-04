#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include < string.h >
#include <stdbool.h>

int scanOneInt();

bool isStringEqual(char string1[], char string2[]) {
	const size_t lengthString1 = strlen(string1);
	const size_t lengthString2 = strlen(string2);
	size_t i = 0;
	while (i < lengthString1 && i < lengthString2) {
		if (string1[i] != string2[i]) {
			return false;
		}
		++i;
	}
	return lengthString1 - lengthString2 == 0;
}

void addRecord(char number[], char name[], char listOfString[100][100], int records) {
	const size_t lengthName = strlen(name);
	for (size_t i = 0; i < lengthName; ++i) {
		listOfString[records][i] = name[i];
	}
	++records;
	const size_t lengthNumber = strlen(number);
	for (size_t i = 0; i < lengthNumber; ++i) {
		listOfString[records][i] = number[i];
	}
}

void printRecords(void) {
	FILE *file = fopen("listOfNumbersAndNames.txt", "r");
	if (file == NULL) {
		printf("���� �� ������!");
		return;
	}
	char data[100] = { '\0' };
	while (fscanf(file, "%s", data) == 1)
	{
		printf("%s\n", data);
	}

	fclose(file);
}

void findNumberByName(char name[]) {
	FILE* file = fopen("listOfNumbersAndNames.txt", "r");
	if (file == NULL) {
		printf("���� �� ������!");
		return;
	}
	char data[100] = { '\0' };
	bool isNeedPrint = false;
	while (fscanf(file, "%s", data) == 1)
	{
		if (isNeedPrint) {
			printf("%s\n", data);
			break;
		}

		if (isStringEqual(data, name)) {
			isNeedPrint = true;
		}
	}

	fclose(file);
}

void findNameByNumber(char number[]) {
	FILE* file = fopen("listOfNumbersAndNames.txt", "r");
	if (file == NULL) {
		printf("���� �� ������!");
		return;
	}
	char data[100] = { '\0' };
	char last[100] = { '\0' };
	while (fscanf(file, "%s", data) == 1)
	{
		if (isStringEqual(data, number)) {
			printf("%s\n", last);
			break;
		}

		const size_t lengthLast = strlen(last);
		for (size_t i = 0; i < lengthLast; ++i) {
			last[i] = '\0';
		}

		const size_t lengthData = strlen(data);
		for (size_t i = 0; i < lengthData; ++i) {
			last[i] = data[i];
		}

	}

	fclose(file);
}

void saveInformation(char listOfStrings[100][100], int records) {
	FILE* file = fopen("listOfNumbersAndNames.txt", "a");
	if (file == NULL) {
		printf("���� �� ������!");
		return;
	}
	int i = 0;
	while (i < records) {
		fprintf(file, "%s\n", listOfStrings[i]);
		++i;
		fprintf(file, "%s\n", listOfStrings[i]);
		++i;
	}

	fclose(file);
}

void talkWithUser() {
	printf("%s", "������� �������.0 - �����, 1 - �������� ������(��� � �������), 2 - ����������� ��� ��������� ������, 3 - ����� ������� �� �����, 4 - ����� ��� �� ��������, 5 - ��������� ������� ������ � ���� \n");
	
	int comand = scanOneInt();
	
	while (comand < 0 || comand > 5) {
		printf("%s\n", "����� ������� �����������.��������� �������");
		comand = scanOneInt();
	}

	char listOfString[100][100] = { '\0' };
	int records = 0;

	while (comand != 0) {
		if (comand == 1 && records < 100) {
			printf("%s\n", "������� ���, � ����� �����. ������ ����� � ������ ������ ���� ������ 100 ��������");
			char name[100] = { '\0' };
			int checkScanf = scanf("%s", &name);
			while (checkScanf != 1 || (int)strlen(name) >= 100) {
				while (getchar() != '\n') {
				}

				printf("%s", "������... ��������� ������������ ����� \n");
				checkScanf = scanf("%s", &name);
			}
			char number[100] = { '\0' };
			checkScanf = scanf("%s", &number);
			while (checkScanf != 1 || (int)strlen(number) >= 100) {
				while (getchar() != '\n') {
				}

				printf("%s", "������... ��������� ������������ ����� \n");
				checkScanf = scanf("%s", &number);
			}
			addRecord(number, name, listOfString, records);
			records += 2;
		} else if (comand == 1) {
			printf("%s", "�� ����� ������� ����� �������\n");
		}
		if (comand == 2) {
			printRecords();
		}
		if (comand == 3) {
			printf("%s\n", "������� ���. ������ ����� ������ ���� ������ 100 ��������");
			char name[100] = {'\0'};
			int checkScanf = scanf("%s", &name);
			while (checkScanf != 1 || (int)strlen(name) >= 100) {
				while (getchar() != '\n') {
				}

				printf("%s", "������... ��������� ������������ ����� \n");
				checkScanf = scanf("%s", &name);
			}

			findNumberByName(name);
		}
		if (comand == 4) {
			printf("%s\n", "������� �����.");
			char number[100] = { '\0' };
			int checkScanf = scanf("%s", &number);
			while (checkScanf != 1 || (int)strlen(number) >= 100) {
				while (getchar() != '\n') {
				}

				printf("%s", "������... ��������� ������������ ����� \n");
				checkScanf = scanf("%s", &number);
			}
			findNameByNumber(number);
		}
		if (comand == 5) {
			saveInformation(listOfString, records);
		}
		printf("%s\n", "������� ����������� �������.(0 - ���� ������ �����)");
		comand = scanOneInt();
		while (comand < 0 || comand > 5) {
			printf("%s\n", "����� ������� �����������.��������� �������");
			comand = scanOneInt();
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	talkWithUser();
}

int scanOneInt() {
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