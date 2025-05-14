def main():
    dict_a = dict()
    list_a = ["사라질까??", "음..."]
    dict_b = {1: 1, 2: 2, 3: list_a}  # 정의 할때 set 과 해깔리지 않게 주의
    a = "d"
    dict_c = {"a": 100, "b": 200, "c": 300, a: 400}

    # for i in dict_c:
    #     print(i, dict_c[i], end=", ")
    # print()

    for k, v in dict_c.items():
        print(k, v, end=", ")
    print()

    dict_b.update(dict_c)  # 내부 데이터가 변하는 메소드! # type: ignore
    print(dict_b)

    del dict_b[3]  # dict 안에서 원소 제거.
    print(dict_b)
    print(list_a)  # 아직 살아 있음.
    del list_a  # list_a 사라짐.
    print(dict_b.pop(2))  # 제거와 동시에 쓰일때!
    print(dict_b)


if __name__ == "__main__":
    main()