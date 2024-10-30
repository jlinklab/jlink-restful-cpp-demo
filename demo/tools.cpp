#include <chrono>
#include <fstream>
#include <thread>
#include "fmt/core.h"
#include "openssl/md5.h"
#include "tools.h"

// 设备状态菜单
void deviceStatusMenu(JLinkClient& client, JLinkDevice& device, JLinkDeveloper& developer)
{
    bool running = true;
    int choice_num;

    while (running) {
        std::cout << "**************设备状态相关****************" << std::endl;
        std::cout << "1. 获取设备状态" << std::endl;
        std::cout << "2. 设备保活" << std::endl;
        std::cout << "3. 获取系统信息" << std::endl;
        std::cout << "4. 获取设备列表" << std::endl;
        std::cout << "5. 返回上一级" << std::endl;
        std::cin >> choice_num;

        switch (choice_num) {
        case 1:
            device.getDeviceStatus();
            break;
        case 2:
            device.deviceAlive();
            break;
        case 3:
            device.getSystemInfo();
            break;
        case 4:
            developer.getDeviceList();
            break;
        case 5:
            running = false;
            break;
        default:
            std::cout << "请输入正确选项(1~5)" << std::endl;
            break;
        }
    }
}

// 获取设备信息菜单
void deviceInfoMenu(JLinkClient& client, JLinkDevice& device, JLinkDeveloper& developer)
{
    bool running = true;
    int choice_num;

    while (running) {
        std::cout << "**************设备信息相关****************" << std::endl;
        std::cout << "1. 获取4G信号信息" << std::endl;
        std::cout << "2. 获取NVR全通道RTMP信息" << std::endl;
        std::cout << "3. 返回上一级" << std::endl;
        std::cin >> choice_num;

        switch (choice_num) {
        case 1:
            device.getDevice4GInfo();
            break;
        case 2:
            device.getDeviceRTMPALLInfo();
            break;
        case 3:
            running = false;
            break;
        default:
            std::cout << "请输入正确选项(1~3)" << std::endl;
            break;
        }
    }
}

// 设备能力集菜单
void deviceCapabilitySetMenu(JLinkClient& client, JLinkDevice& device, JLinkDeveloper& developer)
{
    bool running = true;
    int choice_num;

    while (running) {
        std::cout << "**************设备能力集相关****************" << std::endl;
        std::cout << "1. 区域遮挡能力" << std::endl;
        std::cout << "2. 移动侦测属性能力" << std::endl;
        std::cout << "3. 摄像机参数能力" << std::endl;
        std::cout << "4. 对讲音频属性能力" << std::endl;
        std::cout << "5. 支持语言能力" << std::endl;
        std::cout << "6. 智能分析能力" << std::endl;
        std::cout << "7. 主辅码流录像能力" << std::endl;
        std::cout << "8. 返回上一级" << std::endl;
        std::cin >> choice_num;

        switch (choice_num) {
        case 1:
            device.getDeviceBlindCapAbility();
            break;
        case 2:
            device.getDeviceMotionAreaAblity();
            break;
        case 3:
            device.getDeviceCamerAblity();
            break;
        case 4:
            device.getDeviceTalkAudioAblity();
            break;
        case 5:
            device.getDeviceLanuageAbility();
            break;
        case 6:
            device.getDeviceIntelligentAbility();
            break;
        case 7:
            device.getDeviceSupportExtRecordAbility();
            break;
        case 8:
            running = false;
            break;
        default:
            std::cout << "请输入正确选项(1~8)" << std::endl;
            break;
        }
    }
}

// 设备配置菜单
void deviceConfMenu(JLinkClient& client, JLinkDevice& device, JLinkDeveloper& developer)
{
    bool running = true;
    int choice_num;

    while (running) {
        std::cout << "**************设备配置相关****************" << std::endl;
        std::cout << "1. 获取设备通道配置" << std::endl;
        std::cout << "2. 获取外接云台配置" << std::endl;
        std::cout << "3. 获取网络基础配置" << std::endl;
        std::cout << "4. 获取通用配置" << std::endl;
        std::cout << "5. 获取基本参数配置" << std::endl;
        std::cout << "6. 返回上一级" << std::endl;
        std::cin >> choice_num;

        switch (choice_num) {
        case 1:
            device.getDeviceChnnelTitleConf();
            break;
        case 2:
            device.getDeviceExternalPTZ();
            break;
        case 3:
            device.getDeviceNetBasicConf();
            break;
        case 4:
            device.getDeviceGeneralConf();
            break;
        case 5:
            device.getDeviceCameraParamConf();
            break;
        case 6:
            running = false;
            break;
        default:
            std::cout << "请输入正确选项(1~6)" << std::endl;
            break;
        }
    }
}

