#include "fnx_Arena.h"

fnx_Arena::fnx_Arena(void)
	: Init			(false)
	, Strategies	()
	, p_Strategies	()
	, Datas			()
{

}

fnx_Arena::~fnx_Arena(void)
{
	if (Init)
	{
		for (const auto& [a, b] : p_Strategies)
		{
			delete a;
			delete b;
		}

		Init = false;
	}
}

void fnx_Arena::Initialize(void)
{
	InitializeStrategyList	();
	InitializeStrategyPairs	();
	Init = true;
}

constexpr int Comunism	(100);

void fnx_Arena::InitializeStrategyList(void)
{
	Strategies.push_back(new fnx_Angel			(Comunism, "Angel          ")	);
	Strategies.push_back(new fnx_Heck			(Comunism, "Heck           ")	);
	Strategies.push_back(new fnx_Random			(Comunism, "Random         ")	);
	Strategies.push_back(new fnx_RandomGood		(Comunism, "RandomGood     ")	);
	Strategies.push_back(new fnx_RandomEvil		(Comunism, "RandomEvil     ")	);
	Strategies.push_back(new fnx_Joss			(Comunism, "Joss           ")	);
	Strategies.push_back(new fnx_Fredman		(Comunism, "Fredman        ")	);
	Strategies.push_back(new fnx_Graaskamp		(Comunism, "Graaskamp      ")	);
	Strategies.push_back(new fnx_TitForTat		(Comunism, "TitForTat      ")	);
	Strategies.push_back(new fnx_TitFor2Tat		(Comunism, "TitFor2Tat     ")	);
	Strategies.push_back(new fnx_TitForTatMercy	(Comunism, "TitForTatMercy ")	);
	Strategies.push_back(new fnx_Tester			(Comunism, "Tester         ")	);
	Strategies.push_back(new fnx_Dance_L		(Comunism, "Dance_L        ")	);
	Strategies.push_back(new fnx_Dance_R		(Comunism, "Dance_R        ")	);
	Strategies.push_back(new fnx_Balance		(Comunism, "Balance        ")	);
	Strategies.push_back(new fnx_BalanceGood	(Comunism, "BalanceGood    ")	);
	Strategies.push_back(new fnx_BalanceEvil	(Comunism, "BalanceEvil    ")	);
	Strategies.push_back(new fnx_BalanceEvil2	(Comunism, "BalanceEvil2   ")	);
}

void fnx_Arena::InitializeStrategyPairs(void)
{
	for (int i(0); i < Strategies.size(); i++)
		for (int j(i); j < Strategies.size(); j++)
			p_Strategies.push_back
			(
				{ 
					Strategies.at(i)->Copy() , 
					Strategies.at(j)->Copy() 
				}
			);

	for (const auto& a : Strategies)
		delete a;

	return;
}

void fnx_Arena::TestPair(StrategiesPair& pair)
{
	int Counter(0);
	auto& [A, B] = pair;

	A->Reset();
	B->Reset();

	//fnxMessageOut(A->GetData().Name, B->GetData().Name);

	while ((A->GetStatus() == fnx_Status::Live) && (B->GetStatus() == fnx_Status::Live) && (Counter < MaxRounds))
	{
		A->Decision();
		B->Decision();

		A->SetOpponentChoice(B->GetChoice());
		B->SetOpponentChoice(A->GetChoice());

		//fnxMessageOut(A->GetChoice(), B->GetChoice());

		A->DistributionOfResults();
		B->DistributionOfResults();

		Counter++;
	}

	auto A_data(A->GetData());
	auto B_data(B->GetData());

	Datas.push_back
	(
		{
			{
				A_data.Name					,
				GetStatusStr(A_data.Status)	,
				A_data.CurrentCoin			,
				A_data.RoundCount
			}
			,
			{
				B_data.Name					,
				GetStatusStr(B_data.Status)	,
				B_data.CurrentCoin			,
				B_data.RoundCount
			}
		}
	);

	return;
}


void fnx_Arena::CalcStats(StrategiesPair& pair)
{
	auto func = [this](fnxStrategyData X_data, int win)
	{
		auto key(Stats.find(X_data.Name));
		if (key == Stats.end())
		{
			int Live(X_data.Status == fnx_Status::Live ? 1 : 0);
			int Dead(X_data.Status == fnx_Status::Dead ? 1 : 0);
			Stats.insert({ X_data.Name , {Live , Dead , X_data.CurrentCoin , X_data.RoundCount , 1, win} });
		}
		else
		{
			int Live(X_data.Status == fnx_Status::Live ? 1 : 0);
			int Dead(X_data.Status == fnx_Status::Dead ? 1 : 0);

			auto& [LiveCount, DeadCount, Coins, Rounds, counter, result] = (*key).second;

			LiveCount	+= Live;
			DeadCount	+= Dead;
			Coins		+= X_data.CurrentCoin;
			Rounds		+= X_data.RoundCount;
			result		+= win;

			counter++;
		}

		return;
	};

	int WinFirst	(0);
	int WinSecond	(0);

	if (pair.first->GetData().Status == fnx_Status::Live && pair.second->GetData().Status == fnx_Status::Live)
	{
		if (pair.first->GetData().CurrentCoin == pair.second->GetData().CurrentCoin)
			WinFirst = WinSecond = 1;
		else if (pair.first->GetData().CurrentCoin > pair.second->GetData().CurrentCoin)
			WinFirst = 1;
		else
			WinSecond = 1;
	}
	else
	{
		if (pair.first->GetData().Status == fnx_Status::Live)
			WinFirst = 1;
		else if (pair.second->GetData().Status == fnx_Status::Live)
			WinSecond = 1;
	}

	func(pair.first	->GetData(), WinFirst	);
	func(pair.second->GetData(), WinSecond	);

	return;
}

void fnx_Arena::Work(void)
{
	for (auto& a : p_Strategies)
		TestPair(a);

	for (auto& a : p_Strategies)
		CalcStats(a);
}

void fnx_Arena::PrintResults(void)
{
	fnxMessageOut("Name\t", "Status\t", "Coins\t", "Round\t");

	for (const auto& [a, b] : Datas)
	{
		const auto& [name	, status	, coins	, rounds	] = a;
		const auto& [name1	, status1	, coins1, rounds1	] = b;

		fnxMessageOut(name	,"\t", status	, "\t", coins	, "\t", rounds	);
		fnxMessageOut(name1	,"\t", status1	, "\t", coins1	, "\t", rounds1	);
		fnxMessageOut();
	}

	fnxMessageOut("Name", "\t\t", "LiveCount", "\t", "DeadCount", "\t", "aveCoins", "\t", "aveRounds", "\t", "wins");

	for (const auto& [name, datas] : Stats)
	{
		const auto& [leve, dead, coins, rounds, count, win] = datas;
		fnxMessageOut(name, "\t", leve, "\t\t", dead, "\t", (float)coins / (float)count, "\t", (float)rounds / (float)count, "\t", win);
	}

	fnxMessageOut();
}