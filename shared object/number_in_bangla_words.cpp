#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<algorithm>
#include<iomanip>


using namespace std;

vector<string> fix = {"শুন্য", "এক", "দুই", "তিন", "চার", "পাঁচ", "ছয়", "সাত", "আট", "নয়", "দশ", "এগারো", "বারো", "তেরো", "চোদ্দো", "পনেরো", "ষোলো", "সতেরো", "আঠারো", "উনিশ", "বিশ", "একুশ", "বাইশ", "তেইশ", "চব্বিশ", "পঁচিশ", "ছাব্বিশ", "সাতাশ", "আটাশ", "ঊনত্রিশ", "ত্রিশ", "একত্রিশ", "বত্রিশ", "তেত্রিশ", "চৌত্রিশ", "পৈন্তীরিশ", "ছোতিরিশ", "সাইত্রিশ", "আটত্রিশ", "ঊনচল্লিশ", "চল্লিশ", "একচল্লিশ", "বিয়াল্লিশ", "তেতাল্লিশ", "চুয়াল্লিশ", "পঁয়তাল্লিশ", "ছিচল্লিশ", "সাতচল্লিশ", "আটচল্লিশ", "ঊনপঞ্চাশ", "পঞ্চাশ", "একান্নো", "বাহান্নো", "তেপ্পান্নো", "চুযান্নো", "পঞ্চান্নো", "ছাপ্পান্নো", "সাতান্নো", "আটান্নো", "ঊনষাট", "ষাট", "একষট্টি", "বাষট্টি", "তেষট্টি", "চৌষট্টি", "পৈন্ষট্টি", "ছেষট্টি", "সাতষট্টি", "আটষট্টি", "উনসত্তর", "সত্তর", "একাত্তর", "বাহাত্তর", "তেহাত্তর", " চহত্তর", "পচাত্তর", "ছিয়াত্তর", "সাতাত্তর", "আটাত্তর", "উনাশি", "আশি", "একাশি", "বিরাশি", "তিরাশি", "চুরাশি", "পঁচাশি", "ছিয়াশি", "সাতাশি", "আটাশি", "ঊনোনব্বই", "নব্বুই", "একানব্বই", "বিরানব্বই", "তিরানব্বই", "চুরানব্বই", "পঁচানব্বই", "ছিয়ানব্বই", "সাতানব্বই", "আটানব্বই", "নিরানব্বই", "একশো"};
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

pair<pair<string, string>, int> left_right_dosh(string number){
    number = remove_comma(number);
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
            exit(1);
        }
    return {{left, right}, dosh};
}

string print_in_bangla(string number){
    auto d = left_right_dosh(number);
    vector<string> res, doshomik;
    string now = "", left = d.first.first, right = d.first.second;
    int dosh = d.second;
    string ret = "";
    
    ret += in_bangla_words(left);
    if(dosh){
        ret += "দশমিক";
        ret += fraction_bangla(right);
    }
    return ret;
}

string print_in_bangla_taka(string number){
    auto d = left_right_dosh(number);
    vector<string> res, doshomik;
    string now = "", left = d.first.first, right = d.first.second;
    int dosh = d.second;
    string ret = "";

    if(dosh){
        right = round_two(right);
        if(right[0] == '1'){
            long long temp = stol(left);
            temp++;
            left = to_string(temp);
            ret += "টাকা ";
            ret += in_bangla_words(left);
        }else{
            ret += "টাকা ";
            ret += in_bangla_words(left);
            ret += "পয়সা";
            string dd = "";
            while(right.back() != '.'){
                dd += right.back();
                right.pop_back();
            }
            reverse(dd.begin(), dd.end());
            ret += " ";
            ret += fix[stoi(dd)];
            ret += " ";
        }
    }else{
        ret += "টাকা ";
        ret += in_bangla_words(left);
    }
    ret += "মাত্র";

    return ret;
}

string print_in_english(string number){
    auto d = left_right_dosh(number);
    vector<string> res, doshomik;
    string now = "", left = d.first.first, right = d.first.second;
    int dosh = d.second;
    string ret = "";

    ret += in_words_english(left);
    if(dosh){
        ret += "দশমিক";
        ret += fraction_bangla(right);
    }

    return ret;
}

string print_in_english_taka(string number){
    auto d = left_right_dosh(number);
    vector<string> res, doshomik;
    string now = "", left = d.first.first, right = d.first.second;
    int dosh = d.second;
    string ret = "";

    if(dosh){
        right = round_two(right);
        if(right[0] == '1'){
            long long temp = stol(left);            
            temp++;
            left = to_string(temp);
            ret += "ডলার ";
            ret += in_words_english(left);
        }else{
            ret += "ডলার ";
            ret += in_words_english(left);
            ret += "সেন্ট";
            string dd = "";
            while(right.back() != '.'){
                dd += right.back();
                right.pop_back();
            }
            reverse(dd.begin(), dd.end());
            ret += " ";
            ret += fix[stoi(dd)];
            ret += " ";
        }
    }else{
        ret += "ডলার ";
        ret += in_words_english(left);
    }
    ret += "মাত্র";

    return ret;
}

string in_word_bangla(string number, int opt){
    if(opt == 1) return print_in_bangla(number);
    else if(opt == 2) return print_in_bangla_taka(number);
    else if(opt == 3) return print_in_english(number);
    else if(opt == 4) return print_in_english_taka(number);

    return print_in_bangla(number);
}

string put_comma(string number, int type){
    //put commma in bangla taka style;
    string ret = "";
    number = remove_comma(number); 
    if(type == 1){
        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += ",";

        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += ",";

        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += ",";

        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += number.back(); number.pop_back();
    }else{ //put taka in dollar style.
        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += ",";

        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += ",";

        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += ",";

        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += number.back(); number.pop_back();
        if(number.size()) ret += number.back(); number.pop_back();
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

// int main(){
//     string number;

//     while(cin >> number){
//         //check if the user wants to view the value in million or lakh;
//         int opt;
//         cout << "1. In normal bangla." << endl;
//         cout << "2. In bangla taka." << endl;
//         cout << "3. In normal English." << endl;
//         cout << "4. In English dollar." << endl;
//         cout << "Enter your option: ";
//         cin >> opt;

//         if(opt == 1){
//             // cout << left << " " << right << endl;
//             cout << print_in_bangla(number) << endl;
//         }else if(opt == 2){            
//             cout << print_in_bangla_taka(number) << endl;
//         }else if(opt == 3){
//             cout << print_in_english(number) << endl;
//         }else if(opt == 4){
//             cout << print_in_english_taka(number) << endl;
//         }      
//     }
// }