#include<bits/stdc++.h>
using namespace std;

string in_word_bangla(string number, int tp);
int main(){
    string number;

    while(cin >> number){
        //check if the user wants to view the value in million or lakh;
        int opt;
        cout << "1. In normal bangla." << endl;
        cout << "2. In bangla taka." << endl;
        cout << "3. In normal English." << endl;
        cout << "4. In English dollar." << endl;
        cout << "Enter your option: ";
        cin >> opt;

        cout << in_word_bangla(number, opt) << endl;    
    }
}