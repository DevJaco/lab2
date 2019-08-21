// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"

Line::Line(const string& line)
{
	// Hint: some of string's member functions might come in handy here
	// for extracting words.
	line_ = line;
}


bool Line::contains(const Word& search_word) const {
	try {
		search_word.isQueryable();
		if(line_.empty()){
			return false;
		}
		else {
			try {
				Word current = Word{line_};
				
				if(current == search_word){
					return true;
				}
				else {
					return false;
				}
			}
			catch(WordContainsSpace){
				int current_space = -1;
				int next_space = (signed int)line_.find(' ');
				bool check = false;
			
				while(next_space != -1){
					string current;
					
					current = line_.substr(current_space + 1, next_space);
					current_space = next_space + current_space + 1;
					next_space = line_.substr(current_space + 1).find(' ');
					

					
					Word current_word = Word{current};
					if(current_word == search_word){
						check = true;
					}
					
					if(next_space == -1){
						current = line_.substr(current_space + 1);
						if(Word{current} == search_word){
							return true; 
						}
					}
				}
				return check;
			}
			
		}
	}
	catch(WordIsNotQueryable) {
		return false;
	}

}
