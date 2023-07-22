#include "capsule.h"
#include "block.h"
#include <string>

// ブロックを追加するメソッドの定義
void Capsule::addBlock(std::string data, std::string capsuleID) {
    std::string prevHash = chain.chain.empty() ? "" : chain.chain.back().hash;
    // ブロックにカプセルIDを含める
    data += "\nCapsule ID: " + capsuleID;
    Block newBlock(prevHash, data);
    chain.chain.push_back(newBlock);
}
