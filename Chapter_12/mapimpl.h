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
template <typename KeyType, typename ValueType>
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
    void put(KeyType key, ValueType value);
    /*
     * Method: get
     * Usage: value = map.get(key);
     * ----------------------------
     * If key is found in this map, this method returns the associated
     * value.  If key is not found, the get mathod raises an error.
     * Clients can use the containsKey method to verify the presence
     * of a key in the map before attempting to get its value.
     */
    ValueType get(KeyType key);
    /*
     * Method: containsKey
     * Usage: if (map.containsKey(key))...
     * -----------------------------------
     * Returns true if there is an entry for key in this map,
     * false otherwise.
     */
    bool containsKey(KeyType key);
    /*
     * Method: remove
     * Usage: map.remove(key);
     * -----------------------
     * This method removes any entry for key from this map.
     * If there is no entry for the key, the map is unchanged.
     */
    void remove(KeyType key);
    
    void mapAll(void (*fn)(KeyType, ValueType));
    
 
private:
#include "mapimplpriv.h"
    
};

template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::Map() {
    capacity = INITIAL_CAPACITY;
    array = new keyValuePairT[capacity];
    count = 0;
}
template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::~Map() {
    delete[] array;
}
template <typename KeyType, typename ValueType>
int Map<KeyType, ValueType>::size() {
    return count;
}
template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::isEmpty() {
    return (count == 0);
}
template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::clear() {
    count = 0; }
/*
 * Implementation notes: put
 * -------------------------
 * The put method begins by calling findKey to searches for an
 * existing key.  If that key is found, put stores the value in the
 * corresponding key/value pair.  If not, put adds a new key/value
 * pair to the array, expanding the capacity if necessary.
 */
template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::put(KeyType key, ValueType value) {
    int index = findKey(key);
    bool found = false;
    if (index == -1) {
        if (count == capacity) expandCapacity();
        //iterate through array to find where the new key/value belongs
        for(int x=0; x<count && found ==false; x++){
            if(key>array[x].key){
                //keep going
                
            }else{//if the new value is less than the next value
                //shift to right
                for(int y=count; y>x; y--){
                    array[y].key=array[y-1].key; //shift elements of the array to the right
                    array[y].value=array[y-1].value;
                }
                found = true;  //flag that a spot for the key was found
                index = x;
                count++;
            }
            
        }
        
        if(found==false){
            index=count;
            count++;
        }
        
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
template <typename KeyType, typename ValueType>
ValueType Map<KeyType, ValueType>::get(KeyType key) {
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
template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::containsKey(KeyType key) {
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
template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::remove(KeyType key) {
    int index = findKey(key);
    
    if (index != -1) {
        //iterate through array to find where the new key/value belongs
       
        for(int x=count; x<count-1; x++){
                array[x].key=array[x+1].key; //shift elements of the array to the left
                array[x].value=array[x+1].value;
        }
        
        count--;  //decrment the count
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
template <typename KeyType, typename ValueType>
int Map<KeyType, ValueType>::findKey(KeyType key) {

    int findIndex = findKeyImpl(key, 0, size()-1);
    return findIndex;
    
}

template <typename KeyType, typename ValueType>
int Map<KeyType, ValueType>::findKeyImpl(KeyType key, int leftIndex, int rightIndex){
    if (size()<=0){  //if the map is empty
        return -1;
    }
    
    int midPoint = (rightIndex+leftIndex)/2;
    
    if(rightIndex<=leftIndex){
        if(key==array[leftIndex].key){
            return leftIndex;
        }
        
        return -1;
    }
    
    if(key==array[midPoint].key){  //run binary search
        return midPoint;
    }else if(key>array[midPoint].key){
        return findKeyImpl(key, midPoint+1, rightIndex);
    }else{
        return findKeyImpl(key, 0, midPoint-1);
    }
    
}

/*
 * Implementation notes: expandCapacity
 * ------------------------------------
 * This private method doubles the capacity of the array whenever
 * it runs out of space.  To do so, it must allocate a new array,
 * copy all the elements from the old array to the new one, and
 * free the old storage.
 */
template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::expandCapacity() {
    int count = size();
    capacity *= 2;
    keyValuePairT *oldArray = array;
    array = new keyValuePairT[capacity];
    for (int i = 0; i < count; i++) {
        array[i] = oldArray[i];
    }
    delete[] oldArray;
}

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::mapAll(void (*fn)(KeyType, ValueType)){
    for(int x = 0; x<INITIAL_CAPACITY; x++){
        fn(array[x].key, array[x].value);
    }
};



#endif /* defined(__Ch_12_Coursework__mapimpl__) */
