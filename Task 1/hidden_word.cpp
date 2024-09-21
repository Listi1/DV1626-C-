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
3. ta f�rsta indexet i str�ngen -> g� bokstav till bokstav och leta efter bokstav p� index s� de matchar
4. om den hittar g� n�sta index och forts�tt leta i texten.
5. om den hittar alla bokst�ver innan texten �r slut return True annars False
*/