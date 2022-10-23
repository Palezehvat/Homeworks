#pragma once
#include <stdbool.h>

typedef struct Stack Stack;

// ���������� ��������� � ����
int push(Stack* stack, char value);

// �������� �������� �����
char pop(Stack* stack, int* errorCode);

// �������� �� ������� �����
bool isEmpty(Stack stack);

// �������� �����
void deleteStack(Stack* stack);

// �������� �����
Stack* createStack(void);

// ���������� ������� ������� �����
int top(Stack* stack);