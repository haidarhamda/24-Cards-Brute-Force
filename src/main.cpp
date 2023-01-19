#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <limits>
#include "stdio.h"
using namespace std;
void calc1(int x,int y, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc2(int x,int y, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc3(int x,int y, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc4(int x,int y, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc5(int x,int y, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc6(int x,int y, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc7(int x,int y, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc8(int x,int y, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc9(int x,int y, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc10(int x,int y, float a, float b, float c, float d, std::vector<std::string> *buffer);
void calc11(int x,int y, float a, float b, float c, float d, std::vector<std::string> *buffer);
bool isValid(float a,float b,float c,float d);
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
    while (x<4){
        y=0;
        while (y<4){
            calc1(x,y,a,b,c,d,&buffer);
            y++;
        }
        x++;
    }
//    std::cout << a<<" " << b<<" " << c<<" " << d<<"\n";
    int i=0;
    int n=buffer.size();
    printf("%d solusi\n",n);
//    cout<<n+"\n";
    while (i<buffer.size()){
        cout<<buffer[i]<<"\n";
        i++;
    }
//    cout<< i;
//    cout<<buffer[0];
    return 0;
}
bool isValid(float a,float b,float c,float d){
    return (a>0&&a<14)&&(b>0&&b<14)&&(c>0&&c<14)&&(d>0&&d<14);
}

void f2s(float a, float b, float c, float d,std::vector<string> *p){
//    cout<<"f2sbegin\n";
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
//    cout<<as;
//    string buf[4]={as,bs,cs,ds};
//    cout<<buf[0]<<"\n";

    p->push_back(as);
    p->push_back(bs);
    p->push_back(cs);
    p->push_back(ds);

//    cout<<"f2send\n";
//    cout<<p[0]<<"\n";
//    return buf;
}

void calc1(int x,int y, float a, float b, float c, float d, std::vector<string> *buffer){
//    cout<<"calc1begin\n";
    float res1,res2,res3,res4;
    if (x==0){
        if (y==0){
            res1=a+b+c+d;
            res2=a+b+c-d;
            res3=a+b+c*d;
            res4=a+b+c/d;
            if (24-res1==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"+"+ p[1]+"+"+p[2]+"+"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res2==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"+"+ p[1]+"+"+p[2]+"-"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res3==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"+"+ p[1]+"+"+p[2]+"*"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res4==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"+"+ p[1]+"+"+p[2]+"/"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
        } else if (y==1){
            res1=a+b-c+d;
            res2=a+b-c-d;
            res3=a+b-c*d;
            res4=a+b-c/d;
            if (24-res1==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"+"+ p[1]+"-"+p[2]+"+"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res2==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"+"+ p[1]+"-"+p[2]+"-"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res3==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"+"+ p[1]+"-"+p[2]+"*"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res4==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"+"+ p[1]+"-"+p[2]+"/"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
        } else if (y==2){
            res1=a+b*c+d;
            res2=a+b*c-d;
            res3=a+b*c*d;
            res4=a+b*c/d;
            if (24-res1==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"+"+ p[1]+"*"+p[2]+"+"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res2==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"+"+ p[1]+"*"+p[2]+"-"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res3==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"+"+ p[1]+"*"+p[2]+"*"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res4==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"+"+ p[1]+"*"+p[2]+"/"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
        } else if (y==3){
            res1=a+b/c+d;
            res2=a+b/c-d;
            res3=a+b/c*d;
            res4=a+b/c/d;
            if (24-res1==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"+"+ p[1]+"/"+p[2]+"+"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res2==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"+"+ p[1]+"/"+p[2]+"-"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res3==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"+"+ p[1]+"/"+p[2]+"*"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res4==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"+"+ p[1]+"/"+p[2]+"/"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
        }
    } else if (x==1){
        if (y==0){
            res1=a-b+c+d;
            res2=a-b+c-d;
            res3=a-b+c*d;
            res4=a-b+c/d;
            if (24-res1==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"-"+ p[1]+"+"+p[2]+"+"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res2==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"-"+ p[1]+"+"+p[2]+"-"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res3==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"-"+ p[1]+"+"+p[2]+"*"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res4==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"-"+ p[1]+"+"+p[2]+"/"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
        } else if (y==1){
            res1=a-b-c+d;
            res2=a-b-c-d;
            res3=a-b-c*d;
            res4=a-b-c/d;
            if (24-res1==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"-"+ p[1]+"-"+p[2]+"+"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res2==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"-"+ p[1]+"-"+p[2]+"-"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res3==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"-"+ p[1]+"-"+p[2]+"*"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res4==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"-"+ p[1]+"-"+p[2]+"/"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
        } else if (y==2){
            res1=a-b*c+d;
            res2=a-b*c-d;
            res3=a-b*c*d;
            res4=a-b*c/d;
            if (24-res1==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"-"+ p[1]+"*"+p[2]+"+"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res2==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"-"+ p[1]+"*"+p[2]+"-"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res3==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"-"+ p[1]+"*"+p[2]+"*"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res4==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"-"+ p[1]+"*"+p[2]+"/"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
        } else if (y==3){
            res1=a-b/c+d;
            res2=a-b/c-d;
            res3=a-b/c*d;
            res4=a-b/c/d;
            if (24-res1==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"-"+ p[1]+"+/"+p[2]+"+"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res2==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"-"+ p[1]+"/"+p[2]+"-"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res3==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"-"+ p[1]+"/"+p[2]+"*"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res4==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"-"+ p[1]+"/"+p[2]+"/"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
        }
    } else if (x==2){
        if (y==0){
            res1=a*b+c+d;
            res2=a*b+c-d;
            res3=a*b+c*d;
            res4=a*b+c/d;
            if (24-res1==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"*"+ p[1]+"+"+p[2]+"+"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res2==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"*"+ p[1]+"+"+p[2]+"-"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res3==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"*"+ p[1]+"+"+p[2]+"*"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res4==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"*"+ p[1]+"+"+p[2]+"/"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
        } else if (y==1){
            res1=a*b-c+d;
            res2=a*b-c-d;
            res3=a*b-c*d;
            res4=a*b-c/d;
            if (24-res1==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"*"+ p[1]+"-"+p[2]+"+"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res2==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"*"+ p[1]+"-"+p[2]+"-"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res3==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"*"+ p[1]+"-"+p[2]+"*"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res4==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"*"+ p[1]+"-"+p[2]+"/"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
        } else if (y==2){
            res1=a*b*c+d;
            res2=a*b*c-d;
            res3=a*b*c*d;
            res4=a*b*c/d;
            if (24-res1==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"*"+ p[1]+"*"+p[2]+"+"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res2==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"*"+ p[1]+"*"+p[2]+"-"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res3==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"*"+ p[1]+"*"+p[2]+"*"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res4==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"*"+ p[1]+"*"+p[2]+"/"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
        } else if (y==3){
            res1=a*b/c+d;
            res2=a*b/c-d;
            res3=a*b/c*d;
            res4=a*b/c/d;
            if (24-res1==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"*"+ p[1]+"/"+p[2]+"+"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res2==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"*"+ p[1]+"/"+p[2]+"-"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res3==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"*"+ p[1]+"/"+p[2]+"*"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res4==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"*"+ p[1]+"/"+p[2]+"/"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
        }
    } else if (x==3){
        if (y==0){
            res1=a/b+c+d;
            res2=a/b+c-d;
            res3=a/b+c*d;
            res4=a/b+c/d;
            if (24-res1==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"/"+ p[1]+"+"+p[2]+"+"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res2==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"/"+ p[1]+"+"+p[2]+"-"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res3==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"/"+ p[1]+"+"+p[2]+"*"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res4==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"/"+ p[1]+"+"+p[2]+"/"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
        } else if (y==1){
            res1=a/b-c+d;
            res2=a/b-c-d;
            res3=a/b-c*d;
            res4=a/b-c/d;
            if (24-res1==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"/"+ p[1]+"-"+p[2]+"+"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res2==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"/"+ p[1]+"-"+p[2]+"-"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res3==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"/"+ p[1]+"-"+p[2]+"*"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res4==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"/"+ p[1]+"-"+p[2]+"/"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
        } else if (y==2){
            res1=a/b*c+d;
            res2=a/b*c-d;
            res3=a/b*c*d;
            res4=a/b*c/d;
            if (24-res1==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"/"+ p[1]+"*"+p[2]+"+"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res2==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"/"+ p[1]+"*"+p[2]+"-"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res3==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"/"+ p[1]+"*"+p[2]+"*"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res4==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"/"+ p[1]+"*"+p[2]+"/"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
        } else if (y==3){
            res1=a/b/c+d;
            res2=a/b/c-d;
            res3=a/b/c*d;
            res4=a/b/c/d;
            if (24-res1==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"/"+ p[1]+"/"+p[2]+"+"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res2==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"/"+ p[1]+"/"+p[2]+"-"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res3==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"/"+ p[1]+"/"+p[2]+"*"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
            if (24-res4==0){
                std::vector<string> p;
                f2s(a,b,c,d,&p);
                string buf=p[0]+"/"+ p[1]+"/"+p[2]+"/"+p[3];
                string s(buf);
                buffer->push_back(s);
            }
        }
    }
}