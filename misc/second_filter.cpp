#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream fin("raw2.txt");
    ofstream fout("in_bangla.txt");
    string line;
    int line_number = 1;
    while(getline(fin, line)){
        if(line_number % 3 == 0) fout << line << endl;
        line_number++;
    }
}