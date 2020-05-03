
# create Input handle
def read_pair(handle):
    line = handle.readline()
    line = line.split()
    return (int(line[0]), int(line[1]))

# Depth First Search Definition
def dfs(adj, mark, u, order):
    mark[u] = True
    for v in adj[u]:
        if mark[v] == False:
            dfs(adj, mark, v, order)
    
    order.append(u)



handle = open('rosalind_topological.txt') # input as text file
n,m = read_pair(handle) # get n (# of vertices) and m (# of edges)
# print n,m

# Create adjacency List for graph
adj = [[] for u in range(n)]
for e in range(m):
    u, v = read_pair(handle)  # get input data
    adj[u - 1].append(v - 1)

order = []
mark = [False] * n  # mark vertices as False as initialization

# Run DFS
for u in range(n):
    if mark[u] == False:
        dfs(adj, mark, u, order)

order.reverse()
for u in order:
    print(u + 1),