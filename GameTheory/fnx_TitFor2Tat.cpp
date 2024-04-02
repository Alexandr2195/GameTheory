#include "fnx_TitFor2Tat.h"

fnx_TitFor2Tat::fnx_TitFor2Tat(int inStartCoin, const char* inName)
	: fnx_BasicStrategy(inStartCoin, inName)
	, FirstStep	(fnx_Choice::Cooperation)
	, llOpChoice(fnx_Choice::Cooperation)
{
}

void fnx_TitFor2Tat::Decision(void)
{
	fnx_Choice result(fnx_Choice::NotChoice);

	if (!this->Data.RoundCount)
		result = FirstStep;
	else
	{
		if (this->GetOpLastChoice() == fnx_Choice::Betrayal && llOpChoice == fnx_Choice::Betrayal)
			result = fnx_Choice::Betrayal;

		else
			result = fnx_Choice::Cooperation;
	}

	llOpChoice = this->GetOpLastChoice();

	this->SetChoice(result);
}

void fnx_TitFor2Tat::Reset(void)
{
	this->ResetBase();
}

fnx_BasicStrategy* fnx_TitFor2Tat::Copy(void)
{
	return new fnx_TitFor2Tat(this->StartCoin, this->Data.Name.data());
}