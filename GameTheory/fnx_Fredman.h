#pragma once
#include "fnx_BasicStrategy.h"

class fnx_Fredman :
    public fnx_BasicStrategy
{
        FNX_CLASS_DEFAULT(fnx_Fredman)

public:
    fnx_Fredman (void)              = delete    ;
    ~fnx_Fredman(void)  override    = default   ;

    fnx_Fredman (int inStartCoin, const char* inName);

    void	            Decision    (void)  override;
    void	            Reset       (void)  override;
    fnx_BasicStrategy*  Copy        (void)  override;

private:
    const   fnx_Choice          FirstStep   ;
            fnx_Choice          Choice      ;
};

