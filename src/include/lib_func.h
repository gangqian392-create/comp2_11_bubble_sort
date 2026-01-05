#pragma once   // インクルードガード

#include <stdbool.h>

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif

typedef struct item_
{
    int key;
    char value[256];
} item;

/*
    バブルソート
    begin : 配列の先頭
    end   : 配列の最後の「次」

    +-------------+
    |             |
    |             |
    +-----+-------+ <- begin
    | key | value |
    +-----+-------+
    | key | value |
    +-----+-------+
    | key | value |
    +-----+-------+ <- end
*/
bool bubble_sort(item* begin, const item* end);

/* ===== 実装 ===== */
static inline bool bubble_sort(item* begin, const item* end)
{
    // 引数チェック
    if (begin == NULL || end == NULL || begin >= end) {
        return false;
    }

    int count = (int)(end - begin);

    // バブルソート（key 昇順）
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (begin[j].key > begin[j + 1].key) {
                // 構造体を丸ごと交換
                item temp = begin[j];
                begin[j] = begin[j + 1];
                begin[j + 1] = temp;
            }
        }
    }

    return true;
}

#ifdef __cplusplus
} // extern "C"
#endif