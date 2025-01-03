#include <iostream>
#include "validation.h"
#include "SimpleVector.h"

int main() {

    SimpleVector<int> vec2(7);
    vec2.push(50);
    vec2.push(456123);
    SimpleVector<int> vec(vec2);


    std::cout << "���� ũ��: " << vec.size() << std::endl;
    std::cout << "�ִ� �뷮: " << vec.capacity() << std::endl;

    vec.pop();
    std::cout << "�� ���� �� ���� ũ��: " << vec.size() << std::endl;

    int value;
    std::cout << "���� �Է��ϼ��� (���� �Է� �� ����, -1 �Է� �� �ִ� �뷮 ����): " << std::endl;
    while (true) {
        std::cout << "�Է�: ";
        std::cin >> value;

        if (isInvalidInput()){
            std::cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << std::endl;
            continue;
        }
        if (value == -1) {
            int newCapacity;
            std::cout << "���� �迭�� �ִ� �뷮�� " << vec.capacity() << "�Դϴ�." << std::endl;
            std::cout << "�� �뷮�� �Է��ϼ��� (���� �뷮���� �۰� ������ �� �����ϴ�): ";
            std::cin >> newCapacity;

            if (isInvalidInput()) {
                std::cout << "��ȿ���� ���� �뷮�Դϴ�. ������ ����մϴ�." << std::endl;
                continue;
            }

            vec.resize(newCapacity);
            continue;
        }
        if (value < 0) {
            break; // ���� �Է� �� ����
        }

        vec.push(value); // ��ȿ�� �� �߰�
    }

    std::cout << "���� ũ��: " << vec.size() << std::endl;
    std::cout << "�ִ� �뷮: " << vec.capacity() << std::endl;
    vec.sortData();
    vec.print();
    return 0;
}
