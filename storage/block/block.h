#include <string>

// Block クラスの宣言
class Block {
public:
    std::string prevHash; // 前のブロックのハッシュ
    std::string hash;     // このブロックのハッシュ
    std::string data;     // このブロックに含まれるデータ

    // コンストラクタ
    Block(std::string prevHash, std::string data);

    // ハッシュ計算のメソッド
    std::string calculateHash();
};
