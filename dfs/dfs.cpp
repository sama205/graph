#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
#define MAX 7
#define max 6
using namespace std; 
bool nextisSafe( int row, int col, int row1, int col1, int row2, int col2, int row3, int col3, int row4, int col4, int m[MAX][max], int n, bool visited[MAX][max], int z, int a ) 
{ 
    int X=0;
    if (row1 == -1 || row1 == 7 || col1 == -1 ||  
                  col1 == 6 || visited[row1][col1]  
                           || m[row1][col1] == 0)
    {
        X+=1;
    }  
    if (row2 == -1 || row2 == 7 || col2 == -1 ||  
                  col2 == 6 || visited[row2][col2]  
                           || m[row2][col2] == 0)
    {
        X+=1;
    }
    if (row3 == -1 || row3 == 7 || col3 == -1 ||  
                  col3 == 6 || visited[row3][col3]  
                           || m[row3][col3] == 0)
    {
        X+=1;
    } 
    if (row4 == -1 || row4 == 7 || col4 == -1 ||  
                  col4 == 6 || visited[row4][col4]  
                           || m[row4][col4] == 0)
    {
        X+=1;
    }  
    if(row==z-1 && col==a-1){
        return true;
    }
    if(X==4)
    {
        return false;
    }
    return true; 
}
bool isSafe(int row, int col, int m[MAX][max], int n, bool visited[MAX][max]) 
{ 
    if (row == -1 || row == 7 || col == -1 ||  
                  col == 6 || visited[row][col]  
                           || m[row][col] == 0)
    {
        return false; 
    }  
    return true; 
} 
void printPathUtil(int row, int col, int m[MAX][max], int n, string& path, bool visited[MAX][max], int z, int a) 
{  
    if (row == -1 || row == 7 || col == -1  
               || col == 6 || visited[row][col]  
                           || m[row][col] == 0) 
        return;  
    if (row == z-1 && col ==a-1) {  
        return; 
    }  
    visited[row][col] = true; 
    if (isSafe(row - 1, col, m, n, visited) && nextisSafe(row-1,col,row-2,col,row,col,row-1,col-1,row-1,col+1,m,n,visited, z, a)) 
    { 
        path.push_back('U'); 
        printPathUtil(row - 1, col, m, n, 
               path, visited, z, a);  
    } 
    else if (isSafe(row + 1, col, m, n, visited) && nextisSafe(row+1,col, row,col,row+2,col,row+1,col-1,row+1,col+1,m,n,visited, z, a)) 
    { 
        path.push_back('D'); 
        printPathUtil(row + 1, col, m, n, 
                 path,visited, z, a); 
    } 

    else if (isSafe(row, col - 1, m, n, visited) && nextisSafe(row, col-1, row-1,col-1,row+1,col-1,row,col-2,row,col,m,n,visited, z, a)) 
    { 
        path.push_back('L'); 
        printPathUtil(row, col - 1, m, n, 
                   path, visited, z, a);  
    } 
    else if (isSafe(row, col + 1, m, n, visited) && nextisSafe(row, col+1, row-1,col+1,row+1,col+1,row,col,row,col+2,m,n,visited, z, a))  
    { 
        path.push_back('R'); 
        printPathUtil(row, col + 1, m, n, 
                   path, visited, z, a);  
    } 
   
    visited[row][col] = false; 
}   
void printPath( int m[MAX][max], int n,int x,int y, int z, int a) 
{  
    string path; 
    bool visited[MAX][max]; 
    memset(visited, false, sizeof(visited));   
    printPathUtil(x-1,y-1, m, n, path,  
                       visited,z,a);
    cout<<path<<endl;
} 
int main() 
{ 
    int x,y,z,a;
    int m [MAX][max]{
        { 1, 1, 1, 1, 0, 1 }, 
        { 1, 0, 1, 1, 1, 1 }, 
        { 1, 1, 0, 0, 0, 0 }, 
        { 1, 0, 0, 1, 1, 1 }, 
        { 1, 1, 1, 1, 0, 1 },
        { 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1, 1 } }; 
    cout<<"HEIGHT"<<","<<"WIDTH"<<"of first one"<<endl;
    cin>>x>>y;
    cout<<"HEIGHT"<<","<<"WIDTH"<<"of finish one"<<endl;
    cin>>z>>a;
    int n = sizeof(m) / sizeof(m[0]);
    printPath(m, n,x,y,z,a); 
  
    return 0; 
} 
