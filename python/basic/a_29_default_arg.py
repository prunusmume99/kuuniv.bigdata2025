def print_n_times1(value: str, n: int = 2):
    for _ in range(n):
        print(value)


def print_n_times2(a, b, c, *value: str, n: int = 2):
    print(a, b, c)
    for _ in range(n):
        print(value)


def print_n_times3(a, b, c, n=2):
    for _ in range(n):
        print(a, b, c)


def main():
    print_n_times1("안녕 하세용!")  # defualt 값 2
    print_n_times1("안녕 하세용!", n=5)
    print_n_times1("안녕 하세용!", 10)

    print_n_times2(12, 34, 56, "abc", "def", n=5)
    print_n_times2(12, 34, 56, "abc", "def", n=5)  # 가변매개가 끼면 순서 못 바꿈

    print_n_times3(b=3, a=1, c=2)  # 순서를 바꿀 수 있다.
    print_n_times3(n=3, a=1, c=2, b=5)  # 순서를 바꿀 수 있다.
    # positional argument!, default argument!, variable lenth argument!,


if __name__ == "__main__":
    main()