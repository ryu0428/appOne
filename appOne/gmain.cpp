#include"libOne.h"
void roundFace(float px, float py) {
    fill(255, 255, 0);
    circle(px, py, 300);
    fill(255);
    circle(px - 50, py, 80);
    circle(px + 50, py, 80);
    fill(0);
    circle(px - 50, py, 30);
    circle(px + 50, py, 30);
    fill(255, 200, 200);
    circle(px, py + 80, 80);
}
void squareFace(float px, float py,float angle) {
    rectMode(CENTER),
    fill(255, 255, 0);
    rect(px, py, 300,300,angle);
    fill(255);
    rect(px - 50, py, 80,80,angle);
    rect(px + 50, py, 80,80,angle);
    fill(0);
    rect(px - 50, py, 30,30, angle);
    rect(px + 50, py, 30,30, angle);
    fill(255, 200, 200);
    rect(px, py + 80, 80,80, angle);
}
void gmain() {
    window(1920, 1080, full);
    float px = width / 2;
    float py = height / 2;
    float angle = 0;
    float ofsX = 100;
    float ofsY = 100;
    int sw = 1;
    while (notQuit) {
        ofsX = width / 2 - mouseX;
        ofsY = height / 2 - mouseY;
        if (isTrigger(KEY_SPACE)) { sw = 1 - sw; }
        angle += 0.01f;
        clear(60, 120, 240);
        for (int i = -5; i <= 5; i++) {
            if (sw == 1) {
                roundFace(px+ofsX*i, py+ofsY*i);
            }
            else {
                squareFace(px+ofsX*i, py+ofsY*i, angle);
            }
        }
        
        
    }
}
/*
#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    //データ
    struct COLOR green = { 0,255,0 };
    struct COLOR yellow = { 255,255,0 };
    struct COLOR red= { 255,0,0 };
    struct COLOR color = green;

    int hpMax = 500;
    int hp = hpMax;
    int hpWarning = hpMax * 0.5f;
    int hpDanger = hpMax * 0.3f;
    float px = 700;
    float py = 200;
    float h = 60;
    while(notQuit) {
        if (isTrigger(KEY_SPACE)) { hp = hpMax; }
        if (hp > 0) { hp -= 2; }

        if (hp > hpWarning) {
            color = green;
        }
        else if (hp > hpDanger) {
            color = yellow;
        }
        else {
            color = red;
        }
        clear(74, 84, 89);
        fill(128);
        rect(px, py, hpMax, h);
        fill(color);
        rect(px, py, hp, h);
        if (hp <= 0) {
            textSize(100);
            fill(255, 0, 0);
            text("Game Over", 700, 400);
        }
    
    }
}
*/
/*
#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    //データ
    int life = 5;
    float px = 700;
    float py = 200;
    float radius = 50;
    float space = 100;
    while (notQuit) {
        //データ更新
        if (isTrigger(KEY_A)) { life--; }
        if (isTrigger(KEY_D)) { life++; }
        //描画
        clear(74, 84, 89);
        fill(200, 150, 100);
        print((let)"life=" + life);
        strokeWeight(20);
        stroke(255);
        //whileバージョン
        int i = 0;
        fill(255, 200, 200);
        while (i< life) {
            float offsetX = space * i;
            circle(px + offsetX, py, radius * 2);
            i++;
        }
        //forバージョン
        fill(160, 200, 240);
        for(int i = 0; i<life; i++) {
            float offsetX = space * i;
            float offsetY = space * 2;
            circle(px + offsetX, py+offsetY, radius * 2); 
        }

    }
}
*/
/*
#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    float px = 1920 / 2;
    float py = 1080 / 2;
    float vx = 10;
    float radius = 150;
    float len = radius / 1.4142f * 2;
    float sw = radius / 8;
    float angle = 0;
    float anglespeed = 0.03f;
    while (notQuit) {
    px += vx;
    angle += anglespeed;
    if (px<0||px > 1920) { vx = -vx; }
    clear(60);
    strokeWeight(sw);
    stroke(255, 0, 255);
    circle(px, py, radius * 2);
    rectMode(CENTER);
    rect(px, py, len, len,angle);
    strokeWeight(sw * 4);
    point(px, py);
    strokeWeight(sw);
    line(1920 / 2, 0, px, py);
    }
}
*/