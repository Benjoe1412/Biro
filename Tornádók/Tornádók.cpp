// Tornádók.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    const int myArraySize = 1002;
    int tornadosPerDay[myArraySize];
    for (int i = 1; i < myArraySize; i++) tornadosPerDay[i] = 0;
    int numberOfTornados;
    int numberOfDays;
    cin >> numberOfDays >> numberOfTornados;
    for (int i = 1; i <= numberOfTornados; i++)
    {
        int actualDay;
        cin >> actualDay;
        tornadosPerDay[actualDay]++;
    }

    cout << "#";
    //int noTornadosDayIndex[myArraySize];
    int numberOfTornadoFreeDays=0;
    for (int i = 1; i <= numberOfDays; i++)
    {
        if (tornadosPerDay[i] == 0)
        {
            numberOfTornadoFreeDays++;
            //noTornadosDayIndex[numberOfTornadoFreeDays] = i;
        }
    }
    cout << endl << numberOfTornadoFreeDays <<endl;
    int tripleOneIndex = 0;
    int i = 3;
    while (i<=numberOfDays && !(tornadosPerDay[i] == 1 && tornadosPerDay[i - 1] == 1 && tornadosPerDay[i - 2] == 1))
    {
        i++;
    }
    if (i <= numberOfDays) tripleOneIndex = i - 1;
    cout << "#";
    cout << endl << tripleOneIndex<<endl;
    cout << "#";
    int maxNoTornadoLength = 0;
    //leghosszabb időszak amikor nem volt tornádó
    for (int i = 1; i <= numberOfDays; i++)
    {
        int tornadoFreeLength = 0;
        
        while (i <= numberOfDays && tornadosPerDay[i] == 0)
        {
            i++;
            tornadoFreeLength++;
        }
        if (tornadoFreeLength > maxNoTornadoLength) maxNoTornadoLength = tornadoFreeLength;
    }
    cout << endl << maxNoTornadoLength << endl;
    cout << "#";
    int maxTornadosPerDay = 0;
    for (int i = 1; i <= numberOfDays; i++)
    {
        if (tornadosPerDay[i] > maxTornadosPerDay) maxTornadosPerDay = tornadosPerDay[i];
    }
    cout << endl << maxTornadosPerDay << endl;

    int maxTornadoStart = 0;
    int maxTornadoEnd = 0;
    int maxTornadoLength = 0;
    for (int i = 1; i <= numberOfDays; i++)
    {
        int actualTornadoStart = 0;
        int actualTornadoEnd = 0;
        if (tornadosPerDay[i] > 0)
        {
            actualTornadoStart = i;
            while (tornadosPerDay[i] > 0 && i <= numberOfDays)
            {
                actualTornadoEnd = i;
                i++;
            }
            if ((actualTornadoEnd - actualTornadoStart + 1) > maxTornadoLength)
            {
                maxTornadoStart = actualTornadoStart;
                maxTornadoEnd = actualTornadoEnd;
                maxTornadoLength = maxTornadoEnd - maxTornadoStart + 1;
            }
        }
    }
    cout << "#" << endl << maxTornadoStart << " " << maxTornadoEnd << endl;
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