// 验证密码是否符合要求
bool isValidPassword(const std::string& password)
{
    bool hasUpper = false;   // 检查大写字母
    bool hasLower = false;   // 检查小写字母
    bool hasDigit = false;   // 检查数字
    bool hasSpecial = false; // 检查特殊字符

    for (char c : password) {
        if (std::isupper(c))
            hasUpper = true; // 是否大写字母
        else if (std::islower(c))
            hasLower = true; // 是否小写字母
        else if (std::isdigit(c))
            hasDigit = true; // 是否数字
        else if (!std::isalnum(c))
            hasSpecial = true; // 是否特殊字符
    }

    // 返回检查结果，确保满足所有条件
    return hasUpper && hasLower && hasDigit && hasSpecial && password.length() >= 8; // 至少8位长
}

// 发送验证码
SendCaptchaResponse sendCode(JLinkDeveloper& developer, std::string phoneNum, std::string type)
{
    // 验证码间隔2分钟
    std::this_thread::sleep_for(std::chrono::minutes(2));
    // 发送验证码
    SendCaptcha sendCaptcha;

    sendCaptcha.phone = phoneNum;
    sendCaptcha.type = type;
    SendCaptchaResponse resp = developer.sendCaptcha(sendCaptcha);

    return resp;
}

// 用户账号系统相关
void userAccountMenu(JLinkClient& client, JLinkDevice& device, JLinkDeveloper& developer)
{
    // 用户注册相关参数
    std::string userName_reg;
    std::string passWord_reg;
    std::string confirmPass_reg;
    std::string phoneNum_reg;
    std::string vercode_reg;
    std::string type;

    // 用户登录相关参数
    std::string userName_Login;
    std::string passWord_Login;

    // 修改密码相关参数
    std::string id;
    std::string phoneNum_modify;
    std::string vercode_modify;
    std::string new_pass;
    std::string confirmPass_modify;

    // 用户id
    std::string userid;

    // 用户注册(无需登录)
    std::string phoneNum_unlog;
    std::string vercode_modify_unlog;

    SendCaptchaResponse resp_0;
    GetAMSUserInfoResponse resp_1;
    UserModifyPassUnLoginResponse resp_2;

    // 手机号注册
    PhoneRegInfo phoneReg;

    // 用户登录
    UserLoginInfo userLogin;

    // 修改密码
    ModifyPass modifyPass;

    // 修改密码(无需登录)
    ModifyPass_UnLogin modifyPass_unlog;

    bool running = true;
    int choice_num;

    while (running) {
        std::cout << "**************用户账号系统相关****************" << std::endl;
        std::cout << "1. 手机用户注册" << std::endl;
        std::cout << "2. 用户登录" << std::endl;
        std::cout << "3. 手机验证码修改密码" << std::endl;
        std::cout << "4. 返回上一级" << std::endl;
        std::cin >> choice_num;

        switch (choice_num) {
        case 1:
            std::cout << "请输入用户名：";
            std::cin >> userName_reg;
            phoneReg.name = userName_reg;

            std::cout << "请输入密码：";
            std::cin >> passWord_reg;

            // 验证密码
            if (!isValidPassword(passWord_reg)) {
                std::cout << "密码必须包含大写字母、小写字母、特殊字符和数字，并且长度至少为8位，请重试。" << std::endl;
                continue;
            }
            phoneReg.password = passWord_reg;

            std::cout << "请确认密码：";
            std::cin >> confirmPass_reg;
            // 检查密码是否匹配
            if (passWord_reg != confirmPass_reg) {
                std::cout << "两次输入的密码不匹配，请重试。" << std::endl;
                continue;
            }
            phoneReg.confirm_pass = confirmPass_reg;

            std::cout << "请输入手机号：";
            std::cin >> phoneNum_reg;
            phoneReg.phone = phoneNum_reg;

            // 发送验证码
            resp_0 = sendCode(developer, phoneNum_reg, "re");
            if (resp_0.msg == "REG_PHONE_EXIST") {
                std::cout << "账号已存在" << std::endl;
            } else {
                std::cout << "验证码已发送，请输入手机验证码：";
            }
            std::cin >> vercode_reg;

            phoneReg.verify_code = vercode_reg;
            developer.regWithPhoneCode(phoneReg);
            break;
        case 2:
            std::cout << "请输入用户名(手机号)：";
            std::cin >> userName_Login;
            userLogin.account = userName_Login;

            std::cout << "请输入密码：";
            std::cin >> passWord_Login;
            userLogin.password = passWord_Login;

            developer.userLogin(userLogin);
            break;
        case 3:
            std::cout << "请输入手机号：";
            std::cin >> phoneNum_unlog;
            modifyPass_unlog.phone = phoneNum_unlog;

            // 验证码发送间隔为2分钟
            sendCode(developer, phoneNum_unlog, "fp");

            std::cout << "验证码已发送，请输入手机验证码：";
            std::cin >> vercode_modify_unlog;
            modifyPass_unlog.verify_code = vercode_modify_unlog;
            resp_2 = developer.modifyPassUnlogin(modifyPass_unlog);
            modifyPass.id = resp_2.data.userId;

            std::cout << "请输入新密码：";
            std::cin >> new_pass;
            modifyPass.new_pass = new_pass;

            std::cout << "请确认密码：";
            std::cin >> confirmPass_modify;
            modifyPass.verify_code = vercode_modify;

            std::cout << "请输入手机号：";
            std::cin >> phoneNum_modify;
            modifyPass.phone = phoneNum_modify;

            sendCode(developer, phoneNum_modify, "fp");

            std::cout << "验证码已发送，请输入手机验证码：";
            std::cin >> vercode_modify;
            modifyPass.verify_code = vercode_modify;

            developer.modifyPass(modifyPass);
            break;
        case 4:
            running = false;
            break;
        default:
            std::cout << "请输入正确选项(1~4)" << std::endl;
            break;
        }
    }
}

