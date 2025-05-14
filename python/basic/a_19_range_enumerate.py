def main():
    # 1. 코끼리 연산자 (walrus operator :=)
    a = range(10)  # := 대신 일반 대입 사용: a = range(10)
    print(a)  # range(0, 10)

    # range는 리스트처럼 보이지만 실제로는 '이터러블 객체'예요.
    # 따라서 일부 메서드는 바로 사용할 수 없어요.

    # 2. range 객체는 count() 메서드 없음 → list로 변환해야 함
    a_list = list(a)
    print(a_list.count(2))   # 2의 개수 출력 (1개)

    # 3. range 객체에는 .step, .start, .stop 속성이 있어요
    print(a.step)           # 1
    print(a.index(1))       # ❌ 오류: range 객체에는 index() 없음 → list로 바꿔야 가능
    print(a_list.index(1))  # ✅ 가능

    # 4. range 객체를 리스트로 변환해서 출력
    print(a_list)

    # 5. 반복문 기본 예제
    for i in range(10):
        print(f"{i+1}번째 출력입니다.")

    # 6. enumerate 사용 예시 → list_a가 정의되어 있어야 함
    list_a = ['a', 'b', 'c']  # 정의 누락되어 있어서 추가

    for i, ele in enumerate(list_a):  # i, ele 둘 다 받기
        print(f"{i}번째 원소의 값은 {ele}입니다.")

    # 7. zip을 이용한 병렬 반복
    num = [0, 1, 2]

    for ele, i in zip(list_a, num):
        print(f"{i}번째 원소의 값은 {ele}입니다.")

if __name__ == "__main__":
    main()
