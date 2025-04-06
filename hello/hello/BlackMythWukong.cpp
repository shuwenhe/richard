#include <iostream>
#include <cstdlib>
#include <ctime>

// 输入验证函数
bool isValidInput() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "输入无效，请重新输入。" << std::endl;
        return false;
    }
    return true;
}

// 处理敌人攻击
void handleAttack(int& targetHp, int damage, const std::string& enemyName) {
    targetHp -= damage;
    if (targetHp < 0) targetHp = 0;
    std::cout << enemyName << "攻击，你失去 " << damage << " 生命值。" << std::endl;
}

// 广智形态战斗
void fightAsGuangzhi(int& enemyHp, int& playerHp, int& attackCount, int& mana, int& freezeCount) {
    int gzHp = 800;
    while (enemyHp > 0 && gzHp > 0) {
        std::cout << "敌人HP: " << enemyHp << ", 广智HP: " << gzHp << ", 法力: " << mana << std::endl;
        std::cout << "1.攻击 2.躲避 5.定身术: ";
        char choice;
        std::cin >> choice;
        if (!isValidInput()) continue;
        if (choice == '1') {
            int damage = ++attackCount % 3 ? 30 : 200;
            std::cout << "造成 " << damage << " 伤害。" << std::endl;
            enemyHp -= damage;
            if (enemyHp > 0 && !freezeCount) {
                int enemyDamage = rand() % 100 < 10 ? 80 : 30;
                std::cout << "敌人反击！输入 2 躲避: ";
                char dodge;
                std::cin >> dodge;
                if (dodge != '2' || rand() % 100 >= 60) handleAttack(gzHp, enemyDamage, "敌人");
            }
        } else if (choice == '5') {
            if (mana >= 50) {
                mana -= 50;
                freezeCount = 5;
                std::cout << "敌人被定身 5 回合。" << std::endl;
            } else std::cout << "法力不足。" << std::endl;
        }
        if (freezeCount > 0) freezeCount--;
    }
    if (gzHp <= 0) std::cout << "广智形态被击败，变回本体。" << std::endl;
}

// 处理玩家操作
void handlePlayerAction(int& enemyHp, int& playerHp, int& wineCount, int& mana, int& attackCount, int& freezeCount,
                        bool& canTransform, bool& hasTransformed, const std::string& enemyName,
                        int enemyDamage, int enemySkillChance, int enemySkillDamage, bool canDodge) {
    char choice;
    std::cout << "1.攻击 2.躲避 3.喝酒 4.变身 5.定身术: ";
    std::cin >> choice;
    if (!isValidInput()) return;
    if (choice == '1') {
        int damage = rand() % 100 < 10 ? 100 : 30;
        std::cout << (damage == 100 ? "暴击！" : "") << "造成 " << damage << " 伤害。" << std::endl;
        if (canDodge && rand() % 100 < 20) std::cout << enemyName << "闪避。" << std::endl;
        else enemyHp -= damage;
        if (enemyHp > 0 && !freezeCount) {
            int actualDamage = enemySkillChance > rand() % 100 ? enemySkillDamage : enemyDamage;
            std::cout << enemyName << "攻击！输入 2 躲避: ";
            char dodge;
            std::cin >> dodge;
            if (dodge != '2' || rand() % 100 >= 60) handleAttack(playerHp, actualDamage, enemyName);
        }
    } else if (choice == '3') {
        if (wineCount > 0) {
            playerHp = playerHp + 200 > playerHp ? playerHp + 200 : playerHp;
            wineCount--;
            std::cout << "回复 200 HP，剩 " << wineCount << " 瓶酒。" << std::endl;
        } else std::cout << "无酒。" << std::endl;
    } else if (choice == '4') {
        if (canTransform && !hasTransformed) {
            int tempEnemyHp = enemyHp;
            fightAsGuangzhi(tempEnemyHp, playerHp, attackCount, mana, freezeCount);
            enemyHp = tempEnemyHp;
            hasTransformed = true;
        } else std::cout << "无法变身。" << std::endl;
    } else if (choice == '5') {
        if (mana >= 50) {
            mana -= 50;
            freezeCount = 5;
            std::cout << enemyName << "被定身 5 回合。" << std::endl;
        } else std::cout << "法力不足。" << std::endl;
    }
}

