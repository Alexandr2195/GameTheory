#include <iostream>

#include "fnx_Arena.h"

int     main    (void)
{
    fnx_Arena* A = new fnx_Arena();

    A->Initialize();

    A->Work();
    A->PrintResults();

    //auto TT = new fnx_TitForTat (100, "TitForTat");
    //auto HE = new fnx_Heck      (100, "Heck");
    //StrategiesPair as({ TT , HE });
    //A->TestPair(as);
    //delete TT;
    //delete HE;

    delete A;

    return 0;
}
