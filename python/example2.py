# 섭씨 -> 화씨 변환 프로그램     input -> casting -> 연산 -> 출력
def main():
   print("섭씨 온도를 화씨 온도로 변환하는 프로그램")
   print("섭씨 온도를 입력하세요")
   
   celsius = input()
   fahrenheit = (float(celsius) * 1.8) + 32
   
   print("섭씨 온도 : ", celsius)
   print("화씨 온도 : ", fahrenheit)

if __name__ == "__main__":42
main()
 

# def main():
#     degree = input("섭씨 온도 입력하세요: ")
#     degree.split('.')
#     print(f"섭씨 온도 {degree} 의 화씨 온도는 {float(degree) *1.8 + 32} 입니다.")
# else:
# print("섭씨 온도가 숫자가 아닙니다")
        
# if __name__ == "__main__":
#     main()