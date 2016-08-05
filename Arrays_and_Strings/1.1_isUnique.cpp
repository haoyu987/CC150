#include <iostream>
#include <cstring>
using namespace std;

bool isUnique1(string s)
{
    bool a[256];
    memset(a, 0, sizeof(a));
    int len = s.length();
    for(int i=0; i < len; ++i)
    {
        int v = (int)s[i];
        if(a[v]) return false;
        a[v] = true;
    }
    return true;
}

bool isUnique2(string s)
{
    int a[8];
    memset(a, 0, sizeof(a));
    int len = s.length();
    for(int i=0; i < len; ++i)
    {
        int v = (int)s[i];
        int idx = v/32, shift=v%32;
        if(a[idx] & (1 << shift)) return false;
        a[idx] |= (1 << shift);
    }
    return true;
}
int main()
{
    string s1 = "aabbcc";
    string s2 = "abcdefghijklmnopqrstuvwxyzABCD1234567890";
    cout << isUnique2(s1) << " " << isUnique2(s2) << endl;
    return 0;
}
