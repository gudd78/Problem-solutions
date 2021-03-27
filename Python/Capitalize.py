def solve(s):
    x=s.split()
    for i in x:
        s = s.replace(i, i.capitalize())
    return s

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    s = input()
    result = solve(s)
    fptr.write(result + '\n')
    fptr.close()