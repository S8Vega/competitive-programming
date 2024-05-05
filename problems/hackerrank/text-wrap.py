import textwrap

def wrap(string, max_width):
    ans, i, n = "", 0, len(string)
    while i < n:
        ans += string[i:i+max_width]+ "\n"
        i += max_width 
    return ans

if __name__ == '__main__':
    string, max_width = input(), int(input())
    result = wrap(string, max_width)
    print(result)