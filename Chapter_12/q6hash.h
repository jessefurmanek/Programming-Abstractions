//
//  q6hash.h
//  Ch.12_Coursework
//
//  Created by Jesse Furmanek on 3/26/14.
//
//

#ifndef __Ch_12_Coursework__q6hash__
#define __Ch_12_Coursework__q6hash__

#include <iostream>
#include <iostream>
#include "error.h"
#include <cmath>

/*1) Create an array of key/value pairs
 2) Include a hash function
 3) If the hash collides, increment array counter until an empty element is found
 4) Increment counter loops around the end of the array, accomplished by using a modulo
 5) Put key/value pair in open array element
 
 Additional
 - Include “array is full” error*/

using namespace std;
template <typename ValueType>
class Map {
public:
    /*
     * Constructor: Map
     * Usage: Map<int> map;
     * --------------------
     * The constructor initializes a new empty map.
     */
    Map();
    /*
     * Destructor: ~Map
     * Usage: delete mp;
     * -----------------
     * The destructor frees any heap storage associated with this map.
     */
    ~Map();
    /*
     * Method: size
     * Usage: nEntries = map.size();
     * -----------------------------
     * This method returns the number of entries in this map.
     */
    int size();
    /*
     * Method: isEmpty
     * Usage: if (map.isEmpty())...
     * ----------------------------
     * This method returns true if this map contains no entries,
     * false otherwise.
     */
    bool isEmpty();
    /*
     * Method: clear
     * Usage: map.clear();
     * -------------------
     * This method removes all entries from this map.
     */
    void clear();
    /*
     * Method: put
     * Usage: map.put(key, value);
     * ---------------------------
     * This method associates key with value in this map.  Any value
     * previously associated with this key is replaced by the new one.
     */
    void put(string key, ValueType value);
    /*
     * Method: get
     * Usage: value = map.get(key);
     * ----------------------------
     * If key is found in this map, this method returns the associated
     * value.  If key is not found, the get mathod raises an error.
     * Clients can use the containsKey method to verify the presence
     * of a key in the map before attempting to get its value.
     */
    void copyEntriesInto(Map<ValueType> & copy);
    
    //copies all the key/value pairs from the receiver into the copy parameter
    
    ValueType get(string key);
    /*
     * Method: containsKey
     * Usage: if (map.containsKey(key))...
     * -----------------------------------
     * Returns true if there is an entry for key in this map,
     * false otherwise.
     */
    bool containsKey(string key);
    /*
     * Method: remove
     * Usage: map.remove(key);
     * -----------------------
     * This method removes any entry for key from this map.
     * If there is no entry for the key, the map is unchanged.
     */
    void remove(string key);
    
    void insert(string key, ValueType value);
    
    void DisplayHashTableStatistics();
    
    void Sort();
private:
#include "q6hashpriv.h"
    
};

template <typename ValueType>
Map<ValueType>::Map() {
    
    bucketArray = new cellT [INITIAL_SIZE];
    numCells = 0;  //set initial number of cells to 0
    bucketArraySize = INITIAL_SIZE;
    
    for (int i = 0; i < bucketArraySize; i++) {
        bucketArray[i].value =NULL;
        bucketArray[i].key = "";
    }
}
/*
 * Implementation notes: ~Map destructor
 * -------------------------------------
 * The destructor must deallocate every cell (which it can do by
 * calling clear) and then free the dynamic bucket array.
 */
template <typename ValueType>
Map<ValueType>::~Map() {
    delete[] bucketArray;
    
}

/*
 * Implementation notes: size, isEmpty
 * -----------------------------------
 * These methods can each be implemented in a single line
 * because the size is stored in the nEntries instance variable.
 */
template <typename ValueType>
int Map<ValueType>::size() {
    return numCells;
}
template <typename ValueType>
bool Map<ValueType>::isEmpty() {
    return numCells;
}
/*
 * Implementation notes: clear
 * ---------------------------
 * This method calls the recursive deleteChain method for each
 * bucket chain.
 */
