#include<bits/stdc++.h>
using namespace std;


class Player
{
    string name;
    int rankk;
    char S;
public:
    Player(string s, int r,int sy)
    {
        name=s;
        rankk=r;
        S=sy;
    }
    string getname()
    {
        return name;
    }
    int getrank()
    {
        return rankk;
    }
    char getsymbol()
    {
        return S;
    }
};

