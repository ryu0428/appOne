#define _SHOOT
#ifdef _SHOOT
#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    struct PLAYER {
        float px, py, w, h, vx;
    };
    struct BULLET {
        float px, py, w, h, vy;
        int hp = 0;
    };
    struct PLAYER p;
    p.px = width / 2;
    p.py =  height- 150;
    p.w = 100;
    p.h = 200;
    p.vx = 10;
    struct BULLET b;
    b.px = p.px;
    b.py = p.py;
    b.w = 20;
    b.h = 40;
    b.vy = -10;
    while (notQuit) {
        if (isPress(KEY_A)) { p.px += -p.vx; }
        if (isPress(KEY_D)) { p.px += p.vx; }
        if (isTrigger(KEY_SPACE)) {
            if (b.hp == 0) {
                b.hp = 1;
                b.px = p.px;
                b.py = p.py;
            }
        }
        if (b.hp > 0) {
            b.py += b.vy;
            if (b.py < -b.h) {

            }
        }
        clear();
        rectMode(CENTER);
        rect(p.px, p.py, p.w, p.h);
        if (b.hp > 0) {
            rect(b.px, b.py, b.w, b.h);
        }
    }
}
#endif
#ifdef _FACE
#include"libOne.h"
#include"face.h"
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
#endif
#ifdef _HPGAUGE
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
#endif
#ifdef _LIFE
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
#endif
#ifdef _MOVE
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
#endif