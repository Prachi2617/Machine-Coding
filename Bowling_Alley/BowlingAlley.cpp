#include<bits/stdc++.h>
using namespace std;
class Player
{
    string name;
    int total_score;
    int curr_score;
    bool won;
public:
    Player(string p)
    {
        name=p;
        total_score=0;
        curr_score=0;
    }
    string get_name()
    {
        return name;
    }
    void set_name(string xp)
    {
        name=xp;
    }
    int get_totalscore()
    {
        return total_score;
    }
    void set_totalscore(int x)
    {
        total_score=x;
    }
    int get_curscore()
    {
        return total_score;
    }
    void get_curscore(int x)
    {
        total_score=x;
    }
};

class ScoreBoard
{

};

class BowlingAlley
{
    queue<Player *>player;
    map<string,vector<vector<string>>>sb;
    int pl;
    int round;
public:
    BowlingAlley(int p, int r,vector<string>plyr)
    {
        round=r;
        pl=p;
        vector<vector<string>>temp;
        for(int i=0;i<p;i++)
        {
            Player *pl=new Player(plyr[i]);
            player.push(pl);
            sb[pl->get_name()]=temp;
        }

    }
    void print()
    {
        for(auto it : sb)
        {
            cout<<"\n"<<it.first<<" : ";
            for(vector<string> v : it.second)
            {
                cout<<"{";
                for(string s : v)
                {
                    cout<<s<<",";
                }
                cout<<"}";
            }
        }
    }

    void play()
    {
        int c;
        int i=0;
        while(round--)
        {
            cout<<"\nRound : " <<i+1;
            i++;
            int cnt=0;
            while(!player.empty() && cnt<pl)
            {
                Player *pp=player.front();
                player.pop();
                vector<string>ss;
                int p=2;
                int curr_score=0;
                while(p--)
                {
                    cout<<"\nenter player : "<<pp->get_name() <<"chance: ";
                    cin>>c;
                    if(c==10)
                    {
                        pp->set_totalscore(c+pp->get_totalscore()+10);
                        ss.push_back("X");
                        break;
                    }
                    else
                    {
                        if(c+curr_score==10)
                        {
                            pp->set_totalscore(c+pp->get_totalscore()+5);
                            ss.push_back("/");
                        }
                        else
                        {
                            pp->set_totalscore(c+pp->get_totalscore());
                            curr_score+=c;
                            ss.push_back(to_string(c));
                        }
                    }
                }
                cnt++;
                sb[pp->get_name()].push_back(ss);
                print();
                player.push(pp);
            }
        }
    }
};

/*class PlayerManager
{

};*/

int main()
{
    int r,p;
    cout<<"Enter number of Players: ";
    cin>>p;
    cout<<"\nEnter number of Rounds: ";
    cin>>r;
    string s;
    vector<string>str;
    for(int i=0;i<p;i++)
    {
        cout<<"\nEnter Player "<< i+1<<" name: ";
        cin>>s;
        str.push_back(s);
    }
    BowlingAlley *b=new BowlingAlley(p,r,str);
    b->play();
    return 0;
}
