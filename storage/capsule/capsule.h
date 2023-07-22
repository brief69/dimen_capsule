#include <string>
#include "chain.h"
#include "../Chain/chain.h"


// Capsule クラスの宣言
class Capsule {
public:
    // ブロックチェーン（Blockのベクター）
    Blockchain chain;

    // ブロックを追加するメソッド
    void addBlock(std::string data, std::string capsuleID = "");

    // このカプセルのID
    std::string id;
};
