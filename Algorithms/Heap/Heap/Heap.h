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
        // delete an item from Heap
        void del(DataType item);
        // clear all items in Heap
        void clear();
        // turn Heap into Min Heap
        void min_Heapify();
        // turn Heap into Max Heap
        void max_Heapify();
        // print heap
        void print();
        // print number of items in Heap
        void get_size();
    
    private:
        // Heap vector
        vector<DataType> heap;
        // root node
        int root;
    
        // print helper class
        void print_helper(int idx);
        // Helper functions
        // return parent
        int get_Parent(int idx);
        // return left child
        int get_Left_child(int idx);
        // return right child
        int get_right_child(int idx);
    
    
};

#endif /* Heap_h */
