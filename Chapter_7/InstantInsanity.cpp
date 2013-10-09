//
//  Instant Insanity.cpp
//  Ch.7_Coursework
//
//  Created by Jesse Furmanek on 10/8/13.
//
//

#include "InstantInsanity.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "vector.h"

void RunInsanityCubes();

bool NonRepeatPermOfCubes(Vector< Vector<char> > Blank,Vector< Vector<char> > Cubes);  //cycles through all permutations of cube order e.g. c1c2c3c4, c1c3c2c4 etc.
bool RunCubeSolve(Vector<Vector<char> >);

void RunInsanityCubes(){
    
    Vector <Vector <char> > InsanityCubes;  //create vector of vectors representing cubes
    Vector <Vector <char> > Blank;
    
    Vector <char> Cube1;  //Create Cubes
    Cube1.add('W');
    Cube1.add('B');
    Cube1.add('G');
    Cube1.add('B');
    Cube1.add('G');
    Cube1.add('R');
    
    Vector <char> Cube2;
    Cube2.add('W');
    Cube2.add('W');
    Cube2.add('R');
    Cube2.add('G');
    Cube2.add('G');
    Cube2.add('B');
    
    Vector <char> Cube3;
    Cube3.add('R');
    Cube3.add('R');
    Cube3.add('W');
    Cube3.add('W');
    Cube3.add('G');
    Cube3.add('B');
    
    Vector <char> Cube4;
    
    Cube4.add('G');
    Cube4.add('R');
    Cube4.add('B');
    Cube4.add('R');
    Cube4.add('W');
    Cube4.add('B');
    
    InsanityCubes.add(Cube1);
    InsanityCubes.add(Cube2);
    InsanityCubes.add(Cube3);
    InsanityCubes.add(Cube4);
    
    
    NonRepeatPermOfCubes(Blank,InsanityCubes);
}

bool NonRepeatPermOfCubes(Vector< Vector<char> > Blank,Vector< Vector<char> > Cubes){
    if(Cubes.size()==0){
        cout<<Blank<<endl;
        //return RunCubeSolve(Blank);
    }else{
        for(int x=0; x<Cubes.size(); x++){
            Vector< Vector<char> > newBlank=Blank;  //create temporary vectors to manipulate, leaving the original vectors intact
            Vector< Vector<char> > newCubes = Cubes;
            
            newBlank.add(Cubes[x]);
            newCubes.remove(0);
            
            NonRepeatPermOfCubes(newBlank, newCubes); //recurse
            
        }
    }
    return false;
}

bool RunCubeSolve(Vector<Vector<char> > Cubes){
    
    
    
    return false;
}

bool CheckedForSolvedCube(Vector<Vector<char> > Cubes){
    
    
    return false;
}



