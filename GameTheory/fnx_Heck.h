#pragma once
#include "fnx_BasicStrategy.h"

class fnx_Heck :
    public fnx_BasicStrategy
{
    FNX_CLASS_DEFAULT(fnx_Heck)

public:
    fnx_Heck        (void)              = delete    ;
    ~fnx_Heck       (void)  override    = default   ;

    fnx_Heck        (int inStartCoin, const char* inName);

    void	            Decision    (void)  override;
    void	            Reset       (void)  override;
    fnx_BasicStrategy*  Copy        (void)  override;
};

