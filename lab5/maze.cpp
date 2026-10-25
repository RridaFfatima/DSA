#include<iostream>
#include<string>
using namespace std;
struct Pair{
    int i;
    int j;
};
bool solve_maze(char maze[6][6], Pair s, Pair d, int row, int col){
if(s.i==d.i && s.j==d.j){
    return true;
}

maze[s.i][s.j]='a';
 if(s.i-1>=0 && (maze[s.i-1][s.j] ==' ' || maze[s.i-1][s.j]=='T') ){
Pair next;
next.i=s.i-1;
next.j=s.j;
if(solve_maze(maze,next,d,row,col)){
cout<<"("<<next.i<<","<<next.j<<")"<<endl;
return true;
}
 }

 if(s.i+1<row && (maze[s.i+1][s.j] ==' ' || maze[s.i+1][s.j]=='T') ){
Pair next;
next.i=s.i+1;
next.j=s.j;
if(solve_maze(maze,next,d,row,col)){
cout<<"("<<next.i<<","<<next.j<<")"<<endl;
return true;
}
 }

 if(s.j-1>=0 && (maze[s.i][s.j-1] ==' ' ||  maze[s.i][s.j-1]=='T')){
Pair next;
next.i=s.i;
next.j=s.j-1;
if(solve_maze(maze,next,d,row,col)){
cout<<"("<<next.i<<","<<next.j<<")"<<endl;
return true;
}
 }

 if(s.j+1<col && (maze[s.i][s.j+1] ==' ' || maze[s.i][s.j+1]=='T') ){
Pair next;
next.i=s.i;
next.j=s.j+1;
if(solve_maze(maze,next,d,row,col)){
cout<<"("<<next.i<<","<<next.j<<")"<<endl;
return true;
}
}

return false;
 }

int main()
{
// -------------------------
// Maze 1
// -------------------------
char maze1[6][6] = {
{' ', '*', ' ', '*', ' ', ' '},
{' ', '*', ' ', '*', ' ', ' '},
{'P', ' ', ' ', ' ', '*', ' '},
{'*', ' ', '*', '*', '*', ' '},
{' ', ' ', ' ', ' ', '*', 'T'},
{'*', ' ', ' ', ' ', ' ', ' '}
};
Pair start = {2, 0};
Pair dest = {4, 5};
cout<<"Maze 1"<<endl;
if (solve_maze(maze1, start, dest, 6, 6))
{
cout << " Solved" << endl;
}
else
{
cout << "UnSolved" << endl;
}

// -------------------------
// Maze 2
// -------------------------
char maze2[6][6] = {
{' ', '*', ' ', '*', ' ', ' '},
{' ', '*', ' ', '*', ' ', ' '},
{'P', ' ', ' ', ' ', '*', ' '},
{'*', '*', '*', '*', '*', ' '},
{' ', ' ', ' ', ' ', '*', 'T'},
{'*', ' ', ' ', ' ', ' ', ' '}
};
cout<<"Maze 2"<<endl;
if (solve_maze(maze2, start, dest, 6, 6))
{
cout << " Solved" << endl;
}
else
{
cout << "UnSolved" << endl;
}
return 0;
}
