#include<bits/stdc++.h>
using namespace std;

class Board
{
    int size;
public:
    Board()
    {
        size=3;
    }
    void setsize(int n)
    {
        size=n;
    }
    int getsize()
    {
        return size;
    }
};
