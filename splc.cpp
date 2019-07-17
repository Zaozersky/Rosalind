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

string protein(string s)
{
    int k = 3;
    string protein = "";
    string codon;
    
    fillCodons();
    
    for (int i = 0; i < s.length() - k; i += k)
    {
        string t(s, i, k);
        codon = codons[t];
        if (codon == "Stop")
            break;
        protein += codon;
    }

    return protein;
}

string removeExon(string s, string t)
{
    size_t found = 0;
    
    while(1)
    {
        found = s.find(t, found);
        if (found == string::npos)
            break;
        
        s.erase(found, t.length());
    }
    
    return s;
}

string toRna(string dna)
{
    replace(dna.begin(), dna.end(), 'T', 'U');
    return dna;
}

int main()
{
    VS fasta = readFasta();
    string dna = fasta[0];

    FOR(i, 1, fasta.size())
    {
        dna = removeExon(dna, fasta[i]);
    }
    
    string rna = toRna(dna);
    
    cout << protein(rna) << endl;

    return 0;
}
