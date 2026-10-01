#include "include/raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"

#define MAX_GUI_STYLES_AVAILABLE 20
#include "include/styles/style_advance.h"
#include "include/styles/style_amber.h"
#include "include/styles/style_ashes.h"
#include "include/styles/style_bluish.h"
#include "include/styles/style_brick.h"
#include "include/styles/style_candy.h"
#include "include/styles/style_cherry.h"
#include "include/styles/style_cyber.h"
#include "include/styles/style_dark.h"
#include "include/styles/style_enefete.h"
#include "include/styles/style_genesis.h"
#include "include/styles/style_jungle.h"
#include "include/styles/style_lavanda.h"
#include "include/styles/style_pocket.h"
#include "include/styles/style_rltech.h"
#include "include/styles/style_sunny.h"
#include "include/styles/style_terminal.h"
#include "include/styles/style_turbo.h"
#include "include/styles/style_wisteria.h"

static void ChangeTheme();
static void LoadButton();
static void SaveButton();

int VisualStyleActive = 0;
int PrevVisualStyleActive = -1;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 288;
    int screenHeight = 248;

    InitWindow(screenWidth, screenHeight, "Tracker");

    // layout_name: controls initialization
    //----------------------------------------------------------------------------------
    const char *WindowBoxName = "The FINALS - RS Tracker v0.1b";
    const char *RS_StatsOutlineText = "Result";
    const char *RS_ResultLabelText = "Total RS Change Today:";
    const char *GroupBox003Text = "RS Input";
    const char *ChangeThemeText = "Theme";
    const char *Label005Text = "How much RS did you get?";
    const char *LoadButtonText = "Load";
    const char *SaveButtonText = "Save";
    const char *RS_GainLabelText = "Total RS Gained Today:";
    const char *RS_LostLabelText = "Total RS Lost Today:";

    Vector2 anchor01 = { 0, 0 };
    Vector2 anchor02 = { 8, 192 };

    bool WindowBox000Active = true;
    bool EditMode = false;
    int Value = 0;
    //----------------------------------------------------------------------------------

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

            // raygui: controls drawing
            //----------------------------------------------------------------------------------
            if (WindowBox000Active)
            {
                WindowBox000Active = !GuiWindowBox((Rectangle){ anchor01.x + 0, anchor01.y + 0, 288, 248 }, WindowBoxName);
                GuiGroupBox((Rectangle){ anchor01.x + 8, anchor01.y + 128, 224, 112 }, RS_StatsOutlineText);
                GuiLabel((Rectangle){ anchor01.x + 16, anchor01.y + 136, 208, 32 }, RS_ResultLabelText);
                GuiGroupBox((Rectangle){ anchor01.x + 8, anchor01.y + 32, 224, 80 }, GroupBox003Text);
                if (GuiButton((Rectangle){ anchor01.x + 240, anchor01.y + 176, 40, 64 }, ChangeThemeText)) ChangeTheme();
                GuiLabel((Rectangle){ anchor01.x + 16, anchor01.y + 40, 168, 32 }, Label005Text);
                if (GuiValueBox((Rectangle){ anchor01.x + 16, anchor01.y + 72, 168, 32 }, "", &Value, 0, 100, EditMode)) EditMode = !EditMode;
                if (GuiButton((Rectangle){ anchor01.x + 240, anchor01.y + 104, 40, 64 }, LoadButtonText)) LoadButton();
                if (GuiButton((Rectangle){ anchor01.x + 240, anchor01.y + 32, 40, 64 }, SaveButtonText)) SaveButton();
                GuiLabel((Rectangle){ anchor01.x + 16, anchor01.y + 168, 208, 32 }, RS_GainLabelText);
                GuiLabel((Rectangle){ anchor01.x + 16, anchor01.y + 200, 208, 32 }, RS_LostLabelText);
            }
            //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------
static void ChangeTheme()
{
    VisualStyleActive++;

    if (VisualStyleActive >= MAX_GUI_STYLES_AVAILABLE) {
        VisualStyleActive = 0;
    }

    if (VisualStyleActive != PrevVisualStyleActive) {

        GuiLoadStyleDefault();

        switch (VisualStyleActive) {
        case 0:  GuiLoadStyleDefault(); break;
        case 1:  GuiLoadStyleDark(); break;
        case 2:  GuiLoadStyleAdvance(); break;
        case 3:  GuiLoadStyleAmber(); break;
        case 4:  GuiLoadStyleAshes(); break;
        case 5:  GuiLoadStyleBluish(); break;
        case 6:  GuiLoadStyleBrick(); break;
        case 7:  GuiLoadStyleCandy(); break;
        case 8:  GuiLoadStyleCherry(); break;
        case 9:  GuiLoadStyleCyber(); break;
        case 10: GuiLoadStyleEnefete(); break;
        case 11: GuiLoadStyleGenesis(); break;
        case 12: GuiLoadStyleJungle(); break;
        case 13: GuiLoadStyleLavanda(); break;
        case 14: GuiLoadStylePocket(); break;
        case 15: GuiLoadStyleRLTech(); break;
        case 16: GuiLoadStyleSunny(); break;
        case 17: GuiLoadStyleTerminal(); break;
        case 18: GuiLoadStyleTurbo(); break;
        case 19: GuiLoadStyleWisteria(); break;
        default: break;
        }

        PrevVisualStyleActive = VisualStyleActive;
    }
}
static void LoadButton()
{
    // TODO: Implement control logic
}
static void SaveButton()
{
    // TODO: Implement control logic
}
