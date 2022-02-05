#ifndef C_TOOLS_VEC_H
#define C_TOOLS_VEC_H

/** Vector of variable size, that is dynamically allocatable
 */
typedef struct ct_vec_t {
    size_t capacity;
    size_t size;
    double* data;
} ct_vec;


/** Push an element onto the vector.
 */
void  ct_vec_push(ct_vec* const self, double x);

/** Create a vector with capacity.
 */
ct_vec ct_vec_with_capacity(size_t capacity);

/** Destruct the vector.
 *
 * Since the vector contains dynamically allocated
 * memory, this needs to be de-allocated after usage.
 */
void ct_vec_destruct(ct_vec * const self);

#endif