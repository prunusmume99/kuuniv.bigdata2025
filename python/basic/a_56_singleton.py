class Singleton:
    instance = None  # 클래스 변수 

    def __new__(cls, *args, **kwargs):
        if cls.instance is None:
            cls.instance = super().__new__(cls)
        return cls.instance
    
    def __init__(self, a):
        try:
            print(f"기본에 가지고 있는 값 {self.a}")
        except:
            pass
        self.a = a
        print(f"변경된 값 {self.a}")
    
    def test_method(self):
        self.new_variable = 10 # 이렇게는 사용하지 않는 것이 좋다.

def main():
    a = Singleton(10)
    b = Singleton(20)
    print(id(a), id(b))
    print(a == b)


if __name__ == "__main__":
    main()