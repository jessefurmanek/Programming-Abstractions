//
//  HanoiUsingStack.cpp
//  CourseWork
//
//  Created by Jesse Furmanek on 8/16/13.
//
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "strlib.h"
#include "vector.h"
#include "random.h"
#include "stack.h"
#include "tokenscanner.h"
#include "grid.h"

struct HannoiTask{  //create Task struct
    int n;
    char start;
    char finish;
    char temp;
};



void StackHanoi(int d){
    Stack<HannoiTask> Tower; //create Starting  Stack
    
    HannoiTask Start;  //Initialize starting task
    Start.n = d;
    Start.start = 'A';
    Start.finish = 'B';
    Start.temp = 'C';
    
    Tower.push(Start);  //push start task to stack
    
    
    int count=0;
    
    while (!Tower.isEmpty()){  //keep going while tower is not empty
        
        if (Tower.peek().n==1){ //base case
            
            cout<<Tower.peek().start<<" ->"<<Tower.peek().finish<<endl;  //if there's only one disc, move st->fin
            count++;
            Tower.pop();  //remove that task
            
            if(!Tower.isEmpty()){  //if the above is not the last task
                cout<<Tower.peek().start<<" ->"<<Tower.peek().finish<<endl;  //move the bottom (biggest) piece to from st->fin
                count++;
                
                HannoiTask newTask;    //create a new task moving a disc from the temp to the finish peg, creating a 'recurision'
                newTask.n= Tower.peek().n-1;
                newTask.start= Tower.peek().temp;
                newTask.finish= Tower.peek().finish;
                newTask.temp= Tower.peek().start;
                
                Tower.pop();  //pop the st->finish task off the stack
                
                Tower.push(newTask);  //the third task is added to the stack, replacing the second part
            }
            
            
        }else{  //if not at the base case, add another task to the stack (moving the disc from start to temp)
            
            HannoiTask newTask;
            newTask.n= Tower.peek().n-1;
            newTask.start= Tower.peek().start;
            newTask.finish= Tower.peek().temp;
            newTask.temp= Tower.peek().finish;
            
            Tower.push(newTask);
        }
        
        
    }
    
    cout<<count<<endl;  //display the number of moves
    return;
}


