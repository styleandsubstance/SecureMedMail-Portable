#include "decryptionthread.h"
#include "chilkatencryptionprogress.h"

DecryptionThread::DecryptionThread(QString password, QString inputPath, QString decryptedPath)
{
    this->password = password;
    this->inputPath = inputPath;
    this->decryptedPath = decryptedPath;
}

DecryptionThread::~DecryptionThread()
{

}

void DecryptionThread::run()
{
    CkCrypt2 crypt;

    bool success = crypt.UnlockComponent("SACHINCrypt_tP6Vg2VFYVAb");
    if (success != true) {
        //std::cout << crypt.lastErrorText() << "\r\n";
        //qDebug() << "Unable to unlock component" << endl;
        return;
    }

    //  AES is also known as Rijndael.
    crypt.put_CryptAlgorithm("aes");
    //  CipherMode may be "ecb" or "cbc"
    crypt.put_CipherMode("cbc");
    //  KeyLength may be 128, 192, 256
    crypt.put_KeyLength(256);


    CkByteData iv;
    iv.appendStr(this->password.toStdString().c_str());
    crypt.put_IV(iv);


    CkByteData secret;
    secret.appendStr(this->password.toStdString().c_str());
    crypt.put_SecretKey(secret);

    ChilkatEncryptionProgress *progress = new ChilkatEncryptionProgress();
    progress->setThread((MonitorableThread *)this);
    crypt.put_EventCallbackObject(progress);

    crypt.CkDecryptFile(this->inputPath.toStdString().c_str(), this->decryptedPath.toStdString().c_str());

    delete progress;
}
