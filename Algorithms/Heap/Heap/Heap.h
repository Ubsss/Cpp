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
        // destructor
        ~Heap();
        // insert an itemm into Heap
        void insert(DataType item);
        // delete an item from Heap
        void del(DataType item);
        // clear all items in Heap
        void clear();
        // turn Heap into Min Heap
        void min_Heap();
        // turn Heap into Max Heap
        void max_Heap();
        // print heap
        void print();
    
    private:
        // Heap vector
        vector<DataType> heap;
        // Holds vector item
        DataType item;
        // length of vector
        int count;
        // root node
        DataType *root;
    
        // Helper functions
        // return parent
        int get_Parent(int idx);
        // return left child
        int get_Left_child(int idx);
        // return right child
        int get_right_child(int idx);
};

#endif /* Heap_h */
