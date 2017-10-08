
#include <iostream>
 
using namespace std;
 
inline void printLine(int i, int j) {
    cout << i << " * " << j  << " = " << i * j << endl;
}
 
template <int I, int J>
struct Line {
    inline static void print() {
        Line<I, J-1>::print();
        printLine(I, J);
    }
};
 
template <int I>
struct Line<I, 1> {
    inline static void print() {
        printLine(I, 1);
    }
};
 
template <int NUM, int N>
struct Group {
    inline static void print() {
        Group<NUM, N - 1>::print();
        cout << endl;
        Line<N, NUM>::print();
    }
};
 
template <int NUM>
struct Group<NUM, 1> {
    inline static void print() {
        Line<1, NUM>::print();
    }
};
 
template <int NUM>
struct Meta99 {
    inline static void print() {
        Group<NUM,NUM>::print();
    }
};
 
int main() {
    Meta99<20>::print();
    return 0;
}
