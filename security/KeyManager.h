// KeyManager.h

#ifndef KEYMANAGER_H
#define KEYMANAGER_H

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <string>

class KeyManager {
public:
    KeyManager();
    ~KeyManager();

    std::string getPublicKey();
    std::string getPrivateKey();

private:
    RSA* keypair;
    std::string publicKey;
    std::string privateKey;
};

#endif // KEYMANAGER_H
