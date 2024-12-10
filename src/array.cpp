#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Array{
    size_t capacity;
    size_t size;
    size_t element_size;
    void* data;
}Array;

void initArray(Array* arr, size_t initial_capacity, size_t element_size){
    arr->data = malloc(initial_capacity * element_size);
    if (arr->data == NULL) {
        printf("Error at asigne memory\n");
        exit(1);
    }
    arr->size = 0;
    arr->capacity = initial_capacity;
    arr->element_size = element_size;
} 

void resizeArray(Array* arr, size_t new_size){
    void* new_data = realloc(arr->data, new_size * arr->element_size);
    if(new_data == NULL){
        printf("Error at resize the memory\n");
        free(arr->data);
        exit(1);
    }
    arr->data = new_data;
    arr->capacity = new_size;
}

void addElement(Array* arr, void* element){
    if(arr->size == arr->capacity){
        resizeArray(arr, arr->capacity * 2);
    }
    void* destination = (char*)arr->data + (arr->size * arr->element_size);
    memcpy(destination, element, arr->element_size);
    arr->size++;
}
void freeArray(Array* arr){
    free(arr->data);
    arr->data = NULL;
    arr->size = arr->capacity = arr->element_size = 0;
}
void printArrayInt(Array* arr) {
    for (size_t i = 0; i < arr->size; i++) {
        int* element = (int*)((char*)arr->data + i * arr->element_size);
        printf("%d ", *element);
    }
    printf("\n");
}
void removeElement(Array* arr, int index) {
    if (index < 0 || index >= (int)arr->size) {
        printf("Index out of bounds\n");
        return;
    }
    
    for (size_t i = index; i < arr->size - 1; i++) {
        void* current = (char*)arr->data + i * arr->element_size;
        void* next = (char*)arr->data + (i + 1) * arr->element_size;
        memcpy(current, next, arr->element_size);
    }
    
    arr->size--;
}
void printElementInt(Array* arr, int index){
    int* element = (int*)((char*)arr->data + index * arr->element_size);
    printf("%d \n", *element);
}