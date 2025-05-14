import numpy
import math     # 모듈명 명시해야함
from math import pi, tau, e   # 단위로 쓸 수 있음
# from math import *          # 귀찮으면 이렇게 모두 다 불러오기 가능

def main():
    # pi = 10
    print(np.pi)
    print(pi, e, tau)
    print(math.sin(30 / 180 * pi))  # sin 30도 -> 래디언

if __name__ == "__main__":
    main()
