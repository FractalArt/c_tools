#include <stdlib.h>
#include <assert.h>

#include <c_tools/vec.h>

ct_vec ct_vec_with_capacity(size_t capacity) {
    ct_vec _tmp = {
        .capacity = capacity,
        .size = 0,
        .data = malloc(capacity * sizeof(double))
    };

    // check if the data could be allocated:
    assert(_tmp.data != NULL);
    return _tmp;
}


void ct_vec_destruct(ct_vec * const self) {
    free(self->data);
}


void  ct_vec_push(ct_vec* const self, double x) {
    if (self->size < self->capacity) {
        self->data[self->size++] = x;
    } else {
        double* new_data = (double *) realloc(self->data, 2 * self->capacity * sizeof(double));
        assert(new_data != NULL);
        self->data = new_data;
        self->data[self->size++] = x;
        self->capacity *= 2;

    }
}


double ct_vec_pop(ct_vec * const self) {
   return self->data[--self->size]; 
}


size_t ct_vec_get_capacity(ct_vec * const self) {
    return self->capacity; 
}

size_t ct_vec_get_size(ct_vec * const self) {
    return self->size;
}


