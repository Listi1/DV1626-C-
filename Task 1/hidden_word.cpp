#include <string> // managing strings
/**
 * Determine if a text contain a hidden word or not.
 * 
 * A hidden word in a text is a word that can have other characters between the
 * hidden word's own characters in that text. An example can be that the word
 * "deodorant" is hidden in the previous sentence:
 * 
 *     A hidden word in a text is a word that can have other characters between
 *          ^^   ^ ^                 ^^    ^    ^       ^
 *          de   o d                 or    a    n       t
 *	
 * The hidden word has to completely exist in the text, and the characters of
 * the hidden word has to be in order. It may exist any number of characters
 * between the hidden word's own characters.
 *
 * @param text A text to search.
 * @param word A hidden word to search for in the text.
 * @return true if the text contain the hidden word, otherwise false.
 */
bool hidden_word(const std::string& text, const std::string& word)
{
	int x = 0;
	for (int i = 0; i < text.size(); i++) {
		if (word[x] == text[i]) {
			x++;
		}
	}
	if (x == word.size()) {
		return true;
	}
	else {
		return false;
	}
}



/*
3. ta första indexet i strängen -> gå bokstav till bokstav och leta efter bokstav på index så de matchar
4. om den hittar gå nästa index och fortsätt leta i texten.
5. om den hittar alla bokstäver innan texten är slut return True annars False
*/