def qsort(s):
    if len(s) <= 1:
        return s
    opp = s[len(s) // 2]
    middle = [i for i in s if i == opp]
    left = [i for i in s if i < opp]
    right = [i for i in s if i > opp]
    return qsort(left) + middle + qsort(right)


arr = [45, 55, 20, 17, 6, 70, 5, 1]
print(qsort(arr))
