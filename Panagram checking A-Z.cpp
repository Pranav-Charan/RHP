#include <iostream>
#include <set>
using namespace std;

int main() {
    string str;
    cout << "Enter string: ";
    getline(cin, str);

    set<char> letters;

    for(char ch : str) {
        if(ch >= 'A' && ch <= 'Z')
            letters.insert(ch);
    }

    if(letters.size() == 26)
        cout << "Pangram";
    else
        cout << "Not Pangram";

    return 0;
}