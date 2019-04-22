//
//  Sort.h
//  Sorting_algorithms
//
//  Created by Uchechukwu Uboh on 3/2/19.
//  Copyright © 2019 Uchechukwu Uboh. All rights reserved.
//

#ifndef SORT_H
#define SORT_H


using namespace std;

class Sort
{
public:
    // Constructors
    Sort(char *list, int num); // Default constructor
    // Destructor
    ~Sort();
    
    // Vector manipulation operations
    void selectionSort(); // implement the selection sort algorithm
    void insertionSort(); // implement the selection sort algorithm
    
    void MERGESORT();   // call mergeSort with parameters
    void QUICKSORT();   // call quickSort with parameters
    
    void print();       // print all items in the dataItems
    int  getSize() const { return size;}           // Return the number of items in the vector
    char* getData() const {return dataItems;}
    
private:
    // Data members
    int size;        // Actual number of data item in the vector
    char *dataItems;  // Array containing the vector data item
    
    void mergeSort(char *list, int num); // implement the merge sort algorithm
    void merge(char *A, int N, char *B, int M, char* C); // merge A and B to C in ascending order
    void quickSort(char *list, int left, int right); // implement the quick sort algorithm
    int partition(char *list, int left, int right);  // Quick sort algorithm: partition the list using a pivot and return the position of the pivot after partitioning
};

#endif

