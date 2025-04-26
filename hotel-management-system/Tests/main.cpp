#include <iostream>
#include <windows.h>
#include <stdexcept>

#include "TVector.h"



void set_color(int text_color, int bg_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bg_color << 4) | text_color);
}

namespace TestSystem {
    int count_success = 0, count_failed = 0;

    void start_test(bool(*test)(), const char* name_of_test) {
        set_color(2, 0);
        std::cout << "[ RUN      ]";
        set_color(7, 0);
        std::cout << name_of_test << std::endl;

        bool status = test();

        if (status == true) {
            set_color(2, 0);
            std::cout << "[       OK ]" << std::endl;
            count_success++;
        }
        else {
            set_color(4, 0);
            std::cout << "[  FAILED  ]" << std::endl;
            count_failed++;
        }
        set_color(7, 0);
    }

    template <class T>
    bool check_exp(const T& expected, const T& actual) {
        if (expected == actual) {
            return true;
        }
        else {
            std::cerr << "Expected result is " << expected << ", but actual is " << actual << "." << std::endl;
            return false;
        }
    }

    template <class T>
    bool check_unexp(const T& unexpected, const T& actual) {
        if (unexpected != actual) {
            return true;
        }
        else {
            std::cerr << "Unexpected result is " << unexpected << ", but actual is " << actual << "." << std::endl;
            return false;
        }
    }

    void print_init_info() {
        set_color(2, 0);
        std::cout << "[==========] " << std::endl;
        set_color(7, 0);
    }

    void print_final_info() {
        set_color(2, 0);
        std::cout << "[==========] ";
        set_color(7, 0);
        std::cout << count_success + count_failed << " test" << (count_success + count_failed > 1 ? "s" : "") << " ran." << std::endl;
        set_color(2, 0);
        std::cout << "[  PASSED  ] ";
        set_color(7, 0);
        std::cout << count_success << " test" << (count_success > 1 ? "s" : "") << std::endl;
        if (count_failed > 0) {
            set_color(4, 0);
            std::cout << "[  FAILED  ] ";
            set_color(7, 0);
            std::cout << count_failed << " test" << (count_failed > 1 ? "s." : ".") << std::endl;
        }
    }
};

/*
для добавления нового теста сюда добавить функцию с данными следующего теста
в формате
bool имя_тестовой_функции() {
    1. создать тестовые данные
    2. создать правильный ответ для этих тестовых данных
    3. выполнить тестируемый метод
    4. вернуть результат сравнения ожидаемого и получившегося результатов:
    return TestSystem::check(expected_result, actual_result);
}
*/

