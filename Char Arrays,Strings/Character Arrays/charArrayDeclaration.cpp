#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char name[] = "AMAN";
    char work[5] = "code";
    char msg[] = {'h', 'e', 'l', 'l', 'o', ' ', 'a', 'm', 'a', 'n','\0'};
    char city[4] = {'m', 'u', 'z', '\0'};

    cout << name <<" , length : "<< strlen(name)<< endl;
    cout << work <<" , length : "<< strlen(work)<< endl;
    cout << msg  <<" , length : "<< strlen(msg)<< endl;
    cout << city <<" , length : "<< strlen(city)<< endl;

    return 0;
}