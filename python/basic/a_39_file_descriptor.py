import sys


def main():
    a = "hellow"
    print(f"stdin file descriptor No : {sys.stdin.fileno()}")
    print(f"stdout file descriptor No : {sys.stdout.fileno()}")
    print(f"stderr file descriptor No : {sys.stderr.fileno()}")
    print("error message", file=sys.stderr)
    with open("data/text.txt", "a", encoding="utf-8") as f:
        print(f"{a} Python!!", file=f)


if __name__ == "__main__":
    main()