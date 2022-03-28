from queue import Queue

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

n, m = map(int, input().split())

plane = [[] for _ in range(n)]
for i in range(n):
    plane[i] = list(map(int, input().split()))

visited = [[0 for _ in range(n)]for _ in range(m)]

time = 0
cheese = 0

def BFS(sx, sy):
    global time, cheese, dx, dy
    
    return

