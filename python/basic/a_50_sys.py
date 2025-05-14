import argparse # argument 다룰 때 유용한 패키지
import sys

def main():
    print(sys.argv)
    for value in sys.argv:
        print(value)
    sys.exit()
    exit()
    print("version", sys.version)
    print("version_info", sys.version_info)
    print("copyright", sys.copyright)
    print("getprofile", sys.getprofile())
   

if __name__ == "__main__":
    main()
