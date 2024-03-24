if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    sum_all = sum(student_marks[query_name])
    ans = sum_all / len(student_marks[query_name])
    print(f'{ans:.2f}')
