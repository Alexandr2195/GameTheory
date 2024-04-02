#pragma once
#include "fnx_BasicStrategy.h"

class fnx_TitFor2Tat :
    public fnx_BasicStrategy
{
    FNX_CLASS_DEFAULT(fnx_TitFor2Tat)

public:
    fnx_TitFor2Tat  (void)              = delete    ;
    ~fnx_TitFor2Tat (void)  override    = default   ;

    fnx_TitFor2Tat  (int inStartCoin, const char* inName);

    void	            Decision    (void)  override;
    void	            Reset       (void)  override;
    fnx_BasicStrategy*  Copy        (void)  override;    

private:
    const   fnx_Choice FirstStep    ;
            fnx_Choice llOpChoice   ;
};

