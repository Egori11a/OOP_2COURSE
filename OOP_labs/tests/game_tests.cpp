#include <gtest/gtest.h>
#include "../include/factory/NPCFactory.h"
#include "../include/fight/fight.h"
#include "bits/stdc++.h"


TEST(NPCFactoryTest, Create_NPC) {
    NPCFactory factory;
    bool test = true;
    try {
        std::shared_ptr<NPC> Knight = factory.create_NPC(NPCType::Knight, 1, 2);
        std::shared_ptr<NPC> Outlaw = factory.create_NPC(NPCType::Outlaw, 3, 4);
        std::shared_ptr<NPC> Elf = factory.create_NPC(NPCType::Elf, 5, 6);
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCFactoryTest, Save) {
    NPCFactory factory;
    set_t s;
    bool test = true;
    try {
        s.insert(factory.create_NPC(NPCType::Knight, 1, 2));
        s.insert(factory.create_NPC(NPCType::Outlaw, 3, 4));
        s.insert(factory.create_NPC(NPCType::Elf, 5, 6));
        factory.save(s, "test.txt");
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCFactoryTest, Load) {
    NPCFactory factory;
    set_t s;
    bool test = true;
    try {
        s = factory.load("test.txt");
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCTest, OutputOperator) {
    std::shared_ptr<NPC> npc = std::make_shared<Knight>(1, 2);
    std::stringstream expected_output;
    expected_output << "Knight_9 {x : 1, y : 2}";

    std::stringstream actual_output;
    actual_output << *npc.get();

    EXPECT_EQ(expected_output.str(), actual_output.str());
}

TEST(NPCTest, Getters) {
    NPCFactory factory;
    std::shared_ptr<NPC> Knight = factory.create_NPC(NPCType::Knight, 1, 2);
    std::shared_ptr<NPC> Outlaw = factory.create_NPC(NPCType::Outlaw, 3, 4);
    std::shared_ptr<NPC> Elf = factory.create_NPC(NPCType::Elf, 5, 6);

    EXPECT_EQ(Knight->get_type(), "Knight");
    EXPECT_EQ(Outlaw->get_type(), "Outlaw");
    EXPECT_EQ(Elf->get_type(), "Elf");

    EXPECT_TRUE(Knight->is_alive());
    EXPECT_TRUE(Outlaw->is_alive());
    EXPECT_TRUE(Elf->is_alive());

    EXPECT_EQ(Knight->get_x(), 1);
    EXPECT_EQ(Outlaw->get_x(), 3);
    EXPECT_EQ(Elf->get_x(), 5);
    EXPECT_EQ(Knight->get_y(), 2);
    EXPECT_EQ(Outlaw->get_y(), 4);
    EXPECT_EQ(Elf->get_y(), 6);
}

TEST(NPCTest, Near) {
    NPCFactory factory;
    std::shared_ptr<NPC> Knight = factory.create_NPC(NPCType::Knight, 1, 1);
    std::shared_ptr<NPC> Outlaw = factory.create_NPC(NPCType::Outlaw, 50, 1);
    std::shared_ptr<NPC> Elf = factory.create_NPC(NPCType::Elf, 100, 1);

    EXPECT_FALSE(Knight->near(Outlaw, 10));
    EXPECT_TRUE(Knight->near(Outlaw, 60));
    EXPECT_FALSE(Knight->near(Elf, 90));
    EXPECT_TRUE(Knight->near(Elf, 110));
}

TEST(NPCTest, Attach) {
    NPCFactory factory;
    std::shared_ptr<NPC> Knight = factory.create_NPC(NPCType::Knight, 1, 1);
    std::shared_ptr<observers::IObserver> console_observer, file_observer;
    console_observer = std::make_shared<observers::ConsoleObserver>();
    file_observer = std::make_shared<observers::LogObserver>();
    bool test = true;
    try {
        Knight->attach(console_observer);
        Knight->attach(file_observer);
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(KnightTest, ConstructorAndGetters) {
    Knight Knight(1, 2);
    EXPECT_EQ(Knight.get_x(), 1);
    EXPECT_EQ(Knight.get_y(), 2);
    EXPECT_TRUE(Knight.is_alive());
    EXPECT_EQ(Knight.get_type(), "Knight");
}

TEST(KnightTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> Knight = factory.create_NPC(NPCType::Knight, 1, 2);
    std::shared_ptr<NPC> Elf = factory.create_NPC(NPCType::Elf, 5, 6);

    EXPECT_FALSE(Knight->accept(Knight));
    EXPECT_TRUE(Knight->accept(Elf));
    EXPECT_TRUE(Knight->is_alive());
}

TEST(OutlawTest, ConstructorAndGetters) {
    Outlaw Outlaw(1, 2);
    EXPECT_EQ(Outlaw.get_x(), 1);
    EXPECT_EQ(Outlaw.get_y(), 2);
    EXPECT_TRUE(Outlaw.is_alive());
    EXPECT_EQ(Outlaw.get_type(), "Outlaw");
}

TEST(OutlawTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> Outlaw = factory.create_NPC(NPCType::Outlaw, 3, 4);
    std::shared_ptr<NPC> Elf = factory.create_NPC(NPCType::Elf, 5, 6);

    EXPECT_FALSE(Outlaw->accept(Outlaw));
    EXPECT_FALSE(Outlaw->accept(Elf));
    EXPECT_TRUE(Outlaw->is_alive());
}

TEST(ElfTest, ConstructorAndGetters) {
    Elf Elf(1, 2);
    EXPECT_EQ(Elf.get_x(), 1);
    EXPECT_EQ(Elf.get_y(), 2);
    EXPECT_TRUE(Elf.is_alive());
    EXPECT_EQ(Elf.get_type(), "Elf");
}

TEST(ElfTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> Knight = factory.create_NPC(NPCType::Knight, 1, 2);
    std::shared_ptr<NPC> Elf = factory.create_NPC(NPCType::Elf, 5, 6);

    EXPECT_FALSE(Elf->accept(Knight));
    EXPECT_TRUE(Elf->is_alive());
    remove("battle_stats.txt");
    remove("test.txt");
}

TEST(FightManagerTest, GetReturnsSingletonInstance) {
    FightManager& instance1 = FightManager::get();
    FightManager& instance2 = FightManager::get();

    EXPECT_EQ(&instance1, &instance2);
}

TEST(FightManagerTest, AddEventAddsEventToQueue) {
    FightManager& manager = FightManager::get();
    FightEvent event;

    bool test = true;
    try {
        manager.add_event(std::move(event));
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}