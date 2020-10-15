// Emberek.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    const int myArraySize = 200;
    int employeeCount;
    cin >> employeeCount;
    int age[myArraySize];
    int salary[myArraySize];
    int oldestIndex = 0;
    int ageMax = 0;
    int looserCounter = 0;
    bool ageSpectrum[150];
    for (int i = 0; i < 150; i++) ageSpectrum[i] = false;
    int ageSpectrumCount = 0;
    int underThirtyCount = 0;
    int underThirtyIndex[myArraySize];
    for (int i = 1; i <= employeeCount; i++)
    {
        cin >> age[i] >> salary[i];
        if (age[i] > ageMax)
        {
            oldestIndex = i;
            ageMax = age[i];
        }
        if (age[i] > 40 && salary[i] < 200000) looserCounter++;

        ageSpectrum[age[i]] = true;
        if (age[i] < 30)
        {
            underThirtyCount++;
            underThirtyIndex[underThirtyCount] = i;
        }
    }


    for (int i = 0; i < 150; i++)
    {
        if (ageSpectrum[i]) ageSpectrumCount++;
    }

    cout << oldestIndex << endl << looserCounter << endl << ageSpectrumCount << endl << underThirtyCount;
    for (int i = 1; i <= underThirtyCount; i++) cout << " " << underThirtyIndex[i];
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
