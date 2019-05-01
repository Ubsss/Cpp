//
//  Heap.h
//  Heap
//
//  Created by Uchechukwu Uboh on 4/22/19.
//  Copyright © 2019 Uchechukwu Uboh. All rights reserved.
//
#include <vector>

using namespace std;

#ifndef Heap_h
#define Heap_h

template <class DataType>
class Heap{
    public:
        // constructor
        Heap();
        // insert an itemm into Heap
        void insert(DataType item);
        // clear all items in Heap
        void clear();
        // turn Heap into Min Heap
        void min_heap_sort();
        // turn Heap into Max Heap
        void max_heap_sort();
        // print heap
        void print();
        // print number of items in Heap
        void get_size();
    
    private:
        // Heap vector
        vector<DataType> heap;
        // root node
        int root;
    
        // Helper functions
        // print helper class
        void print_helper(int idx);
        // max_heapify helper
        void max_heapify(vector<DataType> &list, int n, int idx);
        // min_heapify helper
        void min_heapify(vector<DataType> &list, int n,int idx);
        // return parent
        int get_Parent(int idx);
        // return left child
        int get_left_child(int idx);
        // return right child
        int get_right_child(int idx);
};

#endif /* Heap_h */
