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

map<char, double> aaWeight;

void readAminoAcidWeight()
{
    ifstream ifs("mass.txt");
    char aminoAcid;
    double w;
    
    while(!ifs.eof())
    {
        ifs >> aminoAcid >> w;
        aaWeight[aminoAcid] = w;
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

int main()
{
    double totalWeight = 0;
    
    readAminoAcidWeight();
    
    string protein = getProtein();

    FO(i, protein.length()) {
      totalWeight += aaWeight[protein[i]];
    }
    
    printf("%f\n", totalWeight);
  
    return 0;
}
