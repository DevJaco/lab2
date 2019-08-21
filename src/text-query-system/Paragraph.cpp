// -------------------------------------------
//					Paragraph
// -------------------------------------------

#include "Paragraph.h"

void Paragraph::addLine(const Line& line)
{
	paragraph_.push_back(line);
}

tuple<bool, vector<int>> Paragraph::contains(const Word& search_word) const
{
	bool check = false;
	vector<int> value = {};
	
	if(paragraph_.empty()){
		return {check, vector<int>{}};
	}
	else {
		for(int i = 0u; i < paragraph_.size(); i++){
			if(paragraph_[i].contains(search_word)){
				check = true;
				value.push_back(i+1);
			}
		}
		return {check, value};
	}
	return {false, vector<int>{}};
}