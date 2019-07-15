#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <bitset>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <ctime>

#define FOR(i,a,b) for (int i = a; i < b; i++)
#define FO(i,n) FOR(i,0,n)
#define pb push_back
#define VI vector<int>
#define VVI vector<vector<int>>
#define VB vector<bool>
#define VS vector<string>
#define INF 1E9

using namespace std;

map<int, VI> edges;
VB used;
VI dist;

void bfs(int vertex)
{
    int current, u;
    queue<int> q;
    
    q.push(vertex);
    dist[vertex] = 0;
    
    while(!q.empty())
    {
        current = q.back();
        q.pop();
        
        FO(i, edges[current].size())
        {
            u = edges[current][i];
            if (!used[u])
            {
                q.push(u);
                used[u] = true;
                dist[u] = dist[current] + 1;
            }
        }
    }
    
}

int main()
{
    ifstream ifs("input.txt");
  
    int n, m;
    int x, y;
    
    ifs >> n >> m;
    
    used = vector<bool>(n, false);
    dist = vector<int>(n, -1);
    
    FO(i, m)
    {
        ifs >> x >> y;
        edges[--x].pb(--y);
    }
    
    bfs(0);
    
    FO(i, n)
     cout << dist[i] << " ";
    
    
    return 0;
}
