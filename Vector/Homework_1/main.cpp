//
//  main.cpp
//  Homework_1
//
//  Created by Uchechukwu Uboh on 1/29/19.
//  Copyright © 2019 Uchechukwu Uboh. All rights reserved.
//
#include "Vector.h"
#include <iostream>

using namespace std;


int main() {
    
    Vector<int> intVect;
    
    

    intVect.insertAt(5, 10);
    intVect.insertAt(6, 10);
    intVect.insertAt(5, 10);
    intVect.insertAt(-4, 10);
    intVect.append(22);
    intVect.removeAt(-3);
    



    intVect.print_vector();
    cout<<"The vector contains "<< intVect.getSize()<<" items."<<endl;
    
    
//    Vector<char> charVect;
//
//    charVect.append('h');
//    charVect.append('t');
//    charVect.append('p');
//    charVect.print_vector();
    return 0;
}