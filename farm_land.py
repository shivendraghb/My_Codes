def max_square(matrix: list[list]) -> int:
    if not matrix or not matrix[0]:
        return 0
    
    n, m = len(matrix), len(matrix[0])
    dp = [[0] * m for _ in range(n)]
    max_side = 0

    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 1:
                if i == 0 or j == 0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = 1 + min(
                        dp[i-1][j],
                        dp[i][j-1],
                        dp[i-1][j-1]
                    )
                max_side = max(max_side, dp[i][j])

    return max_side * max_side


if __name__ == "__main__":
    n, m = map(int, input().split())
    matrix = []
    for _ in range(n):
        row = list(map(int, input().split()))
        matrix.append(row)
    
    result = max_square(matrix)
    print(result)


