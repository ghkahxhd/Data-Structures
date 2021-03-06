# Tree

## 1. 정의
> 트리는 1개 이상의 노드로 이루어진 유한 집합으로서,  
    (1) 노드 중에는 루트 노드가 하나 있고,  
    (2) 나머지 노드들은 n (>=0)개의 분리 집합 T1, ..., Tn으로 분할될 수 있다. 여기서 T1, ..., Tn은 각각 하나의 트리이며 루트의 서브트리라고 한다.

* 노드(node): 한 정보 아이템에 다른 노드로 뻗어진 가지를 합친 것.
* 차수(degree): 한 노드의 서브트리의 수.
* 트리의 차수: 그 트리에 있는 노드의 최대 차수.

* 노드의 레벨: 루트의 레벨을 1, 한 노드의 레벨이 l이면 자식의 레벨은 l+1
* 트리의 높이, 깊이: 그 트리에 속한 노드의 최대 레벨.

* 리프(left), 단말 노드(terminal node): 차수가 0인 노드.
* 비단말 노드(non-terminal node)

## 2. 트리의 표현
#### 2.1 리스트 표현

* 차수가 k인 트리에 대한 노드 구조  
트리 노드의 데이터와 그 노드의 자식들에 대한 포인터를 위한 필드를 가지고 있는 메모리 노드로 트리 노드를 표현. 각 노드의 차수가 서로 다를 수 있으므로 포인터 필드의 수가 가변적인 메모리 노드를 사용해야 한다. 하지만 실제 트리 노들를 표현하기 위해서는 고정 크기의 노드를 사용해야한다.
> 만일 T가 차수가 k이고 노드 수가 n일 때, nk개의 자식 필드 중 n(k-1) + 1개의 필드(n>=1)는 0이다.

* ##### left child-right sibling

* ##### left child-right child
left child-right sibling 표현에서 오른쪽 형제 포인터를 45도 가량 시계 방향으로 돌리면 된다.

***
# Binary Tree
> 이진 트리는 공백이거나 루트와 왼쪽 서브트리, 오른쪽 서브트리라고 하는 2개의 분리된 이진 트리로 구성된 노드의 유한 집합이다.

## 1. ADT Binary_Tree
### 1.1. Object
> 공백이거나 루트 노드, 왼쪽 Binary_Tree, 오른쪽 Binary_Tree로 구성되는 노드들의 유한 집합.

### 1.2. Functions
> 모든 bt, bt1, bt2 ㅌ BinTree, item ㅌ element

* BinTree Create() ::=
```
공백 이진 트리를 생성.
```

* Boolean IsEmpty(bt) ::=
```
if (bt == 공백 이진 트리)
    return TRUE;
else
    return FALSE;
```

* **BinTree MakeBT(bt1, item, bt2) ::=**
```
왼쪽 서브트리가 bt1, 오른쪽 서브트리가 bt2, 루트는 item을 갖는 이진 트리를 반환
```

* **BinTree LChild(bt) ::=**
```
if (IsEmpty(bt))
    return ERROR;
else
    return bt의 왼쪽 서브트리;
```

* **element Data(bt) ::=**
```
if (IsEmpty(bt))
    return ERROR;
else
    return bt의 루트에 있는 데이터.
```

## 2. 이진 트리의 성질

* 최대 노드 수
> (1) 이진 트리의 레벨 i에서의 최대 노드 수는 2^(i-1) (i>=1)이다.  
  (2) 깊이가 k인 이진 트리의 최대 노드 수는 2^k-1 (k>=1)이다.

  (1) 귀납법으로 증명.  
  (2) =  sigma i=1 to k (레벨 i의 최대 노드 수) = 2^0 + 2^1 + ... + 2^(k-1) = 2^k - 1

* 리프 노드 수와 차수가 2인 노드 수와의 관계
> 공백이 아닌 모든 이진 트리 T에 대하여, n0는 리프 노드 수, n2는 차수가 2인 노드 수라 하면 n0 = n2 + 1이다.  

  n = n0 + n1 + n2  
  총 가지 수를 B라 하면 n = B + 1이 성립한다. 또한 모든 가지들은 차수가 2 또는 1인 노드에서부터 뻗어나오므로 B = n1 + 2 n2가 성립한다.  
  따라서 n = B + 1 = n1 + 2  n2 + 1 -> n0 = n2 + 1이다.