#pragma region TvectorTests
bool tvector_default_init() {
    bool actual_result = true;
    bool expected_result = true;
    TVector<int> vec;

    if (vec.data() != nullptr || vec.begin() != vec.end()) {
        actual_result = false;
    }

    return TestSystem::check_exp(expected_result, actual_result) &&
        TestSystem::check_exp((size_t)0, vec.size()) &&
        TestSystem::check_exp((size_t)0, vec.capacity());
}
bool tvector_size_init() {
    bool actual_result = true;
    bool expected_result = true;
    TVector<int> vec(25);

    if (vec.data() == nullptr || vec.begin() == vec.end()) {
        actual_result = false;
    }

    return TestSystem::check_exp(expected_result, actual_result) &&
        TestSystem::check_exp((size_t)25, vec.size()) &&
        TestSystem::check_exp((size_t)30, vec.capacity());
}
bool tvector_size_and_value_init() {
    bool actual_result = true;
    bool expected_result = true;
    TVector<int> vec(25, 5);

    if (vec.data() == nullptr || vec.begin() == vec.end()) {
        actual_result = false;
    }

    return TestSystem::check_exp(expected_result, actual_result) &&
        TestSystem::check_exp((size_t)25, vec.size()) &&
        TestSystem::check_exp((size_t)30, vec.capacity());
}
bool tvector_copy_init() {
    bool actual_result = true;
    bool expected_result = true;
    TVector<int> vec_1(25, 5);
    TVector<int> vec_2(vec_1);

    if (vec_1.data() == nullptr || vec_1.begin() == vec_1.end()) {
        actual_result = false;
    }

    if (vec_2.data() == nullptr || vec_2.begin() == vec_2.end()) {
        actual_result = false;
    }

    return TestSystem::check_exp(expected_result, actual_result) &&
        TestSystem::check_exp((size_t)25, vec_1.size()) &&
        TestSystem::check_exp((size_t)30, vec_1.capacity()) &&
        TestSystem::check_exp((size_t)25, vec_2.size()) &&
        TestSystem::check_exp((size_t)30, vec_2.capacity());
}
bool tvector_move_init() {
    bool actual_result = true;
    bool expected_result = true;
    TVector<int> vec_1(25, 5);
    TVector<int> vec_2(std::move(vec_1));

    if (vec_1.data() != nullptr || vec_1.begin() != vec_1.end()) {
        actual_result = false;
    }

    if (vec_2.data() == nullptr || vec_2.begin() == vec_2.end()) {
        actual_result = false;
    }

    return TestSystem::check_exp(expected_result, actual_result) &&
        TestSystem::check_exp((size_t)0, vec_1.size()) &&
        TestSystem::check_exp((size_t)0, vec_1.capacity()) &&
        TestSystem::check_exp((size_t)25, vec_2.size()) &&
        TestSystem::check_exp((size_t)30, vec_2.capacity());
}
bool tvector_initialize_list_init() {
    bool actual_result = true;
    bool expected_result = true;
    TVector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

    if (vec.data() == nullptr || vec.begin() == vec.end()) {
        actual_result = false;
    }

    return TestSystem::check_exp(expected_result, actual_result) &&
        TestSystem::check_exp((size_t)16, vec.size()) &&
        TestSystem::check_exp((size_t)30, vec.capacity());
}

bool tvector_data() {
    TVector<int> vec = { 1, 2, 3, 4, 5 };
    int actual_result = *vec.data();
    int expected_result = 1;

    return TestSystem::check_exp(expected_result, actual_result);
}
bool tvector_size() {
    TVector<int> vec = { 1, 2, 3, 4, 5 };
    int actual_result = vec.size();
    int expected_result = 5;

    return TestSystem::check_exp(expected_result, actual_result);
}
bool tvector_capacity() {
    TVector<int> vec = { 1, 2, 3, 4, 5 };
    int actual_result = vec.capacity();
    int expected_result = 15;

    return TestSystem::check_exp(expected_result, actual_result);
}
bool tvector_front() {
    TVector<int> vec = { 1, 2, 3, 4, 5 };
    int actual_result = vec.front();
    int expected_result = 1;

    return TestSystem::check_exp(expected_result, actual_result);
}
bool tvector_back() {
    TVector<int> vec = { 1, 2, 3, 4, 5 };
    int actual_result = vec.back();
    int expected_result = 5;

    return TestSystem::check_exp(expected_result, actual_result);
}

bool tvector_push_back() {
    TVector<int> actual_result = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    actual_result.push_back(16);
    TVector<int> expected_result = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

    return TestSystem::check_exp(expected_result, actual_result);
}
bool tvector_push_front() {
    TVector<int> actual_result = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    actual_result.push_front(1);
    TVector<int> expected_result = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

    return TestSystem::check_exp(expected_result, actual_result);
}
bool tvector_insert() {
    TVector<int> actual_result = { 2, 3, 4, 5, 6, 7, 8, 9, 10};
    actual_result.insert(actual_result.begin() + 2, 12);
    TVector<int> expected_result = { 2, 3, 12, 4, 5, 6, 7, 8, 9, 10};

    return TestSystem::check_exp(expected_result, actual_result);
}

bool tvector_pop_back() {
    TVector<int> actual_result = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    
    TVector<int> expected_result = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

    return TestSystem::check_exp(expected_result, actual_result);
}

