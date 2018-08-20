void quickSort(element a[], int left, int right)
{ /* sort a[left:right] into nondecreasing order on the key field;
        a[left].key is arbitrarily chosen as the pivot key;
        it is assumed that a[left].key <= a[right+1].key */

    int pivot, i, j;
    element temp;

    if (left < right) {
        i = left; j = right+1;
        pivot = a[left.key];
        do { /* search for keys from the left and right sublists,
                swapping out-of-order elements until the lefts and right boundaries cross or meet */
            do i++; while (a[i].key < pivot);
            do j--; while (a[j].key > pivot);
            if (i < j)
                SWAP(a[i], a[j], temp);
        } while (i < j);
        SWAP(a[left], a[j], temp);
        quickSort(a, left, j-1);
        quickSort(a, j+1, right);
    }
}
