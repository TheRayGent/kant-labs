#include <iostream>
#include <vector>
#include <crtdbg.h> // Для _ASSERT_EXPR

int main() {
    std::vector<int> myVector = {1, 2, 3};
    int index = 5;

    _ASSERT_EXPR(false, L"efewefw");

    myVector[index] = 10; // Этот код не будет выполнен, если сработает _ASSERT_EXPR

    return 0;
}