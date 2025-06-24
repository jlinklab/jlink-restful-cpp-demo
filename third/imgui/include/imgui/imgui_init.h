#pragma once

#include <string>
#include <vector>
#include <functional>
#include "imgui/permissions.h"

using StrVec = std::vector<std::string>;
using IntVec = std::vector<int>;
using PermissionCB = std::function<void(const StrVec&, const IntVec&)>;

namespace ImGui{

/************UI显示*************/
#ifdef WIN32
int show_window_directx9(bool block = false);
int show_window_directx10(bool block = false);
int show_window_directx11(bool block = false);
int show_window_directx12(bool block = false);
int show_window_opengl3(bool block = false);
#elif defined(OS_MAC)
// opengl2渲染
int show_window_opengl2(bool block = false);
#elif defined(__ANDROID__)
// opengl3渲染
int show_window_opengl3();
// 获取当前窗口
void* get_native_window();
// 获取附件内容, file_name是相对于assets的路径
int get_asset_data(const std::string& file_name, std::string& out);
// 获取内部数据目录, /data/data/app_name/files
std::string get_internal_data_dir();
// 获取外部数据目录, /sdcard/data/app_name/files
std::string get_external_data_dir();
// 检查是否拥有某权限
bool has_permission(const std::string& name);
// 请求权限
// PERMISSION_DENIED = -1;
// PERMISSION_GRANTED = 0;
int request_permission(const std::vector<std::string>& names, PermissionCB func);
#endif
/*******************************/

/*************子UI**************/
class IMWidget
{
public:
    IMWidget();
    virtual ~IMWidget();
    virtual void showWindow() = 0;
    // 继承的对象构造时主动调用
    void addWidget();
    // 继承的对象析构时主动调用
    void removeWidget();
};

}
