import keyword

def main():
    print(keyword.kwlist)

# 이 파일이 실행이 될 때만 main이 실행되게 하는 코드
# import 하면 main은 실행 안됨
if __name__ == "__main__":
    main()
