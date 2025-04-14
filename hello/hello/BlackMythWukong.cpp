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
void fightAsGuangzhi(int& enemyHp, int& playerHp, int& attackCount, int& mana, int& freezeCount, int& stickStyle, int& qiStrength) {
    int gzHp = 800;
    while (enemyHp > 0 && gzHp > 0) {
        std::cout << "敌人HP: " << enemyHp << ", 广智HP: " << gzHp << ", 法力: " << mana << ", 棍式: " << stickStyle << ", 气力: " << qiStrength << std::endl;
        std::cout << "1.攻击 2.躲避: ";
        char choice;
        if (!(std::cin >> choice) ||!isValidInput()) continue;
        if (choice == '1') {
            int damage = ++attackCount % 3? 30 : 200;
            std::cout << "造成 " << damage << " 伤害。" << std::endl;
            enemyHp -= damage;
            stickStyle += 20;
            qiStrength = std::min(qiStrength + 10, 300);
            if (enemyHp > 0 &&!freezeCount) {
                int enemyDamage = rand() % 100 < 10? 80 : 30;
                std::cout << "敌人反击！输入 2 躲避: ";
                char dodge;
                if (!(std::cin >> dodge) ||!isValidInput()) continue;
                if (dodge != '2' || rand() % 100 >= 60) handleAttack(gzHp, enemyDamage, "敌人");
            }
        } else if (choice == '2') {
            if (qiStrength >= 10) {
                qiStrength -= 10;
                std::cout << "闪避成功，消耗 10 气力，当前气力: " << qiStrength << std::endl;
            } else {
                std::cout << "气力不足，无法闪避。" << std::endl;
            }
            if (enemyHp > 0 &&!freezeCount) {
                int enemyDamage = rand() % 100 < 10? 80 : 30;
                std::cout << "敌人反击！输入 2 躲避: ";
                char dodge;
                if (!(std::cin >> dodge) ||!isValidInput()) continue;
                if (dodge != '2' || rand() % 100 >= 60) handleAttack(gzHp, enemyDamage, "敌人");
            }
        }
        if (freezeCount > 0) freezeCount--;
    }
    if (gzHp <= 0) std::cout << "广智形态被击败，变回本体。" << std::endl;
}

// 获取棍式阶段
int getStickStylePhase(int stickStyle) {
    return std::min(stickStyle / 100, 4);
}

// 获取技能伤害
int getSkillDamage(int phase, char skill) {
    if (skill == '9') {
        switch (phase) {
            case 1: return 200;
            case 2: return 250;
            case 3: return 300;
            case 4: return 350;
            default: return 0;
        }
    }
    return 0;
}

