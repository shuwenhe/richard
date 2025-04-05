#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

// 提前声明 fightAsGuangzhi 函数
void fightAsGuangzhi(int& enemyHp, int& playerHp, int& attackCount, int& wineCount, bool& canTransform);

// 验证输入是否合法
bool isValidInput() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "输入无效，请输入有效的值。" << std::endl;
        return false;
    }
    return true;
}

// 打招呼函数
void welcome() {
    std::cout << "请输入您的大名！" << std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "Hello " << name << std::endl;
}

// 两数运算函数
void twoNumberOperation() {
    double a, b;
    char op;
    std::cout << "请输入两个数和运算符（例如：3 + 5）: ";
    std::cin >> a >> op >> b;
    if (!isValidInput()) return;

    switch (op) {
        case '+':
            std::cout << a + b << std::endl;
            break;
        case '-':
            std::cout << a - b << std::endl;
            break;
        case '*':
            std::cout << a * b << std::endl;
            break;
        case '/':
            if (b != 0) {
                std::cout << a / b << std::endl;
            } else {
                std::cout << "错误：除数不能为零！" << std::endl;
            }
            break;
        default:
            std::cout << "错误：不支持的运算符！" << std::endl;
    }
}

// 连运算函数
void continuousOperation() {
    int x, y;
    char op;
    std::cout << "请输入两个数和运算符（例如：1 + 10）: ";
    std::cin >> x >> op >> y;
    if (!isValidInput()) return;

    switch (op) {
        case '+': {
            int sum = 0;
            for (int i = x; i <= y; i++) {
                sum += i;
            }
            std::cout << x << " 加到 " << y << " 的和是 " << sum << std::endl;
            break;
        }
        case '-': {
            int result = x;
            for (int i = x + 1; i <= y; i++) {
                result -= i;
            }
            std::cout << "连减结果是 " << result << std::endl;
            break;
        }
        case '*': {
            int product = 1;
            for (int i = x; i <= y; i++) {
                product *= i;
            }
            std::cout << "连乘结果是 " << product << std::endl;
            break;
        }
        case '/':
            if (x == 0) {
                std::cout << "错误：连除初始值不能为零！" << std::endl;
            } else {
                int quotient = x;
                for (int i = x + 1; i <= y; i++) {
                    if (i != 0) {
                        quotient /= i;
                    } else {
                        std::cout << "错误：除数不能为零！" << std::endl;
                        return;
                    }
                }
                std::cout << "连除结果是 " << quotient << std::endl;
            }
            break;
        default:
            std::cout << "错误：不支持的运算符！" << std::endl;
    }
}

