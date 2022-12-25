/*
 * Copyright 2023 AzgathCore
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "siege_of_orgrimmar.hpp"

#define NAZGRIM_POWER_TYPE POWER_MANA
#define NAZGRIM_POWER_MAX 100

enum ScriptedTexts
{
    SAY_AGGRO_ALLIANCE = 0,
    SAY_AGGRO_HORDE = 1,
    SAY_DEATH_ALLIANCE = 2,
    SAY_DEATH_GAMON_1 = 3,
    SAY_DEATH_GAMON_2 = 4,
    SAY_DEATH_HORDE_1 = 5,
    SAY_DEATH_HORDE_2 = 6,
    SAY_ADDS = 7,
    SAY_ADDS_ALL = 8,
    SAY_INTRO_ALLIANCE = 9,

    SAY_IRON_JUGGERNAUT_INTRO = 10,
    SAY_IRON_JUGGERNAUT_DEATH = 11,
    SAY_IRON_JUGGERNAUT_OUTRO = 12,

    SAY_INTRO_HORDE = 13,
    SAY_WIPE = 14,
};

enum Spells
{
    SPELL_ZERO_MANA_REGEN = 96301,

    SPELL_BERSERK = 26662,

    SPELL_BATTLE_STANCE = 143589,
    SPELL_BERSERKER_STANCE = 143594,
    SPELL_DEFENSIVE_STANCE = 143593,

    SPELL_GENERATE_RAGE = 144278, // from defensive stance
    SPELL_GENERATE_RAGE_ENERGIZE = 143597,

    SPELL_COOLING_OFF = 143484,

    SPELL_ENEGRIZE_NAZGRIM_1 = 143590, // 3 points from banner
    SPELL_ENERGIZE_NAZGRIM_2 = 143876, // 3 points from aftershock
    SPELL_ENERGIZE_NAZGRIM_3 = 143877, // 5 points from ravager

    SPELL_SUNDERING_BLOW = 143494,

    SPELL_BONECRACKER = 143638,

    SPELL_HEROIC_SHOCKWAVE = 143500,
    SPELL_HEROIC_SHOCKWAVE_DMG = 143716,
    SPELL_HEROIC_SHOCKWAVE_FORCE = 143713,
    SPELL_HEROIC_SHOCKWAVE_SUMMON = 143715,

    SPELL_AFTERSHOCK = 143712,

    SPELL_KORKRON_BANNER = 143591,
    SPELL_KORKRON_BANNER_SUMMON = 143501,
    SPELL_KORKRON_BANNER_AURA = 143536,
    SPELL_KORKRON_BANNER_BUFF = 143535,

    SPELL_WAR_SONG = 143503,

    SPELL_RAVAGER = 143872,
    SPELL_RAVAGER_AURA = 143874,
    SPELL_RAVAGER_DMG = 143873,

    SPELL_EXECUTE = 143502,

    // Kor'kron Ironblade
    SPELL_IRONSTORM = 143420,
    SPELL_IRONSTORM_DMG = 143421,
    SPELL_LAST_STAND = 143427,

    // Kor'kron Arcweaver
    SPELL_ARCANE_SHOCK = 143432,
    SPELL_MAGICSTRIKE = 143431,
    SPELL_UNSTABLE_BLINK = 143433,

    // Kor'kron Assassin
    SPELL_ASSASSINS_MARK = 143480,
    SPELL_BACKSTAB = 143481,
    SPELL_STEALTH = 118969,

    // Kor'kron Warshaman
    SPELL_EARTH_SHIELD = 143475,
    SPELL_EARTH_SHIELD_HEAL = 143479,
    SPELL_EMPOWERED_CHAIN_HEAL = 143473,
    SPELL_HEALING_TIDE_TOTEM = 143474,
    SPELL_HEALING_TIDE = 143477,
    SPELL_HEALING_TIDE_HEAL = 143478,

    // Kor'kron Sniper
    SPELL_SHOT = 143884,
    SPELL_HUNTERS_MARK = 143882,
    SPELL_MULTI_SHOT = 143887,
};

enum Adds
{
    NPC_KORKRON_BANNER = 71626,
    NPC_GENERAL_NAZGRIM_AFTERSHOCK = 71697,
    NPC_RAVAGER = 71762,

    NPC_ORGRIMMAR_FAITHFUL = 71715,
    NPC_KORKRON_IRONBLADE = 71516,
    NPC_KORKRON_ARCWEAVER = 71517,
    NPC_KORKRON_ASSASSIN = 71518,
    NPC_KORKRON_WARSHAMAN = 71519,
    NPC_HEALING_TIDE_TOTEM = 71610,
    NPC_KORKRON_SNIPER = 71656,
};

enum Events
{
    EVENT_SWITCH_STANCE = 1,
    EVENT_SUNDERING_BLOW,
    EVENT_BONECRACKER,
    EVENT_EXECUTE,
    EVENT_RAGE_SPELL,
    EVENT_BERSERK,
    EVENT_SUMMON_ADDS,

    // Kor'kron Warshaman
    EVENT_IRONSTORM,

    // Kor'kron Arcweaver
    EVENT_ARCANE_SHOCK,
    EVENT_MAGICSTRIKE,
    EVENT_UNSTABLE_BLINK,

    // Kor'kron Assassin
    EVENT_BACKSTAB,
    EVENT_ASSASSINS_MARK,

    // Kor'kron Warshaman
    EVENT_EARTH_SHIELD,
    EVENT_EMPOWERED_CHAIN_HEAL,
    EVENT_HEALING_TIDE_TOTEM,

    // Kor'kron Sniper
    EVENT_SHOT,
    EVENT_MULTI_SHOT,
};

enum Datas
{
    DATA_ADD_POSITION = 1,
};

enum Actions
{

};

enum DisplayIds
{
    DISPLAY_ITEM_RAVAGER = 7717,
};

enum Timers
{
    TIMER_BERSERK = 10 * MINUTE * IN_MILLISECONDS,
    TIMER_EVADE_CHECK = 5 * IN_MILLISECONDS,

    TIMER_RAGE_SPELL = 1 * IN_MILLISECONDS,

    TIMER_SWITCH_STANCE_FIRST = 1 * IN_MILLISECONDS,
    TIMER_SWITCH_STANCE = 60 * IN_MILLISECONDS,

    TIMER_SUNDERING_BLOW_FIRST = 8 * IN_MILLISECONDS,
    TIMER_SUNDERING_BLOW = 8 * IN_MILLISECONDS,

    TIMER_BONECRACKER_FIRST = 20 * IN_MILLISECONDS,
    TIMER_BONECRACKER = 30 * IN_MILLISECONDS,

    TIMER_EXECUTE = 18 * IN_MILLISECONDS,

    TIMER_SUMMON_ADDS_FIRST = 45 * IN_MILLISECONDS,
    TIMER_SUMMON_ADDS = 45 * IN_MILLISECONDS,

    // Kor'kron Ironblade
    TIMER_IRONSTORM_FIRST_MIN = 6 * IN_MILLISECONDS,
    TIMER_IRONSTORM_FIRST_MAX = 10 * IN_MILLISECONDS,
    TIMER_IRONSTORM_MIN = 3 * IN_MILLISECONDS,
    TIMER_IRONSTORM_MAX = 5 * IN_MILLISECONDS,

    // Kor'kron Arcweaver
    TIMER_ARCANE_SHOCK_FIRST = 1 * IN_MILLISECONDS,
    TIMER_ARCANE_SHOCK = 1500,
    TIMER_MAGICSTRIKE_FIRST_MIN = 5 * IN_MILLISECONDS,
    TIMER_MAGICSTRIKE_FIRST_MAX = 5 * IN_MILLISECONDS,
    TIMER_MAGICSTRIKE_MIN = 15 * IN_MILLISECONDS,
    TIMER_MAGICSTRIKE_MAX = 20 * IN_MILLISECONDS,
    TIMER_UNSTABLE_BLINK_MIN = 20 * IN_MILLISECONDS,
    TIMER_UNSTABLE_BLINK_MAX = 25 * IN_MILLISECONDS,

    // Kor'kron Assassin
    TIMER_BACKSTAB = 2 * IN_MILLISECONDS,

    // Kor'kron Warshaman
    TIMER_EARTH_SHIELD_FIRST = 5 * IN_MILLISECONDS,
    TIMER_EARTH_SHIELD = 40 * IN_MILLISECONDS,
    TIMER_EMPOWERED_CHAIN_HEAL = 15 * IN_MILLISECONDS,
    TIMER_HEALING_TIDE_TOTEM = 20 * IN_MILLISECONDS,

    // Kor'kron Sniper
    TIMER_SHOT_FIRST = 1,
    TIMER_SHOT = 3 * IN_MILLISECONDS,
    TIMER_MULTI_SHOT_FIRST = 10 * IN_MILLISECONDS,
    TIMER_MULTI_SHOT = 25 * IN_MILLISECONDS,
};

enum MovementPoints : int
{
    POINT_ADDS_POSITION = 1,
    POINT_RAVAGER,
};

enum Stances : int
{
    STANCE_NONE = 0,
    BATTLE_STANCE = 1,
    BERSERKER_STANCE = 2,
    DEFENSIVE_STANCE = 3,
};

#define ADDS_NORMAL_COUNT 2
#define ADDS_HEROIC_COUNT 3
#define ADD_POSITIONS_COUNT 5

const Position addSpawnPos[ADD_POSITIONS_COUNT][2] =
{
    {
        {1584.02f, -4591.88f, -66.80f, 5.84f},
        {1588.61f, -4594.49f, -66.73f, 5.78f}
    },
    {
        {1591.88f, -4584.03f, -66.81f, 5.22f},
        {1594.81f, -4590.88f, -66.73f, 5.02f}
    },
    {
        {1559.00f, -4621.40f, -66.92f, 5.76f},
        {1564.27f, -4624.34f, -66.93f, 5.77f}
    },
    {
        {1558.65f, -4634.91f, -67.05f, 0.50f},
        {1563.88f, -4632.72f, -67.05f, 0.37f}
    },
    {
        {1568.02f, -4647.59f, -66.84f, 0.78f},
        {1572.80f, -4642.79f, -66.70f, 0.78f}
    }
};

#define RAVAGER_POSITIONS_COUNT 25
const Position ravagerPos[RAVAGER_POSITIONS_COUNT] =
{
    {1643.64f, -4645.60f, -66.79f, 3.44f},
    {1637.34f, -4647.63f, -66.76f, 3.45f},
    {1617.09f, -4653.23f, -66.70f, 3.36f},
    {1597.75f, -4646.55f, -66.66f, 2.10f},
    {1606.33f, -4636.58f, -66.66f, 0.16f},
    {1621.81f, -4635.69f, -66.66f, 0.06f},
    {1633.32f, -4630.58f, -66.71f, 0.86f},
    {1635.59f, -4622.14f, -66.80f, 1.59f},
    {1629.13f, -4620.30f, -66.70f, 3.62f},
    {1617.72f, -4626.42f, -66.66f, 3.50f},
    {1610.47f, -4629.20f, -66.67f, 3.51f},
    {1588.71f, -4634.87f, -66.70f, 3.17f},
    {1576.44f, -4625.86f, -66.68f, 1.82f},
    {1582.23f, -4621.98f, -66.69f, 0.15f},
    {1604.74f, -4618.87f, -66.70f, 0.20f},
    {1617.71f, -4615.71f, -66.68f, 0.27f},
    {1627.99f, -4606.91f, -66.67f, 1.36f},
    {1623.68f, -4596.37f, -66.37f, 2.48f},
    {1609.05f, -4589.64f, -66.62f, 2.87f},
    {1601.66f, -4595.68f, -66.68f, 4.78f},
    {1597.47f, -4607.35f, -66.69f, 3.39f},
    {1584.17f, -4608.35f, -66.68f, 3.33f},
    {1581.86f, -4619.30f, -66.68f, 4.48f},
    {1568.73f, -4627.20f, -66.79f, 4.14f},
    {1567.53f, -4636.09f, -66.87f, 5.06f}
};

#define EVADE_DISTANCE 95.f

const Position centerOfRoomPos = { 1608.81f, -4629.61f, -66.60f, 0.0f };
#define DISTANCE_FROM_CENTER 30.f

void AddSC_boss_general_nazgrim()
{
    
}