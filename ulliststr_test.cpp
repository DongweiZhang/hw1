/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;

void print_uliststr(ULListStr &dat){
    for (int i = 0; i < dat.size(); ++i) {
        std::cout << dat.get(i) <<std::endl;
    }
}

void test_push_front(){
    ULListStr dat;
    dat.push_front("1");
    dat.push_front("2");
    dat.push_front("3");

    print_uliststr(dat);
    dat.clear();
}

void test_pop_front(){
    ULListStr dat;
    dat.push_front("1");
    dat.push_front("2");
    dat.push_front("3");

    print_uliststr(dat);
    std::cout << "test pop front" << std::endl;
    dat.pop_front();
    print_uliststr(dat);
    dat.clear();
}

void test_pop_back(){
    ULListStr dat;
    dat.push_back("1");
    dat.push_back("2");
    dat.push_back("3");

    print_uliststr(dat);
    std::cout << "test pop back" << std::endl;
    dat.pop_back();
    print_uliststr(dat);
    dat.clear();
}

void test_push_back(){
    ULListStr dat;
    dat.push_back("1");
    dat.push_back("2");
    dat.push_back("3");

    print_uliststr(dat);
    dat.clear();
}

void test_front_and_back(){
    ULListStr dat;
    dat.push_front("1");
    dat.push_front("2");
    dat.push_front("3");

    std::cout << "front: " << dat.front() << std::endl;
    std::cout << "back: " << dat.back() << std::endl;
    dat.clear();

    ULListStr dat2;
    dat2.push_back("4");
    dat2.push_back("5");
    dat2.push_back("6");

    std::cout << "front: " << dat2.front() << std::endl;
    std::cout << "back: " << dat2.back() << std::endl;
    dat2.clear();
}

void test_push(){
    ULListStr dat;
    dat.push_back("89");
    dat.push_front("1");
    dat.push_back("a");
    dat.push_front("2");
    dat.push_back("b");
    dat.push_front("3");

    print_uliststr(dat);
    dat.clear();
}

void test_pop(){
    ULListStr dat;
    dat.push_front("1");
    dat.push_back("a");
    dat.push_front("2");
    dat.push_back("b");
    dat.push_front("3");

    dat.pop_back();
    dat.pop_front();
    dat.pop_back();
    dat.pop_front();
    print_uliststr(dat);
    dat.clear();
}

void test_back_or_front(){
    ULListStr dat;
    dat.push_front("1");
    dat.push_back("a");
    dat.push_front("2");
    dat.push_back("b");
    dat.push_front("3");

    std::cout << "front: " << dat.front() << std::endl;
    std::cout << "back: " << dat.back() << std::endl;
    dat.pop_back();
    dat.pop_front();
    std::cout << "front: " << dat.front() << std::endl;
    std::cout << "back: " << dat.back() << std::endl;
    dat.pop_back();
    std::cout << "front: " << dat.front() << std::endl;
    std::cout << "back: " << dat.back() << std::endl;
    dat.pop_front();
    dat.pop_front();
    print_uliststr(dat);
    dat.clear();
}

int main() {

    test_push_front();

    test_push_back();

    test_pop_front();

    test_pop_back();

    test_front_and_back();

    test_push();

    test_pop();

    test_back_or_front();

    return 0;
}