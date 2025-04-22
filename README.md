# RingBuffer

1次元配列で2次元配列を扱いたい！

## 使い方

- ほしい次元の配列をコンストラクタで定義する

今回は3*8配列を使いたいので、変数型と合わせてこのように定義します
```cpp
const uint8_t dim = 3;
const uint8_t size = 8;
RingBuffer<int> rb(dim, size);
```

- データの入力

今回は3*8配列を定義したので、3要素の配列のポインタを渡します
```cpp
int data[3] = {};
data[0] = 1;
data[1] = 2;
data[2] = 3;

rb.SetData(data);
```

- データの取得

最新のnデータを取得できます
今回は4データを取得するので、3×4で12要素の配列を利用します

```cpp
int result[12] = {};

rb.GetData(result, 4):
```

データはこのように格納されています
```cpp
result[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
```

各要素に分割したいときは、このように書いてください
```cpp
int data1[4];
int data2[4];
int data3[4];

for(int i=0; i<4; i++){
    
    data1[i] = result[i];
    data2[i] = result[i+1];
    data3[i] = result[i+2];
}
```
