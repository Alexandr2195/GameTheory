#pragma once
#include "fnx_BasicStrategy.h"

class fnx_Graaskamp :
    public fnx_BasicStrategy
{     
    FNX_CLASS_DEFAULT(fnx_Graaskamp)

public:
    fnx_Graaskamp   (void)              = delete    ;
    ~fnx_Graaskamp  (void)  override    = default   ;

    fnx_Graaskamp   (int inStartCoin, const char* inName);

    void	            Decision    (void)  override;
    void	            Reset       (void)  override;
    fnx_BasicStrategy*  Copy        (void)  override;

private:
    const fnx_Choice FirstStep                  ;
          int        RoundCount                 ;
    const int        RoundBetrayal       =  50  ;
};

