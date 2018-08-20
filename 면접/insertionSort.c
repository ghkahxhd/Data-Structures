void insertionSort(int arr[], int n)
{
    int i, j;
    for (i = 1; i < n; i++) {
        int temp = arr[i];
        for (j = i - 1; j >= 0; j--) {
            if (temp < arr[j])
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j+1] = temp;
    }
}
