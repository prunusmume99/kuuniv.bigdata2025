def print_3_times():        # PyTypeObject 무조건
    print("안녕하세요")
    print("안녕하세요")
    print("안녕하세요")

def print_n_times(value: str, n: int):
    print("함수 정상 작동 중 ..")
    if not isinstance(n, int):
        print("에러")
        return 
    for _ in range(n):
        print(value)
        
def print_n_times_variable(n: int, *value: tuple[str]):
    """여러번 출력하는 함수 입니다.
    Args:
        n(int) : 반복되는 숫자
        *value : 출력되는 문자를 넣으세요
    """
    print("함수 정상 작동 중 ..")
    print(type(value))
    if not isinstance(n, int):
        print("에러")
        return 
    for _ in range(n):
        for ele in value:
            print(ele, end=" ")
            print()

def main():
    print_3_times()
    print()
    print_3_times()
    print()
    print_n_times("안녕하세요~", "five")
    print_n_times("안녕하세요~", 5)
    print_n_times_variable(7, "하이", "반갑습니다", "...")
    
if __name__ == "__main__":
    main()
