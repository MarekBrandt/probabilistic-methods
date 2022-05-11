def combinations(lst, m):
    if m == 0:
        return [[]]

    result = []
    for i in range(0, len(lst)):

        elem = lst[i]
        remaining = lst[i + 1:]

        for other_comb in combinations(remaining, m - 1):
            result.append([elem] + other_comb)

    return result


def main():
    n  = 6
    m = 4
    list = combinations(range(1, n+1), m)
    for i in list:
        print(i)


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    main()
