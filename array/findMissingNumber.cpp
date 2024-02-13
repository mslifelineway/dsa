#include <bits/stdc++.h>
using namespace std;

/*
    Definition: find missing number from 1 to N.
    N is not the size of the array. N is the max limit that from 1.
    Note: missing number will be only one.
    For Ex: arr = [1,3,4,5], and N = 5;
    Since, here length of the array is 4 which will be alway (N-1).

    Time complexity: O(N*N-1) almost O(N2)
    Space complexity: O(1)

    !!! This is WORST !!!
*/

void bruteForce(int *arr, int N)
{
    int missing = 0;
    for (int i = 1; i <= N; i++)
    {
        bool isFound = false;
        for (int j = 0; j < N - 1; j++)
        {
            if (arr[j] == i)
            {
                isFound = true;
                break;
            }
        }
        if (!isFound)
        {
            missing = i;
            break;
        }
    }
    cout << "Missing number is (brute force): " << missing << endl;
}

/*

    Time complexity: O(N2)
    Space complexity: O(N)

    !!! BETTER !!!
*/

void usingHash(int *arr, int N)
{
    int hash[N + 1] = {0};
    for (int i = 0; i < N - 1; i++)
    {
        hash[arr[i]] = 1;
    }

    int missing = 0;
    for (int i = 1; i <= N; i++)
    {
        if (hash[i] == 0)
        {
            missing = i;
            break;
        }
    }
    cout << "Missing number is (using hash method): " << missing << endl;
}

/*
    By using formula of natural number sum = (N * (N + 1))/2

    approach: sum all the elements and also sum N (using natural number formula)
    then subtract both to get the missing value.

    Time complexity: O(N)
    Space complexity: O(1)

    !!! OPTIMAL BUT JUST BEST !!!
*/
void usingNaturalNumber(int *arr, int N)
{
    int naturalSum = (N * (N + 1)) / 2;
    int sum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        sum += arr[i];
    }
    cout << "Missing number is (usingNaturalNumber) : " << naturalSum - sum << endl;
}

/*

    XOR => ex: 1 ^ 1  = 0; 2 ^ 2 = 0; 4 ^ 0 = 4;
    XOR of same number = 0 but XOR of 0 and a number = number;

    approach:
        create xor1 from 1 to N =
            if N = 5; then xor1 = 1 ^ 2 ^ 3 ^ 4 ^ 5;
        create xor2 from the give array xor2 = 1 ^ 2 ^ 3 ^ 4;

    !!! OPTIMAL AND BEST !!!
*/
void usingXor(int *arr, int N)
{
    /*
        Time complexity: O(N + (N-1)) almost O(2N)
        Space complexity: O(1)

        !! Best but not that much
    */
    int xor1 = 0;
    for (int i = 1; i <= N; i++)
    {
        xor1 ^= i;
    }
    int xor2 = 0;
    for (int i = 0; i < N - 1; i++)
    {
        xor2 ^= arr[i];
    }
    cout << "Missing number is (using xor) : " << (xor1 ^ xor2) << endl;

    /*
        ! LET'S MAKE MORE OPTIMAL

        Time complexity: O(N)
        Space complexity: O(1)
    */
    int xor3 = 0;
    int xor4 = 0;
    for (int i = 0; i < N - 1; i++)
    {
        xor3 ^= i + 1;
        xor4 ^= arr[i];
    }
    xor3 ^= N;
    cout << "Missing number is (using xor) : " << (xor3 ^ xor4) << endl;
}

int main()
{
    int N;
    cin >> N;
    int arr[N - 1];
    for (int i = 0; i < N - 1; i++)
    {
        cin >> arr[i];
    }

    bruteForce(arr, N);
    usingHash(arr, N);
    usingNaturalNumber(arr, N);
    usingXor(arr, N);

    return 0;
}