#include<bits/stdc++.h>
using namespace std;
queue<string> Q;
map<string, string>parent;
map<string, int>visited;
string z="123456780";
string u,v;
void show(string s){
    cout<<'\n'<<s[0]<<' '<<s[1] <<' '<<s[2]<<'\n';
    cout<<s[3]<<' '<<s[4] <<' '<<s[5]<<'\n';
    cout<<s[6]<<' '<<s[7] <<' '<<s[8]<<'\n';
}
bool isSolved(string x){
    if(z.compare(x)==0) {visited[x] = 9; return true;}
    else false;
}
void checkParentNpush(string x){

    if(visited[x]!=9) {
        parent[x]=v;
        Q.push(x);
    }
}
bool possibleMove(string x){
    if(x[8]=='0'){
        swap(x[8],x[5]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[8],x[5]);
        swap(x[8],x[7]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[8],x[7]);
    }
    else if(x[7]=='0'){
        swap(x[7],x[4]);
        checkParentNpush(x);

        if(isSolved(x)) return true;
        swap(x[7],x[4]);

        swap(x[7],x[8]);
        checkParentNpush(x);
        if(isSolved(x))  return true;
        swap(x[7],x[8]);

        swap(x[7],x[6]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[7],x[6]);
    }
    else if(x[6]=='0'){
        swap(x[6],x[3]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[6],x[3]);
        swap(x[6],x[7]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[6],x[7]);
    }
    else if(x[5]=='0'){
        swap(x[5],x[4]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[5],x[4]);
        swap(x[5],x[2]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[5],x[2]);
        swap(x[5],x[8]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[5],x[8]);
    }
    else if(x[4]=='0'){
        swap(x[4],x[7]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[4],x[7]);

        swap(x[4],x[3]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[4],x[3]);

        swap(x[4],x[5]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[4],x[5]);

        swap(x[4],x[1]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[4],x[1]);
    }
    else if(x[3]=='0'){
        swap(x[3],x[4]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[3],x[4]);
        swap(x[3],x[0]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[3],x[0]);
        swap(x[3],x[6]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[3],x[6]);
    }
    else if(x[2]=='0'){
        swap(x[2],x[1]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[2],x[1]);
        swap(x[2],x[5]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[2],x[5]);
    }
    else if(x[1]=='0'){
        swap(x[1],x[4]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[1],x[4]);
        swap(x[1],x[2]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[1],x[2]);
        swap(x[1],x[0]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[1],x[0]);
    }
    else if(x[0]=='0'){
        swap(x[0],x[1]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[0],x[1]);
        swap(x[0],x[3]);
        checkParentNpush(x);
        if(isSolved(x)) return true;
        swap(x[0],x[3]);
    }

    return false;
}

void bfs(string start){
    Q.push(start);
    visited[start] = 9;
    while(!Q.empty()){
        u.assign(Q.front());
        v.assign(Q.front());
        bool f = possibleMove(u);
        Q.pop();
        visited[v] = 9;
        if(f) return;
    }
}
int main(){
    string start="143258760";
    //cin>>start;
    bfs(start);
    int n=1;
    show(z);
    while(z.compare(start)!=0){
        show(parent[z]);
        z.assign(parent[z]);
        n++;
    }
    cout<<"\ntotal "<<n<<" moves\n";
}

