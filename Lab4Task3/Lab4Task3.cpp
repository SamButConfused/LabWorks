
#include <iostream>
#include <string>
 
using namespace std;
 
int count_repeating_digits(int num) {
    int count = 0;
    string str_num = to_string(num);  // Convert the number to a string
     
    for (int i = 0; i < str_num.length(); i++) {
        for (int j = i+1; j < str_num.length(); j++) {
            if (str_num[i] == str_num[j]) {
                count++;
                break;  // Exit the inner loop once a repeating digit is found
            }
        }
    }
     
    return count;
}
 
int main() {
    int num=996677;
      
     
    int repeating_digits = count_repeating_digits(num);
    cout << "Number of repeating digits: " << repeating_digits << endl;
     
    return 0;
}