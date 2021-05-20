#include "playlist.h"

void sort_by_frequency(nodepointer head, nodepointer tail, int left, int right){
	//main에서 처음 호출할 때 head로 전역변수 head->rlink, tail 은 전역변수 tail, left는 0, right는 전역변수 list_size - 1 전달
	if (left >= right) return;
	int L = left; int R = right + 1;
	nodepointer Lnode = head;
	nodepointer Rnode = tail;
	nodepointer R_right = tail->rlink;
	nodepointer temp = (nodepointer)malloc(sizeof(node));

	Rnode->rlink = temp;
	temp->llink = Rnode;
	Rnode = Rnode->rlink;
	while (L < R) {
		do {
			L++;
			Lnode = Lnode->rlink;
		} while (L <= right && Lnode->frequency < head->frequency);

		do {
			R--;
			Rnode = Rnode->llink;
		} while (R > left && Rnode->frequency > head->frequency);

		if (L < R) {
			int_swap(&Lnode->frequency, &Rnode->frequency);
			string_swap(Lnode->song, Rnode->song, strlen(Lnode->song), strlen(Rnode->song));
			string_swap(Lnode->singer, Rnode->singer, strlen(Lnode->singer), strlen(Rnode->singer));
		}
	}
	int_swap(&head->frequency, &Rnode->frequency);
	string_swap(head->song, Rnode->song, strlen(head->song), strlen(Rnode->song));
	string_swap(head->singer, Rnode->singer, strlen(head->singer), strlen(Rnode->singer));

	free(temp);
	tail->rlink = R_right; //main함수에서 sort_by_frequency를 호출한 후에 tail과 헤더 노드를 다시 연결하는 과정 필요할 듯(이중원형연결리스트)
	//tail->rlink에 헤더 노드 잇고 헤더노드의 llink에 tail 연결

	sort_by_frequency(head, Rnode->llink, left, R - 1);
	sort_by_frequency(Rnode->rlink, tail, R + 1, right);
}