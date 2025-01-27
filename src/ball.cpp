#include "ball.h";

Ball::Ball(Vector2 _center, int *_rad){
    center = _center;
    rad = _rad;
    velocity = {0,0};
    mass = 1;
}
void Ball::Draw(){
    
    
    DrawCircleV(center,*rad,RED);
}
Vector2 Ball::Gravity(){
    Vector2 f = {0,0};
    
    for(auto& ringRef : rings){
        
        incCirc &ring = ringRef.get();
        Vector2 gPoint = {*rad * cosf(ring.getRot() + (ring.getHoleSize() / 2) + PI), *rad * sinf(ring.getRot() + (ring.getHoleSize() / 2) + PI)};
        gPoint += ring.getCenter();
        float force = (G * ring.getMass())/Vector2DistanceSqr(center,gPoint);
        Vector2 calc = {center.x - gPoint.x, center.y - gPoint.y};
        calc = Vector2Normalize(calc * -1);
        
        f += Vector2ClampValue(calc * force, -3,3);
          
    }
    
    return f;
}
void Ball::Update(){
    
    velocity += Gravity();
   
    
    
    for(auto& ringRef : rings){
        incCirc &ring = ringRef.get();
        std::vector<Vector2> points = ring.getSurfacePoints();
       
        for(Vector2 point : points ){
            if(CheckCollisionPointCircle(point,center,*rad)){
                Vector2 norm = {point.x - ring.getCenter().x, point.y - ring.getCenter().y};
                norm = Vector2Normalize(norm);
                norm = norm * -1;
                velocity = Vector2Reflect(velocity,norm);
                break;
            }
        }
        
    }
    
    center += velocity;
    if(center.x < 0 || center.x > 800 || center.y < 0 || center.y > 450){
        
        center = {400,225};
        velocity = {0,0};
    }
}
void Ball::addRing(incCirc& ring){
    rings.push_back(ring);
}

void Ball::Reset(){
    center = {0,0};
    velocity = {GetScreenWidth()/2.0f,GetScreenHeight()/2.0f};
    *rad = 10;
}