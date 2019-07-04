#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

#define FOR(i,m,n) for(int i = m; i < n; i++)
#define FO(i,n) FOR(i,0,n)

using namespace std;

int hammingDistance(string s, string t)
{
	int distance = 0;

	if (!s.empty() && !t.empty() && s.length() == t.length())
	{
		FO(i, s.length())
		{
			if (s[i] != t[i])
				distance++;
		}
	}

	return distance;
}

int main()
{
	string path, s, t;

	cout << "file path: ";
	cin >> path;
	
	ifstream ifs(path);
	
	ifs >> s;
	ifs >> t;

	cout << hammingDistance(s, t) << endl;

	ifs.close();

	return 0;
}

