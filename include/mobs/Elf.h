#pragma once

#include "NPC.h"
#include "Outlaw.h"
#include "Knight.h"

class Elf : public NPC {
  public:
    Elf(const int64_t, const int64_t);

    std::string get_type() override;

    void battle_cry() const override;

    bool accept(std::shared_ptr<NPC>) override;
    bool fight(Outlaw&) override;
    bool fight(Knight&) override;
    bool fight(Elf&) override;
};
