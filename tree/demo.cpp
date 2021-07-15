#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define vb vector<bool>
#define vs vector<string>
#define newline(n) for(int i = 0; i < (n); i++ )cout<<endl;
#define infor(vect) for(auto it : (vect)) { cout<<it<<endl; }
#define ump unordered_map
#define mp map
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))
#define MOD 1000000007

/*
problem statement -> 
Problem link -> 
*/


int heightOfTree(Node *root) {


    if(root == NULL)    return 0;

    int leftHeight = heightOfTree(root -> left);
    int rightHeight = heightOfTree(root -> right);

    return max(leftHeight, rightHeight)+1;
}


// O(n^2)
int diameterOfTree(Node *root) {

    if(root == NULL)
        return 0;

    int leftDiameter = diameterOfTree(root -> left);
    int rightDiameter = diameterOfTree(root -> right);


    int heights = heightOfTree(root -> left) + heightOfTree(root -> right) + 2;

    return max({heights, leftDiameter, rightDiameter})

}

// O(n)
pair<int, int> newHeight( Node *root) {
    
   if(root == NULL)
    return {0, -1};
    
    pair<int, int> left = newHeight(root -> left);
    pair<int, int> right = newHeight(root -> right);
    pair<int, int> newp;

    newp.second = max(left.second, right.second) + 1;
    int newd = left.second + right.second + 2;
   
    newp.first = max({newd, left.first, right.first});
    return newp;
}

int main() {

    freopen("./io/input.txt", "r", stdin);
    freopen("./io/output.txt", "w", stdout);


	cout<<"I'm Running";


    




    fclose(stdin);
    fclose(stdout);

}