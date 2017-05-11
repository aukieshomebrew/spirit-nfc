#ifndef NFC_CARD_H
#define NFC_CARD_H

#include <3ds.h>



struct NFCCardData
{
    u32 card_number;
    
};

class NFCCard
{
    public:
        NFCCard();
        ~NFCCard();

        void ScanInit();
        void ScanExit();
        void ScanCard(u16 timeout);


    private:
        NFC_TagState* nfc_state;
        NFC_TagInfo* nfc_info;

        void printData();
};

#endif