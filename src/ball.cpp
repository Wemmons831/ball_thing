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
        for(Vector2 point : ring.getGravityPoints()){
            float rx = center.x - point.x;
            float ry = center.y - point.y;
            if(rx ==  0 || ry ==0){ continue;}
            f.x += -((G * pointMass * rx)/(powf(powf(rx,2) +  powf(ry,2),3.0/2.0)));
            f.y -= -((G * pointMass * ry)/(powf(powf(rx,2) +  powf(ry,2),3.0/2.0)));
        }
    }
    
    return f;
}
void Ball::Update(){
    velocity += Gravity() * 60;
    std::cout << velocity.x << " " << velocity.y << std::endl;
    center += velocity;
}