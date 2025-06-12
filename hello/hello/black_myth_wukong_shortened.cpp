#include <iostream>
#include <cstdlib>
#include <ctime>

bool isValidInput() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "输入无效，请重新输入。" << std::endl;
        return false;
    }
    return true;
}

void handleAttack(int& targetHp, int damage, const std::string& enemyName) {
    targetHp -= damage;
    if (targetHp < 0) targetHp = 0;
    std::cout << enemyName << "攻击，你失去 " << damage << " 生命值。" << std::endl;
}

void fightAsGuangzhi(int& enemyHp, int& playerHp, int& attackCount, int& mana, int& freezeCount, int& stickStyle, int& qiStrength) {
    int gzHp = 800;
    bool canDeal200Damage = true;
    while (enemyHp > 0 && gzHp > 0) {
        std::cout << "敌人HP: " << enemyHp << ", 广智HP: " << gzHp << ", 法力: " << mana 
                  << ", 棍式: " << stickStyle << ", 气力: " << qiStrength << std::endl;
        std::cout << "1.攻击 2.躲避: ";
        char choice;
        if (!(std::cin >> choice) ||!isValidInput()) continue;

        int damage = 30;
        if (choice == '1') {
            if (attackCount % 3 == 0 && canDeal200Damage) {
                damage = 200;
            }
            std::cout << "造成 " << damage << " 伤害。" << std::endl;
            enemyHp -= damage;
            stickStyle += 20;
            qiStrength = std::min(qiStrength + 10, 300);

            if (stickStyle >= 400) {
                std::cout << "棍式达到400，对敌人造成250伤害。" << std::endl;
                enemyHp -= 250;
                stickStyle = 0;
            }

            attackCount++;
            if (attackCount == 3) {
                canDeal200Damage = false;
            }

            if (enemyHp > 0 &&!freezeCount) {
                int enemyDamage = rand() % 100 < 10? 80 : 30;
                if (rand() % 100 < 20) {
                    enemyDamage += 20;
                    std::cout << "广智攻击附加20火焰伤害！" << std::endl;
                }
                std::cout << "敌人反击！输入 2 躲避: ";
                if (std::cin >> choice && isValidInput() && (choice != '2' || rand() % 100 >= 60)) {
                    handleAttack(gzHp, enemyDamage, "敌人");
                }
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
                if (rand() % 100 < 20) {
                    enemyDamage += 20;
                    std::cout << "广智攻击附加20火焰伤害！" << std::endl;
                }
                std::cout << "敌人反击！输入 2 躲避: ";
                if (std::cin >> choice && isValidInput() && (choice != '2' || rand() % 100 >= 60)) {
                    handleAttack(gzHp, enemyDamage, "敌人");
                }
            }
        }
        if (freezeCount > 0) freezeCount--;
    }
    if (gzHp <= 0) std::cout << "广智形态被击败，变回本体。" << std::endl;
}

int getStickStylePhase(int stickStyle) {
    return std::min(stickStyle / 100, 4);
}

int getSkillDamage(int phase, char skill) {
    return (skill == '9' && phase >= 1 && phase <= 4)? 150 + phase * 50 : 0;
}

