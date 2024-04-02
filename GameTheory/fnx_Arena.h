#pragma once

#include <vector>
#include <list>
#include <utility>
#include <tuple>
#include <unordered_map>

#include "fnx_Angel.h"
#include "fnx_Heck.h"
#include "fnx_Random.h"
#include "fnx_Joss.h"
#include "fnx_Fredman.h"
#include "fnx_Graaskamp.h"
#include "fnx_TitForTat.h"
#include "fnx_TitFor2Tat.h"
#include "fnx_TitForTatMercy.h"
#include "fnx_Tester.h"
#include "Dance_L and Dance_R.h"
#include "fnx_Balance.h"

constexpr int MaxRounds (100000);

namespace
{
    constexpr const char* Dead = "Dead";
    constexpr const char* Live = "Live";

    constexpr const char* GetStatusStr(fnx_Status stat)
    {
        if (stat == fnx_Status::Live)
            return Live;
        else
            return Dead;
    }
}

using StrategiesPair        = std::pair<fnx_BasicStrategy*, fnx_BasicStrategy*> ;
using StrategiesData        = std::tuple<std::string, std::string, int, int>    ;
using StrategiesDataPair    = std::pair<StrategiesData, StrategiesData>         ;
using StatsParams           = std::tuple<int, int, int, int, int, int>          ;//leaveCount, leaveDead, SrCoin, SrRound, count , result
using StatsMap              = std::unordered_map<std::string , StatsParams>     ;

class fnx_Arena
{
    FNX_CLASS_DELETE(fnx_Arena)

public:
    fnx_Arena                   (void);
    ~fnx_Arena                  (void);

    void Initialize             (void);
    void Work                   (void);
    void PrintResults           (void);

    void TestPair    (       StrategiesPair&     pair    );

private:
    void InitializeStrategyList     (void);
    void InitializeStrategyPairs    (void);

    void CalcStats   (       StrategiesPair&     pair    );

    bool                                Init        ;
    std::vector <fnx_BasicStrategy* >   Strategies  ;
    std::list   <StrategiesPair     >   p_Strategies;
    std::list   <StrategiesDataPair >   Datas       ;
    StatsMap                            Stats       ;
};

