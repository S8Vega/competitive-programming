def count_substring(string, sub_string):
    ans = 0
    for i in range(len(string)):
        #print(string[i:len(sub_string) + i], sub_string)
        if string[i:len(sub_string)+ i] == sub_string:
            ans += 1
    return ans

if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)