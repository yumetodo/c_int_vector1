#include "c_int_vector.h"
#include<errno.h>//in gcc

void _rank(c_int_vector* rank, c_int_vector* in_num){
	c_int_vector sorted = in_num->copy(in_num);
	sorted.c_int_vector_sort(&sorted);
	size_t i, rank_current;
	for (i = 0; i < sorted.size(&sorted); i++){
		rank_current = sorted.c_int_vector_bsearch(&sorted, in_num->array[i]);
		int rank_true;
		/* �������l�ɑ΂��Ă͓������ʂƂ��� */
		for (rank_true = rank_current; sorted.array[rank_true] == sorted.array[rank_true + 1]; rank_true++);
		rank->push_back(rank, &rank_true);
	}
}
void print_array(c_int_vector* in_num, c_int_vector* rank){
	size_t i;
	puts("No.���͏�:���l<����>");
	for (i = 0; i < in_num->size(in_num); i++)
		printf("No. %d: %d<%d>\n", i + 1, in_num->array[i], rank->array[i]);
}
int get_integer_num(const int max, const int min){
	/*�@�\�F�W�����͂𐔎��ɕϊ�����B
	//�����F�߂�l�̍ő�l,�߂�l�̍ŏ��l
	//�߂�l�F���͂��������A�G���[����INT_MAX, EOF�Ȃ�EOF*/
	char s[100];
	long t;
	char *endptr;

	if (NULL == fgets(s, 100, stdin)){
		if (feof(stdin))
			return EOF;
		else
			return INT_MAX;
	}
	errno = 0;
	t = strtol(s, &endptr, 10);
	if (errno != 0 || *endptr != '\n' || t < min || max < t)
		return INT_MAX;
	return (int)t;
}
int main(void){
	c_int_vector in_num = new_c_int_vector();
	int temp;
	while (EOF != (temp = get_integer_num(INT_MAX, INT_MIN))){
		if (INT_MAX == temp) continue;/*�G���[�΍�*/
		in_num.push_back(&in_num, &temp);
	}
	c_int_vector rank = new_c_int_vector();
	_rank(&rank, &in_num);
	print_array(&rank, &in_num);
	delete_c_int_vector(&in_num);
	delete_c_int_vector(&rank);
	return 0;
}