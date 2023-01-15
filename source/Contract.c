#include "Contract.h"

void ContractInit(ContractData* Data)
{
    //  Constants.
    Data->BlueEnemiesToPick  = 25;
    Data->CurrentPickedBlues = 0;

    Data->RedEnemiesToEvade = 25;
    Data->GreenEnemiesToEvade = 25;
    Data->YellowEnemiesToEvade  = 25;

    Data->InitSpawnEnemies = 28;
}

void ContractPickedBlue(ContractData* Data)
{
   Data->CurrentPickedBlues++; 
}

void ContractPickedRed(ContractData* Data)
{
    Data->RedEnemiesToEvade--;
}

void ContractPickedGreen(ContractData* Data)
{
   Data->GreenEnemiesToEvade--;
}

void ContractPickedYellow(ContractData* Data)
{
   Data->YellowEnemiesToEvade--;
}

int ContractCheckWon(ContractData* Data)
{
    return Data->BlueEnemiesToPick <= Data->CurrentPickedBlues;
}

int ContractCheckDefeat(ContractData* Data)
{
    return Data->RedEnemiesToEvade < 1 || Data->GreenEnemiesToEvade < 1 || Data->YellowEnemiesToEvade < 1;
}