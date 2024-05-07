#include <cassert>
#include <iostream>

int get_next(int s){
    int next = 0;
    int tmp = s;
    while(tmp > 0){
        int rest = tmp;
        while(rest >= 10){
            rest = rest % 10;
        }
        next += rest;
        tmp = tmp / 10;
    }
    next += s;
    return next;
}

int find_joint(int s1, int s2){

    int step;
    while(s2 != s1){
        if(s2 < s1){
            if(s2 == 0){return -1;}
            s2 = get_next(s2);
        }
        else if(s1 < s2){
            if(s1 == 0){return -1;}
            s1 = get_next(s1);
        }
    }
    return s1;    
}


/* TESTs */

int test1()
{
    int test_s1 = 69;
    int test_s2 = 93;

    assert(find_joint(test_s1,test_s2) == 111);
}


int test2()
{
    int test_s2 = 69;
    int test_s1 = 93;

    assert(find_joint(test_s1,test_s2) == 111);
}


int test3()
{
    int test_s1 = 471;
    int test_s2 = 480;

    assert(find_joint(test_s1,test_s2) == 519);
}


int main(){

    test1();
    test2();
    test3();
    return 0;
}