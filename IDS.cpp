#include<bits/stdc++.h>
using namespace std;

#define fork(i, n) for(long long i = 0; i < (long long)n; i++)
#define pb push_back
#define ln '\n'
#define all(ara) ara.begin(), ara.end()

typedef long long ll;

const ll N = 1e6+10;

const ll mod = 1e8 + 3;

void solve(){

    cout << "Enter the number of vertex : \n";

    ll n, m, level;

    cin >> n;

    cout <<  "Enter the number of edge : " << ln;

    cin >> m;

    cout <<  "Enter the direction of edge : " << ln; 

    cout <<  "Enter the level  : " << ln;

    cin >> level;

    vector<vector<ll>>adjList(n+1, vector<ll>());

    vector<bool>vis(n+1, false);

    vector<ll>lvl(n+1, 0);

    fork(i , m){

        ll x, y;

        cin >> x >> y;

        adjList[x].pb(y);     

    }

    queue<ll>qu;

    qu.push(1);

    while(!qu.empty()){

        if(lvl[qu.front()] == level+1) break;

        if(!vis[qu.front()]){

            ll x = qu.front();

            qu.pop();

            cout << x << ' ';

            vis[x] = true;

            for(ll it : adjList[x]) {

                if(!vis[it]){

                    qu.push(it);

                    lvl[it] = lvl[x]+1;

                }

            }
        }
    }

    for(ll it : lvl) cout << it << ' '; 

    return ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    // cin >> t;


    while(t--){

        solve();

    }

    return 0;
}

