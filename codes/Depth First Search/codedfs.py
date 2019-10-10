# Name: Akshay Jain Reg No: 17BCS002
# Implementing Depth First Seach (DFS) on a Given Input of graph
# Graph input is taken with root node as 0 using Dictionary in Python3
# This code is open for use for everyone

from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def DFSUtil(self, v, visited):
        visited[v] = True
        print(v, end = " ")

        for i in self.graph[v]:
            if visited[i] == False:
                self.DFSUtil(i, visited)

    def DFS(self, v):
        visited = [False] * (len(self.graph))
        self.DFSUtil(v, visited)

g = Graph()
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(0, 4)
g.addEdge(1, 4)
g.addEdge(1, 6)
g.addEdge(2, 0)
g.addEdge(3, 4)
g.addEdge(3, 5)
g.addEdge(4, 0)
g.addEdge(4, 1)
g.addEdge(4, 3)
g.addEdge(4, 5)
g.addEdge(4, 9)
g.addEdge(5, 3)
g.addEdge(5, 4)
g.addEdge(5, 7)
g.addEdge(6, 1)
g.addEdge(7, 5)
g.addEdge(7, 8)
g.addEdge(8, 7)
g.addEdge(8, 9)
g.addEdge(9, 4)
g.addEdge(9, 8)


print("Following is DFS for the given Graph starting from vertex 0")
g.DFS(0)
