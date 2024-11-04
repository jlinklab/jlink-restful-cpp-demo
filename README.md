# OpenApi SDK V3 Demo

This is a simple library for accessing platform and devices, you can learn more from https://docs.jftech.com/docs.



## Open Source

This library is Open Source and is distributed under an MIT-like [license](./LICENSE);




## Project Structure

```
.
├─demo 						// demo
├─include					// include files
│  └─jlink-restful-cpp
│      ├─message			// mqtt message
│      ├─request			// http request
│      └─response			// http response
├─msvc						// msvc solution
├─src						// src
└─third						// third libraries
    ├─curl					// libcurl for http
    ├─fmt					// fmt for string operation
    ├─json					// json library
    ├─mqtt					// mqtt library
    └─openssl				// openssl library
```



## How to Build

### Windows

use `msvc/jlink-restful-cpp-demo/jlink-restful-cpp.sln`


### Linux

```
mkdir build && cd build
cmake .. && make
```



## Usage

### Initialization JLinkClient

> uuid, app_key, app_secret, movecard Obtained from (open.jftech.com).

```cpp
DeveloperInfo developer_info{uuid, app_key, app_secret, movecard};
JLinkClient client(developer_info);
```

### Initialization JLinkDeveloper

```cpp
JLinkDeveloper developer(&client, developer_info);
```

### Initialization JLinkDevice

> device_sn is the device serial number
> device_user_name indicates the device login username
> device_password indicates the device login password

```cpp
JLinkDevice device(&client, device_sn, device_user, device_password);
```
### Device Bind(The v3 version requires the device to be bound to the user's account in order to operate)

```cpp
DeviceBindResponse resp = device.deviceBind();
```

### Device UnBind

```cpp
DeviceUnBindResponse resp = device.deviceUnBind();
```

### Get Device List

```cpp
DeviceListResponse resp = developer.getDeviceList();
```


### Get Device Token

```cpp
DeviceTokenResponse resp = device.getDeviceToken();
```

### Get Device Status

```
DeviceStatusResponse resp = device.getDeviceStatus();
```


### Device Login

> Login with device_user_name and device_password

```
DeviceLoginResponse resp = device.deviceLogin();
```

### Get Device Information

> Take obtaining system information as an example

```
DeviceInfoResponse resp = device.getSystemInfo();
```

### Get Device Configuration

> Take obtaining the device general configuration as an example

```
DeviceGeneralConfResponse resp = device.getDeviceGeneralConf();
```

### Set Device Configuration

> Take the device general configuration as an example enable: enable auto logout;

```
SetGeneralRequest resq = {};
resq.auto_logout = true;
DeviceSetGeneralConfResponse resp = device.setDeviceGeneralConf(resq);
```

### Device Keepalive

```
DeviceAliveResponse resp = device.deviceAlive();
```

### Device Operate

> Take the PTZ direction control as an example

```
DirectionControlRequest resq = {};
resq.Command = "";
DeviceDirectionControlResponse resp = device.deviceDirectionControl();
```

### Get the liveStream

> Take obtaining the live address of the main stream of the device in hls format as an example;
> rs Account represents the user registered by the open platform through the RS interface, 
> and rs Pass represents the user password registered by the open platform through the RS interface

```
LiveStreamRequest resq = {};
resq.mediaType = "hls";
resq.channel = "0";
resq.stream = "1";
resq.protocol = "ts";
resq.username = "admin";
resq.password = "123456";
DeviceLiveStreamResponse resp = device.deviceLiveStream(resq);
```

### Device Snapshot

>  Capture a picture of a channel, The channel number defaults to 0

```
SnapRequest resq = {}
resq.Channel = 0;
resq.PicType = 0;
DeviceSnapResponse resp = device.deviceSnap(req);
```


