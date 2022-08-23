#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
const int M = 1e9+7;

class student{
public: 
    string name;
    ll rollno;
    ll standard ;
    student(){
        cout<<"Default Constructor"<<"\n";
    }
    student(string n,int r,int s){
        cout<<"Parameterized Constructor"<<"\n";
        name=n;
        rollno=r;
        standard=s;
    }
    student(student &a){
        cout<<"Copy Constructor"<<"\n";
        name=a.name;
        rollno=a.rollno;
        standard=a.standard;
    }
    ~student(){
        cout<<"Destructor"<<"\n";
    }
    void printdetails(){
        cout<<name<<'\n';
        cout<<rollno<<"\n";
        cout<<standard<<"\n";
    }
};

class a{
    public:
    a(){
        cout<<"Class A"<<"\n";
    }
};

class b:public a{
    public:
    b(){
        cout<<"Class B"<<'\n';
    }
};

void ans(){


    student a("Dev Gupta",47,12);
    a.name="DEV GUPTA";
    a.rollno=47;
    a.standard=12;
    a.printdetails();
    student b(a);
    b.printdetails();
    student c;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    ll t=1;
    while(t--){
        ans();
        cout<<'\n';
    }
}
