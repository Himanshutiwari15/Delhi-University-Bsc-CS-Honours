#include<bits/stdc++.h> 
using namespace std;
 
#define ull unsigned long long
#define int long long
#define ld long double
#define pb push_back
#define pi  pair< int,int >
#define ff first
#define ss second
#define mod 1000000007
#define endl "\n"
 
signed main()
{
 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
 
    string s,t;

    cin>>s;
    cin>>t;
    
    int n = s.length();
    int m = t.length();

    int dp[n+1][m+1];

    for(int i=0; i<=n; i++)
        dp[i][0]=i;
    for(int i=0; i<=m; i++)
        dp[0][i]=i;

    for(int i=1; i<=n ; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int c = (s[i-1]!=t[j-1]) ? 1 : 0;
            dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1] + c));
            //cout<<dp[i][j]<<endl;
        }
    }

    cout<<dp[n][m]<<endl;
 
    return 0;
   
}