void handlePlayerAction(int& enemyHp, int& playerHp, int& wineCount, int& mana, int& attackCount, int& freezeCount,
                        bool& canTransform, bool& hasTransformed, const std::string& enemyName,
                        int enemyDamage, int enemySkillChance, int enemySkillDamage, bool canDodge,
                        int& blackWindCounter, int& blackWindPhase, int& maxDrinkCount,
                        int& currentSpirit, bool& hasBigHeadSpirit, bool& hasGuangmouSpirit, int& attackCounter,
                        bool& hasDefeatedBlackWindKing, int& invisibleCounter, bool& isInvisible, int& inputCount, int& stickStyle, int& qiStrength,
                        bool& isBlackBearInFlameForm, bool& hasPihuoShield, bool& isPihuoShieldEquipped, int& currentWeaponDamage, int& extraDamageFromBlackWindArmor, bool& hasJinchiRecovered, bool& hasDefeatedWhiteScholar, bool& hasDefeatedBlackBear) {
    if ((currentSpirit == 1 && hasBigHeadSpirit && attackCounter >= 30) || 
        (currentSpirit == 2 && hasGuangmouSpirit && attackCounter >= 20)) {
        int damage = (currentSpirit == 1)? 200 : 125;
        enemyHp -= damage;
        std::cout << "使用精魂，对敌人造成 " << damage << " 伤害。" << std::endl;
        attackCounter = 0;
        qiStrength = std::min(qiStrength + 10, 300);
    }
    if (hasDefeatedBlackWindKing) {
        std::cout << "你已获得技能聚型散气，输入 7 使用（消耗法力 20）。" << std::endl;
    }
    if (hasPihuoShield && isPihuoShieldEquipped) {
        std::cout << "你已装备辟火罩，输入 10 使用。" << std::endl;
    }
    std::cout << "当前棍式: " << stickStyle << ", 棍式阶段: " << getStickStylePhase(stickStyle) 
              << ", 气力: " << qiStrength << ", 当前武器伤害加成: " << currentWeaponDamage << std::endl;
    std::cout << "1.攻击 2.躲避 3.喝酒 4.变身 5.定身术 6.使用精魂 7.聚型散气 8.蓄力 9.重棍";
    if (hasPihuoShield && isPihuoShieldEquipped) {
        std::cout << " 10.使用辟火罩";
    }
    std::cout << " 11.更换武器: ";
    char choice[3];
    if (!(std::cin >> choice) ||!isValidInput()) return;
    inputCount++;
    bool enemyAttacks = true;
    static int freezeInputCount = 0;

    auto handleEnemyAttack = [&]() {
        if (enemyHp > 0 &&!freezeCount &&!isInvisible && freezeInputCount == 0) {
            int actualDamage = enemySkillChance > rand() % 100? enemySkillDamage : enemyDamage;
            if (isBlackBearInFlameForm &&!isPihuoShieldEquipped) {
                actualDamage += 20;
            }
            if (enemyName == "广智" && rand() % 100 < 20 &&!isPihuoShieldEquipped) {
                actualDamage += 20;
                std::cout << "广智攻击附加20火焰伤害！" << std::endl;
            }
            std::cout << enemyName << "攻击！输入 2 躲避: ";
            if (std::cin >> choice[0] && isValidInput() && (choice[0] != '2' || rand() % 100 >= 60)) {
                handleAttack(playerHp, actualDamage, enemyName);
            }
        }
    };

    if (choice[0] == '1') {
        if (enemyName == "黑风大王" && blackWindPhase > 0) {
            std::cout << "黑风状态，攻击无效！" << std::endl;
            if (++blackWindCounter == 5) {
                std::cout << "黑风大王释放大招！" << std::endl;
                handleAttack(playerHp, 200, "黑风大王");
                blackWindPhase = 0;
                blackWindCounter = 0;
            } else {
                handleAttack(playerHp, enemyDamage, enemyName);
            }
            enemyAttacks = false;
        } else {
            int damage = isInvisible? 200 + extraDamageFromBlackWindArmor : 
                         (rand() % 100 < 10? 100 + currentWeaponDamage + extraDamageFromBlackWindArmor : 30 + currentWeaponDamage + extraDamageFromBlackWindArmor);
            std::cout << (damage > 30 + currentWeaponDamage + extraDamageFromBlackWindArmor? "暴击！" : "") << "造成 " << damage << " 伤害。" << std::endl;
            if (isInvisible) {
                isInvisible = false;
                invisibleCounter = 0;
                inputCount = 0;
            } else if (canDodge &&!freezeCount && rand() % 100 < 20) {
                std::cout << enemyName << "闪避。" << std::endl;
            } else {
                enemyHp -= damage;
            }
            stickStyle += 20;
            attackCounter++;
            qiStrength = std::min(qiStrength + 10, 300);
        }
    } else if (choice[0] == '2') {
        if (qiStrength >= 10) {
            qiStrength -= 10;
            std::cout << "闪避成功，消耗 10 气力，当前气力: " << qiStrength << std::endl;
        } else {
            std::cout << "气力不足，无法闪避。" << std::endl;
        }
    } else if (choice[0] == '3') {
        if (wineCount > 0) {
            playerHp += 200;
            wineCount--;
            std::cout << "回复 200 HP，剩 " << wineCount << " 瓶酒。" << std::endl;
        } else {
            std::cout << "无酒。" << std::endl;
        }
        qiStrength = std::min(qiStrength + 10, 300);
    } else if (choice[0] == '4') {
        if (canTransform &&!hasTransformed) {
            int tempEnemyHp = enemyHp;
            fightAsGuangzhi(tempEnemyHp, playerHp, attackCount, mana, freezeCount, stickStyle, qiStrength);
            enemyHp = tempEnemyHp;
            hasTransformed = true;
        } else {
            std::cout << "无法变身。" << std::endl;
        }
        qiStrength = std::min(qiStrength + 10, 300);
    } else if (choice[0] == '5') {
        if (hasTransformed) {
            std::cout << "变身广智时不能用定身术。" << std::endl;
        } else if (mana >= 50) {
            mana -= 50;
            freezeCount = 5;
            freezeInputCount = 6;
            std::cout << enemyName << "被定身 5 回合，期间不能躲避和攻击，接下来你有6次输入机会不受敌人干扰。" << std::endl;
        } else {
            std::cout << "法力不足。" << std::endl;
        }
        qiStrength = std::min(qiStrength + 10, 300);
    } else if (choice[0] == '7') {
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
    } else if (choice[0] == '8') {
        if (qiStrength >= 20) {
            qiStrength -= 20;
            stickStyle += 30;
            std::cout << "蓄力，棍式增加 30，消耗 20 气力，当前棍式: " << stickStyle 
                      << ", 当前气力: " << qiStrength << ", 当前武器伤害加成: " << currentWeaponDamage << std::endl;
        } else {
            std::cout << "气力不足，无法蓄力。" << std::endl;
        }
    } else if (choice[0] == '9') {
        int phase = getStickStylePhase(stickStyle);
        int damage = getSkillDamage(phase, choice[0]);
        enemyHp -= damage;
        std::cout << "重棍攻击，造成 " << damage << " 伤害。" << std::endl;
        stickStyle = 0;
        qiStrength = std::min(qiStrength + 10, 300);
    } else if (choice[0] == '1' && choice[1] == '0' && hasPihuoShield && isPihuoShieldEquipped) {
        stickStyle += 20;
        std::cout << "使用辟火罩，棍式增加20，当前棍式: " << stickStyle << ", 当前武器伤害加成: " << currentWeaponDamage << std::endl;
    } else if (choice[0] == '1' && choice[1] == '1') {
        std::cout << "1. 柳木棍（增加10伤害）" << std::endl;
        if (hasDefeatedWhiteScholar) {
            std::cout << "2. 鳞棍双蛇（增加15伤害）" << std::endl;
        }
        if (hasDefeatedBlackBear) {
            std::cout << "3. 兽棍熊罢（增加20伤害）" << std::endl;
        }
        std::cout << "请选择要装备的武器（输入对应数字）: ";
        if (std::cin >> choice[0] && isValidInput()) {
            if (choice[0] == '1') {
                currentWeaponDamage = 10;
            } else if (choice[0] == '2' && hasDefeatedWhiteScholar) {
                currentWeaponDamage = 15;
            } else if (choice[0] == '3' && hasDefeatedBlackBear) {
                currentWeaponDamage = 20;
            } else {
                std::cout << "无效选择。" << std::endl;
            }
            std::cout << "你装备了对应武器，当前武器伤害加成变为: " << currentWeaponDamage << std::endl;
        }
    } else {
        std::cout << "无效选择。" << std::endl;
        enemyAttacks = false;
    }

    if (isPihuoShieldEquipped) {
        stickStyle += 20;
    }

    if (isInvisible) {
        if (--invisibleCounter <= 0 || inputCount >= 20) {
            isInvisible = false;
            invisibleCounter = 0;
            inputCount = 0;
            std::cout << "聚型散气技能效果结束，你现形了。" << std::endl;
        }
    }
    if (freezeCount > 0) freezeCount--;
    if (freezeInputCount > 0) {
        freezeInputCount--;
        enemyAttacks = false;
    }
    if (enemyAttacks) handleEnemyAttack();
}

