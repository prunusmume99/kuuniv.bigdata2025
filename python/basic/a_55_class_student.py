import random

class Students:
    def __init__(self, name, korean, math, english, science):
        # *this = self  (this->) c++ 에서는 생략 가능 했음/ 파이썬은 생략 불가능 따라서 self 붙어야함
        # 파이썬에서는 인스턴스 변수는 self 를 반드시 붙여야 한다.
        self.name = name 
        self.korean = korean
        self.math = math
        self.english = english
        self.science = science



def student_get_sum(student):
    return student.korean + student.math + student.english + student.science


def student_get_average(student: Students, num: int):
    return student_get_sum(student) / num


def student_to_string(student, num):
    return f'{student.name}\t{student_get_sum(student)}\t{student_get_average(student, num)}'


def main():
    hanguls = list("최강박이손정적고구류오김송곽유")
    hanguls2 = list("가나다라마바사아자차카파타하길진재형준석화섭윤진")
    students = [
        Students(
            random.choice(hanguls) + "".join(random.choices(hanguls2, k=2)),
            random.randint(65, 100),
            random.randint(65, 100),
            random.randint(65, 100),
            random.randint(65, 100),
        )
        for _ in range(50)
    ]
    for student in students:
        print(student_to_string(student, 4))


if __name__ == "__main__":
    main()