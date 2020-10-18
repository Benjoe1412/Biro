// Munka.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int numberOfCompanies;
    int numberOfContracts;
    const int myArraySize=2001;
    int companyIndex[myArraySize];
    int workerIndex[myArraySize];
    int workerAge[myArraySize];
    int workerGender[myArraySize];
    cin >> numberOfCompanies >> numberOfContracts;
    for (int i = 1; i <= numberOfContracts; i++)
    {
        cin >> companyIndex[i] >> workerIndex[i] >> workerAge[i] >> workerGender[i];
    }
    int numberOfWomen=0;
    int numberOfMen = 0;
    for (int i = 1; i <= numberOfContracts; i++)
    {
        if (workerGender[i] == 0) numberOfWomen++;
        else if (workerGender[i] == 1) numberOfMen++;
        //Ez persze kicsit felesleges, de a mai világban akár még bővíthetjük is a nemek számát :)
    }
    cout << numberOfWomen << " " << numberOfMen << endl;
    int companiesUsed[myArraySize];
    int numberOfCompaniesUsed=0;
    for (int i = 1; i <= numberOfCompanies; i++)
    {
        companiesUsed[i] = 0;
    }
    for (int i = 1; i <= numberOfContracts; i++)
    {
        companiesUsed[companyIndex[i]]++;
    }
    for (int i = 1; i <= numberOfCompanies; i++)
    {
        if (companiesUsed[i])numberOfCompaniesUsed++;
    }
    cout << numberOfCompaniesUsed << endl;
    for (int i = 1; i <= numberOfCompanies; i++) cout << companiesUsed[i] << " ";
    cout << endl;
    //Itt csinálunk egy rendezést
    int workerAgeListIndex[myArraySize];
    int workerAgeListAge[myArraySize];
    int workerAgeListGender[myArraySize];
    for (int i = 1; i <= numberOfContracts; i++)
    {
        workerAgeListIndex[i] = workerIndex[i];
        workerAgeListAge[i] = workerAge[i];
        workerAgeListGender[i] = workerGender[i];
    }
    bool bingo = false;
    while (!bingo)
    {
        bingo = true;
        for (int i = 2; i <= numberOfContracts; i++)
        {
            if (workerAgeListAge[i] < workerAgeListAge[i - 1])
            {
                swap(workerAgeListAge[i], workerAgeListAge[i - 1]);
                swap(workerAgeListGender[i], workerAgeListGender[i - 1]);
                swap(workerAgeListIndex[i], workerAgeListIndex[i - 1]);
                bingo = false;

            }
            else if (workerAgeListAge[i] == workerAgeListAge[i - 1] && workerAgeListGender[i] < workerAgeListGender[i - 1])
            {
                swap(workerAgeListAge[i], workerAgeListAge[i - 1]);
                swap(workerAgeListGender[i], workerAgeListGender[i - 1]);
                swap(workerAgeListIndex[i], workerAgeListIndex[i - 1]);
                bingo = false;
            }

        }
    }
    for (int i = 1; i <= numberOfContracts; i++) cout << workerAgeListIndex[i]<<" ";
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
