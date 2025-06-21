#include <thread>
#include "imgui/imgui.h"
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

void mainMenu(JLinkClient* client, JLinkDevice* device, JLinkDeveloper* developer)
{
    g_client = client;
    g_device = device;
    g_developer = developer;

    std::string path = GetLanguagePath();
    std::string finalPath = path + "\\Language\\";
    XLanguage::InitLanguage(finalPath.c_str(), "cn");
    std::cout << "======操作前请先进行设备登录======" << std::endl;
    CMyFunctions mainFuns("MainMenu", "QuitApp");
    mainFuns.SetFunction("ChoiceLanguage", 'a', ChoiceLanguage);
    mainFuns.SetFunction("DeviceBind", 'b', DeviceBind);
    mainFuns.SetFunction("DeviceLogin", 'c', DeviceLogin);
    mainFuns.SetFunction("DeviceStatus", 'd', DeviceStatus);
    mainFuns.SetFunction("DeviceInfo", 'e', DeviceInfo);
    mainFuns.SetFunction("GetDeviceCapability", 'f', GetDeviceCapability);
    mainFuns.SetFunction("DeviceConfiguration", 'g', DeviceConfiguration);
    mainFuns.SetFunction("UserAccount", 'h', UserAccount);
    mainFuns.SetFunction("DeviceLogout", 'i', DeviceLogout);
    mainFuns.SetFunction("DeviceUnbind", 'j', DeviceUnbind);
    mainFuns.SetFunction("音视频对讲demo", 'k', DeviceVideoTalkDemo);
    mainFuns.ShowFuns();
}

int DeviceVideoTalkDemo()
{
    std::shared_ptr<VideoTalk> videoTalk = std::make_shared<VideoTalk>();

    DecoderPramAblity decoderPramAblity = g_device->deviceGetDecodeAblity();
    std::string audioCodePlayer = decoderPramAblity.data.decoder_pram.audio[0].enc;
    int audioAccuracyPlayer = decoderPramAblity.data.decoder_pram.audio[0].sb[0];
    int audioKHZPlayer = decoderPramAblity.data.decoder_pram.audio[0].sr[0];

    std::string videoPlayer = decoderPramAblity.data.decoder_pram.video[0].enc;
    int fpsPlayer = decoderPramAblity.data.decoder_pram.video[0].res[0].fps;
    int widthPlayer = decoderPramAblity.data.decoder_pram.video[0].res[0].w;
    int heightPlayer = decoderPramAblity.data.decoder_pram.video[0].res[0].h;

    // 实时流请求参数
    LiveStreamRequest liveStreamRequest;
    liveStreamRequest.channel = "0";
    liveStreamRequest.stream = "0";
    liveStreamRequest.protocol = "hls-ts";
    liveStreamRequest.videoCode = "h264";
    liveStreamRequest.audioCode = "aac";
    liveStreamRequest.expireTime = "1751212800000";

    // 视频对讲流请求参数
    VideoTalkRequest videoTalkRequest;
    videoTalkRequest.protocol = "rtmp";
    videoTalkRequest.channel = "0";
    videoTalkRequest.audioCodePlayer = audioCodePlayer;
    videoTalkRequest.audioAccuracyPlayer = std::to_string(audioAccuracyPlayer);
    videoTalkRequest.audioKHZPlayer = std::to_string(audioKHZPlayer);
    videoTalkRequest.videoPlayer = videoPlayer;
    videoTalkRequest.widthPlayer = std::to_string(widthPlayer);
    videoTalkRequest.heightPlayer = std::to_string(heightPlayer);
    videoTalkRequest.fpsPlayer = std::to_string(fpsPlayer);

    videoTalk->startVideoTalk(liveStreamRequest, videoTalkRequest);

    return 0;
}

VideoTalk::VideoTalk()
{
    addWidget();
}

int VideoTalk::startVideoTalk(const LiveStreamRequest& liveStreamRequest, const VideoTalkRequest& videoTalkRequest)
{
    // 实时视频流
    DeviceLiveStreamResponse responseLiveStream = g_device->deviceLiveStream(liveStreamRequest);
    _video_url = responseLiveStream.data.url;

    // 视频对讲流
    DeviceVideotalkResponse responseVideotalk = g_device->deviceVideotalk(videoTalkRequest);
    _video_talk_url = responseVideotalk.data.url;

    ImGui::show_window_directx9(true);

    return 0;
}

void VideoTalk::showWindow()
{
    // 视频流url
    static char video_buffer[2048] = {0};
    strncpy(video_buffer, _video_url.c_str(), sizeof(video_buffer) - 1);
    video_buffer[sizeof(video_buffer) - 1] = '\0';

    // 对讲流url
    static char video_talk_buffer[2048] = {0};
    strncpy(video_talk_buffer, _video_talk_url.c_str(), sizeof(video_talk_buffer) - 1);
    video_talk_buffer[sizeof(video_talk_buffer) - 1] = '\0';

    if (ImGui::Begin("音视频对讲")) {
        ImGui::Text("本demo环境：ffplay、ffmpeg(加入环境变量)");
        ImGui::Text("音频设备：立体声混音 (Realtek(R) Audio)、");
        ImGui::Text("视频设备：USB CAMERA");
        ImGui::Text("===========================");
        ImGui::Text("视频流 URL：");
        ImGui::Text("确定播放后关注命令行动态，请稍后...");
        // 只读，不能修改...
        //ImGui::Text("输入视频流 URL：");
        //ImGui::PushTextWrapPos(0.0f);
        //ImGui::TextWrapped("%s", input_url);
        //ImGui::PopTextWrapPos();

        ImGui::SetNextItemWidth(300.0f);
        ImGui::InputText("##url", video_buffer, sizeof(video_buffer));

        if (ImGui::Button("确定播放")) {
            std::string cmd = fmt::format("ffplay.exe -x 480 -y 360 \"{}\"", video_buffer);
            std::thread([=]() { system(cmd.c_str()); }).detach();
        }

        ImGui::Text("视频对讲流 URL：");
        ImGui::Text("开始对讲后关注命令行动态，请稍后...");

        ImGui::SetNextItemWidth(300.0f);
        ImGui::InputText("##url", video_talk_buffer, sizeof(video_talk_buffer));

        if (ImGui::Button("开始对讲")) {
            std::string video_dev = "USB CAMERA";
            std::string audio_dev = "立体声混音 (Realtek(R) Audio)";
            std::string video_talk_url = video_talk_buffer;

            std::string cmd = fmt::format("ffmpeg -f dshow -i video=\"{}\":audio=\"{}\" "
                                          "-ac 1 -ar 8000 -c:a pcm_alaw "
                                          "-c:v libx264 -preset ultrafast -tune zerolatency "
                                          "-f flv \"{}\"",
                                          video_dev,
                                          audio_dev,
                                          video_talk_url);

            std::thread([=]() { system(cmd.c_str()); }).detach();
        }

        ImGui::End();
    }
}