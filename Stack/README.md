# Stack
***
## 1. ADT
### 1.1. Objects
> 0개 이상의 원소를 가진 유한 순서 리스트

### 1.2. Functions
> 모든 stack ㅌ Stack, item ㅌ element, maxStackSize ㅌ positive integer

* **Stack CreateS(maxStackSize) ::=**  
```
최대 크기가 maxStackSize인 공백 스택을 생성.
```

* **Boolean IsFull(stack, maxStackSize) ::=**  
```
if (stack의 원소 수 == maxStackSize)
    return TRUE;
else
    return FALSE;
```

* **Stack Push(stack, item) ::=**  
```
if (IsFull(stack))  
    stackFull
else
    stack의 top에 item을 삽입하고 return;
```

* **Boolean IsEmpty(stack) ::=**
```
if (stack == CreateS(maxStackSize))
    return TRUE;
else
    return FALSE;
```

* **Element Pop(stack) ::=**
```
if (IsEmpty(stack))
    return;
else
    stack의 top의 item을 제거해서 반환.
```

## 2. Implementation

* Stack CreateS(maxStackSize) ::=  
```
#define MAX_STACK_SIZE  100 /* 스택의 최대 크기 */
typedef struct {
    int key;
    /* 다른 필드 */
} element;
element stack[MAX_STACK_SIZE];
int top = -1;
```

* Boolean IsEmpty(Stack) ::=
        top < 0;

* Boolean IsFull(Stack) ::=
        top >= MAX_STACK_SIZE-1;

* **push ::=**
```
/* 전역 stack에 item 삽입 */
void push (element item) {
    if (top >= MAX_STACK_SIZE-1)
        stackFull();

    stack[++top] = item;
}
```

* **pop ::=**
```
/* stack의 최상위 원소를 삭제하고 반환 */
element pop() {
    if (top == -1)
        return stackEmpty();    /* returns an error key */

    return stack[top--];
}
```

* stackFull() ::=
```
void stackFull() {
    fprintf(stderr, "Stack is full, cannot add element.");
    exit (EXIT_FAILURE);
}
```
