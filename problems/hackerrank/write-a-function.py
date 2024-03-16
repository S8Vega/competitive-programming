def is_leap(year):
    return year % 4 == 0 and not (year % 100 == 0 and not (year % 400 == 0))

year = int(input())
print(is_leap(year))