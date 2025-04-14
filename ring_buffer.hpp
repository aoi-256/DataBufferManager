#ifndef INC_RING_BUFFER_HPP_
#define INC_RING_BUFFER_HPP_

#include <cstdint>

template <typename T, uint8_t Dimensions = 2>
class RingBuffer {

    public:
        /* コンストラクタ
        * @param[in] rows: 行数（1次元の場合は全体の要素数）
        * @param[in] cols: 列数（2次元の場合のみ使用）
        */
        RingBuffer(uint8_t rows, uint8_t cols = 1) {

            if (Dimensions == 1) {

                max_index = rows - 1;
                buffer = new T[rows];

            } 
            else if (Dimensions == 2) {

                max_index = rows - 1;
                buffer_2d = new T*[rows];
                
                for(uint8_t i = 0; i < rows; ++i){

                    buffer_2d[i] = new T[cols];
                }
                cols_count = cols;

            }
            index = 0;
        }

        // デストラクタ
        ~RingBuffer() {
            if (Dimensions == 1){

                delete[] buffer;
            } 
            else if (Dimensions == 2){

                for (uint8_t i = 0; i <= max_index; ++i){

                    delete[] buffer_2d[i];
                }

                delete[] buffer_2d;
            }
        }

        /* データの入力（1次元）
        * @param[in] value: 入力するデータ
        */
        void SetValue(const T& value) {

            buffer[index] = value;

            //indexが最大の場合は0に戻す
            if(index == max_index){

                index = 0;
            }
            else{

                index ++;
            }
        }

        /* データの入力（2次元）
        * @param[in] row: 行インデックス
        * @param[in] col: 列インデックス
        * @param[in] value: 入力するデータ
        */
        void SetValue(uint8_t row, uint8_t col, const T& value) {

            buffer_2d[row][col] = value;
        }

        /* データの取得（1次元）
        * @param[in] idx: インデックス
        * @return データ
        */
        T GetValue(uint8_t idx) const {

            return buffer[idx];
        }

        /* データの取得（2次元）
        * @param[in] row: 行インデックス
        * @param[in] col: 列インデックス
        * @return データ
        */
        T GetValue(uint8_t row, uint8_t col) const {

            return buffer_2d[row][col];
        }

    private:
        uint8_t index;
        uint8_t max_index;
        uint8_t cols_count = 1; // 2次元の場合の列数
        T* buffer = nullptr;    // 1次元配列用
        T** buffer_2d = nullptr; // 2次元配列用
};

#endif /* INC_RING_BUFFER_HPP_ */
