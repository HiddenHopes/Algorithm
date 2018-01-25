#include<bits/stdc++.h>
using namespace std;

//int color[20], parent[20];
queue<char*> Q;
//set<char*> state;
map<char*, char*>parent;
map<char*, int>visited;

char goal[10]="123456780";
char u[10];
char x[10];
char origin[10];

bool isSolved(){
    if(x[0]!='1') return false;
    if(x[1]!='2') return false;
    if(x[2]!='3') return false;
    if(x[3]!='4') return false;
    if(x[4]!='5') return false;
    if(x[5]!='6') return false;
    if(x[6]!='7') return false;
    if(x[7]!='8') return false;
    if(x[8]!='0') return false;
    return true;
}
void checkParentNpush(){
    if(visited[x]!=99) {
        parent[x]=origin;
        cout << "parent of " << x << "  is  " << parent[x] << endl;
        Q.push(x);
        visited[x] = 99;
    }
}
bool possibleMove(){
         if(x[8]=='0'){
        swap(x[8],x[5]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[8],x[5]);
        swap(x[8],x[7]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[8],x[7]);
    }
    else if(x[7]=='0'){
        swap(x[7],x[4]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[7],x[4]);

        swap(x[7],x[8]);
        checkParentNpush();
        if(isSolved())  return true;
        swap(x[7],x[8]);

        swap(x[7],x[6]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[7],x[6]);
    }
    else if(x[6]=='0'){
        swap(x[6],x[3]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[6],x[3]);
        swap(x[6],x[7]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[6],x[7]);
    }
    else if(x[5]=='0'){
        swap(x[5],x[4]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[5],x[4]);
        swap(x[5],x[2]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[5],x[2]);
        swap(x[5],x[8]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[5],x[8]);
    }
    else if(x[4]=='0'){
        swap(x[4],x[1]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[4],x[1]);
        swap(x[4],x[3]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[4],x[3]);
        swap(x[4],x[5]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[4],x[5]);
        swap(x[4],x[7]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[4],x[7]);
    }
    else if(x[3]=='0'){
        swap(x[3],x[4]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[3],x[4]);
        swap(x[3],x[0]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[3],x[0]);
        swap(x[3],x[6]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[3],x[6]);
    }
    else if(x[2]=='0'){
        swap(x[2],x[1]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[2],x[1]);
        swap(x[2],x[5]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[2],x[5]);
    }
    else if(x[1]=='0'){
        swap(x[1],x[4]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[1],x[4]);
        swap(x[1],x[2]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[1],x[2]);
        swap(x[1],x[0]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[1],x[0]);
    }
    else if(x[0]=='0'){
        swap(x[0],x[1]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[0],x[1]);
        swap(x[0],x[3]);
        checkParentNpush();
        if(isSolved()) return true;
        swap(x[0],x[3]);
    }

    return false;
}

void bfs(char start[]){

    Q.push(start);
    parent[start] = NULL;
    //visited[start] = 99;

    while(!Q.empty()){
        strcpy(x,Q.front());
        strcpy(origin,Q.front());
        Q.pop();
        if(possibleMove()) return;
    }

}
int main(){
    char start[10]="123456708";
    bfs(start);
    cout << parent[goal]<< '\n';
}

