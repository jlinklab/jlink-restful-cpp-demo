#include "Demo.h"

std::string GetLanguagePath()
{
    char path[MAX_PATH];
    GetModuleFileNameA(NULL, path, MAX_PATH);
    std::string exePath = path;
    return exePath.substr(0, exePath.find_last_of("\\/")) + '\\';
}

int ChoiceLanguage()
{
    CMyFunctions myFuns(__FUNCTION__, "Backup");
    myFuns.SetFunction("SelectedChinse");
    myFuns.SetFunction("Change To English");

    int nCmd = myFuns.ShowFuns() - 'a';
    std::string sLanguage[] = {Language_Chinese, Language_English};
    if (nCmd >= 0 && nCmd <= 1) {
        std::string path = GetLanguagePath();
        std::string finalPath = path + "Language\\";
        XLanguage::InitLanguage(finalPath.c_str(), sLanguage[nCmd].c_str());
    }
    return 0;
}
