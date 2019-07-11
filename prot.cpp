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

map<string, string> codons;

void fillCodonsTable()
{
    ifstream ifs("codons.txt");
    string rna, protein;
      
    while(!ifs.eof())
    {
        ifs >> rna >> protein;
        codons[rna] = protein;
    }
    
    ifs.close();
}

int main()
{
    int k = 3;
    string s, protein;
    ifstream ifs("input.txt");
   
    ifs >> s;
    
    fillCodonsTable();
    
    for (int i = 0; i < s.length() - k; i += k)
    {
        string t(s, i, k);
        protein = codons[t];
        if (protein == "Stop")
            break;
        cout << protein;
    }
    
    cout << endl;

    ifs.close();
    
    return 0;  
}
