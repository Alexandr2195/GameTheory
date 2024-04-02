#pragma once
#include "fnx_BasicStrategy.h"

class fnx_TitForTatMercy :
    public fnx_BasicStrategy
{
     FNX_CLASS_DEFAULT(fnx_TitForTatMercy)

public:
    fnx_TitForTatMercy  (void)              = delete    ;
    ~fnx_TitForTatMercy (void)  override    = default   ;

    fnx_TitForTatMercy  (int inStartCoin, const char* inName);

    void	            Decision    (void)  override;
    void	            Reset       (void)  override;
    fnx_BasicStrategy*  Copy        (void)  override;    

private:
    const   fnx_Choice FirstStep;
    const   float      Mercy = .1f;
};

