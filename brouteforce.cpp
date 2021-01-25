#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
#define MAX 7
#define max 6
using namespace std; 
bool isSafe(int row, int col, int m[MAX][max], int n, bool visited[MAX][max]) 
{ 
    if (row == -1 || row == 7 || col == -1 ||  
                  col == 6 || visited[row][col]  
                           || m[row][col] == 0) 
        return false; 
  
    return true; 
} 
void printPathUtil(int row, int col, int m[MAX][max], int n, string& path, vector<string>&
               possiblePaths, bool visited[MAX][max], int z, int a) 
{  
    if (row == -1 || row == 7 || col == -1  
               || col == 6 || visited[row][col]  
                           || m[row][col] == 0) 
        return;  
    if (row == z-1 && col ==a-1) { 
        possiblePaths.push_back(path); 
        return; 
    }  
    visited[row][col] = true; 
    if (isSafe(row + 1, col, m, n, visited)) 
    { 
        path.push_back('D'); 
        printPathUtil(row + 1, col, m, n, 
                 path, possiblePaths, visited,z,a); 
        path.pop_back(); 
    } 
    if (isSafe(row, col - 1, m, n, visited)) 
    { 
        path.push_back('L'); 
        printPathUtil(row, col - 1, m, n, 
                   path, possiblePaths, visited,z,a); 
        path.pop_back(); 
    } 
    if (isSafe(row, col + 1, m, n, visited))  
    { 
        path.push_back('R'); 
        printPathUtil(row, col + 1, m, n, 
                   path, possiblePaths, visited,z,a); 
        path.pop_back(); 
    } 
    if (isSafe(row - 1, col, m, n, visited)) 
    { 
        path.push_back('U'); 
        printPathUtil(row - 1, col, m, n, 
               path, possiblePaths, visited,z,a); 
        path.pop_back(); 
    } 
    visited[row][col] = false; 
}   
void printPath( int m[MAX][max], int n,int x,int y, int z, int a) 
{ 
    vector<string> possiblePaths; 
    string path; 
    bool visited[MAX][max]; 
    memset(visited, false, sizeof(visited));   
    printPathUtil(x-1,y-1, m, n, path,  
                      possiblePaths, visited,z,a);  
    for (int i = 0; i < possiblePaths.size(); i++) 
        cout << possiblePaths[i] << " "<<endl; 
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
    cout<<"for test git"<<endl:
    int n = sizeof(m) / sizeof(m[0]);
    printPath(m, n,x,y,z,a); 
  
    return 0; 
} 
