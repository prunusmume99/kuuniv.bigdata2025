#ifndef ARRAY_H
#define ARRAY_H

// #define ARRAY_SIZE 100
// extern const int ARRAY_SIZE;


class Array{

private:
    static const int ARRAY_SIZE;

    int *pArr_;
    int size_;
public:
    static int getDefaultArraySize();
    // static const int ARRAY_SIZE; // static member 변수
    // Array();
    // Array(int size);
    // =>
    explicit Array(int size = ARRAY_SIZE);

    Array(const int *pArr , int size);
    Array(const Array& rhs);
    ~Array();

    Array& operator=(const Array& rhs);
    bool operator==(const Array& rhs) const;

    virtual int& operator[](int index);
    virtual const int& operator[](int index) const;

    int size() const;
    
    // X Array() { }
    // X Array(const Array&) { /* memeberwise copy */ }
    // X ~Array() { }
    // X Array& operator=(const Array&) { /*memeberwise copy */ return *this}
    // Array *operator() { return this; }
    // const Array*operator&() const {return this;}
};

#endif