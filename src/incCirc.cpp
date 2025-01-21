#include "incCirc.h"

incCirc::incCirc(Vector2 _center, int _rad, float _holesize, int _thickness)
{
    center = _center;
    rad = _rad;
    holeSize = _holesize;
    thickness = _thickness;
    rotation = 1;
    for (int j = 0; j <= thickness; j++)
    {
        calcPoints(rad - j);
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
        calcPoints(rad - j);
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

void incCirc::calcPoints(int r){
    float v = 0.005;
    points.push_back({0 + center.x,r + center.y});
    float start = atan2f(r * sinf(rotation), r * cosf(rotation));
    float end = atan2f(r * sinf(holeSize + rotation),r * cosf(holeSize + rotation));

    for(float i = 0; i < 2 *PI; i+= v){
        if(i > start && i < end){
            i = end;
        }
        else{
            
        Vector2 temp = {floorf(r * cos(i) + center.x), floorf(r * sin(i) + center.y)};
        if(points.back() != temp){
            points.push_back(temp);
        }
        }
    }
}
void incCirc::setRotation(float _rotation){
    rotation = _rotation;
    Update();
}
