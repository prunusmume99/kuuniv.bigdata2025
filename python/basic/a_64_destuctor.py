class Test:
    def __init__(self, name):
        self.name = name
        print(f"{self.name} - 생성 되었습니다.")

    def __del__(self):
        print(f"{self.name} - 파괴 되었습니다.")


def main():
    a = Test("A")
    b = Test("B")
    c = Test("C")
    print(a, b, c)
    li = [a, b, c]
    del li[2]
    # del c  # GC 작동하지 않고 소멸
    # 컨테이너 안의 원소를 제거 할때는 컨테이너 포함을 제거 하고, 원소를 제거한다!!
    # 원소만 제거 하면 컨테이너안은 남아 있다!
    # 컨테이너 안을 제거 하면 원소는 남아 있다!
    print(li)
    print(c)


if __name__ == "__main__":
    main()