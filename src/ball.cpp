#include "ball.h"
Ball::Ball(Vector2 _center, int _rad, std::vector<incCirc> &_rings){
    center = _center;
    rad = _rad;
    rings = _rings;
    velocity = {0,0};
    mass = 1;
}
void Ball::Draw(){
    Update();
    
    DrawCircleV(center,rad,BLUE);
}
Vector2 Ball::Gravity(){
    Vector2 f = {0,0};
    for(incCirc ring : rings){
        
        float pointMass = ring.getMass()/ring.getGravityPoints().size();
        Vector2 cMass = {0, 0};
        std::vector<Vector2> points = ring.getGravityPoints();
        int size = points.size();
        for(Vector2 point : points){
            cMass += point * (1.0/size);
        }
        float r = 0.1 * sqrtf(powf((cMass.x - center.x) / 100, 2) + (powf((cMass.y - center.y) / 100, 2)));
        f.x += (-(G * ring.getMass())/pow(r,3)) * ((cMass.x - center.x)/100.0);
        f.y += (-(G * ring.getMass())/pow(r,3)) * ((cMass.y - center.y)/100.0);
    }
    
    return f;
}
void Ball::Update(){
    velocity += Gravity() * 100;
    std::cout << velocity.x << " " << velocity.y << std::endl;
    center += velocity;
}