// 处理玩家操作
void handlePlayerAction(int& enemyHp, int& playerHp, int& wineCount, int& mana, int& attackCount, int& freezeCount,
                        bool& canTransform, bool& hasTransformed, const std::string& enemyName,
                        int enemyDamage, int enemySkillChance, int enemySkillDamage, bool canDodge,
                        int& blackWindCounter, int& blackWindPhase, int& maxDrinkCount,
                        int& currentSpirit, bool& hasBigHeadSpirit, bool& hasGuangmouSpirit, int& attackCounter,
                        bool& hasDefeatedBlackWindKing, int& invisibleCounter, bool& isInvisible, int& inputCount, int& stickStyle, int& qiStrength,
                        bool& isBlackBearInFlameForm) {
    if ((currentSpirit == 1 && hasBigHeadSpirit && attackCounter >= 30) || (currentSpirit == 2 && hasGuangmouSpirit && attackCounter >= 20)) {
        std::cout << "你现在可以使用精魂了！输入 6 使用。" << std::endl;
    }
    if (hasDefeatedBlackWindKing) {
        std::cout << "你已获得技能聚型散气，输入 7 使用（消耗法力 20）。" << std::endl;
    }
    std::cout << "当前棍式: " << stickStyle << ", 棍式阶段: " << getStickStylePhase(stickStyle) << ", 气力: " << qiStrength << std::endl;
    char choice;
    std::cout << "1.攻击 2.躲避 3.喝酒 4.变身 5.定身术 6.使用精魂 7.聚型散气 8.蓄力 9.重棍: ";
    if (!(std::cin >> choice) ||!isValidInput()) return;
    inputCount++;
    bool enemyAttacks = true;

    auto handleEnemyAttack = [&]() {
        if (enemyHp > 0 &&!freezeCount &&!isInvisible) {
            int actualDamage = enemySkillChance > rand() % 100? enemySkillDamage : enemyDamage;
            if (isBlackBearInFlameForm) {
                actualDamage += 20;
            }
            std::cout << enemyName << "攻击！输入 2 躲避: ";
            char dodge;
            if (!(std::cin >> dodge) ||!isValidInput()) return;
            if (dodge != '2' || rand() % 100 >= 60) handleAttack(playerHp, actualDamage, enemyName);
        }
    };

    switch (choice) {
        case '1':
            if (enemyName == "黑风大王" && blackWindPhase > 0) {
                std::cout << "黑风状态，攻击无效！" << std::endl;
                blackWindCounter++;
                if (blackWindCounter == 5) {
                    std::cout << "黑风大王释放大招！" << std::endl;
                    handleAttack(playerHp, 200, "黑风大王");
                    blackWindPhase = 0;
                    blackWindCounter = 0;
                } else {
                    handleAttack(playerHp, enemyDamage, enemyName);
                }
                enemyAttacks = false;
            } else {
                if (isInvisible) {
                    enemyHp -= 200;
                    std::cout << "你在隐身状态下攻击，对敌人造成 200 伤害，隐身解除。" << std::endl;
                    isInvisible = false;
                    invisibleCounter = 0;
                    inputCount = 0;
                } else {
                    int damage = rand() % 100 < 10? 100 : 30;
                    std::cout << (damage == 100? "暴击！" : "") << "造成 " << damage << " 伤害。" << std::endl;
                    if (canDodge &&!freezeCount && rand() % 100 < 20) std::cout << enemyName << "闪避。" << std::endl;
                    else enemyHp -= damage;
                }
                stickStyle += 20;
                attackCounter++;
                qiStrength = std::min(qiStrength + 10, 300);
            }
            break;
        case '2':
            if (qiStrength >= 10) {
                qiStrength -= 10;
                std::cout << "闪避成功，消耗 10 气力，当前气力: " << qiStrength << std::endl;
            } else {
                std::cout << "气力不足，无法闪避。" << std::endl;
            }
            break;
        case '3':
            if (wineCount > 0) {
                playerHp += 200;
                wineCount--;
                std::cout << "回复 200 HP，剩 " << wineCount << " 瓶酒。" << std::endl;
            } else std::cout << "无酒。" << std::endl;
            qiStrength = std::min(qiStrength + 10, 300);
            break;
        case '4':
            if (canTransform &&!hasTransformed) {
                int tempEnemyHp = enemyHp;
                fightAsGuangzhi(tempEnemyHp, playerHp, attackCount, mana, freezeCount, stickStyle, qiStrength);
                enemyHp = tempEnemyHp;
                hasTransformed = true;
            } else std::cout << "无法变身。" << std::endl;
            qiStrength = std::min(qiStrength + 10, 300);
            break;
        case '5':
            if (hasTransformed) {
                std::cout << "变身广智时不能用定身术。" << std::endl;
            } else if (mana >= 50) {
                mana -= 50;
                freezeCount = 5;
                std::cout << enemyName << "被定身 5 回合，期间不能躲避和攻击。" << std::endl;
            } else std::cout << "法力不足。" << std::endl;
            qiStrength = std::min(qiStrength + 10, 300);
            break;
        case '6':
            if ((currentSpirit == 1 && hasBigHeadSpirit && attackCounter >= 30) ||
                (currentSpirit == 2 && hasGuangmouSpirit && attackCounter >= 20)) {
                int damage = (currentSpirit == 1) ? 200 : 125;
                enemyHp -= damage;
                std::cout << "使用精魂，对敌人造成 " << damage << " 伤害。" << std::endl;
                attackCounter = 0;
            } else {
                std::cout << "无法使用精魂。" << std::endl;
            }
            qiStrength = std::min(qiStrength + 10, 300);
            break;
        case '7':
            if (hasDefeatedBlackWindKing && mana >= 20) {
                mana -= 20;
                isInvisible = true;
                invisibleCounter = 20;
                inputCount = 0;
                std::cout << "你使用了聚型散气技能，接下来 20 次输入（除攻击）怪物看不见你。" << std::endl;
            } else {
                std::cout << "无法使用聚型散气技能。" << std::endl;
            }
            qiStrength = std::min(qiStrength + 10, 300);
            enemyAttacks = false;
            break;
        case '8':
            if (qiStrength >= 20) {
                qiStrength -= 20;
                stickStyle += 30;
                std::cout << "蓄力，棍式增加 30，消耗 20 气力，当前棍式: " << stickStyle << ", 当前气力: " << qiStrength << std::endl;
            } else {
                std::cout << "气力不足，无法蓄力。" << std::endl;
            }
            break;
        case '9': {
            int phase = getStickStylePhase(stickStyle);
            int damage = getSkillDamage(phase, choice);
            enemyHp -= damage;
            std::cout << "重棍攻击，造成 " << damage << " 伤害。" << std::endl;
            stickStyle = 0;
            qiStrength = std::min(qiStrength + 10, 300);
            break;
        }
        default:
            std::cout << "无效选择。" << std::endl;
            enemyAttacks = false;
    }

    if (isInvisible) {
        invisibleCounter--;
        if (invisibleCounter <= 0 || inputCount >= 20) {
            isInvisible = false;
            invisibleCounter = 0;
            inputCount = 0;
            std::cout << "聚型散气技能效果结束，你现形了。" << std::endl;
        }
    }
    if (freezeCount > 0) freezeCount--;
    if (enemyAttacks) handleEnemyAttack();
}

