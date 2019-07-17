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
#define VS vector<string>
#define INF 1E9

using namespace std;

int main()
{
    string t, s;
    size_t found = 0;
    
    ifstream ifs("input.txt");
    ifs >> s;
    ifs >> t;
    
    while(1)
    {
        found = s.find(t, found);
        if (found != string::npos)
        {
            cout << found + 1 << " ";
            found++;
        }
        else break;
    }
    
    cout << endl;
    ifs.close();

    return 0;
}
