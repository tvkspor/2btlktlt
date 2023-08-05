#include "knight2.h"


int prime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int checkPtg(int n) {
    int a = n / 100;
    int b = n % 100 / 10;
    int c = n % 10;
    if ((a * a + b * b == c * c || b * b + c * c == a * a || a * a + c * c == b * b) && (a!=0 && b!=0 && c!=0)) return 1;
    else return 0;
}
/* * * BEGIN implementation of class BaseBag * * */
int BaseBag::sizeofbag(BaseItem* a) {
    a = head;
    int cnt = 0;
    while (a != NULL) {
        ++cnt;
        a = a->next;
    }
    return cnt;
}
string BaseBag::toString() const {
    BaseItem* item = head;
    if (item == NULL) return "Bag[count=0;]";
    int c = 0;
    string listitem;
    while (item != NULL) {
        switch (item->item) {
        case 0:
            listitem += "Antidote,";
            break;
        case 1:
            listitem += "PhoenixI,";
            break;
        case 2:
            listitem += "PhoenixII,";
            break;
        case 3:
            listitem += "PhoenixIII,";
            break;
        case 4:
            listitem += "PhoenixIV,";
            break;
        }
        ++c;
        item = item->next;
    }

    listitem.erase(listitem.size() - 1);
    string d = to_string(c);
    string a = "Bag[count=" + d + ";" + listitem + "]";
    return a;
}
BaseItem* BaseBag::get(ItemType itemType) {
    BaseItem* k = head;
    while (k != NULL) {
        if (k->item == itemType) {
            return k;
        }
        else k = k->next;
    }
    return NULL;
}
void BaseBag::insert(BaseItem* item) {
    if (item->item == 2) {
        PhoenixDownII* p = new PhoenixDownII();
        p->next = head;
        head = p;
    }
    else if (item->item == 3) {
        PhoenixDownIII* p = new PhoenixDownIII();
        p->next = head;
        head = p;
    }
    else {
        PhoenixDownIV* p = new PhoenixDownIV();
        p->next = head;
        head = p;
    }
}

bool PaladinBag::insertFirst(BaseItem* item) {
    return true;
}
PaladinBag::PaladinBag(int a, int b) {
    for (int i = 0; i < a; i++) {
        PhoenixDownI* p = new PhoenixDownI();
        p->next = head;
        head = p;
    }
    for (int i = 0; i < b; i++) {
        Antidote* p = new Antidote();
        p->next = head;
        head = p;
    }
}

bool LancelotBag::insertFirst(BaseItem* item) {
    if (sizeofbag(head) >= 16) return false;
    return true;
}
LancelotBag::LancelotBag(int a, int b) {
    for (int i = 0; i < a; i++) {
        PhoenixDownI* p = new PhoenixDownI();
        p->next = head;
        head = p;
    }
    for (int i = 0; i < b; i++) {
        Antidote* p = new Antidote();
        p->next = head;
        head = p;
    }
}

bool DragonBag::insertFirst(BaseItem* item) {
    if (sizeofbag(head) >= 14 || item->item == antidote) return false;
    return true;
}
DragonBag::DragonBag(int a) {
    for (int i = 0; i < a; i++) {
        PhoenixDownI* p = new PhoenixDownI();
        p->next = head;
        head = p;
    }
}

bool NormalBag::insertFirst(BaseItem* item) {
    if (sizeofbag(head) >= 19) return false;
    return true;
}
NormalBag::NormalBag(int a, int b) {
    for (int i = 0; i < a; i++) {
        PhoenixDownI* p = new PhoenixDownI();
        p->next = head;
        head = p;
    }
    for (int i = 0; i < b; i++) {
        Antidote* p = new Antidote();
        p->next = head;
        head = p;
    }
}
/* * * END implementation of class BaseBag * * */
/* * * BEGIN implementation of class BaseOpponent * * */

