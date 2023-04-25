
#include <cstdio>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <ctime>
#include<fstream>

using namespace std;

int counter = 0;

int randX()
{
    int x = rand()%2147483647;
    return x;
}

class dictionary {
private:
    int dictionary_size;
public:
    vector<int> dict;

    dictionary(int ds=1000000)
    {
        this->dictionary_size = ds;
        for (int i = 0; i < dictionary_size; i++)
        {
            dict.push_back(-1);
        }
    }
    ~dictionary() = default;

    int find(int i)
    {
        int hash_row = i % 10;
    
        
        for (int j = hash_row; j < dict.size(); j++)
        {
            counter++;
            if (dict[j] == -1)
            {

                return -1;
            }
            else if (dict[j] == i)
            {
             
                return j;
            }
            else if (dict[j] == -2)
            {
                continue;
            }
        }

        for (int j = 0; j < i % 10; j++)
        {
            counter++;
            if (dict[j] == -1)
            {
             
                return -1;
            }
            else if (dict[j] == i)
            {
               
                return j;
            }
            else if (dict[j] == -2)
            {
                continue;
            }
        }
        if (true)
        {
            return -1;
        }


    }

    

    void insert(int i)
    {
        int hash_row = i % 10;
        bool inserted = false;
        if (find(i)==-1)
        {
            for (int j = hash_row; j < dict.size(); j++)
            {
                if (dict[j] == -1)
                {
                    dict[j] = i;
                    inserted = true;
                    break;
                }
                else if (dict[j] == -2)
                {
                    dict[j] = i;
                    inserted = true;
                    break;
                }
                else
                {
                    continue;
                }
            }
            if (inserted == false)
            {
                for (int j = 0; j < hash_row; j++)
                {
                    if (dict[j] == -1)
                    {
                        dict[j] = i;
                        inserted = true;
                        break;
                    }
                    else if (dict[j] == -2)
                    {
                        dict[j] = i;
                        inserted = true;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            
        }
        //if (inserted == false)
        //{
        //    //cout << "there is no space for this value" << endl;
        //}

    }

    void delete_value(int i)
    {

        int index = find(i);
        if (index != -1)
        {
            dict[index] = -2;
        }
    }

    void print()
    {
        for (int i = 0; i < dict.size(); i++)
            cout << dict[i] << ", ";
    }



};

class test: public dictionary{

    int numberOfValuesInseted_Founded;
public:
    
    test(int val=10): numberOfValuesInseted_Founded(val)
    {
      
    }
    ~test() = default;
    
    void TestDataGeneric(test T)
    {
        ofstream save("C:/Users/user/Desktop/Algo proj/proj2_2/porownania.txt");
        for (int i = 0; i < numberOfValuesInseted_Founded; i++)
        {
            int x = randX();
          
            T.insert(x);
            counter = 0;
            int y = randX();
            T.find(y);
          
            save << counter << endl;
            counter = 0;
        }
        save.close();

        //T.print();
    }

};
int main()
{
    srand(time(NULL));
    test T(200000);
    T.TestDataGeneric(T);
    cout << "done";
   
    return 0;
}


