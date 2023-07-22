#include "chain.h"
#include "block.h"
#include <string>

// ブロックを追加するメソッドの定義
void Blockchain::addBlock(std::string data) {
    std::string prevHash = chain.empty() ? "" : chain.back().hash;
    Block newBlock(prevHash, data);
    chain.push_back(newBlock);
}
