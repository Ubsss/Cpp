#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
    char myList1[10]={'E','X','A','M','P','L','E'};
    int len1 = 7;
    Sort mySort1(myList1,len1);
    cout << "Insertion Sort" << endl;
    mySort1.print();
    mySort1.insertionSort();
    cout<<"*****************"<<endl;
    mySort1.print();
    
    char myList2[10]={'E','X','A','M','P','L','E'};
    int len2 = 7;
    Sort mySort2(myList2,len2);
    cout << "Selection Sort" << endl;
    mySort2.print();
    mySort2.selectionSort();
    cout<<"*****************"<<endl;
    mySort2.print();
    
    char myList3[10]={'E','X','A','M','P','L','E'};
    int len3 = 7;
    Sort mySort3(myList3,len3);
    cout << "Merge Sort" << endl;
    mySort3.print();
    mySort3.MERGESORT();
    cout<<"*****************"<<endl;
    mySort3.print();
    
    char myList4[10]={'E','X','A','M','P','L','E'};
    int len4 = 7;
    Sort mySort4(myList4,len4);
    cout << "Quick Sort" << endl;
    mySort4.print();
    mySort4.QUICKSORT();
    cout<<"*****************"<<endl;
    mySort4.print();
    
    return 0;
}
