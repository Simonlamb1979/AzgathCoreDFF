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
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "uldir.h"

enum Spells
{
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
    SPELL_EXPLOSIVE_CORRUPTION_TARGET_SELECTOR = 272504,
    SPELL_EXPLOSIVE_CORRUPTION = 272505,
    SPELL_UNDULATING_MASS = 263321,
    SPELL_UNDULATING_MASS_AT = 263320,
    SPELL_UNDULATING_MASS_AT2 = 271953,
    SPELL_UNCLEAN_CONTAGION = 267657,
    SPELL_UNCLEAN_CONTAGION_AURA = 267659,
    SPELL_CORRUPTING_BITE = 270443,
    SPELL_CORRUPTING_BITE_DMG = 270454,
    SPELL_GROWING_CORRUPTION = 270447,
    SPELL_VIRULENT_CORRUPTION_AT = 272513,
    SPELL_VIRULENT_CORRUPTION = 273486,
    SPELL_VIRULENT_CORRUPTION_AT_HALF = 273540,
    SPELL_VIRULENT_CORRUPTION_AT2 = 277081,
    SPELL_BLIGHTED_GROUND = 270287,
    SPELL_BLIGHTED_GROUND_AT = 270286,
    SPELL_WAVE_OF_CORRUPTION_TARGET_SELECTOR = 270373,
    SPELL_WAVE_OF_CORRUPTION_DMG_N = 273477,
    SPELL_WAVE_OF_CORRUPTION_DMG_H = 270385,
    SPELL_WAVE_OF_CORRUPTION_KNOCK_BACK = 275703,
    SPELL_WAVE_OF_CORRUPTION = 270386,
    SPELL_GAZE_OF_GHUNN = 275160,
    SPELL_POWER_MATRIX_COLLECT = 269455,
    SPELL_POWER_MATRIX = 263372,
    SPELL_POWER_MATRIX_ROOT = 263426,
    SPELL_POWER_MATRIX_DECREASE_SPEED = 263420,
    SPELL_POWER_MATRIX_ENERGIZE = 263433,
    SPELL_POWER_MATRIX_COSMETICS = 263443,
    SPELL_TORMENT = 267427,
    SPELL_REORIGINATION_BLAST_CAST = 267761,
    SPELL_REORIGINATION_BLAST_DAMAGE_MAIN = 263503,
    SPELL_REORIGINATION_BLAST_STUN = 263504,    
    SPELL_REORIGINATION_BLAST_ENERGIZE = 269439,
    //SPELL_REORIGINATION_BLAST_DAMAGE = 281444, // not used
    SPELL_COLLAPSE = 276893,
    SPELL_COLLAPSE_PERIODIC = 276839,
    SPELL_IMPERFECT_PHYSIOLOGY = 263436,
    SPELL_IMPERFECT_PHYSIOLOGY_SELECTOR = 273214,
    SPELL_DARK_YOUNG_COSMETIC = 263381,    
    //Adds
    SPELL_MASSIVE_SMASH = 267412,
    EVENT_MASSIVE_SMASH = 1,
    EVENT_DARK_BARGAIN,
    SPELL_DARK_BARGAIN = 273405,
    SPELL_MIND_NUMBED_CHATTER = 263307,
    SPELL_UNSTOPABBLE_CORRUPTION = 275204,
    SPELL_DARK_PURPOSE = 267816,
    SPELL_BLOOD_HOST = 267813,
    SPELL_BLOOD_HOST_MISSILE = 268099,
    //Heroic
    SPELL_DECAYING_ERUPTION = 267462,
    SPELL_BURROW_TELEPORT = 267579,
    //Mythic
    SPELL_MATRIX_SURGE = 274534,
    SPELL_BURSTING_BOIL_SUMMON = 277071,
    SPELL_BURSTING_BOIL_AURA = 277007,
    SPELL_BURSTING_BOIL_AURA_DAMAGE = 277092,
};

enum Texts
{
    SAY_AGGRO = 0,
    SAY_AGGRO_WHISPER,
    SAY_DARK_YOUNG,
    SAY_THOUSAND_MAWS,
    SAY_THOUSAND_MAWS_WHISPER,
    SAY_EMERGE = 6,
    SAY_EMERGE_WHISPER,
    SAY_BLOOD_FEAST_WHISPER,
    SAY_COLLAPSE,
    SAY_COLLAPSE_WHISPER,
    SAY_GAZE_OF_GHUUN,
    SAY_GAZE_OF_GHUUN_WHISPER,
    SAY_KILL,
    SAY_KILL_WHISPER,
    SAY_DEATH,
    SAY_DEATH_WHISPER
};

enum Events
{
    EVENT_EXPLOSIVE_CORRUPTION = 1,
    EVENT_THOUSAND_MAWS,
    EVENT_POWER_MATRIX,
    EVENT_BLIGHTSPREADER_TENDRIL,
    EVENT_WAVE_OF_CORRUPTION,
    EVENT_MALIGNANT_GROWTH,
    EVENT_GAZE,
    EVENT_TORMENT,
    EVENT_DRAIN_ENERGY,
    EVENT_DECAYING_ERUPTION,
    EVENT_MIND_NUMBED_CHATTER,
    EVENT_CORRUPTING_BITE,
    EVENT_BURSTING_BOIL,
};

enum Actions
{
    ACTION_POWER_MATRIX,
    ACTION_INIT_REORIGINATION_BLAST,
    ACTION_INIT_PHASE_TWO
};

enum Misc
{
    ACHIEVEMENT_MYTHIC_GHUUN = 12533,
    ACHIEVEMENT_HEART_OF_CORRUPTION = 12523,
};

const Position middle_pos = { 503.035f, -255.701f, 459.482f, 6.26f };

void AddSC_boss_ghuun()
{
    
}