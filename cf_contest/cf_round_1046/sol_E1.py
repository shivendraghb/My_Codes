import sys
sys.setrecursionlimit(1 << 25)
MOD = 998244353

def solve():
    input = sys.stdin.readline
    t = int(input())

    for _ in range(t):
        n, m, V = map(int, input().split())
        a = list(map(int, input().split()))

        g = [[] for _ in range(n)]
        for _ in range(m):
            u, v = map(int, input().split())
            g[u-1].append(v-1)
            g[v-1].append(u-1)

        # Use BFS to assign xor-values relative to a root
        dist = [-1] * n
        ok = True
        free_components = 0

        for i in range(n):
            if dist[i] == -1:
                dist[i] = 0
                stack = [i]
                comp_free = True
                while stack:
                    u = stack.pop()
                    for v in g[u]:
                        if dist[v] == -1:
                            dist[v] = dist[u] ^ 1  # bipartition for xor parity
                            stack.append(v)
                        else:
                            # cycle detected: parity must match
                            if (dist[v] ^ dist[u]) != 1:
                                ok = False
                                break
                    if not ok: break
                if not ok: break
                comp_free = True
                # If this component has at least one fixed value, it propagates
                for j in range(n):
                    if dist[j] != -1 and a[j] != -1:
                        comp_free = False
                        break
                if comp_free:
                    free_components += 1

        if not ok:
            print(0)
        else:
            ans = pow(V, free_components, MOD)
            print(ans)

if __name__ == "__main__":
    solve()
