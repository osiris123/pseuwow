#include <vector>
#include <fstream>
#include "common.h"
#include "PseuWoW.h"
#include "Opcodes.h"
#include "SharedDefines.h"
#include "Player.h"
#include "NameTables.h"
#include "DefScript/DefScript.h"
#include "WorldSession.h"


Player::Player() : Unit()
{
    _type = TYPE_PLAYER;
    _typeid = TYPEID_PLAYER;
    _valuescount = PLAYER_END;
}

void Player::Create(uint64 guid)
{
    Object::Create(guid);
}

MyCharacter::MyCharacter() : Player()
{
    SetTarget(0);
}

void MyCharacter::SetActionButtons(WorldPacket &data)
{

}

void MyCharacter::AddSpell(uint16 spellid, uint16 spellslot)
{
	SpellBookEntry _spell;
	_spell.id = spellid;
	_spell.slot = spellslot;

	_spells.push_back(_spell);
}

uint16 MyCharacter::GetSpellSlot(uint32 spellid)
{
    for(std::vector<SpellBookEntry>::iterator i=_spells.begin(); i != _spells.end(); i++)
        if(i->id == spellid)
            return i->slot;
    return 0;
}

    