// 与大头怪战斗函数
void fightBigHead(int& playerHp, int& wineCount, bool& canTransform, bool& hasDefeatedGuangzhi, bool& hasTransformed) {
    int bigHeadHp = 3000;
    int attackCount = 0;

    while (true) {
        playerHp = 300;
        wineCount = 5;
        if (!hasDefeatedGuangzhi) {
            canTransform = false;
        }
        hasTransformed = false;

        std::cout << "你遇到了大头怪，它有 3000 生命值，你当前生命值为 " << playerHp << "。" << std::endl;
        std::cout << "是否要和大头怪战斗？（y/n）";
        char fightChoice;
        std::cin >> fightChoice;
        if (!isValidInput()) return;

        if (fightChoice != 'y' && fightChoice != 'Y') {
            std::cout << "你选择了不战斗，离开了。" << std::endl;
            break;
        }

        bigHeadHp = 3000;
        while (bigHeadHp > 0 && playerHp > 0) {
            std::cout << "大头怪剩余生命值: " << bigHeadHp << ", 你的剩余生命值: " << playerHp << std::endl;
            std::cout << "请选择操作：1. 攻击  2. 躲避  3. 喝酒  4. 若可变身则变身广智" << std::endl;
            char actionChoice;
            std::cin >> actionChoice;
            if (!isValidInput()) continue;

            switch (actionChoice) {
                case '1': {
                    int damage = 30;
                    if (rand() % 100 < 10) {
                        damage = 100;
                        std::cout << "你触发了暴击，对大头怪造成了 100 伤害！" << std::endl;
                    } else {
                        std::cout << "你对大头怪造成了30伤害！" << std::endl;
                    }
                    bigHeadHp -= damage;
                    if (bigHeadHp < 0) bigHeadHp = 0;
                    attackCount++;

                    if (bigHeadHp > 0) {
                        std::cout << "大头怪还手攻击你！请输入 2 尝试躲避。" << std::endl;
                        char dodgeChoice;
                        std::cin >> dodgeChoice;
                        if (!isValidInput()) continue;
                        if (dodgeChoice == '2') {
                            if (rand() % 100 < 60) {
                                std::cout << "你成功躲避了大头怪的攻击！" << std::endl;
                            } else {
                                playerHp -= 50;
                                if (playerHp < 0) playerHp = 0;
                                std::cout << "你躲避失败，被大头怪打中，失去 50 生命值！" << std::endl;
                            }
                        } else {
                            playerHp -= 50;
                            if (playerHp < 0) playerHp = 0;
                            std::cout << "你没有选择躲避，被大头怪打中，失去 50 生命值！" << std::endl;
                        }
                    }
                    break;
                }
                case '2': {
                    std::cout << "你选择了躲避，但只有在大头怪攻击时输入 2 才有效。本次操作无效。" << std::endl;
                    break;
                }
                case '3': {
                    if (wineCount > 0) {
                        playerHp += 200;
                        if (playerHp > 300) playerHp = 300;
                        wineCount--;
                        std::cout << "你喝了酒，回复了 200 生命值，还剩 " << wineCount << " 瓶酒。" << std::endl;
                    } else {
                        std::cout << "你没有酒了，不能再喝了！" << std::endl;
                    }
                    break;
                }
                case '4': {
                    if (canTransform &&!hasTransformed) {
                        fightAsGuangzhi(bigHeadHp, playerHp, attackCount, wineCount, canTransform);
                        hasTransformed = true;
                    } else {
                        std::cout << "你无法变身。" << std::endl;
                    }
                    break;
                }
                default:
                    std::cout << "无效的选择，请重新选择。" << std::endl;
            }
        }

        if (bigHeadHp <= 0) {
            std::cout << "你成功击败了大头怪！" << std::endl;
            break;
        } else {
            std::cout << "你被大头怪击败了！是否再次挑战？（y/n）";
            char retryChoice;
            std::cin >> retryChoice;
            if (!isValidInput()) return;
            if (retryChoice != 'y' && retryChoice != 'Y') {
                break;
            }
        }
    }
}

// 以广智形态战斗函数
void fightAsGuangzhi(int& enemyHp, int& playerHp, int& attackCount, int& wineCount, bool& canTransform) {
    int guangzhiHp = 800;
    int skillCount = 0;

    while (enemyHp > 0 && guangzhiHp > 0) {
        std::cout << "敌人剩余生命值: " << enemyHp << ", 你（广智形态）的剩余生命值: " << guangzhiHp << std::endl;
        std::cout << "请选择操作：1. 攻击  2. 躲避" << std::endl;
        char actionChoice;
        std::cin >> actionChoice;
        if (!isValidInput()) continue;

        switch (actionChoice) {
            case '1': {
                int damage = 30;
                attackCount++;
                if (attackCount % 3 == 0) {
                    damage = 200;
                    std::cout << "你使用大招，对敌人造成了 200 伤害！" << std::endl;
                } else {
                    std::cout << "你对敌人造成了 30 伤害！" << std::endl;
                }
                enemyHp -= damage;
                if (enemyHp < 0) enemyHp = 0;

                if (enemyHp > 0) {
                    int enemyDamage = 30;
                    if (rand() % 100 < 10) {
                        enemyDamage = 80;
                        std::cout << "敌人触发技能，对你造成了 80 伤害！" << std::endl;
                    } else {
                        std::cout << "敌人攻击你，造成了 30 伤害！" << std::endl;
                    }
                    std::cout << "敌人攻击你！请输入 2 尝试躲避。" << std::endl;
                    char dodgeChoice;
                    std::cin >> dodgeChoice;
                    if (!isValidInput()) continue;
                    if (dodgeChoice == '2') {
                        if (rand() % 100 < 60) {
                            std::cout << "你（广智形态）成功躲避了敌人的攻击！" << std::endl;
                        } else {
                            guangzhiHp -= enemyDamage;
                            if (guangzhiHp < 0) guangzhiHp = 0;
                            std::cout << "你（广智形态）躲避失败，被敌人打中，失去 " << enemyDamage << " 生命值！" << std::endl;
                        }
                    } else {
                        guangzhiHp -= enemyDamage;
                        if (guangzhiHp < 0) guangzhiHp = 0;
                        std::cout << "你（广智形态）没有选择躲避，被敌人打中，失去 " << enemyDamage << " 生命值！" << std::endl;
                    }
                }
                break;
            }
            case '2': {
                std::cout << "请在敌人攻击时输入 2 尝试躲避。" << std::endl;
                break;
            }
            default:
                std::cout << "无效的选择，请重新选择。" << std::endl;
        }
    }

    if (guangzhiHp <= 0) {
        std::cout << "你（广智形态）被击败，变回天命人。" << std::endl;
    }
}