// 主菜单
void mainMenu(JLinkClient& client, JLinkDevice& device, JLinkDeveloper& developer)
{
    bool running = true;
    int choice_num;

    while (running) {
        std::cout << "**************设备绑定登录****************" << std::endl;
        std::cout << "操作之前请先登录，首次登录前先进行设备绑定" << std::endl;
        std::cout << "1. 设备绑定" << std::endl;
        std::cout << "2. 设备登录" << std::endl;
        std::cout << "3. 设备状态相关" << std::endl;
        std::cout << "4. 设备信息相关" << std::endl;
        std::cout << "5. 获取设备能力集相关" << std::endl;
        std::cout << "6. 设备配置相关" << std::endl;
        std::cout << "7. 用户账号相关" << std::endl;
        std::cout << "8. 设备登出" << std::endl;
        std::cout << "9. 设备解绑" << std::endl;
        std::cout << "10. 退出" << std::endl;
        std::cin >> choice_num;

        switch (choice_num) {
        case 1:
            device.deviceBind();
            break;
        case 2:
            device.getDeviceToken();
            device.deviceLogin();
            break;
        case 3:
            deviceStatusMenu(client, device, developer);
            break;
        case 4:
            deviceInfoMenu(client, device, developer);
            break;
        case 5:
            deviceCapabilitySetMenu(client, device, developer);
            break;
        case 6:
            deviceConfMenu(client, device, developer);
            break;
        case 7:
            userAccountMenu(client, device, developer);
            break;
        case 8:
            device.deviceLogout();
            break;
        case 9:
            device.deviceUnBind();
            break;
        case 10:
            running = false;
            break;
        default:
            std::cout << "请输入正确选项(1~10)" << std::endl;
            break;
        }
    }
}

void getParams(Params& params)
{
    std::ifstream file("../../config.ini");
    if (!file) {
        std::cerr << "文件打开失败" << std::endl;
    }

    try {
        std::string line;
        while (std::getline(file, line)) {
            size_t pos = line.find('=');
            if (pos == std::string::npos)
                continue; // 跳过没有等号的行

            // 提取键和值
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);

            if (key == "uuid") {
                params._uuid = value;
            } else if (key == "app_key")
                params._app_key = value;
            else if (key == "app_secret")
                params._app_secret = value;
            else if (key == "movecard")
                params._movecard = std::stoi(value); // string转int
            else if (key == "dev_sn")
                params._dev_sn = value;
            else if (key == "dev_user_name")
                params._dev_user_name = value;
            else if (key == "dev_password")
                params._dev_password = value;
        }
    } catch (...) {
        std::cerr << "参数获取失败，请检查参数" << std::endl;
    }
}
