
#include <iostream>
using namespace std;
#include "./gdal/gdal_priv.h"
#pragma comment(lib, "gdal_i.lib")

int main()
{
	GDALDataset* poSrcDS;
	GDALDataset* poDstDS;
	int imgXlen,imgYlen,tmpXlen,tmpYlen,StartX,StartY;
	//��ɫ--------------------------
	char* srcPath = "square.jpg";
	char* dstPath = "res.tif";
	GByte* buffTmp;
	int i,j, bandNum;
	GDALAllRegister();
	poSrcDS = (GDALDataset*)GDALOpenShared(srcPath,GA_ReadOnly);
	imgXlen = poSrcDS->GetRasterXSize();
	imgYlen = poSrcDS->GetRasterYSize();
	bandNum = poSrcDS->GetRasterCount();
	cout << "Image X Length: " << imgXlen << endl;
	cout << "Image Y Length: " << imgYlen << endl;
	cout << "Band number: " << bandNum << endl;
	buffTmp = (GByte*)CPLMalloc(imgXlen*imgYlen*sizeof(GByte));
	poDstDS = (GetGDALDriverManager()->GetDriverByName("GTiff")->Create(dstPath, imgXlen, imgYlen, bandNum, GDT_Byte, NULL));
	for(i = 0; i < bandNum; i++)
	{
		poSrcDS->GetRasterBand(i+1)->RasterIO(GF_Read, 0, 0, imgXlen, imgYlen, buffTmp, imgXlen, imgYlen, GDT_Byte, 0,0);
		poDstDS->GetRasterBand(i+1)->RasterIO(GF_Write, 0, 0, imgXlen, imgYlen, buffTmp, imgXlen, imgYlen, GDT_Byte, 0,0);
		printf("... ... band %d processing ... ...\n", i);
	}
	//��ʼλ������
	StartX=100;
	StartY=100;
	//�����Ⱥ͸߶�
	tmpXlen=200;
	tmpYlen=150;
	//�����ڴ�
	buffTmp=(GByte*)CPLMalloc(tmpXlen*tmpYlen*sizeof(GByte));
	//��ȡ��ɫͨ��������buffTmp��
	poSrcDS->GetRasterBand(1)->RasterIO(GF_Read,StartX,StartY,tmpXlen,tmpYlen,buffTmp,tmpXlen,tmpYlen,GDT_Byte,0,0);
	//��������������ֵΪ255
	for(j=0;j<tmpYlen;j++)
	{
		for(i=0;i<tmpXlen;i++)
		{
			buffTmp[j*tmpXlen+i]=(GByte)255;
		}
	}
	//����д��poDstDS
	poDstDS->GetRasterBand(1)->RasterIO(GF_Write,StartX,StartY,tmpXlen,tmpYlen,buffTmp,tmpXlen,tmpYlen,GDT_Byte,0,0);
	CPLFree(buffTmp);
	GDALClose(poDstDS);
	GDALClose(poSrcDS);


//��ɫ------------
	GDALDataset* poSrcDS2;
	GDALDataset* poDstDS2;
	char* srcPath2 = "square2.jpg";
	char* dstPath2 = "res2.tif";
	GByte* buffTmp2;

	poSrcDS2 = (GDALDataset*)GDALOpenShared(srcPath2,GA_ReadOnly);

	cout << "Image X Length: " << imgXlen << endl;
	cout << "Image Y Length: " << imgYlen << endl;
	cout << "Band number: " << bandNum << endl;
	buffTmp2 = (GByte*)CPLMalloc(imgXlen*imgYlen*sizeof(GByte));
	poDstDS2 = (GetGDALDriverManager()->GetDriverByName("GTiff")->Create(dstPath2, imgXlen, imgYlen, bandNum, GDT_Byte, NULL));
	for(i = 0; i < bandNum; i++)
	{
		poSrcDS2->GetRasterBand(i+1)->RasterIO(GF_Read, 0, 0, imgXlen, imgYlen, buffTmp2, imgXlen, imgYlen, GDT_Byte, 0,0);
		poDstDS2->GetRasterBand(i+1)->RasterIO(GF_Write, 0, 0, imgXlen, imgYlen, buffTmp2, imgXlen, imgYlen, GDT_Byte, 0,0);
		printf("... ... band %d processing ... ...\n", i);
	}

	StartX=300;
	StartY=300;
	tmpXlen=100;
	tmpYlen=50;
	buffTmp2=(GByte*)CPLMalloc(tmpXlen*tmpYlen*sizeof(GByte));
	poSrcDS2->GetRasterBand(1)->RasterIO(GF_Read,StartX,StartY,tmpXlen,tmpYlen,buffTmp2,tmpXlen,tmpYlen,GDT_Byte,0,0);
	poSrcDS2->GetRasterBand(2)->RasterIO(GF_Read,StartX,StartY,tmpXlen,tmpYlen,buffTmp2,tmpXlen,tmpYlen,GDT_Byte,0,0);
	poSrcDS2->GetRasterBand(3)->RasterIO(GF_Read,StartX,StartY,tmpXlen,tmpYlen,buffTmp2,tmpXlen,tmpYlen,GDT_Byte,0,0);
	for(j=0;j<tmpYlen;j++)
	{
		for(i=0;i<tmpXlen;i++)
		{
			buffTmp2[j*tmpXlen+i]=(GByte)255;
		}
	}
	poDstDS2->GetRasterBand(1)->RasterIO(GF_Write,StartX,StartY,tmpXlen,tmpYlen,buffTmp2,tmpXlen,tmpYlen,GDT_Byte,0,0);
	poDstDS2->GetRasterBand(2)->RasterIO(GF_Write,StartX,StartY,tmpXlen,tmpYlen,buffTmp2,tmpXlen,tmpYlen,GDT_Byte,0,0);
	poDstDS2->GetRasterBand(3)->RasterIO(GF_Write,StartX,StartY,tmpXlen,tmpYlen,buffTmp2,tmpXlen,tmpYlen,GDT_Byte,0,0);

	//��ɫ------------
	
	StartX=500;
	StartY=500;
	tmpXlen=50;
	tmpYlen=100;
	buffTmp2=(GByte*)CPLMalloc(tmpXlen*tmpYlen*sizeof(GByte));
	poSrcDS2->GetRasterBand(1)->RasterIO(GF_Read,StartX,StartY,tmpXlen,tmpYlen,buffTmp2,tmpXlen,tmpYlen,GDT_Byte,0,0);
	poSrcDS2->GetRasterBand(2)->RasterIO(GF_Read,StartX,StartY,tmpXlen,tmpYlen,buffTmp2,tmpXlen,tmpYlen,GDT_Byte,0,0);
	poSrcDS2->GetRasterBand(3)->RasterIO(GF_Read,StartX,StartY,tmpXlen,tmpYlen,buffTmp2,tmpXlen,tmpYlen,GDT_Byte,0,0);
	for(j=0;j<tmpYlen;j++)
	{
		for(i=0;i<tmpXlen;i++)
		{
			buffTmp2[j*tmpXlen+i]=(GByte)0;
		}
	}
	poDstDS2->GetRasterBand(1)->RasterIO(GF_Write,StartX,StartY,tmpXlen,tmpYlen,buffTmp2,tmpXlen,tmpYlen,GDT_Byte,0,0);
	poDstDS2->GetRasterBand(2)->RasterIO(GF_Write,StartX,StartY,tmpXlen,tmpYlen,buffTmp2,tmpXlen,tmpYlen,GDT_Byte,0,0);
	poDstDS2->GetRasterBand(3)->RasterIO(GF_Write,StartX,StartY,tmpXlen,tmpYlen,buffTmp2,tmpXlen,tmpYlen,GDT_Byte,0,0);

	CPLFree(buffTmp2);
	GDALClose(poDstDS2);
	GDALClose(poSrcDS2);
	system("PAUSE");
	return 0;
}