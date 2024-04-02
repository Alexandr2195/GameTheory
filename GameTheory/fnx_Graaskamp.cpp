#include "fnx_Graaskamp.h"

fnx_Graaskamp::fnx_Graaskamp(int inStartCoin, const char* inName)
	: fnx_BasicStrategy	(inStartCoin, inName)
	, FirstStep			(fnx_Choice::Cooperation)
	, RoundCount		(0)
{
}

void fnx_Graaskamp::Decision(void)
{
	fnx_Choice result(fnx_Choice::NotChoice);

	RoundCount++;

	if (!this->Data.RoundCount)
		result = FirstStep;
	else
	{
		if (this->GetOpLastChoice() == fnx_Choice::Cooperation)
		{
			if (RoundBetrayal >= RoundCount)
				result = fnx_Choice::Cooperation;
			else
			{
				result = fnx_Choice::Betrayal;
				RoundCount = 0;
			}
		}
		else
			result = fnx_Choice::Betrayal;
	}

	this->SetChoice(result);
}

void fnx_Graaskamp::Reset(void)
{
	this->ResetBase();
	RoundCount = 0;
}

fnx_BasicStrategy* fnx_Graaskamp::Copy(void)
{
	return new fnx_Graaskamp(this->StartCoin, this->Data.Name.data());
}