//
//  main.cpp
//  Heap
//
//  Created by Uchechukwu Uboh on 4/22/19.
//  Copyright © 2019 Uchechukwu Uboh. All rights reserved.
//

#include <iostream>
#include "Heap.h"

using namespace std;

int main() {
    
    Heap<int> int_Heap;
    
  
    int_Heap.insert(9);
    int_Heap.insert(-2);
    int_Heap.insert(34);
    int_Heap.insert(90);
    int_Heap.insert(45);
    int_Heap.insert(72);
    int_Heap.insert(5);
    int_Heap.insert(12);
    int_Heap.insert(0);
    int_Heap.insert(8);
    int_Heap.insert(21);
    int_Heap.insert(19);
    
    int_Heap.min_Heapify();
    cout<<"***************"<<endl;
    int_Heap.print();
    
    int_Heap.del(21);
    int_Heap.del(72);
    
    cout<<"***************"<<endl;
    int_Heap.print();
    
    
    return 0;
}
