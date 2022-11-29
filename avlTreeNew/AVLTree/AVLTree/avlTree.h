#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <stdbool.h>

typedef struct Tree Tree;

//�������� ������
Tree* createTree(void);

//�������� ������
void clearTree(Tree* tree);

//���������� ���� � ������
void addToTree(Tree* tree, int key, char* string);

//���������� �������� �� �����
char* returnValueByKey(Tree* tree, int key);

//�������� ������� �����
bool isKeyInTree(Tree* tree, int key);

//�������� �������� �� �����
void deleteNodeInTreeByKey(Tree* tree, int key, const bool ifUseFile);
#endif