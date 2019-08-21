// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"
#include <stdio.h>
#include <ctype.h>
#include <iostream>

using namespace std;

Word::Word(const string& word): word_{word}
{
	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
    //cout << word_ << endl;
    removePunc(word_);
	if (word_.empty()) throw WordContainsNoLetters{};
    toLower(word_);
    if ((signed int) word_.find(' ') != -1) throw WordContainsSpace{};
        
    
    

	// Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows to Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
    
    //cout << temp1 << " compared to " << temp2 << endl;
	if (word_ == rhs.word_) return true;
	else return false;
}

bool Word::isQueryable() const
{
    if(word_.length() > 2) return true;
    else throw WordIsNotQueryable{};
}

void Word::toLower(string &input)
{
     for(int i = 0u; i < input.length(); i ++)
    {
        if(input[i] >= 65 && input[i] <= 90) {input[i] = input[i] + 32;}
    }
}

void Word::removePunc(string &input) 
{
     for(int i = 0u; i < input.length(); i ++)
        {
            if(ispunct(input[i])) {input.erase(i--,1);}
        }
    
}