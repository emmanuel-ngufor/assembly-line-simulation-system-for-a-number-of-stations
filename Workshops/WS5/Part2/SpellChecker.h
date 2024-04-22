#pragma once
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H

#include <string>

namespace seneca 
{
    constexpr int MAX_WORDS = 6;

    class SpellChecker 
    {
    private:
        std::string m_badWords[MAX_WORDS];      // an array with 6 misspelled words 
        std::string m_goodWords[MAX_WORDS];     // an array with the correct spelling of those 6 words 
        size_t m_cnt[MAX_WORDS]{ 0 };           // remember how many times each bad word has been replaced.

    public:
        /* receives the address of a C - style null - terminated string that holds the name of the file that
           contains the misspelled words.
          - If the file exists, this constructor loads its contents. 
          - If the file is missing, this constructor throws an exception of type const char*, with the message Bad file name!.
          - Each line in the file has the format BAD_WORD  GOOD_WORD; the two fields can be separated by any number of spaces. */
        SpellChecker(const char* filename);

        /*
         - This operator searches text and replaces any misspelled word with the correct version. 
         - It should also count how many times each misspelled word has been replaced.
         - When implementing this operator, consider the following functions: std::string::find(), std::string::replace() */
        void operator()(std::string& text);

        /* inserts into the parameter how many times each misspelled word has been replaced by the correct word using
           the current instance.
         - The format of the output is: BAD_WORD: CNT replacements<endl>
         - where BAD_WORD is to be printed on a field of size 15, aligned to the right. */
        void showStatistics(std::ostream& out) const;
    };
    

}  // namespace seneca

#endif  // !SENECA_SPELLCHECKER_H
