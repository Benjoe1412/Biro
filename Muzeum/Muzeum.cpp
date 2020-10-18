// Muzeum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int numberOfDays;
    int numberOfGuards;
    const int MyArraySize=2001;
    int serviceStart[MyArraySize];
    int serviceEnd[MyArraySize];
    cin >> numberOfDays >> numberOfGuards;
    for (int i = 1; i <= numberOfGuards; i++)
    {
        cin >> serviceStart[i] >> serviceEnd[i];
    }
    int guardsOnEachDay[MyArraySize];
    for (int i = 1; i <= numberOfDays; i++)
    {
        guardsOnEachDay[i] = 0;
    }
    for (int i = 1; i <= numberOfGuards; i++)
    {
        
        for (int j = serviceStart[i]; j <= serviceEnd[i]; j++)
        {
            guardsOnEachDay[j]++;
        }
    }

    int maxServiceLength = 0;
    //int maxServiceLengthIndex=-1;
    for (int i = 1; i <= numberOfGuards; i++)
    {
        if ((serviceEnd[i] - serviceStart[i] + 1) > maxServiceLength)
        {
                maxServiceLength = serviceEnd[i] - serviceStart[i] + 1;
        }
        
    }
    cout << maxServiceLength <<endl;
    for (int i = 1; i <= numberOfDays; i++) cout << guardsOnEachDay[i] << " ";
    int maxNumberOfGuards=0;
    int maxNumberOfGuardsDayIndex=0;
    cout << endl;
    for (int i = 1; i <= numberOfDays; i++)
    {
        if (guardsOnEachDay[i] > maxNumberOfGuards)
        {
            maxNumberOfGuards = guardsOnEachDay[i];
            maxNumberOfGuardsDayIndex = i;
        }
    }
    cout << maxNumberOfGuardsDayIndex << endl;
    int notEnoughGuardsStart = 0;
    int notEnoughGuardsEnd = 0;
    int MaxNotEnoughGuardsStart = 0;
    int MaxNotEnoughGuardsEnd = 0;
    int MaxNotEnoughGuardsDuration=0;
    for (int i = 1; i <= numberOfDays; i++)
    {
        bool weStartedCounting=false;
        while (i <= numberOfDays && guardsOnEachDay[i] < 2)
        {
            if (!weStartedCounting)
            {
                weStartedCounting = true;
                notEnoughGuardsStart = i;
            }
            notEnoughGuardsEnd = i;
            i++;
        }

        if (notEnoughGuardsStart != 0 && (notEnoughGuardsEnd - notEnoughGuardsStart) + 1 > MaxNotEnoughGuardsDuration)
        {
            MaxNotEnoughGuardsStart = notEnoughGuardsStart;
            MaxNotEnoughGuardsEnd = notEnoughGuardsEnd;
            MaxNotEnoughGuardsDuration = 1 + MaxNotEnoughGuardsEnd - MaxNotEnoughGuardsStart;
        }
    }
    if (MaxNotEnoughGuardsDuration == 0) cout << 0 << endl;
    else 
    {
        cout << MaxNotEnoughGuardsStart << " " << MaxNotEnoughGuardsEnd;
    }
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
