#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

#define FOR(i,a,b) for (int i = a; i < b; i++)
#define FO(i,n) FOR(i,0,n)
#define pb push_back
#define VI vector<int>
#define VB vector<bool>
#define INF 1E9

using namespace std;

ofstream ofs("result.txt", ofstream::out);

int factorial(int n)
{
	if (n <= 2)
		return n;

	return n * factorial(n - 1);
}

void print(int n, VI v)
{
	FO(i, n)
		ofs << v[i] << " ";

	ofs << endl;
}

void permutation(int idx, int n, VI v, VB used)
{
	if (idx == n)
	{
		print(n, v);
		return;
	}

	for (int i = 1; i < n + 1; i++)
	{
		if (used[i] == true)
			continue;

		v[idx] = i;
		used[i] = true;
		permutation(idx + 1, n, v, used);
		used[i] = false;
	}
}

int main()
{
	int n;
	cin >> n;

	VI v = vector<int>(n);
	VB used = vector<bool>(n + 1, false);

	ofs << factorial(n) << endl;
	permutation(0, n, v, used);
	
	ofs.close();

	return 0;

}