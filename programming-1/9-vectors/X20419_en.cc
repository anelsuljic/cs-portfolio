//AVERAGE LENGHT AND MOST FREQUENT LETTER

//Given a sequence of words, we wish to know: Which is the average length L
//of its words; and for every word with length L or longer, which is the most
//frequent letter (the smallest in lexicographic order in case of ties).

//The input is formed by a natural n > 0 followed by n non-empty words. Each
//word is formed exclusively by lowercase letters.
//Output: Print the average length of the words in the input sequence with
//precision 2. Additionally print, for every word with length equal or longer
//to the average one, the lowercase letter with most occurrences inside the
//word (the smallest in lexicographic order when ties).

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int LENGTH_ALPHABET = 'z' - 'a' + 1;

//Reads a sequence of strings and stores it into a vector.
//Pre: ---------
//Post: returns Vec.
vector<string> read_data() {
    int size; //natural number
    cin >> size;

    vector<string> Vec(size);

    //Reads the sequence of words and stores it into Vec.
    for (int i = 0; i < size; ++i) {
        cin >> Vec[i];
    }

    return Vec;
}

//Calculates the average lenght of a vector of words.
//Pre: a vector of strings.
//Post: returns average.
double average(const vector<string> &Words) {
    int sizeVec = Words.size();

    double sum = 0;

    //Makes the sum of leghts
    for (int i = 0; i < sizeVec; ++i) {
        sum += Words[i].size();
    }

    double average = sum / sizeVec;

    return average;
}

//Looks for the most frequent letter of a word.
//Pre: a string word.
//Post: returns result.
char most_frequent_letter(const string &word) {
    vector<int> Alphabet(LENGTH_ALPHABET, 0);

    //Counts the frequences of all the letters of word
    int sizeWord = word.size();
    for (int i = 0; i < sizeWord; ++i) {
        ++Alphabet[word[i] - 'a'];
    }

    //Looks for the most frequent letter
    int max = 0;
    char result = 'a';
    for (int j = 0; j < LENGTH_ALPHABET; ++j) {
        if (Alphabet[j] != 0 and Alphabet[j] > max) {
            max = Alphabet[j];
            result = 'a' + j;
        }
    }

    return result;
}

//Calculates the average of lenght of a vector of words and treat all of them
//that has equal or more letters than average.
//Pre: a vector of strings.
//Post: --------------
void compatible_words(vector<string> &Words) {
    //Calculates and prints the average
    double aver = average(Words);

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << aver << endl;

    //Prints the most frequent letter of all the words which size is bigger
    //than average.
    int sizeWords = Words.size();

    for (int i = 0; i < sizeWords; ++i) {
        if (Words[i].size() >= aver) {
            cout << Words[i] << ':' << ' ' << most_frequent_letter(Words[i])
                 << endl;
        }
    }
}

int main() {
    vector<string> Words = read_data();
    compatible_words(Words);
}
