#pragma once

#include "NPC.h"
#include "Outlaw.h"
#include "Elf.h"

class Knight : public NPC {
  public:
    Knight(const int64_t, const int64_t);

    std::string get_type() override;

    void battle_cry() const override;

    bool accept(std::shared_ptr<NPC>) override;
    bool fight(Outlaw&) override;
    bool fight(Knight&) override;
    bool fight(Elf&) override;
};

