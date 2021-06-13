#include<bits/stdc++.h>
using namespace std;

vector<string> fix;  //values <= 100;
vector<string> extra = {"শত", "হাজার", "লক্ষ", "কোটি"};

void init(){
    ifstream fin("0-100.txt");
    string line;
    while(getline(fin, line)){
        fix.push_back(line);
    }
}

string remove_pre_zero(string s){
    string ret = "";
    int st = 0;
    while(s[st] == '0') st++;
    for(int i = st; i < s.size(); i++) ret += s[i];
    return ret;
}

string last_digits(string &number, int cnt){
    string ret = "";
    if(number.empty()) return ret;
    while(cnt--){
        if(number.size()){
            ret += number.back();
            number.pop_back();
        }
    }
    reverse(ret.begin(), ret.end());
    if(ret.size()) ret = remove_pre_zero(ret);
    return ret;
}

string in_bangla_words(string s){
    string number = s, now;
    vector<string> res;

    //convert last two digits;
    now = last_digits(number, 2);
    if(now.size()) res.push_back(fix[stoi(now)]);

    //calculate for shoto, 1 digit;
    now = last_digits(number, 1);
    if(now.size()){
        res.push_back(extra[0]);
        res.push_back(fix[stoi(now)]);
    }

    //for hazar, 2 digts;
    now = last_digits(number, 2);
    if(now.size()){
        res.push_back(extra[1]);
        res.push_back(fix[stoi(now)]);
    }

    //for lakh, 2 digts;
    now = last_digits(number, 2);
    if(now.size()){
        res.push_back(extra[2]);
        res.push_back(fix[stoi(now)]);
    }

    // for koti, 3 digits
    if(number.size()){
        res.push_back(extra[3]);
        //convert two digits;
        now = last_digits(number, 2);
        if(now.size()) res.push_back(fix[stoi(now)]);

        //calculate for shoto, 1 digit;
        now = last_digits(number, 1);
        if(now.size()){
            res.push_back(extra[0]);
            res.push_back(fix[stoi(now)]);
        }
    }
    reverse(res.begin(), res.end());
    string ret = "";
    for(auto i: res){
        ret += i;
        ret += " ";
    }
    return ret;
}

string fraction_bangla(string s){
    vector<string> res;
    while(s.size()){
        string now = ""; now += s.back();
        res.push_back(fix[stoi(now)]);
        s.pop_back();
    }
    reverse(res.begin(), res.end());
    
    string ret = "";
    for(auto i: res){
        ret += " ";
        ret += i;
    }
    return ret;
}
string convert_three_digits(string s){
    // cout << s << endl;
    string ret = "";
    s = remove_pre_zero(s);
    if(s.empty()) return "";
    if(s.size() <= 2){
        ret = fix[stoi(s)];
    }else{
        string temp = "";
        temp += s[0];
        ret += fix[stoi(temp)];
        ret += " "; ret += extra[0]; ret += " ";
        temp = "";
        temp += s[1]; temp += s[2];
        temp  = remove_pre_zero(temp);
        if(temp.size()) ret += fix[stoi(temp)];
    }
    // cout << ret << endl;
    return ret;
}

string in_words_english(string s){
    vector<string> res;
    int cnt = 0;
    while(s.size()){
        
        string now = "";
        if(s.size()) {
            now += s.back(); s.pop_back();
        }
        if(s.size()) {
            now += s.back(); s.pop_back();
        }
        if(s.size()) {
            now += s.back(); s.pop_back();
        }

        reverse(now.begin(), now.end());
        now = remove_pre_zero(now);
        if(cnt == 1 and now.size()) res.push_back(extra[1]);
        if(cnt == 2 and now.size()) res.push_back("মিলিয়ন");
        if(cnt == 3 and now.size()) res.push_back("বিলিয়ন");
        if(now.size())res.push_back(convert_three_digits(now));
        cnt++;
    }
    reverse(res.begin(), res.end());
    string ret = "";
    for(auto i: res){
        ret += i;
        ret += " ";
    }
    return ret;

}

string round_two(string st){
    string temp = ".";
    temp += st;
    double d = stod(temp);
    stringstream stream;
    stream << std::fixed << std::setprecision(2) << d;
    string s = stream.str();
    return s;
}

string remove_comma(string s){
    string ret = "";
    for(char c: s) if(c != ',') ret += c;
    return ret;
}

int main(){
    init();
    string number;

    while(cin >> number){
        string backup = number;
        number = remove_comma(number);

        //check if number is 0
        if(count(number.begin(), number.end(), '0') == number.size()){
            cout << fix[0] << endl;
            continue;
        }

        number = remove_pre_zero(number);
        vector<string> res, doshomik;
        string now = "", left = "", right = "";
        int dosh = 0;
        for(char c: number){
            if(c == '.'){
                dosh = 1;
                continue;
            }
            if(dosh){
                right += c;
            }else{
                left += c;
            }
        }

        /* this program will work upto 999 crore. if the input is greater consider using
        a loop */

        if(left.size() > 10){
            cout << "Input is greater than 999 crore!" << endl;
            cout << "Enter another value." << endl;
            continue;
        }


        //check if the user wants to view the value in million or lakh;
        int opt;
        cout << "1. In normal bangla." << endl;
        cout << "2. In bangla taka." << endl;
        cout << "3. In normal English." << endl;
        cout << "4. In English dollar." << endl;
        cout << "Enter your option: ";
        cin >> opt;

        if(opt == 1){
            // cout << left << " " << right << endl;
            cout << in_bangla_words(left);
            if(dosh){
                cout << "দশমিক";
                cout << fraction_bangla(right);
            }
            cout << endl;
        }else if(opt == 2){            
            if(dosh){
                right = round_two(right);
                if(right[0] == '1'){
                    long long temp = stol(left);
                    temp++;
                    left = to_string(temp);
                    cout << "টাকা " << in_bangla_words(left);
                }else{
                    cout << "টাকা " << in_bangla_words(left);
                    cout << "পয়সা";
                    string dd = "";
                    while(right.back() != '.'){
                        dd += right.back();
                        right.pop_back();
                    }
                    reverse(dd.begin(), dd.end());
                    cout << " " << fix[stoi(dd)];
                }
            }else{
                cout << "টাকা " << in_bangla_words(left);
            }
            cout << "মাত্র" << endl;
        }else if(opt == 3){
            cout << in_words_english(left);
            if(dosh){
                cout << "দশমিক";
                cout << fraction_bangla(right);
            }
            cout << endl;
        }else if(opt == 4){
            if(dosh){
                right = round_two(right);
                if(right[0] == '1'){
                    long long temp = stol(left);
                    temp++;
                    left = to_string(temp);
                    cout << "ডলার " << in_words_english(left);
                }else{
                    cout << "ডলার " << in_words_english(left);
                    cout << "সেন্ট ";
                    string dd = "";
                    while(right.back() != '.'){
                        dd += right.back();
                        right.pop_back();
                    }
                    reverse(dd.begin(), dd.end());
                    cout << " " << fix[stoi(dd)];
                }
            }else{
                cout << "ডলার " << in_words_english(left);
            }
            cout << " মাত্র" << endl;
        }      
    }
}