// 通用战斗函数
void genericFight(int enemyMaxHp, int enemyDamage, int enemySkillChance, int enemySkillDamage,
                  int& playerHp, int& wineCount, int& mana, bool& canTransform, bool& hasDefeatedGuangzhi,
                  bool& hasTransformed, const std::string& enemyName,
                  bool canDodge, int snakeCount, bool& hasDefeatedLingxuzi, int& baseHp, bool& hasDefeatedThisEnemy, bool& canUpgradeDrink,
                  int& maxDrinkCount, bool& hasBigHeadSpirit, bool& hasGuangmouSpirit, int& currentSpirit, int& attackCounter,
                  bool& hasDefeatedBlackWindKing, int& invisibleCounter, bool& isInvisible, int& inputCount, int& stickStyle, int& qiStrength) {
    int enemyHp = enemyMaxHp;
    int attackCount = 0, freezeCount = 0;
    int blackWindCounter = 0;
    int blackWindPhase = 0;
    int blackWindTriggerHp = enemyHp;
    attackCounter = 0;
    invisibleCounter = 0;
    isInvisible = false;
    inputCount = 0;
    stickStyle = 0;
    qiStrength = 300;
    bool isBlackBearInFlameForm = false;

    while (true) {
        playerHp = baseHp;
        wineCount = 5;
        mana = 300;
        hasTransformed = false;
        snakeCount = 0;
        std::cout << "遭遇 " << enemyName << "，敌人HP: " << enemyHp << std::endl;
        std::cout << "是否战斗？(y/n): ";
        char fight;
        if (!(std::cin >> fight) ||!isValidInput()) continue;
        if (fight != 'y') break;

        while (enemyHp > 0 && playerHp > 0) {
            std::cout << enemyName << "HP: " << enemyHp << ", 你HP: " << playerHp << ", 法力: " << mana << ", 棍式: " << stickStyle << ", 气力: " << qiStrength << std::endl;
            handlePlayerAction(enemyHp, playerHp, wineCount, mana, attackCount, freezeCount,
                               canTransform, hasTransformed, enemyName,
                               enemyDamage, enemySkillChance, enemySkillDamage, canDodge,
                               blackWindCounter, blackWindPhase, maxDrinkCount,
                               currentSpirit, hasBigHeadSpirit, hasGuangmouSpirit, attackCounter,
                               hasDefeatedBlackWindKing, invisibleCounter, isInvisible, inputCount, stickStyle, qiStrength,
                               isBlackBearInFlameForm);
            if (snakeCount-- == 0 && enemyName == "广谋") handleAttack(playerHp, 10, "广谋召唤的小蛇");

            if (enemyName == "黑风大王" && enemyHp <= blackWindTriggerHp - 2000 && blackWindPhase == 0) {
                std::cout << "黑风大王变为黑风状态！接下来五次攻击无效。" << std::endl;
                blackWindPhase = 1;
                blackWindCounter = 0;
                blackWindTriggerHp -= 2000;
            }

            if (enemyName == "黑熊精" && enemyHp <= 2000 &&!isBlackBearInFlameForm) {
                std::cout << "黑熊精开启火焰形态！攻击附加火焰伤害。" << std::endl;
                isBlackBearInFlameForm = true;
            }
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
                hasGuangmouSpirit = true;
                canUpgradeDrink = true;
                std::cout << "获得广谋精魂，获得升级酒的机会。";
            } else if (enemyName == "大头怪") {
                hasBigHeadSpirit = true;
                std::cout << "获得大头怪精魂。";
            } else if (enemyName == "黑风大王") {
                canUpgradeDrink = true;
                hasDefeatedBlackWindKing = true;
                std::cout << "获得升级酒的机会！获得技能聚型散气。";
            } else if (enemyName == "黑熊精") {
                std::cout << "击败黑熊精！";
            }
            std::cout << std::endl;
            hasDefeatedThisEnemy = true;
            break;
        }

        std::cout << "被击败，再战？(y/n): ";
        char retry;
        if (!(std::cin >> retry) ||!isValidInput()) continue;
        if (retry != 'y') break;
        enemyHp = enemyMaxHp;
        stickStyle = 0;
        qiStrength = 300;
        isBlackBearInFlameForm = false;
    }
}