// 通用战斗函数
void genericFight(int enemyHp, int enemyDamage, int enemySkillChance, int enemySkillDamage,
                  int& playerHp, int& wineCount, bool& canTransform, bool& hasDefeatedGuangzhi,
                  bool& hasTransformed, int& mana, const std::string& enemyName,
                  bool canDodge, int snakeCount, bool& hasDefeatedLingxuzi, int& baseHp, bool& hasDefeatedGuangmou) {
    int attackCount = 0, freezeCount = 0;
    while (1) {
        playerHp = baseHp;
        wineCount = 5;
        mana = 300;
        hasTransformed = false;
        snakeCount = 0;
        std::cout << "遭遇 " << enemyName << "，敌人HP: " << enemyHp << std::endl;
        std::cout << "是否战斗？(y/n): ";
        char fight;
        std::cin >> fight;
        if (!isValidInput() || fight != 'y') break;
        while (enemyHp > 0 && playerHp > 0) {
            std::cout << enemyName << "HP: " << enemyHp << ", 你HP: " << playerHp << ", 法力: " << mana << std::endl;
            handlePlayerAction(enemyHp, playerHp, wineCount, mana, attackCount, freezeCount,
                               canTransform, hasTransformed, enemyName,
                               enemyDamage, enemySkillChance, enemySkillDamage, canDodge);
            if (snakeCount-- == 0 && enemyName == "广谋") handleAttack(playerHp, 10, "广谋召唤的小蛇");
            if (freezeCount > 0) freezeCount--;
        }
        if (enemyHp <= 0) {
            std::cout << "击败 " << enemyName << "！";
            if (enemyName == "广智") {
                canTransform = hasDefeatedGuangzhi = true;
                std::cout << "获得变身能力。";
            } else if (enemyName == "灵虚子") {
                hasDefeatedLingxuzi = true;
                baseHp += 100;
                std::cout << "获得金丹一枚，基础生命值增加 100。";
                std::cout << "获得行者套，装备后增加 60 生命值。";
            } else if (enemyName == "广谋") {
                hasDefeatedGuangmou = true;
                std::cout << "解锁申猴选项。";
            }
            std::cout << std::endl;
            break;
        }
        std::cout << "被击败，再战？(y/n): ";
        char retry;
        std::cin >> retry;
        if (!isValidInput() || retry != 'y') break;
    }
}

// 白衣秀士战斗函数
void fightWithWhiteScholar(int& playerHp, int& wineCount, bool& canTransform, bool& hasDefeatedGuangzhi,
                           bool& hasTransformed, int& mana, bool& hasDefeatedLingxuzi, int& baseHp) {
    int enemyHpPhase1 = 2500;
    int enemyDamage = 50;
    int enemySkillChance = 20;
    int enemySkillDamage = 150;
    int attackCount = 0, freezeCount = 0;

    while (1) {
        playerHp = baseHp;
        wineCount = 5;
        mana = 300;
        hasTransformed = false;
        std::cout << "遭遇 白衣秀士，敌人HP: " << enemyHpPhase1 << std::endl;
        std::cout << "是否战斗？(y/n): ";
        char fight;
        std::cin >> fight;
        if (!isValidInput() || fight != 'y') break;

        // 一阶段战斗
        int currentEnemyHp = enemyHpPhase1;
        while (currentEnemyHp > 0 && playerHp > 0) {
            std::cout << "白衣秀士HP: " << currentEnemyHp << ", 你HP: " << playerHp << ", 法力: " << mana << std::endl;
            handlePlayerAction(currentEnemyHp, playerHp, wineCount, mana, attackCount, freezeCount,
                               canTransform, hasTransformed, "白衣秀士",
                               enemyDamage, enemySkillChance, enemySkillDamage, true);
            if (freezeCount > 0) freezeCount--;
        }

        if (currentEnemyHp <= 0) {
            std::cout << "击败 白衣秀士 一阶段！进入二阶段..." << std::endl;
            int enemyHpPhase2 = 2500;
            // 二阶段战斗
            while (enemyHpPhase2 > 0 && playerHp > 0) {
                std::cout << "白衣秀士HP: " << enemyHpPhase2 << ", 你HP: " << playerHp << ", 法力: " << mana << std::endl;
                enemyHpPhase2 += 5; // 每次玩家输入回5生命值
                handlePlayerAction(enemyHpPhase2, playerHp, wineCount, mana, attackCount, freezeCount,
                                   canTransform, hasTransformed, "白衣秀士",
                                   enemyDamage, enemySkillChance, enemySkillDamage, true);
                if (freezeCount > 0) freezeCount--;
            }
            if (enemyHpPhase2 <= 0) {
                std::cout << "击败 白衣秀士 二阶段！" << std::endl;
                break;
            }
        }

        std::cout << "被击败，再战？(y/n): ";
        char retry;
        std::cin >> retry;
        if (!isValidInput() || retry != 'y') break;
    }
}