MadBear::MadBear(int sttevent) {
    typeopponent = 1;
    idevent = sttevent;
    level0 = (typeopponent + idevent) % 10 + 1;
}
Bandit::Bandit(int sttevent) {
    typeopponent = 2;
    idevent = sttevent;
    level0 = (typeopponent + idevent) % 10 + 1;
}
LordLupin::LordLupin(int sttevent) {
    typeopponent = 3;
    idevent = sttevent;
    level0 = (typeopponent + idevent) % 10 + 1;
}
Elf::Elf(int sttevent) {
    typeopponent = 4;
    idevent = sttevent;
    level0 = (typeopponent + idevent) % 10 + 1;
}
Troll::Troll(int sttevent) {
    typeopponent = 5;
    idevent = sttevent;
    level0 = (typeopponent + idevent) % 10 + 1;
}
Tornbery::Tornbery(int sttevent) {
    typeopponent = 6;
    idevent = sttevent;
    level0 = (typeopponent + idevent) % 10 + 1;
}
Queenofcard::Queenofcard(int sttevent) {
    typeopponent = 7;
    idevent = sttevent;
    level0 = (typeopponent + idevent) % 10 + 1;
}
Nina::Nina() {
    typeopponent = 8;
}
Duriangarden::Duriangarden() {
    typeopponent = 9;
}
Omegaweapon::Omegaweapon() {
    typeopponent = 10;
}
Hades::Hades() {
    typeopponent = 11;
}
/* * * END implementation of class BaseOpponent* * */

/* * * BEGIN implementation of class BaseItem * * */
Antidote::Antidote() {
    item = antidote;
    next = NULL;
}
PhoenixDownI::PhoenixDownI() {
    item = phoenixDown1;
    next = NULL;
}
PhoenixDownII::PhoenixDownII() {
    item = phoenixDown2;
    next = NULL;
}
PhoenixDownIII::PhoenixDownIII() {
    item = phoenixDown3;
    next = NULL;
}
PhoenixDownIV::PhoenixDownIV() {
    item = phoenixDown4;
    next = NULL;
}


bool Antidote::canUse(BaseKnight* knight) {
    if (knight->getpoisoned() == 1)  return true;
    else return false;
}
void Antidote::use(BaseKnight* knight) {
    knight->setpoisoned(0);
}
bool PhoenixDownI::canUse(BaseKnight* knight) {
    if (knight->gethp() <= 0) {
         return true;
    }
    else return false;
}
void PhoenixDownI::use(BaseKnight* knight) {
    knight->sethp(knight->getmaxhp());
}
bool PhoenixDownII::canUse(BaseKnight* knight) {
    if (knight->gethp() < knight->getmaxhp() / 4) {
        return true;
    }
    else return false;
}
void PhoenixDownII::use(BaseKnight* knight) {
    knight->sethp(knight->getmaxhp());
}
bool PhoenixDownIII::canUse(BaseKnight* knight) {
    if (knight->gethp() < knight->getmaxhp() / 3) return true;
    else return false;
}
void PhoenixDownIII::use(BaseKnight* knight) {
    if (knight->gethp() <= 0)  knight->sethp(knight->getmaxhp() / 3);
    else  knight->sethp(knight->gethp() + knight->getmaxhp() / 4);
}
bool PhoenixDownIV::canUse(BaseKnight* knight) {
    if (knight->gethp() < knight->getmaxhp() / 2) {
          return true;
    }
    else return false;
}
void PhoenixDownIV::use(BaseKnight* knight) {
    if (knight->gethp() <= 0)  knight->sethp(knight->getmaxhp() / 2);
    else  knight->sethp(knight->gethp() + knight->getmaxhp() / 5); 
}
/* * * END implementation of class BaseItem * * */

