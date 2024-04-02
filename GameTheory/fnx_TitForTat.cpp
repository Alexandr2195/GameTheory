#include "fnx_TitForTat.h"

fnx_TitForTat::fnx_TitForTat(int inStartCoin, const char* inName)
	: fnx_BasicStrategy	(inStartCoin, inName)
	, FirstStep			(fnx_Choice::Cooperation)
{
}

void fnx_TitForTat::Decision(void)
{
	fnx_Choice result(fnx_Choice::NotChoice);

	if (!this->Data.RoundCount)
		result = FirstStep;
	else
	{
		if (this->GetOpLastChoice() == fnx_Choice::Cooperation)
			result = fnx_Choice::Cooperation;

		else
			result = fnx_Choice::Betrayal;
	}

	this->SetChoice(result);
}

void fnx_TitForTat::Reset(void)
{
	this->ResetBase();
}

fnx_BasicStrategy* fnx_TitForTat::Copy(void)
{
	return new fnx_TitForTat(this->StartCoin, this->Data.Name.data());
}