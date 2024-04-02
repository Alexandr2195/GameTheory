#pragma once
#include "fnx_BasicStrategy.h"

class fnx_TitForTat :
    public fnx_BasicStrategy
{
     FNX_CLASS_DEFAULT(fnx_TitForTat)

public:
    fnx_TitForTat   (void)              = delete    ;
    ~fnx_TitForTat  (void)  override    = default   ;

    fnx_TitForTat   (int inStartCoin, const char* inName);

    void	            Decision    (void)  override;
    void	            Reset       (void)  override;
    fnx_BasicStrategy*  Copy        (void)  override;    

private:
    const fnx_Choice FirstStep;
};

