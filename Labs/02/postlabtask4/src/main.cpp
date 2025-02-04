//ibrahim johar farooqi
//23k-0074
//bai-4a
//os lab - post lab - task 4

#include <iostream>
#include "LetterCount.h"
#include "WordCount.h"
#include "LineCount.h"
using namespace std;

int main()
{
    string filename = "task4output.txt";

    LetterCount letter_counter;
    WordCount word_counter;
    LineCount line_counter;

    int letters = letter_counter.count_letters(filename);
    int words = word_counter.count_words(filename);
    int lines = line_counter.count_lines(filename);

    if (letters != -1) cout << "letters: " << letters << "\n";
    if (words != -1) cout << "words: " << words << "\n";
    if (lines != -1) cout << "lines: " << lines << "\n";

    return 0;
}