// 白衣秀士战斗函数
void fightWithWhiteScholar(int enemyMaxHpPhase1, int enemyMaxHpPhase2, int enemyDamage, int enemySkillChance, int enemySkillDamage,
                           int& playerHp, int& wineCount, int& mana, bool& canTransform, bool& hasDefeatedGuangzhi,
                           bool& hasTransformed, bool& hasDefeatedLingxuzi, int& baseHp, bool& hasDefeatedWhiteScholar,
                           int& maxDrinkCount, bool& hasBigHeadSpirit, bool& hasGuangmouSpirit, int& currentSpirit, int& attackCounter,
                           bool& hasDefeatedBlackWindKing, int& invisibleCounter, bool& isInvisible, int& inputCount, int& stickStyle, int& qiStrength) {
    int enemyHpPhase1 = enemyMaxHpPhase1;
    int enemyHpPhase2 = enemyMaxHpPhase2;
    int attackCount = 0, freezeCount = 0;
    int blackWindCounter = 0;
    int blackWindPhase = 0;
    attackCounter = 0;
    invisibleCounter = 0;
    isInvisible = false;
    inputCount = 0;
    stickStyle = 0;
    qiStrength = 300;
    bool isBlackBearInFlameForm = false;

    while (true) {
        playerHp = baseHp;
        wineCount = 5;
        mana = 300;
        hasTransformed = false;
        std::cout << "遭遇 白衣秀士，敌人HP: " << enemyHpPhase1 << std::endl;
        std::cout << "是否战斗？(y/n): ";
        char fight;
        if (!(std::cin >> fight) ||!isValidInput()) continue;
        if (fight != 'y') break;

        // 一阶段战斗
        int currentEnemyHp = enemyHpPhase1;
        while (currentEnemyHp > 0 && playerHp > 0) {
            std::cout << "白衣秀士HP: " << currentEnemyHp << ", 你HP: " << playerHp << ", 法力: " << mana << ", 棍式: " << stickStyle << ", 气力: " << qiStrength << std::endl;
            handlePlayerAction(currentEnemyHp, playerHp, wineCount, mana, attackCount, freezeCount,
                               canTransform, hasTransformed, "白衣秀士",
                               enemyDamage, enemySkillChance, enemySkillDamage, true,
                               blackWindCounter, blackWindPhase, maxDrinkCount,
                               currentSpirit, hasBigHeadSpirit, hasGuangmouSpirit, attackCounter,
                               hasDefeatedBlackWindKing, invisibleCounter, isInvisible, inputCount, stickStyle, qiStrength,
                               isBlackBearInFlameForm);
            if (freezeCount > 0) freezeCount--;
        }

        if (currentEnemyHp <= 0) {
            std::cout << "击败 白衣秀士 一阶段！进入二阶段..." << std::endl;
            // 二阶段战斗
            while (enemyHpPhase2 > 0 && playerHp > 0) {
                std::cout << "白衣秀士HP: " << enemyHpPhase2 << ", 你HP: " << playerHp << ", 法力: " << mana << ", 棍式: " << stickStyle << ", 气力: " << qiStrength << std::endl;
                enemyHpPhase2 += 5;
                handlePlayerAction(enemyHpPhase2, playerHp, wineCount, mana, attackCount, freezeCount,
                                   canTransform, hasTransformed, "白衣秀士",
                                   enemyDamage, enemySkillChance, enemySkillDamage, true,
                                   blackWindCounter, blackWindPhase, maxDrinkCount,
                                   currentSpirit, hasBigHeadSpirit, hasGuangmouSpirit, attackCounter,
                                   hasDefeatedBlackWindKing, invisibleCounter, isInvisible, inputCount, stickStyle, qiStrength,
                                   isBlackBearInFlameForm);
                if (freezeCount > 0) freezeCount--;
            }
            if (enemyHpPhase2 <= 0) {
                std::cout << "击败 白衣秀士 二阶段！" << std::endl;
                hasDefeatedWhiteScholar = true;
                break;
            }
        }

        std::cout << "被击败，再战？(y/n): ";
        char retry;
        if (!(std::cin >> retry) ||!isValidInput()) continue;
        if (retry != 'y') break;
        enemyHpPhase1 = enemyMaxHpPhase1;
        enemyHpPhase2 = enemyMaxHpPhase2;
        stickStyle = 0;
        qiStrength = 300;
    }
}

