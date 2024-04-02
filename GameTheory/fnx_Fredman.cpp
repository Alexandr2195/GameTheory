#include "fnx_Fredman.h"

fnx_Fredman::fnx_Fredman(int inStartCoin, const char* inName)
	: fnx_BasicStrategy	(inStartCoin, inName)
	, FirstStep			(fnx_Choice::Cooperation)
	, Choice			(fnx_Choice::Cooperation)
{
}

void fnx_Fredman::Decision(void)
{
	if (this->GetOpLastChoice() == fnx_Choice::Betrayal)
		Choice = fnx_Choice::Betrayal;

	this->SetChoice(Choice);
}

void fnx_Fredman::Reset(void)
{
	this->ResetBase();
}

fnx_BasicStrategy* fnx_Fredman::Copy(void)
{
	return new fnx_Fredman(this->StartCoin, this->Data.Name.data());
}