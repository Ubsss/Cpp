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

// clear all items in Heap - DONE
template <class DataType>
void Heap<DataType>::clear(){
    heap.clear();
};

// turn Heap into Min Heap - DONE
template <class DataType>
void Heap<DataType>::min_heap_sort(){
    // Build heap (rearrange array)
    for (int i = heap.size() / 2 - 1; i >= 0; i--)
        min_heapify(heap, heap.size(), i);
    
    // One by one extract an element from heap
    for (int i=heap.size()-1; i>=0; i--)
    {
        // Move current root to end
        swap(heap[0], heap[i]);
        
        // call min heapify on the reduced heap
        min_heapify(heap, i, 0);
    }
};

// min_heapify helper - DONE
template <class DataType>
void  Heap<DataType>::min_heapify(vector<DataType> &list, int n, int idx){
    int smallest = idx; // Initialize largest as root
    int l = get_left_child(idx); // left = 2*i + 1
    int r = get_right_child(idx); // right = 2*i + 2
    
    // If left child is less than root
    if (l < n && list[l] < list[smallest])
        smallest = l;
    
    // If right child is less than smallest so far
    if (r < n && list[r] < list[smallest])
        smallest = r;
    
    // If smallest is not root
    if (smallest != idx)
    {
        swap(list[idx], list[smallest]);
        
        // Recursively heapify the affected sub-tree
        min_heapify(list, n, smallest);
    }    
};

// turn Heap into Max Heap - DONE
template <class DataType>
void Heap<DataType>::max_heap_sort(){
    // Build heap (rearrange array)
    for (int i = heap.size() / 2 - 1; i >= 0; i--)
        max_heapify(heap, heap.size(), i);
    
    // One by one extract an element from heap
    for (int i=heap.size()-1; i>=0; i--)
    {
        // Move current root to end
        swap(heap[0], heap[i]);
        
        // call max heapify on the reduced heap
        max_heapify(heap, i, 0);
    }
};

// max_heapify helper - DONE
template <class DataType>
void Heap<DataType>::max_heapify(vector<DataType> &list, int n, int idx){
    int largest = idx; // Initialize largest as root
    int l = get_left_child(idx); // left = 2*i + 1
    int r = get_right_child(idx); // right = 2*i + 2
    
    // If left child is larger than root
    if (l < n && list[l] > list[largest])
        largest = l;
    
    // If right child is larger than largest so far
    if (r < n && list[r] > list[largest])
        largest = r;
    
    // If largest is not root
    if (largest != idx)
    {
        swap(list[idx], list[largest]);
        
        // Recursively heapify the affected sub-tree
        max_heapify(list, n, largest);
    }
};

// print heap - DONE
template <class DataType>
void Heap<DataType>::print(){
//    for(int i = 0; i  <heap.size(); i++)
//        cout<<heap[i]<<", ";
//    cout<<endl;
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
    if(get_left_child(idx) < heap.size())
        cout<< heap[get_left_child(idx)]<<" <-lc ";
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
    return (idx/2)-1;
};

// return left child - DONE
template <class DataType>
int Heap<DataType>::get_left_child(int idx){
    return (2*idx)+1;
};

// return right child - DONE
template <class DataType>
int Heap<DataType>::get_right_child(int idx){
    return (2*idx)+2;
};

template class Heap<int>;
template class Heap<char>;