void genericFight(int enemyMaxHp, int enemyDamage, int enemySkillChance, int enemySkillDamage,
                  int& playerHp, int& wineCount, int& mana, bool& canTransform, bool& hasDefeatedGuangzhi,
                  bool& hasTransformed, const std::string& enemyName,
                  bool canDodge, int snakeCount, bool& hasDefeatedLingxuzi, int& baseHp, bool& hasDefeatedThisEnemy, bool& canUpgradeDrink,
                  int& maxDrinkCount, bool& hasBigHeadSpirit, bool& hasGuangmouSpirit, int& currentSpirit, int& attackCounter,
                  bool& hasDefeatedBlackWindKing, int& invisibleCounter, bool& isInvisible, int& inputCount, int& stickStyle, int& qiStrength,
                  bool& isBlackBearInFlameForm, bool& hasPihuoShield, bool& isPihuoShieldEquipped, int& currentWeaponDamage, int& extraDamageFromBlackWindArmor, bool& hasJinchiRecovered, bool& hasDefeatedWhiteScholar, bool& hasDefeatedBlackBear) {
    int enemyHp = enemyMaxHp;
    int attackCount = 0, freezeCount = 0;
    int blackWindCounter = 0, blackWindPhase = 0;
    int blackWindTriggerHp = enemyHp;
    int halfHp = enemyMaxHp / 2;

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
            std::cout << enemyName << "HP: " << enemyHp << ", 你HP: " << playerHp << ", 法力: " << mana 
                      << ", 棍式: " << stickStyle << ", 气力: " << qiStrength << std::endl;
            handlePlayerAction(enemyHp, playerHp, wineCount, mana, attackCount, freezeCount,
                               canTransform, hasTransformed, enemyName,
                               enemyDamage, enemySkillChance, enemySkillDamage, canDodge,
                               blackWindCounter, blackWindPhase, maxDrinkCount,
                               currentSpirit, hasBigHeadSpirit, hasGuangmouSpirit, attackCounter,
                               hasDefeatedBlackWindKing, invisibleCounter, isInvisible, inputCount, stickStyle, qiStrength,
                               isBlackBearInFlameForm, hasPihuoShield, isPihuoShieldEquipped, currentWeaponDamage, extraDamageFromBlackWindArmor, hasJinchiRecovered, hasDefeatedWhiteScholar, hasDefeatedBlackBear);
            if (snakeCount-- == 0 && enemyName == "广谋") {
                handleAttack(playerHp, 10, "广谋召唤的小蛇");
            }

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

            if (enemyName == "金池长老" && enemyHp <= halfHp && !hasJinchiRecovered) {
                enemyHp += 300;
                hasJinchiRecovered = true;
                std::cout << "金池长老生命被攻击到一半后，回复300生命！当前生命值: " << enemyHp << std::endl;
                halfHp = -1;
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
                std::cout << "获得金丹一枚，基础生命值增加 100。获得行者套，装备后增加 60 生命值。";
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
                hasDefeatedBlackBear = true;
                std::cout << "获得装备：黑风铠甲（增加120生命，使用聚型散气攻击一次增加20伤害），武器：兽棍熊罢（增加20伤害）。";
                baseHp += 120;
                extraDamageFromBlackWindArmor = 20;
            } else if (enemyName == "金池长老") {
                hasPihuoShield = true;
                std::cout << "获得法宝辟火罩！";
            } else if (enemyName == "白衣秀士") {
                hasDefeatedWhiteScholar = true;
                std::cout << "获得新装备：锦鳞战袍（增加100生命值），新武器：鳞棍双蛇（增加15伤害）。";
                baseHp += 100;
                currentWeaponDamage = 15;
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
        halfHp = enemyMaxHp / 2;
        hasJinchiRecovered = false;
    }
}

