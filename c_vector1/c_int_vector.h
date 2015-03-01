#ifndef _C_INT_VECTOR_H
#define _C_INT_VECTOR_H
#if defined(_MSC_VER) && _MSC_VER > 1000
#pragma once
#endif /* _MSC_VER */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>//in gcc

#ifndef __cplusplus
#define nullptr NULL
#include <stdbool.h>
#endif /* __cplusplus */

#define c_int_vector__
typedef int* iterator_int;
typedef struct _c_int_vector c_int_vector;
struct _c_int_vector{
	int* array;
	size_t array_num;
	size_t array_capacity;
	size_t array_max_num;

	c_int_vector(*assign)(size_t Count, int Val);
	int(*at)(c_int_vector const* c_this, size_t place);
	int(*back)(c_int_vector const* c_this);
	iterator_int(*begin)(c_int_vector const* c_this);
	c_int_vector(*copy)(c_int_vector const* c_this);
	void(*clear)(c_int_vector* c_this);
	bool(*empty)(c_int_vector* c_this);
	iterator_int(*end)(c_int_vector const* c_this);
	void(*erase)(c_int_vector* c_this, int const* _Where);
	size_t(*size)(c_int_vector const* c_this);
	size_t(*max_size)(c_int_vector const* c_this);
	size_t(*capacity)(c_int_vector const* c_this);
	bool(*reserve)(c_int_vector* c_this, size_t _Count);
	bool(*resize)(c_int_vector* c_this, const size_t Newsize);
	bool(*pop_back)(c_int_vector* c_this);
	bool(*push_back)(c_int_vector* c_this, int const* val);
	void(*c_int_vector_sort)(c_int_vector* c_this);
	size_t(*c_int_vector_bsearch)(c_int_vector* c_this, const int key);
};
c_int_vector c_int_vector__ assign(size_t Count, int Val);
int c_int_vector__ at(c_int_vector const* c_this, size_t place);
int c_int_vector__ back(c_int_vector const* c_this);
iterator_int c_int_vector__ begin(c_int_vector const* c_this);
size_t c_int_vector__ capacity(c_int_vector const* c_this);
void c_int_vector__ clear(c_int_vector* c_this);
c_int_vector c_int_vector__ copy(c_int_vector const* c_this);
bool c_int_vector__ empty(c_int_vector const* c_this);
iterator_int c_int_vector__ end(c_int_vector const* c_this);
void c_int_vector__ erase(c_int_vector* c_this, int const* _Where);
size_t c_int_vector__ size(c_int_vector const* c_this);
size_t c_int_vector__ max_size(c_int_vector const* c_this);
bool c_int_vector__ reserve(c_int_vector* c_this, size_t _Count);
bool c_int_vector__ resize(c_int_vector* c_this, const size_t Newsize);
bool c_int_vector__ pop_back(c_int_vector* c_this);
bool c_int_vector__ push_back(c_int_vector* c_this, int const* val);
void c_int_vector__ c_int_vector_sort(c_int_vector* c_this);
size_t c_int_vector__ c_int_vector_bsearch(c_int_vector* c_this, const int key);

c_int_vector init_c_int_vector(void){
	c_int_vector res;
	res.array_capacity = 0;
	res.array_num = 0;
	res.array_max_num = (1 << 30) - 1;

	res.array = nullptr;

	res.copy = &copy;
	res.size = &size;
	res.resize = &resize;
	res.push_back = &push_back;
	res.at = &at;
	res.c_int_vector_sort = &c_int_vector_sort;
	res.c_int_vector_bsearch = &c_int_vector_bsearch;
	return res;
}
c_int_vector new_c_int_vector(void){
	c_int_vector res = init_c_int_vector();
	res.array_capacity = 15;
	res.array = (int*)calloc(res.array_capacity, sizeof(int));
	return res;
}
void delete_c_int_vector(c_int_vector* c_vector){
	if (0 != c_vector->array_num && nullptr != c_vector->array){
		free(c_vector->array);
		c_vector->array_num = 0;
	}
}

#endif /* _C_INT_VECTOR_H */