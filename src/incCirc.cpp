#include "incCirc.h"

incCirc::incCirc(Vector2 _center, int _rad, float _holesize, int _thickness, float _mass)
{
    center = _center;
    rad = _rad;
    holeSize = _holesize;
    thickness = _thickness;
    rotation = 1;
    mass = _mass;
    for (int j = 0; j <= thickness; j++)
    {
        calcPoints(rad - j, j==0);
    }
    imageBuffer = GenImageColor(GetScreenWidth(), GetScreenHeight(), BLANK);
    for(Vector2 i : points){
        ImageDrawPixelV(&imageBuffer,i,BLACK);
    }
    displayTexture = LoadTextureFromImage(imageBuffer);

}

void incCirc::Update(){
    points.clear();
    imageBuffer = GenImageColor(GetScreenWidth(), GetScreenHeight(), BLANK);
    for (int j = 0; j <= thickness; j++)
    {
        calcPoints(rad - j, j==0);
    }
    for (Vector2 i : points)
    {
        ImageDrawPixelV(&imageBuffer, i, BLACK);
    }
    UpdateTexture(displayTexture, imageBuffer.data);
}

void incCirc::Draw(){
    DrawTexture(displayTexture,0,0,WHITE);
    
}

void incCirc::calcPoints(int r, bool first){
    float v = 0.005;
    gravityPoints.push_back({0,0});
    points.push_back({0 + center.x,r + center.y});
    float start = (atan2f(r * sinf(rotation), r * cosf(rotation)));
    float end = (atan2f(r * sinf(holeSize + rotation),r * cosf(holeSize + rotation)));

    if(end < 0){
        end+= 2 * PI;
    }
    if(end > 2 * PI){
        end = 0;
    }
    if (start < 0)
    {
        start += 2 * PI;
    }
    //std::cout << start << " " << end << std::endl;
    for(float i = 0; i < 2 *PI; i+= v){
        
        if(i > start && i < end){
           
            continue;
        }
        else if(end < PI && start > PI){
            if(i > start || i < end){
                
                continue;
            }
        }
        
            
        Vector2 temp = {floorf(r * cos(i) + center.x), floorf(r * sin(i) + center.y)};
        if(points.back() != temp){
            points.push_back(temp);
        }
        if(first){
            if (gravityPoints.back() != temp){
                gravityPoints.push_back(temp);
            }
        }
        
    }
    gravityPoints.erase(gravityPoints.begin());
}
void incCirc::setRotation(float _rotation){
    rotation = _rotation;
    Update();
}
std::vector<Vector2> incCirc::getGravityPoints(){
    return gravityPoints;
}
float incCirc::getMass(){
    return mass;
}
Vector2 incCirc::getCenter(){
    return center;
}