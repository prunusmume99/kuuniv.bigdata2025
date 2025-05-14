from collections.abc import Iterable

class SimpleIter:
    def __init__(self, start, end):
        self.current = start
        self.end = end
    
    def __iter__(self):
        return self
    def __next__(self):
        if self.current >= self.end:
            raise StopIteration
        value = self.current
        self.current += 1
        return value
        
        
def main():
    iter_a = SimpleIter(1, 10)
     
    for i in iter_a:
        print(i)
    li = list()
    dict_a = dict()
    if isinstance(li, Iterable):
        print("li 는 Iterable 하다")
    if isinstance(dict_a, Iterable):
        print("dict_a 는 Iterable 하다")
    if isinstance(iter_a, Iterable):        # 두 메소드만 정의해도 상속된 것 처럼 행동한다.
        print("iter_a 는 Iterable 하다")
        

if __name__ == "__main__":
    main()
