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
bool isValid(float a,float b,float c,float d);
void f2s(float a, float b, float c, float d,std::vector<string> *p);
std::string getOP(int x);
void getKurbuk(int calc,std::string *kurbuk1,std::string *kurbuk2,std::string *kurbuk3,std::string *kurbuk4,std::string *kurbuk5);
void getKurtup(int calc,std::string *kurbuk1,std::string *kurbuk2,std::string *kurbuk3,std::string *kurbuk4,std::string *kurbuk5);
void pusVec(int x,int y,int z,int calc,float a, float b, float c, float d, std::vector<std::string> *buffer,bool tf);
void swap(float a, float b, float c, float d, float *e, float *f, float *g, float *h,int tag);
void removeDupe(std::vector<std::string> *buffer);
bool cekStr(std::string token);
void getValidInput(std::string a1, std::vector<float> *abcd);
std::vector<std::string> split(std::string str, std::string token);
void saveFile(std::string name,std::vector<std::string> buffer);
void infixtoPostfix(string exp, vector<string> *buffer);
int getPrecedence(string ops);
float getNum(string str);
float calculatePostfix(string exp);

int main(){
    srand((int)time(0));
    std::vector<std::string> buffer;
    std::vector<std::string> temp;
    float a;
    float b;
    float c;
    float d;
    std::vector<float> abcd;
    std::string a1="";
    string menu="";
    std::cout << "1. input\n2. random\n(1/2)\n";
    std::cin >> menu;
    while (menu!="1" && menu!="2"){
        std::cout<<"tidak valid!, ulangi input\n";
        std::cin >> menu;
//        std::cin.clear();
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (menu=="1"){
        getValidInput(a1,&abcd);
        a=abcd[0];
        b=abcd[1];
        c=abcd[2];
        d=abcd[3];
    } else if (menu=="2"){
        a=1+rand()%13;
        b=1+rand()%13;
        c=1+rand()%13;
        d=1+rand()%13;
        std::cout << "4 angka random:\n";
        std::cout << a<<" " << b<<" " << c<<" " << d<<"\n";
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
    vector<string> result;
    int tag=1;
//    int calc=0;
    while (tag<25) {
        x=0;
        while (x < 4) {
            y = 0;
            while (y < 4) {
                z = 0;
                while (z < 4) {
                    calc=0;
                    while (calc<11){
                        pusVec(x,y,z,calc,atmp,btmp,ctmp,dtmp,&buffer, false);
                        infixtoPostfix(buffer.at(buffer.size()-1),&temp);
                        if (((24- calculatePostfix(temp[temp.size()-1]))<0.0001 && (calculatePostfix(temp[temp.size()-1])-24)>-0.0001)&&((24- calculatePostfix(temp[temp.size()-1]))>-0.0001 && (calculatePostfix(temp[temp.size()-1])-24)<0.0001)){
                            pusVec(x,y,z,calc,atmp,btmp,ctmp,dtmp,&result, true);
                        }
                        buffer.pop_back();
                        temp.pop_back();
                        calc++;
                    }
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
    removeDupe(&result);
    int i=0;
    int n=result.size();
    if(n==0){
        cout<<"tidak ada solusi\n";
    } else{
         printf("%d solusi\n",n);
         while (i<result.size()){
            std::cout<<result[i]<<"\n";
            i++;
        }   
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    string save="";
    std::cout << "simpan file solusi?\n"<<"1. simpan\n2. tidak\n(1/2)\n";
    std::cin >> save;
    while (save!="1" && save!="2"){
        std::cout<<"tidak valid!, ulangi input\n";
        std::cin >> save;
//        std::cin.clear();
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (save=="1"){
        std::cout<<"masukkan nama file\n";
        std::string fileName;
        std::cin>>fileName;
        saveFile(fileName,result);
//        saveFile(fileName+"1",temp);
//        saveFile(fileName+"2",result);
    }
    printf("waktu eksekusi: %.3f detik.\n", elapsed.count() * 1e-9);
    return 0;
}

void getValidInput(std::string a1, std::vector<float> *abcd){
    std::string atmp;
    std::vector<std::string> p;
    bool isvalid= false;
    std::cout<<"masukkan 4 angka\n";
    while (!isvalid){
//        cout<<"1";
        getline(std::cin,a1);
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
            std::cout<<"input tidak valid\n";
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

void saveFile(std::string name,std::vector<std::string> buffer){
    std::string path="../test/"+name+".txt";
    std::ofstream output_file(path);
    std::ostream_iterator<std::string> output_iterator(output_file, "\n");
    std::copy(buffer.begin(), buffer.end(), output_iterator);
}

std::vector<std::string> split(std::string str, std::string token){
    std::vector<std::string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=std::string::npos){
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


bool cekStr(std::string token){
    return (token=="A")||(token=="2")||(token=="3")||(token=="4")||(token=="5")||(token=="6")||(token=="7")||(token=="8")||(token=="9")||(token=="10")||(token=="J")||(token=="Q")||(token=="K");
}

bool isValid(float a,float b,float c,float d){
    return (a>0&&a<14)&&(b>0&&b<14)&&(c>0&&c<14)&&(d>0&&d<14);
}

void f2s(float a, float b, float c, float d,std::vector<string> *p){
    std::string as= std::__cxx11::to_string((int) a);
    std::string bs= std::__cxx11::to_string((int) b);
    std::string cs= std::__cxx11::to_string((int) c);
    std::string ds= std::__cxx11::to_string((int) d);
    p->push_back(as);
    p->push_back(bs);
    p->push_back(cs);
    p->push_back(ds);
    int i=0;
    while (i<4){
        if (p->at(i)=="10"){
            p->at(i)="S";
        } else if (p->at(i)=="11"){
            p->at(i)="J";
        } else if (p->at(i)=="12"){
            p->at(i)="Q";
        } else if (p->at(i)=="13"){
            p->at(i)="K";
        }
        i++;
    }
}

void removeDupe(std::vector<std::string> *buffer){
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



void pusVec(int x,int y,int z,int calc,float a, float b, float c, float d, std::vector<std::string> *buffer,bool tf){
    std::vector<std::string> p;
    f2s(a,b,c,d,&p);
    std::string op1,op2,op3;
    op1=getOP(x);
    op2=getOP(y);
    op3=getOP(z);
    std::string kurbuk1,kurbuk2,kurbuk3,kurbuk4,kurbuk5;
    getKurbuk(calc,&kurbuk1,&kurbuk2,&kurbuk3,&kurbuk4,&kurbuk5);
    std::string kurtup1,kurtup2,kurtup3,kurtup4,kurtup5;
    getKurtup(calc,&kurtup1,&kurtup2,&kurtup3,&kurtup4,&kurtup5);
//    string cc= to_string(calc);
//    string xx= to_string(x);
//    string yy= to_string(y);
//    string zz= to_string(z);
//    cc+". "+xx+" "+yy+" "+zz+" "+
    if (tf){
        int i=0;
        while (i<4){
            if (p[i]=="S"){
                p[i]="10";
            }
            i++;
        }
    }
    std::string buf=kurbuk1+kurbuk2+p[0]+op1+kurbuk3+kurbuk4+ p[1]+kurtup1+op2+kurbuk5+p[2]+kurtup2+kurtup3+op3+p[3]+kurtup4+kurtup5;
    std::string s(buf);


//    for (int i = 0; i < s.size(); i++) {
//        cout << i <<". " << s[i] << "\n";
//    }
    buffer->push_back(s);
}

std::string getOP(int x){
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

void getKurbuk(int calc,std::string *kurbuk1,std::string *kurbuk2,std::string *kurbuk3,std::string *kurbuk4,std::string *kurbuk5){
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

void getKurtup(int calc,std::string *kurtup1,std::string *kurtup2,std::string *kurtup3,std::string *kurtup4,std::string *kurtup5){
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

void infixtoPostfix(string exp, vector<string> *buffer){
    vector<string> operatorr;
    string ret="";
    string s="";
    int i=0;
    while(i<exp.size()){
        s="";
        s+=exp.at(i);
L1:
        if (s=="+"|| s=="-" || s=="*" || s=="/" || s=="(" || s==")"){
            if (operatorr.empty()){
                operatorr.push_back(s);
            } else{

                if (s=="("){
                    operatorr.push_back(s);
                } else if (s==")"){
                    while (!operatorr.empty() && operatorr.at(operatorr.size()-1)!="("){
                        ret+=operatorr.at(operatorr.size()-1);
                        operatorr.pop_back();
                    }
//                    operatorr.pop_back();
                    if (!operatorr.empty()&&operatorr.at(operatorr.size()-1)=="("){
                        operatorr.pop_back();
                    }
                }
                else if (getPrecedence(operatorr.at(operatorr.size()-1))< getPrecedence(s)){
                    operatorr.push_back(s);
                } else if (getPrecedence(operatorr.at(operatorr.size()-1))== getPrecedence(s)){
                    ret+=operatorr.at(operatorr.size()-1);
                    operatorr.pop_back();
                    operatorr.push_back(s);
                } else if (getPrecedence(operatorr.at(operatorr.size()-1))> getPrecedence(s)){
//                    while (!operatorr.empty()&& operatorr.at(operatorr.size()-1)!="("&& getPrecedence(operatorr.at(operatorr.size()-1))> getPrecedence(s)){
//                        ret+=operatorr.at(operatorr.size()-1);
//                        operatorr.pop_back();
//                    }
//                    if (!operatorr.empty()&&operatorr.at(operatorr.size()-1)=="("){
//                        operatorr.pop_back();
//                    }
                    ret+=operatorr.at(operatorr.size()-1);
                    operatorr.pop_back();
                    goto L1;
                }
            }
        } else {
            if (s!="("&&s!=")"){
                ret+=s;
            }
        }
        i++;
    }
    while (!operatorr.empty()){
        ret+=operatorr.at(operatorr.size()-1);
        operatorr.pop_back();
    }
    buffer->push_back(ret);
}

int getPrecedence(string ops){
    if (ops=="+" || ops=="-"){
        return 1;
    } else if (ops=="*" || ops=="/"){
        return 2;
    } else {
        return 0;
    }
}

float getNum(string str){
    float f=0;
    try {
        f= stof(str);
    } catch(std::invalid_argument) {
        if (str=="S"){
            f=10;
        } else if(str=="J"){
            f=11;
        } else if(str=="Q"){
            f=12;
        } else if(str=="K"){
            f=13;
        }
    }
    return f;
}

float calculatePostfix(string exp){
    vector<float> res;
    string s="";
    int i=0;
    float o1=0;
    float o2=0;
    float result=0;
    while (i<exp.size()){
        s="";
        s+=exp[i];
        if (s=="+"||s=="-"||s=="*"||s=="/"){
            o2=res[res.size()-1];
            res.pop_back();
            o1=res[res.size()-1];
            res.pop_back();
            if (s=="+"){
                result=o1+o2;
                res.push_back(result);
            } else if (s=="-"){
                result=o1-o2;
                res.push_back(result);
            } else if (s=="*"){
                result=o1*o2;
                res.push_back(result);
            } else if (s=="/"){
                result=o1/o2;
                res.push_back(result);
            }
        } else{
            res.push_back(getNum(s));
        }
        i++;
    }
//    cout<<res.size()<<"\n";
    return res[0];
}