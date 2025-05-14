import threading
import time

def task(name, duration):
    print(f"쓰레드 {name} 작업 시작")
    time.sleep(duration)
    print(f"쓰레드 {name} {duration}초 작업 완료")

def main():
    task("fisrt", 5)    # 동기화 코드 sync code
    task("second", 3)
    threads = []
    for i in range(4):
        t = threading.Thread(target=task, args=(f"T{i+1}", 5+i))
        threads.append(t)
        t.start()

    # threads[0].join()
    # print("main은 언제 실행될까요?")
    # threads[1].join()
    # print("두번째 쓰레드가 끝났네요")
    for t in threads:
        t.join()
    print("main은 언제 실행될까요?")


    
    
if __name__ == "__main__":
    main()

