# Graph

## 정의
> 그래프 G는 2개의 집합 V와 E로 구성된다. V는 공집합이 아닌 정점(vertice)의 유한 집합이다. G는 정점 쌍들의 집합으로, 이러한 쌍을 간선(edge)라 한다. V(G)와 E(G)는 각각 그래프 G의 정점들의 집합과 간선들의 집합을 나타낸다. 임의의 그래프는 G=(V,E)로 표기할 수 있다.

* 경로
> 그래프 G에서 (u, i1), (i1, i2), ..., (ik, v)를 E(G)에 속한 간선들이라 할 때, 정점 u로부터 정점 v까지의 경로란 정점 순서 u, i1, i2, ..., ik, v를 말한다. 만약 G'가 방향 그래프이면 경로는 E(G')에 속한 간선들 <u, i1>, <i1, i2>, ..., <ik, v>로 구성된다. 한 경로의 길이는 경로상에 있는 간선의 수이다. 한 경로상에서 처음과 마지막을 제외한 모든 정점들이 서로 다를 때, 그 경로를 단순 경로(simple path)라 한다.

* 사이클
> 사이클은 처음과 마지막 정점이 같은 단순 경로이다.

* 연결
> 무방향 그래프 G에서 정점 u부터 v까지의 경로가 있다면, 두 정점 u와 v는 연결되었다고 한다. V(G)의 서로 다른 정점 u, v의 모든 쌍에 대해서도 u에서 v까지의 경로가 있으면, 그 무방향 그래프 G는 연결되었다고 한다. 무방향 그래프에서 연결 요소라는 것은 최대 연결 부분그래프를 말한다. 여기서 최대라는 말은 연결이 되어 있으면서 H를 포함하는 또 다른 부분그래프가 그래프 G에는 존재하지 않는다는 것을 의미한다.  
방향 그래프에서 V(G)에 속한 서로 다른 두 정점 u, v의 모든 쌍에 대해서, u에서 v로, 또한 v에서 u로의 방향 경로가 존재하면, 그 방향 그래프는 강하게 연결되었다고 한다. 강한 연결 요소란 강하게 연결된 최대 부분그래프를 말한다.

* 차수
> 한 정점의 차수란 그 정점에 부속한 간선들의 수를 말한다. 방향 그래프 G의 경우, 임의의 정점 v가 머리가 되는 간선들의 수를 정점 v의 진입 차수라 하고, v가 꼬리가 되는 간선들의 수를 정점 v의 진출 차수라 한다.

## 1. ADT Graph
### 1.1. Object
> a nonempty set of vertices and a set of undirected edges, where each edge is a pair of vertices.

### 1.2. Functions
> for all graph ㅌ Graph, v,v1,v2 ㅌ vertices

* Graph Create() ::=
```
return an empty graph.
```

* Graph InsertVertex(graph, v) ::=
```
return a graph with v inserted. v has no incident edges.
```

* Graph InsertEdge(graph, v1, v2) ::=
```
return a graph with a new edge between v1 and v2.
```

* Graph DeleteVertex(graph, v) ::=
```
return a graph in which v and all edges incident to it are removed.
```

* Graph DeleteEdge(graph, v1, v2) ::=
```
return a graph in which the edge (v1, v2) is removed.
Leave the incident nodes in the graph.
```

* Boolean IsEmpty(graph) ::=
```
if (graph == empty graph)
    return TRUE;
else
    return FALSE;
```

* List Adjacent(graph, v) ::=
```
return a list of all vertices that are adjacent to v.
```

## 3. 기본 연산

* 깊이 우선 탐색
```
void dfs(int v)
{ /* depth frist search of a graph beginning at v */
    nodePointer w;
    visited[v] = TRUE;
    printf("%5d", v);
    for (w = graph[v]; w; w = w->link)
        if (!visited[w->vertex])
            dfs(w->vertex);
}
```

* 너비 우선 탐색
```
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
```
