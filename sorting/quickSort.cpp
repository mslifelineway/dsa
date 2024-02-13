#include <iostream>

using namespace std;

/*
    [ 5, 6, 8, 2, 1 , 3]

 step 1:   0th idx (5) =>    [2,1,3,5,6,8] -> return 3 as idx of correct position

  step 2:  [2,1,3] => [1,2,3] => 0th index as correct idx

  step 3: [5,6,8] ==> []




*/

int findPivotIndex(int *arr, int low, int high)
{
    int pivot = low;
    int i = low;
    int j = high;
    while (i < j)
    {

        while (arr[i] <= arr[pivot] && i < high)
        {
            i++;
        }
        while (arr[j] > arr[pivot] && j > low)
        {
            j--;
        }
        if (i < j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    int tmp = arr[low];
    arr[low] = arr[j];
    arr[j] = tmp;
    return j;
}
void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = low;
        int partition = findPivotIndex(arr, low, high);
        quickSort(arr, low, partition - 1);
        quickSort(arr, partition + 1, high);
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

    quickSort(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}