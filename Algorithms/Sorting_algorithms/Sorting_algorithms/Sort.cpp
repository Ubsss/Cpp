//
//  Sort.cpp
//  Sorting_algorithms
//
//  Created by Uchechukwu Uboh on 3/2/19.
//  Copyright © 2019 Uchechukwu Uboh. All rights reserved.
//

#include "Sort.h"
#include <iostream>
#include <time.h>

using namespace std;

// Constructors
Sort::Sort(char *list, int num){
    size = num;
    if(num <= 0){
        return;
    }
    dataItems = list;
};

// Destructor
Sort::~Sort(){
    dataItems = nullptr;
    delete dataItems;
    size = 0;
};

// Vector manipulation operations
// implement the selection sort algorithm
void Sort::selectionSort(){
    if(size < 1){
        cout<<"Array size is less than 1!"<<endl;
        return;
    }
    char min;
    for(int i = 0; i<size - 1; i++){
        min = dataItems[i];
        for(int j = i + 1; j<size; j++){
            if(dataItems[j] < min)
                swap(dataItems[j], min);
        }
        dataItems[i] = min;
    }
};

// implement the selection sort algorithm
void Sort::insertionSort(){
    for(int i = 0; i < size; i++){
        char temp = dataItems[i];
        int j = i;
        while( j > 0 && temp < dataItems[j - 1]){
            dataItems[j] = dataItems[j - 1];
            j=j - 1;
        }
        dataItems[j] = temp;
    }
};

// call mergeSort with parameters
void Sort::MERGESORT(){
    mergeSort(dataItems, size);
};

// call quickSort with parameters
void Sort::QUICKSORT(){
    quickSort(dataItems, 0, size-1);
};

// print all items in the dataItems
void Sort::print(){
    try {
        for (int i=0; i<size;i++) {
            cout<<dataItems[i]<<endl;
        }
    } catch (const std::exception& e) {
        cout<<"There is an error"<<endl;
    }
};

// implement the merge sort algorithm
void Sort::mergeSort(char *list, int num){
    if(num > 1){
        mergeSort(list, num / 2);
        mergeSort(list + num / 2, num - num / 2);
        char *c = (char*)malloc(num * sizeof(char));
        merge(list, num / 2, list + num / 2, num - num / 2, c);
        free(c);
    }
    
};

// merge A and B to C in ascending order
void Sort::merge(char *A, int N, char *B, int M, char* C){
    int i = 0, j = 0, k = 0;
    
    while (i < M && j < N) {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }
    while (i < M)
        C[k++] = A[i++];
    
    while (j < N)
        C[k++] = B[j++];
    
    for (int i = 0; i < k; i++)
        A[i] = C[i];
};

// implement the quick sort algorithm
void Sort::quickSort(char *list, int left, int right){
    if(left < right){
        int piv_pos = partition(list, left, right);
        quickSort(list, left, piv_pos - 1);
        quickSort(list, piv_pos+1, right);
    }
};

// Quick sort algorithm: partition the list using a pivot and return the position of the pivot after partitioning
int Sort::partition(char *list, int left, int right){
    int i = left + 1;
    int piv = list[left];
    
    for( int j = left + 1; j <= right; j++){
        if(list[j] < piv){
            swap(list[i], list[j]);
            i++;
        }
    }
    swap(list[left], list[i-1]);
    return i-1;
};
