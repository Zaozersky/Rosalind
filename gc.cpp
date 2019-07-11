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

double getGC(string fasta)
{
    int cnt = 0;
    
    FO(i, fasta.length())
    {
        if (fasta[i] == 'G' || fasta[i] == 'C')
            cnt++;
    }
    
    return cnt*100.0 / fasta.length();
}

int main()
{
    double max = 0, gc;
    string header, fasta, maxHeader, str;
    map<string, string> headerToFasta;
    
    ifstream ifs("input.txt");
    
    while(getline(ifs, str))
    {
        if (str[0] == '>')
        {
            if (!header.empty())
            {
                headerToFasta[header] = fasta;
                fasta = "";
            }
            
            header = str;
        }
        else
        {
            fasta.append(str);
        }
    }
    
    headerToFasta[header] = fasta;
    
    for (auto it : headerToFasta)
    {
        gc = getGC(it.second);
        
        if (max < gc)
        {
            max = gc;
            maxHeader = it.first;
        }
    }
    
    maxHeader.erase(0,1);
    
    cout << maxHeader <<" ";
    printf("%.6f%%\n", max);

    ifs.close();
    
    return 0;
}
