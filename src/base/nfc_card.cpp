#include "nfc_card.h"
#include <stdio.h>


NFCCard::NFCCard()
{
}

void NFCCard::ScanInit()
{
    nfcInit(NFC_OpType_RawNFC);
}

void NFCCard::ScanExit()
{
    nfcExit();
}

void NFCCard::ScanCard(u16 timeout)
{
    nfcStartScanning(NFC_STARTSCAN_DEFAULTINPUT);
    nfcGetTagState(this->nfc_state);

    printf("\x1b[0;0H%s", "Scanning for card...");

    while (1)
    {
        hidScanInput();

        u32 kDown = hidKeysDown();

        if(kDown & KEY_START)
        {
            break;
        }

        switch (*this->nfc_state)
        {
        case NFC_TagState_Uninitialized:
            break;
        case NFC_TagState_ScanningStopped:
            break;
        case NFC_TagState_Scanning:
            continue;
        case NFC_TagState_InRange:
            nfcGetTagInfo(this->nfc_info);
            this->printData();
            break;
        case NFC_TagState_OutOfRange:
            continue;
        case NFC_TagState_DataReady:
            break;
        }
    }

    nfcStopScanning();
}

void NFCCard::printData()
{
    printf("\x1b[20;0H");
    for(int i = 0; i < 0x28; i++)
    {
        printf("0x%hhX\n", this->nfc_info->id[i]);
    }
}

