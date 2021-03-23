/*
* KMP 算法的实现
*/
#include <iostream>
using namespace std;
int KMP(string s,string p){
    int i = 0, j = 0;
    int *next = new int[p.size()];
    get_next(p, next);
    while(i<s.length()-p.length()&&j<p.length()){
        // j==-1 代表模式串中没有一个字符与当前主串指针指向的字符匹配，
        // 需要将主串指针和模式串指针向前移动一位。
        // 注意这里的字符串以 0 作为起始地址
        if(j==-1||s[i]==s[j]){
            ++i;
            ++j;
        }
        else{
            j = next[j];
        }
    }
    if(j==p.length()-1){
        return i - p.length();
    }
    else
        return 0;
}

// 这个看不懂，照搬的实现，先死记吧 =。=
// 先求出 KMP 的next数组，再对其进行优化。
void get_next(string p, int next[]){
    int i = 0, j = -1;
    next[0] = -1;
    while(i<p.size()-1){
        if(j==-1||p[i]==p[j]){
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
    for (int j = 2; j < p.length();++j){
        if(p[j]==p[next[j]]){
            next[j] = next[next[j]];
        }
    }
}
