//
//  Vector.cpp
//
//  Created by Uchechukwu Uboh on 1/28/19.
//  Copyright © 2019 Uchechukwu Uboh. All rights reserved.
//

#include <iostream>
#include "Vector.h"

using namespace std;

template <class DataType>
Vector<DataType>::Vector(){
    capacity = 2;
    size = 0;
    dataItems = new DataType[capacity] ();
};

template <class DataType>
Vector<DataType>::~Vector(){
    if(dataItems != NULL){
        delete[] dataItems;
        dataItems = NULL;
    }
    size = 0;
    capacity = 2;
};

template <class DataType>
void Vector<DataType>::append(const DataType item){
    if(dataItems == NULL){
        dataItems = new DataType[capacity];
    }
    int current_capacity = capacity;
    if(isFull()){
        capacity = capacity * 2;
        DataType *tmp = new DataType[capacity] ();
        for(int i = 0; i < current_capacity; i++){
            tmp[i] = dataItems[i];
        }
        dataItems = tmp;
    }
    dataItems[size] = item;
    size++;
};

template <class DataType>
void Vector<DataType>::insertAt(const int index, const DataType item ){
    if(dataItems == NULL){
        dataItems = new DataType[capacity];
    }
    if(index > (capacity - 1)){
        int initial_capacity = capacity;
        while((capacity - 1) < index){
            capacity = (capacity * 2);
        }
        DataType *temp = new DataType[capacity] ();
        for(int i = 0; i < initial_capacity; i++){
            temp[i] = dataItems[i];
        }
        size = index + 1;
        dataItems = temp;
        dataItems[index] = item;
        return;
    } else if(index <= capacity - 1 && index > -1){
        if(isFull()){
            int current_capacity = capacity;
            capacity = capacity * 2;
            DataType *tmp = new DataType[capacity] ();
            for(int i = 0; i<current_capacity; i++){
                tmp[i] = dataItems[i];
            }
            dataItems = tmp;
        }
        for(int i = capacity - 2; i > index - 1; i--){
            dataItems[i + 1] = dataItems[i];
        }
        dataItems[index] = item;
        if(index > size){
            size = size + (index - size) + 1;
        }else{
            size++;
        }
        return;
    }
};

template <class DataType>
void Vector<DataType>::removeAt(const int index ){
    if(index > size - 1 || index < 0){
        return;
    }else if(index <= size){
        if(isFull()){
            int current_capacity = capacity;
            capacity = capacity * 2;
            DataType *tmp = new DataType[capacity] ();
            for(int i = 0; i<current_capacity; i++){
                tmp[i] = dataItems[i];
            }
            dataItems = tmp;
        }
        for(int i = index; i < size; i++){
            dataItems[i] = dataItems[i + 1];
        }
        size--;
    }
    return;
};

template <class DataType>
void Vector<DataType>::remove(DataType item){
    removeAt(contains(item));
};

template <class DataType>
void Vector<DataType>::clear(){
    delete[] dataItems;
    dataItems = NULL;
    capacity = 2;
    size = 0;
};

template <class DataType>
bool Vector<DataType>::isEmpty() const{
    return size == 0;
};

template <class DataType>
bool Vector<DataType>::isFull() const{
    return size == capacity;
};

template <class DataType>
int  Vector<DataType>::contains(const DataType item) const{
    if(size == 0){
        return -1;
    }
    for(int i=0; i<capacity; i++){
        if(dataItems[i] == item){
            return i;
        }
    }
    return -1;
};

template <class DataType>
DataType  Vector<DataType>::elementAt(const int index) const{
    if(isEmpty()){
        throw "Out of bounds";
    }
    if(index > capacity - 1 || index < 0){
        throw "Out of bounds";
    }
    return dataItems[index];
};

template <class DataType>
int  Vector<DataType>::getSize() const{
    return size;
};

// what type of error to throw?
template <class DataType>
DataType& Vector<DataType>::operator[] (const int index){
    if(index < 0 || index > size){
        throw "Out of bounds";
    }
    return dataItems[index];
};

template class Vector<int>;
template class Vector<double>;
template class Vector<char>;
template class Vector<string>;
