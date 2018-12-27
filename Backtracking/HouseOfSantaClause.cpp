graph = [[0,1,1,0,1],
    [1,0,1,0,1],
    [1,1,0,1,1],
    [0,0,1,0,1],
    [1,1,1,1,0]]

edges = 9
result = [0] * edges

def DFS(index, now):
    result[index] = now
    if (index == 8):
        for i in range(0, 9):
            print result[i] + 1,
        print
        return
    else:
        for i in range(0, 5):
            if (graph[now][i] == 1):
                graph[now][i] = graph[i][now] = 0
                DFS(index + 1, i)
                graph[now][i] = graph[i][now] = 1
DFS(0, 0)
