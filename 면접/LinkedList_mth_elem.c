ListElement *findMToLastElement(ListElement *head, int m)
{
    ListElement *current, *mBehind;
    if (!head)
        return NULL;

    current = head;
    for (int i = 0; i < m; i++) {
        if (current->next)
            current = current->next;
        else
            return NULL;
    }

    mBehind = head;
    while (current->next) {
        current = current->next;
        mBehind = mBehind->next;
    }

    return mBehind;
}
