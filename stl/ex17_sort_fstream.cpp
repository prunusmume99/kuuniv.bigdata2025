#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student {
public:
    string name;
    int sub1, sub2, sub3, sub4, sub5;

    int totalscore() const {
        return sub1 + sub2 + sub3 + sub4 + sub5;
    }

    void print() const {
        cout << "이름 : " << name << endl;
        cout << "점수 : " << sub1 << " " << sub2 << " " << sub3 << " " << sub4 << " " << sub5 << endl;
        cout << "총점 : " << totalscore() << endl;
        cout << "--------------------------" << endl;
    }
};

int main() {
    ifstream file("/home/yj/kuuniv.bigdata2025/stl/10.txt");  
    vector<Student> students;
    string name;
    int s1, s2, s3, s4, s5;

    // 파일에서 데이터 읽기
    while (file >> name >> s1 >> s2 >> s3 >> s4 >> s5) {
        students.push_back({name, s1, s2, s3, s4, s5});
    }
    file.close();

    // 이름만 출력
    for (const auto &student : students) {
        cout << student.name << " ";
    }
    cout << endl;

    // 총점 기준으로 정렬
    sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.totalscore() < b.totalscore();
    });

    // 상세 출력
    for (const auto &student : students) {
        student.print();
    }

    return 0;
}
