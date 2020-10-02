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
 
    int n,m,l;
    int a[105],b[105],c[105];

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    cin>>m;
    for(int i=0; i<m; i++)
        cin>>b[i];
    cin>>l;
    for(int i=0; i<l; i++)
        cin>>c[i];

    int dp[n+1][m+1][l+1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            for(int k=0; k<=l; k++)
            {
                if(i==0 || j==0 || k==0)
                    dp[i][j][k] = 0;
                else if(a[i-1] == b[j-1] && b[j-1] == c[k-1])
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
            }
        }
    }

    cout<<dp[n][m][l]<<endl;
 
    return 0;
   
}