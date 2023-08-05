#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG
class BaseKnight;
class BaseItem;
enum ItemType { antidote = 0, phoenixDown1, phoenixDown2, phoenixDown3, phoenixDown4 };
class BaseBag {
public:
    BaseItem* head = NULL;
    virtual bool insertFirst(BaseItem* item) = 0;
    virtual BaseItem* get(ItemType itemType);
    virtual string toString() const;
    virtual int sizeofbag(BaseItem* a);
    void insert(BaseItem* item);
};
class PaladinBag : public BaseBag {
public:
    PaladinBag(int a, int b);
    bool insertFirst(BaseItem* item);
};
class LancelotBag :public BaseBag {
public:
    LancelotBag(int a, int b);
    bool insertFirst(BaseItem* item);
};
class DragonBag :public BaseBag {
public:
    DragonBag(int a);
    bool insertFirst(BaseItem* item);
};
class NormalBag :public BaseBag {
public:
    NormalBag(int a, int b);
    bool insertFirst(BaseItem* item);
};


class BaseOpponent {
public:
    int typeopponent;
    int idevent;
    int level0;
};
class MadBear : public BaseOpponent {
public:
    MadBear(int sttevent);
};
class Bandit : public BaseOpponent {
public:
    Bandit(int sttevent);
};
class LordLupin : public BaseOpponent {
public:
    LordLupin(int sttevent);
};
class Elf : public BaseOpponent {
public:
    Elf(int sttevent);
};
class Troll : public BaseOpponent {
public:
    Troll(int sttevent);
};
class Tornbery : public BaseOpponent {
public:
    Tornbery(int sttevent);
};
class Queenofcard : public BaseOpponent {
public:
    Queenofcard(int sttevent);
};
class Nina : public BaseOpponent {
public:
    Nina();
};
class Duriangarden : public BaseOpponent {
public:
    Duriangarden();
};
class Omegaweapon : public BaseOpponent {
public:
    Omegaweapon();
};
class Hades : public BaseOpponent {
public:
    Hades();
};


enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };
class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil ;
    int antidote;
    int phoenixdownI;
    BaseBag* bag;
    KnightType knightType;
    int poisoned ;

public:
    BaseKnight();
    static BaseKnight* create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
    int getid();
    void setid(int hp);
    int gethp();
    void sethp(int maxhp);
    int getmaxhp();
    void setmaxhp(int maxhp);
    int getlevel();
    void setlevel(int level);
    int getgil();
    void setgil(int gil);
    int getantidote();
    void setantidote(int antidote);
    int getphoenixdownI();
    void setphoenixdownI(int phoenixdownI);
    BaseBag* getbag();
    void setbag(BaseBag* bag);
    int getknighttype();
    void setknighttype(KnightType knightType);
    void setpoisoned(int poisoned);
    int getpoisoned();

};
//class PaladinKnight : public BaseKnight {
//
//};
//class LancelotKnight : public BaseKnight {
//
//};
//class NormalKnight : public BaseKnight {
//
//};
class Events;
class ArmyKnights {
public:

    BaseKnight* baseknight;
    int countk;
    int meetomega;
    int meethades;
    int hasshield;
    int hasspear;
    int hashair;
    int hassword;
    ArmyKnights(const string& file_armyknights);
    ~ArmyKnights();
    void check(BaseKnight* a);
    bool fight(BaseOpponent* opponent);
    bool adventure(Events* events);
    int count() const;
    
    BaseKnight* lastKnight() const;

    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;

    void printInfo() const;
    void printResult(bool win) const;
};

class BaseItem {
public:
    ItemType item;
    BaseItem* next;
    virtual bool canUse(BaseKnight* knight) = 0;
    virtual void use(BaseKnight* knight) = 0;
};
class Antidote : public BaseItem {
public:
    Antidote();
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};
class PhoenixDownI : public BaseItem {
public:
    PhoenixDownI();
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};
class PhoenixDownII : public BaseItem {
public:
    PhoenixDownII();
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};
class PhoenixDownIII : public BaseItem {
public:
    PhoenixDownIII();
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};
class PhoenixDownIV : public BaseItem {
public:
    PhoenixDownIV();
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};


class Events {
public:
    int* ev;
    Events(const string& file_events);
    ~Events();
    int count() const;
    int get(int i) const;
};

class KnightAdventure {
private:
    ArmyKnights* armyKnights;
    Events* events;

public:
    KnightAdventure();
    ~KnightAdventure(); // TODO:

    void loadArmyKnights(const string& file_armyknights);
    Events* getEvents() { return events; }
    ArmyKnights* getArmy() { return armyKnights; }
    void loadEvents(const string& file_events);
    void run();
};

#endif // __KNIGHT2_H__