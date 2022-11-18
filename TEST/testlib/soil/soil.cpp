#include "soil.h"
#include "cmath"

SoilTexture::SoilTexture()
{
    this->clay = NODATA;
    this->sand = NODATA;
    this->silt =NODATA;
}


bool checkTexture(const SoilTexture &mySoilTexture, double tollerance)
{
    double sum = (mySoilTexture.clay + mySoilTexture.silt + mySoilTexture.sand);
    return (fabs(sum - 100.0) < tollerance);
}
