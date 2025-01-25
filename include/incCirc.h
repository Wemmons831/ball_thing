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
    float mass;
    int rad;
    int thickness; // will be inside the radius
    float holeSize; // in radians
    float rotation;
    std::vector<Vector2> points;
    
    Image imageBuffer;
    Texture displayTexture;

    std::vector<Vector2> interiorPoints;

public:
    incCirc(Vector2 _center, int _rad, float _holesize, int _thickness, float _mass);
    void Draw();
    void calcPoints(int r, bool first);
    void Update();
    void setRotation(float _rotation);
    std::vector<Vector2> getSurfacePoints();
    float getMass();
    Vector2 getCenter();
    float getRad();
    float getRot();
    float getHoleSize();
    ~incCirc(){
        std::cout << "deleted" << std::endl;
        UnloadTexture(displayTexture);
        UnloadImage(imageBuffer);
    }
    
};


#endif // INCCIRC_H
