

def factorial(n):
    result = 1
    for i in range(2, n + 1):
        result *= i

    return result


def binomial(n, k):
    return factorial(n) / factorial(k) / factorial(n - k)


def chance_to_win_k(n, k, p):
    q = 1 - p
    return binomial(n, k) * p**k * q**(n - k)


def main():
    p = 0.2  # Foggy's chance to win 1 map
    c3 = chance_to_win_k(5, 3, p)
    c4 = chance_to_win_k(5, 4, p)
    c5 = chance_to_win_k(5, 5, p)
    print('Chance to win 3-2: ', round(c3, 8))
    print('Chance to win 4-1: ', round(c4, 8))
    print('Chance to win 5-0: ', round(c5, 8))
    print('Chance to win BO5: ', round(c3 + c4 + c5, 8))


if __name__ == '__main__':
    main()