/* * * BEGIN implementation of class BaseKnight * * */
string BaseKnight::toString() const {
    string typeString[4] = { "PALADIN", "LANCELOT", "DRAGON", "NORMAL" };
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id)
        + ",hp:" + to_string(hp)
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}
BaseKnight::BaseKnight() {
    id = 0;
    hp = 0;
    maxhp = 0;
    level = 0;
    gil = 0;
    antidote = 0;
    bag = NULL;
    phoenixdownI = 0;
    poisoned = 0;
}
static BaseKnight* create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) {
    BaseKnight* newKnight = new BaseKnight();
    newKnight->setid(id);
    newKnight->sethp(maxhp);
    newKnight->setmaxhp(maxhp);
    newKnight->setlevel(level);
    newKnight->setgil(gil);
    newKnight->setantidote(antidote);
    newKnight->setphoenixdownI(phoenixdownI);
    if (prime(maxhp) == 1) {
        newKnight->setknighttype(PALADIN);
        PaladinBag* k = new PaladinBag(phoenixdownI, antidote);
        newKnight->setbag(k);
    }
    else if (maxhp == 888) {
        newKnight->setknighttype(LANCELOT);
        LancelotBag* k = new LancelotBag(phoenixdownI, antidote);
        newKnight->setbag(k);
    }
    else if (checkPtg(maxhp) == 1) {
        newKnight->setknighttype(DRAGON);
        DragonBag* k = new DragonBag(phoenixdownI);
        newKnight->setbag(k);
    }
    else {
        newKnight->setknighttype(NORMAL);
        NormalBag* k = new NormalBag(phoenixdownI, antidote);
        newKnight->setbag(k);
    }
    return newKnight;
}
int BaseKnight::getid() {
    return id;
}
void BaseKnight::setid(int id) {
    this->id = id;
}
int BaseKnight::gethp() {
    return hp;
}
void BaseKnight::sethp(int hp) {
    this->hp = hp;
}
int BaseKnight::getmaxhp() {
    return maxhp;
}
void BaseKnight::setmaxhp(int maxhp) {
    this->maxhp = maxhp;
}
int BaseKnight::getlevel() {
    return level;
}
void BaseKnight::setlevel(int level) {
    this->level = level;
}
int BaseKnight::getgil() {
    return gil;
}
void BaseKnight::setgil(int gil) {
    this->gil = gil;
}
int BaseKnight::getantidote() {
    return antidote;
}
void BaseKnight::setantidote(int antidote) {
    this->antidote = antidote;
}
int BaseKnight::getphoenixdownI() {
    return phoenixdownI;
}
void BaseKnight::setphoenixdownI(int phoenixdownI) {
    this->phoenixdownI = phoenixdownI;
}
BaseBag* BaseKnight::getbag() {
    return bag;
}
void BaseKnight::setbag(BaseBag* bag) {
    this->bag = bag;
}
int BaseKnight::getknighttype() {
    return knightType;
}
void BaseKnight::setknighttype(KnightType knightType) {
    this->knightType = knightType;
}
void BaseKnight::setpoisoned(int poisoned) {
    this->poisoned = poisoned;
}
int BaseKnight::getpoisoned() {
    return poisoned;
}
/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight* lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}
void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}
ArmyKnights::ArmyKnights(const string& file_armyknights) {
    meetomega = 0;
    meethades = 0;
    hasshield = 0;
    hashair = 0;
    hasspear = 0;
    hassword = 0;
    ifstream f(file_armyknights);
    f >> countk;
    if (countk <= 0) baseknight = NULL;
    else {
        baseknight = new BaseKnight[countk];
        for (int i = 0; i < countk; i++)
        {
            // getline(f, line);
            int id;
            int maxhp;
            int level;
            int gil;
            int antidote;
            int phoenixdownI;
            // string* m = new string[100];
            // int n = 0;
            // stringstream s(line);
            // string tmp;
            // while (getline(s, tmp, ' ')) {
            //     m[n] = tmp;
            //     n++;
            // }
            // id = i + 1;
            // maxhp = stoi(m[0]);
            // level = stoi(m[1]);
            // phoenixdownI = stoi(m[2]);
            // gil = stoi(m[3]);
            // antidote = stoi(m[4]);
            id = i + 1;
            f >> maxhp >> level >> phoenixdownI >> gil >> antidote;
            BaseKnight* a = create(id, maxhp, level, gil, antidote, phoenixdownI);
            baseknight[i] = *a;
        }
    }
    f.close();
}
ArmyKnights::~ArmyKnights() {
    delete[] baseknight;
}
int ArmyKnights::count() const {
    int a = 0;
    for (int i = 0; i <= countk - 1; i++) {
        if (baseknight[i].gethp() > 0) a++;
    }
    return a;
}
void ArmyKnights::check(BaseKnight* a) {
    BaseItem* k = a->getbag()->head;
    int xh = 0;
    int n = 0;
    if (a->getpoisoned() == 1) {
        while (k != NULL) {
            n++;
            if (k->item == 0) { xh++; k->use(a); break; }
            else k = k->next;
        }
    }
    else {
    while (k != NULL) {
        n++;
        if (k->canUse(a) == true) { xh++; k->use(a); break; }
        else k = k->next;
    }
    }
    if (xh == 1) {

        BaseItem* m;
        switch (a->getbag()->head->item) {
        case 0:
            m = new Antidote();
            break;
        case 1:
            m = new PhoenixDownI();
            break;
        case 2:
            m = new PhoenixDownII();
            break;
        case 3:
            m = new PhoenixDownIII();
            break;
        default:
            m = new PhoenixDownIV();
            break;
        }
        if (n == 1) {
            a->getbag()->head = a->getbag()->head->next;
        }
        else {
            BaseItem* d = a->getbag()->head;
            BaseItem* h = NULL;
            int t = 0;
            while (d != NULL && t < n - 1) {
                h = d;
                d = d->next;
                t++;
            }
            m->next = d->next;
            h->next = m;
            a->getbag()->head = a->getbag()->head->next;
        }
    }
    if (a->gethp() <= 0 && a->getgil() >= 100) {
        a->setgil(a->getgil() - 100);
        a->sethp(a->getmaxhp() / 2);
    }
    if (a->getlevel() > 10) a->setlevel(10);
    int b = count() - 1;
    int c = 0;
    if (baseknight[b].getgil() > 999)
    {
        c = baseknight[b].getgil() - 999;
        baseknight[b].setgil(999);
        while (c > 0 && b >= 0)
        {
            b--;
            int e = min(baseknight[b].getgil() + c, 999);
            c = baseknight[b].getgil() + c - 999;
            baseknight[b].setgil(e);
        }
    }
}

