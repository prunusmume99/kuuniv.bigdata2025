def afun():
    a = 10
    b = 20
    return a, b

def main():
    #iterable 하고 list 와 차이가 없다
    # tuple 쓰는 이유 : 불변 자료형 / list 는 요소들 바꿀 수 있지만 tuple은 안됨
    a = tuple()
    c = 123
    b = a, c
    print(type(b))
    
    # swap
    a =10
    b = 20
    a, b = b, a  #(a,b) = (b,a)  <- tuple 자료형
    print(a, b)
    print(afun())
    
    for ele in afun():
        print(ele)

if __name__ == "__main__":
    main()
