#!/bin/bash

# 반복문
# for 변수 in 리스트; do 
#     반복할 코드
# done

for name in "Im Yun Jin" "임윤진" "student"; do
    echo "이름: $name"
done

echo "0부터 100까지 숫자 프린트  ------ "
for int in {0..100}; do
    echo -n "$int "
done

# while () 문장1; 문장2; -> while [ condition ]; do 문장1; 문장2; done
# until 루프 -> while 거꾸로 
# until [ condition ]; do 문장1; 문장2; done 
# break continue... 동일

# 함수 !!! -> argument 없음, 소괄호 없음, 리턴 없음 -> $?
# function hello {
#     # $1
#     # return
# }

function hello {
    echo "안녕하세요 $1"
    echo "정상"  # 문자열은 이렇게 echo로 출력해줘야 해
    return 0     # return은 성공을 의미하는 0 사용
}

result=$(hello "하이")  # 함수 실행 결과(출력)를 변수로 저장
echo "함수 출력값: $result"


# 변수 선언 -> 모든 선언이 전역변수 / 지역변수로 -> 변수명 앞에 local 붙이기  local name=$1  

# crontab cron : 시간에 맞춰 쉘 스크립트를 실행하는 기능 

