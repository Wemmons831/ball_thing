#ifndef INCCIRC_H
#define INCCIRC_H
#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <cmath>
#include <iostream>
class incCirc{
private:
    Vector2 center;
    int rad;
    int thickness; // will be inside the radius
    float holeSize; // in radians
    float rotation;
    std::vector<Vector2> points;
    
    Image imageBuffer;
    Texture displayTexture;

public:
    incCirc(Vector2 _center, int _rad, float _holesize, int _thickness);
    void Draw();
    void calcPoints(int r);
    void Update();
    void setRotation(float _rotation);
};

#endif // INCCIRC_H
