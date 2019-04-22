//
//  main.cpp
//  Linked List
//
//  Created by Uchechukwu Uboh on 2/2/19.
//  Copyright © 2019 Uchechukwu Uboh. All rights reserved.
//

#include <iostream>
#include "Linked_List.h"
#include <typeinfo>

using namespace std;

void recu_select_sort(int *a, int n){
// create an iterator to keep track of position
// check to make sure iterator is not greater than n
// 
        
}


void reverse_string(string name, int size){
    int end = size;
    char bs[size];
    
    for(int i = 0; i < size; i++){
        bs[i] = name[i];
    }
    
    for(int i = size - 1; i > -1; i --){
        if(bs[i] == ' '){
            for(int j = i; j<end; j++){
                cout<<bs[i];
            }
            end = i;
        }
    }
    
}

int main() {
    
    return 0;
}