// 土地庙整顿装备函数
void landTemple(int& baseHp, bool& hasDefeatedLingxuzi) {
    std::cout << "你来到了土地庙，当前基础生命值: " << baseHp << std::endl;
    std::cout << "你拥有的装备：虎皮裙（增加 30 HP）";
    if (hasDefeatedLingxuzi) std::cout << "，行者套（增加 60 HP）";
    std::cout << std::endl;
    std::cout << "是否更换装备？(y/n): ";
    char choice;
    std::cin >> choice;
    if (!isValidInput()) return;
    if (choice == 'y')
        baseHp = hasDefeatedLingxuzi ? 300 + 60 : 300 + 30;
    std::cout << "你穿上了" << (hasDefeatedLingxuzi ? "行者套" : "虎皮裙")
              << "，当前基础生命值变为: " << baseHp << std::endl;
}

// 申猴功能函数
void shenhouFunction(int& wineCount) {
    std::cout << "你选择了申猴，是否要升级酒增加一次喝的次数？(y/n): ";
    char choice;
    std::cin >> choice;
    if (!isValidInput()) return;
    if (choice == 'y') {
        wineCount++;
        std::cout << "酒的使用次数增加一次，当前酒的次数: " << wineCount << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int playerHp = 300, wineCount = 5, mana = 300;
    bool canTransform = false, hasDefeatedGuangzhi = false, hasTransformed = false;
    bool hasDefeatedLingxuzi = false;
    bool hasDefeatedGuangmou = false;
    int baseHp = 300 + 30;

    landTemple(baseHp, hasDefeatedLingxuzi);

    while (1) {
        std::cout << "\n=== 黑神话：悟空 ===" << std::endl;
        std::cout << "1.大头怪 2.广智 3.灵虚子 4.广谋 5.土地庙 6.白衣秀士 ";
        if (hasDefeatedGuangmou) {
            std::cout << "7.申猴 ";
        }
        std::cout << (hasDefeatedGuangmou ? "8" : "7") << ".退出: ";
        char choice;
        std::cin >> choice;
        if (!isValidInput()) continue;
        if (choice == '1')
            genericFight(3000, 50, 20, 200, playerHp, wineCount, canTransform, hasDefeatedGuangzhi,
                         hasTransformed, mana, "大头怪", true, 0, hasDefeatedLingxuzi, baseHp, hasDefeatedGuangmou);
        else if (choice == '2')
            genericFight(1500, 30, 10, 80, playerHp, wineCount, canTransform, hasDefeatedGuangzhi,
                         hasTransformed, mana, "广智", true, 0, hasDefeatedLingxuzi, baseHp, hasDefeatedGuangmou);
        else if (choice == '3')
            genericFight(3500, 35, 0, 150, playerHp, wineCount, canTransform, hasDefeatedGuangzhi,
                         hasTransformed, mana, "灵虚子", true, 0, hasDefeatedLingxuzi, baseHp, hasDefeatedGuangmou);
        else if (choice == '4')
            genericFight(1500, 35, 0, 0, playerHp, wineCount, canTransform, hasDefeatedGuangzhi,
                         hasTransformed, mana, "广谋", true, 5, hasDefeatedLingxuzi, baseHp, hasDefeatedGuangmou);
        else if (choice == '5')
            landTemple(baseHp, hasDefeatedLingxuzi);
        else if (choice == '6')
            fightWithWhiteScholar(playerHp, wineCount, canTransform, hasDefeatedGuangzhi,
                                  hasTransformed, mana, hasDefeatedLingxuzi, baseHp);
        else if ((hasDefeatedGuangmou && choice == '7') || (!hasDefeatedGuangmou && choice == '7'))
            return 0;
        else if (hasDefeatedGuangmou && choice == '7') {
            shenhouFunction(wineCount);
        }
        else
            std::cout << "无效选择。" << std::endl;
    }
}    
