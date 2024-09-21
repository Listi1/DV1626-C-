#ifndef VALUE_SORTER_UTILS
#define VALUE_SORTER_UTILS

/**
 * Sorts an array of values in increasing order.
 *
 * @param values An array of values to sort
 * @param size Size of the array
 */
void sort(int values[], int size);

/**
 * Verifies that an array is sorted.
 *
 * @param values An array of values to verify
 * @param size Size of the array
 * @return true if the array is sorted, otherwise false.
 */
bool verify_sorted_array(int values[], int size);

/**
 * Verifies that an array is sorted and only contains even numbers.
 *
 * @param values An array of values to verify
 * @param size Size of the array
 * @return true if the array is sorted and only contains even numbers, or false
 *         if the array is not sorted or at least one odd value can be found.
 */
bool verify_sorted_even_array(int values[], int size);

#endif // VALUE_SORTER_UTILS
