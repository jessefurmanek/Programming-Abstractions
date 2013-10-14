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
bool CheckedForSolvedCube(Vector<Vector<char> > Cubes);
bool RunCubeSolve(Vector<Vector<char> > & Cubes, int CubeNum);
void RotateCube(Vector<Vector<char> > & Cubes, int CubeNum, int SideNum);
void UnRotateCube(Vector<Vector<char> > & Cubes, int CubeNum);





void RunInsanityCubes(){
    
    Vector <Vector <char> > InsanityCubes;  //create vector of vectors representing cubes
    Vector <Vector <char> > Blank;
    
    Vector <char> Cube1;  //Create Cubes
    Cube1.add('Y');
    Cube1.add('Y');
    Cube1.add('B');
    Cube1.add('G');
    Cube1.add('R');
    Cube1.add('R');
    
    Vector <char> Cube2;
    Cube2.add('G');
    Cube2.add('Y');
    Cube2.add('B');
    Cube2.add('B');
    Cube2.add('R');
    Cube2.add('Y');
    
    Vector <char> Cube3;
    Cube3.add('R');
    Cube3.add('B');
    Cube3.add('R');
    Cube3.add('Y');
    Cube3.add('G');
    Cube3.add('G');
    
    Vector <char> Cube4;
    
    Cube4.add('B');
    Cube4.add('G');
    Cube4.add('G');
    Cube4.add('R');
    Cube4.add('Y');
    Cube4.add('G');
    
   
    
    InsanityCubes.add(Cube1);
    InsanityCubes.add(Cube2);
    InsanityCubes.add(Cube3);
    InsanityCubes.add(Cube4);
    
   
    NonRepeatPermOfCubes(Blank,InsanityCubes);
}

bool NonRepeatPermOfCubes(Vector< Vector<char> > Blank, Vector< Vector<char> > Cubes){  //returns every nonrepeating combination order of the cubes
    if(Cubes.size()==0){
        cout<<Blank<<endl;
        return RunCubeSolve(Blank,0);
       
    }else{
        for(int x=0; x<Cubes.size(); x++){
            Vector< Vector<char> > newBlank=Blank;  //create temporary vectors to manipulate, leaving the original vectors intact
            Vector< Vector<char> > newCubes = Cubes;
            
            newBlank.add(Cubes[x]);
            newCubes.remove(x);
            
            if(NonRepeatPermOfCubes(newBlank, newCubes)) return true; //recurse
            
        }
    }
    return false;
}

bool RunCubeSolve(Vector<Vector<char> > & Cubes, int CubeNum){
    if(CubeNum==Cubes.size()){
        if(CheckedForSolvedCube(Cubes)){
            cout<<"Solved!"<<endl;
            cout<<Cubes<<endl;
            return true;
        }else{
            
            return false;
        }
    }
    
       
    for(int x=0; x<Cubes[0].size(); x++){
        for(int y = 0; y<4; y++){
            int NewCubeNum = CubeNum+1;
            if(RunCubeSolve(Cubes, NewCubeNum)) return true;

            RotateCube(Cubes, CubeNum, x);
        }
    }
    
    return false;
}


bool CheckedForSolvedCube(Vector<Vector<char> > Cubes){
    
    for(int x = 0; x<Cubes[0].size(); x++){  //for each side of a cube in the vector
        for(int y= 0; y<Cubes.size(); y++){  //and for each cube
            bool NeedToCheck=true;
            bool NeedToCheckEnds = false;
                for(int z=1; z<Cubes.size(); z++){
                   int tempy = (y+z)%(Cubes.size());
                    
                    if(x==1 && tempy==0) NeedToCheck=false;  //when the cube side doesn't face the outside
                    if(x==1 && tempy==1) NeedToCheck=false;
                    if(x==5 && tempy==1) NeedToCheck=false;
                    if(x==1 && tempy==2) NeedToCheck=false;
                    if(x==5 && tempy==2) NeedToCheck=false;
                    if(x==5 && tempy==3) NeedToCheckEnds=true;
                    
                    if(x==4) NeedToCheck=false;  //check the bottom
                    
                    if(NeedToCheck){
                        if (NeedToCheckEnds){
                            if(Cubes[y][x]==Cubes[0][1]) return false;  //compares the end of the last cube vs. the front of the first cube
                            
                        }else{
                            if(Cubes[y][x]==Cubes[tempy][x]){  //check each side against each of the other sides of the cube
                            return false;  //if a side of one of the blocks matches another outside facing side, return
                            }
                        }
                    }
                }
        }
    }
    
    
    
    return true;
}

void RotateCube(Vector<Vector<char> > & Cubes, int CubeNum, int SideNum){  //this needs to change
    Vector<char> TempCubes = Cubes[CubeNum];

    switch(SideNum){
        case 0:
            TempCubes[1]=Cubes[CubeNum][4];
            TempCubes[4]=Cubes[CubeNum][5];
            TempCubes[5]=Cubes[CubeNum][2];
            TempCubes[2]=Cubes[CubeNum][1];
            break;
        case 1:
            TempCubes[2]=Cubes[CubeNum][3];
            TempCubes[3]=Cubes[CubeNum][4];
            TempCubes[4]=Cubes[CubeNum][0];
            TempCubes[0]=Cubes[CubeNum][2];
            break;
        case 2:
            TempCubes[0]=Cubes[CubeNum][5];
            TempCubes[5]=Cubes[CubeNum][3];
            TempCubes[3]=Cubes[CubeNum][1];
            TempCubes[1]=Cubes[CubeNum][0];
            break;
        case 3:
            TempCubes[2]=Cubes[CubeNum][5];
            TempCubes[5]=Cubes[CubeNum][4];
            TempCubes[4]=Cubes[CubeNum][1];
            TempCubes[1]=Cubes[CubeNum][2];
            break;
           
        case 4:
            TempCubes[0]=Cubes[CubeNum][1];
            TempCubes[1]=Cubes[CubeNum][3];
            TempCubes[3]=Cubes[CubeNum][5];
            TempCubes[5]=Cubes[CubeNum][0];
            break;
        case 5:
            TempCubes[3]=Cubes[CubeNum][2];
            TempCubes[2]=Cubes[CubeNum][0];
            TempCubes[0]=Cubes[CubeNum][4];
            TempCubes[4]=Cubes[CubeNum][3];
            break;
        default:
            cout<<"you've defaulted!"<<endl;
        
    }
    
    Cubes[CubeNum]=TempCubes;  //set cube = to new rotated cube
    
}




