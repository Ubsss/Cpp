//
//  Heap.cpp
//  Heap
//
//  Created by Uchechukwu Uboh on 4/22/19.
//  Copyright © 2019 Uchechukwu Uboh. All rights reserved.
//

#include "Heap.h"
#include <iostream>
#include <vector>

using namespace std;

// constructor - DONE
template <class DataType>
Heap<DataType>::Heap(){
    root = 0;
};

// insert an itemm into Heap - DONE
template <class DataType>
void Heap<DataType>::insert(DataType item){
    heap.push_back(item);
};

// delete an item from Heap and resort - DONE
template <class DataType>
void Heap<DataType>::del(DataType item){
    for(int i=1;i<heap.size();i++){
        if(heap[i] == item){
            heap.erase(heap.begin()+i);
            return;
        }
    }
    cout<<"Item is not in Heap!"<<endl;
};

// clear all items in Heap - DONE
template <class DataType>
void Heap<DataType>::clear(){
    heap.clear();
};

// turn Heap into Min Heap - DONE
template <class DataType>
void Heap<DataType>::min_Heapify(){
    int tail = heap.size() - 1;
    while(root != tail){
        for(int i = 0; i < (tail + 1); i++){
            if(heap[root] <  heap[i])
                swap(heap[root], heap[i]);
        }
        swap(heap[root], heap[tail]);
        tail--;
    }
};

// turn Heap into Max Heap - DONE
template <class DataType>
void Heap<DataType>::max_Heapify(){
    int tail = heap.size() - 1;
    while(root != tail){
        for(int i = 0; i < (tail + 1); i++){
            if(heap[root] > heap[i])
                swap(heap[root], heap[i]);
        }
        swap(heap[root], heap[tail]);
        tail--;
    }
};

// print heap - DONE
template <class DataType>
void Heap<DataType>::print(){
    if(root > heap.size()){
        cout<<"Heap is empty"<<endl;
        return;
    }
    print_helper(root);
};

// print number of items in Heap - DONE
template <class DataType>
void Heap<DataType>::get_size(){
    if(root > heap.size()){
        cout<<"Heap is empty!"<<endl;
        return;
    }
    cout<<"Heap contains "<< heap.size()<<" items."<<endl;
};

// print helper class - DONE
template <class DataType>
void Heap<DataType>::print_helper(int idx){
    if(idx >= heap.size())
        return;
    if(get_Left_child(idx) < heap.size())
        cout<< heap[get_Left_child(idx)]<<" <-lc ";
    else
        cout<<"  <-lc ";
    cout<<"("<<heap[idx]<<")";
    if(get_right_child(idx) < heap.size())
        cout<<" rc-> "<< heap[get_right_child(idx)];
    else
        cout<<" rc-> ";
    cout<<endl;
    idx++;
    print_helper(idx);
};

// return parent - DONE
template <class DataType>
int Heap<DataType>::get_Parent(int idx){
    return (idx-1)/2;
};

// return left child - DONE
template <class DataType>
int Heap<DataType>::get_Left_child(int idx){
    return (2*idx)+1;
};

// return right child - DONE
template <class DataType>
int Heap<DataType>::get_right_child(int idx){
    return (2*idx)+2;
};

template class Heap<int>;
template class Heap<char>;