* 포화 이진 트리
> 깊이가 k인 포화 이진 트리(full binary tree)는 깊이가 k이고 노드 수가 2^k-1 (k>=0)인 이진 트리이다.

* 완전 이진 트리
> 깊이가 k이고 노드 수가 n인 이진 트리의 각 노드들이 깊이 k인 포화 이진 트리에서 1부터 n까지의 번호를 붙인 노드들과 1대1로 일치한다면, 이 트리는 완전 이진 트리(complete binary tree)이며 그 역도 성립한다.

## 3. 이진 트리의 표현

* 배열 표현 (n개의 노드를 가진 완전 이진 트리)
> (1) i != 1이면 parent(i)는 (i/2] 위치에 있다. 만일 i=1이면 i는 루트이므로 부모가 없다.  
  (2) 2i <= n이면 leftChild(i)는 2i의 위치에 있다.  
  (3) 2i + 1 <= n이면 rightChild(i)는 2i+1의 위치에 있다.  
  // (2),(3) 2i > n, 2i + 1 > n이면 i는 왼쪽, 오른쪽 자식이 없다.

* 링크 표현
```
typedef struct node *treePointer;
typedef struct {
    int data;
    treePointer leftChild, rightChild;
} node;
```

## 4. 이진 트리 순회

* 이진 트리의 중위 순회
```
void inorder(treePointer ptr) {
    if (ptr) {
        inorder(ptr->leftChild);
        printf("%d ", ptr->data);
        inorder(ptr->rightChild);
    }
}
```

* 이진 트리의 전위 순회
```
void preorder(treePointer ptr) {
    if (ptr) {
        printf("%d ", ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}
```

* 이진 트리의 후위 순회
```
void postorder(treePointer ptr) {
    if (ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf("%d ", ptr->data);
    }
}
```

* 반복적 중위 순회
> 트리의 노드 수를 n이라고 할 때, iterInorder를 살펴보면, 트리의 모든 노드들은 스택에 꼭 한 번씩 삽입된다. 그러므로 트리의 노드 수가 n이면 시간 복잡도는 O(n)이다. 저장 공간은 트리의 깊이 O(n)만큼 필요하다.  

 ```
void iterInorder(treePointer node) {
    int top = -1;   /* 스택 초기화 */
    treePointer stack[MAX_STACK_SIZE];

    for (;;) {
        for (; node; node = node->leftChild)
            push(node); /* 스택에 삽입 */
        node = pop();   /* 스택에서 삭제 */
        if (!node)  break;  /* 공백 스택 */

        printf("%d", node->data);
        node = node->rightChild;
    }
}
```

* 이진 트리의 레벨 순서 순회
```
void levelOrder(treePointer ptr) {
    int front = rear = 0;
    treePointer queue[MAX_QUEUE_SZIE];
    if (!ptr)   return; /* 공백 트리 */

    addq(ptr);
    for (;;) {
        ptr = deleteq();
        if (ptr) {
            printf("%d", ptr->data);
            if (ptr->leftChild)
                addq(ptr->leftChild);
            if (ptr->rightChild)
                addq(ptr->rightChild);
        }
        else
            break;
    }
}
```

## 4. 이진 트리의 추가 연산

이진 트리의 복사
```
treePointer copy(treePointer original)
{ /* 주어진 트리를 복사하고 복사된 트리의 treePointer를 반환한다. */
    treePointer temp;
    if (original) {
        MALLOC(temp, sizeof(*temp));
        temp->leftChild = copy(original->leftChild);
        temp->rightChild = copy(original->rightChild);
        temp->data = original->data;
        return temp;
    }
    return NULL;
}
```

동일성 검사
```
int equal(treePointer first, treePointer second)
{ /* 두 이진 트리가 동일하면 TRUE, 그렇지 않으면 FALSE를 반환한다. */
    return ((!first && !second) ||
                (first && second &&
                (frist->data == second->data) &&
                eqaul(first->leftChild, second->leftChild) &&
                equal(first->rightChild, second->rightChild));
}
```

