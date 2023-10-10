#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_N 300001
#define INF 100000
int graph[MAX_N][MAX_N]; // 그래프 표현을 인접 행렬로 사용
int shortestDistance[MAX_N];

int main()
{
    int n, m, k, x;
    scanf("%d %d %d %d", &n, &m, &k, &x);

    // 그래프 초기화
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = INF; // 모든 도로의 거리를 무한대로 초기화
        }
    }

    // 도로 정보 입력
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // 모든 도로의 길이를 1로 가정
    }

    // 출발 도시로부터의 최단 거리 배열 초기화
    for (int i = 1; i <= n; i++)
    {
        shortestDistance[i] = INF;
    }

    // 출발 도시에서 출발 도시로의 거리는 0으로 설정
    shortestDistance[x] = 0;

    // 최단 거리 계산
    for (int step = 1; step <= k; step++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                if (graph[u][v] != INF && shortestDistance[u] != INF && shortestDistance[u] + graph[u][v] < shortestDistance[v])
                {
                    shortestDistance[v] = shortestDistance[u] + graph[u][v];
                }
            }
        }
    }

    // 결과 출력
    bool found = false;
    for (int i = 1; i <= n; i++)
    {
        if (shortestDistance[i] == k)
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
