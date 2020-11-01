#include <bits/stdc++.h>

typedef uint8_t pixel; 

typedef struct 
{
    pixel im[10][10] = {};
} image;

image* formImageArray(int number_of_images) {
    image* image_array = (image *) malloc(sizeof(image)*number_of_images);
    for(int i = 0 ; i < number_of_images ; i++) {
        for(int j = 0 ; j < 10 ; j++) {
            for(int k = 0 ; k < 10 ; k++) {
                image_array[i].im[j][k] = random()%255;
            }
        }
    }
    return image_array;
}

void displayImage(image& im) {
    for(int i = 0 ; i < 10 ; i++) {
        for(int j = 0 ; j < 10 ; j++) {
            printf("%d ", im.im[i][j]);
        }
        printf("\n");
    }
}
void displayImages(image* image_array, int n_image) {
    for(int i = 0 ; i < n_image ; i++) {
        printf("Image %d \n", i + 1);
        printf("---------------------------------------------------------------\n");
        displayImage(image_array[i]);
        printf("\n");
    }
}
void AdjustContrast(image& im, int contrastFactor) {
    for(int i = 0 ; i < 10 ; i++) {
        for(int j = 0 ; j < 10 ; j++) {
            im.im[i][j] /= contrastFactor;
        }
    }   
}
int main() {
    srand(time(0));

    int image_num = 0, contrastFactor = 0;

    printf("Enter the number of image you want to create: ");
    scanf("%d", &image_num);
    
    image* my_image_array = formImageArray(image_num);
    
    displayImages(my_image_array, image_num);
    
    printf("Enter contrastFactor: ");
    scanf("%d", &contrastFactor);
    
    for(int i = 0 ; i < image_num ; i++) {
        AdjustContrast(my_image_array[i], contrastFactor);
    }
    
    printf("After adjusting contrast\n");
    
    displayImages(my_image_array, image_num);
    
}