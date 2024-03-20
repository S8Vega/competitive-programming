def custom_srt(sublist):
    return (-sublist[1], sublist[0])

if __name__ == '__main__':
    students = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        students.append([name, score])
    students = sorted(students, key = custom_srt)
    mn_score = students[len(students) - 1][1]
    mn2_score = 1e9
    for student in students:
        if student[1] != mn_score:
            mn2_score = min(mn2_score, student[1])
    # print(mn_score, mn2_score)
    # [print(i) for i in students]
    [print(student[0]) for student in students if student[1] == mn2_score]