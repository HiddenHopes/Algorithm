#include<bits/stdc++.h>
using namespace std;
queue<string> Q;
map<string, string>parent;
map<string, int>visited;
string p, z="123456780";
string u,v;
void show(string s){
    cout<<"============\n";
    cout<<"| "<<s[0]<<" | "<<s[1] <<" | "<<s[2]<<" |\n";
    cout<<"|===|===|===|\n";
    cout<<"| "<<s[3]<<" | "<<s[4] <<" | "<<s[5]<<" |\n";
    cout<<"|===|===|===|\n";
    cout<<"| "<<s[6]<<" | "<<s[7] <<" | "<<s[8]<<" |\n";
    cout<<"============\n\n";
}

bool notVisitedPush(string x, int a, int b){
    swap(x[a],x[b]);
    if(visited[x]!=1) {
        parent[x]=v;
        Q.push(x);
    }
    if(p.compare(x)==0) return true;
    swap(x[a],x[b]);
    return false;
}
bool possibleMove(string x){
    if(x[8]=='0'){
        if(notVisitedPush(x,8,5)) return true;
        if(notVisitedPush(x,8,7)) return true;
    }
    else if(x[7]=='0'){
        if(notVisitedPush(x,7,4)) return true;
        if(notVisitedPush(x,7,8)) return true;
        if(notVisitedPush(x,7,6)) return true;
    }
    else if(x[6]=='0'){
        if(notVisitedPush(x,6,7)) return true;
        if(notVisitedPush(x,6,3)) return true;
    }
    else if(x[5]=='0'){
        if(notVisitedPush(x,5,4)) return true;
        if(notVisitedPush(x,5,2)) return true;
        if(notVisitedPush(x,5,8)) return true;
    }
    else if(x[4]=='0'){
        if(notVisitedPush(x,4,7)) return true;
        if(notVisitedPush(x,4,3)) return true;
        if(notVisitedPush(x,4,5)) return true;
        if(notVisitedPush(x,4,1)) return true;

    }
    else if(x[3]=='0'){
        if(notVisitedPush(x,3,4)) return true;
        if(notVisitedPush(x,3,0)) return true;
        if(notVisitedPush(x,3,6)) return true;
    }
    else if(x[2]=='0'){
        if(notVisitedPush(x,2,1)) return true;
        if(notVisitedPush(x,2,5)) return true;
    }
    else if(x[1]=='0'){
        if(notVisitedPush(x,1,4)) return true;
        if(notVisitedPush(x,1,2)) return true;
        if(notVisitedPush(x,1,0)) return true;
    }
    else if(x[0]=='0'){
        if(notVisitedPush(x,0,1)) return true;
        if(notVisitedPush(x,0,3)) return true;
    }

    return false;
}

void bfs(string start){
    Q.push(start);
    visited[start] = 1;
    while(!Q.empty()){
        u.assign(Q.front());
        bool f = possibleMove(u);
        Q.pop();
        visited[u] = 1;
        if(f) return;
    }
}
int main(){
    //p="143258760";
    cin>>p;
    bfs("123456780");
    int n=0;
    show(p);
    while(p.compare(z)!=0){
        show(parent[p]);
        p.assign(parent[p]);
        n++;
    }
    cout<<"\ntotal "<<n<<" moves\n";
}

