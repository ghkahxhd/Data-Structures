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
