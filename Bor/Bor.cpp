// Bor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    const int myArraySize = 1001;
    int numberOfYears;
    int price[myArraySize];
    int volume[myArraySize];
    cin >> numberOfYears;
    for (int i = 1; i <= numberOfYears; i++)
    {
        cin >> volume[i];
        cin >> price[i];
    }
    //minimumkiválsztás csinálunk
    int minimumVolume = INT16_MAX;
    int minVolumeIndex=0;
    //cout << minimumVolume;
    for (int i = 1; i <= numberOfYears; i++)
    {
        if (volume[i] < minimumVolume)
        {
            minimumVolume = volume[i];
            minVolumeIndex = i;
        }
    }
    cout << minVolumeIndex<<endl;
    int maxPriceOverThousand=-1;

    for (int i = 1; i <= numberOfYears; i++)
    {
        if (volume[i]>1000 && price[i] > maxPriceOverThousand) maxPriceOverThousand = price[i];
    }
    cout << maxPriceOverThousand<<endl;
    int listOfPrices[myArraySize];
    int numberOfPrices=0;
    //Én ilyen esetben szeretek bool tömböt használni és abban pipállgatni, de most listát készítünk és eldöntést 
    for (int i = 1; i <= numberOfYears; i++)
    {
        //Végigmegyünk a listán és eldöntjük, hogy benne van e már az ár
        int j = 1;
        while (j <= numberOfPrices && price[i] != listOfPrices[j])
        {
            j++;
        }
        //Ha nem volt akkor j nagyobb lesz mint a lista elemszáma, ekkor hozzáadjuk az árat a listához
       
        if (j > numberOfPrices)
        {
            numberOfPrices++;
            listOfPrices[numberOfPrices] = price[i];
        }
    }
    cout << numberOfPrices << endl;
    int listOfChampionYears[myArraySize];
    int numberOfChampionYears = 0;
    int maxVolumeSoFar = -1;
    for (int i = 1; i <= numberOfYears; i++)
    {
        if (maxVolumeSoFar >= 0 && volume[i] > maxVolumeSoFar)
        {
            maxVolumeSoFar = volume[i];
            numberOfChampionYears++;
            listOfChampionYears[numberOfChampionYears] = i;
        }
        else if (i == 1) maxVolumeSoFar = volume[i];
        
        
    }
    cout << numberOfChampionYears << " ";
    for (int i = 1; i <= numberOfChampionYears; i++)
    {
        cout << listOfChampionYears[i] << " ";
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
