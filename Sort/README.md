# 1. 동기

* <h5> 순차 탐색
```
int seqSearch(element a[], int k, int n)
{ /* search a[1:n]; return the least i such that a[i].key = l;
                    return 0, if k is not in the array */
    int i;
    for (int i = 1; i <= n && a[i].key == k; i++)
        ;
    if (i > n)  return 0;
    return i;
}
```
최악의 경우, n번의 키 비교.  
평균 키 비교 횟수는 (n + 1)/2.

* <h5> 순차 탐색으로 정렬이 안 된 두 리스트를 검증
```
void verify1(element list1[], element list2[], int n, int m)
{ /* compare two unordered lists list1[1:n] and list2[1:m] */
    int i, j, marked[MAX_SIZE];

    for (i = 1; i <= m; i++)
        marked[i] = FALSE;
    for (i = 1; i <= n; i++) {
        if ((j = seqSearch(list2, m, list[i].key)) == 0)
            printf("%d is not in list2\n", list[i].key);
        else
        /* check each of the other fields from list1[i] and list[j],
            and print out any discrepancies */
            marked[j] = TRUE;
    }
    for (i = 1; i <= m; i++)
        if (!marked[i])
            printf("%d is not in list1\n", list2[i].key);
}
```
O(mn)

* <h5> 두 정렬된 리스트의 빠른 검증
```
void verify2(element list1[], element list2[], int n, int m)
{ /* same as verify1, but we sort list1 and list2 first */
    int i, j;
    sort(list1, n);
    sort(list2, m);

    i = j = 1;
    while (i <= n && j <= m) {
        if (list1[i].key < list2[j].key) {
            printf("%d is not in list2\n", list1[i].key);
            i++;
        }
        else if (list1[i].key == list2[j].key) {
        /* compare list1[i] and list2[j] on each of the other fields
            and report any discrepancies */
            i++; j++;
        }
        else {
            printf("%d is not in list1\n", list2[j].key);
            j++;
        }
    }

    for (; i <= n; i++)
        printf("%d is not in list2\n", list1[i].key);
    for (; j <= m; j++)
        printf("%d is not in list1\n", list2[i].key);
}
```
O(t-sort(n) + t-sort(m) + n + m)  
= O(max{n lgn, m lgm}) (t-sort가 O(n lgn) 시간에 정렬할 때)

# 2. 삽입 정렬

* <h5> 정렬된 리스트로 삽입
```
void insert(element e, elemenet a[], int i)
{ /* insert e into the ordered list a[1:i] such that the resulting list a[1:i+1] is also ordered,
    the array a must have space allocated for at least i+2 elements */

    a[0] = e;
    while (e.key < a[i].key) {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = e;
}
```
매번 삽입의 결과가 정렬된 리스트가 되므로 n개의 레코드를 가진 리스트는 n-1번 삽입함으로써 정렬할 수 있다.

* <h5> 삽입 정렬
```
void insertionSort(element a[], int n)
{ /* a[1:n]을 비감소 키 순서대로 정렬 */
    int j;
    for (j = 2; j <=n; j++) {
        element temp = a[j];
        insert(temp, a, j-1);
    }
}
```
insert(e, a, i)는 최악의 경우 삽입 전 i + 1번 비교해야 한다. 따라서 insert의 복잡도는 O(i).  
insertionSort의 복잡도는 O( sigma i=1 to n-1(i+1)) = O(n^2)

* 변형
 1. 이원 삽입 정렬: 순차 탐색 기법 대신 이원 탐색을 사용하면 비교 횟수를 줄일 수 있다. 레코드 이동 횟수는 변하지 않는다.  
 2. 연결 삽입 정렬: 리스트의 원소들을 배열이 아니라 연결 리스트로 표현.

 # 3. 퀵 정렬

* 퀵 정렬
```
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
```
 > 크기가 n인 리스트에서 한 레코드를 위치시키는 데 필요한 시간은 O(n)이다. n개의 레코드로 된 리스트를 정렬하는 데 소요되는 시간을 T(n)이라 하면, 한 레코드가 정확한 위치에 놓일 때마다 리스트가 거의 똑같은 크기의 두 부분으로 나누어진다.  
    T(n) <= cn + 2T(n/2) <= 2cn + 4T(n/4) <= ... <= cn lg(n) + nT(1) = O(n lg(n))  
