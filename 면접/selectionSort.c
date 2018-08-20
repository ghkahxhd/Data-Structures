void selectionSort(int arr[], int n)
{
    int min, temp;
    for (int i = 0; i < n-1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
                minIndex = j;
        }
        SWAP(arr[i], arr[minIndex], temp);
    }
}
