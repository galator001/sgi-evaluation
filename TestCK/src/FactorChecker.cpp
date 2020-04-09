#include <iostream>
#include "FactorChecker.h"
#include <math.h>

using namespace std;

int FactorChecker::getFactorForIndex(int targetIndex) const{
    int currentNumber = 1;
    int resultsArray [targetIndex];
    resultsArray[0] = 1;
    int twosMultiplierIndex = 0;
    int threesMultiplierIndex = 0;
    int fivesMultiplierIndex = 0;

    for(int i = 1; i < targetIndex; i++){
        int twosResult = 2 * resultsArray[twosMultiplierIndex];
        int threesResult = 3 * resultsArray[threesMultiplierIndex];
        int fivesResult = 5 * resultsArray[fivesMultiplierIndex];

        currentNumber = min(min(twosResult, threesResult), fivesResult);
        resultsArray[i] = currentNumber;

        if(currentNumber == twosResult){
            twosMultiplierIndex++;
        }

        if(currentNumber == threesResult){
            threesMultiplierIndex++;
        }

        if(currentNumber == fivesResult){
            fivesMultiplierIndex++;
        }
    }

    return currentNumber;
}