// 土地庙整顿装备函数
void landTemple(int& baseHp, bool& hasDefeatedLingxuzi, bool& hasBigHeadSpirit, bool& hasGuangmouSpirit, int& currentSpirit) {
    std::cout << "你来到了土地庙，当前基础生命值: " << baseHp << std::endl;
    std::cout << "你拥有的装备：虎皮裙（增加 30 HP）";
    if (hasDefeatedLingxuzi) std::cout << "，行者套（增加 60 HP）";
    std::cout << std::endl;
    std::cout << "你拥有的精魂：";
    if (hasBigHeadSpirit) std::cout << "大头怪精魂 ";
    if (hasGuangmouSpirit) std::cout << "广谋精魂 ";
    std::cout << std::endl;
    std::cout << "当前使用的精魂：";
    if (currentSpirit == 1) std::cout << "大头怪精魂" << std::endl;
    else if (currentSpirit == 2) std::cout << "广谋精魂" << std::endl;
    else std::cout << "无" << std::endl;
    std::cout << "是否更换装备或精魂？(y/n): ";
    char choice;
    if (!(std::cin >> choice) ||!isValidInput()) return;
    if (choice == 'y') {
        std::cout << "1. 更换装备" << std::endl;
        std::cout << "2. 更换精魂" << std::endl;
        std::cout << "请选择: ";
        char subChoice;
        if (!(std::cin >> subChoice) ||!isValidInput()) return;
        if (subChoice == '1') {
            baseHp = hasDefeatedLingxuzi? 300 + 60 : 300 + 30;
            std::cout << "你穿上了" << (hasDefeatedLingxuzi? "行者套" : "虎皮裙")
                      << "，当前基础生命值变为: " << baseHp << std::endl;
        } else if (subChoice == '2') {
            if (hasBigHeadSpirit || hasGuangmouSpirit) {
                std::cout << "1. 大头怪精魂" << std::endl;
                std::cout << "2. 广谋精魂" << std::endl;
                std::cout << "请选择要使用的精魂（输入对应数字）: ";
                char spiritChoice;
                if (!(std::cin >> spiritChoice) ||!isValidInput()) return;
                if (spiritChoice == '1' && hasBigHeadSpirit) {
                    currentSpirit = 1;
                    std::cout << "当前使用大头怪精魂。" << std::endl;
                } else if (spiritChoice == '2' && hasGuangmouSpirit) {
                    currentSpirit = 2;
                    std::cout << "当前使用广谋精魂。" << std::endl;
                } else {
                    std::cout << "无效选择。" << std::endl;
                }
            } else {
                std::cout << "你没有可更换的精魂。" << std::endl;
            }
        }
    }
}

