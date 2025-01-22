#ifndef BALL_H
#define BALL_H
#define G 0.00000000006674
#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <incCirc.h>
class Ball{
private:
    Vector2 center;
    int rad;
    Vector2 velocity;
    std::vector<incCirc> rings;
    float mass;

public:
    Ball(Vector2 _center, int _rad, std::vector<incCirc> &_rings);
    void Draw();
    void Update();
    Vector2 Gravity();
};



#endif // BALL_H