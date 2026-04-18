#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
    char c;
    string input;
    int hua_score=0,opponer_score=0;
    while(1)
    {
      cin>>c;
      input += c;
      if(c=='E')
      break;
    }
    for(int i=0;i<input.length();i++)
    {
        if(input[i]=='W')
        hua_score++;
        else if(input[i]=='L')//if_else语句可以用三目运算符
        opponer_score++;
        else if(input[i]=='E')
        {
            cout<<hua_score<<':'<<opponer_score<<endl;
            hua_score=0;
            opponer_score=0;
            break;
        }
        if(max(hua_score,opponer_score)>=11&&abs(hua_score-opponer_score)>=2)
        {
            cout<<hua_score<<':'<<opponer_score<<endl;
            hua_score=0;
            opponer_score=0;
        }
    }
    cout<<endl;
    for(int i=0;i<input.length();i++)
    {
        if(input[i]=='W')
        hua_score++;
        else if(input[i]=='L')
        opponer_score++;
        else if(input[i]=='E')
        {
            cout<<hua_score<<':'<<opponer_score<<endl;
            hua_score=0;
            opponer_score=0;
            break;
        }
        if(max(hua_score,opponer_score)>=21&&abs(hua_score-opponer_score)>=2)
        {
            cout<<hua_score<<':'<<opponer_score<<endl;
            hua_score=0;
            opponer_score=0;
        }
    }
}