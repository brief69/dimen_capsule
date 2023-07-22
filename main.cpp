#include <iostream>
#include "block.h"
#include "chain.h"

int main() {
    // 新しいブロックチェーンの作成
    Blockchain capsuleChain;

    // データを追加
    capsuleChain.addBlock("Block 1 Data");
    capsuleChain.addBlock("Block 2 Data");

    // ブロックチェーンの出力
    for (const Block& block : capsuleChain.chain) {
        std::cout << "Previous Hash: " << block.prevHash << std::endl;
        std::cout << "Data: " << block.data << std::endl;
        std::cout << "Hash: " << block.hash << std::endl;
        std::cout << "------------" << std::endl;
    }

    return 0;
}
