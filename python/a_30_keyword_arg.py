def print_n_times(*args, **kwargs):     # 함수의 타입이 명확하지 않을 때 이렇게 쓰면 웬만하면 다 넘어감
    print(type(args))                   # tuple
    print(type(kwargs))                 # dict
    for k, v in kwargs.items():
        n = kwargs.get("n")
        if n:
            for _ in range(n):
                print(f"{k} : {v}")

def main():
    print_n_times("hi", 123, 3.1234, a=3, b=4, n=5 ,abc= "hihihi")
    # hi, 123 등 매개변수는 *args, a=3, b=4 등은 **kwargs 임 그래서 순서 바꿔 쓰면 에러남
   
if __name__ == "__main__":
    main()
