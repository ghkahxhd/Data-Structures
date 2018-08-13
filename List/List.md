## 1. 단순 연결 리스트

> (1) 노드들은 실제로 순차적 위치에 존재하지 않는다.  
  (2) 노드들의 위치는 실행 시마다 바뀔 수 있다.  
  따라서 리스트를 사용하는 프로그램을 사용할 때, 0이라는 값을 검사하는 것 이외에는 절대로 특정한 주소를 찾지 않는다. 이를 단순 연결 리스트 또는 체인이라 한다. 단순 연결 리스트에서는 각 노드가 정확히 하나의 포인터 필드를 가지고 있다. 체인은 0개 이상의 노드를 포함하는 단순 연결 리스트이다. 노드의 수가 0이면 체인은 공백이다. 체인의 마지막 노드는 0을 가지고 있다.


리스트 생성  
```
typedef struct listNode *listPointer;
typedef struct {
  char data[4];
  listPointer link;
} listNode;

listPointer first = NULL;   /* 공백 리스트 생성 */
#define IS_EMPTY(first) (!(first))  /* 공백 리스트 검사 */

MALLOC(first, sizeof(*first));      /* 새로운 노드 생성 */
strcpy(first->data, "BAT");
first->link = NULL;
```

리스트의 노드 x 뒤에 삽입
```
void insert(listPointer *first, listPointer x)
{ /* data = 50인 새로운 노드를 체인 first의 노드 x 뒤에 삽입 */
    listPointer temp;
    MALLOC(temp, sizeof(*temp));
    temp->data = 50;
    if (*first) {
        temp->link = x->link;
        x->link = temp;
    }
    else {
        temp->link = NULL;
        *first = temp;
    }
}
```

리스트에서의 삭제  
```
void delete(listPointer *first, listPointer trail, listPointer x)
{ /* 리스트로부터 노드를 삭제, trail은 삭제될 x의 선행 노드이며 first는 리스트의 시작 */
    if (trail)
        trail->link = x->link;
    else
        *first = (*first)->link;
    free(x);
}
```

리스트의 출력
```
void printList(listPointer first)
{
    printf("The list contains: ");
    for (; first; first = first->link)
        printf("%4d", first->data);
    printf("\n");
}
```

## 2. 연결 스택과 큐

### 2.1 연결 스택
연결 스택 표현
```
#define MAX_STACKS 10   /*  스택의 최대 수 */
typedef struct {
    int key;
    /* 기타 필드 */
} element;

typedef struct stack *stackPointer;
typedef struct {
    element data;
    stackPointer link;
} stack;
stackPointer top[MAX_STACKS];
```

연결 스택에서의 삽입
```
void push(int i, element item)
{ /* i번째 스택에 원소를 삽입 */
    stackPointer temp;
    MALLOC(temp, sizeof(*temp));
    temp->data = item;
    temp->link = top[i];
    top[i] = temp;
}
```

연결 스택에서의 삭제
```
element pop(int i)
{ /* i번째 스택으로부터 톱 원소를 삭제 */
    stackPointer temp = top[i];
    element item;

    if (!temp)
        return stackEmpty();

    item = temp->data;
    top[i] = temp->link;
    free(temp);
    return item;
}
```

### 2.2 연결 큐
연결 큐 표현
```
#define MAX_QUEUES 10    /* 큐의 최대 수 */
typedef struct queue *queuePointer;
typedef struct {
    element data;
    queuePointer link;
} queue;

queuePointer front[MAX_QUEUES], rear[MAX_QUEUES];
```

연결 큐의 뒤에 삽입
```
void addq(i, item)
{ /* 큐 i의 뒤에 원소를 삽입 */
    queuePointer temp;
    MALLOC(temp, sizeof(*temp));
    temp->data = item;
    temp->link = NULL;

    if (front[i])
        rear[i]->link = temp;
    else
        front[i] = temp;

    rear[i] = temp;
}
```

연결 큐의 앞으로부터 삭제
```
element deleteq(int i)
{ /* 큐 i로부터 원소를 삭제 */
    queuePointer temp = front[i];

    if (!temp)
        return queueEmpty();

    element item = temp->data;
    front[i] = temp->link;
    free(temp);
    return item;
}
```

> n-스택, m-큐를 리스트로 구현하면 더 이상 공간을 만들기 위해 스택이나 큐를 이동시킬 필요 없이 가용 메모리가 남아 있을 때까지 실행을 계속할 수 있다. 비록 링크 필드를 위한 공간이 추가적으로 필요하지만 연결 리스트의 사용으로 발생하는 이 링크 공간에 대한 헤드는 (1) 간단한 방법으로 리스트를 표현할 수 있는 능력과, (2) 연결된 표현을 처리하기 위한 감소된 연산 시간과 같은 장점들에 의해 무시될 수 있다.

## 2.4 추가 리스트 연산

```
typedef struct listNode *listPointer;
typedef struct {
    char data;
    listPointer link;
} listNode;
```

단순 연결 리스트를 역순으로 만드는 함수
```
listPointer invert(listPointer lead)
{ /* lead가 가리키고 있는 리스트를 역순으로 만든다. */
    listPointer middle, trail;
    middle = NULL;

    while (lead) {
        trail = middle;
        middle = lead;
        lead = lead->link;
        middle->link = trail;
    }
    return lead;
}
```

단순 연결 리스트의 연결
```
listPointer concatenate(listPointer ptr1, listPointer ptr2)
{ /* 리스트 ptr1 뒤에 리스트 ptr2가 연결된 새로운 리스트를 생성한다.
    ptr1이 가리키는 리스트는 영구히 바뀐다. */

    listPointer temp;

    /* check for empty lists */
    if (!ptr1)  return ptr2;
    if (!ptr2)  return ptr1;

    /* 두 리스트가 공백이 아니면 첫 번째 리스트의 끝을 탐색 */
    for (temp = ptr1; temp->link; temp = temp->link)    ;

    /* 첫 번째 끝을 두 번째 시작에 연결 */
    temp->link = ptr2;
}
```

원형 연결 리스트의 앞에 삽입
```
void insertFront(listPointer *last, listPointer node)
{ /* 리스트의 마지막 노드가 last인 원형 리스트의 앞에 노드를 삽입한다. */
    if (!(*last)) {
        /* 리스트가 공백일 경우, last가 새로운 항목을 가리키도록 변경한다. */
        *last = node;
        node->link = node;
    }
    else {
        /* 리스트가 공백이 아닌 경우, 리스트의 앞에 새로운 항목을 삽입시킨다. */
        node->link = (*last)->link;
        (*last)->link = node;
    }
}
```

원형 리스트의 길이 계산
```
int length(listPointer last)
{ /* 원형 리스트 last의 길이를 계산한다. */
    listPointer temp;
    int count = 0;
    if (last) {
        temp = last;
        do {
            count++;
            temp = temp->link;
        } while(temp != last);
    }
    return count;
}
```
