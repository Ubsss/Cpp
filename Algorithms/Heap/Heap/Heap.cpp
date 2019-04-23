//
//  Heap.cpp
//  Heap
//
//  Created by Uchechukwu Uboh on 4/22/19.
//  Copyright © 2019 Uchechukwu Uboh. All rights reserved.
//

#include "Heap.h"
#include <iostream>

using namespace std;

// constructor
template <class DataType>
Heap<DataType>::Heap(){
    
};

// destructor
template <class DataType>
Heap<DataType>::~Heap(){
    
};

// insert an itemm into Heap
template <class DataType>
void Heap<DataType>::insert(DataType item){
    
};

// delete an item from Heap
template <class DataType>
void Heap<DataType>::del(DataType item){
    
};

// clear all items in Heap
template <class DataType>
void Heap<DataType>::clear(){
    
};

// turn Heap into Min Heap
template <class DataType>
void Heap<DataType>::min_Heap(){
    
};

// turn Heap into Max Heap
template <class DataType>
void Heap<DataType>::max_Heap(){
    
};

// print heap
template <class DataType>
void Heap<DataType>::print(){
    
};

// return parent
template <class DataType>
int Heap<DataType>::get_Parent(int idx){
    return idx/2;
};

// return left child
template <class DataType>
int Heap<DataType>::get_Left_child(int idx){
    return 2*idx;
};

// return right child
template <class DataType>
int Heap<DataType>::get_right_child(int idx){
    return (2*idx)+1;
};


template class Heap<int>;
template class Heap<char>;
template class Heap<string>;
