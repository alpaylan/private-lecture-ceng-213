#include <bits/stdc++.h>


int find_place(int* list, int l, int r, int element) {
    for(int i = l; i <= r ; i++) {
        if(element < list[i]) {
            return i;
        }
    }
    return r;
}
void shift_list_by_one(int* list, int l, int r, int index) {
    int start_shift = index;
    int end_shift = r;
    for(int i = r - 1 ; i >= index ; i--) {
        list[i + 1] = list[i];
    }
}
void place_element_to_index(int* list, int l, int r, int element, int index) {
    shift_list_by_one(list, l, r,  index);
    list[index] = element;
}
void place_element(int* list, int l, int r, int element) {
    int index = find_place(list, l, r, element);
    place_element_to_index(list, l, r, element, index);
}

void insertion_sort(int* list, int len) {
    for(int i = 0 ; i < len ; i++) {
        place_element(list, 0, i, list[i]);
    }
}
int main() {
    int* l = (int *) malloc(sizeof(int)*6);
    l[0] = 23;
    l[1] = 78;
    l[2] = 45;
    l[3] = 8;
    l[4] = 32;
    l[5] = 56;

    printf("Before\n");
    for(int i =  0; i < 6 ; i++) {
        printf("%d element of list:  %d\n", i, l[i]);
    }

    insertion_sort(l, 6);

    printf("\nAfter\n");
    for(int i =  0; i < 6 ; i++) {
        printf("%d element of list:  %d\n", i, l[i]);
    }

    free(l);
}