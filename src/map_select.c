#include "modding.h"
#include "functions.h"
#include "variables.h"
#include "recomputils.h"
#include "recompconfig.h"

#define MAP_ARRAY_SIZE (int)(sizeof(MyMapList) / sizeof(MapInfo))

typedef struct {
    unsigned short mapId;   
    unsigned short levelId; 
    char* name;             
} MapInfo;

MapInfo MyMapList[] ={
    {0x0000, 0, "(gcSectionMin)"},
    {MAP_1_SM_SPIRAL_MOUNTAIN,          LEVEL_B_SPIRAL_MOUNTAIN,        "Spiral Mountain"},
    {MAP_8C_SM_BANJOS_HOUSE,            LEVEL_B_SPIRAL_MOUNTAIN,        "SM - Banjo's House"},
    {MAP_69_GL_MM_LOBBY,                LEVEL_6_LAIR,                   "Lair - MM Lobby"},
    {MAP_6A_GL_TTC_AND_CC_PUZZLE,       LEVEL_6_LAIR,                   "Lair - TTC CC Puzzle Room"},
    {MAP_6B_GL_180_NOTE_DOOR,           LEVEL_6_LAIR,                   "Lair - 180 Note Door Room"},
    {MAP_6C_GL_RED_CAULDRON_ROOM,       LEVEL_6_LAIR,                   "Lair - Red Cauldron Room"},
    {MAP_6D_GL_TTC_LOBBY,               LEVEL_6_LAIR,                   "Lair - TTC Lobby"},
    {MAP_70_GL_CC_LOBBY,                LEVEL_6_LAIR,                   "Lair - CC Lobby"},
    {MAP_71_GL_STATUE_ROOM,             LEVEL_6_LAIR,                   "Lair - Grunty Statue Room"},
    {MAP_72_GL_BGS_LOBBY,               LEVEL_6_LAIR,                   "Lair - BGS Lobby"},
    {MAP_6E_GL_GV_LOBBY,                LEVEL_6_LAIR,                   "Lair - GV Lobby"},
    {MAP_6F_GL_FP_LOBBY,                LEVEL_6_LAIR,                   "Lair - FP Lobby"},
    {MAP_74_GL_GV_PUZZLE,               LEVEL_6_LAIR,                   "Lair - GV Puzzle Room"},
    {MAP_75_GL_MMM_LOBBY,               LEVEL_6_LAIR,                   "Lair - MMM Lobby"},
    {MAP_7A_GL_CRYPT,                   LEVEL_6_LAIR,                   "Lair - Inside the Crypt"},
    {MAP_76_GL_640_NOTE_DOOR,           LEVEL_6_LAIR,                   "Lair - 640 Note Door Room"},
    {MAP_77_GL_RBB_LOBBY,               LEVEL_6_LAIR,                   "Lair - RBB Lobby"},
    {MAP_78_GL_RBB_AND_MMM_PUZZLE,      LEVEL_6_LAIR,                   "Lair - RBB MMM Lobby"},
    {MAP_79_GL_CCW_LOBBY,               LEVEL_6_LAIR,                   "Lair - CCW Lobby"},
    {MAP_80_GL_FF_ENTRANCE,             LEVEL_6_LAIR,                   "Lair - FF Entrance"},
    {MAP_8E_GL_FURNACE_FUN,             LEVEL_6_LAIR,                   "Lair - Furnace Fun"},
    {MAP_93_GL_DINGPOT,                 LEVEL_6_LAIR,                   "Lair - Dingpot's Room"},
    {MAP_90_GL_BATTLEMENTS,             LEVEL_C_BOSS,                   "Boss - Grunty Fight"},
    {MAP_2_MM_MUMBOS_MOUNTAIN,          LEVEL_1_MUMBOS_MOUNTAIN,        "Mumbo's Mountain"},
    {MAP_C_MM_TICKERS_TOWER,            LEVEL_1_MUMBOS_MOUNTAIN,        "MM - Ticker's Tower"},
    {MAP_E_MM_MUMBOS_SKULL,             LEVEL_1_MUMBOS_MOUNTAIN,        "MM - Mumbo's Hut"},
    {MAP_7_TTC_TREASURE_TROVE_COVE,     LEVEL_2_TREASURE_TROVE_COVE,    "Treasure Trove Cove"},
    {MAP_5_TTC_BLUBBERS_SHIP,           LEVEL_2_TREASURE_TROVE_COVE,    "TTC - Blubber Ship Interior"},
    {MAP_6_TTC_NIPPERS_SHELL,           LEVEL_2_TREASURE_TROVE_COVE,    "TTC - Nipper's Shell"},
    {MAP_8F_TTC_SHARKFOOD_ISLAND,       LEVEL_2_TREASURE_TROVE_COVE,    "TTC - Sharkfood Island"},
    {MAP_A_TTC_SANDCASTLE,              LEVEL_2_TREASURE_TROVE_COVE,    "TTC - Sandcastle"},
    {MAP_B_CC_CLANKERS_CAVERN,          LEVEL_3_CLANKERS_CAVERN,        "Clanker's Cavern"},
    {MAP_21_CC_WITCH_SWITCH_ROOM,       LEVEL_3_CLANKERS_CAVERN,        "CC - Witch Switch Room"},
    {MAP_22_CC_INSIDE_CLANKER,          LEVEL_3_CLANKERS_CAVERN,        "CC - Inside Clanker"},
    {MAP_23_CC_GOLDFEATHER_ROOM,        LEVEL_3_CLANKERS_CAVERN,        "CC - Goldfeather Room"},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,       LEVEL_4_BUBBLEGLOOP_SWAMP,      "Bubblegloop Swamp"},
    {MAP_10_BGS_MR_VILE,                LEVEL_4_BUBBLEGLOOP_SWAMP,      "BGS - Mr. Vile's Minigame"},
    {MAP_11_BGS_TIPTUP,                 LEVEL_4_BUBBLEGLOOP_SWAMP,      "BGS - Tanktup"},
    {MAP_47_BGS_MUMBOS_SKULL,           LEVEL_4_BUBBLEGLOOP_SWAMP,      "BGS - Mumbo's Hut"},
    {MAP_27_FP_FREEZEEZY_PEAK,          LEVEL_5_FREEZEEZY_PEAK,         "Freezeezy Peak"},
    {MAP_53_FP_CHRISTMAS_TREE,          LEVEL_5_FREEZEEZY_PEAK,         "FP - Christmas Tree"},
    {MAP_41_FP_BOGGYS_IGLOO,            LEVEL_5_FREEZEEZY_PEAK,         "FP - Boggy's Igloo"},
    {MAP_7F_FP_WOZZAS_CAVE,             LEVEL_5_FREEZEEZY_PEAK,         "FP - Wozza's Cave"},
    {MAP_48_FP_MUMBOS_SKULL,            LEVEL_5_FREEZEEZY_PEAK,         "FP - Mumbo's Hut"},
    {MAP_12_GV_GOBIS_VALLEY,            LEVEL_7_GOBIS_VALLEY,           "Gobi's Valley"},
    {MAP_13_GV_MEMORY_GAME,             LEVEL_7_GOBIS_VALLEY,           "GV - Matching Pyramid"},
    {MAP_14_GV_SANDYBUTTS_MAZE,         LEVEL_7_GOBIS_VALLEY,           "GV - Maze Pyramid"},
    {MAP_15_GV_WATER_PYRAMID,           LEVEL_7_GOBIS_VALLEY,           "GV - Water Pyramid"},
    {MAP_16_GV_RUBEES_CHAMBER,          LEVEL_7_GOBIS_VALLEY,           "GV - Rubee's Chamber"},
    {MAP_1A_GV_INSIDE_JINXY,            LEVEL_7_GOBIS_VALLEY,           "GV - Sphinx"},
    {MAP_92_GV_SNS_CHAMBER,             LEVEL_7_GOBIS_VALLEY,           "GV - Secret Chamber"},
    {MAP_1B_MMM_MAD_MONSTER_MANSION,    LEVEL_A_MAD_MONSTER_MANSION,    "Mad Monster Mansion"},
    {MAP_1C_MMM_CHURCH,                 LEVEL_A_MAD_MONSTER_MANSION,    "MMM - Church"},
    {MAP_1D_MMM_CELLAR,                 LEVEL_A_MAD_MONSTER_MANSION,    "MMM - Cellar"},
    {MAP_24_MMM_TUMBLARS_SHED,          LEVEL_A_MAD_MONSTER_MANSION,    "MMM - Tumblar's Shed"},
    {MAP_25_MMM_WELL,                   LEVEL_A_MAD_MONSTER_MANSION,    "MMM - Well"},
    {MAP_26_MMM_NAPPERS_ROOM,           LEVEL_A_MAD_MONSTER_MANSION,    "MMM - Napper's Room"},
    {MAP_28_MMM_EGG_ROOM,               LEVEL_A_MAD_MONSTER_MANSION,    "MMM - Mansion Egg Room"},
    {MAP_29_MMM_NOTE_ROOM,              LEVEL_A_MAD_MONSTER_MANSION,    "MMM - Mansion Note Room"},
    {MAP_2A_MMM_FEATHER_ROOM,           LEVEL_A_MAD_MONSTER_MANSION,    "MMM - Mansion Feather Room"},
    {MAP_2B_MMM_SECRET_CHURCH_ROOM,     LEVEL_A_MAD_MONSTER_MANSION,    "MMM - Church Secret Room"},
    {MAP_2C_MMM_BATHROOM,               LEVEL_A_MAD_MONSTER_MANSION,    "MMM - Bathroom"},
    {MAP_2D_MMM_BEDROOM,                LEVEL_A_MAD_MONSTER_MANSION,    "MMM - Bedroom"},
    {MAP_2E_MMM_HONEYCOMB_ROOM,         LEVEL_A_MAD_MONSTER_MANSION,    "MMM - Floorboards"},
    {MAP_2F_MMM_WATERDRAIN_BARREL,      LEVEL_A_MAD_MONSTER_MANSION,    "MMM - Water Barrel"},
    {MAP_30_MMM_MUMBOS_SKULL,           LEVEL_A_MAD_MONSTER_MANSION,    "MMM - Mumbo's Hut"},
    {MAP_8D_MMM_INSIDE_LOGGO,           LEVEL_A_MAD_MONSTER_MANSION,    "MMM - Inside Loggo"},
    {MAP_31_RBB_RUSTY_BUCKET_BAY,       LEVEL_9_RUSTY_BUCKET_BAY,       "Rusty Bucket Bay"},
    {MAP_8B_RBB_ANCHOR_ROOM,            LEVEL_9_RUSTY_BUCKET_BAY,       "RBB - Anchor Room"},
    {MAP_34_RBB_ENGINE_ROOM,            LEVEL_9_RUSTY_BUCKET_BAY,       "RBB - Engine Room"},
    {MAP_35_RBB_WAREHOUSE,              LEVEL_9_RUSTY_BUCKET_BAY,       "RBB - Warehouse"},
    {MAP_36_RBB_BOATHOUSE,              LEVEL_9_RUSTY_BUCKET_BAY,       "RBB - Boathouse"},
    {MAP_37_RBB_CONTAINER_1,            LEVEL_9_RUSTY_BUCKET_BAY,       "RBB - Container 1"},
    {MAP_3E_RBB_CONTAINER_2,            LEVEL_9_RUSTY_BUCKET_BAY,       "RBB - Container 2"},
    {MAP_38_RBB_CONTAINER_3,            LEVEL_9_RUSTY_BUCKET_BAY,       "RBB - Container 3"},
    {MAP_39_RBB_CREW_CABIN,             LEVEL_9_RUSTY_BUCKET_BAY,       "RBB - Crew Cabin"},
    {MAP_3A_RBB_BOSS_BOOM_BOX,          LEVEL_9_RUSTY_BUCKET_BAY,       "RBB - Boss Boom Box"},
    {MAP_3B_RBB_STORAGE_ROOM,           LEVEL_9_RUSTY_BUCKET_BAY,       "RBB - Storage Room"},
    {MAP_3C_RBB_KITCHEN,                LEVEL_9_RUSTY_BUCKET_BAY,       "RBB - Kitchen"},
    {MAP_3D_RBB_NAVIGATION_ROOM,        LEVEL_9_RUSTY_BUCKET_BAY,       "RBB - Navigation Room"},
    {MAP_3F_RBB_CAPTAINS_CABIN,         LEVEL_9_RUSTY_BUCKET_BAY,       "RBB - Captain's Cabin"},
    {MAP_40_CCW_HUB,                    LEVEL_8_CLICK_CLOCK_WOOD,       "Click Clock Wood"},
    {MAP_43_CCW_SPRING,                 LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Spring"},
    {MAP_44_CCW_SUMMER,                 LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Summer"},
    {MAP_45_CCW_AUTUMN,                 LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Autumn"},
    {MAP_46_CCW_WINTER,                 LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Winter"},
    {MAP_4A_CCW_SPRING_MUMBOS_SKULL,    LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Mumbo's Hut (Spring)"},
    {MAP_4B_CCW_SUMMER_MUMBOS_SKULL,    LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Mumbo's Hut (Summer)"},
    {MAP_4C_CCW_AUTUMN_MUMBOS_SKULL,    LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Mumbo's Hut (Autumn)"},
    {MAP_4D_CCW_WINTER_MUMBOS_SKULL,    LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Mumbo's Hut (Winter)"},
    {MAP_5A_CCW_SUMMER_ZUBBA_HIVE,      LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Zubba Hive (Summer)"},
    {MAP_5B_CCW_SPRING_ZUBBA_HIVE,      LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Zubba Hive (Spring)"},
    {MAP_5C_CCW_AUTUMN_ZUBBA_HIVE,      LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Zubba Hive (Autumn)"},
    {MAP_5E_CCW_SPRING_NABNUTS_HOUSE,   LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Nabnut's House (Spring)"},
    {MAP_5F_CCW_SUMMER_NABNUTS_HOUSE,   LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Nabnut's House (Summer)"},
    {MAP_60_CCW_AUTUMN_NABNUTS_HOUSE,   LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Nabnut's House (Autumn)"},
    {MAP_61_CCW_WINTER_NABNUTS_HOUSE,   LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Nabnut's House (Winter)"},
    {MAP_62_CCW_WINTER_HONEYCOMB_ROOM,  LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Nabnut's Attic (Winter)"},
    {MAP_63_CCW_AUTUMN_NABNUTS_WATER_SUPPLY, LEVEL_8_CLICK_CLOCK_WOOD,  "CCW - Nabnut's Water Supply (Autumn)"},
    {MAP_64_CCW_WINTER_NABNUTS_WATER_SUPPLY, LEVEL_8_CLICK_CLOCK_WOOD,  "CCW - Nabnut's Water Supply (Winter)"},
    {MAP_65_CCW_SPRING_WHIPCRACK_ROOM,  LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Top (Spring)"},
    {MAP_66_CCW_SUMMER_WHIPCRACK_ROOM,  LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Top (Summer)"},
    {MAP_67_CCW_AUTUMN_WHIPCRACK_ROOM,  LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Top (Autumn)"},
    {MAP_68_CCW_WINTER_WHIPCRACK_ROOM,  LEVEL_8_CLICK_CLOCK_WOOD,       "CCW - Top (Winter)"},
    {MAP_1E_CS_START_NINTENDO,          LEVEL_D_CUTSCENE,               "Intro - Start - Nintendo"},
    {MAP_1F_CS_START_RAREWARE,          LEVEL_D_CUTSCENE,               "Intro - Start - Rareware"},
    {MAP_20_CS_END_NOT_100,             LEVEL_D_CUTSCENE,               "Intro - End Scene 2 : Not 100 "},
    {MAP_7B_CS_INTRO_GL_DINGPOT_1,      LEVEL_D_CUTSCENE,               "Intro - Grunties Lair 1 - Scene 1"},
    {MAP_81_CS_INTRO_GL_DINGPOT_2,      LEVEL_D_CUTSCENE,               "Intro - Grunties Lair 2"},
    {MAP_82_CS_ENTERING_GL_MACHINE_ROOM,LEVEL_D_CUTSCENE,               "Intro - Grunties Lair 3 - Machine 1"},
    {MAP_83_CS_GAME_OVER_MACHINE_ROOM,  LEVEL_D_CUTSCENE,               "Intro - Grunties Lair 4 - Game Over"},
    {MAP_84_CS_UNUSED_MACHINE_ROOM,     LEVEL_D_CUTSCENE,               "Intro - Grunties Lair 5"},
    {MAP_7C_CS_INTRO_BANJOS_HOUSE_1,    LEVEL_D_CUTSCENE,               "Intro - Inside Banjo's Cave 1 - Scenes 3,7"},
    {MAP_89_CS_INTRO_BANJOS_HOUSE_2,    LEVEL_D_CUTSCENE,               "Intro - Inside Banjo's Cave 2"},
    {MAP_8A_CS_INTRO_BANJOS_HOUSE_3,    LEVEL_D_CUTSCENE,               "Intro - Inside Banjo's Cave 3"},
    {MAP_7D_CS_SPIRAL_MOUNTAIN_1,       LEVEL_D_CUTSCENE,               "Intro - Spiral 'A' - Scenes 2,4"},
    {MAP_7E_CS_SPIRAL_MOUNTAIN_2,       LEVEL_D_CUTSCENE,               "Intro - Spiral 'B' - Scenes 5,6"},
    {MAP_85_CS_SPIRAL_MOUNTAIN_3,       LEVEL_D_CUTSCENE,               "Intro - Spiral 'C'"},
    {MAP_86_CS_SPIRAL_MOUNTAIN_4,       LEVEL_D_CUTSCENE,               "Intro - Spiral 'D'"},
    {MAP_87_CS_SPIRAL_MOUNTAIN_5,       LEVEL_D_CUTSCENE,               "Intro - Spiral 'E'"},
    {MAP_88_CS_SPIRAL_MOUNTAIN_6,       LEVEL_D_CUTSCENE,               "Intro - Spiral 'F'"},
    {MAP_94_CS_INTRO_SPIRAL_7,          LEVEL_D_CUTSCENE,               "Intro - Spiral 'G'"},
    {MAP_95_CS_END_ALL_100,             LEVEL_D_CUTSCENE,               "Intro - End Scene 3 : All 100"},
    {MAP_98_CS_END_SPIRAL_MOUNTAIN_1,   LEVEL_D_CUTSCENE,               "Intro - Grunty Threat 1"},
    {MAP_99_CS_END_SPIRAL_MOUNTAIN_2,   LEVEL_D_CUTSCENE,               "Intro - Grunty Threat 2"},
    {MAP_96_CS_END_BEACH_1,             LEVEL_D_CUTSCENE,               "Intro - End Scene"},
    {MAP_97_CS_END_BEACH_2,             LEVEL_D_CUTSCENE,               "Intro - End Scene 4"},
    {MAP_91_FILE_SELECT,                LEVEL_B_SPIRAL_MOUNTAIN,        "Training - Banjo Cave Save"}
};

static int gMenuInputLock = 0;
int gMapSelectIndex = 1;
static int isMapMenuOpen = 0; 

void unlockMapMenuInput(void) {
    gMenuInputLock = 0;
}

RECOMP_HOOK ("func_80295C14") void OnPlayerUpdate(void) { 

    if (bakey_pressed(BUTTON_D_UP)) {
        if (isMapMenuOpen == 0) {
            isMapMenuOpen = 1;
        } else {
            isMapMenuOpen = 0;
        }

        gMenuInputLock = 1;
        timedFunc_set_0(0.25f, unlockMapMenuInput);
    }
    
    if (isMapMenuOpen) {

        if (bakey_pressed(BUTTON_D_RIGHT)) {
            gMapSelectIndex++;
            if (gMapSelectIndex >= MAP_ARRAY_SIZE) gMapSelectIndex = 1; 
        }
        
        if (bakey_pressed(BUTTON_D_LEFT)) {
            gMapSelectIndex--;
            if (gMapSelectIndex < 1) gMapSelectIndex = MAP_ARRAY_SIZE - 1; 
        }

        if (bakey_pressed(BUTTON_L)) {
            transitionToMap(MyMapList[gMapSelectIndex].mapId, 1, 2); 
        }

        static char upperName[64]; 
        char* src = MyMapList[gMapSelectIndex].name;
        
        if (src == 0) {
            return;
        }

        int i = 0;
        while (src[i] != '\0' && i < 63) {
            char c = src[i];
            if (c >= 'a' && c <= 'z') {
                upperName[i] = c - 32;
            } else {
                upperName[i] = c;
            }
            i++;
        }
        upperName[i] = '\0';

        print_dialog_w_bg(20, DEFAULT_FRAMEBUFFER_HEIGHT - 20, (u8*)upperName);
    }
}
