# 파이썬으로 구구단 출력하기

def main():
    print("구구단 계산하기")
    user_input = input()
    print("구구단",user_input, "단을 계산")
    int_input = int(user_input)
    for i in range(1, 10):
        result = int_input * i
        print(user_input, "x", i, "=",result) 
   

if __name__ == "__main__":
    main()
