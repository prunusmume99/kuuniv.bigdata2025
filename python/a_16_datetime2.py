# if elif else 사용해서 현재 시각 오전 오후 표시
# 계절을 표시하는 프로그램
# datetime 모듈 사용
# inpout 받아서 나타내게 (시간 : 월 ) -> "now" -> now() 함수를 불러와서 표시

from datetime import datetime

now = datetime.now()

year = now.year
month = now.month
day = now.day
hour = now.hour
minute = now.minute
second = now.second

def main():
    if hour < 12:
        period = "오전"
        hour_12 = hour if hour != 0 else 12
    else:
        period = "오후"
        hour_12 = hour - 12 if hour > 12 else 12
    
    if month in [3,4,5]:
        season = "봄"
    elif month in [6,7,8]:
        season = "여름"
    elif month in [9,10,11]:
        season = "가을"
    else:
        season = "겨울"
    
    print(f"{year}년 {month}월 {day}일 ({season})")
    print(f"{period} {hour_12}시 {minute}분 {second}초")
   

if __name__ == "__main__":
    main()
