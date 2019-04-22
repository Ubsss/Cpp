//
//  Linked_List.h
//  Linked List
//
//  Created by Uchechukwu Uboh on 2/2/19.
//  Copyright © 2019 Uchechukwu Uboh. All rights reserved.
//

#ifndef Linked_List_h
#define Linked_List_h

template <class DataType>
class Linked_List {
public:
    Linked_List();
    ~Linked_List();
    struct node;
    void insert_at_front(DataType item);
    void insert_at_end(DataType item);
    void remove(DataType item);
    int contains(DataType item);
    int return_size();
    bool is_empty();
    

private:
    
    DataType *next;
    DataType item;
    int length;
    DataType *head;
};

#endif /* Linked_List_h */
