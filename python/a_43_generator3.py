#for 문을 쓰지 않고 반복적인 작업을 하고 싶을 때 next 를 씀

def test():
    print("test A")
    yield 1
    print("test B")
    yield 2
    print("test C")
    yield 3
    
    
def main():
    print("main A")
    output = test()      # return object 만들고 실행은 따로
    
    print("main B") 
    a = next(output)    # generator 첫번째 시퀀스
    print(a)
    
    a = next(output)    # generator 두번째 시퀀스
    print(a)
    
    a = next(output)    # generator 세번째 시퀀스
    print(a)
    
    try:
        a= next(output)
        print(a)
    except StopIteration:
        print("stop Itreration Error")
    
    print("main C")


if __name__ == "__main__":
    main()
