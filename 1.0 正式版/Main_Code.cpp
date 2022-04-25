#include<bits/stdc++.h>
#include<windows.h>
#define KEY_DOWN(VK_NONAME) (GetAsyncKeyState(VK_NONAME)&0x8000)
using namespace std;
int main()
{
	int t,k;
	bool f=0;
	puts("请输入每次鼠标点击时间间隔，1000 为一秒：");
	cin>>t;
	if(t<5) t=5;
	puts("请输入鼠标翻倍的倍数：");
	cin>>k;
	k--;
	while(1){
		Sleep(50);
		if(KEY_DOWN(VK_MBUTTON)){
			if(!f){
				f=1;
				continue;
			}
			Sleep(200);
			while(1){
				if(KEY_DOWN(VK_MBUTTON)){
					f=0;
					break;	
				}
			}
			f=0;
		}
		if(KEY_DOWN(VK_LBUTTON)){
			Sleep(t);
			for(int i=1;i<=k;i++){
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
				Sleep(15);
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
				Sleep(t);
			}
		}else if(KEY_DOWN(VK_RBUTTON)){
			Sleep(t);
			for(int i=1;i<=k;i++){
				mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
				Sleep(10);
				mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
				Sleep(t);
			}
		}
	}
	return 0;
}

