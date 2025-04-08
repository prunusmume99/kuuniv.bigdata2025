#!/bin/bash

# 이 스크립트는 hello world를 출력합니다.
name="Im Yun Jin"
export age=25

echo "Hello, World! $name"
echo "date : $(date)" # 이 라인은 date 유틸리티를 실행합니다.

text="hello, world!"
echo ${text:0:5}       # 출력: hello
echo ${text:7}         # 출력: orld! (인덱스는 0부터 시작)

text="I like cat"
echo ${text/cat/dog}   # 출력: I like dog (첫 번째 cat만 치환)

text="I like cat, I really love cat"
echo ${text//cat/dog}  # 출력: I like dog, I really love dog (모두 치환)
echo ${#text}          # 출력: 문자열의 길이 (공백 포함)

# 중요! unset env 환경 변수 초기화!
# unset 환경변수

# read 명령어 -> 비밀번호, 사용자 입력 받아서 처리할 때 사용
echo "이름을 입력하세요 : "
read name
read -s -p "비밀번호를 입력하세요 : " password 
echo "입력한 이름 : $name"
echo "패스워드 : $password "
export name=$name
./envTest

# 화면 출력 echo, printf
echo -n "이어지는 "  # 개행 없음
echo "문장"
echo -e "엔터가 들어가는 문장"      # escape 문자 작동 옵션
printf "이름: %s, 나이: %d\n" "홍길동" 25


# 중요 !! argument 받기 $1 $2  쉘 실행할때 .sh 옆에 글자 적으면 뜸
# 인자 갯수 : $# 모든 인자: $@ $*
echo "첫번째 인자: $1"
echo "두번째 인자: $2"
echo "인자들의 갯수: $#"
echo "모든 인자: $@"
echo "모든 인자: $*"

# 제어문 if then fi(endif)
read -p "나이를 넣으세요: " age
if [ $age -lt 18 ]; then # [] 붙으면 안되고 [ ] 이렇게 띄워야됨
    echo "성인이 아닙니다"
elif [ $age -gt 70 ]; then
    echo "노인입니다"
elif [ $age -gt 20 ] && [ $age -lt 30 ]; then
    echo "20대입니다"
else
    echo "성인입니다"
fi

# 비교 연산자 (숫자)
# == 같다 : eq
# != 같지않다 : ne
# > 크다 : gt
# < 작다 : lt
# >= 크거나 같다 : ge
# <= 작거나 같다 : le

# 비교 연산자 (문자)
# == 같다 : =  헷갈리지 않게 기억 (= 이거 하나만 씀)
# != 같지않다 : !=
# 길이가 0 len(문자열) : z
# 길이가 0이 아닌것 len(문자열) : n 

read -p "입력값을 넣으세요" input
if [ ! -z "$input" ]; then
    echo "입력값이 있습니다"
else 
    echo "입력값이 없습니다"
fi

# 논리 연산 && || ! (and or not)
# 54번 라인 

# switch - case -> case
read -p "과일: " fruit
case $fruit in 
    "사과" | "딸기" ) echo "빨간 과일" ;;
    "바나나" | "레몬" | "망고") echo "노란 과일" ;;
    *) echo "알 수 없음" ;;
esac

