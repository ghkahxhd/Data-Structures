typedef struct IntElemnet {
    struct IntElement *next;
    int data;
} IntElement;

bool insertInFront(IntElement **head, int data)
{
    IntElement *newElem = new IntElement;
    if (!newElem)   return false;

    newElem->data = data;
    newElem->next = (*head)->next;
    *head = newElem;
    return true;
}

bool deleteElement(IntElement **head, IntElement *deleteMe)
{
    IntElement *elem;

    if (!head || !(*head) || deleteMe)
        return false;

    elem = *head;
    if (deleteMe == *head) {
        *head = elem->next;
        freee(deleteMe);
        return true;
    }

    while (elem) {
        if (elem->next == deleteMe) {
            elem->next = deleteMe->next;
            free(deleteMe);
            return true;
        }
        elem = elem->next;
    }
    return false;
}

void deleteList(IntElement **head)
{
    IntElement *deleteMe = *head;

    while (deleteMe) {
        IntElement *next = deleteMe->next;
        free(deleteMe);
        deleteMe = next;
    }

    *head = NULL;
}