// 与广智战斗函数
void fightGuangzhi(int& playerHp, int& wineCount, bool& canTransform, bool& hasDefeatedGuangzhi, bool& hasTransformed) {
    int guangzhiHp = 1500;
    int attackCount = 0;

    while (true) {
        playerHp = 300;
        wineCount = 5;
        hasTransformed = false;

        std::cout << "你遇到了广智，它有 1500 生命值，你当前生命值为 " << playerHp << "。" << std::endl;
        std::cout << "是否要和广智战斗？（y/n）";
        char fightChoice;
        std::cin >> fightChoice;
        if (!isValidInput()) return;

        if (fightChoice != 'y' && fightChoice != 'Y') {
            std::cout << "你选择了不战斗，离开了。" << std::endl;
            break;
        }

        guangzhiHp = 1500;
        while (guangzhiHp > 0 && playerHp > 0) {
            std::cout << "广智剩余生命值: " << guangzhiHp << ", 你的剩余生命值: " << playerHp << std::endl;
            std::cout << "请选择操作：1. 攻击  2. 躲避  3. 喝酒  4. 若可变身则变身广智" << std::endl;
            char actionChoice;
            std::cin >> actionChoice;
            if (!isValidInput()) continue;

            switch (actionChoice) {
                case '1': {
                    int damage = 30;
                    if (rand() % 100 < 10) {
                        damage = 100;
                        std::cout << "你触发了暴击，对广智造成了 100 伤害！" << std::endl;
                    } else {
                        std::cout << "你对广智造成了 30 伤害！" << std::endl;
                    }
                    guangzhiHp -= damage;
                    if (guangzhiHp < 0) guangzhiHp = 0;
                    attackCount++;

                    if (guangzhiHp > 0) {
                        int enemyDamage = 30;
                        if (rand() % 100 < 10) {
                            enemyDamage = 80;
                            std::cout << "广智触发技能，对你造成了 80 伤害！" << std::endl;
                        } else {
                            std::cout << "广智攻击你，造成了 30 伤害！" << std::endl;
                        }
                        std::cout << "广智攻击你！请输入 2 尝试躲避。" << std::endl;
                        char dodgeChoice;
                        std::cin >> dodgeChoice;
                        if (!isValidInput()) continue;
                        if (dodgeChoice == '2') {
                            if (rand() % 100 < 60) {
                                std::cout << "你成功躲避了广智的攻击！" << std::endl;
                            } else {
                                playerHp -= enemyDamage;
                                if (playerHp < 0) playerHp = 0;
                                std::cout << "你躲避失败，被广智打中，失去 " << enemyDamage << " 生命值！" << std::endl;
                            }
                        } else {
                            playerHp -= enemyDamage;
                            if (playerHp < 0) playerHp = 0;
                            std::cout << "你没有选择躲避，被广智打中，失去 " << enemyDamage << " 生命值！" << std::endl;
                        }
                    }
                    break;
                }
                case '2': {
                    std::cout << "你选择了躲避，但只有在广智攻击时输入 2 才有效。本次操作无效。" << std::endl;
                    break;
                }
                case '3': {
                    if (wineCount > 0) {
                        playerHp += 200;
                        if (playerHp > 300) playerHp = 300;
                        wineCount--;
                        std::cout << "你喝了酒，回复了 200 生命值，还剩 " << wineCount << " 瓶酒。" << std::endl;
                    } else {
                        std::cout << "你没有酒了，不能再喝了！" << std::endl;
                    }
                    break;
                }
                case '4': {
                    if (canTransform &&!hasTransformed) {
                        fightAsGuangzhi(guangzhiHp, playerHp, attackCount, wineCount, canTransform);
                        hasTransformed = true;
                    } else {
                        std::cout << "你无法变身。" << std::endl;
                    }
                    break;
                }
                default:
                    std::cout << "无效的选择，请重新选择。" << std::endl;
            }
        }

        if (guangzhiHp <= 0) {
            std::cout << "你成功击败了广智！你获得了变身广智的能力。" << std::endl;
            hasDefeatedGuangzhi = true;
            canTransform = true;
            break;
        } else {
            std::cout << "你被广智击败了！是否再次挑战？（y/n）";
            char retryChoice;
            std::cin >> retryChoice;
            if (!isValidInput()) return;
            if (retryChoice != 'y' && retryChoice != 'Y') {
                break;
            }
        }
    }
}

