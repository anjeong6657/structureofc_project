#include "playlist.h"

void string_swap(char* a, char* b, int a_size, int b_size) {
	char* temp_a;
	temp_a = (char*)malloc(sizeof(char) * a_size);
	strcpy(temp_a, a);

	free(a);
	a = (char*)malloc(sizeof(char) * b_size);
	strcpy(a, b);

	free(b);
	b = (char*)malloc(sizeof(char) * a_size);
	strcpy(b, temp_a);

	free(temp_a);
}