from functools import cache, lru_cache

cnt = 0


# @lru_cache(maxsize=None) # 간단히 메모화 시키는 방법.
@cache
def fibonacci(n):
    global cnt  # 전역 변수 명시
    cnt += 1
    if n == 1:
        return 1
    elif n == 2:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)


def main():
    global cnt
    print(fibonacci(400))
    print(f"fibonacci 가 수행된 횟수 {cnt}")


if __name__ == "__main__":
    main()