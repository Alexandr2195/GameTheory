#include "fnx_Joss.h"

fnx_Joss::fnx_Joss(int inStartCoin, const char* inName)
	: fnx_BasicStrategy	(inStartCoin, inName)
	, FirstStep			(fnx_Choice::Cooperation)
{
}

void fnx_Joss::Decision(void)
{
	fnx_Choice result(fnx_Choice::NotChoice);

	if(!this->Data.RoundCount)
		result = FirstStep;
	else
	{
		if (this->GetOpLastChoice() == fnx_Choice::Cooperation)
		{
			if (ProbabilityBetrayal < RangeRand<float>(.0f, 1.f))
				result = fnx_Choice::Cooperation;
			else
				result = fnx_Choice::Betrayal;

		}
		else
			result = fnx_Choice::Betrayal;
	}

	this->SetChoice(result);
}

void fnx_Joss::Reset(void)
{
	this->ResetBase();
}

fnx_BasicStrategy* fnx_Joss::Copy(void)
{
	return new fnx_Joss(this->StartCoin, this->Data.Name.data());
}