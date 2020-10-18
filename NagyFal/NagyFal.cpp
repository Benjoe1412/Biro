// nagyFal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	bool guardPosts[1002];
	bool guardPostsEditable[1002];
	int guardPostCount;
	cin >> guardPostCount;
	int actualGuardCount;
	int sendGuard = 0;

	int protectedStart = 0, protectedEnd = 0, protectedCount = 0;
	int maxProtectedStart = 0, maxProtectedEnd = 0, maxProtectedCount = 0;
	for (int i = 1; i <= guardPostCount; i++)
	{
		cin >> actualGuardCount;
		if (actualGuardCount > 0) guardPosts[i] = true;
		else guardPosts[i] = false;
		guardPostsEditable[i] = guardPosts[i];
	}
	//
	int guardedCount = 0;
	for (int i = 2; i <= guardPostCount; i++)
	{
		if (guardPosts[i - 1] || guardPosts[i]) guardedCount++;

	}
	cout << guardedCount << endl;
	for (int i = 2; i <= guardPostCount; i++)
	{
		if (!guardPostsEditable[i - 1] && !guardPostsEditable[i])
		{
			sendGuard++;
			guardPostsEditable[i] = true;
		}

	}
	cout << sendGuard << endl;
	int firstUnsupIndex = 0;
	int i = 1;
	while (firstUnsupIndex == 0 && i < guardPostCount)
	{
		if (!guardPosts[i] && !guardPosts[i + 1]) firstUnsupIndex = i;
		i++;
	}
	cout << firstUnsupIndex << endl;

	/*for (int i = 2; i <= guardPostCount; i++)
	{
		if (guardPosts[i - 1] && guardPosts[i])
		{
			if (!inProtected)
			{
				inProtected = true;
				protectedStart = i - 1;
				protectedEnd = i;
			}
			else
			{
				protectedEnd = i;
			}

		}
		else
		{
			if (inProtected)
			{
				protectedEnd = i;
			}
		}
		if ((protectedEnd - protectedStart) > (maxProtectedEnd - maxProtectedStart))
		{
			maxProtectedEnd = protectedEnd;
			maxProtectedStart = protectedStart;
			maxProtectedCount = maxProtectedEnd - maxProtectedStart;
		}
	}*/
	bool inProtected;
	inProtected = false;
	int j = 2;
	while (j <= guardPostCount)
	{
		if (guardPosts[j] && guardPosts[j - 1])
		{
			protectedStart = j - 1;
			while (guardPosts[j] && j <= guardPostCount) j++;
			protectedEnd = j - 1;
			if ((protectedEnd - protectedStart) > (maxProtectedEnd - maxProtectedStart))
			{
				maxProtectedStart = protectedStart;
				maxProtectedEnd = protectedEnd;
			}
		}
		else j++;
	}
	if (maxProtectedEnd == 0) cout << "0";
	else
	{
		cout << maxProtectedStart << " " << maxProtectedEnd;
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
