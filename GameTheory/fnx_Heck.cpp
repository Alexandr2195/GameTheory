#include "fnx_Heck.h"

fnx_Heck::fnx_Heck(int inStartCoin, const char* inName)
	: fnx_BasicStrategy(inStartCoin, inName)
{
}

void fnx_Heck::Decision(void)
{
	this->SetChoice(Betrayal);
}

void fnx_Heck::Reset(void)
{
	this->ResetBase();
}

fnx_BasicStrategy* fnx_Heck::Copy(void)
{
	return new fnx_Heck(this->StartCoin, this->Data.Name.data());
}