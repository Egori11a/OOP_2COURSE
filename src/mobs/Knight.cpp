#include "../../include/mobs/Knight.h"

Knight::Knight(const int64_t __x, const int64_t __y) : 
    NPC(NPCType::Knight, "Knight_" + std::to_string(id++), __x, __y) 
{
}

std::string Knight::get_type() 
{
    return "Knight";
}

void Knight::battle_cry() const
{
    std::cout << "lok'tar Ogar!!!" << std::endl;
}

bool Knight::accept(std::shared_ptr<NPC> visitor) 
{
    if (visitor->fight(*this)) {
        this->_alive = false;
        return true;
    }

    return false;
}

bool Knight::fight(Outlaw& accepter) 
{
    notify_killed(accepter);
    return true;
}

bool Knight::fight(Knight& accepter) 
{
    return false;
}

bool Knight::fight(Elf& accepter) 
{
    return false;
}