//--------------------------------------------------------------------
//
//  Homework                                            Vector.h
//
//  Class declaration for the array implementation of the Vector ADT
//
//--------------------------------------------------------------------

#ifndef VECTOR_H
#define VECTOR_H

using namespace std;

template <class DataType>
class Vector
{
public:
    // Constructors
    Vector(); // Default constructor
    // Destructor
    ~Vector ();
    
    // Vector manipulation operations
    void append (const DataType item); // Add a new item to the end of the vector
    void insertAt (const int index, const DataType item );  // Insert a new element at the given index
    void removeAt (const int index );        // Remove the data item at the given index
    void remove(DataType item); //**** Remove the given element from the vector
    void clear ();                         // Make the vector empty
    
    // Vector status operations
    bool isEmpty () const;                  // Is the Vector empty?
    bool isFull() const;                    // Is the Vector full?
    int  contains(const DataType item) const;    // Does the vector contain the given item? return the index of the item if found, otherwise, return -1.
    DataType  elementAt(const int index) const;  // Access the element at the given index
    int  getSize() const;                      // Return the number of items in the vector
    DataType &operator[] (const int index);   // overloading subscript []
    
    void print_vector(); //Print vector
    
private:
    // Data members
    int capacity;       // the capacity of the vector
    int size;        // Actual number of data item in the vector
    DataType *dataItems;  // Array containing the vector data item
};

#endif

