import pickle

def main():
    students = []
    try:
        with open("/home/yj/kuuniv.bigdata2025/python/basic/students_b.pickle", "rb") as f:
            while True:
                try:
                    student = pickle.load(f)
                    students.append(student)
                except EOFError:
                    break
        
        print(f"총 {len(students)}명의 학생 데이터를 로드했습니다.")
        print("\n학생 데이터 출력")
        print("=" * 70)
        print("이름\t\t국어\t수학\t영어\t과학\t총점\t평균")
        print("-" * 70)
        
        for student in students:
            total = student.korean + student.math + student.english + student.science
            avg = total / 4
            print(f"{student.name}\t{student.korean}\t{student.math}\t{student.english}\t{student.science}\t{total}\t{avg:.2f}")
        
        print("=" * 70)
        
        # 통계 계산
        total_korean = sum(s.korean for s in students)
        total_math = sum(s.math for s in students)
        total_english = sum(s.english for s in students)
        total_science = sum(s.science for s in students)
        count = len(students)
        
        print("\n통계 데이터")
        print("=" * 40)
        print(f"국어 평균: {total_korean / count:.2f}")
        print(f"수학 평균: {total_math / count:.2f}")
        print(f"영어 평균: {total_english / count:.2f}")
        print(f"과학 평균: {total_science / count:.2f}")
        print(f"전체 평균: {(total_korean + total_math + total_english + total_science) / (count * 4):.2f}")
        print("=" * 40)
        
    except FileNotFoundError:
        print("학생 데이터 파일을 찾을 수 없습니다.")
    except Exception as e:
        print(f"오류 발생: {e}")

if __name__ == "__main__":
    main()