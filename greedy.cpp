 #include <iostream>
#include <bits/stdc++.h> 
#include <vector>
#define MAX 7
#define max 6
using namespace std; 
void maximum(int D, int U, int L, int R,int m[MAX][max], int n, string& path, bool visited[MAX][max],int z,int a, int row, int col);
bool closerheight(int row,  int row1, int m[MAX][max], int n,int z)
{
    int Z,H;
    Z=row-z;
    H=row1-z;
    if (H<0){
        H=H*-1;
    }
    if (Z<0){
        Z=Z*-1;
    }
    if(H<Z){
        return true;
    }
    return false;
}
bool closerweight(int col, int col1, int m[MAX][max], int n, int a )
{
    int X,Y;
    X=col-a;
    Y=col1-a;
    if (Y<0){
        Y=Y*-1;
    }
    if (X<0){
        X=X*-1;
    }
    if(Y<X)
    {
        return true;
    }
    return false;
}
bool nextisSafe(int row, int col, int m[MAX][max], int n, bool visited[MAX][max]) 
{ 
    if (row == -1 || row == 7 || col == -1 ||  
                  col == 6 || visited[row][col]  
                           || m[row][col] == 0) 
        return false; 
  
    return true; 
} 
bool isSafe(int row, int col, int m[MAX][max], int n, bool visited[MAX][max]) 
{ 
    if (row == -1 || row == 7 || col == -1 ||  
                  col == 6 || visited[row][col]  
                           || m[row][col] == 0) 
        return false; 
  
    return true; 
} 

void printPathUtil(int row, int col, int m[MAX][max], int n, string& path, bool visited[MAX][max], int z, int a) 
{  
    if (row == -1 || row == 7 || col == -1  
               || col == 6 || visited[row][col]  
                           || m[row][col] == 0) 
    {
        return;  
    
    }
    if (row == z-1 && col ==a-1) {
        return; 
    }  
    visited[row][col] = true; 
    int U,D,R,L;
    if (isSafe(row + 1, col, m, n, visited)) 
    { 
        D+=100;
    } 
    if (isSafe(row, col - 1, m, n, visited)) 
    { 
        L+=100;
    } 
    if (isSafe(row, col + 1, m, n, visited))  
    { 
        R+=100; 
    } 
    if (isSafe(row - 1, col, m, n, visited)) 
    { 
        U+=100;
    } 
    if (nextisSafe(row + 2, col, m, n, visited)) 
    { 
        D+=50;
    } 
    if (nextisSafe(row, col - 2, m, n, visited)) 
    { 
        L+=50;
    } 
    if (nextisSafe(row, col + 2, m, n, visited))  
    { 
        R+=50; 
    } 
    if (nextisSafe(row - 2, col, m, n, visited)) 
    { 
        U+=50;
    }
    if(closerheight(row,row+1,m,n,z-1))
    {
        D+=25;
    }
    if(closerheight(row,row-1,m,n,z-1))
    {
        U+=25;
    }
    if(closerweight(col,col-1,m,n,a-1))
    {
        L+=20;
    }
    if(closerweight(col,col+1,m,n,a-1))
    {
        R+=20;
    }
    maximum(D,U,L,R,m,n,path,visited,z,a,row,col);
    visited[row][col] = false; 
} 
void maximum(int D, int U, int L, int R,int m[MAX][max], int n, string& path, bool visited[MAX][max],int z,int a, int row, int col){
    if (D>U && D>L && D>R && D>=100)
    {
        path.push_back('D'); 
        printPathUtil(row + 1, col, m, n, 
                 path,visited,z,a);
    }
    else if (U>D && U>L && U>R && U>=100)
    {
        path.push_back('U'); 
        printPathUtil(row - 1, col, m, n, 
               path, visited,z,a); 
    }
    else if (L>D && L>U && L>R && L>=100)
    {
        path.push_back('L'); 
        printPathUtil(row, col - 1, m, n, 
                   path, visited,z,a); 
    }
    else if (R>D && R>U && R>L && R>=100)
    {
        path.push_back('R'); 
        printPathUtil(row, col + 1, m, n, 
                   path, visited, z,a); 
    }
    else 
    {
        return;
    }
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
