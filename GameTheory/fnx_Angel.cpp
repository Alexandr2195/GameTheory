#include "fnx_Angel.h"

fnx_Angel::fnx_Angel(int inStartCoin, const char* inName)
	: fnx_BasicStrategy(inStartCoin, inName)
{
}

void fnx_Angel::Decision(void)
{
	this->SetChoice(fnx_Choice::Cooperation);
}

void fnx_Angel::Reset(void)
{
	this->ResetBase();
}

fnx_BasicStrategy* fnx_Angel::Copy(void)
{
	return new fnx_Angel(this->StartCoin, this->Data.Name.data());
}
