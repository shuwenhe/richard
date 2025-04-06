#include <iostream>
#include <limits>

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
    while (true) {
        std::cout << "打招呼程序请按 1  计算程序请按 2  退出请按 3: ";
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
            case '3':
                std::cout << "你已退出程序。" << std::endl;
                return 0;
            default:
                std::cout << "错误：无效的选择！" << std::endl;
        }
    }
    return 0;
}    
