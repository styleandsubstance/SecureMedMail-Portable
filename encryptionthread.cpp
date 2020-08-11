#include "encryptionthread.h"


EncryptionThread::EncryptionThread(QString password, QString inputPath, QString encryptedPath)
{
    this->password = password;
    this->inputPath = inputPath;
    this->encryptedPath = encryptedPath;
}

EncryptionThread::~EncryptionThread()
{

}

void EncryptionThread::run()
{
    CkCrypt2 crypt;

    bool success = crypt.UnlockComponent("SACHINCrypt_tP6Vg2VFYVAb");
    if (success != true) {
        //std::cout << crypt.lastErrorText() << "\r\n";
        qDebug() << "Unable to unlock component" << endl;
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


//    EncryptionProgress *encryptionProgress = new EncryptionProgress();
//    encryptionProgress->setEncryptionThread(this);
//    crypt.put_EventCallbackObject(encryptionProgress);


    ChilkatEncryptionProgress *progress = new ChilkatEncryptionProgress();
    progress->setThread(this);
    crypt.put_EventCallbackObject(progress);



    crypt.CkEncryptFile(this->inputPath.toStdString().c_str(), this->encryptedPath.toStdString().c_str());

//    delete encryptionProgress;
    delete progress;
}

//void EncryptionThread::ReportProgress(int pctDone)
//{
//    emit Progress(pctDone);
//}

