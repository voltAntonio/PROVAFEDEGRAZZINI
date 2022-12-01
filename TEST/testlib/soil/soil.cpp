#include "soil.h"
#include "cmath"

SoilTexture::SoilTexture()
{
    this->clay = NODATA;
    this->sand = NODATA;
    this->silt =NODATA;
}


bool checkTexture(const SoilTexture &mySoilTexture, double &currentSum, double tollerance)
{
    currentSum = (mySoilTexture.clay + mySoilTexture.silt + mySoilTexture.sand);
    return (fabs(currentSum - 100.0) <= tollerance);
}
