#include <iostream>
#include "validation.h"
#include "SimpleVector.h"

int main() {

    SimpleVector<int> vec2(7);
    vec2.push(50);
    vec2.push(456123);
    SimpleVector<int> vec(vec2);


    std::cout << "현재 크기: " << vec.size() << std::endl;
    std::cout << "최대 용량: " << vec.capacity() << std::endl;

    vec.pop();
    std::cout << "값 제거 후 현재 크기: " << vec.size() << std::endl;

    int value;
    std::cout << "값을 입력하세요 (음수 입력 시 종료, -1 입력 시 최대 용량 변경): " << std::endl;
    while (true) {
        std::cout << "입력: ";
        std::cin >> value;

        if (isInvalidInput()){
            std::cout << "잘못된 입력입니다. 다시 시도하세요." << std::endl;
            continue;
        }
        if (value == -1) {
            int newCapacity;
            std::cout << "현재 배열의 최대 용량은 " << vec.capacity() << "입니다." << std::endl;
            std::cout << "새 용량을 입력하세요 (현재 용량보다 작게 설정할 수 없습니다): ";
            std::cin >> newCapacity;

            if (isInvalidInput()) {
                std::cout << "유효하지 않은 용량입니다. 변경을 취소합니다." << std::endl;
                continue;
            }

            vec.resize(newCapacity);
            continue;
        }
        if (value < 0) {
            break; // 음수 입력 시 종료
        }

        vec.push(value); // 유효한 값 추가
    }

    std::cout << "최종 크기: " << vec.size() << std::endl;
    std::cout << "최대 용량: " << vec.capacity() << std::endl;
    vec.sortData();
    vec.print();
    return 0;
}
