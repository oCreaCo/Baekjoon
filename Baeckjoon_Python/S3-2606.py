from queue import Queue

def main():
    global ans, adj_li, visited
    n = int(input())
    m = int(input())

    adj_li = [[] for _ in range(n)]
    visited = [False for _ in range(n)]

    li=[]
    for i in range(m):
        li = list(map(int, input().split()))
        adj_li[li[0] - 1].append(li[1] - 1)
        adj_li[li[1] - 1].append(li[0] - 1)

    BFS()
    print(ans)
    visited = [False for _ in range(n)]
    DFS()
    print(ans)
    return

def BFS():
    global ans, visited, adj_li
    ans = 0
    q = Queue()
    f=0
    q.put(0)
    visited[0] = True
    while(not q.empty()):
        f = q.get()
        for i in range(len(adj_li[f])):
            tmp = adj_li[f][i]
            if visited[tmp] == False:
                visited[tmp] = True
                q.put(tmp)
                ans += 1

    return

def DFS():
    global ans, visited, adj_li
    ans = -1
    s = [0]
    f = 0
    visited[0] = True
    while(len(s) != 0):
        f = s.pop()
        for i in range(len(adj_li[f])):
            tmp = adj_li[f][i]
            if visited[tmp] == False:
                visited[tmp] = True
                s.append(tmp)

        ans += 1
    return

ans = 0
adj_li = [[]]
visited = []

main()