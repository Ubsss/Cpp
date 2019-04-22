//
//  Linked_List.cpp
//  Linked List
//
//  Created by Uchechukwu Uboh on 2/2/19.
//  Copyright © 2019 Uchechukwu Uboh. All rights reserved.
//

#include "Linked_List.h"
#include <iostream>

using namespace std;

template <class DataType>
Linked_List<DataType>::Linked_List(){
    
    
};

template <class DataType>
Linked_List<DataType>::~Linked_List(){
    
};
//template <class DataType>
//Linked_List<DataType>::node{
//    
//};

template <class DataType>
void Linked_List<DataType>::insert_at_front(DataType item){
    
};

template <class DataType>
void Linked_List<DataType>::insert_at_end(DataType item){
    
};

template <class DataType>
void Linked_List<DataType>::remove(DataType item){
    
};

template <class DataType>
int Linked_List<DataType>::contains(DataType item){
    
    return 0;
};

template <class DataType>
int Linked_List<DataType>::return_size(){
    
    return 0;
};

template <class DataType>
bool Linked_List<DataType>::is_empty(){
    
    return false;
};


template class Linked_List<int>;
template class Linked_List<double>;
template class Linked_List<char>;
template class Linked_List<string>;

