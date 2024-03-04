#include<bits/stdc++.h>
using namespace std;

#define fork(i, n) for(long long i = 0; i < (long long)n; i++)
#define pb push_back
#define ln '\n'
#define all(ara) ara.begin(), ara.end()

typedef long long ll;

const ll N = 1e6+10;

const ll mod = 1e8 + 3;

vector<vector<int>>graph;

map<pair<int, int>, int>cost;

vector<int> ucs(vector<int>goal, int start){

    vector<int>ans;

    priority_queue<pair<int, int>> qu;

    for(auto it : goal){

        ans.pb(10e8);
    }

    qu.push({0, start});

    map<int, bool> vis;

    int cnt = 0;

    while(!qu.empty()){

        pair<int, int>p = qu.top();

        qu.pop();

        p.first *= -1;

        auto ii =find(goal.begin(), goal.end(), p.second );

        if(ii != goal.end()){

            int ind = find(goal.begin(), goal.end(), p.second) - goal.end();

            if(ans[ind] == 1e8) cnt++;

            ans[ind] = min(p.first, ans[ind]);

            qu.pop();

            if(cnt == goal.size()) return ans;

        }

        if(vis[p.second] == 0){

            for(auto it : graph[p.second]){

                qu.push({p.first+cost[{p.second, it}]*-1, it});
            }

            vis[p.second] = 1;
        }
    }

    return ans;
}

void solve(){

    int n, m;

    cin >> n >> m;

    char s, gg;

    cin >> s >> gg;

    int start, g;

    start = s-'A';

    g = gg - 'A';

    graph.resize(n);

    fork(i, m){

        char x, y , z;

        cin >> x >> y >> z;

        int xx, yy, zz;

        xx = x - 'A';

        graph[xx].pb(yy);

        cost[{xx, yy}] = zz;
    }

    vector<int>goal;

    goal.pb(g);

    vector<int>ans = ucs(goal, 0);

    cout << ans[0] << ln;

    return ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    cin >> t;


    while(t--){

        solve();

    }

    return 0;
}

