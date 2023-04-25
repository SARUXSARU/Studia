
#include <iostream>
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<fstream>

using namespace std;

int counter = 0;

int randX()
{
    int x = rand() % 2147483647;
    return x;
}

class dictionary {

private:
    int dictioary_size = 10;
public:
    vector<vector<int>> dict;
    dictionary()
    {
        for (int i = 0; i < dictioary_size; i++)
        {
            vector<int> row;
            dict.push_back(row);
        }
    }

    int find(int i)
    {
        int hash_column = i % 10;
        int check = 0;
        for (int j = 0; j < dict[hash_column].size(); j++)
        {
            counter++;
            if (dict[hash_column][j] == i)
            {
                return j;
            }
        }
        return -1;
        
    }

    void delete_value(int i)
    {
        int hash_row = i % 10;
        int f = find(i);
        if (f!=-1)
        {
            dict[hash_row].erase(dict[hash_row].begin() + f);
        }
        else
        {
            cout << "nothing to delete" << endl;
        }
    }

   /* void print()
    {
        for (int i = 0; i < dictioary_size; i++)
        {   
            cout << i << ": ";
            for (int j = 0; j < dict[i].size(); j++)
            {
                cout << dict[i][j] << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }*/

    void insert(int i)
    {
        int value = i;
        int hash_column = value % 10;

        while (find(value) != -1)
        {
            value = randX();
            hash_column = value % 10;
        }

        dict[hash_column].push_back(value);
    }

};



class test{

public:
    test() {}
    ~test() = default;
    dictionary D;

    void insert_values_to_dictionary(int NumberOfElementsInDictionary)
     {
        ofstream save("C:/Users/user/Desktop/Algo proj/proj2_1/porownania.txt");
         for (int i = 0; i < NumberOfElementsInDictionary; i++)
         {
             D.insert(randX());
             counter = 0;
             int x = randX();
             D.find(x);
             
             save << counter << endl;
             
             counter = 0;
         }
         save.close();
     }

};
    

int main()
{
    srand(time(NULL));
    test T;
    T.insert_values_to_dictionary(30000);
    //T.print();
    cout << "done" << endl;


    

    return 0;
}
