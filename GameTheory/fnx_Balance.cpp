#include "fnx_Balance.h"

constexpr int procentAdvantage(30);

fnx_Balance::fnx_Balance(int inStartCoin, const char* inName)
	: fnx_BasicStrategy	(inStartCoin, inName)
	, CountBetrayal		(0)
	, CountCooperation	(0)
{
}

void fnx_Balance::Decision(void)
{
	auto Choice(fnx_Choice::NotChoice);

	if (CountBetrayal == CountCooperation)
	{
		if (RangeRand<float>(0.f, 1.f) > .5f)
			Choice = fnx_Choice::Cooperation;
		else
			Choice = fnx_Choice::Betrayal;
	}
	else if(CountBetrayal > CountCooperation)
		Choice = fnx_Choice::Betrayal;
	else if(CountBetrayal < CountCooperation)
		Choice = fnx_Choice::Cooperation;

	if (this->GetOpLastChoice() == fnx_Choice::Cooperation)
		CountCooperation++;
	else if (this->GetOpLastChoice() == fnx_Choice::Betrayal)
		CountBetrayal++;

	this->SetChoice(Choice);
}

void fnx_Balance::Reset(void)
{
	this->ResetBase();
	CountBetrayal	=	(0);
	CountCooperation=	(0);
}

fnx_BasicStrategy* fnx_Balance::Copy(void)
{
	return new fnx_Balance(this->StartCoin, this->Data.Name.data());
}

fnx_BalanceGood::fnx_BalanceGood(int inStartCoin, const char* inName)
	: fnx_BasicStrategy	(inStartCoin, inName)
	, CountBetrayal		(0)
	, CountCooperation	(0)
	, ProcentBetrayal	(0)
{
}

void fnx_BalanceGood::Decision(void)
{
	auto Choice(fnx_Choice::NotChoice);

	if (ProcentBetrayal > 70.f)
		Choice = fnx_Choice::Betrayal;
	else
		Choice = fnx_Choice::Cooperation;

	if (this->GetOpLastChoice() == fnx_Choice::Cooperation)
		CountCooperation++;
	else if (this->GetOpLastChoice() == fnx_Choice::Betrayal)
		CountBetrayal++;

	auto sum(CountBetrayal + CountCooperation);

	if (sum)
		ProcentBetrayal = ( CountBetrayal / (sum / 100.f) );

	this->SetChoice(Choice);
}

void fnx_BalanceGood::Reset(void)
{
	this->ResetBase();
	CountBetrayal	=	(0);
	CountCooperation=	(0);
	ProcentBetrayal =	(0);
}

fnx_BasicStrategy* fnx_BalanceGood::Copy(void)
{
	return new fnx_BalanceGood(this->StartCoin, this->Data.Name.data());
}

fnx_BalanceEvil::fnx_BalanceEvil(int inStartCoin, const char* inName)
	: fnx_BasicStrategy	(inStartCoin, inName)
	, CountBetrayal		(0)
	, CountCooperation	(0)
	, ProcentBetrayal	(0)
{
}

void fnx_BalanceEvil::Decision(void)
{
	auto Choice(fnx_Choice::NotChoice);

	if (ProcentBetrayal > 30.f)
		Choice = fnx_Choice::Betrayal;
	else
		Choice = fnx_Choice::Cooperation;

	if (this->GetOpLastChoice() == fnx_Choice::Cooperation)
		CountCooperation++;
	else if (this->GetOpLastChoice() == fnx_Choice::Betrayal)
		CountBetrayal++;

	auto sum(CountBetrayal + CountCooperation);

	if (sum)
		ProcentBetrayal = ( CountBetrayal / (sum / 100.f) );

	this->SetChoice(Choice);
}

void fnx_BalanceEvil::Reset(void)
{
	this->ResetBase();
	CountBetrayal	=	(0);
	CountCooperation=	(0);
	ProcentBetrayal =	(0);
}

fnx_BasicStrategy* fnx_BalanceEvil::Copy(void)
{
	return new fnx_BalanceEvil(this->StartCoin, this->Data.Name.data());
}

fnx_BalanceEvil2::fnx_BalanceEvil2(int inStartCoin, const char* inName)
	: fnx_BasicStrategy	(inStartCoin, inName)
	, CountBetrayal		(0)
	, CountCooperation	(0)
	, ProcentBetrayal	(0)
	, FirstStep			(fnx_Choice::Betrayal)
{
}

void fnx_BalanceEvil2::Decision(void)
{
	auto Choice(fnx_Choice::NotChoice);

	if (!this->Data.RoundCount)
		Choice = FirstStep;

	if (ProcentBetrayal > 30.f)
		Choice = fnx_Choice::Betrayal;
	else
		Choice = fnx_Choice::Cooperation;

	if (this->GetOpLastChoice() == fnx_Choice::Cooperation)
		CountCooperation++;
	else if (this->GetOpLastChoice() == fnx_Choice::Betrayal)
		CountBetrayal++;

	auto sum(CountBetrayal + CountCooperation);

	if (sum)
		ProcentBetrayal = ( CountBetrayal / (sum / 100.f) );

	this->SetChoice(Choice);
}

void fnx_BalanceEvil2::Reset(void)
{
	this->ResetBase();
	CountBetrayal	=	(0);
	CountCooperation=	(0);
	ProcentBetrayal =	(0);
}

fnx_BasicStrategy* fnx_BalanceEvil2::Copy(void)
{
	return new fnx_BalanceEvil2(this->StartCoin, this->Data.Name.data());
}