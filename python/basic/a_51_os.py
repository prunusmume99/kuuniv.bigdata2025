import os

def main():
    print(os.name)
    print(os.getcwd())
    print(os.listdir())
    
    # os.mkdir("test_dir")
    # input()
    # os.rmdir("test_dir")
    
    # os.mkdir("test_dir")
    # os.chdir(os.getcwd()+"/test_dir")
    # print(os.getcwd())
    
    print(os.system("ls -al"))

if __name__ == "__main__":
    main()
    
    
# 파이썬 코드 자체 내에서 폴더를 관리하는 코드
# 파이썬 코드 자체 내에서 명령어를 입력 후 결과 확인
