//
// Created by suisei on 1/18/23.
//
#include <iostream>
#include <cstdlib>
#include "stdlib.h"
#include <ctime>
#include <string>
#include <vector>
using namespace std;
void calc1(int x,int y, float a, float b, float c, float d, int *count, std::vector<std::string> *buffer);
void calc2(int x,int y, int a, int b, int c, int d, int *count);
void calc3(int x,int y, int a, int b, int c, int d, int *count);
void calc4(int x,int y, int a, int b, int c, int d, int *count);
void calc5(int x,int y, int a, int b, int c, int d, int *count);
void calc6(int x,int y, int a, int b, int c, int d, int *count);
void calc7(int x,int y, int a, int b, int c, int d, int *count);
void calc8(int x,int y, int a, int b, int c, int d, int *count);
void calc9(int x,int y, int a, int b, int c, int d, int *count);
void calc10(int x,int y, int a, int b, int c, int d, int *count);
void calc11(int x,int y, int a, int b, int c, int d, int *count);
//string f2s(float a, float b, float c, float d);

int main(){
    srand((int)time(0));
    std::cout << "Hello World!\n";
    std::cout << "aaaahah\n";
    std::vector<string> buffer;
//    float a=1+rand()%13;
//    float b=1+rand()%13;
//    float c=1+rand()%13;
//    float d=1+rand()%13;
    float a=6;
    float b=6;
    float c=6;
    float d=6;
    int count=0;

    calc1(0,0,a,b,c,d,&count,&buffer);
    std::cout << a<<" " << b<<" " << c<<" " << d<<"\n";
    cout<<buffer[0];
    return 0;
}

void f2s(float a, float b, float c, float d,std::vector<string> *p){
    cout<<"f2sbegin\n";
//    char ac=((char) a);
//    string as(&ac);
//    char bc=((char) b);
//    string bs(&bc);
//    char cc=((char) c);
//    string cs(&cc);
//    char dc=((char) d);
//    string ds(&dc);
    string as= to_string((int) a);
    string bs= to_string((int) b);
    string cs= to_string((int) c);
    string ds= to_string((int) d);
    cout<<as;
//    string buf[4]={as,bs,cs,ds};
//    cout<<buf[0]<<"\n";

    p->push_back(as);
    p->push_back(bs);
    p->push_back(cs);
    p->push_back(ds);

    cout<<"f2send\n";
//    cout<<p[0]<<"\n";
//    return buf;
}

void calc1(int x,int y, float a, float b, float c, float d, int *count, std::vector<string> *buffer){
    cout<<"calc1begin\n";
    float res1,res2,res3,res4;
    if (x==0){
        if (y==0){
            res1=a+b+c+d;
            res2=a+b+c-d;
            res3=a+b+c*d;
            res4=a+b+c/d;
            if (24-res1==0){
//                std::cout<<a<<"+"<<b<<"+"<<c<<"+"<<d;
                *count++;
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                cout<<p[0]<<"\n";
                cout<<"calc1mid\n";
                cout<<p[0]<<"\n";
                string buf=p[0]+"+"+ p[1]+"+"+p[2]+"+"+p[3];
                cout<<"calc1end\n";
                string s(buf);
                buffer->push_back(s);
                cout<<"calc1end\n";
            }
        } else if (y==1){
            res1=a+b-c+d;
            res2=a+b-c-d;
            res3=a+b-c*d;
            res4=a+b-c/d;
        } else if (y==2){
            res1=a+b*c+d;
            res2=a+b*c-d;
            res3=a+b*c*d;
            res4=a+b*c/d;
        } else if (y==3){
            res1=a+b/c+d;
            res2=a+b/c-d;
            res3=a+b/c*d;
            res4=a+b/c/d;
        }
    } else if (x==1){
        if (y==0){
            res1=a-b+c+d;
            res2=a-b+c-d;
            res3=a-b+c*d;
            res4=a-b+c/d;
        } else if (y==1){
            res1=a-b-c+d;
            res2=a-b-c-d;
            res3=a-b-c*d;
            res4=a-b-c/d;
        } else if (y==2){
            res1=a-b*c+d;
            res2=a-b*c-d;
            res3=a-b*c*d;
            res4=a-b*c/d;
        } else if (y==3){
            res1=a-b/c+d;
            res2=a-b/c-d;
            res3=a-b/c*d;
            res4=a-b/c/d;
        }
    } else if (x==2){
        if (y==0){
            res1=a*b+c+d;
            res2=a*b+c-d;
            res3=a*b+c*d;
            res4=a*b+c/d;
        } else if (y==1){
            res1=a*b-c+d;
            res2=a*b-c-d;
            res3=a*b-c*d;
            res4=a*b-c/d;
        } else if (y==2){
            res1=a*b*c+d;
            res2=a*b*c-d;
            res3=a*b*c*d;
            res4=a*b*c/d;
        } else if (y==3){
            res1=a*b/c+d;
            res2=a*b/c-d;
            res3=a*b/c*d;
            res4=a*b/c/d;
        }
    } else if (x==3){
        if (y==0){
            res1=a/b+c+d;
            res2=a/b+c-d;
            res3=a/b+c*d;
            res4=a/b+c/d;
        } else if (y==1){
            res1=a/b-c+d;
            res2=a/b-c-d;
            res3=a/b-c*d;
            res4=a/b-c/d;
        } else if (y==2){
            res1=a/b*c+d;
            res2=a/b*c-d;
            res3=a/b*c*d;
            res4=a/b*c/d;
        } else if (y==3){
            res1=a/b/c+d;
            res2=a/b/c-d;
            res3=a/b/c*d;
            res4=a/b/c/d;
        }
    }
}