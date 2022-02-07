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
void  ct_vec_push(ct_vec* const, double);

/** Create a vector with capacity.
 */
ct_vec ct_vec_with_capacity(size_t);

/** Destruct the vector.
 *
 * Since the vector contains dynamically allocated
 * memory, this needs to be de-allocated after usage.
 */
void ct_vec_destruct(ct_vec * const);

/** Pop the last element from the vector.
 */
double ct_vec_pop(ct_vec * const);

/** Get the capacity of the vector
 */ 
size_t ct_vec_get_capacity(ct_vec * const);

/** Get the size of the Vector
 */ 
size_t ct_vec_get_size(ct_vec * const);

#endif
