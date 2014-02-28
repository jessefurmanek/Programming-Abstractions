//
//  maphash.h
//  Ch.12_Coursework
//
//  Created by Jesse Furmanek on 2/25/14.
//
//

#ifndef __Ch_12_Coursework__maphash__
#define __Ch_12_Coursework__maphash__


#include <iostream>
#include "error.h"
#include <cmath>

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
#include "maphashpriv.h"
    
};


/*
 * Implementation notes: Map constructor
 * -------------------------------------
 * The constructor allocates the array of buckets and initializes
 * each bucket to the empty list.
 */
template <typename ValueType>
Map<ValueType>::Map() {
    nBuckets = INITIAL_SIZE;
    buckets = new cellT *[nBuckets];
    for (int i = 0; i < nBuckets; i++) {
        buckets[i] = NULL;
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
    clear();
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
    return nEntries;
}
template <typename ValueType>
bool Map<ValueType>::isEmpty() {
    return nEntries;
}
/*
 * Implementation notes: clear
 * ---------------------------
 * This method calls the recursive deleteChain method for each
 * bucket chain.
 */
template <typename ValueType>
void Map<ValueType>::clear() {
    for (int i = 0; i < nBuckets; i++) {
        deleteChain(buckets[i]);
    }
    nEntries = 0;
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
    int index = hash(key) % nBuckets;
    cellT *cell = findCell(buckets[index], key);
    if (cell == NULL) {
        cell = new cellT;
        cell->key = key;
        cell->link = buckets[index];
        buckets[index] = cell;
        nEntries++;
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
    cellT *cell = findCell(buckets[hash(key) % nBuckets], key);
    if (cell == NULL) {
        error("Attempt to get value for key that is not in the map."); }
    return cell->value;
}
template <typename ValueType>
bool Map<ValueType>::containsKey(string key) {
    return findCell(buckets[hash(key) % nBuckets], key) != NULL;
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
    int index = hash(key) % nBuckets;
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
        nEntries--;
    }
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


template <typename ValueType>
void Map<ValueType>::DisplayHashTableStatistics(){
    
    double mean = 0;
    int meanCount=0;
    int numBuckets =0;
    double meanMinCur=0;
    double stdDev = 0;
    
    for (int i = 0; i < nBuckets; i++) {  //for each bucket
        for(cellT *cp = buckets[i]; cp!=NULL; cp=cp->link){  //and for each chain in the bucket
            meanCount++;
        }
        
        numBuckets++;
    }
    mean = meanCount/numBuckets;
    
    for (int i = 0; i < nBuckets; i++) {  //for each bucket
        meanCount=0; //reset to zero
        
        for(cellT *cp = buckets[i]; cp!=NULL; cp=cp->link){  //and for each chain in the bucket
            meanCount++;  //add up the number of links in the chain
        }
        
        meanMinCur+=pow(mean-meanCount,2);
    }
    
    stdDev = sqrt(meanMinCur/numBuckets);
    
    cout<<"Mean: "<<mean<<endl;
    cout<<"Stand. Dev. "<<stdDev<<endl;
    
}

template <typename ValueType>  //used for creating a temporary value for a key
void Map<ValueType>::insert(string key, ValueType value){
    //insert is going to act just like put
    int index = hash(key) % nBuckets;
    cellT *cell = findCell(buckets[index], key);
    if (cell == NULL) {
            //do nothing
    }else{
        
        cellT * cellTemp = new cellT; //create a new cell that is a copy of the current cell
       
        cellTemp->key = key;  //assign the choosen key to the tempcell
        cellTemp->value = cell->value; //assign the chosen value to the temp cell
        
        cellTemp->link = cell->link;  //link the tempCell to the cell with the same key (i.e. the one in front of it)
        cell->link = cellTemp;  //link the cell behind the tempCell to the tempCell
        cell->value = value;
        
        nEntries++;
    }
    
}


#endif /* defined(__Ch_12_Coursework__maphash__) */
