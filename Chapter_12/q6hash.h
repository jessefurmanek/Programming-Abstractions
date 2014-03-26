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
private:
#include "q6hashpriv.h"
    
};

template <typename ValueType>
Map<ValueType>::Map() {
    counter.nBuckets = INITIAL_SIZE;
    buckets = new cellT *[counter.nBuckets];
    
    cellCounter = new int[INITIAL_SIZE]; //create an array to hold the size (i.e. # of cells) of each of the buckets
    
    for (int i = 0; i < counter.nBuckets; i++) {
        buckets[i] = NULL;
        cellCounter[i]=0;
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
    delete[] buckets;
    
}

/*
 * Implementation notes: size, isEmpty
 * -----------------------------------
 * These methods can each be implemented in a single line
 * because the size is stored in the nEntries instance variable.
 */
template <typename ValueType>
int Map<ValueType>::size() {
    return counter.nEntries;
}
template <typename ValueType>
bool Map<ValueType>::isEmpty() {
    return counter.nEntries;
}
/*
 * Implementation notes: clear
 * ---------------------------
 * This method calls the recursive deleteChain method for each
 * bucket chain.
 */
template <typename ValueType>
void Map<ValueType>::clear() {
    for (int i = 0; i < counter.nBuckets; i++) {
        deleteChain(buckets[i]);
    }
    counter.nEntries = 0;
    
    for (int i = 0; i < counter.nBuckets; i++) {  //reinitialize the buckets array
        buckets[i] = NULL;
        cellCounter[i]=0;
    }
    
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
    int index = hash(key) % counter.nBuckets;
    cellT *cell = findCell(buckets[index], key);
    if (cell == NULL) {
        cell = new cellT;
        cell->key = key;
        cell->link = buckets[index]; //new cell points to the old 1st bucket, new 1st bucket is the new cell
        buckets[index] = cell;  //the old 1st bucket retains its pointer
        counter.nEntries++;  //increase the total number of cells
        cellCounter[index]++;  //increase the number of cells in that bucket
    }
    cell->value = value;
    
}
/*
 * Implementation notes: get, containsKey
 * --------------------------------------
 * These methods uses findCell to find the key in the map, which is
 * where all the real work happens.
 */
template <typename ValueType>
ValueType Map<ValueType>::get(string key) {
    cellT *cell = findCell(buckets[hash(key) % counter.nBuckets], key);
    if (cell == NULL) {
        error("Attempt to get value for key that is not in the map."); }
    return cell->value;
}
template <typename ValueType>
bool Map<ValueType>::containsKey(string key) {
    return findCell(buckets[hash(key) % counter.nBuckets], key) != NULL;
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
    int index = hash(key) % counter.nBuckets;
    cellT *prev = NULL;
    cellT *cp = buckets[index];
    while (cp != NULL && cp->key != key) {
        prev = cp;
        cp = cp->link;
    }
    if (cp != NULL) {
        if (prev == NULL) {
            buckets[index] = cp->link;
        } else {
            prev->link = cp->link;
        }
        delete cp;
        counter.nEntries--;
    }
    
    cellCounter[index]--; //decrement the index
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
typename Map<ValueType>::cellT *Map<ValueType>
::findCell(cellT *chain, string key) {
    for (cellT *cp = chain; cp != NULL; cp = cp->link) {
        if (cp->key == key) return cp;
    }
    return NULL;
}


/*
 * Private method: deleteChain
 * ---------------------------
 * This method deletes all of the cells in a bucket chain.
 * It operates recursively by freeing the rest of the chain
 * and the freeing the current cell.
 */
template <typename ValueType>
void Map<ValueType>::deleteChain(cellT *chain) {
    if (chain != NULL) {
        deleteChain(chain->link);
        delete chain;
    }
}




#endif /* defined(__Ch_12_Coursework__q6hash__) */
