# RingBuffer

そのうちちゃんと書きます

とりあえずAIに丸投げtしたサンプルコード

```cpp
#include <iostream>
#include "Ringbuffer.hpp"

int main() {
    
        // 1次元リングバッファのテスト
        std::cout << "1D RingBuffer Test:" << std::endl;
        RingBuffer<int, 1> buffer1D(5); // 要素数5の1次元リングバッファ
        for (int i = 0; i < 7; ++i) {
            buffer1D.SetValue(i);
            std::cout << "Set value: " << i << ", Get value at index " << i % 5 << ": " << buffer1D.GetValue(i % 5) << std::endl;
        }

        // 2次元リングバッファのテスト
        std::cout << "\n2D RingBuffer Test:" << std::endl;
        RingBuffer<int, 2> buffer2D(3, 3); // 3x3の2次元リングバッファ
        for (uint8_t row = 0; row < 3; ++row) {
            for (uint8_t col = 0; col < 3; ++col) {
                buffer2D.SetValue(row, col, row * 10 + col);
                std::cout << "Set value at (" << (int)row << ", " << (int)col << "): " << row * 10 + col << std::endl;
            }
        }

        std::cout << "\nRetrieve values from 2D RingBuffer:" << std::endl;
        for (uint8_t row = 0; row < 3; ++row) {
            for (uint8_t col = 0; col < 3; ++col) {
                std::cout << "Value at (" << (int)row << ", " << (int)col << "): " << buffer2D.GetValue(row, col) << std::endl;
            }
        }

    return 0;
}
```
