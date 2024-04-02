#pragma once
#include "fnx_BasicStrategy.h"

class fnx_Joss :
    public fnx_BasicStrategy
{
     FNX_CLASS_DEFAULT(fnx_Joss)

public:
    fnx_Joss    (void)              = delete    ;
    ~fnx_Joss   (void)  override    = default   ;

    fnx_Joss    (int inStartCoin, const char* inName);

    void	            Decision    (void)  override;
    void	            Reset       (void)  override;
    fnx_BasicStrategy*  Copy        (void)  override;

private:
    const fnx_Choice FirstStep                  ;
    const float      ProbabilityBetrayal = .1f  ;
};

