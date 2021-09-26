#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

class InfiniteInt{
public:
    string str_val;
    const map<int, char> to_char = {{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'},
                                    {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}};
    const map<char, int> to_int = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4},
                                   {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}};
    
    InfiniteInt() {str_val = "0";}
    InfiniteInt(string val) {str_val = val;}
    InfiniteInt(char val) {str_val = val;}
    InfiniteInt(int val) {str_val = to_string(val);}
    InfiniteInt(const InfiniteInt& other) {str_val = other.str_val;}
    
    void operator = (const InfiniteInt & other) {str_val = other.str_val;}
    
    void operator+=(const InfiniteInt & other) {
        *this += other.str_val;
    }
    void operator+=(const string & other) {
        //cout << "(+1) " << str_val << endl;
        //cout << "(+2) " << other << endl;
        string s1 = str_val, s2 = other;
        if (other == "0")
            return;
        if (str_val == "0"){
            str_val = other;
            return;
        }
        
        int carry = 0;
        int max_len = max(s1.length(), s2.length());

        vector<char> result;
        for (int i = 0; i < max_len; i++) {
            int c1 = i < s1.length() ? to_int.at(s1[s1.length() - i - 1]) : 0;
            int c2 = i < s2.length() ? to_int.at(s2[s2.length() - i - 1]) : 0;
            int all_sum = c1 + c2 + carry;
            result.push_back(to_char.at(all_sum % 10));
            carry = all_sum / 10;
        }
        
        if (carry > 0)
            result.push_back(to_char.at(carry));
        while (result.size() > 1 && result[result.size() - 1] == '0')
            result.pop_back();
        
        str_val = string(result.rbegin(), result.rend());
    }
    
    void operator*=(const InfiniteInt & other) {
        *this *= other.str_val;
    }
    void operator*=(const string & other) {
        //cout << "(*1) " << str_val << endl;
        string s1 = str_val, s2 = other;
        
        if (s2 == "0" || s1 == "0"){
            str_val = "0";
            cout << "mult 0" << endl;
            return;
        }

        InfiniteInt result;
        for (int j = 0; j < s2.length(); j++) {
            int c2 = to_int.at(s2[s2.length() - j - 1]);
            
            if (c2 == 0)
                continue;
            
            int carry = 0;
            vector<char> inter;
            for (int z = 0; z < j; z++)
                inter.push_back('0');
            
            for (int i = 0; i < s1.length(); i++){
                int c1 = to_int.at(s1[s1.length() - i - 1]);
                int all_sum = c1 * c2 + carry;
                inter.push_back(to_char.at(all_sum % 10));
                carry = all_sum / 10;
            }
    
            if (carry > 0)
                inter.push_back(to_char.at(carry));
            while (inter.size() > 1 && inter[inter.size() - 1] == '0')
                inter.pop_back();
            
            result += string(inter.rbegin(), inter.rend());
            inter.clear();
        }
        
        str_val = result.str_val;    }
};

string fibonacciModified(int t1, int t2, int n) {
    InfiniteInt i1(t1);
    InfiniteInt i2(t2);
    for (int i = 2; i < n; i++){
        InfiniteInt temp(i2);
        i2 *= i2;
        i2 += i1;
        i1.str_val = temp.str_val;
        cout << "(" << i << ") " << i2.str_val << endl;
    }
        
    return i2.str_val;
}

int main(){
    string result = fibonacciModified(1, 1, 20);
    cout << result << endl;
}
