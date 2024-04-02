#pragma once
#include "fnx_BasicStrategy.h"

class fnx_Angel :
    public fnx_BasicStrategy
{
    FNX_CLASS_DEFAULT(fnx_Angel)

public:
    fnx_Angel   (void)              = delete    ;
    ~fnx_Angel  (void)  override    = default   ;

    fnx_Angel   (int inStartCoin, const char* inName);

    void	            Decision    (void)  override;
    void	            Reset       (void)  override;
    fnx_BasicStrategy*  Copy        (void)  override;
};

