#include <bits/stdc++.h>

void swap(int* list, int i1, int i2) {
    int temp = list[i1];
    list[i1] = list[i2];
    list[i2] = temp;
}

int find_min_index(int* list, int l, int r) {
    int min = list[l];
    int min_index = l;
    for (int i = l ; i <= r ; i++) {
        if (min >= list[i]) {
            min = list[i];
            min_index = i;
        }
    }
    return min_index;
}
void selection_sort(int* list, int len) {
    for(int i = 0 ; i < len ; i++) {
        int index = find_min_index(list, i, len - 1);
        swap(list, i, index);
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

    selection_sort(l, 6);

    printf("\nAfter\n");
    for(int i =  0; i < 6 ; i++) {
        printf("%d element of list:  %d\n", i, l[i]);
    }

    free(l);
}