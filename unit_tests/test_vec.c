#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "c_tools/vec.h"

void test_ct_vec_with_capacity() {
    ct_vec vec = ct_vec_with_capacity(16);
    assert(vec.capacity == 16);
    assert(vec.size == 0);
    ct_vec_destruct(&vec);
}

void test_ct_vec_push() {
    ct_vec vec = ct_vec_with_capacity(1);

    assert(vec.capacity == 1);
    assert(vec.size == 0);

    ct_vec_push(&vec, 3);
    assert(vec.capacity == 1);
    assert(vec.size == 1);

    ct_vec_push(&vec, 4);
    assert(vec.capacity == 2);
    assert(vec.size == 2);

    ct_vec_push(&vec, 5);
    assert(vec.capacity == 4);
    assert(vec.size == 3);

    assert(vec.data[0] == 3);
    assert(vec.data[1] == 4);
    assert(vec.data[2] == 5);

    ct_vec_destruct(&vec);
}


void test_ct_vec_pop() {
    ct_vec vec = ct_vec_with_capacity(16);

    ct_vec_push(&vec, 2);

    assert(vec.capacity == 16);
    assert(vec.size == 1);

    ct_vec_push(&vec, 3.0);

    assert(vec.capacity == 16);
    assert(vec.size == 2);

    double last = ct_vec_pop(&vec);

    assert(last == 3.0);
    assert(vec.capacity == 16);
    assert(vec.size == 1);

    ct_vec_destruct(&vec);
}


void test_ct_vec_capacity_size() {

    ct_vec vec =ct_vec_with_capacity(2);

    assert(ct_vec_get_capacity(&vec) == 2);
    assert(ct_vec_get_size(&vec) == 0);

    ct_vec_push(&vec, 1);
    ct_vec_push(&vec, 2);

    assert(ct_vec_get_capacity(&vec) == 2);
    assert(ct_vec_get_size(&vec) == 2);

    ct_vec_push(&vec, 3);

    assert(ct_vec_get_capacity(&vec) == 4);
    assert(ct_vec_get_size(&vec) == 3);

    ct_vec_destruct(&vec);
}


int main() {
    
    test_ct_vec_with_capacity();
    test_ct_vec_push();
    test_ct_vec_pop();
    test_ct_vec_capacity_size();
    return 0;
}
