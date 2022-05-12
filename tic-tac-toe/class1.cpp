#include "class2.h"
#include "class3.h"
#include "class1.h"


class Game
{
    char bd[mx][mx];
    queue<Player *>q;
    Board *b=new Board();
public:

    Game(int n)
    {
        b->setsize(n);
        memset(bd,' ',sizeof bd);
        initializeBoard();
        getplayerdetail();
        printboard();
    }

    void initializeBoard()
    {
        int n=b->getsize();
        int i, j;
        for(i=0; i<2*n-1; i++)
        {
            for(j=0; j<2*n-1; j++)
            {
                if(i%2==0 && j%2!=0)
                    bd[i][j]='|';
                if(i%2!=0 && j%2==0)
                    bd[i][j]='-';
                if(i%2!=0 && j%2!=0)\
                    bd[i][j]='+';
            }
        }
    }

    void getplayerdetail()
    {
        for(int i=0;i<2;i++)
        {
            cout<<"\nenter the details of player "<<i+1<< endl;
            string name;
            int rank;
            char S;
            cout<<"Name: ";
            cin>>name;
            cout<<"Rank: ";
            cin>>rank;
            cout<<"Symbol: ";
            cin>>S;
            Player *p=new Player(name,rank,S);
            q.push(p);
        }
    }

    void printboard()
    {
        int n=b->getsize();
        int i, j;
        for(i=0;i<2*n-1;i++)
        {
            for(j=0;j<2*n-1;j++)
            {
                cout<<bd[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
   bool checkwinner(int r,int c, Player *x)
   {
       string winn="";
       for(int i=0;i<b->getsize();i++)
        winn+=x->getsymbol();
       string row="",col="",diag="",revdiag="";
       for(int i =0;i<2*b->getsize()-1;i+=2)
       {
           row+=bd[r][i];
           col+=bd[i][c];
           if(r==c)
            diag+=bd[i][i];
           if(r + c == 2*b->getsize()-2)
                revdiag += bd[2*b->getsize()-2-i][i];

       }
       if(winn==row || winn== col || winn== diag || revdiag ==winn)
            return true;
       return false;
   }


    int getrow()
    {
        int r;
        while(1)
        {
            cout<<"\nselect row from 1 to "<<b->getsize()<<" : ";

            cin>>r;
            if(r>=1 || r<=b->getsize())
            {
                r=2*r -2;
                break;
            }
        }
        return r;
    }

    int getcol()
    {
        int r;
        while(1)
        {
            cout<<"\nselect col from 1 to "<<b->getsize()<<" : ";
            cin>>r;
            if(r>=1 || r<=b->getsize())
            {
                r=2*r -2;
                break;
            }
        }
        return r;
    }

    void play()
    {
        cout<<"ggg";
        int count=0;
        while(1)
        {
            count++;
            if(count>b->getsize() * b->getsize())
            {
                cout<<"\n draw ";
                break;
            }
            Player *x= q.front();
            q.pop();
            int row, col;
            do
            {
                cout<<"\nPlayer "<<x->getname() <<" : ";
                row=getrow();
                col=getcol();
            }while(bd[row][col]!=' ');
            bd[row][col]=x->getsymbol();
            if(checkwinner(row,col,x))
            {
                cout<<"\n--------------------------------------The END----------------------------------------------------";
                cout<<"\nWinner is :"<<x->getname()<<endl;
                printboard();
                break;
            }
            printboard();
            q.push(x);
        }
    }
};

