#include <iostream>
#include <windows.h>

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
    bool check(const T& expected, const T& actual) {
        if (expected == actual) {
            return true;
        }
        else {
            std::cerr << "Expected result is " << expected << ", but actual is " << actual << "." << std::endl;
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
bool tvector_def_init() {
    TVector<int> actual_result;
    TVector<int> expected_result;

    return TestSystem::check(expected_result, actual_result);
}
bool tvector_size_init() {
    TVector<int> actual_result(5);
    TVector<int> expected_result(5, 0);

    return TestSystem::check(expected_result, actual_result);
}
bool tvector_initialize_list_init() {
    TVector<int> actual_result = { 1, 1, 1, 1, 1 };
    TVector<int> expected_result(5, 1);

    return TestSystem::check(expected_result, actual_result);
}
bool tvector_data() {
    TVector<int> vec = { 1, 2, 3, 4, 5 };
    int actual_result = *vec.data();
    int expected_result = 1;

    return TestSystem::check(expected_result, actual_result);
}
bool tvector_size() {
    TVector<int> vec = { 1, 2, 3, 4, 5 };
    int actual_result = vec.size();
    int expected_result = 5;

    return TestSystem::check(expected_result, actual_result);
}
bool tvector_capacity() {
    TVector<int> vec = { 1, 2, 3, 4, 5 };
    int actual_result = vec.capacity();
    int expected_result = 15;

    return TestSystem::check(expected_result, actual_result);
}
bool tvector_front() {
    TVector<int> vec = { 1, 2, 3, 4, 5 };
    int actual_result = vec.front();
    int expected_result = 1;

    return TestSystem::check(expected_result, actual_result);
}
bool tvector_back() {
    TVector<int> vec = { 1, 2, 3, 4, 5 };
    int actual_result = vec.back();
    int expected_result = 5;

    return TestSystem::check(expected_result, actual_result);
}
bool tvector_push_back() {
    TVector<int> actual_result = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    actual_result.push_back(16);
    TVector<int> expected_result = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

    return TestSystem::check(expected_result, actual_result);
}
bool tvector_push_front() {
    TVector<int> actual_result = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    actual_result.push_front(1);
    TVector<int> expected_result = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

    return TestSystem::check(expected_result, actual_result);
}
bool tvector_insert() {
    TVector<int> actual_result = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    actual_result.insert(actual_result.begin() + 2, 12);
    TVector<int> expected_result = { 2, 3, 12, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

    return TestSystem::check(expected_result, actual_result);
}
#pragma endregion

int main() {
    TestSystem::print_init_info();
    TestSystem::start_test(tvector_def_init, "def_init");
    TestSystem::start_test(tvector_size_init, "size_init");
    TestSystem::start_test(tvector_initialize_list_init, "initialize_list_init");
    TestSystem::start_test(tvector_data, "get_data");
    TestSystem::start_test(tvector_size, "get_size");
    TestSystem::start_test(tvector_capacity, "get_capacity");
    TestSystem::start_test(tvector_front, "get_front");
    TestSystem::start_test(tvector_back, "get_back");
    TestSystem::start_test(tvector_push_back, "push_back");
    TestSystem::start_test(tvector_push_front, "push_front");
    TestSystem::start_test(tvector_insert, "insert");
    TestSystem::print_final_info();
    return 0;
}
