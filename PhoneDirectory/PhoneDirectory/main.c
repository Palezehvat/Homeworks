#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int scanOne();



void talkWithUser() {
	printf("%s", "������� �������.0 - �����, 1 - �������� ������(��� � �������), 2 - ����������� ��� ��������� ������, 3 - ����� ������� �� �����, 4 - ����� ��� �� ��������, 5 - ��������� ������� ������ � ���� \n");
	
	int comand = scanOne();
	
	while (comand < 0 || comand > 5) {
		printf("%s\n", "����� ������� �����������.��������� �������");
		comand = scanOne();
	}

	while (comand != 0) {
		
		printf("%s\n", "������� ����������� �������.(0 - ���� ������ �����)");
		comand = scanOne();
		while (comand < 0 || comand > 5) {
			printf("%s\n", "����� ������� �����������.��������� �������");
			comand = scanOne();
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	talkWithUser();
}

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