#ifndef SIMPLE_VECTOR_H
#define SIMPLE_VECTOR_H
#include <iostream>
#include <algorithm>

template <typename T>
class SimpleVector {
private:
	T* arr;          // ���� �迭
	int currentSize;        // ���� ���� ����
	int currentCapacity;    // �迭�� �ִ� ũ��
public:
    SimpleVector() : currentSize(0), currentCapacity(10) {
        arr = new T[currentCapacity];
    }

    SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity) {
        arr = new T[currentCapacity];
    }

    // ���� ������
    SimpleVector(const SimpleVector& other)
        : currentSize(other.currentSize), currentCapacity(other.currentCapacity) {
        arr = new T[currentCapacity];

        // ������ ����
        for (int i = 0; i < currentSize; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // �Ҹ���: ���� �迭 ����
    ~SimpleVector() {
        delete[] arr; // �޸� ����
    }

    void push(const T& value) {
        if (size() < capacity()) {
            arr[currentSize++] = value;
        }
        else {
            reallocate(currentCapacity + 5);
            arr[currentSize++] = value;
            std::cout << "���� ũ��: " << size() << std::endl;
            std::cout << "�ִ� �뷮: " << capacity() << std::endl;
            std::cout << "�迭�� ���� á���ϴ�. �뷮�� 5 �������� �����͸� �߰��մϴ�." << std::endl;
            std::cout << "�Է��� �����Ϸ��� ���� ���� �Է��ϼ���. (-1 �Է� �� �ִ� �뷮 ����)" << std::endl;
        }
    }

    void pop() {
        if (size() > 0) {
            currentSize--;
        }
        else {
            std::cout << "�迭�� ��� �ֽ��ϴ�!" << std::endl;
        }
    }

    void resize(int resizeNum) {
        if (resizeNum < currentCapacity) {
            std::cout << "�� �뷮�� ���� �뷮���� ���� �� �����ϴ�. ������ ����մϴ�." << std::endl;
            return;
        }
        reallocate(resizeNum);
        std::cout << "�迭 �뷮�� " << currentCapacity << "�� ����Ǿ����ϴ�." << std::endl;
    }

    void sortData() {
        std::sort(arr, arr + currentSize);
    }

    int size() const {
        return currentSize; // ���� ���� ���� ��ȯ
    }

    int capacity() const {
        return currentCapacity; // �迭�� �ִ� ũ�� ��ȯ
    }

    // �迭 ���Ҵ� �� ������ ���� ���� �Լ�
    void reallocate(int newCapacity) {
        T* newArr = new T[newCapacity]; // �� �迭 ����
        for (int i = 0; i < currentSize; ++i) {
            newArr[i] = arr[i]; // ���� ������ ����
        }
        delete[] arr; // ���� �迭 ����
        arr = newArr; // �� �迭�� ��ü
        currentCapacity = newCapacity;
    }


    void print() const {
        std::cout << "[ ";
        for (int i = 0; i < size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "]" << std::endl;
    }
};
#endif