## 6. 힙
> 히프는 우선순위 큐를 구현하는 데 자주 사용된다. 우선순위 큐에서는 우선순위가 가장 높은 원소를 먼저 삭제한다. 또 언제든지 임의의 우선순위를 가진 원소를 우선순위 큐에 삽입할 수 있다.

> 우선순위 큐를 표현하는 가장 간단한 방법은 무순서 선형 리스트로 표현하는 것.  
  - isEmpty 함수는 O(1), top() 함수는 O(n) 시간.
  - 삽입은 어디에 원소가 삽입되든 관계가 없으므로 push는 O(1) 시간.
  - 삭제는 최대 우선순위를 가진 원소를 찾아야 하고 삭제해야되기 때문에 pop은 O(n) 시간.
## ADT MaxPriorityQueue
### Objects
> a collection of n>0 elements, each element has a key

### Functions
> for all q ㅌ MaxPriorityQueue, item ㅌ Element, n ㅌ integer  

* MaxPriorityQueue create(max_size) ::=
```
create an empty priority queue.
```

* Boolean isEmpty(q, n) ::=
```
if (n > 0)
    return TRUE;
else
    return FALSE;
```

* Element top(q, n) ::=
```
if (!isEmpty(q, n))
    return an instance of the largest element in q;
else
    return error;
```

* Element pop(q, n) ::=
```
if (!isEmpty(q, n))
    return an instance of the largest element in q and remove it from the heap;
else
    return error;
```

* MaxPriorityQueue push(q, item, n) ::=
```
insert item into q and return the resulting priority queue.
```


### 최대 히프
> 최대 트리는 각 노드의 키 값이 그 자식의 키 값보다 작지 않은 트리이다. 최대 히프는 최대 트리이면서 완전 이진 트리이다. 또 최소 히프는 최소 트리이면서 완전 이진 트리이다.  
최대 히프로 우선순위 큐를 표현하면 isEmpty와 top의 복잡도는 O(1)이고, push와 pop은 O(lg(n))이다.

```
#define MAX_ELEMENTS 200    /* 최대 히프 크기 + 1 */
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)
typedef struct {
    int key;
    /* 다른 필드들 */
} element;
element heap[MAX_ELEMENTS];
int n = 0;
```

* 최대 히프에 삽입
```
void push(element item, int *n)
{ /* insert item into a max heap of current size *n */
    int i;
    if (HEAP_FULL(*n)) {
        fprintf(stderr, "The heap is full. \n");
        exit(EXIT_FAILURE);
    }
    i = ++(*n);
    while ((i != 1) && (item.key > heap[i/2].key)) {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}
```
히프는 n개의 원소를 갖는 완전 이진 트리이므로 높이는 [lg(n+1), lg(n+1)+1)이다. 이는 while 루프가 O(lg(n))만큼 반복됨을 의미한다. 그러므로 삽입 함수의 복잡도는 O(lg(n))이다.

* 최대 히프에서의 삭제
```
element pop(int *n)
{ /* delete element with the highest key from the heap */
    int parent, child;
    element item, temp;
    if (HEAP_EMPTY(*n)) {
        fprintf(stderr, "The heap is empty\n");
        exit(EXIT_FAILURE);
    }

    /* save value of the element with the highest key */
    item = heap[1];

    /* use last element in heap to adjust heap */
    temp = heap[(*n)--];
    parent = 1;
    child = 2;
    while (child <= *n) {
        /*find the larger child of the current parent */
        if ((child <= *n) && (heap[child].key <= heap[child+1].key))
            child++;
        if (temp.key >= heap[child].key)
            break;
        /* move to the next lower level */
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}
```
히프가 재구성될 때까지 히프의 아래 방향으로 이동하면서 부모 노드와 자식 노드를 비교하고 교환한다. n개의 원소를 가진 히프의 높이는 [lg(n+1), lg(n+1)+1)이므로 while 루프는 O(lg(n))번 반복된다. 그러므로 삭제의 복잡도는 O(lg(n))이다.

