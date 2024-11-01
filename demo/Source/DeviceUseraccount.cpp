#include <chrono>
#include <thread>
#include "Demo.h"

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

int UserAccount()
{
    // 显示菜单
    CMyFunctions myFuns(__FUNCTION__, "Backup");
    myFuns.SetFunction("MobileUserRegistration", 'a', phongReg);
    myFuns.SetFunction("UserLogin", 'b', userLog);
    myFuns.SetFunction("ChangePasswordByMobileVerificationCode", 'c', modifyUserPass);
    myFuns.ShowFuns();

    return 0;
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
SendCaptchaResponse sendCode(JLinkDeveloper* developer, std::string phoneNum, std::string type)
{
    // 验证码间隔2分钟
    std::this_thread::sleep_for(std::chrono::minutes(2));
    // 发送验证码
    SendCaptcha sendCaptcha;

    sendCaptcha.phone = phoneNum;
    sendCaptcha.type = type;
    SendCaptchaResponse resp = developer->sendCaptcha(sendCaptcha);

    return resp;
}

// 手机号注册
int phongReg()
{
    std::cout << XLAN("Please enter your username:") << std::endl;
    std::cin >> userName_reg;
    getchar();

    phoneReg.name = userName_reg;

    std::cout << XLAN("Please enter your password:") << std::endl;
    std::cin >> passWord_reg;
    getchar();

    // 验证密码
    if (!isValidPassword(passWord_reg)) {
        std::cout << XLAN("The password must contain uppercase letters, lowercase letters, special characters and "
                          "numbers and be at least 8 characters long. Please try again.");

        return -1;
    }
    phoneReg.password = passWord_reg;

    std::cout << XLAN("Please confirm your password:") << std::endl;
    std::cin >> confirmPass_reg;
    getchar();

    // 检查密码是否匹配
    if (passWord_reg != confirmPass_reg) {
        std::cout << XLAN("The passwords you entered twice do not match. Please try again.") << std::endl;

        return -1;
    }
    phoneReg.confirm_pass = confirmPass_reg;

    std::cout << XLAN("Please enter your phone number:") << std::endl;
    std::cin >> phoneNum_reg;
    getchar();
    phoneReg.phone = phoneNum_reg;

    // 发送验证码
    resp_0 = sendCode(g_developer, phoneNum_reg, "re");
    std::cout << "正在发送验证码，请稍后……" << std::endl;
    if (resp_0.msg == "REG_PHONE_EXIST") {
        std::cout << XLAN("Account already exists");
        return -1;
    } else {
        std::cout << XLAN("The verification code has been sent, Please enter the mobile verification code:");
        std::cin >> vercode_reg;
        getchar();
    }

    phoneReg.verify_code = vercode_reg;
    g_developer->regWithPhoneCode(phoneReg);

    return 0;
}

// 用户登录
int userLog()
{
    std::cout << XLAN("Please enter your username(mobile phone number):") << std::endl;
    std::cin >> userName_Login;
    getchar();
    userLogin.account = userName_Login;

    std::cout << XLAN("Please enter your password:") << std::endl;
    std::cin >> passWord_Login;
    getchar();
    userLogin.password = passWord_Login;

    g_developer->userLogin(userLogin);

    return 0;
}

//修改密码
int modifyUserPass()
{
    std::cout << XLAN("Please enter your phone number:") << std::endl;
    std::cin >> phoneNum_unlog;
    modifyPass_unlog.phone = phoneNum_unlog;

    // 验证码发送间隔为2分钟
    sendCode(g_developer, phoneNum_unlog, "fp");
    std::cout << XLAN("Captcha is being sent, please wait...") << std::endl;

    std::cout << XLAN("The verification code has been sent, Please enter the mobile verification code:");
    std::cin >> vercode_modify_unlog;
    getchar();
    modifyPass_unlog.verify_code = vercode_modify_unlog;
    resp_2 = g_developer->modifyPassUnlogin(modifyPass_unlog);
    modifyPass.id = resp_2.data.userId;

    std::cout << XLAN("Please enter new password:") << std::endl;
    std::cin >> new_pass;
    getchar();
    modifyPass.new_pass = new_pass;

    std::cout << XLAN("Please confirm your password:") << std::endl;
    std::cin >> confirmPass_modify;
    getchar();
    modifyPass.verify_code = vercode_modify;

    std::cout << XLAN("Please enter your phone number:") << std::endl;
    std::cin >> phoneNum_modify;
    getchar();
    modifyPass.phone = phoneNum_modify;

    sendCode(g_developer, phoneNum_modify, "fp");
    std::cout << XLAN("Captcha is being sent, please wait...") << std::endl;

    std::cout << XLAN("The verification code has been sent, Please enter the mobile verification code:") << std::endl;
    std::cin >> vercode_modify;
    getchar();
    modifyPass.verify_code = vercode_modify;

    g_developer->modifyPass(modifyPass);

    return 0;
}
