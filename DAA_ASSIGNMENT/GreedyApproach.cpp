// Author: Vivek Kumar
// Roll no.: 181210060
// Branch: CSE 2nd Year(Group2)
// Topic: Backtracking

/*A well known real life problem 
Given an amount, find the minimum number of notes of different denominations that sum 
upto the given amount. Starting from the highest denomination note, try to accommodate 
as many notes possible for given amount.

We may assume that we have infinite supply of notes of values 
{2000, 500, 200, 100, 50, 20, 10, 5, 1}*/

#include <bits/stdc++.h>
using namespace std;

void countCurrency(int amount)
{
    int notes[9] = {2000, 500, 200, 100,
                    50, 20, 10, 5, 1};
    int noteCounter[9] = {0};

    for (int i = 0; i < 9; i++)
    {
        if (amount >= notes[i])
        {
            noteCounter[i] = amount / notes[i];
            amount = amount - noteCounter[i] * notes[i];
        }
    }

    cout << "Currency Count ->" << endl;
    for (int i = 0; i < 9; i++)
    {
        if (noteCounter[i] != 0)
        {
            cout << notes[i] << " : "
                 << noteCounter[i] << endl;
        }
    }
}

int main()
{
    int amount = 956;
    countCurrency(amount);
    return 0;
}
