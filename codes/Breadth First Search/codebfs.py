# Name: Akshay Jain Reg No: 17BCS002
# Implementing Breadth First Seach (BFS) on a Given Input of graph
# Graph input is taken with root node as 0 using Dictionary in Python3
# This code is open for use for everyone

import collections
def bfs(graph, root):
    visited, queue = set(), collections.deque([root])
    visited.add(root)
    result = list()
    result.append(root)
    while queue:
        vertex = queue.popleft()
        for neighbour in graph[vertex]:
            if neighbour not in visited:
                result.append(neighbour)
                visited.add(neighbour)
                queue.append(neighbour)
    return result
if __name__ == '__main__':
    graph = {0: [1, 2, 4], 1: [4,6], 2: [0], 3: [4,5], 4:[0,1,3,5,9], 5:[3,4,7], 6:[1], 7:[5,8], 8:[7,9], 9:[4,8]}
    path = bfs(graph, 0)
    print("One Path from root node using Breadth First Search is {}".format(path))
