#pragma once

#include "NPC.h"
#include "Knight.h"
#include "Elf.h"

class Outlaw : public NPC {
  public:
    Outlaw(const int64_t, const int64_t);

    std::string get_type() override;

    void battle_cry() const override;

    bool accept(std::shared_ptr<NPC>) override;
    bool fight(Outlaw&) override;
    bool fight(Knight&) override;
    bool fight(Elf&) override;
};
