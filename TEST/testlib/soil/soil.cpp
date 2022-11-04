#include "soil.h"

SoilTexture::SoilTexture()
{
    this->clay = NODATA;
    this->sand = NODATA;
    this->silt =NODATA;
}


bool checkTexture(SoilTexture* texture)
{
    return ((texture->clay + texture->silt + texture->sand) >= 99 && (texture->clay + texture->silt + texture->sand)<= 101) ? true : false;
}
