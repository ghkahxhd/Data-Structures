typedef struct Element {
    struct Element *next;
    void *data;
} Element;

bool push(Element **stack, void *data);
bool *pop(Element **stack, void **data);

bool createStack(Element **stack);
bool deleteStack(Element **stack);

bool createStack(Element **stack)
{
    *stack = NULL;
    return true;
}

bool deleteStack(Element **stack)
{
    Element *next;
    while (*stack) {
        next = (*stack)->next;
        free(stack);
        (*stack) = next;
    }
    return true;
}

bool push(Element **stack, void *data)
{
    Element *elem = new Element;
    if (!elem)  return false;

    elem->data = data;
    elem->next = *stack;
    *stack = elem;
    return true;
}

bool pop(Element **stack, void **data)
{
    Element *elem = *stack;
    if (!elem) return false;

    *stack = elem->next;
    *data = elem->data;
    free(elem);
    return true;
}
