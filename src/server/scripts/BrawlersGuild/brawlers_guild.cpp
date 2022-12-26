#include "AchievementMgr.h"
#include "BrawlersGuild.h"
#include "ScriptedGossip.h"
#include "Creature.h"

// 68408, 67267
class npc_brawlers_guild_queue : public CreatureScript
{
public:
    npc_brawlers_guild_queue() : CreatureScript("npc_brawlers_guild_queue") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player)
        {
             auto ok = true;

             if (player->GetTeamId() == TEAM_ALLIANCE && !player->HasAchieved(ACHIEVEMENT_FIRST_RULE_A))
                 ok = false;

             if (player->GetTeamId() == TEAM_HORDE && !player->HasAchieved(ACHIEVEMENT_FIRST_RULE_H))
                 ok = false;

            if (player->HasAchieved(ACHIEVEMENT_FIRST_RULE_H) || player->HasAchieved(ACHIEVEMENT_FIRST_RULE_A))
            {
                AddGossipItemFor(player, 15284, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                AddGossipItemFor(player, 15284, 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            }

            player->PlayerTalkClass->SendGossipMenu(player->GetGossipTextId(creature), creature->GetGUID());
        }

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action)
    {
        if (player)
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
               if (BrawlersGuild* brawlerGuild = player->GetBrawlerGuild())
                   brawlerGuild->AddPlayer(player);
                CloseGossipMenuFor(player);
            }
        }

        return true;
    }

    struct npc_brawlers_guild_queueAI : ScriptedAI
    {
        npc_brawlers_guild_queueAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        { }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (!UpdateVictim())
                return;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_brawlers_guild_queueAI(creature);
    }
};

// 93228, 93195, 93194, 144363
class brawl_invitation_item : public ItemScript
{
public:
    brawl_invitation_item() : ItemScript("brawl_invitation_item") { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        if (!player || !item)
            return false;

        if (player->HasAchieved(ACHIEVEMENT_FIRST_RULE_A) || player->HasAchieved(ACHIEVEMENT_FIRST_RULE_H))
            return false;

        if (player->GetTeamId() == TEAM_ALLIANCE)
        {
            if (auto achievementEntry = sAchievementStore.LookupEntry(ACHIEVEMENT_FIRST_RULE_A))
                player->CompletedAchievement(achievementEntry);

            player->CastSpell(player, SPELL_ALLIANCE_SOUND, true);
        }
        else
        {
            if (auto achievementEntry = sAchievementStore.LookupEntry(ACHIEVEMENT_FIRST_RULE_H))
                player->CompletedAchievement(achievementEntry);

            player->CastSpell(player, SPELL_HORDE_SOUND, true);

            player->DestroyItem(player->GetEntry(), 1, true);
        }
        return true;
    }
};

void AddSC_the_brawlers_guild()
{
    new npc_brawlers_guild_queue();
    new brawl_invitation_item();
}
