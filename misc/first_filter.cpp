#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream fin("raw.txt");
    string line;
    ofstream fout("raw2.txt");
    while(getline(fin, line)){
        int flag= 0;
        string may_be = "";
        for(char c: line){
            if(c == '>'){
                flag = 1;
                continue;
            }
            if(flag == 1 and c == '<'){
                flag = 2;
                break;
            }
            if(flag == 1){
                may_be += c;
            }
        }

        if(flag == 2 and may_be.size()) fout << may_be << endl;
    }
}