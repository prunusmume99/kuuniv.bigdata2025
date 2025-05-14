def main():
    a = "choisugil"
    b = "CHOISUGIL"
    c = "ChoiSuGil"
    print(a.upper())
    print(a)
    print(b.lower())
    print(c.lower())
    c = "    choi    "
    print(c+"end")
    print(c.strip() + 'end')
    print(c.lstrip() + 'end')
    print(c.rstrip() + 'end')
    
    d = "this is a python class in ict, our class is best of IT class"
    print(d.find("a"))
    print(d[d.find("a")])
    print(d[d.rfind("a")])
    
    idx = int()
    while d.find("a", idx) != -1:
        idx = d.find("a", idx)
        print(idx, end= ' ')
        idx += 1 
    
    f = "TrainA10".isalnum()
    print(f)
    
    f = "Train_A10".isalnum()
    print(f)
    
    f = "10a".isdecimal()
    print(f)
    
    f = "10ff".isdecimal()
    print(f)
    g = d.split()
    print(g)    
    
    print("안녕" in "안녕하세요")
    print("요요" in "안녕하세요")
        
if __name__ == "__main__":
    main()
