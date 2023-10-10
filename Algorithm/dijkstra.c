#include <stdio.h>
#include <stdbool.h>

#define MAX_N 300001
#define MAX_M 1000001
#define INF 1e9

int graph[MAX_N][MAX_N]; // 인접 행렬로 그래프 표현
int dist[MAX_N];
bool visited[MAX_N];

void initGraph(int N)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            graph[i][j] = INF;
        }
    }
}

void addEdge(int u, int v)
{
    graph[u][v] = 1; // u에서 v로 가는 간선이 있다고 표시
}

void dijkstra(int N, int start)
{
    for (int i = 1; i <= N; i++)
    {
        dist[i] = INF;      // 모든 도시의 거리를 무한대로 초기화
        visited[i] = false; // 방문 여부 초기화
    }

    dist[start] = 0; // 시작 도시의 거리는 0

    for (int count = 1; count <= N; count++)
    {
        int minDist = INF;
        int u = -1;

        for (int i = 1; i <= N; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 1; v <= N; v++)
        {
            if (!visited[v] && graph[u][v] == 1 && dist[u] + 1 < dist[v])
            {
                dist[v] = dist[u] + 1;
            }
        }
    }
}

int main()
{
    int N, M, K, X;
    scanf("%d %d %d %d", &N, &M, &K, &X);

    initGraph(N);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    dijkstra(N, X);

    bool found = false;
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == K)
        {
            printf("%d\n", i);
            found = true;
        }
    }

    if (!found)
    {
        printf("-1\n");
    }

    return 0;
}
