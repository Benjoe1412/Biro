// Utazás.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    const int myArraySize = 2001;
    int numberOfCities;
    cin >> numberOfCities;
    int distance[myArraySize];
    int price[myArraySize];
    for (int i = 1; i <= numberOfCities; i++)
    {
        cin >> distance[i] >> price[i];
    }
    //Egy laza maximumkiválasztás
    int highestDistance = 0;
    int highestDistanceIndex = 0;
    for (int i = 1; i <= numberOfCities; i++)
    {
        if (distance[i] > highestDistance)
        {
            highestDistance = distance[i];
            highestDistanceIndex = i;
        }
    }
    cout << highestDistanceIndex << endl;
    int highestPriceUnderThousand = 0;
    int highestPriceUnderThousandIndex = 0;
    for (int i = 1; i <= numberOfCities; i++)
    {
        if (distance[i] < 1000)
        {
            if (price[i] > highestPriceUnderThousand)
            {
                highestPriceUnderThousand = price[i];
                highestPriceUnderThousandIndex = i;
            }
        }
    }
    cout << highestPriceUnderThousand << endl;
    //Olyan árat keresünk ami csak egyszer fordul elő a tömbben
    //int pricesWeChecked[myArraySize];
    //int numberOfPricesWeChecked=0;
    int numberOfUniquePrices = 0;
    for (int i = 1; i <= numberOfCities; i++)
    {
        //megszámolunk minden árat, hogy hányszor fordul elő a listában
        int priceOccurence = 0;
        for (int j = 1; j <= numberOfCities; j++)
        {
            if (price[i] == price[j]) priceOccurence++;

        }
        if (priceOccurence == 1) numberOfUniquePrices++;
    }
    cout << numberOfUniquePrices << endl;
    int expensiveFlights[myArraySize];
    int numberOfExpensiveFlights = 0;
    for (int i = 1; i <= numberOfCities; i++)
    {
        if ((price[i] / distance[i]) > 100)
        {
            numberOfExpensiveFlights++;
            expensiveFlights[numberOfExpensiveFlights] = i;
        }
        else if ((price[i] / distance[i]) == 100 && (price[i] % distance[i]) > 0)
        {
            numberOfExpensiveFlights++;
            expensiveFlights[numberOfExpensiveFlights] = i;
        }
    }
    cout << numberOfExpensiveFlights << " ";
    for (int i = 1; i <= numberOfExpensiveFlights; i++)
    {
        cout << expensiveFlights[i] << " ";
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