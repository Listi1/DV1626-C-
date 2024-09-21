#include "value_sorter_utils.hpp"

/**
 * Sorts an array of values in increasing order.
 *
 * @param values An array of values to sort
 * @param size Size of the array
 */
void sort(int values[], int size)
{
    for (int i = size - 1; i >= 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (values[j] > values[j + 1])
            {
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
}

/**
 * Verifies that an array is sorted.
 *
 * @param values An array of values to verify
 * @param size Size of the array
 * @return true if the array is sorted, otherwise false.
 */
bool verify_sorted_array(int values[], int size)
{
    bool is_sorted = true;
    for (int i = 0; i < size - 1 && is_sorted; ++i)
        is_sorted = (values[i] <= values[i + 1]);
    return is_sorted;
}

/**
 * Verifies that an array is sorted and only contains even numbers.
 *
 * @param values An array of values to verify
 * @param size Size of the array
 * @return true if the array is sorted and only contains even numbers, or false
 *         if the array is not sorted or at least one odd value can be found.
 */
bool verify_sorted_even_array(int values[], int size)
{
    bool is_sorted = true;
    bool is_even = true;
    for (int i = 0; i < size - 1 && is_sorted && is_even; ++i)
    {
        is_sorted = (values[i] <= values[i + 1]);
        is_even = (values[i] % 2 == 0) && (values[i + 1] % 2 == 0);
    }
    return is_sorted && is_even;
}
