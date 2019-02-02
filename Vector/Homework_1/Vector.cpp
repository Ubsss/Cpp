//
//  Vector.cpp
//  Algo_HM1
//
//  Created by Uchechukwu Uboh on 1/28/19.
//  Copyright © 2019 Uchechukwu Uboh. All rights reserved.
//
#include <iostream>
#include "Vector.h"

using namespace std;

// Default constructor
template <class DataType>
Vector<DataType>::Vector(){
    capacity = 2;
    size = 0;
    dataItems = new DataType[capacity] ();
};

// Destructor
template <class DataType>
Vector<DataType>::~Vector (){
//    delete[] dataItems; //dataItems probably freed twixe
    dataItems = NULL;
    delete dataItems;
    size = 0;
};

// Vector manipulation operations
// Add a new item to the end of the vector
// Question: Add items to the first available position fromt the front or the back of the vector?
template <class DataType>
void Vector<DataType>::append (const DataType item){
    int current_capacity = capacity;
    if(isFull()){
        capacity = capacity * 2;
        DataType *tmp = new DataType[capacity] ();
        for(int i = 0; i<current_capacity; i++){
            tmp[i] = dataItems[i];
        }
        // Memory leak??
        //delete[] dataItems; /
        dataItems = tmp;
        //delete tmp;
    }
    dataItems[size] = item;
    size++;
};

// Insert a new element at the given index
template <class DataType>
void Vector<DataType>::insertAt (const int index, const DataType item ){
    if(index > (capacity - 1)){
        int initial_capacity = capacity;
        while((capacity - 1)<index){
            capacity = (capacity*2);
        }
        DataType *temp = new DataType[capacity] ();
        for(int i = 0; i < initial_capacity;i++){
            temp[i] = dataItems[i];
        }
        size = index + 1;
        dataItems = temp;
        dataItems[index] = item;
        //Memory leak?
        //delete[] temp;
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
            //delete[] dataItems;
            //delete tmp;
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

// DONE
// Remove the data item at the given index
template <class DataType>
void Vector<DataType>::removeAt (const int index ){
    if(index > size - 1 || index < 0){
        cout<<"Index has no item."<<endl;
        return;
    }else if(index <=size){
        if(isFull()){
            int current_capacity = capacity;
            capacity = capacity * 2;
            DataType *tmp = new DataType[capacity] ();
            for(int i = 0; i<current_capacity; i++){
                tmp[i] = dataItems[i];
            }
            dataItems = tmp;
            //delete[] dataItems;
            //delete tmp;
        }
        for(int i = index; i < size; i++){
            dataItems[i] = dataItems[i + 1];
        }
        size--;
    }
    return;
};

// Remove the given element from the vector
// Remove item for the front of the vector
template <class DataType>
void Vector<DataType>::remove(int item){
    
};

// Make the vector empty
template <class DataType>
void Vector<DataType>::clear (){
    size = 0;
    delete[] dataItems;
    dataItems = NULL;
    dataItems = new DataType[capacity];
};

// DONE
// Voector status operations
// Is the Vector empty?
template <class DataType>
bool Vector<DataType>::isEmpty () const{
    return size == 0;
};

//DONE
// Is the Vector full?
template <class DataType>
bool Vector<DataType>::isFull() const{
    return size == capacity;
};

// DONE!!
// Does the vector contain the given item? return the index of the item if found, otherwise, return -1.
template <class DataType>
int  Vector<DataType>::contains(const DataType item) const{
    if(size == 0){
        cout<<"Vector is empty!"<<endl;
        return -1;
    }
    for(int i=0; i<capacity; i++){
        if(dataItems[i]==item){
            return i;
        }
    }
    return -1;
};

//DONE
// Access the element at the given index
// Return element if index exist else return dataItems[0] if item
template <class DataType>
DataType  Vector<DataType>::elementAt(const int index) const{
    if(isEmpty()){
        cout<<"list is empty"<<endl;
        return dataItems[0];
    }
    if(index>capacity - 1 || index < 0){
        return dataItems[0];
    }
    return dataItems[index];
    
};

//DONE
// Return the number of items in the vector
template <class DataType>
int  Vector<DataType>::getSize() const{
    return size;
};

// Done
// overloading subscript []
template <class DataType>
DataType& Vector<DataType>::operator[] (const int index){
    return dataItems[index];
};

// My function to print the vector list for debuding
template <class DataType>
void Vector<DataType>::print_vector(){
    if(size==0){
        cout<<"Vector is empty"<<endl;
        return;
    }
    for(int i = 0; i<capacity;i++){
        cout<<dataItems[i]<<endl;
    }
};

template class Vector<int>;
template class Vector<double>;
template class Vector<char>;
template class Vector<string>;


