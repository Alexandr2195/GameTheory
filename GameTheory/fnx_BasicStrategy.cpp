#include "fnx_BasicStrategy.h"

fnx_BasicStrategy::fnx_BasicStrategy(int inStartCoin, const char* inName)
	: StartCoin				(inStartCoin)
	, MyCurrentChoice		(NotChoice)
	, OpCurrentChoice		(NotChoice)
	, OpLastChoice	(NotChoice)
	, Data					(inName)
{
	this->ResetBase();
}

void fnx_BasicStrategy::ResetBase(void)
{
	Data.Clear();

	Data.CurrentCoin = this->StartCoin;

	MyCurrentChoice = OpLastChoice = OpCurrentChoice = NotChoice;
}

const fnxStrategyData& fnx_BasicStrategy::GetData(void) const
{
	return Data;
}

void fnx_BasicStrategy::DistributionOfResults(void)
{
			if((MyCurrentChoice == Cooperation	) && (OpCurrentChoice == Cooperation	))	this->Data.CurrentCoin += CC;
	else	if((MyCurrentChoice == Betrayal		) && (OpCurrentChoice == Betrayal		))	this->Data.CurrentCoin += BB;
	else	if((MyCurrentChoice == Cooperation	) && (OpCurrentChoice == Betrayal		))	this->Data.CurrentCoin += CB;
	else	if((MyCurrentChoice == Betrayal		) && (OpCurrentChoice == Cooperation	))	this->Data.CurrentCoin += BC;
	else
				assert(false);

	OpLastChoice = OpCurrentChoice;

	MyCurrentChoice = OpCurrentChoice = NotChoice;

	if (this->Data.CurrentCoin < 0)
		this->Data.Status = Dead;
	else
		this->Data.RoundCount++;
}

fnx_Status fnx_BasicStrategy::GetStatus(void)	const
{
	return this->Data.Status;
}

fnx_Choice	fnx_BasicStrategy::GetChoice(void) const
{
	return this->MyCurrentChoice;
}

void	fnx_BasicStrategy::SetOpponentChoice(const fnx_Choice& in_Choice)
{
	OpCurrentChoice = in_Choice;

	return;
}

void	fnx_BasicStrategy::SetChoice(fnx_Choice inChoice)
{
	MyCurrentChoice = inChoice;
}

const char* fnx_BasicStrategy::GetChoiceStr(void)const
{
	static const char* CooperationStr	= "Cooperation"	;
	static const char* BetrayalStr		= "Betrayal"	;

	if (MyCurrentChoice == Cooperation)
		return CooperationStr;
	else
		return BetrayalStr;
}

fnx_Choice	fnx_BasicStrategy::GetOpLastChoice(void) const
{
	return OpLastChoice;
}