void landTemple(int& baseHp, bool& hasDefeatedLingxuzi, bool& hasBigHeadSpirit, bool& hasGuangmouSpirit, int& currentSpirit,
                bool& hasPihuoShield, bool& isPihuoShieldEquipped, int& currentWeaponDamage, bool& hasDefeatedWhiteScholar, bool& hasDefeatedBlackBear) {
    std::cout << "你来到了土地庙，当前基础生命值: " << baseHp << std::endl;
    std::cout << "你拥有的装备：虎皮裙（增加 30 HP）";
    if (hasDefeatedLingxuzi) std::cout << "，行者套（增加 60 HP）";
    if (hasDefeatedWhiteScholar) std::cout << "，锦鳞战袍（增加100生命值）";
    std::cout << std::endl;
    std::cout << "你拥有的武器：柳木棍（增加10伤害）";
    if (hasDefeatedWhiteScholar) std::cout << "，鳞棍双蛇（增加15伤害）";
    if (hasDefeatedBlackBear) std::cout << "，兽棍熊罢（增加20伤害）";
    std::cout << std::endl;
    std::cout << "你拥有的精魂：";
    if (hasBigHeadSpirit) std::cout << "大头怪精魂 ";
    if (hasGuangmouSpirit) std::cout << "广谋精魂 ";
    std::cout << std::endl;
    if (hasPihuoShield) {
        std::cout << "你拥有的法宝：辟火罩 ";
        std::cout << (isPihuoShieldEquipped? "(已装备)" : "(未装备)");
        std::cout << std::endl;
    }
    std::cout << "当前使用的精魂：";
    if (currentSpirit == 1) std::cout << "大头怪精魂" << std::endl;
    else if (currentSpirit == 2) std::cout << "广谋精魂" << std::endl;
    else std::cout << "无" << std::endl;
    std::cout << "当前武器伤害加成: " << currentWeaponDamage << std::endl;
    std::cout << "是否更换装备、精魂、法宝或武器？(y/n): ";
    char choice;
    if (!(std::cin >> choice) ||!isValidInput()) return;
    if (choice != 'y') return;

    std::cout << "1. 更换装备" << std::endl;
    std::cout << "2. 更换精魂" << std::endl;
    if (hasPihuoShield) {
        std::cout << "3. 更换法宝" << std::endl;
    }
    std::cout << "4. 更换武器" << std::endl;
    std::cout << "请选择: ";
    if (!(std::cin >> choice) ||!isValidInput()) return;

    if (choice == '1') {
        std::cout << "1. 虎皮裙（增加 30 HP）" << std::endl;
        std::cout << "2. 行者套（增加 60 HP）" << std::endl;
        if (hasDefeatedWhiteScholar) std::cout << "3. 锦鳞战袍（增加100生命值）" << std::endl;
        std::cout << "请选择要装备的防具（输入对应数字）: ";
        if (std::cin >> choice && isValidInput()) {
            if (choice == '1') {
                baseHp = 300 + 30;
            } else if (choice == '2' && hasDefeatedLingxuzi) {
                baseHp = 300 + 60;
            } else if (choice == '3' && hasDefeatedWhiteScholar) {
                baseHp = 300 + 100;
            } else {
                std::cout << "无效选择。" << std::endl;
            }
            std::cout << "你装备了对应防具，当前基础生命值变为: " << baseHp << std::endl;
        }
    } else if (choice == '2') {
        if (hasBigHeadSpirit || hasGuangmouSpirit) {
            std::cout << "1. 大头怪精魂" << std::endl;
            std::cout << "2. 广谋精魂" << std::endl;
            std::cout << "请选择要使用的精魂（输入对应数字）: ";
            if (std::cin >> choice && isValidInput()) {
                if (choice == '1' && hasBigHeadSpirit) {
                    currentSpirit = 1;
                } else if (choice == '2' && hasGuangmouSpirit) {
                    currentSpirit = 2;
                } else {
                    std::cout << "无效选择。" << std::endl;
                }
                std::cout << "当前使用 " << (currentSpirit == 1? "大头怪精魂" : "广谋精魂") << std::endl;
            }
        }
    } else if (choice == '3' && hasPihuoShield) {
        isPihuoShieldEquipped =!isPihuoShieldEquipped;
        std::cout << "辟火罩 " << (isPihuoShieldEquipped? "已装备" : "已卸下") << std::endl;
    } else if (choice == '4') {
        std::cout << "1. 柳木棍（增加10伤害）" << std::endl;
        if (hasDefeatedWhiteScholar) std::cout << "2. 鳞棍双蛇（增加15伤害）" << std::endl;
        if (hasDefeatedBlackBear) std::cout << "3. 兽棍熊罢（增加20伤害）" << std::endl;
        std::cout << "请选择要装备的武器（输入对应数字）: ";
        if (std::cin >> choice && isValidInput()) {
            if (choice == '1') {
                currentWeaponDamage = 10;
            } else if (choice == '2' && hasDefeatedWhiteScholar) {
                currentWeaponDamage = 15;
            } else if (choice == '3' && hasDefeatedBlackBear) {
                currentWeaponDamage = 20;
            } else {
                std::cout << "无效选择。" << std::endl;
            }
            std::cout << "你装备了对应武器，当前武器伤害加成变为: " << currentWeaponDamage << std::endl;
        }
    }
}