## 7. 이원 탐색 트리
> 이원 탐색 트리는 탐색, 삽입, 삭제, 연산에 있어서 어떤 자료구조보다도 성능이 좋다.
  이원 탐색 트리는 이진 트리로서 공백일 수 있다. 만약 공백이 아니라면 다음 성질을 만족한다.
1. 모든 원소는 키를 가지며, 어떤 두 원소도 동일한 키를 갖지 않는다. (즉, 모든 키는 상이하다.)
2. 왼쪽 서브트리에 있는 키들은 (만약 있다면) 그 루트의 키보다 작다.
3. 오른쪽 서브트리에 있는 키들은 (만약 있다면) 그 루트의 키보다 크다.
4. 왼쪽과 오른쪽 서브트리도 모두 이원 탐색 트리이다.

## ADT Dictionary
> Dictionary는 쌍의 집합으로서, 각 쌍은 키와 이에 연관된 원소로 구성된다. 여기서는 같은 키를 가진 2개의 쌍은 없다고 가정한다.
### Objects
> a collection of n>0 pairs, each pair has a key and an associated item
### Functions
> for all d ㅌ Dictionary, item ㅌ Item, k ㅌ Key, n ㅌ integer

* Dictionary Crea(max_size) ::=
```
create an empty dictionary.
```

* Boolean IsEmpty(d, n) ::=
```
if (n > 0)
    return TRUE;
else
    return FALSE;
```

* Element Search(d, k) ::=
```
return item with key k,
return NULL if no such element.
```

* Element Delete(d, k) ::=
```
delete and return item (if any) with key k.
```

* void Insert(d, item, k) ::=
```
insert item with key k into d.
```
***

* 이원 탐색 트리의 순환적 탐색
```
element* search(treePointer tree, int key)
{ /* key 값이 k인 노드에 대한 포인터를, 그런 노드가 없는 경우 NULL을 반환 */
    if (!tree)
        return NULL;

    if (k == tree->data.key)
        return &(tree->data);

    if (k < tree->data.key)
        retrun search(tree->leftChild, k);

    return search(tree->rightChild, k);
}
```

* 이원 탐색 트리의 반복적 탐색
```
element* iterSearch(treePointer tree, int k)
{ /* key 값이 k인 노드에 대한 포인터를, 그런 노드가 없는 경우 NULL을 반환 */
    while (tree) {
        if (k == tree->data.key)
            return &(tree->data);
        if (k < tree->data.key)
            tree = tree->leftChild;
        else
            tree = tree->rightChild;
    }
    return NULL;
}
```
만약 높이가 h인 이진 탐색 트리에 대해 O(h) 시간 내에 탐색을 수행할 수 있다. search 함수의 경우 O(h)의 추가적인 스택 공간을 사용한다.

* 이원 탐색 트리에 사전 쌍의 삽입
```
void insert(treePointer *node, int k, iType theItem)
{ /* 트리 내 노드가 k를 가리키고 있으면 아무 일도 하지 않음;
    그렇지 않은 경우는 data = (k, theItem)인 새 노드를 첨가 */

    /* modifiedSearch: *node에서 키 값 k를 탐색,
    트리가 공백이거나 k가 존재하면 NULL을 반환,
    그렇지 않으면 마지막으로 검사한 노드에 대한 포인터 반환 */
    treePointer ptr, temp = modifiedSearch(*node, k);
    if (temp || !(*node)) {
        /* k is not in the tree */
        MALLOC(ptr, sizeof(*ptr));
        ptr->data.key = k;
        ptr->data.item = theItem;
        ptr->leftChild = ptr->rightChild = NULL;

        if (*node) /* insert as child of temp */
            if (k < temp->data.key) temp->leftChild = ptr;
            else temp->rightChild = ptr;
        else
            *node = ptr;
    }
}
```
높이 h인 트리에서 k를 탐색하는 데 필요한 시간은 O(h)이고 알고리즘의 나머지 부분은 O(1)의 시간을 필요로 한다. 그러므로 insert가 필요한 전체 시간은 O(h)이다.
