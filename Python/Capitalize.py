def solve(s):
    x=s.split()
    for i in x:
        s = s.replace(i, i.capitalize())
    return s

if __name__ == '__main__':
    s = input()
    result = solve(s)
<<<<<<< HEAD
    print(result)
=======
    print(result)
>>>>>>> 29f8ce0feb40de23ae31dee1b4c431bd3ab67a53
