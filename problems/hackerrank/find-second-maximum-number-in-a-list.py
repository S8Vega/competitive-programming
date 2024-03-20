if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    i = n - 1
    ans = -101
    while i >= 0:
        # print(i, arr[n-1], arr[i], ans)
        if arr[i] < arr[n - 1] and ans == -101:
            ans = arr[i] 
        i -= 1
    print(ans)
