#include <bits/stdc++.h>;

using namespace std;

void findLargestNumber(int *arr, int n)
{
    if (n == 0 || n == 1)
        return;

    int values[2] = {arr[0], INT_MIN};

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > values[0])
        {
            values[1] = values[0];
            values[0] = arr[i];
        }
        else if (arr[i] > values[1])
        {
            values[1] = arr[i];
        }
    }
    cout << "Largest and second largest value: " << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << values[i] << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    findLargestNumber(arr, n);
    return 0;
}