def deijkstra(n):
    if n == 1:
        return 1

    if n % 2 == 0:
        return deijkstra(n // 2)

    return deijkstra(n // 2) + deijkstra(n // 2 + 1)


n = int(input())
print(f"Deijkstra({n}) = {deijkstra(n)}")
