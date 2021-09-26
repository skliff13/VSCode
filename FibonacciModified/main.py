

def main():
    t1 = 2
    t2 = 0
    n = 12

    for _ in range(2, n):
        temp = t2
        t2 = t1 + t2**2
        t1 = temp
        print(t2)


if __name__ == '__main__':
    main()
