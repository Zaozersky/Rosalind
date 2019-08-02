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

map<string, string> codons;

VS readFasta()
{
    string header, fasta, maxHeader, str;
    VS headerToFasta;
    
    ifstream ifs("input.txt");
    
    while(getline(ifs, str))
    {
        if (str[0] == '>')
        {
            if (!header.empty())
            {
                headerToFasta.pb(fasta);
                fasta = "";
            }
            
            header = str;
        }
        else
        {
            fasta.append(str);
        }
    }
    
    headerToFasta.pb(fasta);
    
    ifs.close();
    
    return headerToFasta;
}

void fillCodons()
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

string getProtein()
{
    string str, protein = "";
    
    ifstream ifs("input.txt");
    
    while(getline(ifs, str))
    {
        protein += str;
    }
    
    ifs.close();
    
    return protein;
}

string toRna(string dna)
{
    replace(dna.begin(), dna.end(), 'T', 'U');
    return dna;
}

int main()
{
    VS v = readFasta();
    
    size_t n = v[0].size();
    
    map<char, VI> stat;
    
    int max;
    char ch;
    string consensus = "";
    
    FO(i, n)
    {
        map<char, int> counts = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
        
        FO(j, v.size())
        {
            counts[v[j][i]]++;
        }
        
        max = 0;
        
        for (auto it : counts)
        {
            if (max < it.second)
            {
                max = it.second;
                ch = it.first;
            }
            
            stat[it.first].pb(it.second);
        }
        
        consensus += ch;
        counts.clear();
    }
 
    cout << consensus << endl;
    
    for (auto it : stat)
    {
        cout << it.first <<": ";
        FO(i, it.second.size())
         cout << it.second[i] << " ";
        
        cout << endl;
        
    }

    return 0;
}
