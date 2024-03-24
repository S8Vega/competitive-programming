if __name__ == '__main__':
    s = input()
    print(0< sum([1 for c in s if c.isalnum()]))  
    print(0< sum([1 for c in s if c.isalpha()]))
    print(0< sum([1 for c in s if c.isdigit()]))
    print(0< sum([1 for c in s if c.islower()]))
    print(0< sum([1 for c in s if c.isupper()]))
    