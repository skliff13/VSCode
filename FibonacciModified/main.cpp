#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

class InfiniteInt{
public:
    vector<char> digits;
    const map<int, char> to_char = {{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'},
                                    {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}};
    const map<char, int> to_int = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4},
                                   {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}};
    
    InfiniteInt() {digits = vector<char>({'0'});}
    InfiniteInt(char one_digit) {digits = vector<char>({one_digit});}
    InfiniteInt(string val) {digits = vector<char>(val.rbegin(), val.rend());}
    InfiniteInt(int val) {
        string str_val = to_string(val);
        digits = vector<char>(str_val.rbegin(), str_val.rend());
    }
    InfiniteInt(InfiniteInt& other) {digits = other.digits;}

    string as_string(){
        return string(digits.rbegin(), digits.rend());
    }
    
    void operator+=(InfiniteInt & other) {
        *this += other.digits;
    }
    void operator+=(vector<char> & other) {
        if (other.size() == 1 && other[0] == '0')
            return;
        if (digits.size() == 1 && digits[0] == '0'){
            digits = other;
            return;
        }

        vector<char> * d1 = &digits;
        vector<char> * d2 = &other;
        
        int carry = 0;
        int max_len = max(d1->size(), d2->size());

        vector<char> result;
        for (int i = 0; i < max_len; i++) {
            int c1 = i < d1->size() ? to_int.at(d1->at(i)) : 0;
            int c2 = i < d2->size() ? to_int.at(d2->at(i)) : 0;
            int all_sum = c1 + c2 + carry;
            result.push_back(to_char.at(all_sum % 10));
            carry = all_sum / 10;
        }
        
        if (carry > 0)
            result.push_back(to_char.at(carry));
        while (result.size() > 1 && result[result.size() - 1] == '0')
            result.pop_back();
        
        digits = result;
    }
    
    void operator*=(InfiniteInt & other) {
        *this *= other.digits;
    }
    void operator*=(vector<char> & other) {
        if ((digits.size() == 1 && digits[0] == '0') ||
            (other.size() == 1 && other[0] == '0')) {
            digits = vector<char>({'0'});
            //cout << "mult 0" << endl;
            return;
        }

        vector<char> * d1 = &digits;
        vector<char> * d2 = &other;

        InfiniteInt result;
        for (int j = 0; j < d2->size(); j++) {
            int c2 = to_int.at(d2->at(j));
            
            if (c2 == 0)
                continue;
            
            int carry = 0;
            vector<char> inter;
            for (int z = 0; z < j; z++)
                inter.push_back('0');
            
            for (int i = 0; i < d1->size(); i++){
                int c1 = to_int.at(d1->at(i));
                int all_sum = c1 * c2 + carry;
                inter.push_back(to_char.at(all_sum % 10));
                carry = all_sum / 10;
            }
    
            if (carry > 0)
                inter.push_back(to_char.at(carry));
            while (inter.size() > 1 && inter[inter.size() - 1] == '0')
                inter.pop_back();
            
            result += inter;
            inter.clear();
        }
        
        digits = result.digits;
    }
};

string fibonacciModified(int t1, int t2, int n) {
    InfiniteInt i1(t1);
    InfiniteInt i2(t2);
    for (int i = 2; i < n; i++){
        InfiniteInt temp(i2);
        i2 *= i2;
        i2 += i1;
        i1.digits = temp.digits;
        //cout << "(" << i << ") " << i2.as_string() << endl;
    }
        
    return i2.as_string();
}

int main(){
    string result = fibonacciModified(2, 0, 12);
    cout << result << endl;
}
