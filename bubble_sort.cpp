#include <bits/stdc++.h>

void swap(int* list, int i1, int i2) {
    int temp = list[i1];
    list[i1] = list[i2];
    list[i2] = temp;
}

int bubble_list(int* list, int l, int r) {
    int sorted = 1;
    for(int i = r - 1 ; i > l ; i--) {
        if (list[i] < list[i - 1]) {
            swap(list, i, i - 1);
            sorted = 0;
        }
    }
    return sorted;
} 
void bubble_sort(int* list, int len) {
    for(int i = 0 ; i < len ; i++) {
        int sorted = bubble_list(list, i, len);
        if(sorted == 1) {
            break;
        }
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

    bubble_sort(l, 6);

    printf("\nAfter\n");
    for(int i =  0; i < 6 ; i++) {
        printf("%d element of list:  %d\n", i, l[i]);
    }

    free(l);
}