#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>

#define MAX_NODES 300001 // 최대 노드 수에 맞게 조절
#define INF 1e9

int graph[MAX_NODES][MAX_NODES]; // 그래프를 인접 행렬로 표현
int distance[MAX_NODES];         // 시작 노드로부터의 최단 거리를 저장하는 배열

void dijkstra(int start, int N)
{
    int visited[MAX_NODES] = {0}; // 방문 여부를 나타내는 배열

    // 모든 노드의 최단 거리를 무한대로 초기화
    for (int i = 1; i <= N; i++)
    {
        distance[i] = INF;
    }

    // 시작 노드의 최단 거리를 0으로 초기화
    distance[start] = 0;

    // 모든 노드를 순회
    for (int i = 0; i < N; i++)
    {
        // 현재까지 방문하지 않은 노드 중에서 최단 거리가 가장 짧은 노드를 찾음
        int min_distance = INF;
        int min_node = -1;
        for (int j = 1; j <= N; j++)
        {
            if (!visited[j] && distance[j] < min_distance)
            {
                min_distance = distance[j];
                min_node = j;
            }
        }

        // 최단 거리 노드를 방문 처리
        visited[min_node] = 1;

        // 최단 거리 노드를 거쳐서 갈 수 있는 노드의 최단 거리를 갱신
        for (int j = 1; j <= N; j++)
        {
            if (graph[min_node][j] != 0 && !visited[j])
            {
                if (distance[min_node] + graph[min_node][j] < distance[j])
                {
                    distance[j] = distance[min_node] + graph[min_node][j];
                }
            }
        }
    }
}

int main()
{
    int N, M, K, X;
    scanf("%d %d %d %d", &N, &M, &K, &X);

    // 그래프 초기화
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            graph[i][j] = 0;
        }
    }

    // 간선 정보 입력
    for (int i = 0; i < M; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1; // 간선 정보 입력 (방향 그래프)
    }

    // 다익스트라 알고리즘 호출
    dijkstra(X, N);

    // 최단 거리가 K인 노드 출력
    int found = 0;
    for (int i = 1; i <= N; i++)
    {
        if (distance[i] == K)
        {
            printf("%d\n", i);
            found = 1;
        }
    }

    if (!found)
    {
        printf("-1\n"); // K인 거리의 노드를 찾지 못한 경우
    }

    return 0;
}
