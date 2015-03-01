#include "c_int_vector.h"

c_int_vector c_int_vector__ assign(size_t Count, int Val){
	c_int_vector res = init_c_int_vector();
	res.reserve(&res, Count * 2);
	for (int i = 0; i < Count; i++){
		res.push_back(&res, Val);
	}
	return res;
}
int c_int_vector__ at(c_int_vector const* c_this, size_t place){
	if (c_this->size(c_this) - 1 < place) return INT_MAX;
	return c_this->array[place];
}
int c_int_vector__ back(c_int_vector const* c_this){
	return c_this->array[c_this->size(c_this) - 1];
}
int* c_int_vector__ begin(c_int_vector const* c_this){
	return &(c_this->array[0]);
}
size_t c_int_vector__ capacity(c_int_vector const* c_this){
	return c_this->array_capacity;
}
void c_int_vector__ clear(c_int_vector* c_this){
	memset(c_this->array, 0, c_this->size(c_this));
	c_this->array_num = 0;
}
c_int_vector c_int_vector__ copy(c_int_vector const* c_this){
	c_int_vector res = init_c_int_vector();
	res.array = malloc(c_this->capacity(c_this) * sizeof(int));
	memcpy(res.array, c_this->array, c_this->capacity(c_this));
	res.array_num = c_this->array_num;
	/*res.array_max_num = c_this->array_max_num;*/
	res.array_capacity = c_this->array_capacity;

	return res;
}
bool c_int_vector__ empty(c_int_vector const* c_this){
	return !(c_this->array_num);
}
int* c_int_vector__ end(c_int_vector const* c_this){
	return &(c_this->array[c_this->size(c_this) - 1]);
}
void c_int_vector__ erase(c_int_vector* c_this){

}
size_t c_int_vector__ size(c_int_vector const* c_this){
	return c_this->array_num;
}
size_t c_int_vector__ max_size(c_int_vector const* c_this){
	return c_this->array_max_num;
}
bool c_int_vector__ reserve(c_int_vector* c_this, size_t _Count){
	const size_t old_size = c_this->size(c_this);
	const size_t old_capacity = c_this->capacity(c_this);
	if (old_capacity < _Count || (old_capacity >> 1) > _Count){
		int* temp;
		if (nullptr == (temp = realloc(c_this->array, _Count * sizeof(int)))) return false;
		memset(&(c_this->array[old_size]), 0, _Count - old_size);
		c_this->array = temp;
		c_this->array_capacity = _Count;
	}
}
bool c_int_vector__ resize(c_int_vector* c_this, const size_t Newsize){
	const size_t old_size = c_this->size(c_this);
	const size_t old_capacity = c_this->capacity(c_this);
	if (old_size == Newsize) return true;

	if (old_size > Newsize){
		if ((old_capacity >> 2) > Newsize){
			int* temp;
			if (nullptr == (temp = malloc(2 * Newsize * sizeof(int)))) return false;
			memcpy(temp, c_this->array, Newsize);
			c_this->array_capacity = 2 * Newsize;
			memset(&(c_this->array[Newsize]), 0, c_this->array_capacity - Newsize);
			free(c_this->array);/* 古い領域は忘れずに開放 */
			c_this->array = temp;
		}
		else{
			memset(&(c_this->array[Newsize]), 0, old_size - Newsize);
		}
	}
	else{
		if (Newsize > old_capacity){/* 新しい領域の大きさが確保済み領域を上回るとき */
			int* temp;
			if (nullptr == (temp = realloc(c_this->array, 2 * Newsize * sizeof(int)))) return false;
			memset(&(c_this->array[old_size]), 0, Newsize - old_size);
			c_this->array = temp;
			c_this->array_capacity = 2 * Newsize;
		}
	}
	c_this->array_num = Newsize;
	return true;
}
bool c_int_vector__ pop_back(c_int_vector* c_this){
	c_this->array[c_this->size(c_this) - 1] = 0;/* わざわざresizeを呼び出すまでもない */
	c_this->array_num--;
	return true;
}
bool c_int_vector__ push_back(c_int_vector* c_this, int const* val){
	if (nullptr == val || false == c_this->resize(c_this, c_this->size(c_this) + 1))
		return false;
	c_this->array[c_this->size(c_this) - 1] = *val;
	return true;
}
int compare_int(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}
void c_int_vector__ c_int_vector_sort(c_int_vector* c_this){
	qsort(c_this->array, c_this->array_num, sizeof(int), compare_int);
}
size_t c_int_vector__ c_int_vector_bsearch(c_int_vector* c_this, const int key){
	int const*result = (int*)bsearch(&key, c_this->array, c_this->array_num, sizeof(int), compare_int);
	return (size_t)(result - c_this->array);
}
