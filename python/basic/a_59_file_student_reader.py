import random


class Student:
    def __init__(self, name, korean, math, english, science):
        # *this = self (this->) cpp 에서는 생략 가능
        # 파이썬 에서는 인스턴스 변수는 self 를 반드시 붙여야 한다.
        self.name = name
        self.korean = korean
        self.math = math
        self.english = english
        self.science = science
        self.num = 4

    def student_get_sum(self):
        return self.korean + self.math + self.english + self.science

    def student_get_average(self):
        return self.student_get_sum() / self.num

    def student_to_string(self):
        return f"{self.name}\t{self.student_get_sum()}\t{self.student_get_average()}"


def main():
    students = []
    with open("/home/yj/kuuniv.bigdata2025/python/basic/students.txt", "r") as f:
        while data := f.readline():
            split_data = data.split()
            students.append(
                Student(
                    split_data[0],
                    int(split_data[1]),
                    int(split_data[2]),
                    int(split_data[3]),
                    int(split_data[4]),
                )
            )

    for student in students:
        print(student.student_to_string())


if __name__ == "__main__":
    main()