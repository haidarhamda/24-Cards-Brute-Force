#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <limits>
#include "stdio.h"
#include <stack>
#include "string.h"
#include <fstream>
#include <iterator>
#include <chrono>

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
void f2s(float a, float b, float c, float d,std::vector<string> *p);
string getOP(int x);
void getKurbuk(int calc,string *kurbuk1,string *kurbuk2,string *kurbuk3,string *kurbuk4,string *kurbuk5);
void getKurtup(int calc,string *kurtup1,string *kurtup2,string *kurtup3,string *kurtup4,string *kurtup5);
void pusVec(int x,int y,int z,int calc,float a, float b, float c, float d, std::vector<string> *buffer);
void swap(float a, float b, float c, float d, float *e, float *f, float *g, float *h,int tag);
void removeDupe(std::vector<string> *buffer);
bool cekStr(string token);
void getValidInput(string a1, std::vector<float> *abcd);
vector<string> split(string str, string token);
void saveFile(string name,vector<string> buffer);

int main(){
    srand((int)time(0));
    std::vector<string> buffer;
    std::vector<string> temp0,temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9,temp10;
    float a;
    float b;
    float c;
    float d;
    vector<float> abcd;
    string a1="";
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
        getValidInput(a1,&abcd);
        a=abcd[0];
        b=abcd[1];
        c=abcd[2];
        d=abcd[3];
    } else if (menu==2){
        a=1+rand()%13;
        b=1+rand()%13;
        c=1+rand()%13;
        d=1+rand()%13;
        cout << "4 angka random:\n";
        cout << a<<" " << b<<" " << c<<" " << d<<"\n";
    }
    auto begin = std::chrono::high_resolution_clock::now();
    int x=0;
    int y=0;
    int z=0;
    int calc=0;
    float atmp,btmp,ctmp,dtmp;
    atmp=a;
    btmp=b;
    ctmp=c;
    dtmp=d;
    int tag=1;
    while (tag<25) {
        x=0;
        while (x < 4) {
            y = 0;
            while (y < 4) {
                z = 0;
                while (z < 4) {
                    calc0(x, y, z, atmp, btmp, ctmp, dtmp, &buffer);
                    calc1(x, y, z, atmp, btmp, ctmp, dtmp, &buffer);
                    calc2(x, y, z, atmp, btmp, ctmp, dtmp, &buffer);
                    calc3(x, y, z, atmp, btmp, ctmp, dtmp, &buffer);
                    calc4(x, y, z, atmp, btmp, ctmp, dtmp, &buffer);
                    calc5(x, y, z, atmp, btmp, ctmp, dtmp, &buffer);
                    calc6(x, y, z, atmp, btmp, ctmp, dtmp, &buffer);
                    calc7(x, y, z, atmp, btmp, ctmp, dtmp, &buffer);
                    calc8(x, y, z, atmp, btmp, ctmp, dtmp, &buffer);
                    calc9(x, y, z, atmp, btmp, ctmp, dtmp, &buffer);
                    calc10(x, y, z, atmp, btmp, ctmp, dtmp, &buffer);
//                    cout<<atmp<<btmp<<ctmp<<dtmp<<"\n";
//                    cout<<calc<<" "<<x<<" "<<y<<" "<<z<<" "<<temp[temp.size()-1]<<"\n";
                    z++;
                }
                y++;
            }
            x++;
        }
//        printf("%f %f %f %f\n",atmp,btmp,ctmp,dtmp);
        swap(a,b,c,d,&atmp,&btmp,&ctmp,&dtmp,tag);
//        printf("%f %f %f %f\n",atmp,btmp,ctmp,dtmp);
        tag++;
    }
    removeDupe(&buffer);
    int i=0;
    int n=buffer.size();
    printf("%d solusi\n",n);
    while (i<buffer.size()){
        cout<<buffer[i]<<"\n";
        i++;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    int save=0;
    cout << "simpan file solusi?\n"<<"1. simpan\n2. tidak\n";
    cin >> save;
    while (save!=1 && save!=2){
        cout<<"tidak valid!, ulangi input\n";
        cin >> menu;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (save==1){
        cout<<"masukkan nama file\n";
        string fileName;
        cin>>fileName;
        saveFile(fileName,buffer);
    }
    printf("waktu eksekusi: %.3f detik.\n", elapsed.count() * 1e-9);
    return 0;
}

void getValidInput(string a1, std::vector<float> *abcd){
    string atmp;
    vector<string> p;
    bool isvalid= false;
    cout<<"masukkan 4 angka\n";
    while (!isvalid){
//        cout<<"1";
        getline(cin,a1);
        if (a1.empty()){
            isvalid= false;
            continue;
        }
        else{
//            cout<<"1";
            atmp=a1;
            p= split(atmp," ");
//            for (int i = 0; i < p.size(); ++i) {
//                cout<<p[i]<<"\n";
//            }
//            cout<<p[0]<<"\n"<<p[1]<<"\n"<<p[2]<<"\n"<<p[3]<<"\n";
            for (int i = 0; i < 4; ++i) {
                if (!cekStr(p[i])){
                    isvalid= false;
                    break;
                } else{
                    isvalid= true;
                }
            }
        }
        if (!isvalid){
            cout<<"input tidak valid\n";
        }
    }
    int i=0;
    while(i<4){
        try {
            abcd->push_back((float ) stoi(p[i]));

        } catch(std::invalid_argument) {
            if (p[i]=="A"){
                abcd->push_back(1);
            } else if(p[i]=="J"){
                abcd->push_back(11);
            } else if(p[i]=="Q"){
                abcd->push_back(12);
            } else if(p[i]=="K"){
                abcd->push_back(13);
            }
        }
        i++;
    }
//    while(((a1->size()>1 || a1->size()<1) || (b1->size()>1 || b1->size()<1) || (c1->size()>1 || c1->size()<1) || (d1->size()>1 || d1->size()<1))||(*a1!="A")){
//        cout<<"input tidak valid";
//        cin >> *a1 >> *b1 >> *c1 >> *d1;
//    }

}

void saveFile(string name,vector<string> buffer){
    string path="../test/"+name+".txt";
    std::ofstream output_file(path);
    std::ostream_iterator<std::string> output_iterator(output_file, "\n");
    std::copy(buffer.begin(), buffer.end(), output_iterator);
}

vector<string> split(string str, string token){
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}


bool cekStr(string token){
    return (token=="A")||(token=="2")||(token=="3")||(token=="4")||(token=="5")||(token=="6")||(token=="7")||(token=="8")||(token=="9")||(token=="10")||(token=="J")||(token=="Q")||(token=="K");
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

void removeDupe(std::vector<string> *buffer){
    for (unsigned int i = 1 ; i < buffer->size(); ++i) {
        for (unsigned int k = 0 ; k < i; ++k) {
            if ( buffer->at(i)==buffer->at(k) ) {
                buffer->erase(buffer->begin()+i);
                --i;
                break;
            }
        }
    }
}

void swap(float a, float b, float c, float d, float *e, float *f, float *g, float *h,int tag){
    if (tag==0){
        *e=a;
        *f=b;
        *g=c;
        *h=d;
    } else if (tag==1){
        *e=a;
        *f=d;
        *g=b;
        *h=c;
    } else if (tag==2){
        *e=a;
        *f=d;
        *g=b;
        *h=c;
    } else if (tag==3){
        *e=a;
        *f=b;
        *g=d;
        *h=c;
    } else if (tag==4){
        *e=a;
        *f=c;
        *g=b;
        *h=d;
    } else if (tag==5){
        *e=a;
        *f=c;
        *g=d;
        *h=b;
    } else if (tag==6){
        *e=a;
        *f=d;
        *g=c;
        *h=b;
    } else if (tag==7){
        *e=b;
        *f=a;
        *g=c;
        *h=d;
    } else if (tag==8){
        *e=b;
        *f=c;
        *g=a;
        *h=d;
    } else if (tag==9){
        *e=b;
        *f=c;
        *g=d;
        *h=a;
    } else if (tag==10){
        *e=b;
        *f=d;
        *g=a;
        *h=c;
    } else if (tag==11){
        *e=b;
        *f=a;
        *g=d;
        *h=c;
    } else if (tag==12){
        *e=b;
        *f=d;
        *g=c;
        *h=a;
    } else if (tag==13){
        *e=c;
        *f=b;
        *g=d;
        *h=a;
    } else if (tag==14){
        *e=c;
        *f=d;
        *g=b;
        *h=a;
    } else if (tag==15){
        *e=c;
        *f=d;
        *g=a;
        *h=b;
    } else if (tag==16){
        *e=c;
        *f=b;
        *g=a;
        *h=d;
    } else if (tag==17){
        *e=c;
        *f=a;
        *g=b;
        *h=d;
    } else if (tag==18){
        *e=c;
        *f=a;
        *g=d;
        *h=b;
    } else if (tag==19){
        *e=d;
        *f=c;
        *g=a;
        *h=b;
    } else if (tag==20){
        *e=d;
        *f=a;
        *g=c;
        *h=b;
    } else if (tag==21){
        *e=d;
        *f=a;
        *g=b;
        *h=c;
    } else if (tag==22){
        *e=d;
        *f=c;
        *g=b;
        *h=a;
    } else if (tag==23){
        *e=d;
        *f=b;
        *g=c;
        *h=a;
    } else if (tag==24) {
        *e = d;
        *f = b;
        *g = a;
        *h = c;
    }
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
//    string cc= to_string(calc);
//    string xx= to_string(x);
//    string yy= to_string(y);
//    string zz= to_string(z);
//    cc+". "+xx+" "+yy+" "+zz+" "+
    string buf=kurbuk1+kurbuk2+p[0]+op1+kurbuk3+kurbuk4+ p[1]+kurtup1+op2+kurbuk5+p[2]+kurtup2+kurtup3+op3+p[3]+kurtup4+kurtup5;
    string s(buf);


//    for (int i = 0; i < s.size(); i++) {
//        cout << i <<". " << s[i] << "\n";
//    }
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
        *kurtup3=")";
    } else if (calc==4){ // a b (c d)
        *kurtup4=")";
    } else if (calc==5){ // a (b c) d
        *kurtup3=")";
    } else if (calc==6){ // (a (b c)) d
        *kurtup2=")";
        *kurtup3=")";
    } else if (calc==7){ // a (b (c d))
        *kurtup4=")";
        *kurtup5=")";
    } else if (calc==8){ // a ((b c) d)
        *kurtup3=")";
        *kurtup5=")";
    } else if (calc==9){ // a (b c d)
        *kurtup4=")";
    } else if (calc==10){ // (a b c) d
        *kurtup3=")";
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
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
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

void calc4(int x,int y,int z, float a, float b, float c, float d, std::vector<string> *buffer){
//    cout<<"calc1begin\n";
    int calc=4;
    float res;
    if (x==0){
        if (y==0){
            if (z==0) {
                res=a+b+(c+d);
            } else if (z==1){
                res=a+b+(c-d);
            } else if (z==2){
                res=a+b+(c*d);
            } else if (z==3){
                res=a+b+(c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a+b-(c+d);
            } else if (z==1){
                res=a+b-(c-d);
            } else if (z==2){
                res=a+b-(c*d);
            } else if (z==3){
                res=a+b-(c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a+b*(c+d);
            } else if (z==1){
                res=a+b*(c-d);
            } else if (z==2){
                res=a+b*(c*d);
            } else if (z==3){
                res=a+b*(c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a+b/(c+d);
            } else if (z==1){
                res=a+b/(c-d);
            } else if (z==2){
                res=a+b/(c*d);
            } else if (z==3){
                res=a+b/(c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==1) {
        if (y == 0) {
            if (z == 0) {
                res = a - b + (c + d);
            } else if (z == 1) {
                res = a - b + (c - d);
            } else if (z == 2) {
                res = a - b + (c * d);
            } else if (z == 3) {
                res = a - b + (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 1) {
            if (z == 0) {
                res = a - b - (c + d);
            } else if (z == 1) {
                res = a - b - (c - d);
            } else if (z == 2) {
                res = a - b - (c * d);
            } else if (z == 3) {
                res = a - b - (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 2) {
            if (z == 0) {
                res = a - b * (c + d);
            } else if (z == 1) {
                res = a - b * (c - d);
            } else if (z == 2) {
                res = a - b * (c * d);
            } else if (z == 3) {
                res = a - b * (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 3) {
            if (z == 0) {
                res = a - b / (c + d);
            } else if (z == 1) {
                res = a - b / (c - d);
            } else if (z == 2) {
                res = a - b / (c * d);
            } else if (z == 3) {
                res = a - b / (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        }
    } else if (x==2) {
        if (y == 0) {
            if (z == 0) {
                res = a * b + (c + d);
            } else if (z == 1) {
                res = a * b + (c - d);
            } else if (z == 2) {
                res = a * b + (c * d);
            } else if (z == 3) {
                res = a * b + (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 1) {
            if (z == 0) {
                res = a * b - (c + d);
            } else if (z == 1) {
                res = a * b - (c - d);
            } else if (z == 2) {
                res = a * b - (c * d);
            } else if (z == 3) {
                res = a * b - (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 2) {
            if (z == 0) {
                res = a * b * (c + d);
            } else if (z == 1) {
                res = a * b * (c - d);
            } else if (z == 2) {
                res = a * b * (c * d);
            } else if (z == 3) {
                res = a * b * (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 3) {
            if (z == 0) {
                res = a * b / (c + d);
            } else if (z == 1) {
                res = a * b / (c - d);
            } else if (z == 2) {
                res = a * b / (c * d);
            } else if (z == 3) {
                res = a * b / (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        }
    }else if (x==3) {
        if (y == 0) {
            if (z == 0) {
                res = a / b + (c + d);
            } else if (z == 1) {
                res = a / b + (c - d);
            } else if (z == 2) {
                res = a / b + (c * d);
            } else if (z == 3) {
                res = a / b + (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 1) {
            if (z == 0) {
                res = a / b - (c + d);
            } else if (z == 1) {
                res = a / b - (c - d);
            } else if (z == 2) {
                res = a / b - (c * d);
            } else if (z == 3) {
                res = a / b - (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 2) {
            if (z == 0) {
                res = a / b * (c + d);
            } else if (z == 1) {
                res = a / b * (c - d);
            } else if (z == 2) {
                res = a / b * (c * d);
            } else if (z == 3) {
                res = a / b * (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 3) {
            if (z == 0) {
                res = a / b / (c + d);
            } else if (z == 1) {
                res = a / b / (c - d);
            } else if (z == 2) {
                res = a / b / (c * d);
            } else if (z == 3) {
                res = a / b / (c / d);
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        }
    }
}

void calc5(int x,int y,int z, float a, float b, float c, float d, std::vector<string> *buffer){
//    cout<<"calc1begin\n";
    int calc=5;
    float res=0;
    if (x==0){
        if (y==0){
            if (z==0) {
                res=a+(b+c)+d;
            } else if (z==1){
                res=a+(b+c)-d;
            } else if (z==2){
                res=a+(b+c)*d;
            } else if (z==3){
                res=a+(b+c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a+(b-c)+d;
            } else if (z==1){
                res=a+(b-c)-d;
            } else if (z==2){
                res=a+(b-c)*d;
            } else if (z==3){
                res=a+(b-c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a+(b*c)+d;
            } else if (z==1){
                res=a+(b*c)-d;
            } else if (z==2){
                res=a+(b*c)*d;
            } else if (z==3){
                res=a+(b*c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a+(b/c)+d;
            } else if (z==1){
                res=a+(b/c)-d;
            } else if (z==2){
                res=a+(b/c)*d;
            } else if (z==3){
                res=a+(b/c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==1){
        if (y==0){
            if (z==0) {
                res=a-(b+c)+d;
            } else if (z==1){
                res=a-(b+c)-d;
            } else if (z==2){
                res=a-(b+c)*d;
            } else if (z==3){
                res=a-(b+c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a-(b-c)+d;
            } else if (z==1){
                res=a-(b-c)-d;
            } else if (z==2){
                res=a-(b-c)*d;
            } else if (z==3){
                res=a-(b-c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a-(b*c)+d;
            } else if (z==1){
                res=a-(b*c)-d;
            } else if (z==2){
                res=a-(b*c)*d;
            } else if (z==3){
                res=a-(b*c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a-(b/c)+d;
            } else if (z==1){
                res=a-(b/c)-d;
            } else if (z==2){
                res=a-(b/c)*d;
            } else if (z==3){
                res=a-(b/c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==2){
        if (y==0){
            if (z==0) {
                res=a*(b+c)+d;
            } else if (z==1){
                res=a*(b+c)-d;
            } else if (z==2){
                res=a*(b+c)*d;
            } else if (z==3){
                res=a*(b+c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a*(b-c)+d;
            } else if (z==1){
                res=a*(b-c)-d;
//                printf("%f %f %f %f\n",a,b,c,d);
//                cout<<"aaa"<<res<<"\n";
            } else if (z==2){
                res=a*(b-c)*d;
            } else if (z==3){
                res=a*(b-c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a*(b*c)+d;
            } else if (z==1){
                res=a*(b*c)-d;
            } else if (z==2){
                res=a*(b*c)*d;
            } else if (z==3){
                res=a*(b*c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a*(b/c)+d;
            } else if (z==1){
                res=a*(b/c)-d;
            } else if (z==2){
                res=a*(b/c)*d;
            } else if (z==3){
                res=a*(b/c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    }else if (x==3){
        if (y==0){
            if (z==0) {
                res=a/(b+c)+d;
            } else if (z==1){
                res=a/(b+c)-d;
            } else if (z==2){
                res=a/(b+c)*d;
            } else if (z==3){
                res=a/(b+c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a/(b-c)+d;
            } else if (z==1){
                res=a/(b-c)-d;
            } else if (z==2){
                res=a/(b-c)*d;
            } else if (z==3){
                res=a/(b-c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a/(b*c)+d;
            } else if (z==1){
                res=a/(b*c)-d;
            } else if (z==2){
                res=a/(b*c)*d;
            } else if (z==3){
                res=a/(b*c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a/(b/c)+d;
            } else if (z==1){
                res=a/(b/c)-d;
            } else if (z==2){
                res=a/(b/c)*d;
            } else if (z==3){
                res=a/(b/c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    }
}

void calc6(int x,int y,int z, float a, float b, float c, float d, std::vector<string> *buffer){
//    cout<<"calc1begin\n";
    int calc=6;
    float res;
    if (x==0){
        if (y==0){
            if (z==0) {
                res=(a+(b+c))+d;
            } else if (z==1){
                res=(a+(b+c))-d;
            } else if (z==2){
                res=(a+(b+c))*d;
            } else if (z==3){
                res=(a+(b+c))/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=(a+(b-c))+d;
            } else if (z==1){
                res=(a+(b-c))-d;
            } else if (z==2){
                res=(a+(b-c))*d;
            } else if (z==3){
                res=(a+(b-c))/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=(a+(b*c))+d;
            } else if (z==1){
                res=(a+(b*c))-d;
            } else if (z==2){
                res=(a+(b*c))*d;
            } else if (z==3){
                res=(a+(b*c))/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=(a+(b/c))+d;
            } else if (z==1){
                res=(a+(b/c))-d;
            } else if (z==2){
                res=(a+(b/c))*d;
            } else if (z==3){
                res=(a+(b/c))/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==1){
        if (y==0){
            if (z==0) {
                res=(a-(b+c))+d;
            } else if (z==1){
                res=(a-(b+c))-d;
            } else if (z==2){
                res=(a-(b+c))*d;
            } else if (z==3){
                res=(a-(b+c))/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=(a-(b-c))+d;
            } else if (z==1){
                res=(a-(b-c))-d;
            } else if (z==2){
                res=(a-(b-c))*d;
            } else if (z==3){
                res=(a-(b-c))/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=(a-(b*c))+d;
            } else if (z==1){
                res=(a-(b*c))-d;
            } else if (z==2){
                res=(a-(b*c))*d;
            } else if (z==3){
                res=(a-(b*c))/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=(a-(b/c))+d;
            } else if (z==1){
                res=(a-(b/c))-d;
            } else if (z==2){
                res=(a-(b/c))*d;
            } else if (z==3){
                res=(a-(b/c))/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==2){
        if (y==0){
            if (z==0) {
                res=(a*(b+c))+d;
            } else if (z==1){
                res=(a*(b+c))-d;
            } else if (z==2){
                res=(a*(b+c))*d;
            } else if (z==3){
                res=(a*(b+c))/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=(a*(b-c))+d;
            } else if (z==1){
                res=(a*(b-c))-d;
            } else if (z==2){
                res=(a*(b-c))*d;
            } else if (z==3){
                res=(a*(b-c))/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=(a*(b*c))+d;
            } else if (z==1){
                res=(a*(b*c))-d;
            } else if (z==2){
                res=(a*(b*c))*d;
            } else if (z==3){
                res=(a*(b*c))/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=(a*(b/c))+d;
            } else if (z==1){
                res=(a*(b/c))-d;
            } else if (z==2){
                res=(a*(b/c))*d;
            } else if (z==3){
                res=(a*(b/c))/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    }else if (x==3){
        if (y==0){
            if (z==0) {
                res=(a/(b+c))+d;
            } else if (z==1){
                res=(a/(b+c))-d;
            } else if (z==2){
                res=(a/(b+c))*d;
            } else if (z==3){
                res=(a/(b+c))/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=(a/(b-c))+d;
            } else if (z==1){
                res=(a/(b-c))-d;
            } else if (z==2){
                res=(a/(b-c))*d;
            } else if (z==3){
                res=(a/(b-c))/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=(a/(b*c))+d;
            } else if (z==1){
                res=(a/(b*c))-d;
            } else if (z==2){
                res=(a/(b*c))*d;
            } else if (z==3){
                res=(a/(b*c))/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=(a/(b/c))+d;
            } else if (z==1){
                res=(a/(b/c))-d;
            } else if (z==2){
                res=(a/(b/c))*d;
            } else if (z==3){
                res=(a/(b/c))/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    }
}

void calc7(int x,int y,int z, float a, float b, float c, float d, std::vector<string> *buffer){
//    cout<<"calc1begin\n";
    int calc=7;
    float res;
    if (x==0){
        if (y==0){
            if (z==0) {
                res=a+(b+(c+d));
            } else if (z==1){
                res=a+(b+(c-d));
            } else if (z==2){
                res=a+(b+(c*d));
            } else if (z==3){
                res=a+(b+(c/d));
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a+(b-(c+d));
            } else if (z==1){
                res=a+(b-(c-d));
            } else if (z==2){
                res=a+(b-(c*d));
            } else if (z==3){
                res=a+(b-(c/d));
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a+(b*(c+d));
            } else if (z==1){
                res=a+(b*(c-d));
            } else if (z==2){
                res=a+(b*(c*d));
            } else if (z==3){
                res=a+(b*(c/d));
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a+(b/(c+d));
            } else if (z==1){
                res=a+(b/(c-d));
            } else if (z==2){
                res=a+(b/(c*d));
            } else if (z==3){
                res=a+(b/(c/d));
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==1) {
        if (y == 0) {
            if (z == 0) {
                res = a - (b + (c + d));
            } else if (z == 1) {
                res = a - (b + (c - d));
            } else if (z == 2) {
                res = a - (b + (c * d));
            } else if (z == 3) {
                res = a - (b + (c / d));
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 1) {
            if (z == 0) {
                res = a - (b - (c + d));
            } else if (z == 1) {
                res = a - (b - (c - d));
            } else if (z == 2) {
                res = a - (b - (c * d));
            } else if (z == 3) {
                res = a - (b - (c / d));
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 2) {
            if (z == 0) {
                res = a - (b * (c + d));
            } else if (z == 1) {
                res = a - (b * (c - d));
            } else if (z == 2) {
                res = a - (b * (c * d));
            } else if (z == 3) {
                res = a - (b * (c / d));
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 3) {
            if (z == 0) {
                res = a - (b / (c + d));
            } else if (z == 1) {
                res = a - (b / (c - d));
            } else if (z == 2) {
                res = a - (b / (c * d));
            } else if (z == 3) {
                res = a - (b / (c / d));
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        }
    } else if (x==2) {
        if (y == 0) {
            if (z == 0) {
                res = a * (b + (c + d));
            } else if (z == 1) {
                res = a * (b + (c - d));
            } else if (z == 2) {
                res = a * (b + (c * d));
            } else if (z == 3) {
                res = a * (b + (c / d));
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 1) {
            if (z == 0) {
                res = a * (b - (c + d));
            } else if (z == 1) {
                res = a * (b - (c - d));
            } else if (z == 2) {
                res = a * (b - (c * d));
            } else if (z == 3) {
                res = a * (b - (c / d));
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 2) {
            if (z == 0) {
                res = a * (b * (c + d));
            } else if (z == 1) {
                res = a * (b * (c - d));
            } else if (z == 2) {
                res = a * (b * (c * d));
            } else if (z == 3) {
                res = a * (b * (c / d));
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 3) {
            if (z == 0) {
                res = a * (b / (c + d));
            } else if (z == 1) {
                res = a * (b / (c - d));
            } else if (z == 2) {
                res = a * (b / (c * d));
            } else if (z == 3) {
                res = a * (b / (c / d));
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        }
    }else if (x==3) {
        if (y == 0) {
            if (z == 0) {
                res = a / (b + (c + d));
            } else if (z == 1) {
                res = a / (b + (c - d));
            } else if (z == 2) {
                res = a / (b + (c * d));
            } else if (z == 3) {
                res = a / (b + (c / d));
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 1) {
            if (z == 0) {
                res = a / (b - (c + d));
            } else if (z == 1) {
                res = a / (b - (c - d));
            } else if (z == 2) {
                res = a / (b - (c * d));
            } else if (z == 3) {
                res = a / (b - (c / d));
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 2) {
            if (z == 0) {
                res = a / (b * (c + d));
            } else if (z == 1) {
                res = a / (b * (c - d));
            } else if (z == 2) {
                res = a / (b * (c * d));
            } else if (z == 3) {
                res = a / (b * (c / d));
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        } else if (y == 3) {
            if (z == 0) {
                res = a / (b / (c + d));
            } else if (z == 1) {
                res = a / (b / (c - d));
            } else if (z == 2) {
                res = a / (b / (c * d));
            } else if (z == 3) {
                res = a / (b / (c / d));
            }
            if (24 - res == 0) {
                pusVec(x, y, z, calc, a, b, c, d, &*buffer);
            }
        }
    }
}

void calc8(int x,int y,int z, float a, float b, float c, float d, std::vector<string> *buffer){
//    cout<<"calc1begin\n";
    int calc=8;
    float res;
    if (x==0){
        if (y==0){
            if (z==0) {
                res=a+((b+c)+d);
            } else if (z==1){
                res=a+((b+c)-d);
            } else if (z==2){
                res=a+((b+c)*d);
            } else if (z==3){
                res=a+((b+c)/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a+((b-c)+d);
            } else if (z==1){
                res=a+((b-c)-d);
            } else if (z==2){
                res=a+((b-c)*d);
            } else if (z==3){
                res=a+((b-c)/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a+((b*c)+d);
            } else if (z==1){
                res=a+((b*c)-d);
            } else if (z==2){
                res=a+((b*c)*d);
            } else if (z==3){
                res=a+((b*c)/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a+((b/c)+d);
            } else if (z==1){
                res=a+((b/c)-d);
            } else if (z==2){
                res=a+((b/c)*d);
            } else if (z==3){
                res=a+((b/c)/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==1){
        if (y==0){
            if (z==0) {
                res=a-((b+c)+d);
            } else if (z==1){
                res=a-((b+c)-d);
            } else if (z==2){
                res=a-((b+c)*d);
            } else if (z==3){
                res=a-((b+c)/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a-((b-c)+d);
            } else if (z==1){
                res=a-((b-c)-d);
            } else if (z==2){
                res=a-((b-c)*d);
            } else if (z==3){
                res=a-((b-c)/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a-((b*c)+d);
            } else if (z==1){
                res=a-((b*c)-d);
            } else if (z==2){
                res=a-((b*c)*d);
            } else if (z==3){
                res=a-((b*c)/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a-((b/c)+d);
            } else if (z==1){
                res=a-((b/c)-d);
            } else if (z==2){
                res=a-((b/c)*d);
            } else if (z==3){
                res=a-((b/c)/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==2){
        if (y==0){
            if (z==0) {
                res=a*((b+c)+d);
            } else if (z==1){
                res=a*((b+c)-d);
            } else if (z==2){
                res=a*((b+c)*d);
            } else if (z==3){
                res=a*((b+c)/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a*((b-c)+d);
            } else if (z==1){
                res=a*((b-c)-d);
            } else if (z==2){
                res=a*((b-c)*d);
            } else if (z==3){
                res=a*((b-c)/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a*((b*c)+d);
            } else if (z==1){
                res=a*((b*c)-d);
            } else if (z==2){
                res=a*((b*c)*d);
            } else if (z==3){
                res=a*((b*c)/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a*((b/c)+d);
            } else if (z==1){
                res=a*((b/c)-d);
            } else if (z==2){
                res=a*((b/c)*d);
            } else if (z==3){
                res=a*((b/c)/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    }else if (x==3){
        if (y==0){
            if (z==0) {
                res=a/((b+c)+d);
            } else if (z==1){
                res=a/((b+c)-d);
            } else if (z==2){
                res=a/((b+c)*d);
            } else if (z==3){
                res=a/((b+c)/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a/((b-c)+d);
            } else if (z==1){
                res=a/((b-c)-d);
            } else if (z==2){
                res=a/((b-c)*d);
            } else if (z==3){
                res=a/((b-c)/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a/((b*c)+d);
            } else if (z==1){
                res=a/((b*c)-d);
            } else if (z==2){
                res=a/((b*c)*d);
            } else if (z==3){
                res=a/((b*c)/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a/((b/c)+d);
            } else if (z==1){
                res=a/((b/c)-d);
            } else if (z==2){
                res=a/((b/c)*d);
            } else if (z==3){
                res=a/((b/c)/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    }
}

void calc9(int x,int y,int z, float a, float b, float c, float d, std::vector<string> *buffer){
//    cout<<"calc1begin\n";
    int calc=9;
    float res;
    if (x==0){
        if (y==0){
            if (z==0) {
                res=a+(b+c)+d;
            } else if (z==1){
                res=a+(b+c)-d;
            } else if (z==2){
                res=a+(b+c)*d;
            } else if (z==3){
                res=a+(b+c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a+(b-c+d);
            } else if (z==1){
                res=a+(b-c-d);
            } else if (z==2){
                res=a+(b-c*d);
            } else if (z==3){
                res=a+(b-c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a+(b*c+d);
            } else if (z==1){
                res=a+(b*c-d);
            } else if (z==2){
                res=a+(b*c*d);
            } else if (z==3){
                res=a+(b*c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a+(b/c+d);
            } else if (z==1){
                res=a+(b/c-d);
            } else if (z==2){
                res=a+(b/c*d);
            } else if (z==3){
                res=a+(b/c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==1){
        if (y==0){
            if (z==0) {
                res=a-(b+c+d);
            } else if (z==1){
                res=a-(b+c-d);
            } else if (z==2){
                res=a-(b+c*d);
            } else if (z==3){
                res=a-(b+c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a-(b-c+d);
            } else if (z==1){
                res=a-(b-c-d);
            } else if (z==2){
                res=a-(b-c*d);
            } else if (z==3){
                res=a-(b-c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a-(b*c+d);
            } else if (z==1){
                res=a-(b*c-d);
            } else if (z==2){
                res=a-(b*c*d);
            } else if (z==3){
                res=a-(b*c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a-(b/c+d);
            } else if (z==1){
                res=a-(b/c-d);
            } else if (z==2){
                res=a-(b/c*d);
            } else if (z==3){
                res=a-(b/c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==2){
        if (y==0){
            if (z==0) {
                res=a*(b+c+d);
            } else if (z==1){
                res=a*(b+c-d);
            } else if (z==2){
                res=a*(b+c*d);
            } else if (z==3){
                res=a*(b+c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a*(b-c+d);
            } else if (z==1){
                res=a*(b-c-d);
            } else if (z==2){
                res=a*(b-c*d);
            } else if (z==3){
                res=a*(b-c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a*(b*c+d);
            } else if (z==1){
                res=a*(b*c-d);
            } else if (z==2){
                res=a*(b*c*d);
            } else if (z==3){
                res=a*(b*c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a*(b/c+d);
            } else if (z==1){
                res=a*(b/c-d);
            } else if (z==2){
                res=a*(b/c*d);
            } else if (z==3){
                res=a*(b/c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    }else if (x==3){
        if (y==0){
            if (z==0) {
                res=a/(b+c+d);
            } else if (z==1){
                res=a/(b+c-d);
            } else if (z==2){
                res=a/(b+c*d);
            } else if (z==3){
                res=a/(b+c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=a/(b-c+d);
            } else if (z==1){
                res=a/(b-c-d);
            } else if (z==2){
                res=a/(b-c*d);
            } else if (z==3){
                res=a/(b-c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=a/(b*c+d);
            } else if (z==1){
                res=a/(b*c-d);
            } else if (z==2){
                res=a/(b*c*d);
            } else if (z==3){
                res=a/(b*c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=a/(b/c+d);
            } else if (z==1){
                res=a/(b/c-d);
            } else if (z==2){
                res=a/(b/c*d);
            } else if (z==3){
                res=a/(b/c/d);
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    }
}

void calc10(int x,int y,int z, float a, float b, float c, float d, std::vector<string> *buffer){
//    cout<<"calc1begin\n";
    int calc=10;
    float res;
    if (x==0){
        if (y==0){
            if (z==0) {
                res=(a+b+c)+d;
            } else if (z==1){
                res=(a+b+c)-d;
            } else if (z==2){
                res=(a+b+c)*d;
            } else if (z==3){
                res=(a+b+c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=(a+b-c)+d;
            } else if (z==1){
                res=(a+b-c)-d;
            } else if (z==2){
                res=(a+b-c)*d;
            } else if (z==3){
                res=(a+b-c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=(a+b*c)+d;
            } else if (z==1){
                res=(a+b*c)-d;
            } else if (z==2){
                res=(a+b*c)*d;
            } else if (z==3){
                res=(a+b*c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=(a+b/c)+d;
            } else if (z==1){
                res=(a+b/c)-d;
            } else if (z==2){
                res=(a+b/c)*d;
            } else if (z==3){
                res=(a+b/c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==1){
        if (y==0){
            if (z==0) {
                res=(a-b+c)+d;
            } else if (z==1){
                res=(a-b+c)-d;
            } else if (z==2){
                res=(a-b+c)*d;
            } else if (z==3){
                res=(a-b+c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=(a-b-c)+d;
            } else if (z==1){
                res=(a-b-c)-d;
            } else if (z==2){
                res=(a-b-c)*d;
            } else if (z==3){
                res=(a-b-c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=(a-b*c)+d;
            } else if (z==1){
                res=(a-b*c)-d;
            } else if (z==2){
                res=(a-b*c)*d;
            } else if (z==3){
                res=(a-b*c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=(a-b/c)+d;
            } else if (z==1){
                res=(a-b/c)-d;
            } else if (z==2){
                res=(a-b/c)*d;
            } else if (z==3){
                res=(a-b/c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    } else if (x==2){
        if (y==0){
            if (z==0) {
                res=(a*b+c)+d;
            } else if (z==1){
                res=(a*b+c)-d;
            } else if (z==2){
                res=(a*b+c)*d;
            } else if (z==3){
                res=(a*b+c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=(a*b-c)+d;
            } else if (z==1){
                res=(a*b-c)-d;
            } else if (z==2){
                res=(a*b-c)*d;
            } else if (z==3){
                res=(a*b-c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=(a*b*c)+d;
            } else if (z==1){
                res=(a*b*c)-d;
            } else if (z==2){
                res=(a*b*c)*d;
            } else if (z==3){
                res=(a*b*c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=(a*b/c)+d;
            } else if (z==1){
                res=(a*b/c)-d;
            } else if (z==2){
                res=(a*b/c)*d;
            } else if (z==3){
                res=(a*b/c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    }else if (x==3){
        if (y==0){
            if (z==0) {
                res=(a/b+c)+d;
            } else if (z==1){
                res=(a/b+c)-d;
            } else if (z==2){
                res=(a/b+c)*d;
            } else if (z==3){
                res=(a/b+c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==1){
            if (z==0) {
                res=(a/b-c)+d;
            } else if (z==1){
                res=(a/b-c)-d;
            } else if (z==2){
                res=(a/b-c)*d;
            } else if (z==3){
                res=(a/b-c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==2){
            if (z==0) {
                res=(a/b*c)+d;
            } else if (z==1){
                res=(a/b*c)-d;
            } else if (z==2){
                res=(a/b*c)*d;
            } else if (z==3){
                res=(a/b*c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        } else if (y==3){
            if (z==0) {
                res=(a/b/c)+d;
            } else if (z==1){
                res=(a/b/c)-d;
            } else if (z==2){
                res=(a/b/c)*d;
            } else if (z==3){
                res=(a/b/c)/d;
            }
            if (24-res==0){
                pusVec(x,y,z,calc,a,b,c,d,&*buffer);
            }
        }
    }
}