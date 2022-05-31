#include "raylib.h"

int main()
{
    // Window Dimensions
    int width = 800;
    int height = 450;
    InitWindow(width,height,"Stan's Window");
    // Circle Dimenions
    int circle_x = 175;
    int circle_y = 100;
    int circle_radius = 25;
    //Circle edges
    int l_circle_x = circle_x - circle_radius;
    int r_circle_x = circle_x + circle_radius;
    int u_circle_y = circle_y - circle_radius;
    int b_circle_y = circle_y + circle_radius;
    //Axe Dimensions
    int axe_x = 400;
    int axe_y = 0;
    int axe_length = 50;
    // Axe edges
    int l_axe_x = axe_x;
    int r_axe_x = axe_x + axe_length;
    int u_axe_y = axe_y;
    int b_axy_y = axe_y + axe_length;
    // Directions
    int direction = 10;

    bool collision_with_axe = (b_axy_y >= u_circle_y) && 
                              (u_axe_y <= b_circle_y) && 
                              (r_axe_x >= l_circle_x) && 
                              (l_axe_x <= r_circle_x);

    SetTargetFPS(60);
    while (WindowShouldClose() != true)
    {
    //  Game Logic Begins 
        BeginDrawing();
        ClearBackground(WHITE);
        
        if (collision_with_axe)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else
        {

        // Update the edges
        l_circle_x = circle_x - circle_radius;
        r_circle_x = circle_x + circle_radius;
        u_circle_y = circle_y - circle_radius;
        b_circle_y = circle_y + circle_radius;
        l_axe_x = axe_x;
        r_axe_x = axe_x + axe_length;
        u_axe_y = axe_y;
        b_axy_y = axe_y + axe_length;
        // Update collision with axe
        collision_with_axe = (b_axy_y >= u_circle_y) && 
                              (u_axe_y <= b_circle_y) && 
                              (r_axe_x >= l_circle_x) && 
                              (l_axe_x <= r_circle_x);

        //  Drawing circle
            DrawCircle(circle_x,circle_y,circle_radius,BLUE);
        //  Drawing rectangle
            DrawRectangle(axe_x,axe_y,axe_length,axe_length,RED);
        //  Move the axe
            axe_y += direction;
            if (axe_y > height || axe_y < 0)
            {
                direction = -direction;
            }    
        //  Movement of circle
            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x +=  10;
            }
            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }
        }


        EndDrawing();
    //  Game Logic Ends
    }
    
  
}

