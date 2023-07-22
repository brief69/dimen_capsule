#include "block.h"
#include <string>

Block::Block(std::string prevHash, std::string data) {
    this->prevHash = prevHash;
    this->data = data;
    this->hash = calculateHash();
}

std::string Block::calculateHash() {
    return prevHash + data;  // 単純な連結
}