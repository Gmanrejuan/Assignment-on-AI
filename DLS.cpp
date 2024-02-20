#include<bits/stdc++.h>
using namespace std;

#define fork(i, n) for(long long i = 0; i < (long long)n; i++)
#define pb push_back
#define ln '\n'
#define all(ara) ara.begin(), ara.end()

typedef long long ll;

const ll N = 1e6+10;

ll level;

const ll mod = 1e8 + 3;

void dfs(vector<vector<ll>>adjList, ll in, vector<bool>vis, ll curLevel){

    if(curLevel == level+1) return;

    if(!vis[in]){

        cout << in << ' ';

        vis[in] = true;

        for(ll it : adjList[in]){

            dfs(adjList, it, vis, curLevel+1);
        }
    }


}

void solve(){

    cout << "Enter the number of vertex : \n";

    ll n, m;

    cin >> n;

    cout <<  "Enter the number of edge : " << ln;

    cin >> m;

    cout <<  "Enter the direction of edge : " << ln; 

    cout <<  "Enter the level  : " << ln;

    cin >> level;

    vector<vector<ll>>adjList(n+1, vector<ll>());

    vector<bool>vis(n+1, false);

    fork(i , m){

        ll x, y;

        cin >> x >> y;

        adjList[x].pb(y);

        

    }



    // for(int i = 1; i <= n; i++){

    //     cout << i << " ---- ";

    //     for(ll it : adjList[i]) cout << it << ' '; 

    //     cout << ln;
    // }

    dfs(adjList, 1, vis, 0);

    return ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    //cin >> t;


    while(t--){

        solve();

    }

    return 0;
}

