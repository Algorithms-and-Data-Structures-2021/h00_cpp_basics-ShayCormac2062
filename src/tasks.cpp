#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    if(lhs != nullptr && rhs != nullptr) {
        int mhs = *lhs;
        *lhs = *rhs;
        *rhs = mhs;
    }
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if (num_rows > 0 && num_cols > 0) {
        int **array_2d = new int *[num_rows];
        for (int i = 0; i < num_rows; i++) {
            array_2d[i] = new int[num_cols];
            fill(array_2d[i], array_2d[i] + num_cols, init_value);
        }
        return array_2d;
    }
    return nullptr;
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if(arr_2d_target != nullptr && arr_2d_source != nullptr) {
        if (num_rows > 0 && num_cols > 0) {
            for (int i = 0; i < num_rows; i++) {
                for (int j = 0; j < num_cols; j++) {
                    arr_2d_source[i][j] = arr_2d_target[i][j];
                }
            }
            return true;
        }
    }
    return false;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    for (int i = 0; i < arr.size() / 2; i++){
        int x = arr[i];
        arr[i] = arr[arr.size() - 1 - i];
        arr[arr.size() - 1 - i] = x;
    }
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if (arr_begin != nullptr && arr_end != nullptr) {
        int change;
        while (arr_begin <= arr_end) {
            change = *arr_begin;
            *arr_begin = *arr_end;
            *arr_end = change;
            ++arr_begin;
            --arr_end;
        }
    }
}

// Задание 6
int *find_max_element(int *arr, int size) {
    if (arr != nullptr && size > 0) {
        int *max = arr;
        arr++;
        for (int i = 1; i < size; i++, arr++){
            if (*max < *arr) {
                max = arr;
            }
        }
        return max;
    }
    return nullptr;
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
    vector<int> odd_numbers;
    for(int & i : arr) {
        if (i % 2 == 1 && i > 0) odd_numbers.push_back(i);
    }
    return odd_numbers;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    vector<int> arr_c;
    sort(arr_a.begin(), arr_a.end());
    sort(arr_b.begin(), arr_b.end());
    for (int i : arr_a) {
        for (int j : arr_b) {
            if (i == j) {
                if (!arr_c.empty()) {
                    bool isOkay = true;
                    for (int w : arr_c) {
                        if (i == w) {
                            isOkay = false;
                            break;
                        }
                    }
                    if (isOkay) arr_c.push_back(i);
                } else arr_c.push_back(i);
            }
        }
    }
    return arr_c;
}