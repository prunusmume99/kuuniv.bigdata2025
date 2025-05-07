# 문자열을 입력 받아서 단어를 카운트 해서 결과를 출력하기
def main():
    f=open("data.txt", 'r')
    yesterday_lyric=f.readlines()
    f.close()
   
    contents = ""
    for line in yesterday_lyric:
        contents = contents + line.strip() + "\n"
       
    n_of_yesterday = contents.lower().count("yesterday")
    print("yesterday의 횟수 ", n_of_yesterday)

if __name__ == "__main__":
    main()