bool ArmyKnights::fight(BaseOpponent* opponent) {
    BaseKnight* a = lastKnight();
    if (opponent->typeopponent == 1 || opponent->typeopponent == 2 || opponent->typeopponent == 3 || opponent->typeopponent == 4 || opponent->typeopponent == 5) {
        if (a->getlevel() < opponent->level0 && (a->getknighttype() == DRAGON || a->getknighttype() == NORMAL)) {
            int c = 0;
            switch (opponent->typeopponent) {
            case 1:
                c = 10;
                break;
            case 2:
                c = 15;
                break;
            case 3:
                c = 45;
                break;
            case 4:
                c = 75;
                break;
            default:
                c = 95;
                break;
            }
            a->sethp(a->gethp() - c * (opponent->level0 - a->getlevel()));
        }
        else {
            int b = 0;
            switch (opponent->typeopponent) {
            case 1:
                b = 100;
                break;
            case 2:
                b = 150;
                break;
            case 3:
                b = 450;
                break;
            case 4:
                b = 750;
                break;
            default:
                b = 800;
                break;
            }
            a->setgil(a->getgil() + b);
        }
        check(a);
    }
    else if (opponent->typeopponent == 6) {
        if (opponent->level0 <= a->getlevel()) { a->setlevel(a->getlevel() + 1); if (a->getlevel() > 10) a->setlevel(10); }
        else if (a->getknighttype() != DRAGON) {
            a->setpoisoned(1);
            check(a);
            if (a->getpoisoned() == 1) {
                a->sethp(a->gethp() - 10);
                if (a->getbag()->sizeofbag(a->getbag()->head) <= 3)  a->getbag()->head = NULL;
                else {
                    for (int i = 3; i > 0; i--) {
                        a->getbag()->head = a->getbag()->head->next;
                    }
                }
                a->setpoisoned(0);
                check(a);
            }
        }
        
    }
    else if (opponent->typeopponent == 7) {
        if (opponent->level0 > a->getlevel()) { if (a->getknighttype() != PALADIN) a->setgil(a->getgil() / 2); }
        else {
            int b = count() - 1;
            int c = 0;
            if (baseknight[b].getgil() * 2 > 999) {
                c = baseknight[b].getgil() * 2 - 999;
                baseknight[b].setgil(999);
                while (c > 0 && b >= 0)
                {
                    b--;
                    int e = min(baseknight[b].getgil() + c, 999);
                    c = baseknight[b].getgil() + c - 999;
                    baseknight[b].setgil(e);
                }
            }
            else a->setgil(a->getgil() * 2);
        }
    }
    else if (opponent->typeopponent == 8) {
        if ((a->getgil() >= 50 || a->getknighttype() == PALADIN) && a->gethp() < a->getmaxhp() / 3) {
            if (a->getknighttype() != PALADIN) a->setgil(a->getgil() - 50);
                
        a->sethp(a->gethp() + a->getmaxhp() / 5);
        }
    }
    else if (opponent->typeopponent == 9) {
        a->sethp(a->getmaxhp());
    }
    else if (opponent->typeopponent == 10 && meetomega == 0) {
        if ((a->getlevel() == 10 && a->gethp() == a->getmaxhp()) || a->getknighttype() == DRAGON) {
            meetomega = 1;
            a->setlevel(10);
            a->setgil(999);
        }
        else a->sethp(0);
        check(a);
    }
    else if (opponent->typeopponent == 11 && meethades == 0) {
        if ((a->getlevel() == 10) || (a->getknighttype() == PALADIN && a->getlevel() >= 8)) {
            meethades = 1;
            hasshield = 1;
        }
        else a->sethp(0);
        check(a);
    }
    if (a->gethp() > 0) return true;
    else return false;
    
}
BaseKnight* ArmyKnights::lastKnight() const {
    int a = 0;
    for (int i = 0; i < countk; i++) {
        if (baseknight[i].gethp() > 0 && i > a) {
            a = i;
        }
    }
    if (a == 0) {
        if (baseknight[0].gethp() > 0) return &baseknight[0];
        else return NULL;
    }
    else return &baseknight[a];
}
bool ArmyKnights::adventure(Events* event) {
    bool win=1;
    for (int i = 1; i <= event->count(); i++) {
        BaseOpponent* b;
        if (event->ev[i] == 1) {
            b = new MadBear(i - 1); fight(b);
        }
        else if (event->ev[i] == 2) {
            b = new Bandit(i - 1); fight(b);
        }
        else if (event->ev[i] == 3) {
            b = new LordLupin(i - 1); fight(b);
        }
        else if (event->ev[i] == 4) {
            b = new Elf(i - 1); fight(b);
        }
        else if (event->ev[i] == 5) { 
            b = new Troll(i - 1); fight(b);
        }
        else if (event->ev[i] == 6) { 
            b = new Tornbery(i - 1); fight(b);
        }
        else if (event->ev[i] == 7) {
            b = new Queenofcard(i - 1); fight(b);
        }
        else if (event->ev[i] == 8) {
            b = new Nina(); fight(b);
        }
        else if (event->ev[i] == 9) {
            b = new Duriangarden(); fight(b) ;
        }
        else if (event->ev[i] == 10) {
            b = new Omegaweapon(); fight(b);
        }
        else if (event->ev[i] == 11) {
            b = new Hades(); fight(b);
        }
        else if (event->ev[i] == 95) hasshield = 1;
        else if (event->ev[i] == 96) hasspear = 1;
        else if (event->ev[i] == 97) hashair = 1;
        else if (event->ev[i] == 98) {
            if (hasshield == 1 && hasspear == 1 && hashair == 1) hassword = 1;
        }
        else if (event->ev[i] == 112) {
            BaseItem* a = new PhoenixDownII();
            int b = count() - 1;
            while (b >= 0) {
                if (baseknight[b].getbag()->insertFirst(a) == 0) b--; 
                else { baseknight[b].getbag()->insert(a); break; }
            }
        }
        else if (event->ev[i] == 113) {
            BaseItem* a = new PhoenixDownIII();
            int b = count() - 1;
            while (b >= 0) {
                if (baseknight[b].getbag()->insertFirst(a) == 0) b--;
                else {
                    baseknight[b].getbag()->insert(a); break;
                }
            }
        }
        else if (event->ev[i] == 114) {
            BaseItem* a = new PhoenixDownIV();
            int b = count() - 1;
            while (b >= 0) {
                if (baseknight[b].getbag()->insertFirst(a) == 0) b--;
                else {
                    baseknight[b].getbag()->insert(a); break;
                }
            }
        }
        else {
            if (hassword == 1) win = true;
            else if (hasshield == 1 && hasspear == 1 && hashair == 1) {
                double Ultimeciahp = 5000;
                for (int j = count(); j >= 0; j--) {
                    if (baseknight[j].getknighttype() == PALADIN) { Ultimeciahp -= 0.06 * baseknight[j].gethp() * baseknight[j].getlevel(); }
                    else if (baseknight[j].getknighttype() == LANCELOT) { Ultimeciahp -= 0.05 * baseknight[j].gethp() * baseknight[j].getlevel(); }
                    else if (baseknight[j].getknighttype() == DRAGON) { Ultimeciahp -= 0.075 * baseknight[j].gethp() * baseknight[j].getlevel(); }

                    if (Ultimeciahp > 0 && (baseknight[j].getknighttype() == PALADIN || baseknight[j].getknighttype() == LANCELOT || baseknight[j].getknighttype() == DRAGON)) baseknight[j].sethp(0);
                }
                if (Ultimeciahp < 0) { win = true; }
                else {
                    for (int i = 0; i < countk; i++) {
                        baseknight[i].sethp(0);
                    }
                    win = false;
                }
                
            }
            else {
                for (int i = 0; i < countk; i++) {
                    baseknight[i].sethp(0);
                }
                win = false;
            }
        }
        printInfo();
        if (count() == 0) { win = 0; break; }
    }
    printResult(win);
    if (win = 1) return true;
    else return false;
}


