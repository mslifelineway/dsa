#include <bits/stdc++.h>
using namespace std;

/*
-------------------
    input.txt
    ---------
5
1 3 2 1 3
5
1
4
2
3
12
----------------------
    OUTPUT
    ------
2
0
1
2
0

------------------------
*/

/**
     5 ---> size of the list
    1 3 2 1 3 ---> elements in the list
    5 --> Number of testcase or Number of queries to check the occurance. 4,2,3,12
    1
    4
    2
    3
    12
*/
int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // let assume max value can be 12. This will be given in the problem statement
    // Assign 0 to all the indices
    int hash[13] = {0};

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    // Queries
    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;
        cout << hash[number] << endl;
    }

    return 0;
}