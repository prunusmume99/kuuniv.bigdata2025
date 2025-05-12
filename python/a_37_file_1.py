def main():
    # f = open("data/text.txt", "w")
    # print(f.fileno())  # file descriptor
    # f.write("hello, Python Programming, hi every one!!")
    # # 표준 IO 함수 fputs fprintf f...
    # f.close()

    with open("data/text.txt", "a", encoding="utf-8") as f:
        f.write("hello Python!! second input")


if __name__ == "__main__":
    main()