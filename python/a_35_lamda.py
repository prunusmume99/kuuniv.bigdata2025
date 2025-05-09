def call_n_times(func, n):
    for _ in range(n):
        func()


def print_hello():
    # 정적 변수 처럼 쓰기
    if not hasattr(print_hello, "i"):
        print_hello.i = 0
    print(f"안녕하세요 {print_hello.i}")
    print_hello.i += 1


def power(x):
    return x**2


def under_3(x):
    return x < 3


def under_50(x):
    return x < 50


def main():
    temp_func = print_hello
    call_n_times(temp_func, 10)
    # 함수를 객체 처럼 쓴다. (사실(C 레벨에서) 객체가 맞다.)
    lambda_func1 = power
    lambda_func2 = lambda x: x**2  # 함수 객체를 리턴한다.
    print(lambda_func1(5))
    print(lambda_func2(5))
    lambda_under1 = under_3
    lambda_under2 = lambda x: x < 3
    print(lambda_under1(2))
    print(lambda_under2(2))

    li = [x for x in range(100)]
    # map 활용.
    output = map(power, li)
    print(list(output))
    # filter 활용.
    output = filter(under_50, li)
    print(list(output))


if __name__ == "__main__":
    main()