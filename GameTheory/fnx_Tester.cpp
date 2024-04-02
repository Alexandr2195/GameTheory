#include "fnx_Tester.h"

fnx_Tester::fnx_Tester(int inStartCoin, const char* inName)
	: fnx_BasicStrategy	(inStartCoin, inName)
	, FirstStep			(fnx_Choice::Betrayal)
	, TitForTat			(false)
	, CountCoop			(0)
{
}

void fnx_Tester::Decision(void)
{
	fnx_Choice result(fnx_Choice::NotChoice);

	if (this->Data.RoundCount == 1)
	{
		if (this->GetOpLastChoice() == fnx_Choice::Betrayal)
			TitForTat = true;
	}

	if (!this->Data.RoundCount)
		result = FirstStep;
	else
	{
		if (TitForTat)
		{
			if (this->GetOpLastChoice() == fnx_Choice::Cooperation)
				result = fnx_Choice::Cooperation;

			else
				result = fnx_Choice::Betrayal;
		}
		else
		{
			CountCoop++;

			if(CountCoop < 2)
				result = fnx_Choice::Cooperation;
			else
			{
				result = fnx_Choice::Betrayal;
				CountCoop = 0;
			}
		}
	}

	this->SetChoice(result);
}

void fnx_Tester::Reset(void)
{
	this->ResetBase();
}

fnx_BasicStrategy* fnx_Tester::Copy(void)
{
	return new fnx_Tester(this->StartCoin, this->Data.Name.data());
}