#include<iostream>
#include <algorithm>

using namespace std;

string clean_text(string sentence) {
    string res = "";
    for (int i=0; i<sentence.size(); ++i) {
       if (sentence[i] == '(') {
           while (true) {
               if (sentence[i] != ')') {
                   i++;
               } else {
                   i++;
                   break;
               }
           }
       }
       res+= sentence[i];
    }

    return res;
}


int main() {
    string input_a = "Hello (world)";
    string input_b = "INF(INI)T(E)25()03()";
    cout << clean_text(input_a) << endl;
    cout << clean_text(input_b) << endl;

    //Hello
    //INFT2503
}