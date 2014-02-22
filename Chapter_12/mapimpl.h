//
//  mapimpl.h
//  Ch.12_Coursework
//
//  Created by Jesse Furmanek on 2/21/14.
//
//

#ifndef __Ch_12_Coursework__mapimpl__
#define __Ch_12_Coursework__mapimpl__

#include <iostream>
#include "error.h"

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
private:
#include "mapimplpriv.h"
    
};

template <typename ValueType>
Map<ValueType>::Map() {
    capacity = INITIAL_CAPACITY;
    array = new keyValuePairT[capacity];
    count = 0;
}
template <typename ValueType>
Map<ValueType>::~Map() {
    delete[] array;
}
template <typename ValueType>
int Map<ValueType>::size() {
    return count;
}
template <typename ValueType>
bool Map<ValueType>::isEmpty() {
    return (count == 0);
}
template <typename ValueType>
void Map<ValueType>::clear() {
    count = 0; }
/*
 * Implementation notes: put
 * -------------------------
 * The put method begins by calling findKey to searches for an
 * existing key.  If that key is found, put stores the value in the
 * corresponding key/value pair.  If not, put adds a new key/value
 * pair to the array, expanding the capacity if necessary.
 */
template <typename ValueType>
void Map<ValueType>::put(string key, ValueType value) {
    int index = findKey(key);
    if (index == -1) {
        if (count == capacity) expandCapacity();
        index = count++;
        array[index].key = key;
    }
    array[index].value = value;
}

/*
 * Implementation notes: get
 * -------------------------
 * The get method calls findKey to search for the specified key.
 * If the key is found, get returns the value from that key/value
 * pair.  If not, get reports an error.
 */
template <typename ValueType>
ValueType Map<ValueType>::get(string key) {
    int index = findKey(key);
    if (index == -1) {
        error("Attempt to get value for key that is not in the map."); }
    return array[index].value;
}
/*
 * Implementation notes: containsKey
 * ---------------------------------
 * This method simply checks the result of the private findKey
 * method, which does all the work.
 */
template <typename ValueType>
bool Map<ValueType>::containsKey(string key) {
    return (findKey(key) != -1);
}
/*
 * Implementation notes: remove
 * ----------------------------
 * The code for remove saves a little time by copying the
 * key/value pair from the last entry into this cell.  Note
 * that there is no reason to check whether the deleted item
 * is the last element.  If it is, the copy is harmless, and
 * that key/value pair will no longer be part of the active
 * region of the array.  Note also that count can't be zero
 * if findKey has found a match.
 */
template <typename ValueType>
void Map<ValueType>::remove(string key) {
    int index = findKey(key);
    if (index != -1) {
        array[index] = array[--count];
    }
}

/* Private methods */
/*
 * Private method: findKey
 * Usage: int index = findKey(key);
 * --------------------------------
 * This method searches through all the keys in the map searching
 * for a cell that contains the specified key.  If it finds one,
 * it returns the index of that element in the array.  If no
 * such key exists, findKey returns -1.
 */
template <typename ValueType>
int Map<ValueType>::findKey(string key) {
    for (int i = 0; i < count; i++) {
        if (array[i].key == key) return i;
    }
    return -1; }
/*
 * Implementation notes: expandCapacity
 * ------------------------------------
 * This private method doubles the capacity of the array whenever
 * it runs out of space.  To do so, it must allocate a new array,
 * copy all the elements from the old array to the new one, and
 * free the old storage.
 */
template <typename ValueType>
void Map<ValueType>::expandCapacity() {
    int count = size();
    capacity *= 2;
    keyValuePairT *oldArray = array;
    array = new keyValuePairT[capacity];
    for (int i = 0; i < count; i++) {
        array[i] = oldArray[i];
    }
    delete[] oldArray;
}


#endif /* defined(__Ch_12_Coursework__mapimpl__) */
