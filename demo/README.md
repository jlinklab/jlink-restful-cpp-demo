# Demo使用说明

## 📁 文件结构说明

``` text
项目根目录/
├── Config/				        # imgui配置文件，将这个文件夹的两个文件拖出放到程序工作目录
├── Language/                   # 中英文语言文件，Demo支持中英文
├── Public/                     # 封装的一些基础工具
├── Source/            		    # 若未配置环境变量，需将 ffmpeg 放入此处
├── CMakeLists.txt
├── config.ini					# 配置文件，将里面信息填写好后放到程序工作目录 
└── README.md					# 本文档
```

## ✅ 音视频对讲环境准备

1. **操作系统要求：**
   - Windows 10 或更高版本
2. **依赖工具（需加入系统环境变量 `PATH`）：**
   - [ffmpeg](https://ffmpeg.org/download.html)
   - [ffplay](https://ffmpeg.org/ffplay.html)
3. **其他工具**
   
   - [imgui](https://github.com/ocornut/imgui) 在音视频对讲demo中用到
   
1. **本Demo设备名称：**

   - 音频设备：`立体声混音 (Realtek(R) Audio)`
   - 视频设备：`USB CAMERA`

   > 如何获取自己的音视频设备名称：
   >
   > 开始菜单搜索“设备管理器”，找到音频输入和输出设置和照相机选项即可找到自己的设备名称
   >
   > 如需更换设备名称，请在源代码 ./Source—Demo.cpp—VideoTalk::showWindow()中修改

## ⚙️ 配置步骤

- **拷贝配置文件**
  - 将本目录下的 `Config` 文件夹**中的所有内容**（`imgui.ini`、`msyh.ttc` 文件）**复制**或**移动**至程序的工作目录（即与 `.exe` 同目录）。
  - 将本目录下的` Language`**文件夹**直接**复制**或**移动**至程序的工作目录（即与 `.exe` 同目录）。
  - 将本目录下的`config.ini`文件内容填写好后**复制**或**移动**至程序的解决方案根目录（即与 `.sln` 同目录）。
- **如何填写config.ini**
   打开 `config.ini` 文件，根据实际设备进行参数填写。字段包括：

```text
以下参数获取参考
https://docs.jftech.com/docs?menusId=2531aba7e2d84e13ad8ce977007922f3&siderId=6aad821475674da4afc8bed5cd50f98d&lang=zh
uuid=
app_key=
app_secret=
movecard=
以下参数为杰峰摄像头的设备序列号、设备名称、设备密码，需购买杰峰摄像头
dev_sn=
dev_user_name=
dev_password=
```