// 申猴界面
void shenhou(bool& canUpgradeDrink, int& maxDrinkCount) {
    while (true) {
        std::cout << "申猴界面：" << std::endl;
        std::cout << "1. 升级酒（当前可喝次数: " << maxDrinkCount << "）" << std::endl;
        std::cout << "2. 返回主菜单" << std::endl;
        std::cout << "请选择: ";
        char choice;
        if (!(std::cin >> choice) ||!isValidInput()) continue;
        switch (choice) {
            case '1':
                if (canUpgradeDrink) {
                    maxDrinkCount++;
                    canUpgradeDrink = false;
                    std::cout << "酒升级成功，现在可喝次数: " << maxDrinkCount << std::endl;
                } else {
                    std::cout << "没有升级酒的机会。" << std::endl;
                }
                break;
            case '2':
                return;
            default:
                std::cout << "无效选择。" << std::endl;
        }
    }
}
int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int playerHp = 300, wineCount = 5, mana = 300;
    bool canTransform = false, hasDefeatedGuangzhi = false, hasTransformed = false;
    bool hasDefeatedLingxuzi = false;
    int baseHp = 300 + 30;
    bool hasDefeatedBigMonster = false;
    bool hasDefeatedGuangzhiEnemy = false;
    bool hasDefeatedLingxuziEnemy = false;
    bool hasDefeatedGuangmou = false;
    bool hasDefeatedWhiteScholar = false;
    bool hasDefeatedBlackWindKing = false;
    bool canUpgradeDrink = false;
    int maxDrinkCount = 4;
    bool hasBigHeadSpirit = false;
    bool hasGuangmouSpirit = false;
    int currentSpirit = 0;
    int attackCounter = 0;
    int invisibleCounter = 0;
    bool isInvisible = false;
    int inputCount = 0;
    int stickStyle = 0;
    int qiStrength = 300;
    bool hasDefeatedBlackBear = false; // 新增变量

    landTemple(baseHp, hasDefeatedLingxuzi, hasBigHeadSpirit, hasGuangmouSpirit, currentSpirit);

    while (true) {
        std::cout << "\n=== 黑神话：悟空 ===" << std::endl;
        std::cout << "1. 打怪" << std::endl;
        std::cout << "2. 土地庙" << std::endl;
        std::cout << "3. 人物（申猴）" << std::endl;
        std::cout << "4. 退出" << std::endl;
        std::cout << "请选择: ";
        char mainChoice;
        if (!(std::cin >> mainChoice) ||!isValidInput()) continue;

        switch (mainChoice) {
            case '1': {
                std::cout << "可选战斗：";
                if (!hasDefeatedBigMonster) std::cout << "1.大头怪 ";
                if (!hasDefeatedGuangzhiEnemy) std::cout << "2.广智 ";
                if (!hasDefeatedLingxuziEnemy) std::cout << "3.灵虚子 ";
                if (!hasDefeatedGuangmou) std::cout << "4.广谋 ";
                if (!hasDefeatedWhiteScholar) std::cout << "5.白衣秀士 ";
                if (!hasDefeatedBlackWindKing) std::cout << "6.黑风大王 ";
                if (!hasDefeatedBlackBear) std::cout << "7.黑熊精 ";
                std::cout << std::endl;
                std::cout << "请选择要挑战的怪物（输入对应数字，输入其他返回主菜单）: ";
                char fightChoice;
                if (!(std::cin >> fightChoice) ||!isValidInput()) continue;

                struct EnemyInfo {
                    int hp;
                    int damage;
                    int skillChance;
                    int skillDamage;
                    bool canDodge;
                    int snakeCount;
                    bool* defeatedFlag;
                    std::string name;
                };

                EnemyInfo enemies[] = {
                    {3000, 50, 20, 200, true, 0, &hasDefeatedBigMonster, "大头怪"},
                    {2000, 30, 10, 100, true, 0, &hasDefeatedGuangzhiEnemy, "广智"},
                    {1500, 40, 15, 150, true, 0, &hasDefeatedLingxuziEnemy, "灵虚子"},
                    {2500, 45, 20, 200, true, 3, &hasDefeatedGuangmou, "广谋"},
                    {1800, 40, 15, 150, true, 0, &hasDefeatedWhiteScholar, "白衣秀士"},
                    {5000, 60, 25, 250, true, 0, &hasDefeatedBlackWindKing, "黑风大王"},
                    {5000, 50, 20, 200, true, 0, &hasDefeatedBlackBear, "黑熊精"}
                };

                for (int i = 0; i < 7; ++i) {
                    if (fightChoice - '1' == i &&!(*enemies[i].defeatedFlag)) {
                        if (i == 4) {
                            fightWithWhiteScholar(enemies[i].hp, 2200, enemies[i].damage, enemies[i].skillChance, enemies[i].skillDamage,
                                                  playerHp, wineCount, mana, canTransform, hasDefeatedGuangzhi,
                                                  hasTransformed, hasDefeatedLingxuzi, baseHp, hasDefeatedWhiteScholar,
                                                  maxDrinkCount, hasBigHeadSpirit, hasGuangmouSpirit, currentSpirit, attackCounter,
                                                  hasDefeatedBlackWindKing, invisibleCounter, isInvisible, inputCount, stickStyle, qiStrength);
                        } else {
                            genericFight(enemies[i].hp, enemies[i].damage, enemies[i].skillChance, enemies[i].skillDamage,
                                         playerHp, wineCount, mana, canTransform, hasDefeatedGuangzhi,
                                         hasTransformed, enemies[i].name,
                                         enemies[i].canDodge, enemies[i].snakeCount, hasDefeatedLingxuzi, baseHp, *enemies[i].defeatedFlag,
                                         canUpgradeDrink, maxDrinkCount, hasBigHeadSpirit, hasGuangmouSpirit, currentSpirit, attackCounter,
                                         hasDefeatedBlackWindKing, invisibleCounter, isInvisible, inputCount, stickStyle, qiStrength);
                        }
                        break;
                    }
                }
                break;
            }
            case '2':
                landTemple(baseHp, hasDefeatedLingxuzi, hasBigHeadSpirit, hasGuangmouSpirit, currentSpirit);
                break;
            case '3':
                shenhou(canUpgradeDrink, maxDrinkCount);
                break;
            case '4':
                return 0;
            default:
                std::cout << "无效选择，请重新输入。" << std::endl;
        }
    }
    return 0;
}    