bool tvector_iterator_init() {
    TVector<int> vec = { 1, 2, 3, 4, 5 };
    bool actual_result = true;
    bool expected_result = true;

    try {
        TVector<int>::Iterator it = vec.begin();
    }
    catch (const std::exception& ex) {
        actual_result = false;
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }

    return TestSystem::check_exp(expected_result, actual_result);
}
bool tvector_iterator_dereference_operator_test() {
    TVector<int> vec = { 1, 2, 3, 4, 5 };
    bool actual_result = true;
    bool expected_result = true;

    try {
        TVector<int>::Iterator it = vec.begin();

        if (*it != 1) {
            actual_result = false;
            std::cerr << "Dereference failed. Expected 1, got " << *it << std::endl;
        }

        *it = 10;

        if (vec[0] != 10) {
            actual_result = false;
            std::cerr << "Failed to modify element through dereference." << std::endl;
        }

        ++it;

        if (*it != 2) {
            actual_result = false;
            std::cerr << "Dereference after increment failed. Expected 2, got " << *it << std::endl;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
        actual_result = false;
    }

    return TestSystem::check_exp(expected_result, actual_result);
}
bool tvector_iterator_dereference_operator_empty_test() {
    TVector<int> vec;
    bool actual_result = true;
    bool expected_result = false;

    try {
        TVector<int>::Iterator it = vec.begin();
        if (it == vec.end()) {
            throw std::out_of_range("Cannot dereference end iterator of empty vector");
        }
        int value = *it;
    }
    catch (const std::exception& ex) {
        actual_result = false;
        std::cerr << "Caught expected exception: " << ex.what() << std::endl;
    }

    return TestSystem::check_exp(expected_result, actual_result);
}

//bool tvector_iterator_arrow_operator_test() {
//    TVector<int> vect(1, 5);
//    TVector<TVector<int>> vec(1);
//    vec.push_back(vect);
//    bool actual_result = true;
//    bool expected_result = true;
//
//    try {
//        if (vec.begin()->front() != 1) {
//            actual_result = false;
//            std::cerr << "operator-> returned wrong pointer." << std::endl;
//        }
//    }
//    catch (const std::exception& ex) {
//        std::cerr << "Exception caught: " << ex.what() << std::endl;
//        actual_result = false;
//    }
//
//    return TestSystem::check_exp(expected_result, actual_result);
//}

bool tvector_iterator_add_out_off_range_exeption_test() {
    TVector<int> vect = { 1, 2, 3, 4, 5 };
    bool actual_result = true;
    bool expected_result = false;

    try {
        vect.begin() + 6;
    }
    catch (const std::exception& ex) {
        actual_result = false;
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }

    return TestSystem::check_exp(expected_result, actual_result);
}

#pragma endregion

int main() {
    TestSystem::print_init_info();
    TestSystem::start_test(tvector_default_init, "default_init");
    TestSystem::start_test(tvector_size_init, "size_init");
    TestSystem::start_test(tvector_copy_init, "copy_init");
    TestSystem::start_test(tvector_move_init, "move_init");
    TestSystem::start_test(tvector_initialize_list_init, "initialize_list_init");
    TestSystem::start_test(tvector_data, "get_data");
    TestSystem::start_test(tvector_size, "get_size");
    TestSystem::start_test(tvector_capacity, "get_capacity");
    TestSystem::start_test(tvector_front, "get_front");
    TestSystem::start_test(tvector_back, "get_back");
    TestSystem::start_test(tvector_push_back, "push_back");
    TestSystem::start_test(tvector_push_front, "push_front");
    TestSystem::start_test(tvector_insert, "insert");
    TestSystem::start_test(tvector_pop_back, "pop_back");
    TestSystem::start_test(tvector_iterator_init, "iterator_init");
    TestSystem::start_test(tvector_iterator_dereference_operator_test, "iterator_dereference_operator_test");
    TestSystem::start_test(tvector_iterator_dereference_operator_empty_test, "iterator_dereference_operator_empty_test");
    TestSystem::start_test(tvector_iterator_add_out_off_range_exeption_test, "insert_add_out_off_range_exeption_test");
    TestSystem::print_final_info();
    return 0;
}
