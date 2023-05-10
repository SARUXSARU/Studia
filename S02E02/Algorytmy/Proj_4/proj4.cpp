
#include <iostream>
#include<limits.h>
using namespace std;

class graph_table {

private:
	int top;
	int edges;
public:
	int** tab;
	graph_table(int x, int y): top(x), edges(y)
	{
		tab = new int*[x];
		for (int i = 0; i < x; i++)
		{
			tab[i] = new int[x];
			for (int j = 0; j < x; j++)
			{
				tab[i][j] = INT_MAX;
			}
			tab[i][i] = 0;
		}

	}

	~graph_table()
	{
		for (int i = 0; i < top; i++)
		{
			delete[] tab[i];
		}
		delete[] tab;
	}
	void print()
	{
		for (int i = 0; i < top; i++)
		{
			
			for (int j = 0; j < top; j++)
			{
				if (tab[i][j] == INT_MAX)
				{
					cout << " :";
				}
				else
				{
					cout << tab[i][j] << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	void add_values()
	{
		int x, y, v;
		//cout << size_x << " " << size_y << endl;
		for (int i = 0; i < edges; i++)
		{
			cout << i << endl;
			do {
				cout << "podaj wartosci (wierzcholek z -> do oraz wartosc ): ";
				cin >> x >> y >> v;
			} while (x >= top && y >= top);
			tab[x][y] = v;
		}
	}
	void cal_value()
	{
		int x;
		for (int k = 0; k < top; k++)
		{
			for (int i = 0; i < top; i++)
			{
				for (int j = 0; j < top; j++)
				{
					if ((tab[i][k] == INT_MAX) || (tab[k][j] == INT_MAX))
					{
						continue;
					}

						x = tab[i][k] + tab[k][j];

					if (tab[i][j] > x)
					{
						tab[i][j] = x;
						// cout << "zamienilem gdy i: " << i << " j: " << j << " k: " << k <<" val: "<<x<< endl;
					}
				}
			}
		}
	}

	void show_val()
	{
		cout << " Wartosci wynikowe: " << endl;
		for (int i = 0; i < top; i++)
			for (int j = 0; j < top; j++)
			{
				
				if (tab[i][j] == INT_MAX)
				{
					continue;
				}
				else
				{
					cout << "tab [ " << i << ", " << j << " ] = ";
					cout << tab[i][j] << endl;
				}
				
			}
	}

	

};
int main()
{
	int x, y;
	cout << " podaj ilosc wierzchlkow i krawedzi: ";
	cin >> x >> y;
	graph_table G1(x, y);
	G1.print();
	cout << endl;
	G1.add_values();
	cout << endl;
	cout << "stan poczatkowy macierzy (\" :\" = infty): " << endl;
	G1.print();
	G1.cal_value();
	cout << "stan koncowy macierzy: " << endl;
	G1.print();
	cout << endl;
	G1.show_val();
	return 1410;
   
}

