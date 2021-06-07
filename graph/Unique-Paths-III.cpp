#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define ump(dataTyp1, dataTyp2) unordered_map<(dataTyp1), (dataTyp2)>
#define mp(dataTyp1, dataTyp2) map<(dataTyp1), (dataTyp2)>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))
#define MOD 1000000007

/*
// 
problem statement -> On a 2-dimensional grid, there are 4 types of squares:
1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to 
the ending square, that walk over every non-obstacle square exactly once.

// Problem link -> https://leetcode.com/problems/unique-paths-iii/
*/


// ips
// [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
// [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
// [[0,1],[2,0]]




class Solution {
public:
        int ans = 0;
        int zeros = 0;
        int obstacles = 0;
        pair<int, int> start;
        pair<int, int> end;
    
    bool isItSafe(vector<vector<int>>& grid, int i, int j) {
        
        return i >= 0 and j >= 0 and i < grid.size() and j < grid[i].size() and grid[i][j] == 0;
    }
    
    
    void dfs(vector<vector<int>>& grid, int i, int j, int count) {
        
        // cout<<i<<" "<<j<<" "<<count<<endl;
        
        if(i == end.first and j == end.second) {
            
            if(count == zeros)
                ans++;
            return;
        }
        else if(not isItSafe(grid, i, j) ){
            return;
        }
        
        // if(i != start.first and j != start.second)
            grid[i][j] = -9;
        
        dfs(grid, i-1, j, count+1);
        dfs(grid, i, j+1, count+1);
        dfs(grid, i+1, j, count+1);
        dfs(grid, i, j-1, count+1);
        
    // if(i != start.first and j != start.second)
        grid[i][j] = 0;
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        
        for(int i = 0; i < grid.size(); i++) {
            
            for(int j = 0; j < grid[i].size(); j++) {
                
                if(grid[i][j] == 0) 
                    zeros++;
                else if(grid[i][j] == -1)
                    obstacles++;
                else if(grid[i][j] == 1) {
                    
                    start.first = i;
                    start.second = j;
                }
                else if(grid[i][j] == 2) {
                    
                    end.first = i;
                    end.second = j;
                }
            }
        }
        
        
        
        int i = start.first, j = start.second;
        dfs(grid, i-1, j, 0);
        dfs(grid, i, j+1, 0);
        dfs(grid, i+1, j, 0);
        dfs(grid, i, j-1, 0);
        
        
        return ans;
    }
};

// TC: o(n^2)
// space O(n^2)

class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {

        int R = obstacleGrid.length;
        int C = obstacleGrid[0].length;

        // If the starting cell has an obstacle, then simply return as there would be
        // no paths to the destination.
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        // Number of ways of reaching the starting cell = 1.
        obstacleGrid[0][0] = 1;

        // Filling the values for the first column
        for (int i = 1; i < R; i++) {
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) ? 1 : 0;
        }

        // Filling the values for the first row
        for (int i = 1; i < C; i++) {
            obstacleGrid[0][i] = (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) ? 1 : 0;
        }

        // Starting from cell(1,1) fill up the values
        // No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
        // i.e. From above and left.
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                } else {
                    obstacleGrid[i][j] = 0;
                }
            }
        }

        // Return value stored in rightmost bottommost cell. That is the destination.
        return obstacleGrid[R - 1][C - 1];
    }
}

