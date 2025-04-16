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
    TVector<int> expected_result;
    TVector<int> actual_result;

    return TestSystem::check(expected_result, actual_result);
}
#pragma endregion

int main() {
    TestSystem::print_init_info();
    TestSystem::start_test(tvector_def_init, "def_init");
    TestSystem::print_final_info();
    return 0;
}
