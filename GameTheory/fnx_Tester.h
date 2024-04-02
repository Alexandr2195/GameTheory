#pragma once
#include "fnx_BasicStrategy.h"

class fnx_Tester :
    public fnx_BasicStrategy
{
    FNX_CLASS_DEFAULT(fnx_Tester)

public:
    fnx_Tester  (void)              = delete    ;
    ~fnx_Tester (void)  override    = default   ;

    fnx_Tester  (int inStartCoin, const char* inName);

    void	            Decision    (void)  override;
    void	            Reset       (void)  override;
    fnx_BasicStrategy*  Copy        (void)  override;    

private:
    const fnx_Choice FirstStep;
          bool       TitForTat;
          int        CountCoop;
};