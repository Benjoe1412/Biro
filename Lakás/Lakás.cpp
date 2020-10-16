// Lakás.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    const int myArraySize=202;
    const int areaUpperLimit = 2000;
    int numberOfFlats;
    int flatArea[myArraySize];
    int flatPrice[myArraySize];
    cin >> numberOfFlats;
    for (int i = 1; i <= numberOfFlats; i++)
    {
        cin >> flatArea[i] >> flatPrice[i];
    }
    int highestPrice, highestPriceIndex;
    highestPrice = 0;
    for (int i = 1; i <= numberOfFlats; i++)
    {
        if (flatPrice[i] >= highestPrice)
        {
            highestPrice = flatPrice[i];
            highestPriceIndex = i;
        }
    }
    cout << highestPriceIndex << endl;
    int numberOfGoodDeals=0;
    //int goodDeals[myArraySize];
    for (int i = 1; i <= numberOfFlats; i++)
    {
        if (flatPrice[i] < 40 && flatArea[i]>100)
        {
            numberOfGoodDeals++;
            //goodDeals[numberOfGoodDeals] = i;
        }
    }
    cout << numberOfGoodDeals << endl;
    bool allFlatSizes[areaUpperLimit+1];
    int numberOfSizes=0;
    for (int i = 1; i <= areaUpperLimit; i++) allFlatSizes[i] = false;
    for (int i = 1; i <= numberOfFlats; i++) allFlatSizes[flatArea[i]] = true;
    for (int i = 1; i <= areaUpperLimit; i++)
    {
        if (allFlatSizes[i]) numberOfSizes++;
    }
    cout << numberOfSizes<<endl;
    int highPriceFlats[myArraySize];
    int numberOfHighPriceFlats=0;
    for (int i = 1; i <= numberOfFlats; i++)
    {
        if (flatPrice[i] > 100)
        {
            numberOfHighPriceFlats++;
            highPriceFlats[numberOfHighPriceFlats] = i;
        }
    }
    cout << numberOfHighPriceFlats << " ";
    for (int i = 1; i <= numberOfHighPriceFlats;i++) cout << highPriceFlats[i] << " ";


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
