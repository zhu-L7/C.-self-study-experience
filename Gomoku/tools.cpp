// ʵ��PNG͸��������ͼ

#include <stdio.h>
#include <Windows.h>
#include "tools.h"

int getDelay() {
    static unsigned long long lastTime = 0;
    unsigned long long currentTime = GetTickCount();
    if (lastTime == 0) {
        lastTime = currentTime;
        return 0;
    }
    else {
        int ret = currentTime - lastTime;
        lastTime = currentTime;
        return ret;
    }
}

// ����PNGͼ��ȥ͸������
void putimagePNG(int  picture_x, int picture_y, IMAGE* picture) //xΪ����ͼƬ��X���꣬yΪY����
{
    DWORD* dst = GetImageBuffer();    // GetImageBuffer()���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬EASYX�Դ�
    DWORD* draw = GetImageBuffer();
    DWORD* src = GetImageBuffer(picture); //��ȡpicture���Դ�ָ��
    int picture_width = picture->getwidth(); //��ȡpicture�Ŀ�ȣ�EASYX�Դ�
    int picture_height = picture->getheight(); //��ȡpicture�ĸ߶ȣ�EASYX�Դ�
    int graphWidth = getwidth();       //��ȡ��ͼ���Ŀ�ȣ�EASYX�Դ�
    int graphHeight = getheight();     //��ȡ��ͼ���ĸ߶ȣ�EASYX�Դ�
    int dstX = 0;    //���Դ������صĽǱ�

    // ʵ��͸����ͼ ��ʽ�� Cp=��p*FP+(1-��p)*BP �� ��Ҷ˹���������е���ɫ�ĸ��ʼ���
    for (int iy = 0; iy < picture_height; iy++)
    {
        for (int ix = 0; ix < picture_width; ix++)
        {
            int srcX = ix + iy * picture_width; //���Դ������صĽǱ�
            int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA��͸����
            int sr = ((src[srcX] & 0xff0000) >> 16); //��ȡRGB���R
            int sg = ((src[srcX] & 0xff00) >> 8);   //G
            int sb = src[srcX] & 0xff;              //B
            if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
            {
                dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //���Դ������صĽǱ�
                int dr = ((dst[dstX] & 0xff0000) >> 16);
                int dg = ((dst[dstX] & 0xff00) >> 8);
                int db = dst[dstX] & 0xff;
                draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //��ʽ�� Cp=��p*FP+(1-��p)*BP  �� ��p=sa/255 , FP=sr , BP=dr
                    | ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //��p=sa/255 , FP=sg , BP=dg
                    | (sb * sa / 255 + db * (255 - sa) / 255);              //��p=sa/255 , FP=sb , BP=db
            }
        }
    }
}

// ������ y <0 �Լ�x<0���κ����
void putimagePNG2(int x, int y, IMAGE* picture) {
    IMAGE imgTmp;
    if (y < 0) {
        SetWorkingImage(picture);
        getimage(&imgTmp, 0, -y,
            picture->getwidth(), picture->getheight() + y);
        SetWorkingImage();
        y = 0;
        picture = &imgTmp;
    }

    if (x < 0) {
        SetWorkingImage(picture);
        getimage(&imgTmp, -x, 0, picture->getwidth() + x, picture->getheight());
        SetWorkingImage();
        x = 0;
        picture = &imgTmp;
    } 

    putimagePNG(x, y, picture);
}

// ������ y <0 �Լ�y>0���κ����
void putimagePNG2(int x, int y, int winWidth, IMAGE* picture) {
    IMAGE imgTmp;
    if (y < 0) {
        SetWorkingImage(picture);
        getimage(&imgTmp, 0, -y,
            picture->getwidth(), picture->getheight() + y);
        SetWorkingImage();
        y = 0;
        picture = &imgTmp;
    }

    if (x < 0) {
        SetWorkingImage(picture);
        getimage(&imgTmp, -x, 0, 
            picture->getwidth()< winWidth? picture->getwidth(): winWidth, 
            picture->getheight());
        SetWorkingImage();
        x = 0;
        picture = &imgTmp;
    }
    else if (x >= winWidth) {
        return;
    }
    else if (x > winWidth-picture->getwidth()) {
        SetWorkingImage(picture);
        getimage(&imgTmp, 0, 0, winWidth - x, picture->getheight());
        SetWorkingImage();
        picture = &imgTmp;
    }

    putimagePNG(x, y, picture);
}