template <typename ValueType>
void Map<ValueType>::clear() {
  
    for (int i = 0; i < bucketArraySize; i++) {  //reinitialize the buckets array
        bucketArray[i].key = "";
        bucketArray[i].value = NULL;
    }
    numCells=0;
}
/*
 * Implementation notes: put
 * -------------------------
 * This method first looks to see whether the key already
 * exists in the map by calling the findCell method.  If one
 * exists, this method simply changes the value; if not, the
 * implementation adds a new cell to the beginning of the chain.
 */
template <typename ValueType>
void Map<ValueType>::put(string key, ValueType value) {
    int index = hash(key) % bucketArraySize;
    int cellIndex = findCell(index, key);
    
    if(cellIndex==-1) error("cell array is full");
    
     bucketArray[cellIndex].key=key;
     bucketArray[cellIndex].value = value;
    
    
    numCells++;
    
}

/*
 * Implementation notes: get, containsKey
 * --------------------------------------
 * These methods uses findCell to find the key in the map, which is
 * where all the real work happens.
 */
template <typename ValueType>
ValueType Map<ValueType>::get(string key) {
    int index = hash(key) % bucketArraySize;
    int cellIndex = findCell(index, key);
    if (cellIndex == -1) {
        error("Attempt to get value for key that is not in the map."); }
    
    return bucketArray[cellIndex].value;
}


template <typename ValueType>
bool Map<ValueType>::containsKey(string key) {
    int index = hash(key) % bucketArraySize;
    return findCell(index, key) != -1;
}
/*
 * Implementation notes: remove
 * ----------------------------
 * The remove method cannot use the findCell method as it
 * stands because it needs a pointer to the previous entry.
 * Because that code is used only in this method, the loop
 * through the cells in a chain is reimplemented here and
 * therefore does not add any cost to the get/put operations.
 */
template <typename ValueType>
void Map<ValueType>::remove(string key) {
    int index = hash(key) % bucketArraySize;
    int cellIndex =findCell(index, key);
    
    bucketArray[cellIndex].key="";
    bucketArray[cellIndex].value = NULL;  //reset the removed cell to empty,  value to NULL
  
}

/* Private methods */
/*
 * Implementation notes: hash
 * Usage: bucket = hash(key);
 * --------------------------
 * This function takes the key and uses it to derive a hash code,
 * which is a nonnegative integer.  The hash code is computed
 * using a method called linear congruence.
 */
template <typename ValueType>
int Map<ValueType>::hash(string s) {
    const long MULTIPLIER = -1664117991L;
    unsigned long hashcode = 0;
    for (int i = 0; i < s.length(); i++) {
        hashcode = hashcode * MULTIPLIER + s[i];
    }
    return hashcode & ((unsigned) -1 >> 1);
}
/*
 * Implementation notes: findCell
 * Usage: cell = findCell(chain, key);
 * -----------------------------------
 * This function finds a cell in the chain that matches key.
 * If a match is found, findCell returns a pointer to that cell;
 * if not, findCell returns NULL.
 */

template <typename ValueType>
int Map<ValueType>::findCell(int index, string key) {

    for (int x = 0; x<bucketArraySize; x++){
        if(bucketArray[(index+x)%bucketArraySize].key==key) return ((index+x)%bucketArraySize);  //if the referenced cell is equal to the key, return the cell to overwrite the value
        
        if(bucketArray[((index+x)%bucketArraySize)].key==""){
            return ((index+x)%bucketArraySize);  //if the referenced cell key is empty, return the index for assigning
        }
        
        //if the index is full, continue on to the next cell
    }
   
    return -1;
    
}

template <typename ValueType>
void Map<ValueType>::copyEntriesInto(Map <ValueType> & copy){
    for(int x = 0; x<bucketArraySize; x++){
        copy.put(bucketArray[x].key, bucketArray[x].value);
    }
}


int OperatorCmp(){
    return 0;
}

template<typename Type>
void Sort(Type array[], int n, int (*cmp)(Type, Type) = OperatorCmp){
    
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (cmp(array[j],array[minIndex]) < 0) minIndex = j;
        }
        Type temp =array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}



#endif /* defined(__Ch_12_Coursework__q6hash__) */
