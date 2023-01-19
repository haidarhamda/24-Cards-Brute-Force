#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <limits>
#include "stdio.h"
using namespace std;
void calc0(int x,int y,int z, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc1(int x,int y,int z, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc2(int x,int y,int z, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc3(int x,int y,int z, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc4(int x,int y,int z, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc5(int x,int y,int z, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc6(int x,int y,int z, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc7(int x,int y,int z, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc8(int x,int y,int z, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc9(int x,int y,int z, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc10(int x,int y,int z, float a, float b, float c, float d, std::vector<std::string> *buffer);
bool isValid(float a,float b,float c,float d);
//string f2s(float a, float b, float c, float d);
string getOP(int x);
void getKurbuk(int calc,string *kurbuk1,string *kurbuk2,string *kurbuk3,string *kurbuk4,string *kurbuk5);
void getKurtup(int calc,string *kurtup1,string *kurtup2,string *kurtup3,string *kurtup4,string *kurtup5);

int main(){
    srand((int)time(0));
    std::cout << "Hello World!\n";
    std::cout << "aaaahah\n";
    std::vector<string> buffer;
    float a=6;
    float b=6;
    float c=6;
    float d=6;
    int menu=0;
    cout << "1. input\n2. random\n";
    cin >> menu;
    while (menu!=1 && menu!=2){
        cout<<"tidak valid!, ulangi input\n";
        cin >> menu;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (menu==1){
        cout<<"masukkan 4 angka\n";
        cin >> a >> b >> c >> d;
        while (!isValid(a,b,c,d)){
            cout<<"tidak valid!, ulangi input\n";
            cin >> a >> b >> c >> d;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } else if (menu==2){
        a=1+rand()%13;
        b=1+rand()%13;
        c=1+rand()%13;
        d=1+rand()%13;
        cout << "4 angka random:\n";
        cout << a<<" " << b<<" " << c<<" " << d<<"\n";
    }
    int x=0;
    int y=0;
    int z=0;
    while (x<4){
        y=0;
        while (y<4){
            z=0;
            while (z<4){
                calc0(x,y,z,a,b,c,d,&buffer);
                calc1(x,y,z,a,b,c,d,&buffer);
                calc2(x,y,z,a,b,c,d,&buffer);
                calc3(x,y,z,a,b,c,d,&buffer);
                z++;
            }
            y++;
        }
        x++;
    }
    int i=0;
    int n=buffer.size();
    printf("%d solusi\n",n);
    while (i<buffer.size()){
        cout<<buffer[i]<<"\n";
        i++;
    }
    return 0;
}
bool isValid(float a,float b,float c,float d){
    return (a>0&&a<14)&&(b>0&&b<14)&&(c>0&&c<14)&&(d>0&&d<14);
}

void f2s(float a, float b, float c, float d,std::vector<string> *p){
    string as= to_string((int) a);
    string bs= to_string((int) b);
    string cs= to_string((int) c);
    string ds= to_string((int) d);

    p->push_back(as);
    p->push_back(bs);
    p->push_back(cs);
    p->push_back(ds);
}

void pusVec(int x,int y,int z,int calc,float a, float b, float c, float d, std::vector<string> *buffer){
    std::vector<string> p;
    f2s(a,b,c,d,&p);
    string op1,op2,op3;
    op1=getOP(x);
    op2=getOP(y);
    op3=getOP(z);
    string kurbuk1,kurbuk2,kurbuk3,kurbuk4,kurbuk5;
    getKurbuk(calc,&kurbuk1,&kurbuk2,&kurbuk3,&kurbuk4,&kurbuk5);
    string kurtup1,kurtup2,kurtup3,kurtup4,kurtup5;
    getKurtup(calc,&kurtup1,&kurtup2,&kurtup3,&kurtup4,&kurtup5);
    string buf=kurbuk1+kurbuk2+p[0]+op1+kurbuk3+kurbuk4+ p[1]+kurtup1+op2+kurbuk5+p[2]+kurtup2+kurtup3+op3+p[3]+kurtup4+kurtup5;
    string s(buf);
    buffer->push_back(s);
}

string getOP(int x){
    if (x==0){
        return "+";
    } else if (x==1){
        return "-";
    } else if (x==2){
        return "*";
    } else if (x==3){
        return "/";
    } else{
        return "0";
    }
}

void getKurbuk(int calc,string *kurbuk1,string *kurbuk2,string *kurbuk3,string *kurbuk4,string *kurbuk5){
    *kurbuk1="";
    *kurbuk2="";
    *kurbuk3="";
    *kurbuk4="";
    *kurbuk5="";
    if (calc==0){ //a b c d
    } else if (calc==1){ //(a b) c d
        *kurbuk1="(";
    } else if (calc==2){ //(a b) (c d)
        *kurbuk1="(";
        *kurbuk5="(";
    } else if (calc==3){ //((a b) c) d
        *kurbuk1="(";
        *kurbuk2="(";
    } else if (calc==4){ // a b (c d)
        *kurbuk5="(";
    } else if (calc==5){ // a (b c) d
        *kurbuk3="(";
    } else if (calc==6){ // (a (b c)) d
        *kurbuk1="(";
        *kurbuk3="(";
    } else if (calc==7){ // a (b (c d))
        *kurbuk3="(";
        *kurbuk5="(";
    } else if (calc==8){ // a ((b c) d)
        *kurbuk3="(";
        *kurbuk4="(";
    } else if (calc==9){ // a (b c d)
        *kurbuk3="(";
    } else if (calc==10){ // (a b c) d
        *kurbuk1="(";
    }
}

void getKurtup(int calc,string *kurtup1,string *kurtup2,string *kurtup3,string *kurtup4,string *kurtup5){
    *kurtup1="";
    *kurtup2="";
    *kurtup3="";
    *kurtup4="";
    *kurtup5="";
    if (calc==0){ //a b c d
    } else if (calc==1){ //(a b) c d
        *kurtup1=")";
    } else if (calc==2){ //(a b) (c d)
        *kurtup1=")";
        *kurtup5=")";
    } else if (calc==3){ //((a b) c) d
        *kurtup1=")";
        *kurtup2=")";
    } else if (calc==4){ // a b (c d)
        *kurtup5=")";
    } else if (calc==5){ // a (b c) d
        *kurtup3=")";
    } else if (calc==6){ // (a (b c)) d
        *kurtup1=")";
        *kurtup3=")";
    } else if (calc==7){ // a (b (c d))
        *kurtup3=")";
        *kurtup5=")";
    } else if (calc==8){ // a ((b c) d)
        *kurtup3=")";
        *kurtup4=")";
    } else if (calc==9){ // a (b c d)
        *kurtup3=")";
    } else if (calc==10){ // (a b c) d
        *kurtup1=")";
    }
}

void calc0(int x,int y,int z, float a, float b, float c, float d, std::vector<string> *buffer){
//    cout<<"calc1begin\n";
    int calc=0;
    float res;
    if (x==0){
        if (y==0){
            if (z==0) {
                res=a+b+c+d;
            } else if (z==1){
                res=a+b+c-d;
            } else if (z==2){
                res=a+b+c*d;
            } else if (z==3){
                res=a+b+c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a+b-c+d;
            } else if (z==1){
                res=a+b-c-d;
            } else if (z==2){
                res=a+b-c*d;
            } else if (z==3){
                res=a+b-c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a+b*c+d;
            } else if (z==1){
                res=a+b*c-d;
            } else if (z==2){
                res=a+b*c*d;
            } else if (z==3){
                res=a+b*c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a+b/c+d;
            } else if (z==1){
                res=a+b/c-d;
            } else if (z==2){
                res=a+b/c*d;
            } else if (z==3){
                res=a+b/c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==1){
        if (y==0){
            if (z==0) {
                res=a-b+c+d;
            } else if (z==1){
                res=a-b+c-d;
            } else if (z==2){
                res=a-b+c*d;
            } else if (z==3){
                res=a-b+c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a-b-c+d;
            } else if (z==1){
                res=a-b-c-d;
            } else if (z==2){
                res=a-b-c*d;
            } else if (z==3){
                res=a-b-c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a-b*c+d;
            } else if (z==1){
                res=a-b*c-d;
            } else if (z==2){
                res=a-b*c*d;
            } else if (z==3){
                res=a-b*c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a-b/c+d;
            } else if (z==1){
                res=a-b/c-d;
            } else if (z==2){
                res=a-b/c*d;
            } else if (z==3){
                res=a-b/c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==2){
        if (y==0){
            if (z==0) {
                res=a*b+c+d;
            } else if (z==1){
                res=a*b+c-d;
            } else if (z==2){
                res=a*b+c*d;
            } else if (z==3){
                res=a*b+c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a*b-c+d;
            } else if (z==1){
                res=a*b-c-d;
            } else if (z==2){
                res=a*b-c*d;
            } else if (z==3){
                res=a*b-c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,0,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a*b*c+d;
            } else if (z==1){
                res=a*b*c-d;
            } else if (z==2){
                res=a*b*c*d;
            } else if (z==3){
                res=a*b*c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a*b/c+d;
            } else if (z==1){
                res=a*b/c-d;
            } else if (z==2){
                res=a*b/c*d;
            } else if (z==3){
                res=a*b/c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    }else if (x==3){
        if (y==0){
            if (z==0) {
                res=a/b+c+d;
            } else if (z==1){
                res=a/b+c-d;
            } else if (z==2){
                res=a/b+c*d;
            } else if (z==3){
                res=a/b+c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a/b-c+d;
            } else if (z==1){
                res=a/b-c-d;
            } else if (z==2){
                res=a/b-c*d;
            } else if (z==3){
                res=a/b-c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a/b*c+d;
            } else if (z==1){
                res=a/b*c-d;
            } else if (z==2){
                res=a/b*c*d;
            } else if (z==3){
                res=a/b*c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a/b/c+d;
            } else if (z==1){
                res=a/b/c-d;
            } else if (z==2){
                res=a/b/c*d;
            } else if (z==3){
                res=a/b/c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    }
}

void calc1(int x,int y,int z, float a, float b, float c, float d, std::vector<string> *buffer){
//    cout<<"calc1begin\n";
    int calc=1;
    float res;
    if (x==0){
        if (y==0){
            if (z==0) {
                res=(a+b)+c+d;
            } else if (z==1){
                res=(a+b)+c-d;
            } else if (z==2){
                res=(a+b)+c*d;
            } else if (z==3){
                res=(a+b)+c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=(a+b)-c+d;
            } else if (z==1){
                res=(a+b)-c-d;
            } else if (z==2){
                res=(a+b)-c*d;
            } else if (z==3){
                res=(a+b)-c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=(a+b)*c+d;
            } else if (z==1){
                res=(a+b)*c-d;
            } else if (z==2){
                res=(a+b)*c*d;
            } else if (z==3){
                res=(a+b)*c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=(a+b)/c+d;
            } else if (z==1){
                res=(a+b)/c-d;
            } else if (z==2){
                res=(a+b)/c*d;
            } else if (z==3){
                res=(a+b)/c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==1){
        if (y==0){
            if (z==0) {
                res=(a-b)+c+d;
            } else if (z==1){
                res=(a-b)+c-d;
            } else if (z==2){
                res=(a-b)+c*d;
            } else if (z==3){
                res=(a-b)+c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=(a-b)-c+d;
            } else if (z==1){
                res=(a-b)-c-d;
            } else if (z==2){
                res=(a-b)-c*d;
            } else if (z==3){
                res=(a-b)-c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=(a-b)*c+d;
            } else if (z==1){
                res=(a-b)*c-d;
            } else if (z==2){
                res=(a-b)*c*d;
            } else if (z==3){
                res=(a-b)*c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=(a-b)/c+d;
            } else if (z==1){
                res=(a-b)/c-d;
            } else if (z==2){
                res=(a-b)/c*d;
            } else if (z==3){
                res=(a-b)/c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==2){
        if (y==0){
            if (z==0) {
                res=(a*b)+c+d;
            } else if (z==1){
                res=(a*b)+c-d;
            } else if (z==2){
                res=(a*b)+c*d;
            } else if (z==3){
                res=(a*b)+c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=(a*b)-c+d;
            } else if (z==1){
                res=(a*b)-c-d;
            } else if (z==2){
                res=(a*b)-c*d;
            } else if (z==3){
                res=(a*b)-c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=(a*b)*c+d;
            } else if (z==1){
                res=(a*b)*c-d;
            } else if (z==2){
                res=(a*b)*c*d;
            } else if (z==3){
                res=(a*b)*c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=(a*b)/c+d;
            } else if (z==1){
                res=(a*b)/c-d;
            } else if (z==2){
                res=(a*b)/c*d;
            } else if (z==3){
                res=(a*b)/c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    }else if (x==3){
        if (y==0){
            if (z==0) {
                res=(a/b)+c+d;
            } else if (z==1){
                res=(a/b)+c-d;
            } else if (z==2){
                res=(a/b)+c*d;
            } else if (z==3){
                res=(a/b)+c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=(a/b)-c+d;
            } else if (z==1){
                res=(a/b)-c-d;
            } else if (z==2){
                res=(a/b)-c*d;
            } else if (z==3){
                res=(a/b)-c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=(a/b)*c+d;
            } else if (z==1){
                res=(a/b)*c-d;
            } else if (z==2){
                res=(a/b)*c*d;
            } else if (z==3){
                res=(a/b)*c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=(a/b)/c+d;
            } else if (z==1){
                res=(a/b)/c-d;
            } else if (z==2){
                res=(a/b)/c*d;
            } else if (z==3){
                res=(a/b)/c/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    }
}

void calc2(int x,int y,int z, float a, float b, float c, float d, std::vector<string> *buffer){
//    cout<<"calc1begin\n";
    int calc=2;
    float res;
    if (x==0){
        if (y==0){
            if (z==0) {
                res=(a+b)+(c+d);
            } else if (z==1){
                res=(a+b)+(c-d);
            } else if (z==2){
                res=(a+b)+(c*d);
            } else if (z==3){
                res=(a+b)+(c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=(a+b)-(c+d);
            } else if (z==1){
                res=(a+b)-(c-d);
            } else if (z==2){
                res=(a+b)-(c*d);
            } else if (z==3){
                res=(a+b)-(c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=(a+b)*(c+d);
            } else if (z==1){
                res=(a+b)*(c-d);
            } else if (z==2){
                res=(a+b)*(c*d);
            } else if (z==3){
                res=(a+b)*(c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=(a+b)/(c+d);
            } else if (z==1){
                res=(a+b)/(c-d);
            } else if (z==2){
                res=(a+b)/(c*d);
            } else if (z==3){
                res=(a+b)/(c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==1) {
        if (y == 0) {
            if (z == 0) {
                res = (a - b) + (c + d);
            } else if (z == 1) {
                res = (a - b) + (c - d);
            } else if (z == 2) {
                res = (a - b) + (c * d);
            } else if (z == 3) {
                res = (a - b) + (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 1) {
            if (z == 0) {
                res = (a - b) - (c + d);
            } else if (z == 1) {
                res = (a - b) - (c - d);
            } else if (z == 2) {
                res = (a - b) - (c * d);
            } else if (z == 3) {
                res = (a - b) - (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 2) {
            if (z == 0) {
                res = (a - b) * (c + d);
            } else if (z == 1) {
                res = (a - b) * (c - d);
            } else if (z == 2) {
                res = (a - b) * (c * d);
            } else if (z == 3) {
                res = (a - b) * (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 3) {
            if (z == 0) {
                res = (a - b) / (c + d);
            } else if (z == 1) {
                res = (a - b) / (c - d);
            } else if (z == 2) {
                res = (a - b) / (c * d);
            } else if (z == 3) {
                res = (a - b) / (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        }
    } else if (x==2) {
        if (y == 0) {
            if (z == 0) {
                res = (a * b) + (c + d);
            } else if (z == 1) {
                res = (a * b) + (c - d);
            } else if (z == 2) {
                res = (a * b) + (c * d);
            } else if (z == 3) {
                res = (a * b) + (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 1) {
            if (z == 0) {
                res = (a * b) - (c + d);
            } else if (z == 1) {
                res = (a * b) - (c - d);
            } else if (z == 2) {
                res = (a * b) - (c * d);
            } else if (z == 3) {
                res = (a * b) - (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 2) {
            if (z == 0) {
                res = (a * b) * (c + d);
            } else if (z == 1) {
                res = (a * b) * (c - d);
            } else if (z == 2) {
                res = (a * b) * (c * d);
            } else if (z == 3) {
                res = (a * b) * (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 3) {
            if (z == 0) {
                res = (a * b) / (c + d);
            } else if (z == 1) {
                res = (a * b) / (c - d);
            } else if (z == 2) {
                res = (a * b) / (c * d);
            } else if (z == 3) {
                res = (a * b) / (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        }
    }else if (x==3) {
        if (y == 0) {
            if (z == 0) {
                res = (a / b) + (c + d);
            } else if (z == 1) {
                res = (a / b) + (c - d);
            } else if (z == 2) {
                res = (a / b) + (c * d);
            } else if (z == 3) {
                res = (a / b) + (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 1) {
            if (z == 0) {
                res = (a / b) - (c + d);
            } else if (z == 1) {
                res = (a / b) - (c - d);
            } else if (z == 2) {
                res = (a / b) - (c * d);
            } else if (z == 3) {
                res = (a / b) - (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 2) {
            if (z == 0) {
                res = (a / b) * (c + d);
            } else if (z == 1) {
                res = (a / b) * (c - d);
            } else if (z == 2) {
                res = (a / b) * (c * d);
            } else if (z == 3) {
                res = (a / b) * (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 3) {
            if (z == 0) {
                res = (a / b) / (c + d);
            } else if (z == 1) {
                res = (a / b) / (c - d);
            } else if (z == 2) {
                res = (a / b) / (c * d);
            } else if (z == 3) {
                res = (a / b) / (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        }
    }
}

void calc3(int x,int y,int z, float a, float b, float c, float d, std::vector<string> *buffer){
//    cout<<"calc1begin\n";
    int calc=3;
    float res;
    if (x==0){
        if (y==0){
            if (z==0) {
                res=((a+b)+c)+d;
            } else if (z==1){
                res=((a+b)+c)-d;
            } else if (z==2){
                res=((a+b)+c)*d;
            } else if (z==3){
                res=((a+b)+c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=((a+b)-c)+d;
            } else if (z==1){
                res=((a+b)-c)-d;
            } else if (z==2){
                res=((a+b)-c)*d;
            } else if (z==3){
                res=((a+b)-c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=((a+b)*c)+d;
            } else if (z==1){
                res=((a+b)*c)-d;
            } else if (z==2){
                res=((a+b)*c)*d;
            } else if (z==3){
                res=((a+b)*c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=((a+b)/c)+d;
            } else if (z==1){
                res=((a+b)/c)-d;
            } else if ((a+b)/c){
                res=((a+b)/c)*d;
            } else if (z==3){
                res=((a+b)/c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==1){
        if (y==0){
            if (z==0) {
                res=((a-b)+c)+d;
            } else if (z==1){
                res=((a-b)+c)-d;
            } else if (z==2){
                res=((a-b)+c)*d;
            } else if (z==3){
                res=((a-b)+c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=((a-b)-c)+d;
            } else if (z==1){
                res=((a-b)-c)-d;
            } else if (z==2){
                res=((a-b)-c)*d;
            } else if (z==3){
                res=((a-b)-c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=((a-b)*c)+d;
            } else if (z==1){
                res=((a-b)*c)-d;
            } else if (z==2){
                res=((a-b)*c)*d;
            } else if (z==3){
                res=((a-b)*c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=((a-b)/c)+d;
            } else if (z==1){
                res=((a-b)/c)-d;
            } else if (z==2){
                res=((a-b)/c)*d;
            } else if (z==3){
                res=((a-b)/c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==2){
        if (y==0){
            if (z==0) {
                res=((a*b)+c)+d;
            } else if (z==1){
                res=((a*b)+c)-d;
            } else if (z==2){
                res=((a*b)+c)*d;
            } else if (z==3){
                res=((a*b)+c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=((a*b)-c)+d;
            } else if (z==1){
                res=((a*b)-c)-d;
            } else if (z==2){
                res=((a*b)-c)*d;
            } else if (z==3){
                res=((a*b)-c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=((a*b)*c)+d;
            } else if (z==1){
                res=((a*b)*c)-d;
            } else if (z==2){
                res=((a*b)*c)*d;
            } else if (z==3){
                res=((a*b)*c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=((a*b)/c)+d;
            } else if (z==1){
                res=((a*b)/c)-d;
            } else if (z==2){
                res=((a*b)/c)*d;
            } else if (z==3){
                res=((a*b)/c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    }else if (x==3){
        if (y==0){
            if (z==0) {
                res=((a/b)+c)+d;
            } else if (z==1){
                res=((a/b)+c)-d;
            } else if (z==2){
                res=((a/b)+c)*d;
            } else if (z==3){
                res=((a/b)+c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=((a/b)-c)+d;
            } else if (z==1){
                res=((a/b)-c)-d;
            } else if (z==2){
                res=((a/b)-c)*d;
            } else if (z==3){
                res=((a/b)-c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=((a/b)*c)+d;
            } else if (z==1){
                res=((a/b)*c)-d;
            } else if (z==2){
                res=((a/b)*c)*d;
            } else if (z==3){
                res=((a/b)*c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=((a/b)/c)+d;
            } else if (z==1){
                res=((a/b)/c)-d;
            } else if (z==2){
                res=((a/b)/c)*d;
            } else if (z==3){
                res=((a/b)/c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    }
}