#include<bits/stdc++.h>
using namespace std;

const int N = 101;
int dp[N][N];
int grid[N][N];

int minimumPath(int n,int m)
{
    // 1. Base case
    if(n == 0 && m == 0)
    {
        return grid[n][m];
    }
    if(dp[n][m] != -1)
    {
        return dp[n][m];
    }
    int x,y,ans = 0;
    x = minimumPath(n-1,m) + grid[n][m];
    y = minimumPath(n,m-1) + grid[n][m];

    ans += min(x,y);
    dp[n][m] = ans;
    return dp[n][m];

}
int main()
{
    int row,col;
    cin>>row>>col;

    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            dp[i][j] = -1;
        }
    }

    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            cin>>grid[i][j];
        }
    }

    cout<<minimumPath(row-1,col-1)<<endl;



    return 0;
}
