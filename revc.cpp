#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

string reverseComplement(string dna)
{
	string complementDna;

	if (!dna.empty())
	{
		for (int i = dna.length() - 1; i >= 0; i--)
		{
			switch (dna[i])
			{
			case 'A':
				complementDna.append("T");
				break;
			case 'C':
				complementDna.append("G");
				break;
			case 'G':
				complementDna.append("C");
				break;
			case 'T':
				complementDna.append("A");
				break;
			}
		}
	}

	return complementDna;
}

int main()
{
	string path, dna;

	cout << "file path: ";
	cin >> path;
	
	ifstream ifs(path);	
	ifs >> dna;

	cout << reverseComplement(dna) << endl;

	ifs.close();
	
	return 0;
}