bool ArmyKnights::hasPaladinShield() const {
    if (hasshield == 0) return false;
    else return true;
}
bool ArmyKnights::hasGuinevereHair() const {
    if (hashair == 0) return false;
    else return true;
}
bool ArmyKnights::hasLancelotSpear() const {
    if (hasspear == 0) return false;
    else return true;
}
bool ArmyKnights::hasExcaliburSword() const {
    if (hassword == 0) return false;
    else return true;
}
/* * * END implementation of class ArmyKnights * * */


/* * * BEGIN implementation of class Events* * */
Events::Events(const string& file_events) {
    ifstream f(file_events);
    int x;
    int i = 0;
    ev = new int[1000];
    while (f >> x) {
        ev[i] = x;
        i++;
    }
    f.close();
}
Events::~Events() {
    delete[] ev;
}
int Events::count()const {
    return ev[0];
}
int Events::get(int i)const {
    return ev[i];
}

/* * * END implementation of class Events* * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}
KnightAdventure::~KnightAdventure() {
    armyKnights->~ArmyKnights();
    events->~Events();
}
void KnightAdventure::loadArmyKnights(const string& file_armyknights) {
    armyKnights = new ArmyKnights(file_armyknights);
}
void KnightAdventure::loadEvents(const string& file_events) {
    events = new Events(file_events);
}
void KnightAdventure::run() {
    armyKnights->adventure(events);
}
/* * * END implementation of class KnightAdventure * * */