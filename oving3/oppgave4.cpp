#include <iostream>

using namespace std;
int main() {
    //a)
    string word1;
    string word2;
    string word3;

    cout << "First word: "<< endl;
    cin >> word1;
    cout << "Second word: "<<endl;
    cin >> word2;
    cout << "Third word: "<<endl;
    cin >> word3;

    //b)
    string sentence;

    sentence = word1 + " " + word2 + " " + word3 + ".";
    cout << "Your sentence: " << sentence << endl;

    //c)
    cout << "word1 length: " << word1.length() << endl;
    cout << "word2 length: " << word2.length() << endl;
    cout << "word3 length: " << word3.length() << endl;
    cout << "Sentence length: " << sentence.length() << endl;

    //d)
    string sentence2 = sentence;

    //e)
    sentence2[9] = 'x';
    sentence2[10] = 'x';
    sentence2[11] = 'x';


    cout << "sentence: " << sentence << endl;
    cout << "sentence2: " << sentence2 << endl;

    //f)
    string sentence_start = sentence.substr(0,5);

    cout << "sentence: " << sentence << endl;
    cout << "sentence_start: " << sentence_start << endl;

    //g)
    if (sentence.find("hallo", 0) != string::npos) {
        cout << "Found \"hallo\" at index: "<< sentence.find("hallo", 0)<< " in: "<< sentence << endl;
    } else {
        cout << "Hallo not found in the sentence." << endl;
    }

    //h)
    int er_count = 0;
    int index = 0;

    while(true) {
        if (index >= sentence.length()-1) {
            break;
        }
        if (sentence.find("er", index) != string::npos) {
            index = sentence.find("er", index) + 2;
            er_count++;
        } else {
            index++;
        }
    }

    cout << "Found \"er\" " << er_count << " times." << endl;

}