#include <bits/stdc++.h>

void swap(int* list, int i1, int i2) {
    int temp = list[i1];
    list[i1] = list[i2];
    list[i2] = temp;
}

void merge_list(int* list, int l1, int r1, int l2, int r2) {
    int c1 = l1;
    int c2 = l2;
    int* l_copy = (int* )malloc(sizeof(int)*(r2 - l1 + 1));
    int j = 0;
    while(c1 <= r1 && c2 <= r2) {
        if(list[c1] < list[c2]) {
            l_copy[j] = list[c1];
            c1++;
        } else {
            l_copy[j] = list[c2];
            c2++;
        }
        j++;
    }
    if(c1 <= r1) {
        for(int i = c1 ; i <= r1 ; i++) {
            l_copy[j] = list[i];
            j++;
        }
    } else if(c2 <= r2) {
        for(int i = c2 ; i <= r2 ; i++) {
            l_copy[j] = list[i];
            j++;
        }
    }
    for(int i = l1 ; i <= r2 ; i++) {
        list[i] = l_copy[i - l1];
    }
    free(l_copy);
}
void merge_sort_from_to(int* list, int l, int r) {
    if(l != r) {
                
        int mid = (l + r) / 2;
        merge_sort_from_to(list, l, mid);
        merge_sort_from_to(list, mid + 1, r);

        merge_list(list, l, mid, mid + 1, r);

    }
}
void merge_sort(int* list, int len) {
    merge_sort_from_to(list, 0, len - 1);
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

    merge_sort(l, 6);

    printf("\nAfter\n");
    for(int i =  0; i < 6 ; i++) {
        printf("%d element of list:  %d\n", i, l[i]);
    }

    free(l);
}