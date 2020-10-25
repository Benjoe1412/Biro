// Allatkert.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//FÉLKÉSZ ÁLLAPOTBAN VAN
int main()
{
    const int matrixSize=102;
    int zooMatrix[matrixSize][matrixSize];//első index az állatkert, második index a faj, az érték pedig az állatok száma
    int numberOfZoos,numberOfSpecies,numberOfDataLines;
    cin >> numberOfZoos>>numberOfSpecies>>numberOfDataLines;
    //kinullázzuk a mátrixunkat
    for (int i = 1; i <= numberOfZoos; i++)
    {
        for (int j = 1; j <= numberOfSpecies; j++)
        {
            zooMatrix[i][j] = 0;
        }
    }
    //Feltöltjük a mátrixunkat az adatok beolvasásával
    int actualZoo, actualSpecies, numberOfSpecimens;
    for (int i = 1; i <= numberOfDataLines; i++)
    {
        cin >> actualZoo >> actualSpecies >> numberOfSpecimens;
        zooMatrix[actualZoo][actualSpecies] = numberOfSpecimens;
    }
    //Irjuk ki annak az állatkertnek a sorszámát ahol a legtöbb állat van
    //Maximumkiválasztásba ágyazott öszegzés
    int maxNumberOfAnimals = 0;
    int maxiZooIndex=0;
    for (int i = 1; i <= numberOfZoos; i++)
    {
        int speciesSum = 0;
        for (int j = 1; j <= numberOfSpecies; j++)
        {
            speciesSum += zooMatrix[i][j];
        }
        if (speciesSum > maxNumberOfAnimals)
        {
            maxNumberOfAnimals = speciesSum;
            maxiZooIndex = i;
        }
    }
    cout <<"#"<<endl << maxiZooIndex << endl;
    //legkevesebb állatkertben előforduló állatfaj kiválsztása minimumkiválasztással
    //állatkertek kiválogatása kiválogatással
    //int rareZoos[matrixSize];//ebben tároljuk az állatkertek listáját
    int rarestIndex;
    
    int rarestCount = INT16_MAX;
    for (int i = 1; i <= numberOfSpecies; i++)
    {
        int zooCountPerSpecies = 0;
        for (int j = 1; j <= numberOfZoos; j++)
        {
            if (zooMatrix[j][i] > 0) zooCountPerSpecies++;
        }
        if (zooCountPerSpecies < rarestCount && zooCountPerSpecies>0)
        {
            rarestCount = zooCountPerSpecies;
            rarestIndex = i;
        }
    }
    cout <<"#"<<endl << rarestCount << endl;
    for (int i = 1; i <= numberOfSpecies; i++)
    {
        int zooCountPerSpecies = 0;
        for (int j = 1; j <= numberOfZoos; j++)
        {
            if (zooMatrix[j][i] > 0) zooCountPerSpecies++;
        }
        if (zooCountPerSpecies == rarestCount)
        {
            cout << i << " ";
        }
    }
    cout << endl;
    //minden fajtából legalább 2-t tartó állatkertek sorszáma
    //kiválogatásba ágyazott eldöntés, lehet üres is az állatkert
    int pairZoosIndex[matrixSize];
    int numberOfPairedZoos = 0;
    for (int i = 1; i <= numberOfZoos; i++)
    {
        bool empty = false;
        bool everyAnimalHasAFriend = true;
        for (int j = 1; j <= numberOfSpecies; j++)
        {
            //if (empty && zooMatrix[i][j] > 0) empty = false;
            if (everyAnimalHasAFriend && zooMatrix[i][j] == 1) everyAnimalHasAFriend = false;
        }
        if (!empty && everyAnimalHasAFriend)
        {
            numberOfPairedZoos++;
            pairZoosIndex[numberOfPairedZoos] = i;
        }

    }
    cout <<"#"<<endl<< numberOfPairedZoos<<endl;
    //for (int i = 1; i <= numberOfPairedZoos; i++) cout << pairZoosIndex[i] << " ";
    int noCommonAnimalZooIndexA, noCommonAnimalZooIndexB;
    bool bingo = false;
    int i = 1;
    while (!bingo && i <= numberOfZoos)
    {
        int j = i+1;
        while (!bingo && j <= numberOfZoos)
        {
            int k = 1;
            while (k<=numberOfSpecies && (zooMatrix[i][k]==0 || zooMatrix[j][k]==0 ))
            {
                k++;
            }
            if (k > numberOfSpecies)
            {
                bingo = true;
                noCommonAnimalZooIndexA = i;
                noCommonAnimalZooIndexB = j;
            }
            
            j++;
        }
        i++;
    }
    cout << "#" << endl;
    if (!bingo) cout << "-1";
    else cout << noCommonAnimalZooIndexA << " " << noCommonAnimalZooIndexB;
    int superZooIndex[matrixSize];
    int superZooCount=0;
    for (int i = 1; i <= numberOfZoos; i++)
    {
        bool empty = true;
        bool itIsASuperZoo = true;
        for (int j = 1; j <= numberOfSpecies; j++)
        {
            if (empty && zooMatrix[i][j] > 0) empty = false;
            for (int k = 1; k <= numberOfZoos; k++)
            {
                if (zooMatrix [i][j]>0 && zooMatrix[i][j] <= zooMatrix[k][j] && i != k) itIsASuperZoo = false;
            }
        }
        if (itIsASuperZoo)
        {
            superZooCount++;
            superZooIndex[superZooCount] = i;
        }
    }
    cout <<endl<< "#";
    cout <<endl<< superZooCount << endl;
    for (int i = 1; i <= superZooCount; i++)
    {
        cout << superZooIndex[i] << " ";
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
