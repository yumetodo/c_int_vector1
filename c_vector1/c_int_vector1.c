#include "c_int_vector.h"

void c_int_vector__ assign(c_int_vector const* c_this, size_t Count, int Val){
	c_this->reserve(c_this, Count * 2);
	for (int i = 0; i < Count; i++){
		c_this->push_back(c_this, Val);
	}
}
void c_int_vector__ assign_by_array(c_int_vector const* c_this, iterator_int First, iterator_int Last){
	iterator_int it;
	for (it = First; it != Last; it++){
		c_this->push_back(c_this, *it);
	}
	if (it == Last) c_this->push_back(c_this, *Last);
}
int c_int_vector__ at(c_int_vector const* c_this, size_t place){
	if (c_this->size(c_this) - 1 < place) return INT_MAX;
	return c_this->array[place];
}
int c_int_vector__ back(c_int_vector const* c_this){
	return c_this->array[c_this->size(c_this) - 1];
}
iterator_int c_int_vector__ begin(c_int_vector const* c_this){
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
iterator_int c_int_vector__ end(c_int_vector const* c_this){
	return &(c_this->array[c_this->size(c_this) - 1]);
}
void c_int_vector__ erase(c_int_vector* c_this, int const* _Where){
	size_t i;
	iterator_int it;
	/* 一致するポインターを線形探索、減算命令だけで出来る・・・のかな？ */
	for (it = c_this->begin(c_this), i = 0; it != _Where && it != c_this->end(c_this); it++, i++);
	if (it == _Where){
		if (_Where != c_this->end(c_this)){
			/* 前に詰める */
			memmove(&(c_this->array[i]), &(c_this->array[i + 1]), c_this->size(c_this) - 1 - i);
		}
		c_this->pop_back(c_this);/* 後ろを消去 */
	}
}
void c_int_vector__ erase_by_range(c_int_vector* c_this, int const* _First, int const* _Last){
	if (_First == c_this->end(c_this)){
		c_this->pop_back(c_this);
	}
	else if (_First == _Last){
		c_this->erase(c_this, _First);
	}
	else{
		size_t i, j;
		iterator_int it1;
		for (it1 = c_this->begin(c_this), i = 0; it1 != _First && it1 != c_this->end(c_this); it1++, i++);
		if (_Last == c_this->end(c_this)){
			j = c_this->size(c_this) - 1;
		}
		else{
			for (j = 0; it1 != _Last && it1 != c_this->end(c_this); it1++, j++);
		}
		/* 前に詰める */
		memmove(&(c_this->array[i]), &(c_this->array[j]), c_this->size(c_this) - 1 - j);
		c_this->resize(c_this, c_this->size(c_this) - 1 - j + i);/* 後ろを消去 */
	}
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
