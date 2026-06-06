#include <iostream>
using namespace std;

void combinations(string str, string curr, int index) {
    if (!curr.empty())
        cout << curr << endl;

    for (int i = index; i < str.length(); i++) {
        combinations(str, curr + str[i], i + 1);
    }
}

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;

    combinations(str, "", 0);

    return 0;
}