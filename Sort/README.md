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
