// KeyManager.cpp

#include "KeyManager.h"
#include <openssl/bio.h>

// コンストラクタ: 公開鍵と秘密鍵を生成
KeyManager::KeyManager() {
    keypair = RSA_generate_key(2048, RSA_F4, nullptr, nullptr);

    BIO* pub = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPublicKey(pub, keypair);
    size_t pub_len = BIO_pending(pub);
    publicKey.resize(pub_len);
    BIO_read(pub, &publicKey[0], pub_len);
    BIO_free_all(pub);

    BIO* pri = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPrivateKey(pri, keypair, nullptr, nullptr, 0, nullptr, nullptr);
    size_t pri_len = BIO_pending(pri);
    privateKey.resize(pri_len);
    BIO_read(pri, &privateKey[0], pri_len);
    BIO_free_all(pri);
}

// デストラクタ
KeyManager::~KeyManager() {
    RSA_free(keypair);
}

// 公開鍵を取得
std::string KeyManager::getPublicKey() {
    return publicKey;
}

// 秘密鍵を取得
std::string KeyManager::getPrivateKey() {
    return privateKey;
}