한 레코드에 대해 하나의 공간만 추가로 필요로 하는 삽입 정렬과는 달리, 퀵 정렬은 recursion을 구현하기 위하여 스택 공간이 필요하다. 앞에서의 분석에서처럼 리스트가 균등하게 나누어지는 경우, 최대 순환 깊이는 lg(n)이 되어 스택 공간 O(lg(n))이 필요하다.

 > 최악의 경우 quickSort의 성능은 O(n^2)이다. (이미 정렬되어 있을 때)
    recursion의 각 단계에서, 크기가 n-1인 왼쪽 서브리스트와 크기가 0인 오른쪽 서브리스트로 리스ㅡ가 나누어지는 때. 이 경우 순환 깊이는 n이 되어 O(n) 스택 공간이 필요하다.

# 3. 병합 정렬
* 정렬된 두 리스트의 합병
```
void merge(element initList[], elemenet mergedList[], int i, int m, int n)
{ /* the sorted lists initList[i:m] and initList[m+1:n] are merged
    to obtain the sorted list mergedList[i:n];  */

    int j, k, t;
    j = m+1;    /* index for the second sublist */
    k = i;      /* index for the merged list */

    while (i <= m && j <= n) {
        if (initList[i].key <= initList[j].key)
            mergedList[k++] = initList[i++];
        else
            mergedList[k++] = initList[j++];
    }
    if (i > m)
    /* mergedList[k:n] = initList[j:n] */
        for (t = j; t <= n; t++)
            mergedList[t] = initList[t];
    else
    /* mergedList[k:n] = initList[i:m] */
        for (t = i; t <= m; t++)
            mergedList[t] = initList[t];
}
```
k는 n-i+1만큼 증가, 즉 while 루프는 n-i+1만큼 반복된다. for문은 최대 n-i+1 레코드를 복사한다. 그래서 총 시간은 O(n-i+1)이다. ( O(레코드 수) )  
각 레코드의 길이가 s이면, 연산 시간은 O(s(n-i+1))이다. s가 1보다 클 때 배열 대신 연결 리스트를 이용하면 이들 n-i+1 레코드를 포함한 새로운 정렬된 연결 리스트를 얻을 수 있다. n-i+1 레코드 공간 대신 포인터 공간만 필요하므로 합병 시간은 O(n-i+1)이 되어 s에 독립적이다.

### 3.1 Itreative Merge Sort
* 합병 패스
```
void mergePass(element initList[], element mergedList[], int n, int s)
{ /* perform one pass of the merge sort,
    merge adjacent pairs of sorted segments from initList[] into mergedList[],
    n is the number of elements in the list, s is the size of each sorted segment */
    int i, j;
    for (i = 1; i <= n - 2*s + 1; i += 2*s)
        merge(initList, mergedList, i, i + s - 1, i + 2 * s - 1);
    if (i + s - 1 < n)
        merge(initList, mergedList, i, i + s - 1, n);
    else
        for (j = i; j <= n; j++)
            mergedList[j] = initList[j];
}
```

* 합병 정렬
```
void mergeSort(element a[], int n)
{ /* sort a[1:n] using the merge sort method */

    int s = 1;  /* current segment size */
    element extra[MAX_SIZE];

    while (s < n) {
        mergePass(a, extra, n, s);
        s *= 2;
        mergePass(extra, a, n, s);
        s *= 2;
    }
}
```
1번째 패스에서는 크기가 1인 리스트를 합병, i번째 패스에서는 2^(i-1)인 리스트를 합병한다. 결과적으로 총 [lg(n), lg(n)+1) 단계가 데이타에 적용된다. 함수 merge와 같이 2개의 리스트에 대한 합병은 선형 시간에 이루어질 수 있으므로, 정렬 합병의 각 단계는 O(n) 시간이 걸린다.  
따라서 총 연산 시간은 O(n lg(n))이 된다.

### 3.2 Recursive Merge sort

* 순환 합병 정렬
```
int rmergeSort(element a[], int link[], int left, int right)
{ /* a[left:right] is to be sorted, line[i] is initially 0 for all i,
    returns the index of the first element in the sorted chain */

    if (left >= right)  return left;

    int mid = (left + right) / 2;
    return listMerge(a, link, rmergeSort(a, link, left, mid),   /* sort left half */
                            rmergeSort(a, link, mid+1, right)); /* sort right half */
}
```

* 정렬된 체인의 합병
```
int listMerge(element a[], int link[], int start1, int start2)
{ /* sorted chains beginnings at start1 and start2, respectively, are merged;
    link[0] is used as a temporary header; returns start of merged chain */

    int last1, last2, lastResult = 0;
    for (last1 = start1, last2 = start2; last1 && last2;) {
        if (a[last1] <= a[last2]) {
            link[lastResult] = last1;
            lastResult = last1; last1 = link[last1];
        }
        else {
            link[lastResult] = last2;
            lastResult = last2; last2 = link[last2];
        }
    }

    /* attach remaining records to result chain */
    if (last1 == 0)
        link[lastResult] = last2;
    else
        link[lastResult] = last1;

    return link[0];
}
```
