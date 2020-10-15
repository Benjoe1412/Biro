// idojaras.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    const int myArraySize=201;
    int daycount;
    cin >> daycount;
    int min[myArraySize];
    int max[myArraySize];
    int frostcount = 0;
    int maxdiff = 0;
    int maxdiffindex = 0;
    bool istherecolder = false;
    int colderindex = -1;
    int warmfrostindex[myArraySize];
    int warmfrostcount = 0;
    for (int i = 1; i <= daycount; i++)
    {
        cin >> min[i];
        if (min[i] <= 0) frostcount++;
        cin >> max[i];
        if (max[i] - min[i] > maxdiff)
        {
            maxdiff = max[i] - min[i];
            maxdiffindex = i;
        }
        if (i >= 2 && !istherecolder)
        {
            if (max[i] < min[i - 1])
            {
                istherecolder = true;
                colderindex = i;
            }
        }
        if (min[i] <= 0 && max[i] > 0)
        {
            warmfrostcount++;
            warmfrostindex[warmfrostcount] = i;
        }

    }
    //elso reszfeladat

    cout << "#" << endl << frostcount << endl << "#" << endl << maxdiffindex << endl << "#" << endl << colderindex << endl << "#" << endl << warmfrostcount;
    for (int i = 1; i <= warmfrostcount; i++)
    {
        cout << " " << warmfrostindex[i];
    }

    return 0;
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
