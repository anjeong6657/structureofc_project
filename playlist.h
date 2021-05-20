#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
	char* song;
	char* singer;
	int frequency;
	nodepointer llink, rlink;
}node; //���߿������Ḯ��Ʈ ���
typedef node* nodepointer; //����� ������

nodepointer head, tail; //����Ʈ�� ��� ���� ���� ������ ���
int list_size; //�÷��� ����Ʈ�� ����� �뷡�� ��

void sort_by_frequency(nodepointer head, nodepointer tail, int left, int right);
void int_swap(int* a, int* b);
void string_swap(char* a, char*b, int a_size, int b_size);