// 计算操作函数
void operation() {
    std::cout << "开始计算..." << std::endl;
    std::cout << "计算两数加减乘除请按 1  计算连加请按 2: ";
    char choice;
    std::cin >> choice;
    if (!isValidInput()) return;

    switch (choice) {
        case '1':
            twoNumberOperation();
            break;
        case '2':
            continuousOperation();
            break;
        default:
            std::cout << "错误：无效的选择！" << std::endl;
    }
}

int main() {
    std::srand(std::time(0));

    std::cout << "Hello World!" << std::endl << std::endl;
    std::printf("hello,richad i like my daddy mammy brother and coding\n");
    std::cout << std::endl;
    std::printf("i like ai robot\n");
    std::cout << std::endl;
    std::printf("I want to own a rocket\n");
    std::cout << std::endl;
    std::printf("我想拥有一艘火箭\n");
    std::cout << std::endl;

    int playerHp = 300;
    int wineCount = 5;
    bool canTransform = false;
    bool hasDefeatedGuangzhi = false;
    bool hasTransformed = false;

    while (true) {
        std::cout << "打招呼程序请按 1  计算程序请按 2  与大怪战斗请按 3  退出请按 4: ";
        char mainChoice;
        std::cin >> mainChoice;
        if (!isValidInput()) continue;

        switch (mainChoice) {
            case '1':
                welcome();
                break;
            case '2':
                std::cout << "进入计算逻辑" << std::endl;
                operation();
                break;
            case '3': {
                std::cout << "选择要挑战的大怪：1. 大头  2. 广智" << std::endl;
                char monsterChoice;
                std::cin >> monsterChoice;
                if (!isValidInput()) continue;
                switch (monsterChoice) {
                    case '1':
                        fightBigHead(playerHp, wineCount, canTransform, hasDefeatedGuangzhi, hasTransformed);
                        break;
                    case '2':
                        fightGuangzhi(playerHp, wineCount, canTransform, hasDefeatedGuangzhi, hasTransformed);
                        break;
                    default:
                        std::cout << "无效的选择，请重新选择。" << std::endl;
                }
                break;
            }
            case '4':
                std::cout << "你已退出游戏。" << std::endl;
                return 0;
            default:
                std::cout << "错误：无效的选择！" << std::endl;
        }
    }

    return 0;
}    
