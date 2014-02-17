//
//  gridarray.h
//  Ch.11_Coursework
//
//  Created by Jesse Furmanek on 2/17/14.
//
//

#ifndef __Ch_11_Coursework__gridarray__
#define __Ch_11_Coursework__gridarray__

#include <iostream>
#include "error.h"


/*
 * Class: Grid
 * ------------
 * The class Grid stores an indexed, two-dimensional collection.
 * It is supplied as a class template.  The client specializes
 * the grid to hold values of a specific type.  Because the class
 * is defined with private data members, clients have no access
 * to the underlying data members and can only manipulate a grid
 * object through its public methods.
 */
template <typename ElemType>
class Grid {
public:
 
    /*
     * Constructor: Grid
     * Usage: Grid<bool> grid;
     * -----------------------
     * Initializes a new empty grid with 0 rows and 0 cols.  Clients
     * that use this form of the constructor will need to call resize
     * to set the dimensions of the grid.
     */
    Grid();
    /*
     * Constructor: Grid
     * Usage: Grid<bool> grid(10, 20);
     * -------------------------------
     * Initializes a new grid with the specified number of rows and
     * columns.  Each element in the grid is assigned a value equal
     * to the default for that element type (e.g., for strings it would
     * be empty string, for ints, the default value is uninitialized).
     * Raises an error if numRows or numCols is negative.
     */
    Grid(int numRows, int numCols);
    /*
     * Destructor: ~Grid
     * Usage: (usually implicit)
     * -------------------------
     * Frees the storage associated with this grid.
     */
    ~Grid();
    /*
     * Methods: numRows, numCols
     * Usage: nRows = grid.numRows();
     * ------------------------------
     * These methods returns the number of rows or columns in this grid.
     */
    int numRows();
    int numCols();
    /*
     * Method: resize
     * Usage: grid.resize(5, 10);
     * --------------------------
     * Sets the number of rows and columns in this grid to the specified
     * values. Any previous grid contents are discarded.  Each element
     * in the resized grid has value equal to the default for that
     * element type. Raises an error if numRows or numCols is negative.
     */
    void resize(int numRows, int numCols);
    /*
     * Method: getAt
     * Usage: val = grid.getAt(3, 10);
     * -------------------------------
     * Returns the element at specified row/col location in this grid.
     * Locations are indexed starting from 0.  Raises an error if row
     * is outside the range [0, numRows()-1] or if col is outside
     * the range [0, numCols()-1].
     */
    ElemType getAt(int row, int col);
    /*
     * Method: setAt
     * Usage: grid.setAt(3, 10, value);
     * --------------------------------
     * Replaces the element at the specified row/col location in
     * this grid with a new value.  The previous value at that
     * location is overwritten with the new value.  Raises an error
     * if row is outside the range [0, numRows()-1] or if col is
     * outside the range [0, numCols()-1].
     */
    void setAt(int row, int col, ElemType data);
    /*
     * Method: inBounds
     * Usage: if (grid.inBounds(row, col);
     * -----------------------------------
     * Returns true if the specified row and column position are inside
     * the bounds of the grid.
     */
    bool inBounds(int row, int col);
   
    private:
    
    #include "gridarrpriv.h"
    
};

template <typename ElemType>
Grid<ElemType>::Grid(){
    elements = new ElemType;
    nRows = 0;
    nColumns = 0;
}

template<typename ElemType>
Grid<ElemType>::Grid(int rows, int columns){
    nRows = rows;
    nColumns = columns;
    elements = new ElemType[nRows*nColumns];
}

template<typename ElemType>
Grid<ElemType>::~Grid(){
    delete [] elements;
}

template<typename ElemType>
inline int Grid<ElemType>::numRows(){
    return nRows;
}

template<typename ElemType>
inline int Grid<ElemType>::numCols(){
    return nColumns;
}

template<typename ElemType>
void Grid<ElemType>::resize(int rows, int columns){
    ElemType *temp = elements; //set temp array equal to current array
    elements = new ElemType[rows*columns];
    nRows = rows;
    nColumns= columns;
    delete [] temp;
    
}

template<typename ElemType>
ElemType Grid<ElemType>::getAt(int rows, int columns){
    
    int index=rows*nColumns+columns;
    
    if(inBounds(rows, columns)){
        return elements[index];
    }
    
    
    error("outside of range");
    return 0;
    
    
}


template<typename ElemType>
void Grid<ElemType>::setAt(int rows, int columns, ElemType data){
    
    if(!inBounds(rows, columns)){
        error("row/column outside bounds of grid");
    }
    
    int index = rows*nColumns+columns;
    
    elements[index]=data;
    
}


template<typename ElemType>

inline bool Grid<ElemType>::inBounds(int rows, int columns){
   
    if(rows>0 && columns>0){
        if(rows<nRows){
            return true;
        }else if(columns<nColumns){
            return true;
        }else{
        
        return false;
        }
    }else{
        return false;
    }
}

#endif /* defined(__Ch_11_Coursework__gridarray__) */
