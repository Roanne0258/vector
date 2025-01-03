#ifndef SIMPLE_VECTOR_H
#define SIMPLE_VECTOR_H
#include <iostream>
#include <algorithm>

template <typename T>
class SimpleVector {
private:
	T* arr;          // 동적 배열
	int currentSize;        // 현재 원소 개수
	int currentCapacity;    // 배열의 최대 크기
public:
    SimpleVector() : currentSize(0), currentCapacity(10) {
        arr = new T[currentCapacity];
    }

    SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity) {
        arr = new T[currentCapacity];
    }

    // 복사 생성자
    SimpleVector(const SimpleVector& other)
        : currentSize(other.currentSize), currentCapacity(other.currentCapacity) {
        arr = new T[currentCapacity];

        // 데이터 복사
        for (int i = 0; i < currentSize; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // 소멸자: 동적 배열 해제
    ~SimpleVector() {
        delete[] arr; // 메모리 해제
    }

    void push(const T& value) {
        if (size() < capacity()) {
            arr[currentSize++] = value;
        }
        else {
            reallocate(currentCapacity + 5);
            arr[currentSize++] = value;
            std::cout << "현재 크기: " << size() << std::endl;
            std::cout << "최대 용량: " << capacity() << std::endl;
            std::cout << "배열이 가득 찼습니다. 용량을 5 증가시켜 데이터를 추가합니다." << std::endl;
            std::cout << "입력을 종료하려면 음수 값을 입력하세요. (-1 입력 시 최대 용량 변경)" << std::endl;
        }
    }

    void pop() {
        if (size() > 0) {
            currentSize--;
        }
        else {
            std::cout << "배열이 비어 있습니다!" << std::endl;
        }
    }

    void resize(int resizeNum) {
        if (resizeNum < currentCapacity) {
            std::cout << "새 용량은 현재 용량보다 작을 수 없습니다. 변경을 취소합니다." << std::endl;
            return;
        }
        reallocate(resizeNum);
        std::cout << "배열 용량이 " << currentCapacity << "로 변경되었습니다." << std::endl;
    }

    void sortData() {
        std::sort(arr, arr + currentSize);
    }

    int size() const {
        return currentSize; // 현재 원소 개수 반환
    }

    int capacity() const {
        return currentCapacity; // 배열의 최대 크기 반환
    }

    // 배열 재할당 및 데이터 복사 헬퍼 함수
    void reallocate(int newCapacity) {
        T* newArr = new T[newCapacity]; // 새 배열 생성
        for (int i = 0; i < currentSize; ++i) {
            newArr[i] = arr[i]; // 기존 데이터 복사
        }
        delete[] arr; // 기존 배열 해제
        arr = newArr; // 새 배열로 교체
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