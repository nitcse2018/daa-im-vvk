// Author: Vivek Kumar
// Roll no.: 181210060
// Branch: CSE 2nd Year(Group2)
// Topic: Dynamic Programming

/*Given a distance ‘dist, count total number of ways to cover the distance with
 1, 2 and 3 steps.
*/

// // A naive recursive C++ program to count number of ways to cover
// // a distance with 1, 2 and 3 steps
// #include <iostream>
// using namespace std;

// // Returns count of ways to cover 'dist'
// int printCountRec(int dist)
// {
//     // Base cases
//     if (dist < 0)
//         return 0;
//     if (dist == 0)
//         return 1;

//     // Recur for all previous 3 and add the results
//     return printCountRec(dist - 1) +
//            printCountRec(dist - 2) +
//            printCountRec(dist - 3);
// }

// // driver program
// int main()
// {
//     int dist = 4;
//     cout << printCountRec(dist);
//     return 0;
// }

// Dynamic programming approach

#include <iostream>
using namespace std;

int printCountDP(int dist)
{
    int count[dist + 1];

    // Initialize base values. There is one way to cover 0 and 1
    // distances and two ways to cover 2 distance
    count[0] = 1, count[1] = 1, count[2] = 2;

    // Fill the count array in bottom up manner
    for (int i = 3; i <= dist; i++)
        count[i] = count[i - 1] + count[i - 2] + count[i - 3];

    return count[dist];
}

int main()
{
    int dist = 4;
    cout << printCountDP(dist);
    return 0;
}
