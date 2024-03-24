if __name__ == '__main__':
    N = int(input())
    ans = []
    for i in range(N):
        query, *ops = input().split()
        ops = list(map(int, ops))
        if query == "insert":
           ans.insert(ops[0], ops[1])
        elif query == "print":
            print(ans)
        elif query == "remove":
            ans.remove(ops[0])
        elif query == "append":
            ans.append(ops[0])
        elif query == "sort":
            ans.sort()
        elif query == "pop":
            ans.pop()
        elif query == "reverse":
            ans.reverse()