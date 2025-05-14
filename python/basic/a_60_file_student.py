# student 58번의 학생 총점 평균 이 실행할 때마다 랜덤입니다.
# -> 고정적인 데이터로 100 명의 학생을 처리하는 프로그램을 만드세요.
# 1. 데이터 생성 후 저장 하는 프로그램 100 명
# 2. students.txt 를 읽어서 클래스를 생성하고 처리하는 프로그램
import random


def main():
    hanguls = list("최강박이손정적고구류오김송곽유")
    hanguls2 = list("가나다라마바사아자차카파타하길진재형준석화섭윤진")
    with open("/home/yj/kuuniv.bigdata2025/python/basic/students.txt", "w") as f:
        for _ in range(100):
            data = f'{random.choice(hanguls) + "".join(random.choices(hanguls2, k=2))} {random.randint(65, 100)} {random.randint(65, 100)} {random.randint(65, 100)} {random.randint(65, 100)}\n'
            f.write(data)


if __name__ == "__main__":
    main()