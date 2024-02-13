#include <iostream>

using namespace std;

void bubbleSort(int *arr, int n)
{
    for (int i = n; i > 0; i--)
    {
        bool didSwap = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                didSwap = true;
            }
            if (!didSwap)
                true;
        }
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

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}