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

## 3.시스템 스택

프로그램은 함수가 호출될 때마다 활성 레코드(activation record) 또는 스택 프레임(stack frame)이라는 구조를 생성하고 이것을 시스템 스택의 톱에 둔다. 한 순간에는 하나의 함수만 수행될 수 있으므로, 시스템 스택의 톱에 있는 스택 프레임의 함수가 실행된다.  

초기에 호출된 함수의 활성 레코드는 이전 스택 프레임에 대한 포인터와 복귀주소만 가지고 있다. (포인터 -> 호출한 함수의 스택 프레임, 복귀 주소 -> 함수가 종료된 후 실행되어야 할 명령문 위치.)  
만약 이 함수가 다른 함수를 호출하면 static으로 선언된 변수를 제외한 지역 변수와 호출한 함수의 매개변수가 그의 스택 프레임에 추가된다. 그리고 호출한 함수의 새로운 스택 프레임이 생성되어 시스템 스택의 톱에 위치시킨다. 이 함수가 종료되면 시스템 스택에서 해당 스택 프레임이 삭제되고 새로 톱에 있는 호출한 함수의 수행이 계속된다.


## 4. 동적 배열을 사용하는 스택

* Stack CreateS() ::=
```
typedef struct {
    int key;
    /* 다른 필드들 */
} element;
element *stack;
Malloc(stack, sizeof(*stack));
int capacity = 1;
int top = -1;
```

* Boolean IsEmpty(Stack) ::=
```
top < 0;
```

* Boolean IsFull(Stack) ::=
```
top >= capacity-1;
```

* **stackFull() ::=**
```
void stackFull() {
    REALLOC(stack, 2 * capacity * sizeof(*stack));
    capacity *= 2;
}
```
최악의 경우, realloc 함수는 2\*capacity\*sizeof(\*stack)바이트의 메모리를 할당해야 하고 capacity\*sizeof(\*stack)바이트 메모리를 원래의 배열로부터 새로운 배열로 복사한다. O(capacity)  
모든 스택 삽입을 마쳤을 때 capacity가 2^k일 때, 배열 배가에 소모된 시간은 O(2^0 + 2^1 + ... + 2^k) = O(2^(k+1)) = O(2^k)이다. 전체 삽입 수는 2^(k-1)보다 크므로, n이 전체 삽입 수일 때 전체 시간은 O(n)이 된다.
