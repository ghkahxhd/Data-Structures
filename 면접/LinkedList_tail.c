bool delete(Element *elem)
bool insertAfter(Element *elem, int data);


bool delete(Element *elem)
{
    if (!elem)
        return false;

    if (elem == head) {
        head = elem->next;
        free(elem);
        if (!head)
            tail = NULL;
        return true;
    }

    Element *curPos = head;
    while (curPos)
        if (curPos->next == elem) {
            curPos->next = elem->next;
            free(elem);
            if (curPos->next == NULL)
                tail = curPos;
            return true;
        }
        curPos = curPos->next;
    }

    return false;
}

bool insertAfter(Element *elem, int data)
{
    Element *newElem = (Element *)malloc(sizeof(Element));
    if (!newElem)
        return false;
    newElem->data = data;

    if (!elem) {
        newElem->next = head;
        head = newElem;
        if (!tail)
            tail = newElem;
        return true;
    }

    Element *curPos = head;
    while (curPos) {
        if (curPos == elem) {
            newElem->next = curPos->next;
            curPos->next = newElem;
            if (!(newElem->next))
                tail = newElem;
            return true;
        }
        curPos = curPos->next;
    }
    free(newElem);
    return false;
}
