#include "Dance_L and Dance_R.h"


fnx_Dance_L::fnx_Dance_L(int inStartCoin, const char* inName)
	: fnx_BasicStrategy	(inStartCoin, inName)
	, FirstStep			(fnx_Choice::Betrayal)
{
}

void fnx_Dance_L::Decision(void)
{	
	if (FirstStep == fnx_Choice::Cooperation)
	{
		FirstStep = fnx_Choice::Betrayal;
	}
	else if (FirstStep == fnx_Choice::Betrayal)
	{
		FirstStep = fnx_Choice::Cooperation;
	}

	auto result = FirstStep;	

	this->SetChoice(result);
}

void fnx_Dance_L::Reset(void)
{
	this->ResetBase();
	FirstStep = fnx_Choice::Betrayal;
}

fnx_BasicStrategy* fnx_Dance_L::Copy(void)
{
	return new fnx_Dance_L(this->StartCoin, this->Data.Name.data());
}

fnx_Dance_R::fnx_Dance_R(int inStartCoin, const char* inName)
	: fnx_BasicStrategy(inStartCoin, inName)
	, FirstStep(fnx_Choice::Cooperation)
{
}

void fnx_Dance_R::Decision(void)
{
	if (FirstStep == fnx_Choice::Cooperation)
	{
		FirstStep = fnx_Choice::Betrayal;
	}
	else if (FirstStep == fnx_Choice::Betrayal)
	{
		FirstStep = fnx_Choice::Cooperation;
	}

	auto result = FirstStep;

	this->SetChoice(result);
}

void fnx_Dance_R::Reset(void)
{
	this->ResetBase();
	FirstStep = fnx_Choice::Cooperation;
}

fnx_BasicStrategy* fnx_Dance_R::Copy(void)
{
	return new fnx_Dance_R(this->StartCoin, this->Data.Name.data());
}