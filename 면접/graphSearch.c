void dfs(int v)
{ /* depth frist search of a graph beginning at v */
    nodePointer w;
    visited[v] = TRUE;
    printf("%5d", v);
    for (w = graph[v]; w; w = w->link)
        if (!visited[w->vertex])
            dfs(w->vertex);
}

void bfs(int v)
{ /* breadth first traversal of a graph,
    starting at v the global array visited is initialized to 0 */

    nodePointer w;
    front = rear = NULL;    /* initialized queue */
    printf("%5d", v);
    visited[v] = TRUE;
    addq(v);

    while (front) {
        v = deleteq();
        for (w = graph[v]; w; w = w->link) {
            if (!visited[w->vertex]) {
                printf("%5d", w->vertex);
                addq(w->vertex);
                visited[w->vertex] = TRUE;
            }
        }
    }
}
