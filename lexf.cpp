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
#define VB vector<bool>
#define INF 1E9

using namespace std;

vector<char> v;
vector<char> z;

void print()
{
    FO(i, v.size())
     cout<<v[i];
    
    cout<<endl;
}

void perm(int idx, int n)
{
    if (idx == n)
    {
        print();
        return;
    }
    
    FO(i, z.size())
    {
        v[idx] = z[i];
        perm(idx + 1, n);
    }
        
}

int main()
{
    int n;
    string str;
    
    ifstream ifs("input.txt");
    
    getline(ifs, str);
    
    FO(i, str.length())
    {
        if (str[i] != ' ')
            z.pb(str[i]);
    }
    
    ifs >> n;

    v = vector<char>(n);
    perm(0, n);
        
    return 0;   
}
