// WORD SEARCH

// Solves word searches! Words can be written horizontally (from left to 
// right), vertically (from top to bottom) diagonally (from left to right and 
// from top to bottom).

// Input: different test data. Each test data contains three parts: the first 
//        part contains three natural numbers x, m and n not null. The second 
//        part is a sequence of x words. The third part is a matrix with m 
//        rows and n columns that represents the word search. Every symbol 
//        that appears in the words and in the word search are lowercase 
//        letters a,…,z.
// Output: for each test data print the matrix of the input, changing the 
//         letters which form part of any word to uppercase letters. Separate 
//         each letter of the word search by a space; separate each test data 
//         by an empty line.




#include <iostream>
#include <string>
#include <vector>
using namespace std;


typedef vector<char> Row;
typedef vector<Row> Matrix;



// Reads a sequence of elements and stores it into a vector.
// Pre/Input: vec.size() == n > 0; the std input channel contains a sequence
//            of "n" elements of type "elem".
// Post: "vec" contains the information read from the std input channel.
template <typename elem>
void read_vec(vector<elem> &vec)
{
    unsigned int size = vec.size();
    for (unsigned int i = 0; i < size; ++i) cin >> vec[i];
}



// Reads a pack of characters orginized as a matrix and stores it into a 
// matrix.
// Pre/Input: soup.size() == n_rows > 0; soup[0].size() == n_cols > 0; the std
//            input channel contais "n_rows" sequences of "n_cols" undercase 
//            characters.
// Post: "soup" contains the information read from the std input channel.
void read_soup(Matrix &soup)
{
    unsigned int n_rows = soup.size();
    unsigned int n_cols = soup[0].size();
    for (unsigned int i = 0; i < n_rows; ++i) {
        for (unsigned int j = 0; j < n_cols; ++j) cin >> soup[i][j];
    }
}



// Prints a matrix of characters into the std output channel.
// Pre: soup.size() == n_rows > 0; soup[0].size() == n_cols > 0.
// Post/Output: all the elements from "soup" are printed to the std output
//              channel, having one row per line and a space between columns.
void print_soup(const Matrix &soup)
{
    unsigned int n_rows = soup.size();
    unsigned int n_cols = soup[0].size();
    for (unsigned int i = 0; i < n_rows; ++i) {
        for (unsigned int j = 0; j < n_cols; ++j) {
            cout << (j == 0 ? "":" ") << soup[i][j];
        }
        cout << endl;
    }
}



// Converts an uppercase letter into its undercase form.
// Pre: 'A' <= letter <= 'Z'.
// Post: returns the undercase form of "letter".
char undcase(char letter)
{
    return letter - 'A' + 'a';
}



// Checks if a letter is undercase.
// Pre: ---
// Post: returns true iff 'a' <= letter <= 'z'. Otherwise, returns false.
bool is_undercase(char letter)
{
    return 'a' <= letter and letter <= 'z';
}



// Converts an undercase letter into its uppercase form.
// Pre: 'a' <= letter <= 'z'.
// Post: return the uppercase form of "letter".
char upcase(char letter)
{
    return letter - 'a' + 'A';
}



// Checks if a word appears on an alphabet soup given an initial position on
// it and the corresponding type of checking (horizontally, vertically,
// diagonally).
// Pre: soup.size() == n_rows > 0; soup[0].size() == n_cols > 0;
//      word.size() > 0; 0 <= word_idx <= word.size(); 0 <= row_idx <= n_rows;
//      0 <= col_idx <= n_cols; posible combinations for {row_inc, col_inc}: 
//      {0, 1} for horizontal checking, {1, 0} for vertical checking, {1, 1} 
//      for diagonal checking; correct == false; "word" is a string of 
//      undercase letters; "soup" is made by undercase or uppercase letters.
// Post: if correct == true, then all the letters checked in soup that are 
//       equal to word[word_idx..word.size()-1] are converted into uppercase.
void check_word(const string &word, Matrix &soup, unsigned int word_idx,
                unsigned int row_idx, unsigned int col_idx, 
                unsigned int row_inc, unsigned int col_inc, bool &correct)
{
    unsigned int word_size = word.size();
    unsigned int n_rows = soup.size();
    unsigned int n_cols = soup[0].size();
    
    if (word_idx == word_size) correct = true;
    else if (row_idx < n_rows and col_idx < n_cols) {
        char w_char = word[word_idx];
        char soup_char = soup[row_idx][col_idx];

        if (w_char == soup_char or w_char == undcase(soup_char)) {
            check_word(word, soup, word_idx + 1, row_idx + row_inc, 
                       col_idx + col_inc, row_inc, col_inc, correct);
            
            if (correct and is_undercase(soup_char)) {
                soup[row_idx][col_idx] = upcase(soup_char);
            }
        }
    }
}



// Given a pack of words and an alphabet soup, checks if every word is part
// from it and, if it is, then it highlights it putting the matching letters 
// in uppercase.
// Pre: soup.size() == n_rows > 0; soup[0].size() == n_cols > 0; 
//      words.size() > 0; "words" contains undercase words and "soup" is a
//      matrix made by undercase characters.
// Post: for every word from "words" that appears on "soup", "soup" contains
//       all of its appearances highlighted with the word letters' in 
//       uppercase. A word can appear more than once, with one of those three
//       modes: horizontally (from left to right), vertically (from top to 
//       bottom) and diagonally (from left to right and from top to bottom).
void solve(Matrix &soup, const vector<string> &words)
{
    unsigned int n_words = words.size();
    unsigned int n_rows = soup.size();
    unsigned int n_cols = soup[0].size();
    for (unsigned int i = 0; i < n_words; ++i) {  
        for (unsigned int j = 0; j < n_rows; ++j) {
            for (unsigned int k = 0; k < n_cols; ++k) {
                // Checks if the first letter of the current word appears in
                // soup[j][k].
                if (words[i][0] == soup[j][k] or 
                    words[i][0] == undcase(soup[j][k])) {
                    bool correct = false;
                    // Checks horizontally
                    check_word(words[i], soup, 0, j, k, 0, 1, correct);
                    correct = false;
                    // Checks vertically
                    check_word(words[i], soup, 0, j, k, 1, 0, correct);
                    correct = false;
                    // Checks diagonally
                    check_word(words[i], soup, 0, j, k, 1, 1, correct);
                }
            }
        }
    }
}



int main()
{
    unsigned int n_words, n_rows, n_cols;
    bool first = true;
    while (cin >> n_words >> n_rows >> n_cols) {
        vector<string> words(n_words);
        read_vec<string>(words);
        Matrix soup(n_rows, Row(n_cols));
        read_soup(soup);
        
        solve(soup, words);

        if (not first) cout << endl;
        else first = false;
        print_soup(soup);
    }
}