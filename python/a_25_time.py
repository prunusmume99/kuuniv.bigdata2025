import time

def main():
    print(time.asctime())  # 현재 날짜와 시간 출력
    print(time.time())     # 현재 시간 (초 단위, Epoch 기준)
    print(time.time_ns())  # 현재 시간 (나노초 단위)

    # 5초 동안 몇 번 루프를 도는지 측정
    ptime = time.time()
    cnt = 0
    while time.time() < ptime + 5:
        cnt += 1
    print(f"이 컴퓨터는 5초에 {cnt} 카운트 가능하다.")

    # 특정 루프가 몇 초 걸리는지 측정
    cnt = 0
    ptime = time.time()
    for i in range(10_000_000):
        cnt += 1
    endtime = time.time()
    print(f"위 작업을 수행할 때 {endtime - ptime:.6f} 초 걸렸다.")

if __name__ == "__main__":
    main()
