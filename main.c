#include "raylib.h"
#include "math.h"
#include "string.h"

#define MAX_ENTITY  3000
#define MAX_STRING_LEN 50

typedef struct
{


    int  cursor;

    char name[MAX_ENTITY][MAX_STRING_LEN];
    
    Vector2 pos[MAX_ENTITY];
    int size[MAX_ENTITY];
    int speed[MAX_ENTITY];
    Color color[MAX_ENTITY];

} Ent;


int val_cursor(Ent *entlist)
{
    if (entlist->cursor == 0)
    {
        entlist->cursor = 1;
    }

    return entlist->cursor;
}

void normalize_vector(Vector2 *v)
{
    float m = sqrtf(v->x * v->x + v->y * v->y);
    if (m == 0) return;
    v->x /= m;
    v->y /= m;


void scale_vector(Vector2 *v, float scale)
{
    *v = (Vector2) {v->x*scale, v->y*scale};
}

void setup_player(Ent *entlist)
{

    strcpy(entlist->name[0], "Player");
    entlist->pos[0] = (Vector2) {200, 200};
    entlist->speed[0] = 10;
    entlist->size[0] = 50;
    entlist->color[0] = BLUE;

}

void drawent(Ent *entlist, int id)
{
        DrawRectangleV(entlist->pos[id], (Vector2) {entlist->size[id], entlist->size[id]}, entlist->color[id]);
}

void process_input(Ent *entlist)
{
    
    int x = 0;
    int y = 0;

    if (IsKeyDown(KEY_UP))
    {
        y += -1;

    }
    if (IsKeyDown(KEY_DOWN))
    {
        y += 1;

    }


    if (IsKeyDown(KEY_RIGHT))
    {
        x += 1;

    }
    if (IsKeyDown(KEY_LEFT))
    {
        x += -1;

    }

    Vector2 mv = (Vector2) {x,y};
    normalize_vector(&mv);
    scale_vector(&mv, entlist->speed[0]);
    entlist->pos[0].x += mv.x;
    entlist->pos[0].y += mv.y;


}

int main(void)
{
    Ent  entlist = {0};


    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Shooter Game");

    SetTargetFPS(60);

    setup_player(&entlist);
    while (!WindowShouldClose()) {
        process_input(&entlist);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawent(&entlist, 0);
        EndDrawing();
    }

    CloseWindow();
}
