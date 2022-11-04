#ifndef TREE_H
#define TREE_H

typedef struct Tree Tree;

//�������� ������
Tree* createTree(void);

//���������� � ������ ��������, ���������� �� ������� int'� � ��������� char'�
void addToTreeSymbol(Tree* tree, char symbol, int* errorCode);

//���������� � ������ ��������, ���������� �� ��������� int'� � ������� char'�
void addToTreeNumber(Tree* tree, int number, int* errorCode);

#endif