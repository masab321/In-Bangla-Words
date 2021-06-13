#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream fin("0-100.txt");
    ofstream fout("bangla_vec.txt");
    fout << "{";
    string line;
    while(getline(fin, line)){
        fout << "\"";
        fout << line;
        fout << "\"";
        fout << ", ";
    }
    fout << "}";
}