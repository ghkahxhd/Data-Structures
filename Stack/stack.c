#define MAX_STACK_SIZE  100 /* 스택의 최대 크기 */
typedef struct {
    int key;
    /* 다른 필드 */
} element;
element stack[MAX_STACK_SIZE];
int top = -1;

/* Boolean IsEmpty(Stack) ::= top < 0; */
/* Boolean IsFull(Stack) ::= top >= MAX_STACK_SIZE-1; */

/* 전역 stack에 item 삽입 */
void push (element item) {
    if (top >= MAX_STACK_SIZE-1)
        stackFull();

    stack[++top] = item;
}

/* stack의 최상위 원소를 삭제하고 반환 */
element pop() {
    if (top == -1)
        return stackEmpty();    /* returns an error key */

    return stack[top--];
}

void stackFull() {
    fprintf(stderr, "Stack is full, cannot add element.");
    exit (EXIT_FAILURE);
}

void stackEmpty() {
    fprintf(stderr, "Stack is empty, cannot delete element.")
    exit (EXIT_FAILURE);
}
