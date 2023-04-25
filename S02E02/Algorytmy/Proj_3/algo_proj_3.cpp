#include<iostream>
#include<algorithm>
using namespace std;

string s1;
string s2;

class NWP {

	int A;
	int B;
public:
	int** tab;
	NWP(int a=5, int b=5) : A(a), B(b)
	{
		tab = new int*[a];
		for (int i = 0; i < a; i++)
		{
			tab[i] = new int[b];
		}
		for (int i = 0; i < a; i++)
		{
			tab[i][0] = 0;
		}
		for (int i = 0; i < b; i++)
		{
			tab[0][i] = 0;
		}
	}
	~NWP() = default;
	void findLengthNWP()
			{
				for (int i = 1; i < A; i++)
				{
					for (int j = 1; j < B; j++)
					{
						if (s1[i-1] == s2[j-1])
						{
							tab[i][j] = tab[i - 1][j - 1] + 1;
						}
						else
						{
							tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
						}	
					}
				}
				cout <<"dlugosc NWP: "<< tab[A - 1][B - 1] << endl;
			}

	void printTab()
	{
		for (int i = 0; i < A; i++)
		{
			
			for (int j = 0; j < B; j++)
			{
				cout<<tab[i][j]<<" ";
			}
			cout << endl;
		}
	}

	void printNWP()
	{
		int i = A - 1;
		int j = B - 1;
		string NWP = "";
		while (i != 0 && j != 0)
		{
			if (tab[i][j - 1] == tab[i][j])
			{
				j -= 1;
			}
			else if (tab[i - 1][j] == tab[i][j])
			{
				i -= 1;
			}
			else
			{
				NWP += s1[i-1];
				i -= 1;
				j -= 1;
			}
		}
		reverse(NWP.begin(), NWP.end());
		cout << "NWP: " << NWP << endl;
		
	}
};

int main()
{
	cin >> s1;
	cin >> s2;

	NWP tabl(s1.length()+1, s2.length()+1);

	tabl.findLengthNWP();
	
	tabl.printNWP();

	tabl.printTab();

	return 0;
}