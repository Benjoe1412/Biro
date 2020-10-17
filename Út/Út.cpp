// Út.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Tudom, hogy nem így kéne, de én ezt egy tömbbel fogom megoldani
#include <iostream>
using namespace std;

int main()
{
    const int myVolumeSize = 1001;
    short roadSegementsNumberOfConstructions[myVolumeSize];
    
    int roadLength;
    int numberOfConstructions;
    int constructionStart[myVolumeSize];
    int constructionEnd[myVolumeSize];
    cin >> roadLength;
    cin >> numberOfConstructions;
    for (int i = 1; i <= numberOfConstructions; i++)
    {
        cin >> constructionStart[i] >> constructionEnd[i];
    }
    int minConstructionLength = INT16_MAX;
    for (int i = 1; i <= numberOfConstructions; i++)
    {
        if ((constructionEnd[i] - constructionStart[i]) < minConstructionLength)
        {
            minConstructionLength = (constructionEnd[i] - constructionStart[i]);
        }
    }
    cout << minConstructionLength<<endl;
    for (int i = 1; i <= roadLength; i++)
    {
        roadSegementsNumberOfConstructions[i] = 0;
    }
    for (int i = 1; i <= numberOfConstructions; i++)
    {
        for (int j = constructionStart[i]+1; j <= constructionEnd[i]; j++)
        {
            roadSegementsNumberOfConstructions[j]++;
        }
    }
    int firstTripleSegment = -1;
    int j = 1;
    while (j <= roadLength && roadSegementsNumberOfConstructions[j]<3 )
    {
        j++;
    }
    if (j <= roadLength) firstTripleSegment = j-1;
    cout << firstTripleSegment << endl;
    int untouchedRoadLength=0;
    for (int i = 1; i <= roadLength; i++)
    {
        if (roadSegementsNumberOfConstructions[i] == 0) untouchedRoadLength++;
    }
    cout << untouchedRoadLength<<endl;
    int maxUntouchedRoadlength = 0;
    for (int i = 1; i <= roadLength; i++)
    {
        int actualUntuchedRoadLength=0;
        while (roadSegementsNumberOfConstructions[i] == 0 && i <= roadLength)
        {
            actualUntuchedRoadLength++;
            i++;
        }
        if (actualUntuchedRoadLength > maxUntouchedRoadlength)maxUntouchedRoadlength = actualUntuchedRoadLength;
    }
    cout << maxUntouchedRoadlength;
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
