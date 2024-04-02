#pragma once
#include <string>
#include <cassert>

#include "fnxService.h"

constexpr int ExternalResource		(6	);
constexpr int PricePerTransaction	(5	);
constexpr int PriceOfInaction		(-1	);

enum fnx_Choice
{
		Cooperation
	,	Betrayal
	,   NotChoice
};

#if 1
enum fnx_ChoiceReward : int
{
		CC	= ExternalResource / 2
	,	CB	= -PricePerTransaction
	,	BC	= PricePerTransaction
	,	BB	= PriceOfInaction
};
#else
enum fnx_ChoiceReward : int
{
		CC	= 3
	,	CB	= 0
	,	BC	= 5
	,	BB	= 1
};
#endif
enum fnx_Status
{
		Dead = 0
	,	Live = 1
};

typedef struct fnxStrategyData
{
	fnxStrategyData(const char* inName)
		: Name(inName)
	{
		this->Clear();
	}

	fnxStrategyData(void)
		: Name("Unknow")
	{
		this->Clear();
	}

	void Clear	(void)
	{
		CurrentCoin		= 0			;
		Status			= Live		;
		RoundCount		= 0			;
	}

	int					CurrentCoin		;
	fnx_Status			Status			;
	int					RoundCount		;
	const std::string	Name			;
}fnxStrategyData;

class fnx_BasicStrategy
{
	FNX_CLASS_DEFAULT(fnx_BasicStrategy)

public:

	fnx_BasicStrategy	(int inStartCoin, const char* inName)								;
	fnx_BasicStrategy	(void)													= delete	;

	virtual ~fnx_BasicStrategy	(void)											= default	;


	
	virtual void				Decision				(void)							= 0;
	virtual void				Reset					(void)							= 0;
	virtual fnx_BasicStrategy*	Copy					(void)							= 0;

			void				DistributionOfResults	(void)											;
			fnx_Choice			GetChoice				(void)							const			;
			const char*			GetChoiceStr			(void)							const			;
			void				SetOpponentChoice		(const fnx_Choice& in_Choice)					;

	const	fnxStrategyData&	GetData					(void)							const			;
			fnx_Status			GetStatus				(void)							const			;

protected:
			void				SetChoice				(fnx_Choice inChoice)							;
			void				ResetBase				(void)											;
			fnx_Choice			GetOpLastChoice			(void)							const			;

	const	int					StartCoin			;
			fnx_Choice			MyCurrentChoice		;
			fnx_Choice			OpCurrentChoice		;
			fnx_Choice			OpLastChoice		;
			fnxStrategyData		Data				;
};