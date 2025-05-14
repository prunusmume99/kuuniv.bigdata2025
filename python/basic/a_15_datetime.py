import datetime  # datetime 모듈을 불러옴 (현재 시간 등을 다루는 기능 제공)
import test_package  # 사용자가 만든 패키지를 불러옴 (이 파일과 같은 디렉토리 또는 PYTHONPATH 내에 있어야 함)

# 참고 설명 (주석 부분):
# - PYTHONPATH에 있는 .py 파일들을 import 할 수 있음
# - C에서 만든 .so (공유 객체, Shared Object) 파일도 import 가능 (C extension module)
# - GIL(Global Interpreter Lock) 때문에 일반적으로 Python은 멀티 스레드에서 병렬 처리에 제한이 있음
# - C 모듈은 GIL을 우회하여 병렬 처리가 가능 (속도 향상 목적)
# - .pyi 파일은 Python stub 파일 (인터페이스만 정의)로 타입 힌트 제공용

class Myclass:
    def __Str__(self):  # 잘못된 메서드 이름: __str__이어야 제대로 동작함
        return "test My class"

def main():
    ptime = datetime.datetime.now()  # 현재 날짜 및 시간 구하기
    print(ptime)  # datetime 객체는 __str__ 오버로딩 되어 있어 보기 좋게 출력됨

    myclass = Myclass()
    print(myclass)  # → <__main__.Myclass object at ...> 형태 출력됨 (오버로딩이 안 됨, 이유는 아래 설명)

    print(ptime.month)  # 월 출력
    print(f"{ptime.year}년 {ptime.month}월 {ptime.day}일")  # 날짜 포맷 출력

if __name__ == "__main__":
    main()
