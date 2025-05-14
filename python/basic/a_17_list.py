import datetime

def main():
    # 선언
    # 리스트는 크기 제한 없음, 모든 객체가 동시에 들어갈 수 있음
    # type 제한 없음
    list_a = list()
    list_b = [1,2,[3,4,5]]
    print(type(list_a), type(list_b))
    
    ptime = datetime.datetime.now()
    list_c = [1,2, 3.14, "choi", ptime]
    
    print(list_c[3], list_c[4])
    print(list_b[1:])
    print(list_b[2][1], list_b[2][2])
   

if __name__ == "__main__":
    main()
