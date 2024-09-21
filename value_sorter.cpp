#include <string> // managing strings
#include <fstream> // reading/writing files
using namespace std;

/**
 * !!! IMPORTANT !!!
 * value_sorter_utils.hpp includes three functions that all MUST be called at
 * least once in order to pass the assignment.
 * 
 * Note that these functions take arrays as arguments. You have to allocate
 * your own arrays using dynamic allocations on the heap to pass this assignment.
 * 
 * The arrays you allocate MUST have the exact capacity to fill the needed
 * values, no more, no less.
 */
#include "value_sorter_utils.hpp"

/**
 * Reads a file containing values, sorts them and generates two files: one file
 * with all the sorted values and one file with the only the sorted values that
 * are even.
 *
 * @param original_file_path A file containing values to read. See format below.
 * @param sorted_file_path A file to write all values but sorted. See format below.
 * @param sorted_even_file_path A file to write all values but sorted and only
 *                              the values that are even. See format below.
 * @return true if the read reading, sorting, and file writing succeeded as
 *         expected, otherwise false.
 * 
 * Note: The format of the three files has to all be the same. The file may
 *       contain any number of values, separated with white-space, with the
 *       first value representing the number of values to read not including
 *       itself.
 * 
 * Example: If value_sorter("demo.txt", "sorted.txt", "sorted_even.txt") is called
 *          and "demo.txt" has the following content:
 * 
 *              demo.txt:
 *                  3 32513 12 915
 * 
 *          then the two following files should be generated:
 * 
 *              sorted.txt:
 *                  3 12 915 32513
 *     
 *              sorted_even.txt:
 *                  1 12
 */
bool value_sorter(const std::string& original_file_path, const std::string& sorted_file_path, const std::string& sorted_even_file_path) {
    fstream original_file, sorted_file, sorted_even_file;
    ifstream original_file_exists;

    original_file_exists.open(original_file_path); //kollar om filen finns, annars k�rs inget
    if (original_file_exists) {

        original_file.open(original_file_path, ios::in);
        int num_count = 0;    //r�knar hur m�nga nummer som finns i dokumentet, b�rjar p� -1 f�r att skippa det f�rsta
        string num;
        int remove_first;  //anv�nds f�r att skriva f�rsta v�rdet till d� vi inte vill ha det
        original_file >> remove_first;
        while (original_file >> num) {  //k�rs medans det fortfarande finns nummer att k�ra genom
            num_count++;
        }
        original_file.close();

        original_file.open(original_file_path, ios::in);
        original_file >> remove_first;  
        int* number_array = new int[num_count];   //skapar en array som �r lika l�ng som m�ngden nummer
        for (int i = 0; i < num_count; i++) {
            original_file >> number_array[i];  //skriver fr�n filen till arrayen
        }
        original_file.close();

        sort(number_array, num_count);   //sorterar arrayen
        bool sorted_all = verify_sorted_array(number_array, num_count);

        sorted_file.open(sorted_file_path, ios::out);  //skriver sorterade arrayen till ett nytt text dokument
        sorted_file << num_count << " ";
        for (int i = 0; i < num_count; i++) {
            sorted_file << number_array[i] << " ";
        }
        sorted_file.close();

        int even_num_count = 0;     
        for (int i = 0; i < num_count; i++) {     //r�knar m�ngden j�mna tal
            if (number_array[i] % 2 == 0) {
                even_num_count++;
            }
        }

        int* even_number_array = new int[even_num_count];
        int x = 0;

        sorted_even_file.open(sorted_even_file_path, ios::out);   //skriver sorterade och j�mna arrayen till ett nytt text dokument
        sorted_even_file << even_num_count << " ";
        for (int i = 0; i < num_count; i++) {
            if (number_array[i] % 2 == 0) {
                even_number_array[x] = number_array[i];
                sorted_even_file << even_number_array[x] << " ";
                x++;
            }
        }
        sorted_even_file.close();

        bool sorted_even = verify_sorted_even_array(even_number_array, even_num_count);

        delete[] even_number_array;  //raderar b�da arrayerna
        delete[] number_array;

        if (sorted_even && sorted_all) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}
