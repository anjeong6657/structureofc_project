#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
	char* song;
	char* singer;
	int frequency;
	nodepointer llink, rlink;
}node; //이중원형연결리스트 노드
typedef node* nodepointer; //노드의 포인터

nodepointer head, tail; //리스트의 헤드 노드와 가장 마지막 노드
int list_size; //플레이 리스트에 저장된 노래의 수

void sort_by_frequency(nodepointer head, nodepointer tail, int left, int right);
void int_swap(int* a, int* b);
void string_swap(char* a, char*b, int a_size, int b_size);