#include "fnx_Random.h"

fnx_Random::fnx_Random(int inStartCoin, const char* inName)
	: fnx_BasicStrategy(inStartCoin, inName)
{
}

void fnx_Random::Decision(void)
{
	auto ChoiceVer(RangeRand<float>(0.f, 1.f));
	auto Choice(fnx_Choice::NotChoice);

	if (ChoiceVer >= .5f)
		Choice = fnx_Choice::Cooperation;
	else
		Choice = fnx_Choice::Betrayal;

	this->SetChoice(Choice);
}

void fnx_Random::Reset(void)
{
	this->ResetBase();
}

fnx_BasicStrategy* fnx_Random::Copy(void)
{
	return new fnx_Random(this->StartCoin, this->Data.Name.data());
}

fnx_RandomGood::fnx_RandomGood(int inStartCoin, const char* inName)
	: fnx_BasicStrategy(inStartCoin, inName)
{
}

void fnx_RandomGood::Decision(void)
{
	auto ChoiceVer(RangeRand<float>(0.f, 1.f));
	auto Choice(fnx_Choice::NotChoice);

	if (ChoiceVer >= .3f)
		Choice = fnx_Choice::Cooperation;
	else
		Choice = fnx_Choice::Betrayal;

	this->SetChoice(Choice);
}

void fnx_RandomGood::Reset(void)
{
	this->ResetBase();
}

fnx_BasicStrategy* fnx_RandomGood::Copy(void)
{
	return new fnx_RandomGood(this->StartCoin, this->Data.Name.data());
}

fnx_RandomEvil::fnx_RandomEvil(int inStartCoin, const char* inName)
	: fnx_BasicStrategy(inStartCoin, inName)
{
}

void fnx_RandomEvil::Decision(void)
{
	auto ChoiceVer(RangeRand<float>(0.f, 1.f));
	auto Choice(fnx_Choice::NotChoice);

	if (ChoiceVer >= .7f)
		Choice = fnx_Choice::Cooperation;
	else
		Choice = fnx_Choice::Betrayal;

	this->SetChoice(Choice);
}

void fnx_RandomEvil::Reset(void)
{
	this->ResetBase();
}

fnx_BasicStrategy* fnx_RandomEvil::Copy(void)
{
	return new fnx_RandomEvil(this->StartCoin, this->Data.Name.data());
}