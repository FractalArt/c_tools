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
    printf("%ld\n", vec.size);
    assert(vec.size == 3);

    assert(vec.data[0] == 3);
    assert(vec.data[1] == 4);
    assert(vec.data[2] == 5);

    ct_vec_destruct(&vec);
}


int main() {
    
    test_ct_vec_with_capacity();
    test_ct_vec_push();
    return 0;
}
