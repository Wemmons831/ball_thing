#ifndef BALL_H
#define BALL_H
#define G 0.0006674
#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <cmath>

#include <incCirc.h>
#include <functional>
class Ball{
private:
    Vector2 center;
    int *rad;
    Vector2 velocity;
    std::vector<std::reference_wrapper<incCirc>> rings;
    float mass;

public:
    Ball(Vector2 _center, int *_rad);
    void Draw();
    void Update();
    Vector2 Gravity();
    void addRing(incCirc& ring);
    void Reset();
};



#endif // BALL_H