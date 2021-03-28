def solve(s):
    x=s.split()
    for i in x:
        s = s.replace(i, i.capitalize())
    return s

if __name__ == '__main__':
    s = input()
    result = solve(s)
    print(result)