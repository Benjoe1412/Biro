// rokonokBiro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define MYARRAYSIZE 200
#define PARENT 1
#define CHILD 2
#define DATEOFBIRTH 3

int main()
{
    int numberOfHumans; //A listában szereplő emberek száma
    string human[MYARRAYSIZE]; //Az emberek nevének listája ABC sorrendben
    cin >> numberOfHumans;
    for (int i = 1; i <= numberOfHumans; i++) cin >> human[i];
    int numberOfRelations;
    cin >> numberOfRelations;
    int relations[MYARRAYSIZE][4];
    for (int i = 1; i <= numberOfRelations; i++)
    {
        cin >> relations[i][PARENT];
        cin >> relations[i][CHILD];
        cin >> relations[i][DATEOFBIRTH];
    }
    int dateStart, dateEnd;
    int minNumberOfChildren;
    int parentWeCount;
    int parentWeMatch;
    cin >> dateStart >> dateEnd >> minNumberOfChildren >> parentWeCount >> parentWeMatch;
    int bornRight = 0;

    int j = 1;
    while (bornRight == 0 && j <= numberOfRelations)
    {

        if (relations[j][DATEOFBIRTH] >= dateStart && relations[j][DATEOFBIRTH] <= dateEnd) bornRight = relations[j][CHILD];
        j++;
    }
    if (bornRight > 0) cout << human[bornRight] << endl;
    else cout << "NINCS ILYEN EMBER" << endl;
    int numberOfChildren[MYARRAYSIZE];
    for (int i = 1; i <= numberOfHumans; i++) numberOfChildren[i] = 0;
    for (int i = 1; i <= numberOfRelations; i++)
    {
        numberOfChildren[relations[i][PARENT]]++;

    }
    for (int i = 1; i <= numberOfHumans; i++) cout << numberOfChildren[i] << " ";
    cout << endl;
    int superParents[MYARRAYSIZE];
    int numberOfSuperParents = 0;
    for (int i = 1; i <= numberOfHumans; i++)
        if (numberOfChildren[i] >= minNumberOfChildren)
        {
            numberOfSuperParents++;
            superParents[numberOfSuperParents] = i;
        }
    cout << numberOfSuperParents << " ";
    for (int i = 1; i <= numberOfSuperParents; i++)
    {
        cout << human[superParents[i]] << " ";
    }
    cout << endl;
    int mrX = parentWeCount;
    bool childrenOfMrX[MYARRAYSIZE];
    int numberOfMrXChildren = 0;
    for (int i = 1; i <= MYARRAYSIZE - 1; i++)
    {
        childrenOfMrX[i] = false;
    }
    for (int i = 1; i <= numberOfRelations; i++)
    {
        if (relations[i][PARENT] == mrX)
        {
            childrenOfMrX[relations[i][CHILD]] = true;
        }
    }

    for (int i = 1; i <= numberOfHumans; i++)
    {
        if (childrenOfMrX[i]) numberOfMrXChildren++;
    }
    cout << numberOfMrXChildren << " ";
    for (int i = 1; i <= numberOfHumans; i++)
    {
        if (childrenOfMrX[i]) cout << human[i] << " ";
    }
    cout << endl;
    bool sexMatrix[MYARRAYSIZE][MYARRAYSIZE];
    for (int i = 1; i <= numberOfHumans; i++)
    {
        for (int j = 1; j <= numberOfHumans; j++) sexMatrix[i][j] = false;
    }
    int whoSParentsHadSex, parentA, parentB;

    for (int i = 1; i <= numberOfRelations; i++)
    {
        whoSParentsHadSex = relations[i][CHILD];
        parentA = relations[i][PARENT];
        parentB = 0;
        int j = i;
        while (j <= numberOfRelations && parentB == 0)
        {
            if (relations[j][CHILD] == whoSParentsHadSex)
            {
                if (relations[j][PARENT] != parentA)
                {
                    parentB = relations[j][PARENT];
                }
            }
            j++;
        }
        sexMatrix[parentA][parentB] = true;
        sexMatrix[parentB][parentA] = true;
    }
    int thePersonWhoHadSex = parentWeMatch;
    int sexyTimesCounter = 0;
    for (int i = 1; i <= numberOfHumans; i++)
    {
        if (sexMatrix[thePersonWhoHadSex][i])sexyTimesCounter++;
    }
    cout << sexyTimesCounter << " ";
    for (int i = 1; i <= numberOfHumans; i++)
    {
        if (sexMatrix[thePersonWhoHadSex][i])cout << human[i] << " ";
    }


    // cout << "Hello World!\n";
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
