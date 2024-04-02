#include "fnx_TitForTatMercy.h"

fnx_TitForTatMercy::fnx_TitForTatMercy(int inStartCoin, const char* inName)
	: fnx_BasicStrategy	(inStartCoin, inName)
	, FirstStep			(fnx_Choice::Cooperation)
{
}

void fnx_TitForTatMercy::Decision(void)
{
	fnx_Choice result(fnx_Choice::NotChoice);

	if (!this->Data.RoundCount)
		result = FirstStep;
	else
	{
		if (this->GetOpLastChoice() == fnx_Choice::Cooperation)
			result = fnx_Choice::Cooperation;

		else
		{
			if(Mercy < RangeRand<float>(.0f, 1.f))
				result = fnx_Choice::Betrayal;
			else
				result = fnx_Choice::Cooperation;
		}
	}

	this->SetChoice(result);
}

void fnx_TitForTatMercy::Reset(void)
{
	this->ResetBase();
}

fnx_BasicStrategy* fnx_TitForTatMercy::Copy(void)
{
	return new fnx_TitForTatMercy(this->StartCoin, this->Data.Name.data());
}