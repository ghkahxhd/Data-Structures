bool push(Heap *heap, element item)
{ /* insert item into a max heap */
    element *arr = heap->arr;

    if (HEAP_FULL(heap))
        return false;

    int i = ++(heap->cnt);
    while (i != 1 && (item.key > arr[i/2].key)) {
        arr[i] = arr[i/2];
        i /= 2;
    }
    arr[i] = item;
    return true;
}

bool pop(Heap *heap, element *item)
{
    element *arr = heap->arr;

    if (HEAP_EMPTY(heap))
        return false;

    int i = 1;
    *item = arr[1];
    i
    arr[1] = arr[heap->cnt--];
    while (i < heap->cnt) {
        int max = i;
        if (i*2 <= heap->cnt && arr[max] < arr[i*2])
            max = i*2;
        if (i*2 < heap->cnt && arr[max] > arr[i*2+1])
            max = i*2+1;
        if (max == i)
            break;

        SWAP(arr[i], arr[max], t);
        i = max;
    }

    return true;
}
