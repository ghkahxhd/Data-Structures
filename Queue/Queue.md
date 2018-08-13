# Queue
***
## 1. ADT
### 1.1. Objects
> 0개 이상의 원소를 가진 유한 순서 리스트

### 1.2. Functions
> 모든 queue ㅌ Queue, item ㅌ element, maxQueueSize ㅌ positive integer

* **Queue CreateQ(maxQueueSize) ::=**  
```
최대 크기가 maxQueueSize인 공백 큐를 생성.
```

* **Boolean IsFullQ(queue, maxQueueSize) ::=**  
```
if (queue의 원소 수 == maxQueueSize)
    return TRUE;
else
    return FALSE;
```

* **Queue AddQ(queue, item) ::=**  
```
if (IsFullQ(queue))
    queueFull
else
    queue의 뒤에 item을 삽입하고 queue를 반환;
```

* **Boolean IsEmptyQ(queue) ::=**
```
if (queue == CreateQ(maxQueueSize))
    return TRUE;
else
    return FALSE;
```

* **Element DeleteQ(queue) ::=**
```
if (IsEmpty(queue))
    return;
else
    queue의 앞에 있는 item을 제거해서 반환.
```

## 2. Implementation

* Queue CreateQ(maxQueueSize) ::=
```
#define MAX_QUEUE_SIZE  100 /* 큐의 최대 크기 */
typedef struct {
    int key;
    /* 다른 필드 */
} element;
element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;
```
* Boolean IsEmptyQ(queue) ::= front == rear  

* Boolean IsFullQ(queue) ::= rear == MAX_QUEUE_SIZE=1;

* **큐에서의 삽입**
```
/* queue에 item을 삽입 */
void addq(element item) {
    if (rear == MAX_QUEUE_SIZE-1)
        queueFull();

    queue[++rear] = item;
}
```

* **큐에서의 삭제**
```
/* queue의 앞에 있는 원소를 삭제 */
element deleteq() {
    if (front == rear)
        return queueEmpty();    /* return an error key */

    return queue[++front];
}
```

## 3. 원형 큐
> 배열을 하나의 원으로 보면 위치 MAX_QUEUE_SIZE-1의 다음 위치는 0이고, 0의 앞 위치는 MAX_QUEUE_SIZE-1이다. 큐가 공백이 되면 front == rear가 되며, 큐가 만원이 될 때 도 front == rear가 된다. 이를 구별하기 위해서는 큐가 만원이 되기 전에 큐의 크기를 확장하면, front == rear일 때 큐는 공백이 된다.

* **원형 큐에서의 삽입**
```
/* queue에 item을 삽입 */
void addq(element item) {
    rear = (rear + 1) % MAX_QUEUE_SIZE;

    if (front == rear)
        queueFull();    /* print error and exit */

    queue[rear] = item;
}
```
> addq에서 만원에 대한 검사에서, 큐의 첫 번째 원소는 queue[front]에 있지 않고 시계 방향으로 한 위치 앞에 있다. 그렇기 때문에 실제로는 하나의 여유 공간 (queue[rear])이 있는 상태에서 queueFull()이 수행된다. 만원과 공백 상태를 구별하기 위해 항상 큐에는 MAX_QUEUE_SIZE-1개의 원소만 허용한다.

* **원형 큐에서의 삭제**
```
/* queue의 앞 원소를 삭제 */
element deleteq() {
    element item;
    if (front == rear)
        return queueEmpty();    /* return an error key */

    front = (front + 1) % MAX_QUEUE_SIZE;
}
```

## 4. 동적 배열을 이용하는 원형 큐

* 원형 큐 배열 확장  
정확한 원형 큐 구조를 얻기 위해서 두 번째 부분(queue[front+1]에서 queue[capacity-1] 사이에 있는 원소들)을 오른편으로 밀면 된다. 배열을 2배로 확장하고 원소를 오른편으로 미는 것을 다 합하면 최악의 경우 2 * capacity -2 원소를 복사하게 된다.

* 다음 방법으로 복사되는 원소 수를 capacity - 1로 제한할 수 있다.
    1. 크기가 2배인 새로운 배열 newQueue를 생성한다.
    2. 두 번째 부분(queue[front+1]에서 queue[capacity-1] 사이에 있는 원소들)을 newQueue의 0위치에서부터 복사하여 넣는다.
    3. 첫 번째 부분(queue[0]에서 queue[rear] 사이에 있는 원소들)을 newQueue의 capacity-front-1 위치에서부터 복사하여 넣는다.


* 원형 큐에서의 삽입
```
/* add an item to the queue */
void addq(element item) {
    rear = (rear + 1) % capacity;

    if (front == rear)
        queueFull();    /* double capacity */

    queue[rear] = item;
}
```

* **큐의 크기를 2배로 확장하는 queueFull**
```
void queueFull() {
    /* allocate an array with twice the capacity */
    element *newQueue;
    MALLOC(newQueue, 2 * capacity * sizeof(*queue));

    /* copy from queue to newQueue */
    int start = (front + 1) % capacity;
    if (start < 2)
        /* no wrap around */
        copy(queue+start, queue+start+capacity-1, newQueue);
    else {
        /* queue wraps around */
        copy(queue+start, queue+capacity, newQueue);
        copy(queue, queue+rear+1, newQueue+capacity-start);
    }

    /* switch to newQueue */
    front = 2 * capacity -1;
    rear = capacity - 2;
    capacity *= 2;
    free(queue);
    queue = newQueue;
}
```