int main() {
    srand(time(0));
    int baseHp = 300 + 30;
    int playerHp = baseHp;
    int wineCount = 5;
    int mana = 300;
    bool canTransform = false;
    bool hasDefeatedGuangzhi = false;
    bool hasTransformed = false;
    bool hasDefeatedLingxuzi = false;
    bool hasDefeatedWhiteScholar = false;
    bool hasDefeatedGuangmou = false;
    bool hasDefeatedBigHead = false;
    bool hasDefeatedBlackWindKing = false;
    bool hasDefeatedBlackBear = false;
    bool hasDefeatedJinchi = false;
    int maxDrinkCount = 5;
    bool hasBigHeadSpirit = false;
    bool hasGuangmouSpirit = false;
    int currentSpirit = 0;
    int attackCounter = 0;
    int invisibleCounter = 0;
    bool isInvisible = false;
    int inputCount = 0;
    int stickStyle = 0;
    int qiStrength = 300;
    bool isBlackBearInFlameForm = false;
    bool hasPihuoShield = false;
    bool isPihuoShieldEquipped = false;
    int currentWeaponDamage = 10;
    int extraDamageFromBlackWindArmor = 0;
    bool hasJinchiRecovered = false;

    while (true) {
        std::cout << "当前HP: " << playerHp << ", 酒: " << wineCount << ", 法力: " << mana << std::endl;
        std::cout << "1. 挑战广智 2. 挑战灵虚子 3. 挑战白衣秀士 4. 挑战广谋 5. 挑战大头怪 ";
        std::cout << "6. 挑战黑风大王 7. 挑战黑熊精 8. 挑战金池长老 9. 前往土地庙 0. 退出游戏: ";
        char choice;
        if (!(std::cin >> choice) ||!isValidInput()) continue;

        bool canUpgradeDrink;
        bool hasDefeatedThisEnemy;

        switch (choice) {
            case '1':
                canUpgradeDrink = false;
                hasDefeatedThisEnemy = false;
                genericFight(3000, 30, 10, 80, playerHp, wineCount, mana, canTransform, hasDefeatedGuangzhi,
                             hasTransformed, "广智", true, 0, hasDefeatedLingxuzi, baseHp, hasDefeatedThisEnemy,
                             canUpgradeDrink, maxDrinkCount, hasBigHeadSpirit, hasGuangmouSpirit, currentSpirit, attackCounter,
                             hasDefeatedBlackWindKing, invisibleCounter, isInvisible, inputCount, stickStyle, qiStrength,
                             isBlackBearInFlameForm, hasPihuoShield, isPihuoShieldEquipped, currentWeaponDamage, extraDamageFromBlackWindArmor, hasJinchiRecovered, hasDefeatedWhiteScholar, hasDefeatedBlackBear);
                break;
            case '2':
                canUpgradeDrink = false;
                hasDefeatedThisEnemy = false;
                genericFight(2500, 35, 15, 90, playerHp, wineCount, mana,