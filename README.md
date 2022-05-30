# QtEmbedOutDemo
# QtEmbedOutDemo1  为使用window api直接后台启动meshlab程序所作的尝试，后台启动正常，但是在使用::ResumeThread((HANDLE)pi.hThread); 唤醒时还会打开界面一闪
# QtEmbedOutDemo   为使用QProcess进行启动，虽然设置了后台隐藏启动，但是似乎不起作用，目前让meshlab最小化显示启动，闪屏效果有一定改善，闪只在任务栏图标位置。