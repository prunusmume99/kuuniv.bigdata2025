b = [1, 2, 3, 'four']

def main():
    print("local 변수 :", locals())
    print("vars 변수 :", vars())
    print("globals 변수 :", globals())

if __name__ == "__main__":
    main()
