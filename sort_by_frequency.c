#include "playlist.h"

void sort_by_frequency(nodepointer head, nodepointer tail, int left, int right){
	//main���� ó�� ȣ���� �� head�� �������� head->rlink, tail �� �������� tail, left�� 0, right�� �������� list_size - 1 ����
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
	tail->rlink = R_right; //main�Լ����� sort_by_frequency�� ȣ���� �Ŀ� tail�� ��� ��带 �ٽ� �����ϴ� ���� �ʿ��� ��(���߿������Ḯ��Ʈ)
	//tail->rlink�� ��� ��� �հ� �������� llink�� tail ����

	sort_by_frequency(head, Rnode->llink, left, R - 1);
	sort_by_frequency(Rnode->rlink, tail, R + 1, right);
}