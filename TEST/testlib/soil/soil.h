#ifndef SOIL_H
#define SOIL_H

#define NODATA -9999

class  SoilTexture
{
public:
    double sand, silt, clay; // in %

    SoilTexture ();
};

bool checkTexture(const SoilTexture &mySoilTexture, double tollerance);


#endif // SOIL_H

