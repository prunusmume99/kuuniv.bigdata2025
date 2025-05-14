import random
from collections.abc import Iterable


class TestClass:  # class TestClas(object):
    pass


def main():
    t1 = TestClass()
    if isinstance(t1, TestClass):
        print("t1 은 TestClass 의 객체이다.")
    if isinstance(1, TestClass):
        print("int(1) 은 TestClass 의 객체이다.")
    else:
        print("int(1) 은 TestClass 의 객체가 아니다.")

    if issubclass(int, TestClass):
        print("int 는 TestClass를 상속받았다.")
    else:
        print("int 는 TestClass를 상속 받지 않았다.")

    if issubclass(list, Iterable):
        print("list 는 interable를 상속받았다.")
    else:
        print("list 는 interable를 상속 받지 않았다.")

    if issubclass(TestClass, object):
        print("TestClass 는 object를 상속받았다.")
    else:
        print("TestClass 는 object 상속 받지 않았다.")

    print(
        issubclass(int, object),
        issubclass(float, object),
        issubclass(list, object),
        issubclass(dict, object),
        issubclass(tuple, object),
        issubclass(str, object),
        issubclass(random.Random, object),
    )


if __name__ == "__main__":
    main()